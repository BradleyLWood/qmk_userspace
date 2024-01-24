#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _DVORAK 1
#define _COLEMAK 2
#define _RAISE 4
#define _LOWER 3

// #define SFT_ESC  SFT_T(KC_ESC)
// #define CTL_BSPC CTL_T(KC_BSPC)
// #define ALT_SPC  ALT_T(KC_SPC)
// #define SFT_ENT  SFT_T(KC_ENT)
//
// #define KC_ML KC_MS_LEFT
// #define KC_MR KC_MS_RIGHT
// #define KC_MU KC_MS_UP
// #define KC_MD KC_MS_DOWN
// #define KC_MB1 KC_MS_BTN1
// #define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
        KC_TAB,  KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,            KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_APP,
        KC_ESC,  KC_A,   KC_S,    KC_D,   KC_F,    KC_G,            KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_CAPS, KC_Z,   KC_X,    KC_C,   KC_V,    KC_B,            KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, DF(0),
                         KC_MINS, KC_EQL,                                           KC_LBRC, KC_RBRC,
                                          KC_BSPC, KC_LSFT,         KC_SPC, KC_ENT,
                                          RAISE,   LOWER,           TG(2),  TG(1),
                                          KC_LCTL, KC_LGUI,         KC_DEL, KC_LALT
    ),

	[_DVORAK] = LAYOUT(
        KC_TAB,  KC_SCLN, KC_COMM, KC_DOT, KC_P,    KC_Y,           KC_F,    KC_G,    KC_C,    KC_R, KC_L, KC_SLSH,
        KC_ESC,  KC_A,    KC_O,    KC_E,   KC_U,    KC_I,           KC_D,    KC_H,    KC_T,    KC_N, KC_S, KC_BSLS,
        KC_CAPS, KC_QUOT, KC_Q,    KC_J,   KC_K,    KC_X,           KC_B,    KC_M,    KC_W,    KC_V, KC_Z, DF(3),
                          KC_MINS, KC_EQL,                                   KC_LBRC, KC_RBRC,
                                           KC_BSPC, KC_LSFT,        KC_SPC,  KC_ENT,
                                           RAISE,   LOWER,          KC_TRNS, TO(4),
                                           KC_LCTL, KC_LGUI,        KC_DEL,  KC_LALT
    ),

	[_COLEMAK] = LAYOUT(
        KC_TAB,  KC_Q, KC_W,    KC_F,   KC_P,    KC_G,              KC_J,   KC_L,     KC_U, KC_Y, KC_SCLN, KC_BSLS,
        KC_ESC,  KC_A, KC_R,    KC_S,   KC_T,    KC_D,              KC_H,   KC_N,     KC_E, KC_I, KC_O, KC_QUOT,
        KC_CAPS, KC_Z, KC_X,    KC_C,   KC_V,    KC_B,              KC_K,   KC_M,     KC_COMM, KC_DOT, KC_SLSH, DF(4),
                       KC_MINS, KC_EQL,                                               KC_LBRC, KC_RBRC,
                                        KC_BSPC, KC_LSFT,           KC_SPC, KC_ENT,
                                        RAISE,   LOWER,             TG(3),  KC_NO,
                                        KC_LCTL, KC_LGUI,           KC_DEL, KC_LALT
    ),

	[_LOWER] = LAYOUT(
        KC_TRNS, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_MPRV, KC_MPLY,    KC_MNXT, KC_TRNS, KC_TRNS, KC_PSCR,
        KC_TRNS, KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,         KC_LEFT, KC_DOWN,    KC_UP, KC_RGHT, KC_TRNS, KC_INS,
        QK_BOOT, KC_F11, KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS,        KC_MUTE, KC_VOLD,    KC_VOLU, KC_TRNS, KC_TRNS, KC_SCRL,
                         KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,        KC_TRNS, TG(_LOWER),
                                           KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
    ),

	[_RAISE] = LAYOUT(
        KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,    KC_P7, KC_P8,   KC_P9, KC_PLUS, KC_TRNS,
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LPRN,       KC_RPRN,    KC_P4, KC_P5,   KC_P6, KC_MINS, KC_TRNS,
        KC_PIPE, KC_PERC, KC_AMPR, KC_ASTR, KC_UNDS, KC_LBRC,       KC_RBRC,    KC_P1, KC_P2,   KC_P3, KC_EQL, KC_TRNS,
                          KC_PAUS, KC_PSCR,                                            KC_P0, KC_PDOT,
                                            KC_TRNS, KC_TRNS,       KC_TRNS,    KC_TRNS,
                                            KC_TRNS, KC_TRNS,       TG(_RAISE), KC_TRNS,
                                            KC_TRNS, KC_TRNS,       KC_TRNS,    KC_TRNS
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}


