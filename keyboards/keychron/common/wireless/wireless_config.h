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

#include "config.h"

//
#ifndef BT_HOST_DEVICES_COUNT
#    define BT_HOST_DEVICES_COUNT 3
#endif

<<<<<<< HEAD:keyboards/unicomp/classic_ultracl_post_2013/overnumpad_1xb/config.h
#define SOLENOID_PIN B5
#define HAPTIC_ENABLE_PIN C13
#define SOLENOID_DEFAULT_DWELL 20
#define SOLENOID_MIN_DWELL 4
#define HAPTIC_OFF_IN_LOW_POWER 1
#define NO_HAPTIC_MOD
=======
#define P2P4G_HOST_DEVICES_COUNT 1

//  Uint: Second
#ifndef DISCONNECTED_BACKLIGHT_OFF_DELAY_TIME
#    define DISCONNECTED_BACKLIGHT_OFF_DELAY_TIME 40
#endif

//  Uint: Second, the timer restarts on key activities.
#ifndef CONNECTED_BACKLIGHT_OFF_DELAY_TIME
#    define CONNECTED_BACKLIGHT_OFF_DELAY_TIME 600
#endif
>>>>>>> c8b2b237b4ef09765e48cbb5c1fdb0afd164289f:keyboards/keychron/common/wireless/wireless_config.h
