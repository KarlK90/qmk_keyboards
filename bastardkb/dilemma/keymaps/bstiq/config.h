/**
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef VIA_ENABLE
/* Via/Vial configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8
#    ifdef VIAL_ENABLE
/** Vial-specific configuration. */

#        define VIAL_KEYBOARD_UID \
            { 0x09, 0x80, 0xDF, 0x80, 0xFB, 0x72, 0xB8, 0x4A }
#        define VIAL_UNLOCK_COMBO_ROWS \
            { 0, 4 }
#        define VIAL_UNLOCK_COMBO_COLS \
            { 0, 0 }
#    endif // VIAL_ENABLE
#endif     // VIA_ENABLE

/**
 * Configure the global tapping term (default: 200ms).
 * If you have a lot of accidental mod activations, crank up the tapping term.
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
 */
#ifndef TAPPING_TERM
#    define TAPPING_TERM 160
#endif // TAPPING_TERM

// disable trackpad taps
// #define CIRQUE_PINNACLE_TAPPING_TERM 0

/**
 * Enable rapid switch from tap to hold.  Disable auto-repeat when pressing key
 * twice, except for one-shot keys.
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold
 */
#define TAPPING_FORCE_HOLD

/*
 * Tap-or-Hold decision modes.
 *
 * Note that the following flags behave differently when combined (ie. when 2 or
 * more are enabled).
 *
 * See bit.ly/tap-or-hold for a visual explanation of the following tap-or-hold
 * decision modes.
 */

/**
 * Faster tap-hold trigger.
 *
 * Without `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ ae
 * With `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ Mod+e
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
 */
#define PERMISSIVE_HOLD

/**
 * Prevent normal rollover on alphas from accidentally triggering mods.
 *
 * Ignores key presses that interrupt a mod-tap.  Must-have for Home Row mod.
 *
 * Without `IGNORE_MOD_TAP_INTERRUPT`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 ➞ Mod+e
 * With `IGNORE_MOD_TAP_INTERRUPT`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 ➞ ae
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
 */
#define IGNORE_MOD_TAP_INTERRUPT

/** Dilemma-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Flip horizontal direction for drag-scroll.
#    define DILEMMA_DRAGSCROLL_REVERSE_X
// #define DILEMMA_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE

/** RGB Matrix. */

#ifdef RGB_MATRIX_ENABLE
// Enable all animations on ARM boards since they have plenty of memory
// available for it.
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_MULTISPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

// Limit maximum brightness to keep power consumption reasonable, and avoid
// disconnects.
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64

// Rainbow swirl as startup mode.
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

// Slow swirl at startup.
#    define RGB_MATRIX_STARTUP_SPD 32

// Startup values.
#    define RGB_MATRIX_STARTUP_HUE 0
#    define RGB_MATRIX_STARTUP_SAT 255
#    define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_STARTUP_HSV RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT, RGB_MATRIX_STARTUP_VAL
#endif // RGB_MATRIX_ENABLE
