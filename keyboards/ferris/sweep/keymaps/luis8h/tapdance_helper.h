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

