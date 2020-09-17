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
#include <sensor/baro.h>

#ifdef CONFIG_DEBUG_FEATURES
static void print_sensor_baro_message(const void* buffer)
{
    const struct sensor_baro* message = (const struct sensor_baro*)buffer;

    uorbinfo_raw(" sensor_baro\n");

    const orb_abstime now = orb_absolute_time();

    if (message->timestamp != 0) {
        uorbinfo_raw("\ttimestamp: %" PRIu64 "  (%.6f seconds ago)\n", message->timestamp, (now - message->timestamp) / 1e6);
    } else {
        uorbinfo_raw("\n");
    }

    uorbinfo_raw("\tpressure: %.4f\n", message->pressure);
    uorbinfo_raw("\ttemperature: %.4f\n", message->temperature);
}

ORB_DEFINE(sensor_baro, struct sensor_baro, print_sensor_baro_message);
#else
ORB_DEFINE(sensor_baro, struct sensor_baro, NULL);
#endif
