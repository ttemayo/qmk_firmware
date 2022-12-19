// Copyright 2022 Kevin Hoang (@ttemayo) <khoang65@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Use I2C or Serial, not both */
#define USE_SERIAL

/* Select hand config */
#define MASTER_LEFT

/* Bootloader mode config */
#ifdef BOOTMAGIC_ENABLE
#  define BOOTMAGIC_LITE_ROW 0
#  define BOOTMAGIC_LITE_COLUMN 0 // default esc
#endif

/* N-key rollover config */
/*
#ifdef NKRO_ENABLE
  #undef FORCE_NKRO
  #define FORCE_NKRO // QMK default is 6KRO
#endif 
*/

/* Polling rate and keys per scan for video games */
#define USB_POLLING_INTERVAL_MS 1 // Set polling to 1000Hz
#define QMK_KEYS_PER_SCAN 4 // By default, only 1 key event gets sent via process_record() per scan

/* Defines what is considered a hold vs tap, affects both Mod Tap and Tap Dance */
#undef TAPPING_TERM
#define TAPPING_TERM 120 // QMK default 200; omkb/ergodash/rev1 default 120
#define TAPPING_TERM_PER_KEY // Used in conjunction with get_tapping_term() to finetune

/* If no other key is pressed with mod, still sends input even after tapping term window */
#undef RETRO_TAPPING_PER_KEY
#define RETRO_TAPPING_PER_KEY

/* Tap-Or-Hold Decision Modes */
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT

/* Slightly changes dual-role keys */
// #undef PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY // Used in conjuction with get_permissive_hold() to finetune

/* Select Leader Key Timeout (ms) */
#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 250
// #define LEADER_PER_KEY_TIMING 75 // fickle

/* Caps Word Timeout (ms) */
#undef CAPS_WORD_IDLE_TIMEOUT
#define CAPS_WORD_IDLE_TIMEOUT 3000 // 3 seconds.

/* Define Underglow LED settings */
// RGBLIGHT doesn't support defining physical positions for leds, it's just a 1d string of pixels
#ifdef RGBLIGHT_ENABLE
#  undef RGBLIGHT_DEFAULT_HUE
#  define RGBLIGHT_DEFAULT_HUE 148 // Azure
#endif

/* Matrix LED; both Underglow and key LEDs, will keep Disabled */
#ifdef RGB_MATRIX_ENABLE
#  undef RGB_MATRIX_STARTUP_MODE
#  undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#  undef RGB_MATRIX_STARTUP_SAT
#  undef RGB_MATRIX_LED_FLUSH_LIMIT
#  define RGB_MATRIX_STARTUP_MODE RGB_MODE_PLAIN // This causes RGB issues on my board?
#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#  define RGB_MATRIX_STARTUP_SAT 255 // Sets the default saturation value, if none has been set
#  define RGB_MATRIX_LED_FLUSH_LIMIT 16 /* Limits, in milliseconds, how frequently an animation will update the LEDs. 
                                            16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
                                            default: 26 */
/* Active RGB Matrix Effects */
// None

/* Inactive RGB Matrix Effects, Disabling to optimize firmware size */
#  define DISABLE_RGB_MATRIX_ALPHAS_MODS               // Static dual hue, speed is hue for secondary hue
#  define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN          // Static gradient top to bottom, speed controls how much gradient changes
#  define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT       // Static gradient left to right, speed controls how much gradient changes
#  define DISABLE_RGB_MATRIX_BREATHING                 // Single hue brightness cycling animation
#  define DISABLE_RGB_MATRIX_BAND_SAT                  // Single hue band fading saturation scrolling left to right
#  define DISABLE_RGB_MATRIX_BAND_VAL                  // Single hue band fading brightness scrolling left to right
#  define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT         // Single hue 3 blade spinning pinwheel fades saturation
#  define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL         // Single hue 3 blade spinning pinwheel fades brightness
#  define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT           // Single hue spinning spiral fades saturation
#  define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL           // Single hue spinning spiral fades brightness
#  define DISABLE_RGB_MATRIX_CYCLE_ALL                 // Full keyboard solid hue cycling through full gradient
#  define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT          // Full gradient scrolling left to right
#  define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN             // Full gradient scrolling top to bottom
#  define DISABLE_RGB_MATRIX_CYCLE_OUT_IN              // Full gradient scrolling out to in
#  define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL         // Full dual gradients scrolling out to in
#  define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON    // Full gradent Chevron shapped scrolling left to right
#  define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL            // Full gradient spinning pinwheel around center of keyboard
#  define DISABLE_RGB_MATRIX_CYCLE_SPIRAL              // Full gradient spinning spiral around center of keyboard
#  define DISABLE_RGB_MATRIX_DUAL_BEACON               // Full gradient spinning around center of keyboard
#  define DISABLE_RGB_MATRIX_RAINBOW_BEACON            // Full tighter gradient spinning around center of keyboard
#  define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS         // Full dual gradients spinning two halfs of keyboard
#  define DISABLE_RGB_MATRIX_RAINDROPS                 // Randomly changes a single key's hue
#  define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS       // Randomly changes a single key's hue and saturation
#  define DISABLE_RGB_MATRIX_HUE_BREATHING             // Hue shifts up a slight ammount at the same time, then shifts back
#  define DISABLE_RGB_MATRIX_HUE_PENDULUM              // Hue shifts up a slight ammount in a wave to the right, then back to the left
#  define DISABLE_RGB_MATRIX_HUE_WAVE                  // Hue shifts up a slight ammount and then back down in a wave to the right
#  define DISABLE_RGB_MATRIX_PIXEL_FRACTAL             // Single hue fractal filled keys pulsing horizontally out to edges
#  define DISABLE_RGB_MATRIX_PIXEL_FLOW                // Pulsing RGB flow along LED wiring with random hues
#  define DISABLE_RGB_MATRIX_PIXEL_RAIN                // Randomly light keys with random hues
/* #if define (RGB_MATRIX_FRAMEBUFFER_EFFECTS) */
#  define DISABLE_RGB_MATRIX_TYPING_HEATMAP   		     // How hot is your WPM!
#  define DISABLE_RGB_MATRIX_DIGITAL_RAIN              // That famous computer simulation
/* #if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES) */
#  define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Pulses keys hit to hue & value then fades value out
#  define DISABLE_RGB_MATRIX_SOLID_REACTIVE            // Static single hue, pulses keys hit to shifted hue then fades to current hue
#  define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
#  define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
#  define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
#  define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#  define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
#  define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#  define DISABLE_RGB_MATRIX_SPLASH                    // Full gradient & value pulse away from a single key hit then fades value out
#  define DISABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
#  define DISABLE_RGB_MATRIX_SOLID_SPLASH              // Hue & value pulse away from a single key hit then fades value out
#  define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out
#endif // RGB_MATRIX_ENABLE

/* Firmware Size Optimimzation */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT

#ifndef NO_DEBUG
#  define NO_DEBUG
#endif // NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#  define NO_PRINT
#endif // !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
