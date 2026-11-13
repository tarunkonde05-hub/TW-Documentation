# Assignment 5 - Report and Presentation

Q1 (report) is here. Q2 (Beamer slides) is in [`../../Beamer`](../../Beamer).

## Files

- `report.tex` / `report.pdf`

## Requirements and how each one is met

| Requirement | Code |
|---|---|
| report class, 12pt, A4 | `\documentclass[12pt,a4paper]{report}` |
| ~1 inch margins | `\usepackage[margin=1in]{geometry}` |
| Title page: title, name, ID, date, course, instructor | `titlepage` environment, written by hand |
| Title bold and Huge, name Large | `{\Huge\bfseries ...}`, `{\Large Tarun Konde}` |
| Abstract, then section Introduction | `\chapter*{Abstract}`, then `\chapter` + `\section{Introduction}` |
| Chapter titles red, bold, huge | `\chapterfont{\color{red}\bfseries\huge}` |
| Section titles magenta, italic, large | `\sectionfont{\color{magenta}\itshape\large}` |
| Subsection titles orange | `\subsectionfont{\color{orange}}` |
| No header on first page | `\thispagestyle{empty}` in the title page |
| Header from page 2: name / course / date | `fancyhdr`: `\fancyhead[L]`, `[C]`, `[R]` |

## What I learned

**sectsty** changes heading fonts with one line each instead of redefining the heading commands.

**fancyhdr and the plain style.** I set `\pagestyle{fancy}` but the first page of every chapter still had no header. The `report` class forces `\thispagestyle{plain}` on chapter pages. Redefining `plain` with `\fancypagestyle{plain}{...}` fixed it.

**The abstract environment.** In `report`, `\begin{abstract}` makes its own title-style page and prints no header there, which breaks the "header from the second page" rule. I replaced it with `\chapter*{Abstract}`, which is unnumbered and uses the redefined `plain` style.

**orange colour.** `orange` is not in the basic `xcolor` set, so I loaded `xcolor` with `dvipsnames`.

## Compile

```bash
pdflatex report.tex
pdflatex report.tex
```
