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

#ifndef __APPS_SYSTEM_UORB_LOCATION_LOCATION_H
#define __APPS_SYSTEM_UORB_LOCATION_LOCATION_H

#include <nuttx/sensors/sensor.h>
#include <uORB/uORB.h>

#define BSSID_MAX_LENGTH 18
#define SSID_MAX_LENGTH 36
#define MAC_MAX_LENGTH 18
#define WIFI_INFO_MAX_LENGTH 30

struct provider_network_wifiinfo {
    char bssid[BSSID_MAX_LENGTH];
    char ssid[SSID_MAX_LENGTH];
    uint32_t ip_address;
    uint32_t rssi;
    int8_t is_connected;
};

struct lbs_wifi {
    char mac_address[MAC_MAX_LENGTH];
    uint32_t wifiinfo_count;
    struct provider_network_wifiinfo wifiinfo[WIFI_INFO_MAX_LENGTH];
};

ORB_DECLARE(location_network);
ORB_DECLARE(location_fused);
ORB_DECLARE(lbs_wifi);

#endif
