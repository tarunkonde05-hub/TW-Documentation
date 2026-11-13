# Git and GitHub

| File / Folder | Contents |
|---|---|
| [commands.md](commands.md) | Every command from the Git slides, grouped by topic, with what each one does |
| [Assignment-9_Branching](Assignment-9_Branching) | Branch, rename, switch, merge, conflict, delete, stash - with terminal output |

This repository itself is also my Git practice: it was built commit by commit and pushed to GitHub with the commands below.

## Git vs GitHub

- **Git** is the version control tool. It runs on my laptop and works offline: commits, branches, merges, history.
- **GitHub** is a website that hosts Git repositories. It adds remotes to push to, pull requests, issues and a web view of the code.

## Why version control

Without it a project ends up as `vecadd.py`, `vecadd_final.py`, `vecadd_final2.py`. Git keeps one file and a history of every change, with who made it, when, and why (the commit message). Any old version can be brought back.

## The three areas

```
working directory --git add--> staging area --git commit--> local repo (.git) --git push--> GitHub
        ^                                                          |
        +------------------------- git pull / git fetch -----------+
```

- **Working directory:** the files I edit.
- **Staging area (index):** what will go into the next commit. `git add` copies the current content of a file here; if I edit the file again, I have to `git add` it again.
- **Repository:** the `.git` folder with all commits.

A file is **untracked** (Git has never seen it), **modified**, **staged**, or **committed**.

## Everyday workflow

```bash
git status                       # what changed
git add main.py                  # stage
git diff --staged                # check what is staged
git commit -m "Add main program" # record
git push                         # upload
```

## Undoing things

| Situation | Command |
|---|---|
| Unstage a file, keep my edits | `git restore --staged main.py` |
| Throw away edits in a file | `git restore main.py` |
| Undo a commit that is already pushed | `git revert COMMIT_ID` (makes a new commit that reverses it) |

`git revert` is safe on shared branches because it does not rewrite history.

## Three kinds of diff

| Command | Compares |
|---|---|
| `git diff` | working directory vs staging area (unstaged changes) |
| `git diff --staged` | staging area vs last commit |
| `git diff HEAD` | working directory vs last commit (everything) |

## .gitignore

Files that should never be committed: build output, caches, editor files, secrets. This repo's `.gitignore` keeps out LaTeX auxiliary files (`*.aux`, `*.log`, `*.toc` ...) and the Doxygen `doc_latex/` folder.

Adding a file to `.gitignore` after it was committed does not remove it from history. It has to be removed with `git rm --cached` and any secret in it should be treated as leaked.

## Branching

- A branch is a pointer to a commit; `HEAD` points to the branch I am on.
- `git switch -c feature-login` creates and switches in one step.
- `git merge feature-login` brings that branch into the current one. If both sides changed the same lines, Git marks the conflict with `<<<<<<<`, `=======`, `>>>>>>>` and I fix it by hand, then `git add` and `git commit`.
- `git rebase main` (from a feature branch) replays the feature commits on top of main, giving a straight history instead of a merge commit. Not to be used on branches others already pulled.

## Working with GitHub

```bash
git remote add origin https://github.com/USERNAME/REPO.git
git remote -v
git branch -M main
git push -u origin main          # -u remembers origin/main for later git push / git pull
git clone https://github.com/USERNAME/REPO.git
git fetch origin                 # download, do not change my files
git pull                         # fetch + merge
```

**Pull request:** on GitHub, a request to merge one branch into another, with discussion and review. It is not the same as `git pull`.

**Fork vs clone:** a fork is a copy of someone's repository under my GitHub account; a clone is a copy on my computer.

**Tags** mark releases:

```bash
git tag -a v1.0.0 -m "Version 1.0.0"
git show v1.0.0
git push origin v1.0.0
```

## Common problems from the slides

| Problem | Fix |
|---|---|
| File not in the commit | it was untracked; `git add` it |
| Commit went to the wrong branch | check `git branch` before committing |
| "nothing to commit" | check `git status`; maybe nothing was staged |
| Push rejected | someone pushed first; `git pull` then push |
