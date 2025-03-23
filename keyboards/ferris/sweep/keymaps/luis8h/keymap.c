#include QMK_KEYBOARD_H
#include "i18n.h"
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum custom_keycodes {
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,

  // OS_A,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_17,
  DANCE_18,
  DANCE_19,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P,
        LSFT_T(KC_A), LT(5,KC_S), LT(1,KC_D), LT(3,KC_F), KC_G,         KC_H, LT(4,KC_J), LT(2,KC_K), LT(6,KC_L),LSFT_T(KC_SCLN),
        KC_Z, LCTL_T(KC_X), LALT_T(KC_C), KC_V, KC_B,                   KC_N, KC_M, LALT_T(KC_COMM), LCTL_T(KC_DOT), KC_SLSH,
        KC_P0, KC_BSPC,                                                 LT(7,KC_SPC), KC_P1
    ),
    [1] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_WH_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_BTN2, KC_NO, KC_BTN1, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [2] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LGUI, KC_NO, LCTL(KC_LALT), LCA(KC_LSFT), KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_QUOT, KC_TRNS, KC_CIRC, KC_ASTR, KC_AMPR, KC_NO, KC_TRNS, KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_BSLS, KC_GRV, KC_TRNS, RM_PREV, KC_TRNS, KC_TRNS, RM_NEXT),
    [4] = LAYOUT_split_3x5_2(KC_TRNS, KC_COLN, KC_LT, KC_GT, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT, KC_TRNS, KC_NO, KC_EQL, KC_PLUS, KC_PERC, KC_TRNS, KC_EXLM, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_VOLU),
    [5] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [6] = LAYOUT_split_3x5_2(KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [7] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS, DF(1), KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT, KC_TRNS, KC_TAB, KC_NO, KC_TRNS)
};



#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C


bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    // Shift + Backspace → Delete (applies to all OS)
    static const key_override_t shift_backspace_override =
        ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

    // Ctrl + Backspace → Option + Backspace (only for macOS)
    static const key_override_t macos_backspace_ctl_override =
        ko_make_basic(MOD_MASK_CTRL, KC_BSPC, LALT(KC_BSPC));
    static const key_override_t macos_left_ctl_override =
        ko_make_basic(MOD_MASK_CTRL, KC_LEFT, LALT(KC_LEFT));
    static const key_override_t macos_right_ctl_override =
        ko_make_basic(MOD_MASK_CTRL, KC_RIGHT, LALT(KC_RIGHT));

    static const key_override_t macos_backspace_alt_override =
        ko_make_basic(MOD_MASK_ALT, KC_BSPC, LCTL(KC_BSPC));
    static const key_override_t macos_left_alt_override =
        ko_make_basic(MOD_MASK_ALT, KC_LEFT, LCTL(KC_LEFT));
    static const key_override_t macos_right_alt_override =
        ko_make_basic(MOD_MASK_ALT, KC_RIGHT, LCTL(KC_RIGHT));

    static const key_override_t macos_ctl_tab =
        ko_make_basic(MOD_MASK_CTRL, KC_TAB, LGUI(KC_TAB));
    static const key_override_t macos_gui_tab =
        ko_make_basic(MOD_MASK_GUI, KC_TAB, LCTL(KC_TAB));

    // Default key overrides (applies to all OS)
    static const key_override_t *default_key_overrides[] = {
        &shift_backspace_override,
        NULL
    };

    // macOS-specific key overrides (Shift + Backspace + Ctrl behavior)
    static const key_override_t *mac_key_overrides[] = {
        &shift_backspace_override,
        &macos_backspace_ctl_override,
        &macos_left_ctl_override,
        &macos_right_ctl_override,
        &macos_backspace_alt_override,
        &macos_left_alt_override,
        &macos_right_alt_override,
        &macos_ctl_tab,
        &macos_gui_tab,
        NULL
    };

    // Apply overrides based on OS
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            key_overrides = mac_key_overrides;
            break;
        default:
            key_overrides = default_key_overrides;
            break;
    }

    return true;
}

