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
#include "sk-hd_overrides.h"

const key_override_t coln_scln = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t dot_amper = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_AMPR);
const key_override_t slsh_astr = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_ASTR);
const key_override_t dqt_ques  = ko_make_basic(MOD_MASK_SHIFT, KC_DQT, KC_QUES);
const key_override_t quot_bang = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_EXLM);
const key_override_t mins_plus = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_PLUS);
const key_override_t comm_pipe = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_PIPE);
const key_override_t unds_eql  = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_EQL);

const key_override_t *key_overrides[] = {
  [COLN_SCLN] = &coln_scln,
  [DOT_AMPER] = &dot_amper,
  [SLSH_ASTR] = &slsh_astr,
  [DQT_QUES]  = &dqt_ques,
  [QUOT_BANG] = &quot_bang,
  [MINS_PLUS] = &mins_plus,
  [COMM_PIPE] = &comm_pipe,
  [UNDS_EQL]  = &unds_eql
};

