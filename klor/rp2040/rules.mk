# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# LTO must be disabled for RP2040 builds
LTO_ENABLE = yes

# PIO serial/WS2812 drivers must be used on RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

# Audio currently doesn't work with the RP2040
AUDIO_ENABLE = no

# convert to rp2040 pinout. if you use the kb2040 comment this line and uncomment the second line
CONVERT_TO = kb2040
