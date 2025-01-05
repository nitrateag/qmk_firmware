/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
// #include "quantum\keymap_extras\keymap_french.h"
// #include "quantum\unicode.h"
#include "quantum\keymap_extras\sendstring_french.h"


#include QMK_KEYBOARD_H

enum custom_keycodes {
    FR_O_TREMA = SAFE_RANGE,  // 'ö'
    FR_U_TREMA,               // 'ü'
    FR_E_TREMA,               // 'ë'
    FR_I_TREMA,               // 'ï'
    FR_O_CIRC,                // 'ô'
    FR_U_CIRC,                // 'û'
    FR_E_CIRC,                // 'ê'
    FR_I_CIRC,                // 'î'
    FR_A_CIRC,                // 'â'
    FR_CURRENCY               // '¤'
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Lettres avec tréma
        case FR_O_TREMA:
            if (record->event.pressed) {
                tap_code16(FR_DIAE);  // Dead key pour le tréma
                tap_code(FR_O);     // Lettre 'O'
            }
            return false;

        case FR_U_TREMA:
            if (record->event.pressed) {
                tap_code16(FR_DIAE);  // Dead key pour le tréma
                tap_code(FR_U);     // Lettre 'U'
            }
            return false;

        case FR_E_TREMA:
            if (record->event.pressed) {
                tap_code16(FR_DIAE);  // Dead key pour le tréma
                tap_code(FR_E);     // Lettre 'E'
            }
            return false;

        case FR_I_TREMA:
            if (record->event.pressed) {
                tap_code16(FR_DIAE);  // Dead key pour le tréma
                tap_code(FR_I);     // Lettre 'I'
            }
            return false;

        // Lettres avec circonflexe
        case FR_O_CIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);  // Dead key pour le circonflexe
                tap_code(FR_O);     // Lettre 'O'
            }
            return false;

        case FR_U_CIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);  // Dead key pour le circonflexe
                tap_code(FR_U);     // Lettre 'U'
            }
            return false;

        case FR_E_CIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);  // Dead key pour le circonflexe
                tap_code(FR_E);     // Lettre 'E'
            }
            return false;

        case FR_I_CIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);  // Dead key pour le circonflexe
                tap_code(FR_I);     // Lettre 'I'
            }
            return false;

        case FR_A_CIRC:
          if (record->event.pressed) {
              tap_code16(FR_CIRC);  // Dead key pour le circonflexe
              tap_code(FR_A);     // Lettre 'A'
          }
          return false;

        // Gestion de '€' et '¤'
        case FR_CURRENCY:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code16(FR_EURO);  // Envoie '€'
                } else {
                    tap_code16(FR_CURR);     // Envoie '¤'
                }
            }
            return false;

        default:
            return true;  // Les autres touches restent inchangées
    }
}

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    ERGOL_ACC1,
    ERGOL_ACC2,
    ERGOL_SPE
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_90_ansi(
        KC_MUTE,    KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,  KC_F5,            KC_F6,    KC_F7, KC_F8,      KC_F9,           KC_F10,   KC_F11,   KC_F12,   KC_PGUP,  KC_PGDN,
        MC_1,       KC_GRV,             FR_1,     FR_2,     FR_3,     FR_4,   FR_5,             FR_6,     FR_7,  FR_8,       FR_9,            FR_0,     FR_MINS,  FR_EQL,   KC_BSPC,  KC_DEL,
        MC_2,       KC_TAB,             FR_Q,     FR_C,     FR_O,     FR_P,   FR_W,             FR_J,     FR_M,  FR_D,       OSL(ERGOL_ACC1), FR_Y,     FR_LBRC,  FR_RBRC,  FR_BSLS,  KC_HOME,
        MC_3,       KC_CAPS,            FR_A,     FR_S,     FR_E,     FR_N,   FR_F,             FR_L,     FR_R,  FR_T,       FR_I,            FR_U,     FR_QUOT,            KC_ENT,   KC_END,
        MC_4,       KC_LSFT,            FR_Z,     FR_X,     FR_MINS,  FR_V,   FR_B,       FR_B, FR_DOT,   FR_H,  FR_G,       FR_COMM,         FR_K,         KC_RSFT,      KC_UP,
        MC_5,       KC_LCTL,  KC_LWIN,           KC_LALT,          KC_SPC,  KC_LSFT,            MO(ERGOL_SPE),   MO(MAC_FN), KC_RCTL,                             KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_90_ansi(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,             _______,            _______,            _______,            _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_90_ansi(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PGUP,            KC_PGDN,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_DEL,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        MC_3,       KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,   KC_LSFT,           KC_RALT,              MO(WIN_FN),            KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_90_ansi(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,   RGB_VAI,            KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______, _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,   _______,  _______, _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,            _______,  _______,  _______,  _______,  _______,   _______,  _______, _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,            _______,  _______,  _______,  _______,  _______,             _______, _______,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,             _______,            _______,            _______,             _______,  _______,  _______),

    [ERGOL_ACC1] = LAYOUT_90_ansi(
        _______,    _______,            _______,    _______,    _______,    _______,     _______,           _______, _______,    _______,    _______,     _______,       _______,   _______,   _______,        _______,
        _______,    _______,            _______,    _______,    _______,    _______,     _______,           _______, _______,    _______,    _______,     _______,       _______,   _______,   _______,        _______,
        _______,    _______,            FR_A_CIRC,  FR_CCED,    FR_O_CIRC,  FR_CURRENCY, _______,           _______, FR_MICR,    FR_UNDS,OSL(ERGOL_ACC2), FR_U_CIRC,     _______,   _______,   _______,        _______,
        _______,    _______,            FR_AGRV,    FR_EACU,    FR_EGRV,    FR_E_CIRC,   _______,           _______, _______,    FR_I_CIRC,  FR_I_TREMA,  FR_UGRV,       _______,              _______,        _______,
        _______,    _______,            _______,    _______,    _______,    _______,     _______,    _______,  _______,    _______,       _______,    _______, _______,    _______,      _______,
        _______,    _______,   _______,             _______,          _______,           _______,                 _______,                _______,   _______,                           _______,   _______,   _______), 
    
    [ERGOL_ACC2] = LAYOUT_90_ansi(
        _______,    _______,            _______,    _______,    _______,    _______,    _______,            _______, _______, _______, _______,    _______,    _______,   _______,   _______,      _______,
        _______,    KC_GRV,             _______,    _______,    _______,    _______,    _______,            _______, _______, _______, _______,    _______,    FR_MINS,   FR_EQL,    _______,      _______,
        _______,    _______,            _______,    _______, FR_O_TREMA,    _______,    _______,            _______, _______, _______, FR_I_TREMA, FR_U_TREMA, FR_LBRC,   FR_RBRC,   FR_BSLS,      _______,
        _______,    _______,            _______,    _______, FR_E_TREMA,    _______,    _______,            _______, _______, _______, _______,    _______,    _______,   _______,                 _______,
        _______,    _______,            _______,    _______,    _______,    _______,    _______,   _______, _______, _______, _______, _______,    _______,    _______,   _______,
        _______,    _______,   _______,             _______,                _______,    _______,          _______,            _______, _______,                _______,   _______,   _______), 
       
    [ERGOL_SPE] = LAYOUT_90_ansi(
        _______,    _______,            _______,    _______,    _______,    _______,    _______,           _______, _______,    _______,    _______,    _______,   _______,   _______,   _______,  _______,
        _______,    KC_GRV,             FR_1,       FR_2,       FR_3,       FR_4,       FR_5,              FR_6,    FR_7,       FR_8,       FR_9,       FR_0,      FR_MINS,   FR_EQL,    _______,  _______,
        _______,    _______,            FR_Q,       FR_W,       FR_E,       FR_R,       FR_T,              FR_Y,    FR_U,       FR_I,       FR_O,       FR_P,      FR_LBRC,   FR_RBRC,   FR_BSLS,  _______,
        _______,    _______,            FR_A,       FR_S,       FR_D,       FR_F,       FR_G,              FR_H,    FR_J,       FR_K,       FR_L,       FR_SCLN,   FR_QUOT,              _______,  _______,
        _______,    _______,            FR_Z,       FR_X,       FR_C,       FR_V,        FR_B,       FR_B, FR_N,    FR_M,       FR_COMM,    FR_DOT,     FR_SLSH,       _______,       _______,
        _______,    _______,   _______,             _______,                _______,    _______,           _______,              _______,   _______,                       _______,   _______,   _______), 
    
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [ERGOL_ACC1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [ERGOL_ACC2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [ERGOL_SPE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLD) },
};
#endif // ENCODER_MAP_ENABLE
