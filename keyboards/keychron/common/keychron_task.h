<<<<<<<< HEAD:keyboards/keychron/x0/mcuconf.h
/* Copyright 2020 QMK
========
/* Copyright 2022 ~ 2025 @ Keychron (https://www.keychron.com)
>>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/common/keychron_task.h
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

#pragma once

#include "stdint.h"
#include "action.h"

<<<<<<<< HEAD:keyboards/keychron/x0/mcuconf.h
#undef STM32_PLLM_VALUE
#define STM32_PLLM_VALUE 8

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE
========
bool keychron_task_kb(void);
bool process_record_keychron_kb(uint16_t keycode, keyrecord_t *record);

void keychron_task(void);
>>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/common/keychron_task.h
