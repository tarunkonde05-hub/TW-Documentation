# Assignment 7 - Documenting a C++ Project with Doxygen

The lab gave three source files with `TODO` comments and a Doxyfile template. The task was to write the missing Doxygen comments, configure the Doxyfile and generate HTML and PDF documentation.

## Files

| File | Contents |
|---|---|
| `Logger.h` | `LogLevel` enum (INFO, WARNING, ERROR) and the `Logger` class |
| `CalculationEngine.h` | `CalculationEngine` class with `power_calculation()`, uses `Logger` |
| `main.cpp` | `main()` and the `@mainpage` |
| `Doxyfile` | Final configuration used to generate the docs |
| `doc_html/` | Generated HTML. Open `doc_html/index.html` in a browser |
| `Calculation_Engine_Reference_Manual.pdf` | PDF built from `doc_latex/` with `make` |
| `screenshots/` | Screenshots of the generated HTML pages |
| `sample_output.txt` | Output of the compiled program |

## Steps I followed

```bash
sudo apt install doxygen graphviz      # graphviz gives the diagrams (dot)
doxygen -g Doxyfile                    # create a default config
# edit Doxyfile (settings below)
doxygen Doxyfile                       # writes doc_html/ and doc_latex/
cd doc_latex && make                   # runs pdflatex, gives refman.pdf
```

Run the program:

```bash
g++ -std=c++17 main.cpp -o calc
./calc
```

## What was documented

| Element | Commands used |
|---|---|
| Main page | `@mainpage`, `@section`, `@code{.sh}` ... `@endcode` |
| Logger file and class | `@file`, `@class`, `@brief`, `@author` |
| `LogLevel` enum | `@enum`, and `///<` after each value |
| `Logger::Logger` constructor | `@brief`, `@param logPrefix`, `@param level` |
| `CalculationEngine` class | `@file`, `@class`, `@brief`, `@details`, `@see Logger` |
| `power_calculation` | `@param base`, `@param exponent`, `@return`, `@warning`, the existing `@todo` |
| Private members | `///<` trailing comments |

The `\f$ base^{exponent} \f$` in the comment is a LaTeX formula. Doxygen renders it with MathJax in HTML and as real math in the PDF.

## Doxyfile settings I changed

```
PROJECT_NAME        = "Calculation Engine"
PROJECT_NUMBER      = 1.0
INPUT               = Logger.h CalculationEngine.h main.cpp
FILE_PATTERNS       = *.h *.cpp
EXTRACT_ALL         = YES     # include members even if undocumented
EXTRACT_PRIVATE     = YES     # show private members
SOURCE_BROWSER      = YES     # source pages with line numbers
GENERATE_HTML       = YES
HTML_OUTPUT         = doc_html
GENERATE_TREEVIEW   = YES     # sidebar navigation
GENERATE_LATEX      = YES
LATEX_OUTPUT        = doc_latex
USE_MATHJAX         = YES     # formulas in HTML
HAVE_DOT            = YES     # graphs with graphviz
CALL_GRAPH          = YES
CALLER_GRAPH        = YES
```

## Problems I ran into

- **Formula images failed** with "Problems running gs". Without MathJax, Doxygen renders formulas to images using Ghostscript. Setting `USE_MATHJAX = YES` avoids that for the HTML.
- **`make` stopped on `listofitems.sty` not found.** Newer Doxygen LaTeX output needs it. Fixed with `sudo apt install texlive-plain-generic`.
- **Editing `FILE_PATTERNS`:** the default value spans many lines ending in `\`. Replacing only the first line left the rest behind and Doxygen warned about unknown tags. The whole block has to be replaced.

## What I learned

- Doxygen reads comments that start with `/**`, `///` or `//!`. Normal `//` comments are ignored.
- `@` and `\` work the same (`@brief` = `\brief`).
- `@brief` is the one-line summary shown in lists; the rest is the detailed description.
- `///<` documents the thing on the same line, which is the cleanest way to document enum values and member variables.
- The `@todo` items are collected on a separate "Todo List" page automatically.
- With `HAVE_DOT`, Doxygen draws the include graph and a collaboration diagram showing that `CalculationEngine` contains a `Logger`.
