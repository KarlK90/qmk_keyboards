# Choose to use RISC-V or ARM MCU
RISC-V ?= yes

ifeq ($(strip $(RISC-V)), yes)
    MCU                =   GD32VF103
    BOARD              =   SIPEED_LONGAN_NANO
    BOOTLOADER         =   gd32v-dfu
    # BOOTLOADER = tinyuf2
    LTO_ENABLE         =   yes
    EXTRAFLAGS         += -O2  -gdwarf-5
    # Default clock is 96MHz, 120MHz is out of spec but possible.
    OPT_DEFS           += -DOVERCLOCK_120MHZ
    TOOLCHAIN = riscv64-unknown-elf-
else
    MCU        =   STM32F303
    BOARD      =   GENERIC_STM32_F303XC
    BOOTLOADER = stm32-dfu
    LTO_ENABLE =   yes
    EXTRAFLAGS += -Os
endif

# DZZY source files
SRC     += matrix.c karlk90.qgf.c iosevka11.qff.c
LAYOUTS =  dzzy_5x6

# Debugging
ALLOW_WARNINGS =   yes

# QMK features 
CONSOLE_ENABLE                     = yes
CUSTOM_MATRIX                      = lite
EEPROM_DRIVER                      = vendor
ENCODER_ENABLE                     = no
EXTRAKEY_ENABLE                    = no
KEYBOARD_SHARED_EP                 = yes
MOUSEKEY_ENABLE                    = no
NKRO_ENABLE                        = yes
REGISTER_MULTIPLE_KEYEVENTS_ENABLE = yes
VIA_ENABLE                         = no
WPM_ENABLE                         = no
QUANTUM_PAINTER_ENABLE             = yes
QUANTUM_PAINTER_DRIVERS            = ili9341_spi
