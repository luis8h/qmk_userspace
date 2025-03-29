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
#define L_SYS 10 // TODO: make sys accessible

// first row
#define D_L1_1(key) key
#define D_L1_2(key) key
#define D_L1_3(key) MT(MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI, key)
#define D_L1_4(key) key
#define D_L1_5(key) key
#define D_R1_1(key) key
#define D_R1_2(key) LT(L_WORKAC, key)
#define D_R1_3(key) HYPR_T(key)
#define D_R1_4(key) LT(L_WORKA, key)
#define D_R1_5(key) LGUI_T(key)

// second row
#define D_L2_1(key) MT(MOD_LGUI, key)
#define D_L2_2(key) LALT_T(key)
#define D_L2_3(key) LSFT_T(key)
#define D_L2_4(key) MT(MOD_LCTL, key)
#define D_L2_5(key) key
#define D_R2_1(key) key
#define D_R2_2(key) LCTL_T(key)
#define D_R2_3(key) LSFT_T(key)
#define D_R2_4(key) LALT_T(key)
#define D_R2_4_RIGHT LALT_T(C_RIGHT)
#define D_R2_5() KC_BSPC

// third row
#define D_L3_1(key) LT(L_MOVE, key)
#define D_L3_2(key) LT(L_SYMSPEC, key)
#define D_L3_3(key) key
#define D_L3_4(key) RGUI_T(key)
#define D_L3_5(key) key
#define D_R3_1(key) key
#define D_R3_2(key) RGUI_T(key)
#define D_R3_3(key) key
#define D_R3_4(key) LT(L_SYMSPEC, key)
#define D_R3_5() OSL(L_NUMT)

// thumb cluster
#define D_TL_1() LT(L_ESC, KC_ESC)
#define D_TL_2() LT(L_NUMH, KC_SPC)
#define D_TR_1() OSM(MOD_LSFT)
#define D_TR_2() OSL(L_SYM)


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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_split_3x5_2(
        D_L1_1(KC_Q), D_L1_2(KC_W), D_L1_3(KC_E), D_L1_4(KC_R), D_L1_5(KC_T),                   D_R1_1(KC_Y), D_R1_2(KC_U), D_R1_3(KC_I), D_R1_4(KC_O), D_R1_5(KC_P),
        D_L2_1(KC_A), D_L2_2(KC_S), D_L2_3(KC_D), D_L2_4(KC_F), D_L2_5(KC_G),                   D_R2_1(KC_H), D_R2_2(KC_J), D_R2_3(KC_K), D_R2_4(KC_L), D_R2_5(),
        D_L3_1(KC_Z), D_L3_2(KC_X), D_L3_3(KC_C), D_L3_4(KC_V), D_L3_5(KC_B),                   D_R3_1(KC_N), D_R3_2(KC_M), D_R3_3(KC_COMM), D_R3_4(KC_DOT), D_R3_5(),
        D_TL_1(), D_TL_2(),                                                                     D_TR_1(), D_TR_2()
    ),
    [L_COLE] = LAYOUT_split_3x5_2(
        D_L1_1(KC_Q), D_L1_2(KC_W), D_L1_3(KC_E), D_L1_4(KC_R), D_L1_5(KC_T),                   D_R1_1(KC_Y), D_R1_2(KC_U), D_R1_3(KC_I), D_R1_4(KC_O), D_R1_5(KC_P),
        D_L2_1(KC_A), D_L2_2(KC_S), D_L2_3(KC_D), D_L2_4(KC_F), D_L2_5(KC_G),                   D_R2_1(KC_H), D_R2_2(KC_J), D_R2_3(KC_K), D_R2_4(KC_L), D_R2_5(),
        D_L3_1(KC_Z), D_L3_2(KC_X), D_L3_3(KC_C), D_L3_4(KC_V), D_L3_5(KC_B),                   D_R3_1(KC_N), D_R3_2(KC_M), D_R3_3(KC_COMM), D_R3_4(KC_DOT), D_R3_5(),
        D_TL_1(), D_TL_2(),                                                                     D_TR_1(), D_TR_2()
    ),
    [L_SYM] = LAYOUT_split_3x5_2(
        D_L1_1(KC_EXLM), D_L1_2(KC_AT), KC_HASH, D_L1_4(KC_DLR), D_L1_5(KC_PERC),               D_R1_1(KC_CIRC), TD(DANCE_4), KC_LPRN, TD(DANCE_3), TD(DANCE_5),
        D_L2_1(KC_MINS), D_L2_2(KC_QUOT), TD(DANCE_6), TD(DANCE_7), D_L2_5(KC_GRAVE),           D_R2_1(KC_PLUS), D_R2_2(KC_SLSH), TD(DANCE_8), TD(DANCE_9), KC_TRNS,
        TD(DANCE_2), D_L3_2(KC_SCLN), D_L3_3(KC_LBRC), D_L3_4(KC_RBRC), D_L3_5(KC_EQL),         D_R3_1(KC_TILD), D_R3_2(KC_BSLS), D_R3_3(KC_COMM), D_R3_4(KC_DOT), KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                                   KC_TRNS, KC_TRNS
    ),
    [L_NUMT] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, TO(L_SYMSPEC), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                                       KC_TRNS, KC_TRNS
    ),
    [L_SYMSPEC] = LAYOUT_split_3x5_2(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                                      KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,                                              LT(L_SYS, KC_F7), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, UC(0x00E4), KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                                       KC_TRNS, KC_TRNS
    ),
    [L_NUMH] = LAYOUT_split_3x5_2(
        D_L1_1(KC_DOT), D_L1_2(KC_1), D_L1_3(KC_2), D_L1_4(KC_3), D_L1_5(KC_COMM),              D_R1_1(KC_QUES), D_R1_2(KC_PIPE), D_R1_3(KC_LPRN), D_R1_4(KC_RPRN), D_R1_5(KC_ASTR),
        LALT_T(KC_MINS), LGUI_T(KC_4), D_L2_3(KC_5), D_L2_4(KC_6), D_L2_5(KC_0),             D_R2_1(KC_PLUS), LSFT_T(KC_LT), D_R2_3(KC_GT), D_R2_4(KC_COLN), KC_TRNS,
        LCA_T(QK_LLCK), D_L3_2(KC_7), D_L3_3(KC_8), D_L3_4(KC_9), D_L3_5(KC_EQL),               D_R3_1(KC_TILD), D_R3_2(KC_BSLS), D_R3_3(KC_COMM), D_R3_4(KC_DOT), KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                                       KC_TRNS, KC_TRNS
    ),
    [L_WORKA] = LAYOUT_split_3x5_2(
        KC_TRNS, LALT(KC_1), LALT(KC_2), LALT(KC_3), KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_0),                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LALT(KC_7), LALT(KC_8), LALT(KC_9), KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                                       KC_TRNS, KC_TRNS
    ),
    [L_WORKAC] = LAYOUT_split_3x5_2(
        KC_TRNS, LCA(KC_1), LCA(KC_2), LCA(KC_3), KC_TRNS,                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, LCA(KC_4), LCA(KC_5), LCA(KC_6), LCA(KC_0),                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LCA(KC_7), LCA(KC_8), LCA(KC_9), KC_TRNS,                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                                       KC_TRNS, KC_TRNS
    ),
    [L_ESC] = LAYOUT_split_3x5_2(
        KC_COPY, KC_PASTE, LCTL(KC_SPC), KC_F8, KC_TRNS,                                        KC_TRNS, CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS,
        C_TAB, KC_DEL, KC_LSFT, KC_TRNS, KC_BSPC,                                              KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,
        KC_ENT, KC_WBAK, KC_UNDO, KC_AGIN, KC_WFWD,                                             KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                                       KC_ENT, KC_TRNS
    ),
    [L_MOVE] = LAYOUT_split_3x5_2(
        D_L1_1(KC_Q), D_L1_2(KC_W), D_L1_3(KC_UP), D_L1_4(KC_R), D_L1_5(KC_T),                  D_R1_1(KC_HOME), D_R1_2(KC_U), D_R1_3(KC_I), D_R1_4(KC_END), D_R1_5(KC_UP),
        D_L2_1(KC_A), D_L2_2(C_LEFT), D_L2_3(KC_DOWN), D_L2_4(C_RIGHT), D_L2_5(KC_G),          D_R2_1(C_LEFT), D_R2_2(KC_DOWN), D_R2_3(KC_UP), D_R2_4(C_RIGHT), KC_TRNS,
        D_L3_1(KC_Z), D_L3_2(KC_WBAK), D_L3_3(KC_PGUP), D_L3_4(KC_PGDN), D_L3_5(KC_WFWD),       D_R3_1(KC_DOWN), D_R3_2(KC_M), D_R3_3(KC_COMM), D_R3_4(KC_DOT), KC_TRNS,
        D_TL_1(), D_TL_2(),                                                                     D_TR_1(), D_TR_2()
    ),
    [L_SYS] = LAYOUT_split_3x5_2(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        QK_BOOTLOADER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOTLOADER,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TD(DANCE_1), KC_TRNS,                                                                       KC_TRNS, KC_TRNS
    ),
};

// tap dance 1 functions
void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            layer_move(L_BASE);
            break;
        case SINGLE_HOLD:
            layer_on(L_ESC);
            break;
        case DOUBLE_TAP:
            layer_move(L_BASE);
            break;
        case DOUBLE_SINGLE_TAP:
            layer_move(L_BASE);
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
};


// OS detection
static os_variant_t current_os = OS_UNSURE;
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        set_unicode_input_mode(UNICODE_MODE_MACOS);
    } else {
        set_unicode_input_mode(UNICODE_MODE_LINUX);
    }

    current_os = detected_os;
    return true;
}

// overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t *key_overrides[] = {
	&delete_key_override
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
    switch (keycode) {
        // otherwiese the tap hold behavior would not work in move layer
        case D_R2_4(C_RIGHT):
            if (record->event.pressed) {
                mod_swap(KC_RIGHT, KC_LCTL, KC_LALT);
            }
            break;
        case D_L2_4(C_RIGHT):
            if (record->event.pressed) {
                mod_swap(KC_RIGHT, KC_LCTL, KC_LALT);
            }
            break;
        case D_L2_2(C_LEFT):
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
        // case C_BSPC:
        //     if (record->event.pressed) {
        //         mod_swap(KC_BSPC, KC_LCTL, KC_LALT);
        //     }
        //     break;

        // macos rewrite
        case KC_BSPC:
            if (record->event.pressed) {
                mod_swap(KC_BSPC, KC_LCTL, KC_LALT);
            }
            break;

        // fix tap hold behavior
        case LSFT_T(KC_LT):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LT); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}
