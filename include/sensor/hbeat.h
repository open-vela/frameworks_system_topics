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

#ifndef __TOPICS_INCLUDE_SENSOR_HBEAT_H
#define __TOPICS_INCLUDE_SENSOR_HBEAT_H

#include <uORB/uORB.h>

struct sensor_hbeat {
    uint64_t timestamp; /* Units is microseconds */
    float beat; /* Heart Beat measurement in units times/minutes */
};

/* register this as object request broker structure */

ORB_DECLARE(sensor_hbeat);

#endif
