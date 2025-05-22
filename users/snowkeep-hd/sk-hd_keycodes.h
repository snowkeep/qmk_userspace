/* Copyright 2021 Craig J. (snowkeep)
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

#pragma once
#include QMK_KEYBOARD_H

// Custom keycodes and macros
enum custom_keycodes {
  // layers
  HD = SAFE_RANGE,
  SYM,
  NAV,
  FUNC,

  // macros
  M_UPDIR,
  M_BRACES,
};

#define ALT_S LALT_T(KC_S)
#define CTR_N LCTL_T(KC_N)
#define SFT_A RSFT_T(KC_A)
#define CTR_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_H RGUI_T(KC_H)
#define AGR_F RALT_T(KC_F)

#ifdef KM_GOLD
#define GUI_R LGUI_T(KC_R)
#define SFT_D LSFT_T(KC_D)
#endif

#ifdef KM_TITANIUM
#define GUI_C LGUI_T(KC_C)
#define SST_T LSFT_T(KC_T)
#endif

