# Assignment 2 - Math

Handout file name was `Assignment 3.pdf` on Classroom but it was announced as Assignment 2.

## Files

- `math_equations.tex` - solution
- `math_equations.pdf` - compiled output

## Sections in the handout and how I did them

| Section | Main commands |
|---|---|
| Basics | `$...$` for inline, `\[ ... \]` for display |
| Fractions & Roots | `\frac{}{}`, `\sqrt{}`, `\sqrt[3]{}` |
| Symbols & Math-fonts | Greek letters, `\mathbb{R}`, `\forall`, `\exists`, `\Rightarrow`, `\binom{n}{k}`, `\sum_{k=0}^{n}` |
| Calculus | `\frac{\partial u}{\partial t}`, `\partial^2`, `\int_0^1 ... \,dx` |
| Multi-line equations | `gather`, `align`, `multline*` |
| Matrices | `matrix`, `pmatrix`, `bmatrix`, `vmatrix` |

## What I learned

**Inline vs display.** `$E = m.c^2$` stays inside the sentence. `\[ v = u + a.t \]` goes on its own centred line. I avoided `$$ ... $$` because it is plain TeX and gives wrong spacing with `amsmath`.

**`amsmath` and `amssymb`.** `align`, `gather`, `multline`, `\binom` and `\eqref` come from `amsmath`. `\mathbb{R}` needs `amssymb`.

**Subscripts and superscripts with more than one character need braces.** `x^10` prints x to the 1 followed by 0. `x^{10}` is correct. Same for `G_{\mu\nu}`.

**gather vs align.** In the handout both 5.1 equations look the same, but one block is centred and the other is aligned. `gather` centres every line separately. `align` lines them up at the `&`:

```latex
\begin{align}
    x     &= 5 \\
    x + y &= 3
\end{align}
```

**multline for one long equation.** The cube expansion does not fit on one line. `multline` puts the first line on the left and the last line on the right. The `*` removes the number. When a line ends in `+`, writing `+ {}` keeps the correct spacing around the plus sign.

**Brackets that grow.** `\left( \frac{a}{b} \right)` sizes the brackets to the fraction. Plain `( )` stays small.

**Matrices.** All four are the same code with a different environment name: no bracket, round, square and vertical bars (determinant).

**Small spaces.** `\,` before `dx` in integrals, `\quad` between two formulas on one line.

## Compile

```bash
pdflatex math_equations.tex
pdflatex math_equations.tex   # second run for equation references
```
