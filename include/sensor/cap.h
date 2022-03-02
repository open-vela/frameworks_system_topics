/*
 * Copyright (C) 2022 Xiaomi Corporation
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

#ifndef __TOPICS_INCLUDE_SENSOR_CAP_H
#define __TOPICS_INCLUDE_SENSOR_CAP_H

#include <uORB/uORB.h>

struct sensor_cap {
    uint64_t timestamp; /* Unit is microseconds */
    int32_t status; /* Detection status */
    int32_t rawdata[4]; /* in SI units pF */
};

/* register this as object request broker structure */

ORB_DECLARE(sensor_cap);

#endif
