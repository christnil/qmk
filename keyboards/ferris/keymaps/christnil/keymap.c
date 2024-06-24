#include QMK_KEYBOARD_H

enum layers {
  COLEMAK_DH,
  SYMBOLS_LAYER,
  NAVIGATION_LAYER,
  MEDIA_LAYER
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK_DH] = LAYOUT(
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  KC_Q, KC_W,         KC_F,         KC_P,               KC_B,
                                                                  KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  KC_A, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T),       KC_G,
                                                                  KC_M, RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I), KC_O,
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  KC_Z, KC_X,         KC_C,         KC_D,               KC_V,
                                                                  KC_K, KC_H, KC_COMM, KC_DOT,  KC_SLSH,
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
                                    MEH_T(KC_SPC), KC_LSFT,
                                                                  KC_RCTL, TO(SYMBOLS_LAYER)
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  ),

  [SYMBOLS_LAYER] = LAYOUT(
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  KC_ESCAPE,      KC_AT,          KC_HASH,        KC_DLR,          KC_PERC,
                                                                                  KC_CIRC, KC_AMPR,         KC_ASTR,         KC_SCLN,         KC_BSPC,
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  LSFT_T(KC_TAB), LCTL_T(KC_EQL), LALT_T(KC_GRV), LGUI_T(KC_QUOT), KC_DQUO,
                                                                                  KC_BSLS, RGUI_T(KC_LCBR), RALT_T(KC_RCBR), RCTL_T(KC_PIPE), RSFT_T(KC_ENT),
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  KC_TILD,        KC_EXLM,        KC_QUES,        KC_UNDS,         KC_MINS,
                                                                                  KC_LBRC, KC_LPRN,         KC_RPRN,         KC_RBRC,         TO(NAVIGATION_LAYER),
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
                                                  TO(COLEMAK_DH),  OSM(MOD_LSFT),
                                                                                  KC_RALT, TO(MEDIA_LAYER) 
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  ),

  [NAVIGATION_LAYER] = LAYOUT(
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  KC_ESCAPE, KC_MS_WH_LEFT, KC_MS_UP,    KC_MS_WH_RIGHT, KC_Q,
                                                                          LALT(KC_LEFT), LCTL(LSFT(KC_TAB)), RCTL(KC_TAB),  LALT(KC_RIGHT), KC_BSPC, 
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  KC_TAB,    KC_MS_LEFT,    KC_MS_DOWN,  KC_MS_RIGHT,    LGUI_T(KC_DEL),
                                                                          KC_LEFT,       KC_DOWN,            KC_UP,         KC_RIGHT,       KC_ENT,     
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  KC_GRV,    KC_MS_BTN2,    KC_MS_WH_UP, KC_MS_WH_DOWN,  KC_LCTL,
                                                                          KC_MS_BTN1,    KC_MS_ACCEL0,       KC_MS_ACCEL1,  KC_MS_ACCEL2,   KC_NO, 
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
                                         TO(COLEMAK_DH), KC_LGUI,
                                                                          KC_RALT,       TO(SYMBOLS_LAYER)
  ),

  [MEDIA_LAYER] = LAYOUT(
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_ESCAPE, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK,       KC_MEDIA_NEXT_TRACK,     LSFT(KC_MINS),
                                                                                                        KC_MINS, KC_7,            KC_8, KC_9, KC_BSPC,
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_TAB,    OSM(MOD_LCTL),       LALT_T(KC_AUDIO_VOL_DOWN), LGUI_T(KC_AUDIO_VOL_UP), KC_PLUS,
                                                                                                        KC_EQL,  KC_4,            KC_5, KC_6, KC_ENTER,
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    QK_BOOT,   KC_KP_ASTERISK,      KC_BRIGHTNESS_DOWN,        KC_BRIGHTNESS_UP,        KC_DOT,
                                                                                                        KC_0,    KC_1,            KC_2, KC_3, TO(NAVIGATION_LAYER),
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
                                                                    TO(COLEMAK_DH),     KC_LGUI,
                                                                                                        KC_RALT, TO(SYMBOLS_LAYER)
  )
};
// clang-format on

// Combos
enum combos {
  AO_ESC,
  RI_SEMI,
  BJ_BOOT
};

const uint16_t PROGMEM ao_combo[] = {KC_A, KC_O, COMBO_END};
const uint16_t PROGMEM ri_combo[] = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM bj_combo[] = {KC_B, KC_J, COMBO_END};

combo_t key_combos[] = {
  [AO_ESC] = COMBO(ao_combo, KC_ESC),
  [RI_SEMI] = COMBO(ri_combo, KC_SCLN),
  [BJ_BOOT] = COMBO(bj_combo, QK_BOOT)
};
