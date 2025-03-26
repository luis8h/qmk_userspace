#include QMK_KEYBOARD_H
#include "i18n.h"
#if __has_include("keymap.h")
    #include "keymap.h"
#endif

// enum {
//     TD_EXAMPLE
// };
//
// tap_dance_action_t tap_dance_actions[] = {
//     [TD_EXAMPLE] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_B),
// };


// enum custom_keycodes {
//   // ST_MACRO_0,
//   // ST_MACRO_1,
//   // ST_MACRO_2,
//   // ST_MACRO_3,
//   // ST_MACRO_4,
//   // OS_A,
// };

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
#define D_L1_3(key) key
#define D_L1_4(key) key
#define D_L1_5(key) key
#define D_R1_1(key) key
#define D_R1_2(key) LT(L_WORKAC, key)
#define D_R1_3(key) key
#define D_R1_4(key) LT(L_WORKA, key)
#define D_R1_5(key) LGUI_T(key)

// second row
#define D_L2_1(key) LGUI_T(key)
#define D_L2_2(key) LALT_T(key)
#define D_L2_3(key) LSFT_T(key)
#define D_L2_4(key) LCTL_T(key)
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
        D_L1_1(KC_EXLM), D_L1_2(KC_AT), D_L1_3(KC_HASH), D_L1_4(KC_DLR), D_L1_5(KC_PERC),       D_R1_1(KC_CIRC), D_R1_2(KC_AMPR), D_R1_3(KC_LPRN), D_R1_4(KC_RPRN), D_R1_5(KC_ASTR),
        D_L2_1(KC_MINS), D_L2_2(KC_QUOT), D_L2_3(KC_LCBR), D_L2_4(KC_RCBR), D_L2_5(KC_GRV),     D_R2_1(KC_PLUS), D_R2_2(KC_SLSH), D_R2_3(KC_DQUO), D_R2_4(KC_COLN), D_R2_5(),
        D_L3_1(KC_UNDS), D_L3_2(KC_SCLN), D_L3_3(KC_LBRC), D_L3_4(KC_RBRC), D_L3_5(KC_EQL),     D_R3_1(KC_TILD), D_R3_2(KC_BSLS), D_R3_3(KC_COMM), D_R3_4(KC_DOT), D_R3_5(),
        D_TL_1(), D_TL_2(),                                                                     D_TR_1(), D_TR_2()
    ),
    [L_NUMT] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LGUI, KC_NO, LCTL(KC_LALT), LCA(KC_LSFT), KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [L_SYMSPEC] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_QUOT, KC_TRNS, KC_CIRC, KC_ASTR, KC_AMPR, KC_NO, KC_TRNS, KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_BSLS, KC_GRV, KC_TRNS, RM_PREV, KC_TRNS, KC_TRNS, RM_NEXT),
    [L_NUMH] = LAYOUT_split_3x5_2(KC_TRNS, KC_COLN, KC_LT, KC_GT, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT, KC_TRNS, KC_NO, KC_EQL, KC_PLUS, KC_PERC, KC_TRNS, KC_EXLM, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_VOLU),
    [L_WORKA] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [L_WORKAC] = LAYOUT_split_3x5_2(KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [L_ESC] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS, DF(1), KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT, KC_TRNS, KC_TAB, KC_NO, KC_TRNS),
    [L_MOVE] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS, DF(1), KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT, KC_TRNS, KC_TAB, KC_NO, KC_TRNS),
    [L_SYS] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_COLN, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_PERC, KC_SLSH, KC_ENT, KC_TRNS, DF(1), KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EXLM, KC_TRNS, DF(0), KC_TRNS, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT, KC_TRNS, KC_TAB, KC_NO, KC_TRNS)
};


// 1. Define your tap dance identifiers.
enum {
    TD_LAYER_CHANGE, // index 0 for our tap dance key
    // ... add more if needed
};

// 2. Define tap dance step types for clarity.
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_SINGLE_TAP
} tap_dance_step_t;

// 3. Global state for tap dance; adjust array size if you use multiple keys.
typedef struct {
    tap_dance_step_t step;
} dance_state_t;
dance_state_t dance_state[1];

// 4. Helper function to determine tap dance step.
int dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    }
    if (state->count == 2) {
        return DOUBLE_TAP;
    }
    return 0;
}

// 5. Finished function: execute action based on tap dance type.
void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    // Use index 0 for our single tap dance key.
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            layer_move(0);
            break;
        case SINGLE_HOLD:
            layer_on(7);
            break;
        case DOUBLE_TAP:
            layer_move(0);
            break;
        case DOUBLE_SINGLE_TAP:
            layer_move(0);
            break;
    }
}

// 6. Reset function: clean up state after tap dance finishes.
void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (dance_state[0].step == SINGLE_HOLD) {
        layer_off(7);
    }
    dance_state[0].step = 0;
}

// 7. Register the tap dance action using the updated type and macro.
tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYER_CHANGE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset)
};



// #ifdef OTHER_KEYMAP_C
// #    include OTHER_KEYMAP_C
// #endif // OTHER_KEYMAP_C


// os specific configuration
// bool process_detected_host_os_kb(os_variant_t detected_os) {
//     if (!process_detected_host_os_user(detected_os)) {
//         return false;
//     }
//
//     // Shift + Backspace → Delete (applies to all OS)
//     static const key_override_t shift_backspace_override =
//         ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
//
//     // Ctrl + Backspace → Option + Backspace (only for macOS)
//     static const key_override_t macos_backspace_ctl_override =
//         ko_make_basic(MOD_MASK_CTRL, KC_BSPC, LALT(KC_BSPC));
//     static const key_override_t macos_left_ctl_override =
//         ko_make_basic(MOD_MASK_CTRL, KC_LEFT, LALT(KC_LEFT));
//     static const key_override_t macos_right_ctl_override =
//         ko_make_basic(MOD_MASK_CTRL, KC_RIGHT, LALT(KC_RIGHT));
//
//     static const key_override_t macos_backspace_alt_override =
//         ko_make_basic(MOD_MASK_ALT, KC_BSPC, LCTL(KC_BSPC));
//     static const key_override_t macos_left_alt_override =
//         ko_make_basic(MOD_MASK_ALT, KC_LEFT, LCTL(KC_LEFT));
//     static const key_override_t macos_right_alt_override =
//         ko_make_basic(MOD_MASK_ALT, KC_RIGHT, LCTL(KC_RIGHT));
//
//     static const key_override_t macos_ctl_tab =
//         ko_make_basic(MOD_MASK_CTRL, KC_TAB, LGUI(KC_TAB));
//     static const key_override_t macos_gui_tab =
//         ko_make_basic(MOD_MASK_GUI, KC_TAB, LCTL(KC_TAB));
//
//     // Default key overrides (applies to all OS)
//     static const key_override_t *default_key_overrides[] = {
//         &shift_backspace_override,
//         NULL
//     };
//
//     // macOS-specific key overrides (Shift + Backspace + Ctrl behavior)
//     static const key_override_t *mac_key_overrides[] = {
//         &shift_backspace_override,
//         &macos_backspace_ctl_override,
//         &macos_left_ctl_override,
//         &macos_right_ctl_override,
//         &macos_backspace_alt_override,
//         &macos_left_alt_override,
//         &macos_right_alt_override,
//         &macos_ctl_tab,
//         &macos_gui_tab,
//         NULL
//     };
//
//     // Apply overrides based on OS
//     switch (detected_os) {
//         case OS_MACOS:
//         case OS_IOS:
//             key_overrides = mac_key_overrides;
//             break;
//         default:
//             key_overrides = default_key_overrides;
//             break;
//     }
//
//     return true;
// }
//
