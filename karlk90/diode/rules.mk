MCU                =   GD32VF103
BOARD              =   SIPEED_LONGAN_NANO
LTO_ENABLE         =   yes
EXTRAFLAGS         += -Os
USE_PROCESS_STACKSIZE = 2048
# Default clock is 96MHz, 120MHz is out of spec but possible.
OPT_DEFS           += -DOVERCLOCK_120MHZ

# YAEMK source files
#SRC     = led_config.c custom_color.c
SRC     = led_config.c 

# Debugging
#EXTRAFLAGS     += -gdwarf-4 -Wextra -Wconversion
ALLOW_WARNINGS =   yes

# QMK features
CONSOLE_ENABLE                     = no
EEPROM_DRIVER                      = vendor
KEYBOARD_SHARED_EP                 = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
VIA_ENABLE                         = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes
VIALRGB_ENABLE = yes
WS2812_DRIVER                      = pwm
