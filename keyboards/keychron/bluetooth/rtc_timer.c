/* Copyright 2023 ~ 2025 @ lokher (https://www.keychron.com)
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

#if (HAL_USE_RTC)
#    include "hal.h"
#    include "rtc_timer.h"

<<<<<<< HEAD:keyboards/bbrfkr/dynamis/dynamis.c
#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (clockwise) {
        tap_code(layer_state == 0 ? MS_WHLD : KC_VOLD);
    } else {
        tap_code(layer_state == 0 ? MS_WHLU : KC_VOLU);
    }
    return true;
=======
void rtc_timer_init(void) {
    rtc_timer_clear();
}

void rtc_timer_clear(void) {
    RTCDateTime tm = {0, 0, 0, 0, 0, 0};
    rtcSetTime(&RTCD1, &tm);
}

uint32_t rtc_timer_read_ms(void) {
    RTCDateTime tm;
    rtcGetTime(&RTCD1, &tm);

    return tm.millisecond;
}

uint32_t rtc_timer_elapsed_ms(uint32_t last) {
    return TIMER_DIFF_32(rtc_timer_read_ms(), last);
>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/bluetooth/rtc_timer.c
}
#endif
