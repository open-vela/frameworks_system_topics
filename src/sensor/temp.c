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
#include <sensor/temp.h>
#include <uORBTopics.h>

#ifdef CONFIG_DEBUG_FEATURES
static void print_sensor_temp_message(const struct orb_metadata *meta, const void* buffer)
{
    const struct sensor_temp* message = (const struct sensor_temp*)buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) temperature: %.2f",
                  meta->o_name, message->timestamp, now - message->timestamp, message->temperature);
}

ORB_DEFINE(sensor_temp, struct sensor_temp, print_sensor_temp_message, sensor_temp);
#else
ORB_DEFINE(sensor_temp, struct sensor_temp, NULL, sensor_temp);
#endif
