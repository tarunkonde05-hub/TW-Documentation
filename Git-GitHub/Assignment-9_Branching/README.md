# Assignment 9 - Git Branching

Handout title: "Git Branching". The lab uses a small repository with `vecadd.py` and a README, then creates a branch for a parallel dot product, makes a fix on master, merges, resolves a conflict, deletes the branch and tries `git stash`.

## Files

- `vecadd.py` - final version after the merge (parallel dot product with `multiprocessing.Pool`)
- `run_lab.sh` - every command of the lab in order, so the whole exercise can be repeated in a fresh folder

The outputs below are copied from my terminal.

## Setup

A repository with two commits: `vecadd.py` + README, then a change to the README.

```
$ git log --oneline
cd507b7 Add run instructions to README
3dd3496 Add vecadd.py with vector addition and dot product
```

**1. HEAD.** `HEAD` points to the latest commit on the current branch (`cd507b7` on `master`). With `--decorate` (on by default in a terminal) it shows as `(HEAD -> master)`.

## 2. Create a branch `fast`

```
$ git branch fast
$ git branch
  fast
* master
```

`git branch fast` only creates the pointer. The `*` shows I am still on `master`.

## 3. Rename `fast` to `parallel`

```
$ git branch -m fast parallel
$ git branch
* master
  parallel
```

## 4. Switch to `parallel`

```
$ git switch parallel
Switched to branch 'parallel'

$ git status
On branch parallel
nothing to commit, working tree clean
```

`git checkout parallel` does the same; `switch` is the newer command that only changes branches.

## 5. Parallel dot product, commit, compare logs

Changed `dot()` to multiply the pairs in a process pool:

```python
from multiprocessing import Pool

def dot(a, b):
    ...
    with Pool() as pool:
        products = pool.starmap(_mul, zip(a, b))
    return sum(products)
```

```
$ git log --oneline
31017af Compute dot product in parallel with multiprocessing.Pool
cd507b7 Add run instructions to README
3dd3496 Add vecadd.py with vector addition and dot product
```

**Difference between master and parallel:** `parallel` has one extra commit (`31017af`). `master` still points at `cd507b7`, so its `vecadd.py` still has the old loop.

## 6. Fix on master

My teammate reported that `dot([1,2,3,4], [5,6,7,8])` returns 38 instead of 70. The loop was `range(len(a) - 1)`, so the last pair was never added. I switched back to master and fixed that one line:

```python
for i in range(len(a)):        # was range(len(a) - 1)
```

```
$ git switch master
Switched to branch 'master'

$ python3 vecadd.py
a + b = [6, 8, 10, 12]
a . b = 38

(fixed the line)

$ python3 vecadd.py
a + b = [6, 8, 10, 12]
a . b = 70

$ git commit -am "Fix dot product skipping the last element"
[master 5e42dbe] Fix dot product skipping the last element
 1 file changed, 1 insertion(+), 1 deletion(-)

$ git log --oneline --all --graph
* 5e42dbe Fix dot product skipping the last element
| * 31017af Compute dot product in parallel with multiprocessing.Pool
|/
* cd507b7 Add run instructions to README
* 3dd3496 Add vecadd.py with vector addition and dot product

$ git status
On branch master
nothing to commit, working tree clean
```

The graph shows the history splitting after `cd507b7`: one commit on each branch.

## 7 and 8. Merge and resolve the conflict

Both commits changed the same lines of `dot()` (the fix touched the loop, the parallel version replaced the loop), so the merge stopped:

```
$ git merge parallel
Auto-merging vecadd.py
CONFLICT (content): Merge conflict in vecadd.py
Automatic merge failed; fix conflicts and then commit the result.

$ git status
On branch master
You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)
	both modified:   vecadd.py
```

What Git wrote into the file:

```
<<<<<<< HEAD
    total = 0
    for i in range(len(a)):
        total += a[i] * b[i]
    return total
=======
    with Pool() as pool:
        products = pool.starmap(_mul, zip(a, b))
    return sum(products)


def _mul(x, y):
    return x * y
>>>>>>> parallel
```

- Between `<<<<<<< HEAD` and `=======`: the version on `master` (where I am).
- Between `=======` and `>>>>>>> parallel`: the version coming from `parallel`.

I kept the parallel version, since it already loops over every pair (`zip(a, b)`) and so does not have the bug. Removed the three marker lines, checked the output was 70 again, then:

```
$ git add vecadd.py
$ git status
On branch master
All conflicts fixed but you are still merging.
  (use "git commit" to conclude merge)

$ git commit -m "Merge parallel into master, keep the parallel dot product"
[master 20511db] Merge parallel into master, keep the parallel dot product

$ git log --oneline --all --graph
*   20511db Merge parallel into master, keep the parallel dot product
|\
| * 31017af Compute dot product in parallel with multiprocessing.Pool
* | 5e42dbe Fix dot product skipping the last element
|/
* cd507b7 Add run instructions to README
* 3dd3496 Add vecadd.py with vector addition and dot product
```

The merge commit `20511db` has two parents, which is why the graph joins back.

If the two commits had touched different lines, `git merge parallel` would have finished on its own with "Merge made by the 'ort' strategy".

## 9. Delete the branch

```
$ git branch -d parallel
Deleted branch parallel (was 31017af).

$ git branch
* master
```

`-d` refuses to delete a branch that is not merged yet. `-D` forces it.

## 10. git stash

Made an uncommitted change to README.md, then:

```
$ git stash
Saved working directory and index state WIP on master: 20511db Merge parallel into master, keep the parallel dot product

$ git status
On branch master
nothing to commit, working tree clean

$ git stash list
stash@{0}: WIP on master: 20511db Merge parallel into master, keep the parallel dot product

$ git stash pop
...
	modified:   README.md
Dropped refs/stash@{0} (27c469b...)
```

`git stash` puts the uncommitted changes on a stack and cleans the working tree, so I can switch branches. `git stash pop` brings them back and removes them from the stack; `git stash apply` brings them back but keeps the entry. `git help stash` shows the full manual (`git help <command>` works for every command).

## What I learned

- A branch is just a movable pointer to a commit. Creating one is instant.
- `HEAD` tells Git which branch I am on.
- `git log --oneline --all --graph` is the clearest way to see where branches split and join.
- Conflicts only happen when both sides change the same lines. They are resolved by editing the file, then `git add` and `git commit`.
- Delete branches after merging so the branch list stays short.
