# Git Command Reference

All commands from the course Git slides, in the order they were taught. Placeholders are in CAPITALS.

## Install and check

```bash
sudo apt install git          # Ubuntu
brew install git              # macOS
git --version                 # git version 2.x.x
```

Windows: installer from https://git-scm.com/downloads

## First-time setup

```bash
git config --global user.name "Tarun Konde"
git config --global user.email "EMAIL"
git config --global --list
```

The name and email are stored in every commit I make.

## Create a repository

```bash
git init                      # creates the hidden .git folder
```

## Stage and commit

```bash
git status                    # current state of working directory and staging area
git add main.py               # stage one file
git add file1.py file2.py     # several files
git add *.py                  # pattern
git add .                     # everything in this folder
git commit -m "Add main program"
```

## Inspect

```bash
git log                       # full history
git log --oneline             # one line per commit
git log --oneline --all --graph   # all branches as a graph
git diff                      # unstaged changes
git diff --staged             # staged changes
git diff HEAD                 # all changes since last commit
git ls-files                  # files Git is tracking
git show COMMIT_ID            # one commit in detail
```

## Rename and delete files

```bash
git mv old.py new.py          # rename and stage the rename
git rm old.py                 # delete and stage the deletion
git rm --cached FILE          # stop tracking, keep the file on disk
```

## Undo

```bash
git restore --staged main.py  # unstage, keep edits
git restore main.py           # discard edits in the working directory
git revert COMMIT_ID          # new commit that reverses COMMIT_ID
```

## Remotes (GitHub)

```bash
git remote add origin https://github.com/USERNAME/calculator.git
git remote -v                 # list remotes (fetch and push URLs)
git branch -M main            # rename current branch to main
git push -u origin main       # first push, sets upstream
git push                      # later pushes
git clone https://github.com/USERNAME/calculator.git
git fetch origin              # download without merging
git pull                      # fetch + merge
git pull origin main
```

## Branches

```bash
git branch                    # list local branches, * = current
git branch feature-login      # create
git switch feature-login      # move to it
git switch -c feature-login   # create + move
git switch main
git branch -m OLD NEW         # rename
git branch -d feature-login   # delete (only if merged)
git branch -D feature-login   # force delete
git checkout BRANCH           # older way to switch
```

## Merge and rebase

```bash
git switch main
git merge feature-login       # bring feature-login into main
# on conflict: edit the file, remove <<<<<<< ======= >>>>>>>, then
git add FILE
git commit
git merge --abort             # give up on a merge

git switch feature
git rebase main               # replay feature on top of main
```

## Tags

```bash
git tag                       # list
git tag -a v1.0.0 -m "Version 1.0.0"
git show v1.0.0
git push origin v1.0.0
```

## Stash

```bash
git stash                     # save uncommitted changes, clean the tree
git stash list
git stash apply               # bring back, keep in the list
git stash pop                 # bring back and remove from the list
git stash drop                # delete the top entry
```

## Help

```bash
git help stash                # manual page for any command
git COMMAND --help
```

## Feature-branch workflow from the slides

```bash
git init
git add .
git commit -m "Add initial calculator"
git remote add origin REPOSITORY_URL
git branch -M main
git push -u origin main

git switch -c feature-subtraction
# edit files
git add .
git commit -m "Add subtraction feature"
git push -u origin feature-subtraction
# open a pull request on GitHub, get it reviewed and merged

git switch main
git pull origin main
```

## Example .gitignore

```gitignore
__pycache__/
*.pyc
*.log
build/
.env
```
