// Copyright 2022 @geigeigeist
// SPDX-License-Identifier: GPL-2.0+

#pragma once

#include "config_common.h"

/* audio support */
#undef AUDIO_PIN
//#define AUDIO_PIN GP9

/* i2c */
#define I2C_DRIVER I2CD2
#define I2C1_CLOCK_SPEED 1000000

/* split communication */
#define SERIAL_USART_SPEED 460800

/* crc */
#define CRC8_OPTIMIZE_SPEED
