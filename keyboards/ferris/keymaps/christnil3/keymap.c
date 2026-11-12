#include QMK_KEYBOARD_H

// Thumbs (left to right): Space/ALWAYS_ACCESSIBLE, Tab/WM, Bksp/SYMBOLS, Enter/NUMBERS.
// WM + NUMBERS held together = FUNCTION_MEDIA (tri-layer).
enum layers { COLEMAK_DH_LAYER, WM_LAYER, NUMBERS_LAYER, SYMBOLS_LAYER, ALWAYS_ACCESSIBLE_LAYER, FUNCTION_MEDIA_LAYER };

// WM layer: every key sends its own MEH (Ctrl+Alt+Shift) or HYPR (MEH+GUI) combo, so
// holding the thumb and tapping a key repeatedly (e.g. rotate) works like holding SUPER.
// Hyprland (Linux) and Aerospace (macOS) bind the same combos; no OS detection needed.
//   MEH  = go / focus / act        HYPR = move (window to workspace, window in direction)
#define WM_WS1 MEH(KC_1)
#define WM_WS2 MEH(KC_2)
#define WM_WS3 MEH(KC_3)
#define WM_WS4 MEH(KC_4)
#define WM_WS5 MEH(KC_5)
#define WM_MV1 HYPR(KC_1)
#define WM_MV2 HYPR(KC_2)
#define WM_MV3 HYPR(KC_3)
#define WM_MV4 HYPR(KC_4)
#define WM_MV5 HYPR(KC_5)
#define WM_FL MEH(KC_LEFT)   // focus
#define WM_FD MEH(KC_DOWN)
#define WM_FU MEH(KC_UP)
#define WM_FR MEH(KC_RGHT)
#define WM_ML HYPR(KC_LEFT)  // move window
#define WM_MD HYPR(KC_DOWN)
#define WM_MU HYPR(KC_UP)
#define WM_MR HYPR(KC_RGHT)
#define WM_PREV MEH(KC_TAB)  // previous workspace
#define WM_PROM MEH(KC_ENT)  // promote to master
#define WM_RPRV MEH(KC_COMM) // rotate previous
#define WM_RNXT MEH(KC_DOT)  // rotate next
#define WM_HELP MEH(KC_SLSH) // cheat sheet
#define WM_SCR MEH(KC_S)     // scratchpad
#define WM_AGNT MEH(KC_A)    // agents
#define WM_CLOS HYPR(KC_C)   // close window (HYPR on purpose: harder to hit by accident)
#define WM_FLT MEH(KC_V)     // float toggle
#define WM_ZEN MEH(KC_Z)     // fullscreen / zen (not F: Aerospace uses MEH+F for workspace 3)
#define WM_FLIP MEH(KC_T)    // flip split
#define WM_GRP MEH(KC_G)     // tab group

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK_DH_LAYER] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    LT(ALWAYS_ACCESSIBLE_LAYER, KC_SPC), LT(WM_LAYER, KC_TAB), LT(SYMBOLS_LAYER, KC_BSPC), LT(NUMBERS_LAYER, KC_ENT)
  ),

  // Window manager (hold Tab thumb). Left: workspaces. Right: focus/move/rotate.
  // Focus/move arrows sit on N E I O like the arrows on the Space layer.
  [WM_LAYER] = LAYOUT_split_3x5_2(
    WM_MV1,  WM_MV2,  WM_MV3,  WM_MV4,  WM_MV5,  WM_PREV, WM_ML,   WM_MD,   WM_MU,   WM_MR,
    WM_WS1,  WM_WS2,  WM_WS3,  WM_WS4,  WM_WS5,  WM_PROM, WM_FL,   WM_FD,   WM_FU,   WM_FR,
    WM_CLOS, WM_FLT,  WM_ZEN,  WM_FLIP, WM_GRP,  WM_SCR,  WM_AGNT, WM_RPRV, WM_RNXT, WM_HELP,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [NUMBERS_LAYER] = LAYOUT_split_3x5_2(
    KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_PEQL, KC_7,    KC_8,    KC_9,    KC_BSPC, KC_TRNS,
    KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_PERC, KC_4,    KC_5,    KC_6,    KC_0,    KC_DOT,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_COMM, KC_ENT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [SYMBOLS_LAYER] = LAYOUT_split_3x5_2(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_GRV,
    KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_EQL,  KC_UNDS, KC_MINS, KC_PLUS, KC_SLSH, KC_BSLS,
    KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   KC_TILD, KC_COLN, KC_SCLN, KC_DQUO, KC_QUOT, KC_QUES,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Hold Space: one-shot mods + navigation. Home/PgDn/PgUp/End (from the old NAV layer)
  // sit above the arrows.
  [ALWAYS_ACCESSIBLE_LAYER] = LAYOUT_split_3x5_2(
    OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), KC_CAPS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    OSM(MOD_MEH),  OSM(MOD_HYPR), KC_ESC,        KC_ENT,        KC_BSPC, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_TAB,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_DEL,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  // Hold Tab + Enter thumbs. QK_BOOT lives here now (was Space+V, too easy to hit).
  [FUNCTION_MEDIA_LAYER] = LAYOUT_split_3x5_2(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_INS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, WM_LAYER, NUMBERS_LAYER, FUNCTION_MEDIA_LAYER);
}
