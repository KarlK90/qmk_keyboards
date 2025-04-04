#pragma once

#include "config_common.h"

/* USB CONFIG */
#define FORCE_NKRO

/* MATRIX CONFIG */
#define MATRIX_ROWS 10
#define MATRIX_COLS 8
#define MATRIX_COL_PINS \
    { B15, B14, B13, B2, B1, B0, A7, A2 }
#define MATRIX_ROW_PINS \
    { A8, B12, A6, A5, A1 }
#define MATRIX_COL_PINS_RIGHT \
    { A2, A7, B0, B1, B2, B13, B14, B15 }
#define DIODE_DIRECTION COL2ROW
// #define DEBUG_MATRIX_SCAN_RATE
#define DEBOUNCE 10

/* CAPS WORD CONFIG */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* ENCODER CONFIG */
#define ENCODER_RESOLUTION 2
#define ENCODERS_PAD_A_RIGHT \
    { A4 }
#define ENCODERS_PAD_B_RIGHT \
    { A3 }
#define ENCODERS_PAD_A \
    { A3 }
#define ENCODERS_PAD_B \
    { A4 }

/* SPLIT CONFIG */
#define SPLIT_HAND_PIN C13
#define USB_VBUS_PIN A9
#define SPLIT_LAYER_STATE_ENABLE
#define FORCED_SYNC_THROTTLE_MS 500
#define SPLIT_TRANSPORT_MIRROR

/* CRC DRIVER */
#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* RGB MATRIX CONFIG */
#define RGB_MATRIX_HUE_STEP 6
#define RGB_MATRIX_SAT_STEP 6
#define RGB_MATRIX_VAL_STEP 6
#define RGB_MATRIX_SPD_STEP 6
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

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

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
// #define RGB_MATRIX_LED_PROCESS_LIMIT DRIVER_LED_TOTAL / 10
// #define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_SPLIT \
    { 40, 40 }

/* WS2812 DRIVER */
#define RGB_MATRIX_LED_COUNT 80
// #define RGBLED_NUM DRIVER_LED_TOTAL
// #define DRIVER_LED_TOTAL 80
#define FASTLED_SCALE8_FIXED 1
#define RGB_DI_PIN A10
#define WS2812_TRST_US 80
#define WS2812_PWM_TARGET_PERIOD 800000
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 6
#define WS2812_DMA_CHANNEL 5
#define WS2812_EXTERNAL_PULLUP

/* SERIAL SPLIT DRIVER */
#define SERIAL_USART_TX_PIN B10
#define SERIAL_USART_RX_PIN B11
#define SERIAL_USART_DRIVER SD3
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TIMEOUT 5
#define SERIAL_USART_CR2 0x0  // 1 stop bit is enough

/* I2C DRIVER */
#define EEPROM_I2C_CAT24C512

/* OLED DRIVER CONFIG */
#define OLED_DISPLAY_CUSTOM
#define OLED_DISPLAY_WIDTH 64
#define OLED_DISPLAY_HEIGHT 128
#define OLED_COM_PIN_OFFSET 32
#define OLED_MATRIX_SIZE (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH)
#define OLED_BLOCK_TYPE uint16_t
#define OLED_SOURCE_MAP \
    { 0, 8, 16, 24, 32, 40, 48, 56 }
#define OLED_TARGET_MAP \
    { 56, 48, 40, 32, 24, 16, 8, 0 }
#define OLED_BLOCK_COUNT (sizeof(OLED_BLOCK_TYPE) * 8)
#define OLED_BLOCK_SIZE (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT)
#define OLED_COM_PINS COM_PINS_ALT
#define OLED_IC OLED_IC_SH1107
#define OLED_BRIGHTNESS 255
#define OLED_TIMEOUT 15000
#define OLED_UPDATE_INTERVAL 200

/* TAPPING CONFIG */
#define TAPPING_TERM 160
#define TAPPING_TOGGLE 2
#define QUICK_TAP_TERM 0
#define IGNORE_MOD_TAP_INTERRUPT
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define LAYER_STATE_8BIT

/* MOUSEKEY CONFIG */
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

/* JOYSTICK CONFIG */
#define JOYSTICK_AXES_COUNT 0
#define JOYSTICK_BUTTON_COUNT 0

/* VIA CONFIG */
#if defined(VIA_ENABLE)
#    define DYNAMIC_KEYMAP_LAYER_COUNT 6
#    define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 4095
#endif
