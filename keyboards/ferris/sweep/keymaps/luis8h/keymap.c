#include QMK_KEYBOARD_H
#include "quantum.h"
#include "print.h"
#include "tapdance_helper.h"
#if __has_include("keymap.h")
    #include "keymap.h"
#endif

enum custom_keycodes {
    WWW_BACK = SAFE_RANGE,
    WWW_FWD,
    COLEMAK_ON,
    QWERTY_ON
};

// values here do not matter because they are overridden later (they have to be uniqu though)
#define DUAL_FUNC_ALTEXCL LT(104, KC_F14)
#define DUAL_FUNC_TOBASE LT(105, KC_F14)

// Layers
#define L_BASE 0
#define L_QUERTY 1
#define L_SYM 2
#define L_NUMT 3
#define L_SYMSPEC 4
#define L_NUMH 5
#define L_WORKA 6
#define L_WORKAC 7
#define L_ESC 8
#define L_MOVE 9
#define L_SYS 10
#define L_TMUX_MOVE 11

#define K_PC_COPY LCTL(KC_C)
#define K_PC_PASTE LCTL(KC_V)

#define K_PC_UNDO LCTL(KC_Z)
#define K_PC_REDO LCTL(KC_Y)

#define K_PC_BACK LALT(KC_LEFT)
#define K_PC_FWD LALT(KC_RIGHT)
#define K_MAC_BACK LCTL(KC_LBRC)
#define K_MAC_FWD LCTL(KC_RBRC)

// define tap dance keys
enum {
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
};


uint8_t curbase = L_BASE;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_split_3x5_2(
        LALT_T(KC_Q), KC_W, KC_F, KC_P, HYPR_T(KC_B),                               HYPR_T(KC_J), LT(L_WORKAC, KC_L), LT(L_TMUX_MOVE, KC_U), LT(L_WORKA, KC_Y), KC_BSPC,
        LT(L_MOVE, KC_A), LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,               KC_M, LCTL_T(KC_N), LSFT_T(KC_E), LGUI_T(KC_I), LALT_T(KC_O),
        LT(L_MOVE, KC_Z), LT(L_SYMSPEC, KC_X), KC_C, RALT_T(KC_D), KC_V,            KC_K, RALT_T(KC_H), KC_COMM, LT(L_SYMSPEC, KC_DOT), OSL(L_NUMT),
        LT(L_ESC, KC_ESC), LT(L_NUMH, KC_SPC),                                      OSM(MOD_LSFT), OSL(L_SYM)
    ),
    [L_QUERTY] = LAYOUT_split_3x5_2(
        LALT_T(KC_Q), KC_W, KC_E, KC_R, HYPR_T(KC_T),                   KC_Y, LT(L_WORKAC, KC_U), LT(L_TMUX_MOVE, KC_I), LT(L_WORKA, KC_O), LALT_T(KC_P),
        LT(L_MOVE, KC_A), GUI_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,           KC_H, LCTL_T(KC_J), LSFT_T(KC_K), LGUI_T(KC_L), KC_BSPC,
        LT(L_MOVE, KC_Z), LT(L_SYMSPEC, KC_X), KC_C, RALT_T(KC_V), KC_B,        KC_N, RALT_T(KC_M), KC_COMM, LT(L_SYMSPEC, KC_DOT), OSL(L_NUMT),
        LT(L_ESC, KC_ESC), LT(L_NUMH, KC_SPC),                                  OSM(MOD_LSFT), OSL(L_SYM)
    ),
    [L_SYM] = LAYOUT_split_3x5_2(
        DUAL_FUNC_ALTEXCL, KC_AT, KC_HASH, KC_DLR, KC_PERC,                               KC_CIRC, TD(DANCE_4), KC_LPRN, TD(DANCE_3), TD(DANCE_5),
        LALT_T(KC_MINS), LGUI_T(KC_QUOT), TD(DANCE_6), TD(DANCE_7), KC_GRAVE,   KC_PLUS, LCTL_T(KC_SLSH), TD(DANCE_8), TD(DANCE_9), KC_SCLN,
        TD(DANCE_2), KC_SCLN, KC_LBRC, RALT_T(KC_RBRC), KC_EQL,                 KC_TILD, RALT_T(KC_BSLS), KC_COMM, KC_DOT, KC_TRNS,
        DUAL_FUNC_TOBASE, KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_NUMT] = LAYOUT_split_3x5_2(
        KC_DOT, KC_1, KC_2, KC_3, KC_COMM,                                      KC_QUES, KC_PIPE, KC_LPRN, KC_RPRN, TD(DANCE_12),
        LGUI_T(KC_MINS), LALT_T(KC_4), LSFT_T(KC_5), LCTL_T(KC_6), KC_0,        KC_PLUS, LCTL_T(KC_SLSH), TD(DANCE_10), TD(DANCE_11), KC_TRNS,
        LCA_T(QK_LLCK), KC_7, KC_8, RALT_T(KC_9), KC_EQL,                       KC_TILD, RALT_T(KC_BSLS), KC_COMM, KC_DOT, KC_TRNS,
        DUAL_FUNC_TOBASE, KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_SYMSPEC] = LAYOUT_split_3x5_2(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                      KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,                              LT(L_SYS, KC_F7), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, UC(0x00E4), KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        DUAL_FUNC_TOBASE, KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_NUMH] = LAYOUT_split_3x5_2(
        KC_DOT, KC_1, KC_2, KC_3, KC_COMM,                                      KC_QUES, KC_PIPE, KC_LPRN, KC_RPRN, TD(DANCE_12),
        LGUI_T(KC_MINS), LALT_T(KC_4), LSFT_T(KC_5), LCTL_T(KC_6), KC_0,        KC_PLUS, LCTL_T(KC_SLSH), TD(DANCE_10), TD(DANCE_11), KC_TRNS,
        LCA_T(QK_LLCK), KC_7, KC_8, RALT_T(KC_9), KC_EQL,                       KC_TILD, RALT_T(KC_BSLS), KC_COMM, KC_DOT, KC_TRNS,
        DUAL_FUNC_TOBASE, KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_WORKA] = LAYOUT_split_3x5_2(
        KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_0),                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    ),
    [L_WORKAC] = LAYOUT_split_3x5_2(
        KC_TRNS, LCTL(LGUI(KC_1)), LCTL(LGUI(KC_2)), LCTL(LGUI(KC_3)), KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, LCTL(LGUI(KC_4)), LCTL(LGUI(KC_5)), LCTL(LGUI(KC_6)), LCTL(LGUI(KC_0)),                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LCTL(LGUI(KC_7)), LCTL(LGUI(KC_8)), LCTL(LGUI(KC_9)), KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    ),
    [L_ESC] = LAYOUT_split_3x5_2(
        K_PC_COPY, K_PC_PASTE, LCTL(KC_SPC), KC_F8, KC_TRNS,                    KC_TRNS, CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TAB, KC_DEL, KC_LSFT, KC_BSPC, KC_TRNS,                               KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,
        KC_ENT, WWW_BACK, K_PC_UNDO, K_PC_REDO, WWW_FWD,                        KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_ENT, KC_TRNS
    ),
    [L_MOVE] = LAYOUT_split_3x5_2(
        LALT_T(KC_Q), KC_W, KC_UP, KC_R, KC_T,                                          KC_Y, KC_HOME, KC_I, KC_END, LGUI_T(KC_UP),
        KC_A, LGUI_T(KC_LEFT), LSFT_T(KC_DOWN), LCTL_T(KC_RIGHT), KC_G,   KC_LEFT, LCTL_T(KC_DOWN), LSFT_T(KC_UP), LGUI_T(KC_RIGHT), KC_TRNS,
        KC_Z, WWW_BACK, KC_PGDN, KC_PGUP, WWW_FWD,                              KC_DOWN, KC_M, KC_COMM, KC_DOT, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    ),
    [L_SYS] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        QK_BOOTLOADER, KC_TRNS, QWERTY_ON, COLEMAK_ON, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOTLOADER,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        DUAL_FUNC_TOBASE, KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_TMUX_MOVE] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            LCTL(KC_H), LCTL(KC_J), LCTL(KC_K), LCTL(KC_L), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    )
};

// tap dance 2 functions
void on_dance_2(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_on_dance(state, KC_UNDS);
}
void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_dance_finished(state, KC_UNDS, L_MOVE, 1);
}
void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_dance_reset(state, KC_UNDS, L_MOVE, 1);
}

// tap dance 3 functions
void on_dance_3(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_on_dance(state, KC_RPRN);
}
void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_dance_finished(state, KC_RPRN, L_WORKA, 2);
}
void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_dance_reset(state, KC_RPRN, L_WORKA, 2);
}

// tap dance 4 functions
void on_dance_4(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_on_dance(state, KC_AMPR);
}
void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_dance_finished(state, KC_AMPR, L_WORKAC, 3);
}
void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_layer_dance_reset(state, KC_AMPR, L_WORKAC, 3);
}

// tap dance 5 functions
void on_dance_5(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_on_dance(state, KC_ASTR);
}
void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_finished(state, KC_ASTR, KC_LGUI, 4);
}
void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_reset(state, KC_ASTR, KC_LGUI, 4);
}

// tap dance 6 functions
void on_dance_6(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_on_dance(state, KC_LCBR);
}
void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_finished(state, KC_LCBR, KC_LSFT, 5);
}
void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_reset(state, KC_LCBR, KC_LSFT, 5);
}

// tap dance 7 functions
void on_dance_7(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_on_dance(state, KC_RCBR);
}
void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_finished(state, KC_RCBR, KC_LCTL, 6);
}
void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_reset(state, KC_RCBR, KC_LCTL, 6);
}

// tap dance 8 functions
void on_dance_8(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_on_dance(state, KC_DQUO);
}
void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_finished(state, KC_DQUO, KC_LSFT, 7);
}
void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_reset(state, KC_DQUO, KC_LSFT, 7);
}

// tap dance 9 functions
void on_dance_9(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_on_dance(state, KC_COLN);
}
void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_finished(state, KC_COLN, KC_LALT, 8);
}
void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_reset(state, KC_COLN, KC_LALT, 8);
}

// tap dance 10 functions
void on_dance_10(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_on_dance(state, KC_LT);
}
void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_finished(state, KC_LT, KC_LSFT, 9);
}
void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_reset(state, KC_LT, KC_LSFT, 9);
}

// tap dance 11 functions
void on_dance_11(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_on_dance(state, KC_GT);
}
void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_finished(state, KC_GT, KC_LALT, 10);
}
void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_reset(state, KC_GT, KC_LALT, 10);
}

// tap dance 12 functions
void on_dance_12(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_on_dance(state, KC_ASTR);
}
void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_finished(state, KC_ASTR, KC_LGUI, 11);
}
void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    hold_tap_mod_dance_reset(state, KC_ASTR, KC_LGUI, 11);
}

// register tap dance keys
tap_dance_action_t tap_dance_actions[] = {
    [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
    [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
    [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
    [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
    [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
    [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
    [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
    [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
    [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
};

// caps word customisation
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// overrides and os detection
static os_variant_t current_os = OS_UNSURE;
static bool is_macos = false;

#include <string.h>

#define MAX_KEY_OVERRIDES 10
const key_override_t *key_overrides[MAX_KEY_OVERRIDES] = { NULL };

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        set_unicode_input_mode(UNICODE_MODE_MACOS);
        is_macos = true;
    } else {
        set_unicode_input_mode(UNICODE_MODE_LINUX);
        is_macos = false;
    }
    current_os = detected_os;

    // Shift + Backspace → Delete (applies to all OS)
    // static const key_override_t shift_backspace_override =
    //     ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

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
        // &shift_backspace_override,
        NULL
    };

    // macOS-specific key overrides (Shift + Backspace + Ctrl behavior)
    static const key_override_t *mac_key_overrides[] = {
        // &shift_backspace_override,
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
    // pick which source list to copy
    const key_override_t * const *src = (detected_os == OS_MACOS || detected_os == OS_IOS)
        ? mac_key_overrides
        : default_key_overrides
        ;

    // copy pointers into the global array
    // sizeof(src) doesn't work (it's a pointer), so we compute element count manually:
    size_t i = 0;
    for (; src[i] && i < MAX_KEY_OVERRIDES-1; ++i) {
        key_overrides[i] = src[i];
    }
    key_overrides[i] = NULL;
    return true;
}


// macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case DUAL_FUNC_ALTEXCL:
            if (record->tap.count > 0) {
                if (record->event.pressed) register_code16(KC_EXLM);
                else unregister_code16(KC_EXLM);
            } else {
                if (record->event.pressed) register_code16(KC_LEFT_ALT);
                else unregister_code16(KC_LEFT_ALT);
            }
            return false;

        case DUAL_FUNC_TOBASE:
            if (record->tap.count > 0) {
                if (record->event.pressed) layer_move(curbase);
                else layer_move(curbase);
            } else {
                if (record->event.pressed) layer_on(L_ESC);
                else layer_off(L_ESC);
            }
            return false;

        case WWW_FWD:
            if (record->event.pressed) {
                tap_code16(is_macos ? K_MAC_BACK : K_PC_BACK);
                return false;
            }
        case WWW_BACK:
            if (record->event.pressed) {
                tap_code16(is_macos ? K_MAC_FWD : K_PC_FWD);
                return false;
            }
        case COLEMAK_ON:
            if (record->event.pressed) {
                curbase = L_BASE;
                set_single_default_layer(L_BASE);
            }
            return false;
        case QWERTY_ON:
            if (record->event.pressed) {
                curbase = L_QUERTY;
                set_single_default_layer(L_QUERTY);
            }
            return false;
    }
    return true;
}
