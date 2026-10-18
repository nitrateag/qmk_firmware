/* Copyright 2025 @ lokher (https://www.keychron.com)
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

<<<<<<< HEAD:keyboards/akko/5108/halconf.h
#define HAL_USE_I2C TRUE
#define HAL_USE_SPI TRUE

#include_next <halconf.h>
=======
typedef enum {
    PM_RUN,
    PM_LOW_POWER_RUN,
    PM_SLEEP,
    PM_LOW_POWER_SLEEP,
    PM_STOP0,
    PM_STOP1,
    PM_STOP2,
    PM_STANDBY_WITH_RAM,
    PM_STANDBY,
    PM_SHUTDOWN,
} pm_t;
>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/common/wireless/lpm_stm32l432.h
