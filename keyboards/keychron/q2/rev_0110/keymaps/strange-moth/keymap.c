/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "qmk-vim/src/vim.h"
#include "qmk-vim/src/modes.h"

enum layers{
    MAC_BASE,
    WIN_BASE,
    _HRM,
    _FN1M,
    _FN1W,
    _FN2
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    TOG_VIM
};

#define KC_WAVE S(KC_GRV)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define CTLESC  LCTL_T(KC_ESC)

#define HM_LSFT LSFT_T(KC_V)
#define HM_LCTL LCTL_T(KC_F)
#define HM_LGUI LGUI_T(KC_D)
#define HM_LALT LALT_T(KC_S)
#define HM_RSFT RSFT_T(KC_N)
#define HM_RCTL RCTL_T(KC_J)
#define HM_RGUI RGUI_T(KC_K)
#define HM_RALT RALT_T(KC_L)

#ifdef UCIS_ENABLE
#define UC_COMP KC_NUBS
#else
#define UC_COMP KC_TRNS
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_INS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LCMD, KC_LOPT,                            KC_SPC,                             KC_RALT, MO(_FN1M),MO(_FN2), KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_INS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN1W),MO(_FN2), KC_LEFT, KC_DOWN, KC_RGHT),

    [_HRM] = LAYOUT_ansi_67(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          _______,
        _______, _______, HM_LALT, HM_LGUI, HM_LCTL, _______, _______, HM_RCTL, HM_RGUI, HM_RALT, _______, _______,           _______,          _______,
        _______,          _______, _______, _______, HM_LSFT, _______, HM_RSFT, _______, _______, _______, _______,           _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______, _______, _______, _______),

    [_FN1M] = LAYOUT_ansi_67(
        KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU, _______,          KC_LOCK,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          DM_REC1,
        _______, KC_SYRQ, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,          DM_REC2,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, KC_PGUP,
        _______, _______, _______,                            _______,                            _______, _______,  _______, KC_HOME, KC_PGDN, KC_END),

    [_FN1W] = LAYOUT_ansi_67(
        KC_ESC,  KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU, _______,          KC_LOCK,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          DM_REC1,
        _______, KC_SYRQ, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,          DM_REC2,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, KC_PGUP,
        _______, _______, _______,                            _______,                            _______, _______,  _______, KC_HOME, KC_PGDN, KC_END),

    [_FN2] = LAYOUT_ansi_67(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  _______,          KC_LOCK,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______, _______,          DM_PLY1,
        _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,           _______,          DM_PLY2,
        KC_CAPS,          _______, _______, _______, _______, _______, _______, _______, _______, UC_MOD,  _______,           KC_CAPS, KC_PGUP,
        _______, _______, _______,                            _______,                            TG(_HRM),TOG_VIM,  _______, KC_HOME, KC_PGDN, KC_END),
};
#ifdef UCIS_ENABLE
#include "ucis.h"
#endif

keyrecord_t dummy_up_keyrecord = {.event = {.pressed = false}};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
	#ifdef UCIS_ENABLE
        case UC_COMP:
            if (record->event.pressed) {
                qk_ucis_start();
            }
            return false;  // Skip all further processing of this key
    #endif
        case TOG_VIM:
            if (record->event.pressed) {
                toggle_vim_mode();
            }
            return false;  // Skip all further processing of this key
        //case KC_LOCK:
            //if (record->event.pressed) {
                //isLocking = true; // Turn the board red
            //}
            //return true;
    }
    if (!process_vim_mode(keycode, record)) {
        return false;
    }
    return true; // Process all other keycodes normally
}

bool isRecording = false;

void dynamic_macro_record_start_user(void) {
    isRecording = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    isRecording = false;
}

#define LED_SHIFT_LEFT 44
#define LED_SHIFT_RIGHT 55
#define LED_MACRO_1 29
#define LED_MACRO_2 43
#define LED_VIM_INDICATOR 14

keypos_t led_index_to_keypos(uint8_t index) {

    if (index == 65) {
        return (keypos_t){12, 2};
    }

    uint8_t greebled_index = index + (index<42 ? 0 : index<45 ? 1 : index<55 ? 2 : index<60 ? 3 : index<61 ? 6 : index<66 ? 9 : 8);

    return (keypos_t){greebled_index % 15, greebled_index / 15};
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (led_min <= LED_VIM_INDICATOR && led_max >= LED_VIM_INDICATOR && vim_mode_enabled()) {
        switch (get_vim_mode()) {
            case NORMAL_MODE:
                rgb_matrix_set_color(LED_VIM_INDICATOR, RGB_GOLD);
                break;
            case INSERT_MODE:
                rgb_matrix_set_color(LED_VIM_INDICATOR, RGB_CORAL);
                break;
            case VISUAL_MODE:
            case VISUAL_LINE_MODE:
                rgb_matrix_set_color(LED_VIM_INDICATOR, RGB_TEAL);
                break;
            case UNKNOWN_MODE:
                rgb_matrix_set_color(LED_VIM_INDICATOR, RGB_PURPLE);
        }
    }

    // red lights on caps lock
    if (host_keyboard_led_state().caps_lock) {
        if (led_min <= LED_SHIFT_LEFT && led_max >= LED_SHIFT_LEFT) {
            rgb_matrix_set_color(LED_SHIFT_LEFT, RGB_RED);
        };
        if (led_min <= LED_SHIFT_RIGHT && led_max >= LED_SHIFT_RIGHT) {
            rgb_matrix_set_color(LED_SHIFT_RIGHT, RGB_RED);
        };
    }

    // macro record indicator
    if (isRecording) {
        if (led_min <= LED_MACRO_1 && led_max >= LED_MACRO_1) {
            rgb_matrix_set_color(LED_MACRO_1, RGB_GOLD);
        };
        if (led_min <= LED_MACRO_2 && led_max >= LED_MACRO_2) {
            rgb_matrix_set_color(LED_MACRO_2, RGB_GOLD);
        };
    }

    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t index = led_min; index <= led_max; index++) {
        keypos_t keypos = led_index_to_keypos(index);

        // highlight all locked keys
        uint16_t kc = keymap_key_to_keycode(layer, keypos);
        if (!process_key_lock(&kc, &dummy_up_keyrecord)) {
            rgb_matrix_set_color(index, RGB_GOLD);
        }

        // layer indicator with only configured keys
        else if (layer > 1 && kc > KC_TRNS) {
            rgb_matrix_set_color(index, RGB_GREEN);
        }
    }
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
#ifdef VIM_FOR_ALL
        if (active) {
            disable_vim_for_mac();
        }
        else {
            enable_vim_for_mac();
        }
#endif
    }
    return true;
}

void keyboard_post_init_user(void) {
    // Start with rgb on but no color
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
