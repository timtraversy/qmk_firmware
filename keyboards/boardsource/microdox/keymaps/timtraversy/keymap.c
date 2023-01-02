/*
Copyright 2022 Cole Smith <cole@boadsource.xyz>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Configure the global tapping term 
#undef TAPPING_TERM 
#define TAPPING_TERM 150

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

enum layers {
    _DVORAK,
    _MEDIA,
    _SYMBOL1,
    _NAV,
    _NUM,
    _SYMBOL2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_split_3x5_3(
	KC_QUOT,		KC_COMM,		KC_DOT,			KC_P,			KC_Y,		KC_F,	KC_G,			KC_C,			KC_R,			KC_L,
	LGUI_T(KC_A),	LALT_T(KC_O),	LCTL_T(KC_E),	LSFT_T(KC_U),	KC_I,		KC_D,	RSFT_T(KC_H),	RCTL_T(KC_T),	LALT_T(KC_N),	RGUI_T(KC_S),
	KC_SCLN,		KC_Q,			KC_J,			KC_K,			KC_X,		KC_B,	KC_M,			KC_W,			KC_V,			KC_Z,
		LT(_MEDIA, KC_TAB),	LT(_SYMBOL1, KC_SPC),	LT(_NAV, KC_ESC),			LT(_NUM, KC_ENT),	LT(_SYMBOL2, KC_BSPC),	XXXXXXX
  ),
  [_MEDIA] = LAYOUT_split_3x5_3(
	QK_BOOT,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,		XXXXXXX,	XXXXXXX,	KC_BRID,	KC_BRIU,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,		XXXXXXX,	KC_MPRV,	KC_VOLD,	KC_VOLU,	KC_MNXT,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
							XXXXXXX,	XXXXXXX,	XXXXXXX,		KC_MUTE,	KC_MPLY,	XXXXXXX
  ),
  [_SYMBOL1] = LAYOUT_split_3x5_3(
	QK_BOOT,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,		XXXXXXX,	KC_PERC,	KC_AMPR,	XXXXXXX,	XXXXXXX,
	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	XXXXXXX,		KC_BSLS,	KC_EQL,		KC_QUES,	KC_ASTR,	KC_EXLM,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,		XXXXXXX,	KC_TILD,	KC_CIRC,	KC_PIPE,	XXXXXXX,
							XXXXXXX,	XXXXXXX,	XXXXXXX,		KC_UNDS,	KC_MINS,	XXXXXXX
  ),
  [_NAV] = LAYOUT_split_3x5_3(
	QK_BOOT,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	XXXXXXX,		CW_TOGG,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,		XXXXXXX,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,
							XXXXXXX,	XXXXXXX,	XXXXXXX,		KC_ENT,		KC_BSPC,	XXXXXXX
  ),
  [_NUM] = LAYOUT_split_3x5_3(
	XXXXXXX,	KC_7,		KC_8,		KC_9,		XXXXXXX,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	QK_BOOT,
	XXXXXXX,	KC_4,		KC_5,		KC_6,		XXXXXXX,		XXXXXXX,	KC_RSFT,	KC_RCTL,	KC_LALT,	KC_RGUI,
	XXXXXXX,	KC_1,		KC_2,		KC_3,		XXXXXXX,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
							XXXXXXX,	KC_0,		KC_DOT,			XXXXXXX,	XXXXXXX,	XXXXXXX
  ),
  [_SYMBOL2] = LAYOUT_split_3x5_3(
	XXXXXXX,	KC_PLUS,	KC_GRV,		KC_DLR,		XXXXXXX,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	QK_BOOT,
	KC_LBRC,	KC_RBRC,	KC_LCBR,	KC_RCBR,	KC_SLSH,		XXXXXXX,	KC_RSFT,	KC_RCTL,	KC_LALT,	KC_RGUI,
	XXXXXXX,	XXXXXXX,	KC_HASH,	KC_AT,		XXXXXXX,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
							XXXXXXX,	KC_LPRN,	KC_RPRN,		XXXXXXX,	XXXXXXX,	XXXXXXX
  )
};
