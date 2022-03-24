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

#include <sensor/gps_nmea.h>

#ifdef CONFIG_DEBUG_UORB
static void print_gps_nmea_message(const struct orb_metadata* meta, const void* buffer)
{
    const struct gps_nmea* message = buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) nmea: %s",
        meta->o_name, message->timestamp, now - message->timestamp, message->nmea);
}
#endif
ORB_DEFINE(gps_nmea, struct gps_nmea, print_gps_nmea_message);
