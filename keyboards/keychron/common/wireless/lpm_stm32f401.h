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

#pragma once

#ifndef STOP_MODE_MAIN_REGULATOR_LOW_VOLTAGE
#    define STOP_MODE_MAIN_REGULATOR_LOW_VOLTAGE TRUE
#endif

<<<<<<< HEAD:keyboards/ibm/model_m_4th_gen/overnumpad_1xb/config.h
#define SOLENOID_PIN B5
#define HAPTIC_ENABLE_PIN C13
#define SOLENOID_DEFAULT_DWELL 20
#define SOLENOID_MIN_DWELL 4
#define HAPTIC_OFF_IN_LOW_POWER 1
#define NO_HAPTIC_MOD
=======
#ifndef STOP_MODE_LOW_POWER_REGULATOR_LOW_VOLTAG
#    define STOP_MODE_LOW_POWER_REGULATOR_LOW_VOLTAG TRUE
#endif

#ifndef STOP_MODE_FLASH_POWER_DOWN
#    define STOP_MODE_FLASH_POWER_DOWN TRUE
#endif

#ifndef STOP_MODE_LOW_POWER_DEEPSLEEP
#    define STOP_MODE_LOW_POWER_DEEPSLEEP TRUE
#endif
>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/common/wireless/lpm_stm32f401.h
