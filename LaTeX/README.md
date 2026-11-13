# LaTeX

Lab assignments 1 to 6. Each folder has the `.tex` source, the compiled PDF and a README with what the assignment asked and what I learned from it.

| Folder | Topic | Compiler |
|---|---|---|
| [Assignment-1_First-Document](Assignment-1_First-Document) | Hello World, document class options, lists, natbib citations, cross-references | pdflatex + bibtex |
| [Assignment-2_Math](Assignment-2_Math) | Inline/display math, fractions, symbols, calculus, align/gather/multline, matrices | pdflatex |
| [Assignment-3_Arrays-and-Tables](Assignment-3_Arrays-and-Tables) | over/underbrace, array, cases, multicolumn, multirow, coloured tables, booktabs, nested tables | pdflatex |
| [Assignment-4_Lists-Colors-Figures](Assignment-4_Lists-Colors-Figures) | itemize/enumerate/description, float placement, custom colours, rotate/crop images, minipage | pdflatex |
| [Assignment-5_Report](Assignment-5_Report) | report class, title page, sectsty, fancyhdr | pdflatex |
| [Assignment-6_Document-Structure](Assignment-6_Document-Structure) | fontspec, page colour, spacing, alphabetic numbering, savebox/parbox, index, bibliography | xelatex + bibtex + makeindex |

The Beamer part of Assignment 5 is in [`../Beamer`](../Beamer).

## Basics I use in every file

```latex
\documentclass[12pt,a4paper]{article}   % class + options
% preamble: packages and settings
\usepackage{amsmath}
\begin{document}
% body: the actual content
\end{document}
```

- Document classes I used: `article`, `report`, `beamer`.
- `\section`, `\subsection`, `\subsubsection` for structure; `report` adds `\chapter`.
- `\label{...}` and `\ref{...}` for numbers that update on their own.
- Reserved characters: `# $ % & _ { } ~ ^ \`.

## Packages used across the assignments

| Package | Used for |
|---|---|
| `amsmath`, `amssymb` | equations, `align`, `cases`, `\mathbb` |
| `natbib` | `\citet`, `\citep` |
| `graphicx` | `\includegraphics` |
| `xcolor`, `colortbl` | text and table colours |
| `multirow`, `booktabs`, `array` | tables |
| `geometry` | margins and paper size |
| `fancyhdr`, `sectsty` | headers/footers, heading styles |
| `fontspec` | system fonts (XeLaTeX only) |
| `makeidx` | index |

## Why some files need several runs

LaTeX reads labels, citations and index entries from auxiliary files written in the previous run. A typical full build is:

```
pdflatex -> bibtex / makeindex -> pdflatex -> pdflatex
```

## Editor

I used TeXstudio on Ubuntu (`sudo apt install texstudio texlive-full`). Overleaf works too and needs nothing installed.

## References

- *The Not So Short Introduction to LaTeX* (lshort), Tobias Oetiker
- Overleaf documentation: https://www.overleaf.com/learn
- Course slides: LaTeX lectures 1-2, Maths constructs, Tables, Colour/Figure/Picture, Environments
