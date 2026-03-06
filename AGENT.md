# AGENT

This repository is a personal QMK workspace (forked from upstream QMK) used to build firmware for a Ferris Sweep.

If you are making changes as an agent, treat this as a focused, personal layout repo rather than a general upstream QMK contribution target.

The parts that are most interesting here are:
- `keyboards/ferris/` for Ferris Sweep keyboard definitions and board-level behavior.
- `keyboards/ferris/keymaps/christnil/` for one personal keymap variant.
- `keyboards/ferris/keymaps/christnil2/` for the current personal keymap variant and layout artifacts.

Scope guidance for agents:
- Only `christnilX` layouts are relevant (`christnil` and `christnil2`).
- Prioritize `christnil2` unless a task explicitly calls out `christnil`.
- Ignore unrelated keyboards, keymaps, and generic upstream-wide cleanup unless explicitly requested.

Current hardware/context:
- I currently use a Ferris Sweep keyboard.
- I maintain and iterate on my own `christnilX` layouts in `keyboards/ferris/keymaps/`.
