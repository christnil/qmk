#!/usr/bin/env bash
set -euo pipefail

KEYBOARD="ferris/sweep"
KEYMAP="christnil3"
KEYMAP_DIR="keyboards/ferris/keymaps/christnil3"
README_PATH="$KEYMAP_DIR/readme.md"
SVG_NAME="christnil3.svg"
YAML_NAME="christnil3.yaml"
JSON_NAME="christnil3.json"

if ! command -v qmk >/dev/null 2>&1; then
  echo "Error: qmk is not installed or not on PATH." >&2
  exit 1
fi

KEYMAP_CLI=""
if command -v keymap >/dev/null 2>&1; then
  KEYMAP_CLI="keymap"
elif [ -x "$HOME/.local/bin/keymap" ]; then
  KEYMAP_CLI="$HOME/.local/bin/keymap"
else
  echo "Error: keymap-drawer CLI ('keymap') is not installed or not on PATH." >&2
  echo "Install with: pipx install keymap-drawer" >&2
  exit 1
fi

REPO_ROOT="$(git rev-parse --show-toplevel)"

cd "$REPO_ROOT"

echo "Generating QMK JSON..."
qmk c2json -kb "$KEYBOARD" -km "$KEYMAP" "$KEYMAP_DIR/keymap.c" > "$KEYMAP_DIR/$JSON_NAME"

echo "Generating keymap-drawer YAML..."
"$KEYMAP_CLI" parse -c 10 -q "$KEYMAP_DIR/$JSON_NAME" > "$KEYMAP_DIR/$YAML_NAME"

echo "Generating SVG layout..."
"$KEYMAP_CLI" draw "$KEYMAP_DIR/$YAML_NAME" > "$KEYMAP_DIR/$SVG_NAME"

START_MARKER="<!-- layout-preview:start -->"
END_MARKER="<!-- layout-preview:end -->"
PREVIEW_BLOCK="$START_MARKER\n![christnil3 layout](./$SVG_NAME)\n$END_MARKER"

python3 - "$README_PATH" "$PREVIEW_BLOCK" <<'PY'
import re
import sys

path = sys.argv[1]
block = sys.argv[2]
block = block.replace("\\n", "\n")

with open(path, "r", encoding="utf-8") as f:
    text = f.read()

if "<!-- layout-preview:start -->" in text and "<!-- layout-preview:end -->" in text:
    text = re.sub(
        r"<!-- layout-preview:start -->.*?<!-- layout-preview:end -->",
        block,
        text,
        flags=re.S,
    )
else:
    text = text.rstrip() + "\n\n## Layout preview\n\n" + block + "\n"

with open(path, "w", encoding="utf-8") as f:
    f.write(text)
PY

echo "Done. Updated files:"
echo "- $KEYMAP_DIR/$JSON_NAME"
echo "- $KEYMAP_DIR/$YAML_NAME"
echo "- $KEYMAP_DIR/$SVG_NAME"
echo "- $README_PATH"
