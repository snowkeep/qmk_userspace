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

#include QMK_KEYBOARD_H
#include "process_records.h"

uint8_t mod_state;

__attribute__ ((weak))
bool process_record_user_kb(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_caps_word(keycode, record)) {
      return false;
  }

  uint8_t mods = get_mods();
  uint8_t oneshot_mods = get_oneshot_mods();

  switch (keycode) {
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;
      break;

    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
      } else {
        layer_off(_SYM);
      }
      return false;
      break;

    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;

    case M_UPDIR:
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("#!");
        } else {
          SEND_STRING("../");
        }
      }
      return false;
      break;

    case M_BRACES:  // Types [], {}, or <> and puts cursor between braces.
      if (record->event.pressed) {
        clear_mods();  // Temporarily disable mods.
        clear_oneshot_mods();
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("{}");
        } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
          SEND_STRING("<>");
        } else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
          SEND_STRING("()");
        } else {
          SEND_STRING("[]");
        }
        tap_code(KC_LEFT);  // Move cursor between braces.
        set_mods(mods);  // Restore mods.
      }
      return false;
      break;
  }
  return process_record_user_kb(keycode, record);
}

