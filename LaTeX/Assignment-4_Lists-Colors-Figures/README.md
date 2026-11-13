# Assignment 4 - Lists, Colors, Figures

## Files

- `lists_colors_figures.tex` / `.pdf`
- `images/mnit_logo.png`, `images/mnit_building.jpg` - images given with the handout

## Lists

Three list environments:

```latex
\begin{itemize} \item ... \end{itemize}        % bullets
\begin{enumerate} \item ... \end{enumerate}    % 1. 2. 3.
\begin{description}
    \item[Presentational] ...                  % bold term then text
\end{description}
```

I also noticed the handout spells "Porcedural"; I wrote it as "Procedural".

## Table placement

The table is written in Section 2 but placed with `[p]`, so LaTeX puts it on a page of its own at the end. The options are:

| Option | Meaning |
|---|---|
| `h` | here, roughly |
| `t` | top of a page |
| `b` | bottom of a page |
| `p` | separate float page |
| `!` | ignore some of LaTeX's limits |

The last row of the table prints the width of each `p{}` column (2.5 cm, 2 cm, 2 cm, 3.5 cm).

## Colours as numbers

- RGB on a 0-255 scale: red 200, green 20, blue 200.
- HTML hex is the same three numbers in base 16: 200 = C8, 20 = 14, so `#C814C8`.
- CSS numeric form: `rgb(200, 20, 200)`.

```latex
\definecolor{mypurple}{RGB}{200,20,200}     % or {HTML}{C814C8}
\colorlet{myorange}{red!60!yellow}          % 60% red, rest yellow
```

`RGB` (capital) means 0-255 and `rgb` (small) means 0-1. Giving 200 to the small `rgb` model is out of range.

The recurrence `T(n) = aT(n/b) + f(n)` is coloured with `\textcolor{...}{...}` inside math mode.

## Figures

**Rotate:** `\includegraphics[width=3.5cm, angle=-15]{mnit_logo.png}`

**Crop the sky:** `trim` takes left, bottom, right, top. The image is 696 px tall at 72 dpi, and the sky is roughly the top quarter, so I trimmed 165 bp from the top. `clip` is required, otherwise trim only changes the bounding box and the sky still shows.

```latex
\includegraphics[width=\textwidth, trim={0 0 0 165bp}, clip]{mnit_building.jpg}
```

**Two images side by side:** two `minipage`s of `0.45\textwidth` with `\hfill` between them, each with its own `\caption`, all inside one `figure`.

`\graphicspath{{images/}}` lets me write only the file name.

## Compile

```bash
pdflatex lists_colors_figures.tex
pdflatex lists_colors_figures.tex
```
