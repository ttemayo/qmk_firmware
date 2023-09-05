// Copyright 2022 Kevin Hoang (@ttemayo) <khoang65@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "key_override.h"

const key_override_t ko_rshift_tab = 
  ko_make_with_layers_negmods_and_options(MOD_BIT(KC_RSFT)                      // Modifier
                                          , KC_TAB                              // Trigger key
                                          , KC_F22                              // Replacement
                                          , (1 << _BASE)                        // Layers
                                          , (uint8_t) ~MOD_BIT(KC_RSFT)         // Negative_mods
                                          , ko_option_activation_trigger_down); // Options

const key_override_t ko_lshift_lead = 
  ko_make_with_layers_negmods_and_options(MOD_BIT(KC_LSFT)
                                          , KC_LEAD
                                          , KC_F23
                                          , (1 << _BASE)
                                          , (uint8_t) ~MOD_BIT(KC_LSFT)
                                          , ko_option_activation_trigger_down);

const key_override_t ko_rshift_f16 = 
  ko_make_with_layers_negmods_and_options(MOD_BIT(KC_RSFT)
                                          , KC_F16
                                          , KC_PGUP
                                          , (1 << _BASE)
                                          , (uint8_t) ~MOD_BIT(KC_RSFT)
                                          , ko_option_activation_trigger_down);

const key_override_t ko_rshift_prtscr = 
  ko_make_with_layers_negmods_and_options(MOD_BIT(KC_RSFT)
                                          , FT_PSCR
                                          , KC_PGDN
                                          , (1 << _BASE)
                                          , (uint8_t) ~MOD_BIT(KC_RSFT)
                                          , ko_option_activation_trigger_down);

const key_override_t **key_overrides = (const key_override_t *[]){
	&ko_rshift_tab,
  &ko_lshift_lead,
  &ko_rshift_f16,
  &ko_rshift_prtscr,
	NULL // Null terminate the array of overrides!
};
