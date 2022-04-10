# MCU name
MCU = STM32F401
# or
# MCU = STM32F411
# For newer blackpills

LAYOUTS = split_4x6_5

# Bootloader selection
BOOTLOADER = stm32-dfu

CONSOLE_ENABLE         = yes
DEBOUNCE_TYPE          = asym_eager_defer_pk
EEPROM_DRIVER          = spi
KEYBOARD_SHARED_EP     = yes
POINTING_DEVICE_DRIVER = pmw3360
POINTING_DEVICE_ENABLE = yes
RGBLIGHT_DRIVER        = WS2812
RGBLIGHT_ENABLE        = yes
SERIAL_DRIVER          = usart
SPLIT_KEYBOARD         = yes
VIA_ENABLE             = no
WS2812_DRIVER          = pwm
