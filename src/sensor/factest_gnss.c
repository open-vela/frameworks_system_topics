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

#include <sensor/factest_gnss.h>

#ifdef CONFIG_DEBUG_UORB
static const char sensor_factest_gnss_format[] = "cn0:%d,ttff:%hf,clk_drift:%hf,info[0]:0x%08" PRIx32 ","
                                                 "info[1]:0x%08" PRIx32 ",info[2]:0x%08" PRIx32 ","
                                                 "info[3]:0x%08" PRIx32 ",info[4]:0x%08" PRIx32 ","
                                                 "info[5]:0x%08" PRIx32 ",info[6]:0x%08" PRIx32 ","
                                                 "info[7]:0x%08" PRIx32 ",info[8]:0x%08" PRIx32 ","
                                                 "info[9]:0x%08" PRIx32 ",info[10]:0x%08" PRIx32 ","
                                                 "info[11]:0x%08" PRIx32 ",info[12]:0x%08" PRIx32 ","
                                                 "info[13]:0x%08" PRIx32 ",info[14]:0x%08" PRIx32 ","
                                                 "info[15]:0x%08" PRIx32 "";
#endif

ORB_DEFINE(sensor_factest_gnss_parameter,
    struct sensor_factest_gnss_parameter, sensor_factest_gnss_format);
