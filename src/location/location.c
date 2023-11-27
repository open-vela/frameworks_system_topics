/*
 * Copyright (C) 2023 Xiaomi Corporation
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

#include <location/location.h>

#ifdef CONFIG_DEBUG_UORB
static const char location_format[] = "timestamp:%" PRIu64 ",latitude:%hf,longitude:%hf,"
                                      "altitude:%hf,altitude_ellipsoid:%hf,eph:%hf,"
                                      "epv:%hf,hdop:%hf,pdop:%hf,vdop:%hf,ground_speed:%hf,"
                                      "course:%hf,satellites_used:%" PRIu32 "";
#endif

ORB_DEFINE(location_network, struct sensor_gps, location_format);
ORB_DEFINE(location_fused, struct sensor_gps, location_format);
ORB_DEFINE(lbs_wifi, struct lbs_wifi, NULL);
