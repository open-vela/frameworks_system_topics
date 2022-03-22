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

#include <sensor/ppgd.h>
#include <uORB/common/log.h>
#include <uORBTopics.h>

#ifdef CONFIG_DEBUG_SENSORS
static void print_sensor_ppgd_message(const struct orb_metadata* meta, const void* buffer)
{
    const struct sensor_ppgd* message = (const struct sensor_ppgd*)buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) "
                 "ppg1: %" PRIu32 " ppg2: %" PRIu32 " current: %" PRIu32 " "
                 "gain1: %" PRIu16 " gain2: %" PRIu16 "",
        meta->o_name, message->timestamp, now - message->timestamp, message->ppg[0],
        message->ppg[1], message->current, message->gain[0], message->gain[1]);
}

ORB_DEFINE(sensor_ppgd, struct sensor_ppgd, print_sensor_ppgd_message, sensor_ppgd);
#else
ORB_DEFINE(sensor_ppgd, struct sensor_ppgd, NULL, sensor_ppgd);
#endif
