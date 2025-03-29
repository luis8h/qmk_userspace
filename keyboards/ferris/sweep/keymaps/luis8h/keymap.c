#include QMK_KEYBOARD_H
#include "tapdance_helper.h"
#if __has_include("keymap.h")
    #include "keymap.h"
#endif

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

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
        LALT_T(KC_MINS), LGUI_T(KC_4), D_L2_3(KC_5), D_L2_4(KC_6), D_L2_5(KC_0),             D_R2_1(KC_PLUS), D_R2_2(KC_LT), D_R2_3(KC_GT), D_R2_4(KC_COLN), KC_TRNS,
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
        KC_TAB, KC_DEL, KC_LSFT, KC_TRNS, KC_BSPC,                                              KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,
        KC_ENT, KC_WBAK, KC_UNDO, KC_AGIN, KC_WFWD,                                             KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                                                                       KC_ENT, KC_TRNS
    ),
    [L_MOVE] = LAYOUT_split_3x5_2(
        D_L1_1(KC_Q), D_L1_2(KC_W), D_L1_3(KC_UP), D_L1_4(KC_R), D_L1_5(KC_T),                  D_R1_1(KC_HOME), D_R1_2(KC_U), D_R1_3(KC_I), D_R1_4(KC_END), D_R1_5(KC_UP),
        D_L2_1(KC_A), D_L2_2(KC_LEFT), D_L2_3(KC_DOWN), D_L2_4(KC_RGHT), D_L2_5(KC_G),          D_R2_1(KC_LEFT), D_R2_2(KC_DOWN), D_R2_3(KC_UP), D_R2_4(KC_RGHT), KC_TRNS,
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




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Only process these substitutions if the host is macOS or iOS.
    if (current_os == OS_MACOS || current_os == OS_IOS) {
        // -------------------------
        // General override:
        // Shift + Backspace -> Delete
        // -------------------------
        if (keycode == KC_BSPC && (get_mods() & MOD_MASK_SHIFT)) {
            if (record->event.pressed) {
                register_code16(KC_DEL);
            } else {
                unregister_code16(KC_DEL);
            }
            return false;
        }

        // -------------------------
        // macOS Ctrl overrides:
        // Ctrl + Backspace -> LALT + Backspace
        // Ctrl + Left    -> LALT + Left Arrow
        // Ctrl + Right   -> LALT + Right Arrow
        // -------------------------
        if (keycode == KC_BSPC && (get_mods() & MOD_MASK_CTRL)) {
            if (record->event.pressed) {
                register_code16(LALT(KC_BSPC));
            } else {
                unregister_code16(LALT(KC_BSPC));
            }
            return false;
        }
        if (keycode == KC_LEFT && (get_mods() & MOD_MASK_CTRL)) {
            if (record->event.pressed) {
                register_code16(LALT(KC_LEFT));
            } else {
                unregister_code16(LALT(KC_LEFT));
            }
            return false;
        }
        if (keycode == KC_B && (get_mods() & MOD_MASK_CTRL)) {
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                mods &= ~MOD_MASK_CTRL;
                set_mods(mods);
                register_code16(LALT(KC_RGHT));
            } else {
                unregister_code16(LALT(KC_RGHT));
            }
            return false;
        }

        // -------------------------
        // macOS Alt overrides:
        // Alt + Backspace -> LCTL + Backspace
        // Alt + Left    -> LCTL + Left Arrow
        // Alt + Right   -> LCTL + Right Arrow
        // -------------------------
        if (keycode == KC_BSPC && (get_mods() & MOD_MASK_ALT)) {
            if (record->event.pressed) {
                register_code16(LCTL(KC_BSPC));
            } else {
                unregister_code16(LCTL(KC_BSPC));
            }
            return false;
        }
        if (keycode == KC_LEFT && (get_mods() & MOD_MASK_ALT)) {
            if (record->event.pressed) {
                register_code16(LCTL(KC_LEFT));
            } else {
                unregister_code16(LCTL(KC_LEFT));
            }
            return false;
        }
        if (keycode == KC_RGHT && (get_mods() & MOD_MASK_ALT)) {
            if (record->event.pressed) {
                register_code16(LCTL(KC_RGHT));
            } else {
                unregister_code16(LCTL(KC_RGHT));
            }
            return false;
        }

        // -------------------------
        // macOS Tab overrides:
        // Ctrl + Tab -> LGUI + Tab
        // GUI + Tab  -> LCTL + Tab
        // -------------------------
        if (keycode == KC_TAB && (get_mods() & MOD_MASK_CTRL)) {
            if (record->event.pressed) {
                register_code16(LGUI(KC_TAB));
            } else {
                unregister_code16(LGUI(KC_TAB));
            }
            return false;
        }
        if (keycode == KC_TAB && (get_mods() & MOD_MASK_GUI)) {
            if (record->event.pressed) {
                register_code16(LCTL(KC_TAB));
            } else {
                unregister_code16(LCTL(KC_TAB));
            }
            return false;
        }
    }
    // Process all other keycodes normally.
    return true;
}






// overrides

// Custom callback for key override.
typedef struct {
    uint16_t replacement;
    uint16_t original;
} os_override_ctx_t;
bool os_specific_override(bool key_down, void *ctx) {
    os_override_ctx_t *override_ctx = (os_override_ctx_t *)ctx;
    if (current_os == OS_MACOS || current_os == OS_IOS) {
        // For macOS/iOS, send the replacement key.
        if (key_down) {
            register_code16(override_ctx->replacement);
        } else {
            unregister_code16(override_ctx->replacement);
        }
    } else {
        // For other OSes (e.g., Linux), re-send the original key.
        if (key_down) {
            register_code16(override_ctx->original);
        } else {
            unregister_code16(override_ctx->original);
        }
    }
    return false;
}

// define custom overrides

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// const key_override_t macos_right_ctl_override = ko_make_basic(MOD_MASK_CTRL, KC_B, KC_A);
//
// static const os_override_ctx_t macos_backspace_ctl_override_ctx = {
//     .replacement = A(KC_BSPC), // Replacement for macOS: Alt+Backspace.
//     .original    = G(KC_BSPC)  // Original key.
// };
// const key_override_t macos_backspace_ctl_override = {
//     .trigger_mods      = MOD_MASK_GUI,
//     .trigger           = KC_BSPC,
//     .layers            = ~0,                    // Active on all layers.
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,                     // Do not suppress modifiers.
//     .custom_action     = os_specific_override,  // Our custom callback.
//     .context           = (void *)&macos_backspace_ctl_override_ctx,
//     .replacement       = KC_NO,                 // Not used since our callback handles it.
//     .enabled           = NULL,
//     .options           = ko_options_default,
// };
//
// // Left Arrow (Ctrl → Alt)
// static const os_override_ctx_t macos_left_ctl_override_ctx = {
//     .replacement = A(KC_LEFT),
//     .original    = G(KC_LEFT)
// };
// const key_override_t macos_left_ctl_override = {
//     .trigger_mods      = MOD_MASK_GUI,
//     .trigger           = KC_LEFT,
//     .layers            = ~0,
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,
//     .custom_action     = os_specific_override,
//     .context           = (void *)&macos_left_ctl_override_ctx,
//     .replacement       = KC_NO,
//     .enabled           = NULL,
//     .options           = ko_options_default,
// };
//
// // Right Arrow (Ctrl → Alt)
// // static const os_override_ctx_t macos_right_ctl_override_ctx = {
// //     .replacement = A(KC_RGHT),
// //     .original    = C(KC_RGHT)
// // };
// // const key_override_t macos_right_ctl_override = {
// //     .trigger_mods      = MOD_MASK_CTRL,
// //     .trigger           = KC_RGHT,
// //     // .layers            = 1 << L_MOVE,
// //     // .negative_mod_mask = 0,
// //     .suppressed_mods   = MOD_MASK_CTRL,
// //     // .custom_action     = os_specific_override,
// //     // .context           = (void *)&macos_right_ctl_override_ctx,
// //     .replacement       = A(KC_RGHT),
// //     .enabled           = NULL,
// // };
// // static const key_override_t macos_right_ctl_override = ko_make_basic(MOD_MASK_CTRL, KC_RIGHT, LALT(KC_RIGHT));
// // Define the key override for Control + Right Arrow to produce Alt + Right Arrow
// // const key_override_t macos_right_ctl_override = {
// //     .trigger = KC_RIGHT,             // The key to override
// //     .trigger_mods = MOD_MASK_CTRL,   // The modifier that triggers the override
// //     .layers = ~0,                    // Active on all layers
// //     .replacement = KC_A,    // The replacement keycode
// //     .suppressed_mods = MOD_MASK_CTRL,// Suppress the Control modifier
// // };
//
//
// // Backspace (Alt → Ctrl)
// static const os_override_ctx_t macos_backspace_alt_override_ctx = {
//     .replacement = C(KC_BSPC),
//     .original    = A(KC_BSPC)
// };
// const key_override_t macos_backspace_alt_override = {
//     .trigger_mods      = MOD_MASK_ALT,
//     .trigger           = KC_BSPC,
//     .layers            = ~0,
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,
//     .custom_action     = os_specific_override,
//     .context           = (void *)&macos_backspace_alt_override_ctx,
//     .replacement       = KC_NO,
//     .enabled           = NULL,
//     .options           = ko_options_default,
// };
//
// // Left Arrow (Alt → Ctrl)
// static const os_override_ctx_t macos_left_alt_override_ctx = {
//     .replacement = C(KC_LEFT),
//     .original    = A(KC_LEFT)
// };
// const key_override_t macos_left_alt_override = {
//     .trigger_mods      = MOD_MASK_ALT,
//     .trigger           = KC_LEFT,
//     .layers            = ~0,
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,
//     .custom_action     = os_specific_override,
//     .context           = (void *)&macos_left_alt_override_ctx,
//     .replacement       = KC_NO,
//     .enabled           = NULL,
//     .options           = ko_options_default,
// };
//
// // Right Arrow (Alt → Ctrl)
// static const os_override_ctx_t macos_right_alt_override_ctx = {
//     .replacement = C(KC_RGHT),
//     .original    = A(KC_RGHT)
// };
// const key_override_t macos_right_alt_override = {
//     .trigger_mods      = MOD_MASK_ALT,
//     .trigger           = KC_RGHT,
//     .layers            = ~0,
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,
//     .custom_action     = os_specific_override,
//     .context           = (void *)&macos_right_alt_override_ctx,
//     .replacement       = KC_NO,
//     .enabled           = NULL,
//     .options           = ko_options_default,
// };
//
// // Ctrl + Tab → GUI + Tab
// static const os_override_ctx_t macos_ctl_tab_override_ctx = {
//     .replacement = G(KC_TAB),
//     .original    = C(KC_TAB)
// };
// const key_override_t macos_ctl_tab_override = {
//     .trigger_mods      = MOD_MASK_CTRL,
//     .trigger           = KC_TAB,
//     .layers            = ~0,
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,
//     .custom_action     = os_specific_override,
//     .context           = (void *)&macos_ctl_tab_override_ctx,
//     .replacement       = KC_NO,
//     .enabled           = NULL,
//     .options           = ko_options_default,
// };
//
// // GUI + Tab → Ctrl + Tab
// static const os_override_ctx_t macos_gui_tab_override_ctx = {
//     .replacement = C(KC_TAB),
//     .original    = G(KC_TAB)
// };
// const key_override_t macos_gui_tab_override = {
//     .trigger_mods      = MOD_MASK_GUI,
//     .trigger           = KC_TAB,
//     .layers            = ~0,
//     .negative_mod_mask = 0,
//     .suppressed_mods   = 0,
//     .custom_action     = os_specific_override,
//     .context           = (void *)&macos_gui_tab_override_ctx,
//     .replacement       = KC_NO,
//     .enabled           = NULL,
//     .options           = ko_options_default,
// };
//
// // Register all overrides
// const key_override_t *key_overrides[] = {
//     &delete_key_override,
//     // &macos_backspace_ctl_override,
//     // &macos_left_ctl_override,
//     &macos_right_ctl_override,
//     // &macos_backspace_alt_override,
//     // &macos_left_alt_override,
//     // &macos_right_alt_override,
//     // &macos_ctl_tab_override,
//     // &macos_gui_tab_override,
//     NULL
// };
