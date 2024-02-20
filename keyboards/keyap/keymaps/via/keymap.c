// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define LED1 B0
#define LED2 B1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * ├───┼───┼───┤
     * │ G │ H │ I │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x3(KC_A, KC_B, KC_C,
                           KC_P, KC_E, KC_D,
                           KC_G, KC_H, KC_I)
    };

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_C, KC_D)}
};

void keyboard_pre_init_user(void) {
    setPinOutput(LED1); // initialize B0 for LED
    setPinOutput(LED2); // initialize B1 for LED
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            writePinHigh(LED1);
            writePinLow(LED2);
            return 0;
            break;
        case 1:
            writePinHigh(LED1);
            writePinLow(LED2);
            return 0;
            break;
        default:
            writePinHigh(LED1);
            writePinHigh(LED2);
            
            break;
    }
    return 0;
}

void matrix_init_user(void) {
    setPinInputHigh(D4);
}

void matrix_scan_user(void) {
    if (!readPin(D4)) {
        tap_code(KC_MUTE);
    }
}
