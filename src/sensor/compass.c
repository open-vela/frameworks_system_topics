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

#include <sensor/compass.h>

#ifdef CONFIG_DEBUG_UORB
static const char sensor_compass_format[] = "timestamp:%" PRIu64 ",state:%hhu,cal_status:%hhu,"
                                            "direction:%hf,gravity_direction:%hf,"
                                            "gravity_magnitude:%hf,"
                                            "x:%hf,y:%hf,z:%hf";
#endif

ORB_DEFINE(sensor_compass, struct sensor_compass, sensor_compass_format);
