/* Copyright 2023 ~ 2025 @ Keychron (https://www.keychron.com)
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

#include "stdint.h"
#ifdef VIA_ENABLE
#    include "via.h"
#endif
#include "quantum_keycodes.h"

void lkbt51_param_init(void);

<<<<<<< HEAD:keyboards/fungo/rev1/post_config.h
#ifndef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED	20
#endif
=======
bool process_record_keychron_wireless(uint16_t keycode, keyrecord_t *record);
void keychron_wireless_common_task(void);
>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/common/wireless/keychron_wireless_common.h
