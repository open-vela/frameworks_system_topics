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

#include <sensor/cap.h>
#include <uORB/common/log.h>
#include <uORBTopics.h>

#ifdef CONFIG_DEBUG_FEATURES
static void print_sensor_cap_message(const struct orb_metadata* meta, const void* buffer)
{
    const struct sensor_cap* message = (const struct sensor_cap*)buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) "
                 "status: %" PRIu32 " rawdata0: %" PRIu32 " "
                 "rawdata1: %" PRIu32 " rawdata2: %" PRIu32 " rawdata3: %" PRIu32 "",
                  meta->o_name, message->timestamp, now - message->timestamp,
                  message->status, message->rawdata[0], message->rawdata[1],
                  message->rawdata[2], message->rawdata[3]);
}

ORB_DEFINE(sensor_cap, struct sensor_cap, print_sensor_cap_message, sensor_cap);
#else
ORB_DEFINE(sensor_cap, struct sensor_cap, NULL, sensor_cap);
#endif
