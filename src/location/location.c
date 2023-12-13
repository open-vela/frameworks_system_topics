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
static void print_location_message(FAR const struct orb_metadata* meta,
    FAR const void* buffer)
{
    FAR const struct sensor_gps* message = buffer;
    const orb_abstime now = orb_absolute_time();

    uorbinfo_raw("%s:\ttimestamp: %" PRIu64 " (%" PRIu64 " us ago) "
                 "time_utc: %" PRIu64 " latitude: %.4f longitude: %.4f",
        meta->o_name, message->timestamp, now - message->timestamp,
        message->time_utc, message->latitude, message->longitude);

    uorbinfo_raw("%s:\taltitude: %.4f altitude_ellipsoid: %.4f "
                 "ground_speed: %.4f course: %.4f",
        meta->o_name, message->altitude, message->altitude_ellipsoid,
        message->ground_speed, message->course);

    uorbinfo_raw("%s:\teph: %.4f epv: %.4f hdop: %.4f vdop: %.4f",
        meta->o_name, message->eph, message->epv,
        message->hdop, message->vdop);
}

static void print_lbs_wifi_message(FAR const struct orb_metadata* meta,
    FAR const void* buffer)
{
    int i;
    FAR const struct lbs_wifi* message = buffer;

    uorbinfo_raw("%s:\tmac_address: %s", meta->o_name, message->mac_address);

    for (i = 0; i < message->wifiinfo_count; i++) {
        uorbinfo_raw("wifiinfo[%d]:\tbssid: %s ssid: %s ip_address: %" PRIu32 " "
                     "rssi: %" PRIu32 " is_connected: %s",
            i,
            message->wifiinfo[i].bssid,
            message->wifiinfo[i].ssid,
            message->wifiinfo[i].ip_address,
            message->wifiinfo[i].rssi,
            message->wifiinfo[i].is_connected ? "true" : "false");
    }
}

static void print_lbs_telephony_message(FAR const struct orb_metadata* meta,
    FAR const void* buffer)
{
    int i;
    FAR const struct lbs_telephony* message = buffer;

    uorbinfo_raw("%s:\tphone_type: %" PRIu32 " data_network_type: %" PRIu32 " "
                 "imei: %s subscriber_id: %s phone_number: %s",
        meta->o_name, message->phone_type, message->data_network_type,
        message->imei, message->subscriber_id, message->phone_number);

    for (i = 0; i < message->cellinfo_count; i++) {
        uorbinfo_raw("cellinfo[%d]:\tmcc_string: %s mnc_string: %s "
                     "cid: %" PRId32 ", lac: %" PRId32 ", dbm: %" PRId8 ", is_registered: %s",
            i,
            message->cellinfo[i].mcc_string,
            message->cellinfo[i].mnc_string,
            message->cellinfo[i].cid,
            message->cellinfo[i].lac,
            message->cellinfo[i].dbm,
            message->cellinfo[i].is_registered ? "true" : "false");
    }
}
#endif

ORB_DEFINE(location_network, struct sensor_gps, print_location_message);
ORB_DEFINE(location_fused, struct sensor_gps, print_location_message);
ORB_DEFINE(lbs_wifi, struct lbs_wifi, print_lbs_wifi_message);
ORB_DEFINE(lbs_telephony, struct lbs_telephony, print_lbs_telephony_message);
