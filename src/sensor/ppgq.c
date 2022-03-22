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

#include <sensor/ppgq.h>
#include <uORB/common/log.h>
#include <uORBTopics.h>

#ifdef CONFIG_DEBUG_SENSORS
static void print_sensor_ppgq_message(const struct orb_metadata* meta, const void* buffer)
{
    const struct sensor_ppgq* message = (const struct sensor_ppgq*)buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) "
                 "ppg1: %" PRIu32 " ppg2: %" PRIu32 " ppg3: %" PRIu32 " "
                 "ppg4: %" PRIu32 "current: %" PRIu32 " gain1: %" PRIu16 " "
                 "gain2: %" PRIu16 " gain3: %" PRIu16 " gain4: %" PRIu16 "",
        meta->o_name, message->timestamp, now - message->timestamp, message->ppg[0],
        message->ppg[1], message->ppg[2], message->ppg[3], message->current,
        message->gain[0], message->gain[1], message->gain[2], message->gain[3]);
}

ORB_DEFINE(sensor_ppgq, struct sensor_ppgq, print_sensor_ppgq_message, sensor_ppgq);
#else
ORB_DEFINE(sensor_ppgq, struct sensor_ppgq, NULL, sensor_ppgq);
#endif
