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

#ifndef __TOPICS_INCLUDE_SENSOR_FACTEST_GNSS_H
#define __TOPICS_INCLUDE_SENSOR_FACTEST_GNSS_H

#include <uORB/uORB.h>

begin_packed_struct struct sensor_factest_gnss_parameter {
    int cn0; /* Signal Intensity */
    float ttff; /* Positioning Time */
    float clk_drift; /* CLK Drift */
    uint32_t info[16]; /* num|gnssId|svId|cnr */
} end_packed_struct;

/* register this as object request broker structure */

ORB_DECLARE(sensor_factest_gnss_parameter);

#endif
