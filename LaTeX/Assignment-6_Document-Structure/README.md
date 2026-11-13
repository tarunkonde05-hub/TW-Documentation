# Assignment 6 - Document Structure

Fonts, background colour, spacing, alphabetic numbering, boxes, index and bibliography.

## Files

- `document_structure.tex` / `.pdf`
- `references.bib` - with the missing "LaTeX in short" entry added

## This one needs XeLaTeX

`fontspec` loads system fonts by name and only works with XeLaTeX or LuaLaTeX. In TeXstudio:
Options > Configure TeXstudio > Build > Default Compiler > XeLaTeX.

```latex
\usepackage{fontspec}
\setmainfont{DejaVu Serif}
\setsansfont{DejaVu Sans}
\setmonofont{Courier}[Scale=MatchLowercase]
```

If Courier is missing on Windows/Ubuntu, `TeX Gyre Cursor` is a free clone that comes with TeX Live.

## A. Fonts and background

- Background: I took the colour from the handout page, `#FDF3E9`, and set it with `\definecolor{handoutbg}{HTML}{FDF3E9}` and `\pagecolor{handoutbg}`.
- `trivlist` is a list with no labels and no indent. Each `\item` is just a new line.

## B. Spacing

- `\\` ends a line without starting a new paragraph.
- `\vspace{1cm}` adds the vertical gap.
- Hyphenation: the first long-word paragraph is normal, so LaTeX breaks "antidisestablishmentarianisms" at a hyphen. In the second I set `\hyphenpenalty=10000` inside a group, so the word cannot be broken and runs past the margin, the same as in the handout.
- Section C is skipped on purpose: `\newpage` then `\stepcounter{section}`, so the next section is numbered D.

## D. Numbering

```latex
\renewcommand{\thesection}{\Alph{section}}   % A, B, C ...
```

The ellipse was added before the circle. Because both equations use `\label`/`\ref`, the circle changed from (1) to (2) and the text updated itself.

## E. Boxes

```latex
\newsavebox{\notebox}
\sbox{\notebox}{\fbox{This message is written in a savebox.}}
\usebox{\notebox}   % reuse as many times as needed
\fbox{\parbox{5cm}{This message is wrapped in a 5cm paragraph box.}}
```

A savebox is typeset once and stored, so reusing it is cheaper than writing the box again. A `\parbox` wraps text to a fixed width.

## Index

```latex
\usepackage{makeidx}
\makeindex                 % preamble
\index{savebox}            % next to the word in the text
\printindex                % where the index should appear
```

## Bibliography

The missing book entry I added to `references.bib`:

```bibtex
@book{oetiker2021,
  author    = {Oetiker, Tobias},
  title     = {The Not So Short Introduction to {\LaTeX} 2$\varepsilon$},
  publisher = {CTAN},
  year      = {2021}
}
```

Cited with `\cite{oetiker2021}` and `\cite{overleafbib}`, style `plain`.

## Compile order

```bash
xelatex   document_structure
bibtex    document_structure    # reads .aux, writes .bbl
makeindex document_structure    # reads .idx, writes .ind
xelatex   document_structure
xelatex   document_structure
```

Each tool works on a file written by the previous LaTeX run, which is why the order matters. Running `makeindex` before the first `xelatex` does nothing because the `.idx` file does not exist yet.
