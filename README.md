# Technical Writing Lab - Documentation

**Name:** Tarun Konde
**Student ID:** 2025UCP1811
**Course:** 22CSP210 Technical Writing, 2026
**Institute:** Malaviya National Institute of Technology (MNIT), Jaipur - Department of CSE

This repository has my lab work for Technical Writing: the solution files for each lab assignment and a README in every folder describing what the assignment asked, how I did it and what I learned.

## Contents

| Section | What is inside | Assignments |
|---|---|---|
| [LaTeX](LaTeX) | Documents, math, tables, figures, report, document structure | 1 - 6 |
| [Beamer](Beamer) | Slide presentation supporting the Assignment 5 report | 5 (Q2) |
| [Doxygen](Doxygen) | Documented multi-file C++ project, Doxyfile, generated HTML and PDF | 7 |
| [Google-Docs](Google-Docs) | Notes on structure, collaboration and export in Google Docs | - |
| [Git-GitHub](Git-GitHub) | Concepts, full command reference, branching lab with terminal output | 9 |

## Folder structure

```
TW-Documentation/
├── README.md
├── LaTeX/
│   ├── README.md
│   ├── Assignment-1_First-Document/       hello_world, first_latex_example, physics.bib
│   ├── Assignment-2_Math/                 math_equations
│   ├── Assignment-3_Arrays-and-Tables/    arrays_and_tables (14 questions)
│   ├── Assignment-4_Lists-Colors-Figures/ lists_colors_figures + images/
│   ├── Assignment-5_Report/               report
│   └── Assignment-6_Document-Structure/   document_structure + references.bib (XeLaTeX)
├── Beamer/
│   ├── README.md
│   └── presentation.tex / .pdf
├── Doxygen/
│   ├── README.md
│   └── Assignment-7/
│       ├── Logger.h, CalculationEngine.h, main.cpp
│       ├── Doxyfile
│       ├── doc_html/                      open index.html
│       ├── Calculation_Engine_Reference_Manual.pdf
│       └── screenshots/
├── Google-Docs/
│   └── README.md
└── Git-GitHub/
    ├── README.md
    ├── commands.md
    └── Assignment-9_Branching/
        ├── README.md
        ├── vecadd.py
        └── run_lab.sh
```

Every `.tex` file has its compiled `.pdf` next to it.

## Tools

| Tool | Used for | Check |
|---|---|---|
| TeX Live + TeXstudio | LaTeX and Beamer | `pdflatex --version` |
| XeLaTeX | Assignment 6 (fontspec) | `xelatex --version` |
| Doxygen + Graphviz | Assignment 7 | `doxygen --version`, `dot -V` |
| g++ | building the C++ project | `g++ --version` |
| Git | version control | `git --version` |
| Python 3 | `vecadd.py` | `python3 --version` |

Ubuntu install:

```bash
sudo apt install texlive-full texstudio doxygen graphviz g++ git python3
```

## Building

```bash
# LaTeX (Assignment 1 also needs bibtex, see its README)
cd LaTeX/Assignment-2_Math && pdflatex math_equations.tex

# Assignment 6
cd LaTeX/Assignment-6_Document-Structure
xelatex document_structure && bibtex document_structure && makeindex document_structure
xelatex document_structure && xelatex document_structure

# Doxygen
cd Doxygen/Assignment-7 && doxygen Doxyfile && (cd doc_latex && make)

# Git lab, repeated in a new folder
bash Git-GitHub/Assignment-9_Branching/run_lab.sh
```
