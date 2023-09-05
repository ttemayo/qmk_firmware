// Copyright 2022 Kevin Hoang (@ttemayo) <khoang65@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H
#include "ttemayo.h"

const key_override_t ko_rshift_tab;
const key_override_t ko_lshift_lead;
const key_override_t ko_rshift_f16;
const key_override_t ko_rshift_prtscr;

// This globally defines all key overrides to be used
const key_override_t **key_overrides;
