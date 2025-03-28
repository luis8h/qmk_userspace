typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_SINGLE_TAP
} tap_dance_step_t;

typedef struct {
    tap_dance_step_t step;
} dance_state_t;
dance_state_t dance_state[20]; // increase for more tapdance keys

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

// hold tap implementation
void hold_tap_on_dance(tap_dance_state_t *state, uint16_t keycode) {
    if (state->count == 3) {
        tap_code16(keycode);
        tap_code16(keycode);
        tap_code16(keycode);
    } else if (state->count > 3) {
        tap_code16(keycode);
    }
}
void hold_tap_dance_finished(tap_dance_state_t *state, uint16_t keycode, int layer, int state_index) {
    dance_state[state_index].step = dance_step(state);
    switch (dance_state[state_index].step) {
        case SINGLE_TAP:
            register_code16(keycode); break;
            break;
        case SINGLE_HOLD:
            layer_on(layer);
            break;
        case DOUBLE_TAP:
            register_code16(keycode);
            register_code16(keycode);
            break;
        case DOUBLE_SINGLE_TAP:
            register_code16(keycode);
            register_code16(keycode);
            break;
    }
}

