# Assignment 3 - Braces, Arrays, Cases and Tables

14 questions. Que 1-5 are math structures, Que 6-14 are tables.

## Files

- `arrays_and_tables.tex` - all 14 answers in one file
- `arrays_and_tables.pdf` - output

## Packages used

```latex
\usepackage{amsmath}        % cases, bmatrix, \dfrac, \text
\usepackage{array}          % >{\raggedright\arraybackslash}p{..}
\usepackage{multirow}       % Que 8
\usepackage[table]{xcolor}  % \rowcolor, \cellcolor (Que 9, 10)
\usepackage{colortbl}
\usepackage{booktabs}       % Que 12
```

## Question by question

| Que | Idea | Key command |
|---|---|---|
| 1 | Label parts of an expression | `\overbrace{..}^{label}`, `\underbrace{..}_{label}`, braces can be nested |
| 2 | Bordered array with header row and column | `array` with `{c|ccc}` and `\hline`, wrapped in `\left[ ... \right]` |
| 3 | Piecewise function | `cases`, `&` before the condition, `\dfrac` so the fraction is full size |
| 4 | Brace over a group of matrix columns | `\multicolumn{3}{c}{\overbrace{\hphantom{...}}^{...}}` |
| 5 | Quadratic + matrix term labelled as total energy | nested `\overbrace` inside `\underbrace`, `bmatrix`, `\cdots \vdots \ddots` |
| 6 | Simple bordered table | `|c|l|l|c|c|`, `\hline`, `\textbf` headings |
| 7 | Heading across all columns | `\multicolumn{3}{|c|}{...}` |
| 8 | Department cell over several rows | `\multirow{3}{*}{CSE}` and `\cline{2-4}` |
| 9 | Coloured header and alternate row | `\rowcolor{headblue}`, `\textcolor{white}{...}` |
| 10 | Colour by marks | `\cellcolor`, wrapped in three small macros |
| 11 | Paragraphs inside cells | `p{4cm}` columns, `\raggedright` to stop wide gaps |
| 12 | Professional table | `\toprule`, `\midrule`, `\bottomrule`, no `|` |
| 13 | Table inside a table | a `tabular` inside a cell |
| 14 | Formulas in cells | `$\displaystyle ...$`, bigger `\arraystretch` for row height |

## Things I learned

**`array` vs `tabular`.** `array` is for math mode and its cells are math. `tabular` is for text tables.

**Column spec.** `l c r` for alignment, `p{width}` for a wrapping column, `|` for a vertical line. The number of letters has to match the number of `&` + 1 in every row, otherwise LaTeX gives "Extra alignment tab".

**`\multicolumn` overrides the column spec for that cell.** That is why the borders have to be written again: `\multicolumn{3}{|c|}{...}`.

**`\multirow` needs empty cells below it.** The rows under `\multirow{3}{*}{CSE}` start with `&`. Using `\hline` would draw a line through the merged cell, so I used `\cline{2-4}` for those rows.

**Que 10 macros.** Instead of writing `\cellcolor{good}` twelve times I defined:

```latex
\newcommand{\hi}[1]{\cellcolor{good}#1}   % >= 90
\newcommand{\md}[1]{\cellcolor{avg}#1}    % 75-89
\newcommand{\lo}[1]{\cellcolor{poor}#1}   % < 75
```

My first try named the middle one `\mid`, which already exists in LaTeX (the `|` relation), so `\newcommand` refused it. Renamed to `\md`.

**booktabs rules.** No vertical lines and no double lines. The three rules have different thickness so the table still reads clearly. The caption goes above a table (below a figure).

**Paragraph columns.** In narrow `p{}` columns the text gets justified and leaves big gaps. `>{\raggedright\arraybackslash}p{4cm}` from the `array` package fixes it. The `\arraybackslash` is needed so `\\` still ends the row.

## Compile

```bash
pdflatex arrays_and_tables.tex
pdflatex arrays_and_tables.tex
```
