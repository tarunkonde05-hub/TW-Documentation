# Doxygen

Doxygen generates documentation from comments in source code. The same comments produce an HTML site and a LaTeX manual that compiles to PDF. Projects like LLVM, OpenCV and D-Bus document their code this way.

| Folder | Contents |
|---|---|
| [Assignment-7](Assignment-7) | Multi-file C++ project, Doxyfile, generated HTML, PDF manual |

## How it works

```
source files with /** ... */ comments
            |
         doxygen  (reads Doxyfile)
         /     \
  doc_html/   doc_latex/ --make--> refman.pdf
```

## Comment styles

```cpp
/**
 * @brief One line summary.
 *
 * Longer description.
 */

/// single line doc comment
int x; ///< comment for the item on this line
```

## Tags I used

| Tag | Purpose |
|---|---|
| `@file` | documents the file itself; without it, free functions in the file are not listed |
| `@mainpage` | content of the front page |
| `@class`, `@enum` | attach a block to a class or enum |
| `@brief`, `@details` | short and long description |
| `@param name` | one per parameter |
| `@return` | return value |
| `@warning`, `@note` | highlighted boxes |
| `@todo` | collected on the Todo List page |
| `@see` | link to another item |
| `@code` ... `@endcode` | code example |
| `@author` | author name |
| `\f$ ... \f$` | inline LaTeX formula |

## Useful Doxyfile options

| Option | Effect |
|---|---|
| `INPUT`, `FILE_PATTERNS`, `RECURSIVE` | which files are read |
| `EXTRACT_ALL`, `EXTRACT_PRIVATE` | include undocumented / private members |
| `GENERATE_HTML`, `GENERATE_LATEX` | output formats |
| `HTML_OUTPUT`, `LATEX_OUTPUT` | output folder names |
| `SOURCE_BROWSER` | adds source code pages |
| `HAVE_DOT`, `CALL_GRAPH`, `CALLER_GRAPH` | diagrams (needs graphviz) |
| `USE_MATHJAX` | formulas in HTML |

`doxygen -g` creates a fully commented default Doxyfile, and `doxywizard` is a GUI for the same settings.
