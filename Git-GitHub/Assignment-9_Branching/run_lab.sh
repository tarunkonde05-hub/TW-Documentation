#!/usr/bin/env bash
# Assignment 9 - Git Branching
# Repeats the whole lab in a new folder. Run: bash run_lab.sh
# Tarun Konde (2025UCP1811)

set -u
LAB=${1:-git-branching-lab}
rm -rf "$LAB" && mkdir "$LAB" && cd "$LAB" || exit 1

step() { echo; echo "========== $* =========="; }

git init -b master
cat > vecadd.py <<'EOF'
"""Vector addition and dot product."""


def vec_add(a, b):
    if len(a) != len(b):
        raise ValueError("vectors must have the same length")
    return [x + y for x, y in zip(a, b)]


def dot(a, b):
    if len(a) != len(b):
        raise ValueError("vectors must have the same length")
    total = 0
    for i in range(len(a) - 1):
        total += a[i] * b[i]
    return total


if __name__ == "__main__":
    a = [1, 2, 3, 4]
    b = [5, 6, 7, 8]
    print("a + b =", vec_add(a, b))
    print("a . b =", dot(a, b))
EOF
printf "# Vector operations\n\nvecadd.py adds two vectors and finds their dot product.\n" > README.md
git add .
git commit -m "Add vecadd.py with vector addition and dot product"
printf "\nRun with: python3 vecadd.py\n" >> README.md
git commit -am "Add run instructions to README"

step "1. HEAD"
git log --oneline

step "2. create branch fast"
git branch fast
git branch

step "3. rename fast -> parallel"
git branch -m fast parallel
git branch

step "4. switch to parallel"
git switch parallel
git status

step "5. parallel dot product"
python3 - <<'EOF'
s = open("vecadd.py").read()
s = s.replace('"""Vector addition and dot product."""',
              '"""Vector addition and dot product."""\n\nfrom multiprocessing import Pool')
s = s.replace("""    total = 0
    for i in range(len(a) - 1):
        total += a[i] * b[i]
    return total""", """    with Pool() as pool:
        products = pool.starmap(_mul, zip(a, b))
    return sum(products)


def _mul(x, y):
    return x * y""")
open("vecadd.py", "w").write(s)
EOF
git commit -am "Compute dot product in parallel with multiprocessing.Pool"
git log --oneline

step "6. fix on master"
git switch master
python3 vecadd.py        # teammate sees a . b = 38, expected 70
sed -i 's/range(len(a) - 1)/range(len(a))/' vecadd.py
python3 vecadd.py        # a . b = 70
git commit -am "Fix dot product skipping the last element"
git log --oneline --all --graph
git status

step "7/8. merge (conflict expected)"
git merge parallel
git status
echo "--- file with conflict markers ---"
cat vecadd.py

# keep the parallel side
python3 - <<'EOF'
import re
s = open("vecadd.py").read()
s = re.sub(r"<<<<<<< HEAD\n.*?=======\n(.*?)>>>>>>> parallel\n", r"\1", s, flags=re.S)
open("vecadd.py", "w").write(s)
EOF
python3 vecadd.py
git add vecadd.py
git commit -m "Merge parallel into master, keep the parallel dot product"
git log --oneline --all --graph

step "9. delete parallel"
git branch -d parallel
git branch

step "10. stash"
echo "work in progress" >> README.md
git status
git stash
git status
git stash list
git stash pop
git status
