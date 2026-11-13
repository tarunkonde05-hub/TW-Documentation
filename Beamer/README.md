# Beamer

Beamer is a LaTeX document class for slides. The slides support the report from LaTeX Assignment 5 (Q2: 3-4 slides with a title slide, content slides and a concluding slide).

## Files

- `presentation.tex` - source
- `presentation.pdf` - output (8 PDF pages because of overlays; 5 frames)

## Structure of a Beamer file

```latex
\documentclass{beamer}
\usetheme{Madrid}

\title[Short title]{Full title}
\author[Short]{Full name}
\institute{...}
\date{\today}

\begin{document}
\begin{frame}
    \titlepage
\end{frame}

\begin{frame}{Frame title}
    content
\end{frame}
\end{document}
```

The short versions in `[...]` are what appear in the footer of the Madrid theme.

## Frames in my presentation

| Frame | What it shows |
|---|---|
| Title | `\titlepage` |
| Outline | `\tableofcontents`, built from `\section` commands placed between frames |
| What is LaTeX? | bullets revealed one by one, then a block |
| Math and Structure | two columns: bullets on the left, equations on the right |
| Conclusion | `alertblock` with the takeaway |

## What I learned

**Overlays.** `\item<2->` means "show from slide 2 onwards". One frame becomes several PDF pages, which is why the PDF has more pages than frames. `\only<4>{...}` shows something only on that step and takes no space otherwise; `\uncover<4>{...}` keeps the space reserved.

**Blocks.** `block`, `alertblock` and `exampleblock` give titled boxes coloured by the theme.

**Columns.**

```latex
\begin{columns}
    \begin{column}{0.5\textwidth} ... \end{column}
    \begin{column}{0.5\textwidth} ... \end{column}
\end{columns}
```

**Themes.** `\usetheme{Madrid}` controls layout; `\usecolortheme{...}` changes only colours (`beaver`, `crane`, `dolphin`, ...). Other layout themes: `Warsaw`, `Berlin`, `CambridgeUS`.

**Sections in Beamer** do not print anything on a slide. They only feed the outline and the navigation bar.

**Verbatim code on a slide** needs `\begin{frame}[fragile]`, otherwise it fails to compile.

## Compile

```bash
pdflatex presentation.tex
pdflatex presentation.tex   # second run fills the outline
```
