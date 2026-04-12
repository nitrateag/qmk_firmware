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
// #include "quantum\unicode\unicode.h"
#include "quantum\keymap_extras\sendstring_french.h"
#include "host.h"

// Windows Alt Code :
// https://alt-codes.fr/tables/windows/
// exemple :
// SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P2) SS_TAP(X_P0) SS_TAP(X_P1) SS_UP(X_LALT)); // 'É'

#include QMK_KEYBOARD_H


enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    ERGOL_ACC,
    ERGOL_SPE
};

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
    FR_CURRENCY,              // '€/¤'
    FR_CIRC2,                 // '^'
    FR_DIAE2,                 // '¨'
    FR_TILD2,                 // '~'
    FR_GRV2,                  // '`'

    // Ergo-L MAJ
    EL_MINS,                  // '-/?'
    EL_DOT,                   // './:'
    EL_COMM,                  // ',/;'
    EL_1,                     // '1/!'
    EL_2,                     // '2/@'
    EL_3,                     // '3/#'
    EL_4,                     // '4/$'
    EL_5,                     // '5/%'
    EL_6,                     // '6/^'
    EL_7,                     // '7/&'
    EL_8,                     // '8/*'
    EL_9,                     // '9/('
    EL_0,                     // '0/)'
    EL_MINS2,                 // '-/_'
    EL_EQL,                   // '=/+'
    EL_LBRC,                  // '[/{'
    EL_RBRC,                  // ']/}'
    EL_BSLS,                  // '\/|'
    EL_QUOT,                  // ''/"'
    EL_EACC,                  // 'é/É'
    EL_AACC,                  // 'à/À'
    EL_CCED                   // 'ç/Ç'

};
#define FR_CIRC2 ALGR(KC_9) // ^ undead

// Liste des Alt-code en CP1252   http://www.nknabe.dk/database/pdxeditor/help/ascii-extended-cp1252.png
#define send_alt_code(v0, v1, v2, v3) \
    if(!host_keyboard_led_state().num_lock) { \
      tap_code16(KC_NUM); \
    } \
    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P#v0) SS_TAP(X_P#v1) SS_TAP(X_P#v2) SS_TAP(X_P#v3) SS_UP(X_LALT)) /* 'le AltCode' */

#define send_min_maj_altcode( min,  maj1,  maj2,  maj3) \
  uint8_t mods = get_mods(); /* Sauvegarde les modificateurs actuels */ \
  del_mods(MOD_MASK_SHIFT); /* Désactive temporairement SHIFT */ \
\
  if (mods & MOD_MASK_SHIFT) { /* Si SHIFT est actif */ \
    if(!host_keyboard_led_state().num_lock) { \
      tap_code16(KC_NUM); \
    } \
    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P#maj1) SS_TAP(X_P#maj2) SS_TAP(X_P#maj3) SS_UP(X_LALT)); /* 'le AltCode' */ \
  } else { \
    tap_code16(min); /* Envoie 'le caractère minuscule classique' */ \
  } \
\
  set_mods(mods) /* Restaure les modificateurs */

#define send_min_altcode_maj_altcode( min1, min2, min3,  maj1,  maj2,  maj3) \
  uint8_t mods = get_mods(); /* Sauvegarde les modificateurs actuels */ \
  del_mods(MOD_MASK_SHIFT); /* Désactive temporairement SHIFT */ \
\
  if (mods & MOD_MASK_SHIFT) { /* Si SHIFT est actif */ \
    send_alt_code(0, #maj1, #maj2, #maj3); /* Envoie 'le caractère majuscule' en Alt+Code */ \
  } else { \
    send_alt_code(0, #min1, #min2, #min3); /* Envoie 'le caractère minuscule' en Alt+Code */ \
  } \
\
  set_mods(mods) /* Restaure les modificateurs */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case FR_DIAE2:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT
                tap_code16(FR_DIAE);  // Dead key pour le grav
                set_mods(mods); // Restaure les modificateurs
                tap_code(KC_SPC);     // Lettre ' '
            }
            return false;
        case FR_TILD2:
            if (record->event.pressed) {
                tap_code16(FR_TILD);  // Dead key pour le ~
                tap_code(KC_SPC);     // Lettre ' '
            }
            return false;
        case FR_GRV2:
            if (record->event.pressed) {
                tap_code16(FR_GRV);  // Dead key pour le grav
                tap_code(KC_SPC);     // Lettre ' '
            }
            return false;

        // Lettres avec tréma
        case FR_O_TREMA:
            if (record->event.pressed) {
              send_min_altcode_maj_altcode(2,4,6, 2,1,4);
            }
            return false;

        case FR_U_TREMA:
            if (record->event.pressed) {
              send_min_altcode_maj_altcode(2,5,2, 2,2,0);
            }
            return false;

        case FR_E_TREMA:
            if (record->event.pressed) {
              send_min_altcode_maj_altcode(2,3,5, 2,0,3);
            }
            return false;

        case FR_I_TREMA:
            if (record->event.pressed) {
              send_min_altcode_maj_altcode(2,3,9, 2,0,7);
            }
            return false;

        // Lettres avec circonflexe
        case FR_O_CIRC:
            if (record->event.pressed) {
              send_min_altcode_maj_altcode(2,4,4, 2,1,2);
            }
            return false;

        case FR_U_CIRC:
            if (record->event.pressed) {
              send_min_altcode_maj_altcode(2,5,1, 2,1,9);
            }
            return false;

        case FR_E_CIRC:
            if (record->event.pressed) {
              send_min_altcode_maj_altcode(2,3,4, 2,0,2);
            }
            return false;

        case FR_I_CIRC:
            if (record->event.pressed) {
              send_min_altcode_maj_altcode(2,3,8, 2,0,6);
            }
            return false;

        case FR_A_CIRC:
          if (record->event.pressed) {
            send_min_altcode_maj_altcode(2,2,6, 1,9,4);
          }
          return false;

        // Gestion de '€' et '¤'
        case FR_CURRENCY:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(ALGR(KC_RBRC)); // Envoie '¤'
                } else {
                    tap_code16(FR_EURO); // Envoie '€'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;

        case OSL(ERGOL_ACC):
           uint8_t mods = get_mods();
          if(record->event.pressed && (mods & MOD_MASK_SHIFT))
          {
            del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT               
            tap_code16(FR_EXLM);
            set_mods(mods); // Restaure les modificateurs
            return false;
          }
          else return true;

        case EL_MINS:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_COMM); // Envoie '?'
                } else {
                    tap_code16(FR_MINS); // Envoie '-'
                }
            }
            return false;
        case EL_MINS2:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT
                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_UNDS); // Envoie '_'
                } else {
                    tap_code16(FR_MINS); // Envoie '-'
                }
                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_DOT:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_COLN); // Envoie ':'
                } else {
                    tap_code16(FR_DOT); // Envoie '.'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_COMM:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_SCLN); // Envoie ';'
                } else {
                    tap_code16(FR_COMM); // Envoie ','
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_0:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_RPRN); // Envoie ')'
                } else {
                    tap_code16(FR_0); // Envoie '0'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_1:
          if (record->event.pressed){
            send_min_maj_altcode(FR_1, 1,8,5); // '1/¹'
            }
          return false;
        case EL_2:
          if (record->event.pressed) {
            send_min_maj_altcode(FR_2, 1,7,8); // '2/²'
          }
          return false;
        case EL_3:
          if (record->event.pressed) {
            send_min_maj_altcode(FR_3, 1,7,9); // '3/³'
          }
          return false;
        case EL_4:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_DLR); // Envoie '$'
                } else {
                    tap_code16(FR_4); // Envoie '4'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_5:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_PERC); // Envoie '%'
                } else {
                    tap_code16(FR_5); // Envoie '5'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_6:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_CIRC); // Envoie '^'
                } else {
                    tap_code16(FR_6); // Envoie '6'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_7:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT);  // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_AMPR); // Envoie '&'
                } else {
                    tap_code16(FR_7); // Envoie '7'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_8:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_ASTR); // Envoie '*'
                } else {
                    tap_code16(FR_8); // Envoie '8'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_9:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_LPRN); // Envoie '('
                } else {
                    tap_code16(FR_9); // Envoie '9'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_EQL:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_PLUS); // Envoie '€'
                } else {
                    tap_code16(FR_EQL); // Envoie '¤'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_LBRC:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_LCBR); // Envoie '{'
                } else {
                    tap_code16(FR_LBRC); // Envoie '['
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_RBRC:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_RCBR); // Envoie '}'
                } else {
                    tap_code16(FR_RBRC); // Envoie ']'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_BSLS:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_PIPE); // Envoie '|'
                } else {
                    tap_code16(FR_BSLS); // Envoie '\'
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;
        case EL_QUOT:
            if (record->event.pressed) {
                uint8_t mods = get_mods(); // Sauvegarde les modificateurs actuels
                del_mods(MOD_MASK_SHIFT); // Désactive temporairement SHIFT

                if (mods & MOD_MASK_SHIFT) { // Si SHIFT est actif
                    tap_code16(FR_DQUO); // Envoie '"'
                } else {
                    tap_code16(FR_QUOT); // Envoie '''
                }

                set_mods(mods); // Restaure les modificateurs
            }
            return false;

        case EL_EACC:
          if (record->event.pressed) {
            send_min_maj_altcode(FR_EACU, 2,0,1); // 'é/É'
          }
          return false;

        case EL_AACC:
          if (record->event.pressed) {
            send_min_maj_altcode(FR_AGRV, 1,9,2); // 'à/À'
          }
          return false;

        case EL_CCED:
          if (record->event.pressed) {
            send_min_maj_altcode(FR_CCED, 1,9,9); // 'ç/Ç'
          }
          return false;
        default:
            return true;  // Les autres touches restent inchangées
    }
}


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_90_ansi(
        KC_MUTE,    KC_INS,             KC_F1,    KC_F2,    KC_F3,    KC_F4,  KC_F5,            KC_F6,    KC_F7, KC_F8,      KC_F9,           KC_F10,   KC_F11,    KC_F12,   KC_PGUP,  KC_PGDN,
        MC_1,       KC_ESC,             EL_1,     EL_2,     EL_3,     EL_4,   EL_5,             EL_6,     EL_7,  EL_8,       EL_9,            EL_0,     EL_MINS2,  EL_EQL,   KC_BSPC,  KC_DEL,
        MC_2,       KC_TAB,             FR_Q,     FR_C,     FR_O,     FR_P,   FR_W,             FR_J,     FR_M,  FR_D,       OSL(ERGOL_ACC),  FR_Y,     KC_BSPC,   KC_BSPC,  KC_RSFT,  KC_HOME,
        KC_CAPS,    KC_APP,             FR_A,     FR_S,     FR_E,     FR_N,   FR_F,             FR_L,     FR_R,  FR_T,       FR_I,            FR_U,     KC_ENT,        KC_ENT,         KC_END,
        KC_PSCR,    KC_LSFT,            FR_Z,     FR_X,     EL_MINS,  FR_V,   FR_B,       FR_B, EL_DOT,   FR_H,  FR_G,       EL_COMM,         FR_K,         KC_DEL,         KC_UP,
        KC_LCTL,    KC_LCTL,  KC_LWIN,           KC_LALT,          KC_SPC,  KC_LSFT,            MO(ERGOL_SPE),   MO(MAC_FN), KC_RCTL,                             KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_90_ansi(
        _______,    _______,            KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  _______,             _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,   _______,
        _______,     KC_NUM,            _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,
        _______,    _______,            KC_TAB ,  KC_HOME,  KC_UP  ,  KC_END ,  KC_PGUP,             _______,  EL_7   ,  EL_8   ,  EL_9   ,  _______,  _______,  _______,  _______,   _______,
        _______,    _______,            KC_LSFT,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,             EL_MINS,  EL_4   ,  EL_5   ,  EL_6   ,  EL_0   ,  _______,       _______,        _______,
        _______,    _______,            KC_RCTL,  _______,  _______,  _______,  _______,  EL_COMM,   KC_PDOT,  EL_1   ,  EL_2   ,  EL_3   ,  KC_PDOT,        _______,       _______,
        _______,    _______,  _______,            _______,         _______,  _______,                _______,            _______,  _______,                       _______,  _______,  _______),

    [ERGOL_ACC] = LAYOUT_90_ansi(
        _______,    _______,            _______,    _______,    _______,    _______,     _______,           _______, _______,    _______,    _______,     _______,    _______,   _______,   _______,        _______,
        _______,    _______,            _______,    _______,   FR_O_TREMA,  _______,     _______,           _______, _______,    _______,    _______,     _______,    _______,   _______,   _______,        _______,
        _______,    _______,            FR_A_CIRC,  EL_CCED,   FR_O_CIRC,   FR_CURRENCY, _______,           _______, FR_MICR,    FR_UNDS,    FR_DQUO,     FR_U_CIRC,  _______,   _______,   _______,        _______,
        _______,    _______,            EL_AACC,    EL_EACC,    FR_EGRV,    FR_E_CIRC,   _______,           _______, _______,    FR_I_CIRC,  FR_I_TREMA,  FR_UGRV,    _______,        _______,              _______,
        _______,    _______,            _______,    _______,   FR_E_TREMA,  _______,     _______, _______,  _______, _______,    _______,    _______,     _______,           _______,        _______,
        _______,    _______,   _______,             _______,          FR_QUOT,           _______,                 FR_QUOT,       _______,    _______,                             _______,   _______,   _______), 

    [ERGOL_SPE] = LAYOUT_90_ansi(
        _______,    _______,             KC_BRID, KC_BRIU,  KC_TASK,  KC_FILE,  _______,         _______,  KC_MPRV,  KC_MPLY,   KC_MNXT,  KC_MUTE,   KC_VOLD,     KC_VOLU,    _______,    _______,
        _______,     KC_NUM,             KC_P1,    KC_P2,    KC_P3,    KC_P4,   KC_P5,            KC_P6,    KC_P7,   KC_P8,     KC_P9,    KC_P0,     KC_KP_DOT,   KC_PPLS,    _______,    _______,
        _______,    _______,             FR_CIRC2, FR_LABK,  FR_RABK,  FR_DLR,  FR_PERC,          FR_AT,    FR_AMPR, FR_ASTR,   FR_QUOT,  FR_GRV2,   _______,     _______,    KC_PENT,    _______,
        _______,    KC_CAPS,             FR_LCBR,  FR_LPRN,  FR_RPRN,  FR_RCBR, FR_EQL,           FR_BSLS,  FR_PLUS, KC_PMNS,   KC_PSLS,  FR_DQUO,   KC_PENT,        KC_PENT,             _______,
        _______,    _______,             FR_TILD2, FR_LBRC,  FR_RBRC,  FR_UNDS, FR_HASH, FR_HASH, FR_COLN,  FR_PIPE, FR_EXLM,   FR_SCLN,  FR_QUES,     _______,          _______,
        _______,    _______,  _______,           _______,        _______,       _______,            _______,         _______,   _______,                       _______,  _______,  _______),




        



    [WIN_BASE] = LAYOUT_90_ansi(
        KC_MUTE,    KC_GRV,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PGUP,            KC_PGDN,
        MC_1,       KC_ESC,             KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_DEL,
        MC_2,       KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,  KC_BSPC,  KC_RSFT,            KC_HOME,
        MC_3,       KC_CAPS,            KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,        KC_ENT,                  KC_END,
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,       KC_DEL,             KC_UP,
        MC_5,       KC_LCTL,  KC_LWIN,            KC_LALT,            KC_SPC,   KC_LSFT,                        KC_RALT,          MO(WIN_FN), KC_RCTL,               KC_LEFT,  KC_DOWN,  KC_RGHT),
   
    [WIN_FN] = LAYOUT_90_ansi(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,   RGB_VAI,            KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______, _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,   _______,  _______, _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,            _______,  _______,  _______,  _______,  _______,   _______,  _______, _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,            _______,  _______,  _______,  _______,  _______,             _______, _______,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  _______,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,             _______,            _______,            _______,             _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [ERGOL_ACC]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [ERGOL_SPE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLD) },
};
#endif // ENCODER_MAP_ENABLE
