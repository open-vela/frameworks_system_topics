/*
 * Copyright (C) 2021 Xiaomi Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _TOPICS_INCLUDE_SENSOR_COMPASS_H_
#define _TOPICS_INCLUDE_SENSOR_COMPASS_H_

#include <uORB/uORB.h>

begin_packed_struct struct sensor_compass {
    uint64_t timestamp; /* Units is microseconds */
    uint8_t state; /* Calibration level, the Range is [0, 4]. */
    float direction; /* Compass direction， the unit is 1 degree. */
    float gravity_direction; /* Gravity direction， the unit is 1 degree. */
    float gravity_magnitude; /* Gravity magnitude, the range is 0 to 9.8 m/s². */
    float x; /* Mag calibrate data axis X in Gauss or micro Tesla (uT) */
    float y; /* Mag calibrate data axis Y in Gauss or micro Tesla (uT) */
    float z; /* Mag calibrate data axis Z in Gauss or micro Tesla (uT) */
} end_packed_struct;

/* register this as object request broker structure */

ORB_DECLARE(sensor_compass);

#endif
