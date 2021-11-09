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

#include <sensor/gesture.h>
#include <uORB/common/log.h>
#include <uORBTopics.h>

#ifdef CONFIG_DEBUG_FEATURES
static void print_sensor_wake_gesture_message(const struct orb_metadata* meta, const void* buffer)
{
    const struct sensor_wake_gesture* message = (const struct sensor_wake_gesture*)buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) event: %" PRIu32 "\n",
        meta->o_name, message->timestamp, now - message->timestamp, message->event);
}

ORB_DEFINE(sensor_wake_gesture, struct sensor_wake_gesture, print_sensor_wake_gesture_message, sensor_wake_gesture);
ORB_DEFINE(sensor_wake_gesture_uncal, struct sensor_wake_gesture, print_sensor_wake_gesture_message, sensor_wake_gesture_uncal);
#else
ORB_DEFINE(sensor_wake_gesture, struct sensor_wake_gesture, NULL, sensor_wake_gesture);
ORB_DEFINE(sensor_wake_gesture_uncal, struct sensor_wake_gesture, NULL, sensor_wake_gesture_uncal);
#endif
