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

#include QMK_KEYBOARD_H

#ifdef QUANTUM_PAINTER_ENABLE
#    include "qp.h"
#    include "karlk90.qgf.h"
#    include "iosevka11.qff.h"
static painter_device_t       display;
static painter_image_handle_t image;
static painter_font_handle_t  font;
#endif

void keyboard_post_init_user(void) {
    debug_enable = true;
#ifdef QUANTUM_PAINTER_ENABLE
    display = qp_ili9341_make_spi_device(240, 320, GP17, GP16, GP20, 8, 0);
    qp_init(display, QP_ROTATION_0); // Initialise the display
    qp_power(display, true);
    image = qp_load_image_mem(gfx_karlk90);
    if (image != NULL) {
        qp_drawimage(display, 0, 0, image);
        // qp_flush(display);
    }
    font = qp_load_font_mem(font_iosevka11);
    if (font != NULL) {
        qp_drawtext(display, 40, 160, font, "QUANTUM PAINTER @ RP2040");
    }
#endif
    // Customise these values to desired behaviour
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse=true;
}

void housekeeping_task_user(void) {
    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();
        // Draw 8px-wide rainbow down the left side of the display
        for (int i = 240; i < 319; ++i) {
            qp_line(display, 0, i, 239, i, i, 255, 255);
        }
        qp_flush(display);
    }
}

void board_init(void) {}

// void keyboard_post_init_user(void) {
//     debug_enable   = true;
//     debug_matrix   = true;
//     debug_keyboard = true;
//     debug_mouse    = true;
// }

// void raw_hid_receive(uint8_t *data, uint8_t length) {
//     dprintln("GOT RAW HID");
//     raw_hid_send(data, length);
// }

// void housekeeping_task_user(void) {
//     static uint16_t start = 0;
//     if (timer_elapsed(start) > 1000) {
//         // TRICE(Id(37873), "Hallo Kevin %d\n", start);
//         // triceTriggerTransmit();
//         // TriceTransfer();
//         start = timer_read();
//         if (host_keyboard_led_state().caps_lock) {
//             dprintln("CAPS!");
//         } else {
//             dprintln("NO CAPS!");
//         }
//         //     dprintf("Fresh into eeprom %d\n", (uint8_t)start);
//         //     eeconfig_update_debug((uint8_t)start);
//         //     dprintf("Fresh from eeprom %d\n", (uint8_t)eeconfig_read_debug());
//     }
// }
uint32_t ReadUs32(void) {
    return chSysGetRealtimeCounterX();
};
