/*
 * Copyright (C) 2020 Xiaomi Corporation
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

#ifndef __TOPICS_INCLUDE_SENSOR_PM1P0_H
#define __TOPICS_INCLUDE_SENSOR_PM1P0_H

#include <uORB/uORB.h>

struct sensor_pm1p0 {
    uint64_t timestamp; /* Units is microseconds */
    float pm1p0; /* pm1p0 measurement in SI units ug/m^3 */
};

/* register this as object request broker structure */

ORB_DECLARE(sensor_pm1p0);

#endif