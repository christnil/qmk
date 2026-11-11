# AGENT

This repository is a personal QMK workspace (forked from upstream QMK) used to build firmware for a Ferris Sweep.

If you are making changes as an agent, treat this as a focused, personal layout repo rather than a general upstream QMK contribution target.

The parts that are most interesting here are:
- `keyboards/ferris/` for Ferris Sweep keyboard definitions and board-level behavior.
- `keyboards/ferris/keymaps/christnil/` for a legacy personal keymap variant.
- `keyboards/ferris/keymaps/christnil2/` for a previous personal keymap variant.
- `keyboards/ferris/keymaps/christnil3/` for the **current** personal keymap variant and layout artifacts.

Scope guidance for agents:
- Only `christnilX` layouts are relevant (`christnil`, `christnil2`, and `christnil3`).
- Prioritize `christnil3` unless a task explicitly calls out another variant.
- Ignore unrelated keyboards, keymaps, and generic upstream-wide cleanup unless explicitly requested.

Current hardware/context:
- I currently use a Ferris Sweep keyboard with an **Elite-Pi** controller.
- I maintain and iterate on my own `christnilX` layouts in `keyboards/ferris/keymaps/`.
- The active layout is `christnil3`.

## Generating layout files and images

The `christnil3` keymap includes a script that generates a QMK JSON, a keymap-drawer YAML, and an SVG visualization of the layout. Run it from the repo root:

```sh
./keyboards/ferris/keymaps/christnil3/generate-layout.sh
```

This does the following (in order):
1. Generates `christnil3.json` from `keymap.c` using `qmk c2json`.
2. Generates `christnil3.yaml` from the JSON using the `keymap` CLI (keymap-drawer).
3. Generates `christnil3.svg` from the YAML using `keymap draw`.
4. Updates the `readme.md` with an embedded SVG preview.

### Prerequisites
- `qmk` CLI installed (`brew install qmk/qmk/qmk`).
- `keymap` CLI (keymap-drawer) installed (`pipx install keymap-drawer`).

## Building and flashing firmware (Elite-Pi)

Since the hardware uses an Elite-Pi (RP2040-based), always pass `-e CONVERT_TO=elite_pi` when compiling to produce a `.uf2` file.

### Compile
```sh
qmk compile -kb ferris/sweep -km christnil3 -e CONVERT_TO=elite_pi
```

### Flash (boot the keyboard)
1. Put the Elite-Pi into bootloader mode: double-tap the reset button (or short the RST and GND pins). The board will mount as a USB mass-storage drive.
2. Copy the generated `.uf2` file to the mounted drive:
   ```sh
   cp ~/qmk_firmware/.build/ferris_sweep_christnil3.uf2 /Volumes/RPI-RP2/
   ```
   (The exact mount path may vary; look for the `RPI-RP2` volume.)
3. The board will automatically reboot with the new firmware once the file is copied.
