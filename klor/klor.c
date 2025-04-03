#include <platform_deps.h>
#include <gpio.h>

static const ioportmask_t col_mask = (1 << GP27 | 1 << GP26 | 1 << GP22 | 1 << GP20 | 1 << GP23 | 1 << GP21);

/**
 * @brief Helper function to wait until the IO port has reached the wanted
 * target state. This only works for Push-Pull pins with enabled input stage.
 */
static void __time_critical_func(matrix_wait_for_port)(ioportmask_t target_bitmask) {
    rtcnt_t start = chSysGetRealtimeCounterX();
    rtcnt_t end   = start + MS2RTC(REALTIME_COUNTER_CLOCK, 100);
    while (chSysIsCounterWithinX(chSysGetRealtimeCounterX(), start, end)) {
        if (palReadGroup(IOPORT1, target_bitmask, 0) == target_bitmask) {
            return;
        }
    }
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
    matrix_wait_for_port(col_mask);
}
