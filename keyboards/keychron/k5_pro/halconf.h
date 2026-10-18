/* Copyright 2020 ~ 2025 @ Keychron (https://www.keychron.com)
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

#define _CHIBIOS_HAL_CONF_VER_8_4_

#define HAL_USE_I2C TRUE

#if defined(ENCODER_ENBALE) || defined(KC_BLUETOOTH_ENABLE)
#    define PAL_USE_CALLBACKS TRUE
#endif

<<<<<<< HEAD:keyboards/custommk/evo70_r2/halconf.h
#define HAL_USE_RTC TRUE

#define HAL_USE_SPI TRUE

#define HAL_USE_GPT TRUE

#define SERIAL_BUFFERS_SIZE 256
=======
#ifdef KC_BLUETOOTH_ENABLE
#    define HAL_USE_SERIAL TRUE
#    define HAL_USE_RTC TRUE
#endif
>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/k5_pro/halconf.h

#include_next <halconf.h>
