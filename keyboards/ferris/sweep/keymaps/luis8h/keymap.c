#include QMK_KEYBOARD_H
#include "quantum.h"
#include "print.h"
#include "tapdance_helper.h"
#if __has_include("keymap.h")
    #include "keymap.h"
#endif

enum custom_keycodes {
    C_RIGHT = SAFE_RANGE,
    C_LEFT,
    C_TAB,
    C_BSPC,
    K_PC_BACK,
    K_PC_FWD,
    COLEMAK_ON,
    QWERTY_ON,
};

// Layers
#define L_BASE 0
#define L_COLE 1
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
#define L_VIM_MOVE 12

#define K_PC_COPY LCTL(KC_C)
#define K_PC_PASTE LCTL(KC_V)
#define K_PC_UNDO LCTL(KC_Z)
#define K_PC_REDO LCTL(KC_Y)

#define K_PC_BACK LALT(KC_LEFT)
#define K_PC_FWD LALT(KC_RIGHT)

// define tap dance keys
enum {
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
};

uint8_t curbase = L_BASE;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_split_3x5_2(
        LGUI_T(KC_Q), KC_W, HYPR_T(KC_E), LT(L_TMUX_MOVE, KC_R), KC_T,                  KC_Y, LT(L_WORKAC, KC_U), HYPR_T(KC_I), LT(L_WORKA, KC_O), LGUI_T(KC_P),
        LT(L_VIM_MOVE, KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), LT(L_VIM_MOVE, KC_G),           KC_H, LCTL_T(KC_J), LSFT_T(KC_K), LALT_T(KC_L), KC_BSPC,
        LT(L_MOVE, KC_Z), LT(L_SYMSPEC, KC_X), KC_C, RALT_T(KC_V), KC_B,        KC_N, RALT_T(KC_M), KC_COMM, LT(L_SYMSPEC, KC_DOT), OSL(L_NUMT),
        LT(L_ESC, KC_ESC), LT(L_NUMH, KC_SPC),                                  OSM(MOD_LSFT), OSL(L_SYM)
    ),
    [L_COLE] = LAYOUT_split_3x5_2(
        LGUI_T(KC_Q), KC_W, HYPR_T(KC_F), LT(L_TMUX_MOVE, KC_P), KC_B,                                       KC_J, LT(L_WORKAC, KC_L), HYPR_T(KC_U), LT(L_WORKA, KC_Y), KC_BSPC,
        LT(L_VIM_MOVE, KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), LT(L_VIM_MOVE, KC_G),               KC_M, LCTL_T(KC_N), LSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),
        LT(L_MOVE, KC_Z), LT(L_SYMSPEC, KC_X), KC_C, RALT_T(KC_D), KC_V,            KC_K, RALT_T(KC_H), KC_COMM, LT(L_SYMSPEC, KC_DOT), OSL(L_NUMT),
        LT(L_ESC, KC_ESC), LT(L_NUMH, KC_SPC),                                      OSM(MOD_LSFT), OSL(L_SYM)
    ),
    [L_SYM] = LAYOUT_split_3x5_2(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                               KC_CIRC, TD(DANCE_4), KC_LPRN, TD(DANCE_3), TD(DANCE_5),
        LGUI_T(KC_MINS), LALT_T(KC_QUOT), TD(DANCE_6), TD(DANCE_7), KC_GRAVE,   KC_PLUS, LCTL_T(KC_SLSH), TD(DANCE_8), TD(DANCE_9), KC_SCLN,
        TD(DANCE_2), KC_SCLN, KC_LBRC, RALT_T(KC_RBRC), KC_EQL,                 KC_TILD, RALT_T(KC_BSLS), KC_COMM, KC_DOT, KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_NUMT] = LAYOUT_split_3x5_2(
        KC_DOT, KC_1, KC_2, KC_3, KC_COMM,                                      KC_QUES, KC_PIPE, KC_LPRN, KC_RPRN, TD(DANCE_12),
        LALT_T(KC_MINS), LGUI_T(KC_4), LSFT_T(KC_5), LCTL_T(KC_6), KC_0,        KC_PLUS, LCTL_T(KC_SLSH), TD(DANCE_10), TD(DANCE_11), KC_TRNS,
        LCA_T(QK_LLCK), KC_7, KC_8, RALT_T(KC_9), KC_EQL,                       KC_TILD, RALT_T(KC_BSLS), KC_COMM, KC_DOT, KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_SYMSPEC] = LAYOUT_split_3x5_2(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                      KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,                              LT(L_SYS, KC_F7), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, UC(0x00E4), KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_NUMH] = LAYOUT_split_3x5_2(
        KC_DOT, KC_1, KC_2, KC_3, KC_COMM,                                      KC_QUES, KC_PIPE, KC_LPRN, KC_RPRN, TD(DANCE_12),
        LALT_T(KC_MINS), LGUI_T(KC_4), LSFT_T(KC_5), LCTL_T(KC_6), KC_0,        KC_PLUS, LCTL_T(KC_SLSH), TD(DANCE_10), TD(DANCE_11), KC_TRNS,
        LCA_T(QK_LLCK), KC_7, KC_8, RALT_T(KC_9), KC_EQL,                       KC_TILD, RALT_T(KC_BSLS), KC_COMM, KC_DOT, KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_WORKA] = LAYOUT_split_3x5_2(
        KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_0),                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LALT(KC_7), LALT(KC_8), LALT(KC_9), KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    ),
    [L_WORKAC] = LAYOUT_split_3x5_2(
        KC_TRNS, LCA(KC_1), LCA(KC_2), LCA(KC_3), KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, LCA(KC_4), LCA(KC_5), LCA(KC_6), LCA(KC_0),                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LCA(KC_7), LCA(KC_8), LCA(KC_9), KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    ),
    [L_ESC] = LAYOUT_split_3x5_2(
        K_PC_COPY, K_PC_PASTE, LCTL(KC_SPC), KC_F8, KC_TRNS,                    KC_TRNS, CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS,
        C_TAB, KC_DEL, KC_LSFT, KC_BSPC, KC_TRNS,                               KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,
        KC_ENT, K_PC_BACK, K_PC_UNDO, K_PC_REDO, K_PC_FWD,                      KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_ENT, KC_TRNS
    ),
    [L_MOVE] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_UP, KC_R, KC_T,                                          KC_Y, KC_HOME, KC_I, KC_END, LGUI_T(KC_UP),
        LGUI_T(KC_A), LALT_T(C_LEFT), LSFT_T(KC_DOWN), LCTL_T(C_RIGHT), KC_G,   C_LEFT, LCTL_T(KC_DOWN), LSFT_T(KC_UP), LALT_T(C_RIGHT), KC_TRNS,
        KC_Z, K_PC_BACK, KC_PGDN, KC_PGUP, K_PC_FWD,                            KC_DOWN, KC_M, KC_COMM, KC_DOT, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    ),
    [L_SYS] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        QK_BOOTLOADER, KC_TRNS, QWERTY_ON, COLEMAK_ON, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOTLOADER,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                   KC_TRNS, KC_TRNS
    ),
    [L_TMUX_MOVE] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            LCTL(KC_H), LCTL(KC_J), LCTL(KC_K), LCTL(KC_L), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    ),
    [L_VIM_MOVE] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS
    ),
};

// tap dance 1 functions
void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            layer_move(curbase);
            break;
        case SINGLE_HOLD:
            layer_on(L_ESC);
            break;
        case DOUBLE_TAP:
            layer_move(curbase);
            break;
        case DOUBLE_SINGLE_TAP:
            layer_move(curbase);
            break;
    }
}
void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (dance_state[0].step == SINGLE_HOLD) {
        layer_off(L_ESC);
    }
    dance_state[0].step = 0;
}

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
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
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


// OS detection
static os_variant_t current_os = OS_UNSURE;
static bool macos_overrides_enabled = false;
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        set_unicode_input_mode(UNICODE_MODE_MACOS);
        macos_overrides_enabled = true;
    } else {
        set_unicode_input_mode(UNICODE_MODE_LINUX);
        macos_overrides_enabled = false;
    }

    current_os = detected_os;
    return true;
}

// overrides
// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t macos_backspace_ctl_override = {
    .trigger_mods      = MOD_MASK_CTRL,
    .trigger           = KC_BSPC,
    .replacement       = A(KC_BSPC),
    .layers            = ~0,
    .negative_mod_mask = 0,
    .suppressed_mods   = MOD_MASK_CTRL,
    .enabled           = &macos_overrides_enabled,
    .options           = ko_options_default,
};

const key_override_t macos_backspace_alt_override = {
    .trigger_mods      = MOD_MASK_ALT,
    .trigger           = KC_BSPC,
    .replacement       = C(KC_BSPC),
    .layers            = ~0,
    .negative_mod_mask = 0,
    .suppressed_mods   = MOD_MASK_ALT,
    .enabled           = &macos_overrides_enabled,
    .options           = ko_options_default,
};

const key_override_t *key_overrides[] = {
	// &delete_key_override,
    &macos_backspace_ctl_override,
    &macos_backspace_alt_override,
    NULL,
};

// macros
void mod_swap(uint16_t key, uint16_t mod1, uint16_t mod2) {
    if (get_mods() & MOD_BIT(mod1) && (current_os == OS_MACOS || current_os == OS_IOS)) {
        del_mods(MOD_BIT(mod1));

        register_code16(mod2);
        tap_code16(key);
        unregister_code16(mod2);

        set_mods(get_mods() | MOD_BIT(mod1));
    }
    else if (get_mods() & MOD_BIT(mod2) && (current_os == OS_MACOS || current_os == OS_IOS)) {
        del_mods(MOD_BIT(mod2));

        register_code16(mod1);
        tap_code16(key);
        unregister_code16(mod1);

        set_mods(get_mods() | MOD_BIT(mod2));
    } else {
        tap_code(key);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // TODO: the mod swap behavior could also be implemented with tap dance in the future (this would probably allow to repeat the key on double press hold)

    switch (keycode) {
        // otherwiese the tap hold behavior would not work in move layer
        case LALT_T(C_RIGHT):
            if (record->event.pressed) {
                mod_swap(KC_RIGHT, KC_LCTL, KC_LALT);
            }
            break;
        case LCTL_T(C_RIGHT):
            if (record->event.pressed) {
                mod_swap(KC_RIGHT, KC_LCTL, KC_LALT);
            }
            break;
        case LALT_T(C_LEFT):
            if (record->event.pressed) {
                mod_swap(KC_RIGHT, KC_LCTL, KC_LALT);
            }
            break;

        // macros for macos on move layer
        case C_RIGHT:
            if (record->event.pressed) {
                mod_swap(KC_RIGHT, KC_LCTL, KC_LALT);
            }
            break;
        case C_LEFT:
            if (record->event.pressed) {
                mod_swap(KC_LEFT, KC_LCTL, KC_LALT);
            }
            break;
        case C_TAB:
            if (record->event.pressed) {
                mod_swap(KC_TAB, KC_LCTL, KC_LGUI);
            }
            break;
        case K_PC_FWD:
            if (record->event.pressed) {
                if (macos_overrides_enabled) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_RGHT)));
                }
            }
            break;
        case K_PC_BACK:
            if (record->event.pressed) {
                if (macos_overrides_enabled) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
                } else {
                    SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
                }
            }
            break;
        case COLEMAK_ON:
            if (record->event.pressed) {
                curbase = L_COLE;
                set_single_default_layer(L_COLE);
            }
            return false;
        case QWERTY_ON:
            if (record->event.pressed) {
                curbase = L_BASE;
                set_single_default_layer(L_BASE);
            }
            return false;
    }
    return true;
}
