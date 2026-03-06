#!/usr/bin/env bash
set -euo pipefail

KEYBOARD="ferris/sweep"
KEYMAP="christnil2"
KEYMAP_DIR="keyboards/ferris/keymaps/christnil2"
README_PATH="$KEYMAP_DIR/readme.md"
SVG_NAME="christnil2.svg"
YAML_NAME="christnil2.yaml"

if ! command -v qmk >/dev/null 2>&1; then
  echo "Error: qmk is not installed or not on PATH." >&2
  exit 1
fi

if ! command -v keymap >/dev/null 2>&1; then
  echo "Error: keymap-drawer CLI ('keymap') is not installed or not on PATH." >&2
  echo "Install with: pipx install keymap-drawer" >&2
  exit 1
fi

REPO_ROOT="$(git rev-parse --show-toplevel)"
TMP_DIR="$(mktemp -d)"
trap 'rm -rf "$TMP_DIR"' EXIT

cd "$REPO_ROOT"

echo "Generating QMK JSON..."
qmk c2json -kb "$KEYBOARD" -km "$KEYMAP" "$KEYMAP_DIR/keymap.c" > "$TMP_DIR/$KEYMAP.json"

echo "Generating keymap-drawer YAML..."
keymap parse -c 10 -q "$TMP_DIR/$KEYMAP.json" > "$KEYMAP_DIR/$YAML_NAME"

echo "Generating SVG layout..."
keymap draw "$KEYMAP_DIR/$YAML_NAME" > "$KEYMAP_DIR/$SVG_NAME"

START_MARKER="<!-- layout-preview:start -->"
END_MARKER="<!-- layout-preview:end -->"
PREVIEW_BLOCK="$START_MARKER\n![christnil2 layout](./$SVG_NAME)\n$END_MARKER"

if grep -q "$START_MARKER" "$README_PATH" && grep -q "$END_MARKER" "$README_PATH"; then
  python3 - "$README_PATH" "$PREVIEW_BLOCK" <<'PY'
import re
import sys

path = sys.argv[1]
block = sys.argv[2]

with open(path, "r", encoding="utf-8") as f:
    text = f.read()

text = re.sub(
    r"<!-- layout-preview:start -->.*?<!-- layout-preview:end -->",
    block,
    text,
    flags=re.S,
)

with open(path, "w", encoding="utf-8") as f:
    f.write(text)
PY
else
  cat >> "$README_PATH" <<EOF

## Layout preview

$START_MARKER
![christnil2 layout](./$SVG_NAME)
$END_MARKER
EOF
fi

echo "Done. Updated files:"
echo "- $KEYMAP_DIR/$YAML_NAME"
echo "- $KEYMAP_DIR/$SVG_NAME"
echo "- $README_PATH"
