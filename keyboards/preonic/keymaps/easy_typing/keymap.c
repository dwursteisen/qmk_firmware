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
#include "keymap_french_osx.h"

#define TAPPING_TERM 200

enum preonic_layers {
  _AZERTY,
  _ACCENTS
};

enum preonic_keycodes {
  AZERTY = SAFE_RANGE,
  ACCENTS
};

// Tap Dance declarations
enum {
    TD_MAJ_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_MAJ_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Azerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_preonic_grid( \
  KC_ESC,            KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_0,    KC_BSPC, \
  KC_TAB,            FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV, \
  KC_CAPS,           FR_Q,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  TD(TD_MAJ_CAPS),   FR_W,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, FR_DOT,  KC_UP,   KC_RSFT, \
  _______,           KC_LCTL, KC_LALT, KC_LGUI, _______,   KC_SPC,  KC_SPC,  MO(1),   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT  \
),

[_ACCENTS] = LAYOUT_preonic_grid( \
  _______,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    _______, \
  _______,     _______,    _______,    FR_LPRN,    FR_RPRN,    _______,    _______,    _______,    _______,    FR_LABK,    FR_RABK,    _______, \
  _______,     _______,    _______,    FR_LBRC,    FR_RBRC,    _______,    _______,    _______,    _______,    _______,    _______, _______, \
  _______,     _______,    _______,    FR_LCBR,    FR_RCBR,    _______,    _______,    _______,    _______, _______,  _______,   _______, \
  _______,     _______, _______, _______, _______,   _______,  _______,  _______,   _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
};
