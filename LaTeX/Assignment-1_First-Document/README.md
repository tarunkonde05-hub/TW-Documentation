# Assignment 1 - Hello World and My First LaTeX Document

## Files

| File | What it is |
|---|---|
| `hello_world.tex` / `.pdf` | The smallest document that compiles |
| `first_latex_example.tex` / `.pdf` | The starter file after all the changes asked in the handout |
| `physics.bib` | BibTeX database with Einstein's 1905 paper |

## Tasks done

1. Hello World: `\documentclass`, `\begin{document}`, text, `\end{document}`. Nothing else is required.
2. Added a new section and a subsection and recompiled.
3. Added `\tableofcontents`. It shows up empty on the first run and fills in on the second, because LaTeX writes the headings to a `.toc` file first and reads it on the next run.
4. Changed the font size with `\documentclass[12pt]{article}`.
5. Paper size: the default for `article` is **letter** (8.5 x 11 in). Adding the `a4paper` option changes it, so the final line is `\documentclass[12pt,a4paper]{article}`.
6. Made a numbered list with `enumerate`.
7. Added a section called "Science!" with `$e = mc^2$` in inline math.
8. Cited Einstein using `natbib` + `physics.bib` with the `agu` style, and added labels and cross-references.

## What I learned

**Whitespace.** Any number of spaces is treated as one space. One line break is also just a space. A blank line is what starts a new paragraph.

**Special characters.** `# $ % & _ { }` have meanings in LaTeX, so they are printed as `\# \$ \% \& \_ \{ \}`. `%` starts a comment.

**Quotes and dashes.** Opening quotes are typed with backticks (` `` `), closing with two apostrophes. `-` is a hyphen, `--` is for ranges like 10--20, `---` is a sentence dash.

**Citations with natbib.**

```latex
\usepackage{natbib}
...
as written by \citet{einstein1905}     % Einstein (1905)
the equation $e=mc^2$ \citep{einstein1905}   % (Einstein, 1905)
...
\bibliographystyle{agu}
\bibliography{physics}   % physics.bib, no extension
```

**Cross-references.** `\label{sec:science}` after a heading, then `\ref{sec:science}` or `\pageref{sec:science}` anywhere. For equations `\eqref` adds the brackets.

## How to compile

```bash
pdflatex first_latex_example
bibtex   first_latex_example
pdflatex first_latex_example
pdflatex first_latex_example
```

The first `pdflatex` writes the citation keys to the `.aux` file, `bibtex` builds the `.bbl` from `physics.bib`, and the last two runs put the references and numbers in place. If I skip a run I get `[?]` instead of the citation.

## Things to watch out for

- `\bibliography{physics}` takes the file name without `.bib`.
- `bibtex` is given the base name of the document (`first_latex_example`), not the `.tex` file.
- `%` starts a comment, so a percentage has to be written as `\%`.
