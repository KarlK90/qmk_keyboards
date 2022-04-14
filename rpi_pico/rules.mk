# MCU name
MCU = RP2040

ALLOW_WARNINGS = yes
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS!
VIA_ENABLE = yes
#RAW_ENABLE = no 
SHARED_EP_ENABLE = no
CONSOLE_ENABLE = yes
LTO_ENABLE = no
OPT_DEFS = -Og -gdwarf-4# -DUSB_DEBUG
EEPROM_DRIVER = transient


SRC     += karlk90.qgf.c iosevka11.qff.c

QUANTUM_PAINTER_ENABLE             = yes
QUANTUM_PAINTER_DRIVERS            = ili9341_spi

LAYOUTS = ortho_1x1
