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

#include <sensor/gnss.h>

#ifdef CONFIG_DEBUG_UORB
static void print_sensor_gnss_parameter_message(const struct orb_metadata* meta, const void* buffer)
{
    const struct sensor_gnss_parameter* message = buffer;

    uorbinfo_raw("cn0: %d", message->cn0);
    uorbinfo_raw("ttff: %f", message->ttff);
    uorbinfo_raw("clk_drift: %.2f", message->clk_drift);

    for (int i = 0; i < (sizeof(message->info) / sizeof(uint32_t)); i++) {
        uorbinfo_raw("info[%d]: 0x%08" PRIx32 "", i, message->info[i]);
    }
}
#endif
ORB_DEFINE(sensor_gnss_parameter, struct sensor_gnss_parameter, print_sensor_gnss_parameter_message);
