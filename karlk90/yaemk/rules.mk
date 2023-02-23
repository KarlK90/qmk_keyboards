# Shared configs
LTO_ENABLE = yes
EXTRAFLAGS += -O2

# YAEMK source files
SRC = led_config.c custom_color.c

# QMK features
CAPS_WORD_ENABLE              = yes
CONSOLE_ENABLE                = no
DEBOUNCE_TYPE                 = asym_eager_defer_pk
DEBUG_MATRIX_SCAN_RATE_ENABLE = yes
EEPROM_DRIVER                 = i2c
ENCODER_ENABLE                = yes
ENCODER_MAP_ENABLE            = yes
EXTRAKEY_ENABLE               = yes
MOUSEKEY_ENABLE               = yes
NKRO_ENABLE                   = yes
OLED_DRIVER                   = SSD1306
OLED_ENABLE                   = no
RGB_MATRIX_DRIVER             = WS2812
RGB_MATRIX_ENABLE             = yes
SERIAL_DRIVER                 = usart
SPLIT_KEYBOARD                = yes
WS2812_DRIVER                 = pwm
