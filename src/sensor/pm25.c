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
#include <sensor/pm25.h>

#ifdef CONFIG_DEBUG_FEATURES
static void print_sensor_pm25_message(const void* buffer)
{
    const struct sensor_pm25* message = (const struct sensor_pm25*)buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("sensor_pm25:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) pm25: %.2f",
                  message->timestamp, now - message->timestamp, message->pm25);
}

ORB_DEFINE(sensor_pm25, struct sensor_pm25, print_sensor_pm25_message);
#else
ORB_DEFINE(sensor_pm25, struct sensor_pm25, NULL);
#endif
