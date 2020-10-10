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

#include <uORB/common/log.h>
#include <sensor/gps.h>

#ifdef CONFIG_DEBUG_FEATURES
static void print_sensor_gps_message(const void* buffer)
{
    const struct sensor_gps* message = (const struct sensor_gps*)buffer;

    uorbinfo_raw("sensor_gps:\tyear: %d month: %d day: %d hour: %d min: %d sec: %d msec: %d",
                 message->year, message->month, message->day, message->hour, message->min, message->sec, message->msec);

    uorbinfo_raw("sensor_gps:\tyaw: %.4f height: %.4f speed: %.4f latitude: %.4f longitude: %.4f",
                 message->yaw, message->height, message->speed, message->latitude, message->longitude);
}

ORB_DEFINE(sensor_gps, struct sensor_gps, print_sensor_gps_message);
#else
ORB_DEFINE(sensor_gps, struct sensor_gps, NULL);
#endif
