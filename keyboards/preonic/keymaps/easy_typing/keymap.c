/* Copyright 2015-2017 Jack Humbert
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
#include "rgblight.h"
#include "keymap_french_osx.h"

#define TAPPING_TERM 200

enum preonic_layers {
  _AZERTY,
  _LOWER,
  _RAISE,
  _FN
};

enum preonic_keycodes {
  AZERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN,
  EJ_WAVE,
  EJ_CRI,
  EJ_THN,
  EJ_FLI,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QwertSplitly
 * ,-----------------------------------------------------------------------------------.
 * |   ESC|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   Z  |   E  |   R  |   T  |   [  |   ]  |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   Q  |   S  |   D  |   F  |   G  |   -  |   '  |   H  |   J  |   K  |   L  |   M  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   W  |   X  |   C  |   V  | TAB  |ENTER  |   B |   N  |   .  |   ,  |  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | fn   | LCtrl| LOpt | LCmd |LOWER |    SPACE    |RAISE | \    |  /   | =   |  `    |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5 ,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_Z,    KC_E,    KC_R,    KC_T,    KC_GRAVE, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_EQL,  KC_Q,    KC_S,    KC_D,    KC_F,    KC_G,    KC_QUOTE, KC_H,    KC_J,    KC_K,    KC_L,    KC_M, \
  KC_LSFT, KC_LBRC, KC_W,    KC_X,    KC_C,    KC_V,    KC_ENT,  KC_B,    KC_N,    KC_MINUS,KC_UP,   KC_RBRC,\
  FN     , KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_SLASH, KC_LEFT, KC_DOWN, KC_RIGHT \
),

[_LOWER] = LAYOUT_preonic_grid( \
  _______,     KC_F1,       KC_F2,     KC_F3,      KC_F4,      KC_F5,      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    _______, \
  _______,     _______,    KC_UP,    _______,    _______,    _______,    _______,  _______,  _______,  _______,  _______,   _______, \
  _______,     KC_LEFT,    KC_DOWN,    KC_RIGHT,    _______,    _______,    _______,  _______,  _______,  _______,  _______,   _______, \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,  _______,  KC_EQL, KC_COMM,  KC_DOT,   KC_SCLN, \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,  _______, KC_BSLS,    KC_COMM,    KC_DOT,  KC_SCLN   \
),

[_RAISE] = LAYOUT_preonic_grid( \
  _______,     KC_F1,       KC_F2,    KC_F3,       KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,   _______, \
  _______,   _______,       KC_UP, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______, \
  _______,     KC_LEFT,    KC_DOWN,    KC_RIGHT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______, \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______, \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_UP,    KC_DOWN,  KC_RIGHT  \
),

[_FN] = LAYOUT_preonic_grid( \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,     KC_MUTE,    KC_VOLD,   KC_VOLU,   _______, \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,    EJ_WAVE,    EJ_CRI,    EJ_THN,    EJ_FLI,   _______, \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______, \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_BSLS,    KC_COMM,    KC_DOT,   KC_SCLN, \
  _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_BSLS,    KC_COMM,    KC_DOT,   KC_SCLN  \
)


};


void keyboard_post_init_user(void) {
    backlight_disable();
    rgblight_disable();
}


/*
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, HSV_GREEN}       // Light 4 LEDs, starting with LED 0
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _FN);
            rgblight_enable();
            rgblight_setrgb(255, 0, 0);
          } else {
            layer_off(_LOWER);
             update_tri_layer(_LOWER, _RAISE, _FN);
             rgblight_disable();
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
             update_tri_layer(_LOWER, _RAISE, _FN);
             rgblight_enable();
             rgblight_setrgb(0, 255, 0);
          } else {
            layer_off(_RAISE);
             update_tri_layer(_LOWER, _RAISE, _FN);
             rgblight_disable();
          }
          return false;
          break;
        case FN:
          if (record->event.pressed) {
            layer_on(_FN);
             rgblight_enable();
             rgblight_setrgb(0, 0, 255);
          } else {
            layer_off(_FN);
             rgblight_disable();
          }
          return false;
          break;
          case EJ_WAVE:
            if (record->event.pressed) {
                SEND_STRING(":wave:");
            }
          return false;
          break;
          case EJ_CRI:
            if (record->event.pressed) {
                SEND_STRING(":cri:");
            }
          return false;
          break;
          case EJ_THN:
            if (record->event.pressed) {
                SEND_STRING(":thinking_face:");
            }
          return false;
          break;
      }
    return true;
};
