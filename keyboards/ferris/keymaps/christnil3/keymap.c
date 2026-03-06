#include QMK_KEYBOARD_H

enum layers {
    COLEMAK_DH_LAYER,
    NAVIGATION_LAYER,
    NUMBERS_LAYER,
    SYMBOLS_LAYER,
    ALWAYS_ACCESSIBLE_LAYER,
    FUNCTION_MEDIA_LAYER,
    QWERTY_LAYER,
};

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK_DH_LAYER] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    LT(ALWAYS_ACCESSIBLE_LAYER, KC_TAB), LT(NAVIGATION_LAYER, KC_BSPC), LT(SYMBOLS_LAYER, KC_SPC), LT(NUMBERS_LAYER, KC_ENT)
  ),

  [QWERTY_LAYER] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    LT(ALWAYS_ACCESSIBLE_LAYER, KC_TAB), LT(NAVIGATION_LAYER, KC_BSPC), LT(SYMBOLS_LAYER, KC_SPC), LT(NUMBERS_LAYER, KC_ENT)
  ),

  [NAVIGATION_LAYER] = LAYOUT_split_3x5_2(
    KC_ESC,  KC_TRNS, KC_HOME, KC_UP,   KC_END,  LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP),   LCTL(KC_RGHT), KC_BSPC,
    KC_TAB,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_LEFT, KC_DOWN,       KC_UP,   KC_RGHT,       KC_ENT,
    KC_TRNS, KC_TRNS, KC_INS,  KC_PGUP, KC_PGDN, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), KC_DEL,
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

  [ALWAYS_ACCESSIBLE_LAYER] = LAYOUT_split_3x5_2(
    OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI), KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, QWERTY, COLEMAK,
    OSM(MOD_MEH),  OSM(MOD_HYPR), KC_ESC,        KC_ENT,        KC_BSPC, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_TAB,        KC_TRNS,       KC_TRNS,       KC_TRNS,       QK_BOOT, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_DEL,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [FUNCTION_MEDIA_LAYER] = LAYOUT_split_3x5_2(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, NAVIGATION_LAYER, NUMBERS_LAYER, FUNCTION_MEDIA_LAYER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case COLEMAK:
            set_single_persistent_default_layer(COLEMAK_DH_LAYER);
            return false;
        case QWERTY:
            set_single_persistent_default_layer(QWERTY_LAYER);
            return false;
    }

    return true;
}
