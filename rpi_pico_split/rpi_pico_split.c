/* Copyright 2021 Stefan Kerkmann
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

#include "rpi_pico_split.h"
#include "debug.h"
#include <hal.h>
// #include "trice.h"
// #define TRICE_FILE Id(60868)

void keyboard_post_init_user(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
#if defined(RGBLIGHT_ENABLE)
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(255, 255, 128);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
#endif
}

void usart_init(void) {
    palSetLineMode(GP0, PAL_MODE_ALTERNATE_UART);
    palSetLineMode(GP1, PAL_MODE_ALTERNATE_UART);
}

#if defined(OLED_ENABLE)
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    oled_write_ln("\n", true);
    oled_write_ln("RP2040 here we go!", true);
    return false;
}
#endif

void housekeeping_task_user(void) {
    static uint16_t start = 0;
    if (timer_elapsed(start) > 1000) {
        // TRICE(Id(37873), "Hallo Kevin %d\n", start);
        // triceTriggerTransmit();
        // TriceTransfer();
        start = timer_read();
        //     dprintf("Fresh into eeprom %d\n", (uint8_t)start);
        //     eeconfig_update_debug((uint8_t)start);
        //     dprintf("Fresh from eeprom %d\n", (uint8_t)eeconfig_read_debug());
    }
}

uint32_t ReadUs32(void) {
    return chSysGetRealtimeCounterX();
}

uint8_t get_bar_bits(uint8_t load) {
    uint8_t temp = 0;
    if (load > 2 && load < 10) {
        temp = 0b1000;
    } else if (load >= 90) {
        temp = 0b1111;
    } else if (load >= 50) {
        temp = 0b0111;
    } else if (load >= 25) {
        temp = 0b0011;
    } else if (load >= 10) {
        temp = 0b0001;
    }
    return temp;
};

#ifdef VIA_ENABLE
/*
Stop sending hid data before opening VIA application on host. All hid data is sent back to the host
with via enabled. The VIA application will not work as expected.
    data[0] 0x03 (VIA id_set_keyboard_value) workaround via doesn't seem to pass id_unhandled onto _kb
    data[1] 0xFF (not valid command data for id_set_keyboard_value so will be passed onto *kb (no *user))
    data[2-4] h, s, v (will automatically set mode to static)
    data[5] 0x01 is RGB update
    data[6+] temperature, load etc
*/
void raw_hid_receive_kb(uint8_t* data, uint8_t length) {
#else

#    define RAW_HUE data[2]
#    define RAW_SAT data[3]
#    define RAW_VAL data[4]
#    define RAW_DORGB data[5]
#    define RAW_CPU_TEMP data[6]
#    define RAW_CPU_LOAD data[9]
#    define RAW_GPU_TEMP data[7]
#    define RAW_GPU_LOAD data[10]

void raw_hid_receive(uint8_t* data, uint8_t length) {
#endif
    // #ifdef RGB_LIGHTNING_ENABLE
    if (RAW_DORGB == 1) {
        static uint16_t old_hue      = 0;
        static bool     changed_mode = false;
        if (!changed_mode) { // only change mode on first update
            changed_mode = true;

            // rgb_matrix_mode_noeeprom(RGB_MATRIX_HUE_WAVE);
        }
        if (old_hue != RAW_HUE || old_hue == 0) {
            old_hue = RAW_HUE;
            // uint8_t val = rgb_matrix_get_val();
            // rgb_matrix_sethsv_noeeprom(RAW_HUE, RAW_SAT, val);
            dprintf("HUE changed!");
        }
    }
    // #endif
    uint8_t cpu_temp = data[6];
    uint8_t cpu_load = get_bar_bits(data[9]);
    uint8_t gpu_temp = data[7];
    uint8_t gpu_load = get_bar_bits(data[10]);
}
