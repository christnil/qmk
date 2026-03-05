# christnil2 Ferris Sweep keymap

This keymap is based on the Ferris default layout philosophy (8 layers, heavy tap/hold usage), with these main customizations:

- Base alpha layout is Colemak-DH.
- `Cmd`/`GUI` is on hold for the bottom-row index keys: `D` and `H`.

## Build and flash

### Install QMK
```sh
brew install qmk/qmk/qmk
```

### Setup QMK (one-time)
```sh
qmk setup
```

### Compile
```sh
qmk compile -kb ferris/sweep -km christnil2
```

For Elite-Pi (`.uf2` output):
```sh
qmk compile -kb ferris/sweep -km christnil2 -e CONVERT_TO=elite_pi
```

### Flash
```sh
qmk flash -kb ferris/sweep -km christnil2
```

For Elite-Pi, copy the generated `.uf2` file to the board's USB mass-storage drive in boot mode.

## Layer strategy

The layout keeps frequently-used keys on the 34-key base and uses hold behaviors to reach all other functions.

- Layer `0`: Base (Colemak-DH)
- Layer `1`: Mouse
- Layer `2`: Navigation
- Layer `3`: Right symbols
- Layer `4`: Left symbols
- Layer `5`: Function keys
- Layer `6`: Numbers
- Layer `7`: Always accessible (momentary via Space hold)

## Base layer (Layer 0)

Tap behavior is Colemak-DH alpha. Hold behavior is where the layout becomes powerful.

### Home row holds
- `A` / `O`: `Shift` (`LSFT_T`)
- `R` hold: Layer `5` (Function)
- `S` hold: Layer `1` (Mouse)
- `T` hold: Layer `3` (Right symbols)
- `N` hold: Layer `4` (Left symbols)
- `E` hold: Layer `2` (Navigation)
- `I` hold: Layer `6` (Numbers)

### Bottom row holds
- `X` / `.`: `Ctrl`
- `C` / `,`: `Alt`
- `D` / `H`: `Cmd`/`GUI` (requested DH index hold placement)

### Thumbs
- Left home thumb: `Backspace`
- Right home thumb: `Space` tap, Layer `7` hold (`LT(7, KC_SPC)`)
- Outer thumbs: `KC_P0` and `KC_P1` placeholders for your own shortcuts/macros

## Layer 1: Mouse

Mouse movement and click control.

- Right home row: cursor movement (`MS_L`, `MS_D`, `MS_U`, `MS_R`)
- Right top/bottom rows: wheel up/down/left/right and extra clicks
- Transparent keys keep base modifiers available while mousing

## Layer 2: Navigation

Text navigation and window-manager style modifiers.

- Left home row: arrows (`Left`, `Up`, `Down`, `Right`)
- Left top/bottom: `PgUp`, `Home`, `PgDn`, `End`
- Right home row: `GUI`, `Ctrl+Alt`, `Ctrl+Alt+Shift` combos

## Layer 3: Right symbols

Symbols commonly used in shells/programming on the right hand.

- Includes `_`, `|`, `'`, `#`, `~`, `/`, `"`, `$`, `-`, `\`, `` ` ``
- Left home row includes `^`, `*`, `&`
- Thumb keys include RGB mode controls (`RGB_RMOD`, `RGB_MOD`)

## Layer 4: Left symbols

Brackets and paired symbols.

- Includes `{}`, `()`, `[]`, `:`, `<`, `>`, `;`, `@`, `!`, `%`, `=`, `+`
- Thumb keys include volume down/up

## Layer 5: Function keys

Function row in compact cluster form.

- `F1` to `F12` arranged across right-hand columns
- Includes `Ctrl+Alt` shortcut for common desktop/terminal workflows

## Layer 6: Numbers

Number entry in numpad-like grouping with common operators.

- `0-9` plus `/`, `*`, `+`, `-`, `=`

## Layer 7: Always accessible

Accessed by holding Space from any layer.

- Core utility keys: `Esc`, `Del`, `Enter`, `Tab`
- Quick symbols for command/editor flows: `:`, `%`, `/`, `!`
- Default-layer switches: `DF(1)` (Mouse layer default), `DF(0)` (Base default)
- Bootloader key: `QK_BOOT`

## Optional: generate visual layer images

If you want images like the Ferris default docs, the easiest route is `keymap-drawer`.

### Option A: web app
- Use https://keymap-drawer.streamlit.app
- Paste a KLE/QMK-style layout and export SVG/PNG.

### Option B: local CLI
- Install `keymap-drawer` and generate an SVG from this keymap.
- Follow the current conversion commands from the project docs: https://github.com/caksoylar/keymap-drawer
- Commit the generated SVG in this directory and embed it in this README.
