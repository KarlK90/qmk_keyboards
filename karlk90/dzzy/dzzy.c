#include "dzzy.h"

#ifdef QUANTUM_PAINTER_ENABLE
#    include "qp.h"
#    include "karlk90.qgf.h"
#    include "iosevka11.qff.h"
static painter_device_t       display;
static painter_image_handle_t image;
static painter_font_handle_t  font;
#endif

void keyboard_post_init_user(void) {
#ifdef QUANTUM_PAINTER_ENABLE
    display = qp_ili9341_make_spi_device(240, 320, B5, B12, B7, 2, 0);
    qp_init(display, QP_ROTATION_0); // Initialise the display
    qp_power(display, true);
    image = qp_load_image_mem(gfx_karlk90);
    if (image != NULL) {
        qp_drawimage(display, 0, 0, image);
        qp_flush(display);
    }
    font = qp_load_font_mem(font_iosevka11);
    if (font != NULL) {
        qp_drawtext(display, 0, 0, font, "QMK or BUST mattafakka!äüöß");
    }
#endif
#if defined(__riscv)
    // Free B4 pin.
    AFIO->MAPR |= AFIO_PCF0_SWJ_CFG_NOJNTRST;
#endif
    // Customise these values to desired behaviour
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse=true;
}

void housekeeping_task_user(void) {
    static uint32_t last_draw = 0;
    // if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
    //     last_draw = timer_read32();
    //     // Draw 8px-wide rainbow down the left side of the display
    //     for (int i = 0; i < 239; ++i) {
    //         qp_line(display, 0, i, 239, i, i, 255, 255);
    //     }
    //     qp_flush(display);
    // }
}

#if defined(__riscv)

#    pragma GCC push_options
#    pragma GCC optimize("O0")

uintptr_t handle_trap(uintptr_t mcause, uintptr_t sp, uintptr_t mdcause, uintptr_t msubm) {
    uint32_t             m_epc        = __RV_CSR_READ(mepc);
    uint32_t             m_tval       = __RV_CSR_READ(mtval);
    uint32_t             m_bad        = __RV_CSR_READ(mbadaddr);
    CSR_MSTATUS_Type     m_status     = {.d = __RV_CSR_READ(mstatus)};
    CSR_MCAUSE_Type      m_cause      = {.d = mcause};
    CSR_MSAVESTATUS_Type m_savestatus = {.w = __RV_CSR_READ(CSR_MSAVESTATUS)};
    CSR_MSUBM_Type       m_subm       = {.d = msubm};

    (void)m_epc;
    (void)m_tval;
    (void)m_bad;
    (void)m_status;
    (void)m_cause;
    (void)m_savestatus;
    (void)m_subm;

    while (1)
        ;

    return 0;
}
#    pragma GCC pop_options

#endif
