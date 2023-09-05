## Copyright 2022 Kevin Hoang (@ttemayo) <khoang65@gmail.com>
## SPDX-License-Identifier: GPL-2.0-or-later
## Userspace rules.mk
##
## NOTE: This is included in build AFTER keyboard specific rules 

SRC += ttemayo.c

# ttemayo's Custom Features
ifeq ($(strip $(USER_SYM_MACROS_ENABLE)), yes)
    OPT_DEFS += -DUSER_SYM_MACROS_ENABLE
endif

ifeq ($(strip $(USER_VIMDOWS_ENABLE)), yes)
	SRC += features/vimdows.c
    OPT_DEFS += -DUSER_VIMDOWS_ENABLE
endif

# QMK Features
ifeq ($(strip $(KEY_OVERRIDE_ENABLE)), yes)
	SRC += features/key_override.c
    OPT_DEFS += -DKEY_OVERRIDE_ENABLE
endif

#ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
#  SRC += tap_dance.c
#endif
