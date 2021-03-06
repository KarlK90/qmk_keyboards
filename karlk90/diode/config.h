#pragma once

#include "config_common.h"

/* USB CONFIG */
#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO
/* Device descriptor parameters */
#define VENDOR_ID 0xDEAD   // KK
#define PRODUCT_ID 0xBEEF  // YA
#define DEVICE_VER 0x0003
#define MANUFACTURER KARLK90
#define VIAL_KEYBOARD_UID \
    { 0xE7, 0xC1, 0xC2, 0x83, 0xFF, 0x9B, 0xD2, 0x3C }

// clang-format off
#define PRODUCT WS2803 RISC-V
#define DESCRIPTION RGB TEST
// clang-format on

/* MATRIX CONFIG */
#define MATRIX_ROWS 2
#define MATRIX_COLS 2
#define MATRIX_COL_PINS \
    { B12, B13 }
#define MATRIX_ROW_PINS \
    { B15, B14 }
#define DIODE_DIRECTION COL2ROW
#define DEBUG_MATRIX_SCAN_RATE
#define DEBOUNCE 5
#define QMK_KEYS_PER_SCAN 8

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define VIALRGB_NO_DIRECT
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_RAIN

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
/* WS2812 DRIVER */
#define RGBLED_NUM 4
#define DRIVER_LED_TOTAL 4
#define FASTLED_SCALE8_FIXED 1
#define RGB_DI_PIN A10
#define WS2812_TRST_US 80
#define WS2812_PWM_TARGET_PERIOD 800000
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 6
#define WS2812_DMA_CHANNEL 5
/* #define WS2812_EXTERNAL_PULLUP */
#define WS2812_DMA_STREAM GD32_DMA0_STREAM4
