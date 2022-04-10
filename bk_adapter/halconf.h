#pragma once

#define HAL_USE_SPI TRUE
#define HAL_USE_PWM TRUE
#define HAL_USE_SERIAL TRUE
#define HAL_USE_GPT TRUE
#define PAL_USE_WAIT TRUE
#define PAL_USE_CALLBACKS TRUE

#include_next <halconf.h>
