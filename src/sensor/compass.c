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

#include <sensor/compass.h>

#ifdef CONFIG_DEBUG_UORB
static void print_compass_message(const struct orb_metadata* meta, const void* buffer)
{
    const struct sensor_compass* message = buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago)"
                 "state: %d, direction: %.01f, gravity_direction: %.01f,"
                 "gravity_magnitude: %.1f,"
                 "x: %.02f,y: %.02f,z: %.02f",
        meta->o_name, message->timestamp, now - message->timestamp,
        message->state, message->direction, message->gravity_direction,
        message->gravity_magnitude,
        message->x, message->y, message->z);
}
#endif
ORB_DEFINE(sensor_compass, struct sensor_compass, print_compass_message);
