<<<<<<<< HEAD:keyboards/morningstar1/pttbutton/pttbutton.c
/* Copyright 2026 Sebastian Morgenstern
========
/* Copyright 2022 ~ 2025 @ lokher (https://www.keychron.com)
>>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/bluetooth/bluetooth_main.c
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

#include "quantum.h"
<<<<<<<< HEAD:keyboards/morningstar1/pttbutton/pttbutton.c
#include "hal.h"

void board_init(void) {
  // Remap PA11->PA9 and PA12->PA10 for USB
  SYSCFG->CFGR1 |= SYSCFG_CFGR1_PA11_PA12_RMP;
}

void keyboard_pre_init_kb(void) {
    // Immediately set the LED pin as an output and set it ON
    gpio_set_pin_output(A15);
    gpio_write_pin_high(A15);

    keyboard_pre_init_user();
}

void keyboard_post_init_kb(void) {
    // Blink the LED so we know everything is running OK
    // Finish with LED OFF
    gpio_write_pin_low(A15);
    wait_ms(100);
    gpio_write_pin_high(A15);
    wait_ms(100);
    gpio_write_pin_low(A15);

    keyboard_post_init_user();
========
#include "bluetooth.h"
#include "transport.h"

__attribute__((weak)) void bluetooth_pre_task(void) {}
__attribute__((weak)) void bluetooth_post_task(void) {}

void bluetooth_tasks(void) {
    bluetooth_pre_task();
    bluetooth_task();
    bluetooth_post_task();

    /* usb_remote_wakeup() should be invoked last so that we have chance
     * to switch to bluetooth after start-up when usb is not connected
     */
    if (get_transport() == TRANSPORT_USB) usb_remote_wakeup();
}

void housekeeping_task_kb(void) {
    bluetooth_tasks();
>>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/bluetooth/bluetooth_main.c
}
