from pathlib import Path

ROOT = Path(__file__).parent.parent

IGNORE = {
    "notebook",
    ".git",
    ".github",
    "build",
}

EXTENSIONS = {".cpp", ".hpp", ".h"}


def escape_latex(text):
    return (
        text.replace("_", r"\_")
            .replace("&", r"\&")
            .replace("%", r"\%")
            .replace("#", r"\#")
    )


def title(path):
    name = path.stem

    return name.replace("_", " ").replace("-", " ").title()


sections = []

for directory in sorted(ROOT.iterdir()):
    if not directory.is_dir():
        continue

    if directory.name in IGNORE:
        continue

    files = [
        f for f in sorted(directory.iterdir())
        if f.suffix in EXTENSIONS
    ]

    if not files:
        continue

    sections.append(
        rf"\section{{{escape_latex(directory.name.title())}}}"
    )

    for file in files:
        relative = file.relative_to(ROOT)

        sections.append(
            rf"""
\subsection{{{escape_latex(title(file))}}}
\lstinputlisting{{../{relative.as_posix()}}}
"""
        )


template_path = Path(__file__).parent / "template.tex"
template = template_path.read_text(encoding="utf-8")

output = template.replace(
    "%%CONTENT%%",
    "\n".join(sections)
)

(Path(__file__).parent / "notebook.tex").write_text(
    output,
    encoding="utf-8"
)
