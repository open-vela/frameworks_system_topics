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
#include <sensor/pm10.h>
#include <uORBTopics.h>

#ifdef CONFIG_DEBUG_FEATURES
static void print_sensor_pm10_message(const struct orb_metadata *meta, const void* buffer)
{
    const struct sensor_pm10* message = (const struct sensor_pm10*)buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) pm10: %.2f",
                  meta->o_name, message->timestamp, now - message->timestamp, message->pm10);
}

ORB_DEFINE(sensor_pm10, struct sensor_pm10, print_sensor_pm10_message, sensor_pm10);
#else
ORB_DEFINE(sensor_pm10, struct sensor_pm10, NULL, sensor_pm10);
#endif
