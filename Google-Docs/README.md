# Google Docs

Google Docs was covered as the collaborative side of documentation: where Doxygen documents code, Docs is used for reports, specs and lab write-ups that several people edit together.

## Doxygen vs Google Docs

| | Doxygen | Google Docs |
|---|---|---|
| Input | comments in source code | rich text typed in the browser |
| Output | HTML site, LaTeX/PDF manual | the document itself; export to PDF, DOCX, ODT, EPUB, TXT |
| Collaboration | through Git (commits, pull requests) | real time, several cursors at once |
| Best for | API reference | reports, proposals, meeting notes |

## Features I used

**Structure**
- Styles: Title, Heading 1/2/3, Normal text (Format > Paragraph styles). Using real headings instead of bold text is what makes the outline work.
- Document outline in the left sidebar, built from the headings.
- Table of contents: Insert > Table of contents, refreshed with the reload icon after editing headings.
- Page numbers, headers and footers: Insert > Page numbers / Headers & footers.
- Page setup: File > Page setup for paper size, margins and orientation.

**Content**
- Equations: Insert > Equation. Typing LaTeX-like shortcuts such as `\alpha` or `\frac` works inside the equation box.
- Tables, images, Insert > Drawing for simple diagrams, footnotes (Ctrl+Alt+F).
- Citations: Tools > Citations, style MLA/APA/Chicago.
- Code-like text: the Code blocks building block (Insert > Building blocks).

**Collaboration**
- Share with Viewer / Commenter / Editor access.
- Comments (Ctrl+Alt+M), and assigning a comment to someone with `+name@email`.
- Suggesting mode: edits appear as suggestions that the owner accepts or rejects, similar to a pull request review.
- Version history: File > Version history > See version history. Named versions work like tags in Git.

**Export**
- File > Download > PDF / DOCX / ODT / Markdown / plain text.

## How it relates to the rest of the course

- Version history and suggesting mode are the same ideas as commits and pull requests in Git, but without branches.
- The heading-based outline is the same idea as `\section` in LaTeX: structure first, formatting from styles.
- For long technical documents with many equations I would still use LaTeX. For a short shared report that needs comments from teammates, Docs is quicker.

## Keyboard shortcuts I use

| Action | Shortcut |
|---|---|
| Heading 1 / 2 / 3 | Ctrl+Alt+1 / 2 / 3 |
| Normal text | Ctrl+Alt+0 |
| Insert comment | Ctrl+Alt+M |
| Insert link | Ctrl+K |
| Word count | Ctrl+Shift+C |
| Clear formatting | Ctrl+\ |
| Show all shortcuts | Ctrl+/ |
