/* Copyright 2019
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

#include "config_common.h"

#define MATRIX_ROWS 2
#define MATRIX_COLS 1

#define VENDOR_ID 0xDEAD
#define PRODUCT_ID 0xBABE
#define DEVICE_VER 0x6666
#define MANUFACTURER KARLK90

#define MATRIX_COL_PINS \
    { GP2 }
#define MATRIX_ROW_PINS \
    { GP3 }
#define DIODE_DIRECTION COL2ROW
#define UNUSED_PINS
#define DEBUG_MATRIX_SCAN_RATE
// #define SPLIT_LAYER_STATE_ENABLE
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define SPLIT_MAX_CONNECTION_ERRORS 0
// #define SERIAL_USART_FULL_DUPLEX // Enable full duplex operation mode.
// #define SERIAL_USART_PIN_SWAP 
// #    define SERIAL_USART_SPEED 460800
// #define SERIAL_USART_SPEED 921600
// #define DISABLE_SYNC_TIMER
// #define SERIAL_USART_SPEED 115200
#define SERIAL_USART_DRIVER SIOD0 // USART driver of TX and RX pin. default: SD1
#define SERIAL_USART_TIMEOUT 20    // USART driver timeout. default 20
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
// #define SERIAL_PIO_USE_PIO1

#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 60000 * 10
#define I2C1_CLOCK_SPEED 1000000

/* #define BACKLIGHT_PIN         A0 */
/* #define BACKLIGHT_PWM_DRIVER  PWMD5 */
/* #define BACKLIGHT_PWM_CHANNEL 1 */

/* SPI DRIVER */
#define SPI_DRIVER SPID1

/* EEPROM DRIVER */
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN GP13
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
#define RGB_DI_PIN GP16
#define RGBLED_NUM 32
#define WS2812_PIO_USE_PIO1 
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT \
    { 16, 16 }
#define RGBLIGHT_ANIMATIONS
// #define WS2812_EXTERNAL_PULLUP

/* #define ADC_PIN A0 */
