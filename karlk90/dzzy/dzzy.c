#include <quantum.h>

void keyboard_post_init_user(void) {
    // Free B4 pin.
    AFIO->MAPR |= AFIO_PCF0_SWJ_CFG_NOJNTRST;
    // Customise these values to desired behaviour
    // debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse=true;
}
