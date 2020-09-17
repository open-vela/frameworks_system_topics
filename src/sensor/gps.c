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

    uorbinfo_raw(" sensor_gps\n");
    uorbinfo_raw("\tyear: %d\n", message->year);
    uorbinfo_raw("\tmonth: %d\n", message->month);
    uorbinfo_raw("\tday: %d\n", message->day);
    uorbinfo_raw("\thour: %d\n", message->hour);
    uorbinfo_raw("\tmin: %d\n", message->min);
    uorbinfo_raw("\tsec: %d\n", message->sec);
    uorbinfo_raw("\tmsec: %d\n", message->msec);
    uorbinfo_raw("\tyaw: %.4f\n", message->yaw);
    uorbinfo_raw("\theight: %.4f\n", message->height);
    uorbinfo_raw("\tspeed: %.4f\n", message->speed);
    uorbinfo_raw("\tlatitude: %.8f\n", message->latitude);
    uorbinfo_raw("\tlongitude: %.8f\n", message->longitude);
}

ORB_DEFINE(sensor_gps, struct sensor_gps, print_sensor_gps_message);
#else
ORB_DEFINE(sensor_gps, struct sensor_gps, NULL);
#endif
