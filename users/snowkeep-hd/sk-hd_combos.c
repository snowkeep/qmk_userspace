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
#include "sk-hd_combos.h"

enum combo_events {
  CMB_Q,
  CMB_QU,
  CMB_Z,
  CMB_TH,
  CMB_CH,
  CMB_SH,
  CMB_PH,
  CMB_GH,
  CMB_WH,
  CMB_P4,
  CMB_CAPSWORD,
  CMB_SHBANG,
  CMB_UPDIR,
  CMB_BKSP,
  CMB_UNDS,
  CMB_TAB,
  CMB_ESC,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM q_combo[]  = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM qu_combo[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM sh_combo[] = {ALT_S, CTR_N, COMBO_END};
const uint16_t PROGMEM ph_combo[] = {KC_P, KC_M, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_C, KC_U, COMBO_END};
const uint16_t PROGMEM shbang_combo[] = {KC_1, KC_3, COMBO_END};
const uint16_t PROGMEM updir_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM bksp_combo[] = {KC_DQT, KC_QUOT, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {CTR_E, ALT_I, COMBO_END};
const uint16_t PROGMEM z_combo[]  = {KC_J, KC_G, COMBO_END};

#ifdef KM_GOLD
const uint16_t PROGMEM th_combo[] = {SFT_D, CTR_N, COMBO_END};
const uint16_t PROGMEM ch_combo[] = {KC_C, KC_L, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM wh_combo[] = {KC_W, KC_C, COMBO_END};
const uint16_t PROGMEM p4_combo[] = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_X, AGR_F, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {GUI_R, ALT_S, COMBO_END};
#endif

#ifdef KM_TITANIUM
const uint16_t PROGMEM th_combo[] = {SST_T, CTR_N, COMBO_END};
const uint16_t PROGMEM ch_combo[] = {GUI_C, ALT_S, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_J, COMBO_END};
const uint16_t PROGMEM wh_combo[] = {KC_W, KC_Y, COMBO_END};
const uint16_t PROGMEM p4_combo[] = {KC_P, KC_G, COMBO_END};
#endif

combo_t key_combos[] = {
  [CMB_Q]  = COMBO_ACTION(q_combo),
  [CMB_QU] = COMBO_ACTION(qu_combo),
  [CMB_Z]  = COMBO_ACTION(z_combo),
  [CMB_TH] = COMBO_ACTION(th_combo),
  [CMB_CH] = COMBO_ACTION(ch_combo),
  [CMB_SH] = COMBO_ACTION(sh_combo),
  [CMB_PH] = COMBO_ACTION(ph_combo),
  [CMB_GH] = COMBO_ACTION(gh_combo),
  [CMB_WH] = COMBO_ACTION(wh_combo),
  [CMB_P4] = COMBO_ACTION(p4_combo),
  [CMB_CAPSWORD] = COMBO_ACTION(caps_combo),
  [CMB_SHBANG] = COMBO_ACTION(shbang_combo),
  [CMB_UPDIR] = COMBO_ACTION(updir_combo),
  [CMB_BKSP] = COMBO_ACTION(bksp_combo),
  [CMB_UNDS] = COMBO_ACTION(unds_combo),
#ifdef KM_GOLD
  [CMB_TAB] = COMBO_ACTION(tab_combo),
  [CMB_ESC] = COMBO_ACTION(esc_combo)
#endif

//  [UNDO] = COMBO_ACTION(undo_combo),
//  [CUT] = COMBO_ACTION(cut_combo),
//  [COPY] = COMBO_ACTION(copy_combo),
//  [PASTE] = COMBO_ACTION(paste_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMB_Q:
      if (pressed) {
        tap_code16(KC_Q);
      }
      break;

    case CMB_QU:
      if (pressed) {
        tap_code(KC_Q); 
        caps_word_combo();
        tap_code(KC_U);
      }
      break;

    case CMB_Z:
      if (pressed) {
        tap_code16(KC_Z);
      }
      break;

    case CMB_TH:
      if (pressed) {
        tap_code(KC_T); 
        caps_word_combo();
        tap_code(KC_H);
      }
      break;

    case CMB_CH:
      if (pressed) {
        tap_code(KC_C); 
        caps_word_combo();
        tap_code(KC_H);
      }
      break;

    case CMB_SH:
      if (pressed) {
        tap_code(KC_S); 
        caps_word_combo();
        tap_code(KC_H);
      }
      break;

    case CMB_PH:
      if (pressed) {
        tap_code(KC_P); 
        caps_word_combo();
        tap_code(KC_H);
      }
      break;

    case CMB_GH:
      if (pressed) {
        tap_code(KC_G); 
        caps_word_combo();
        tap_code(KC_H);
      }
      break;

    case CMB_WH:
      if (pressed) {
        tap_code(KC_W); 
        caps_word_combo();
        tap_code(KC_H);
      }
      break;

    case CMB_P4:
      if (pressed) {
        tap_code(KC_P); 
        caps_word_combo();
        tap_code(KC_4);
      }
      break;

    case CMB_CAPSWORD:
      if (pressed) {
        toggle_caps_word();
      }
      break;

    case CMB_SHBANG:
      if (pressed) {
        SEND_STRING("#!");
      }
      break;

    case CMB_UPDIR:
      if (pressed) {
        SEND_STRING("../");
      }
      break;

    case CMB_BKSP:
      if (pressed) {
        tap_code16(KC_BSPC);
      }
      break;

    case CMB_UNDS:
      if (pressed) {
        tap_code16(KC_UNDS);
      }
      break;

    case CMB_TAB:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;

    case CMB_ESC:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;

  }
}
