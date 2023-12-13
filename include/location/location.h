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
#define MCC_MAX_LENGTH 4
#define MNC_MAX_LENGTH 4
#define IMEI_MAX_LENGTH 16
#define SUBSCRIBER_ID_MAX_LENGTH 16
#define PHONE_NUMBER_MAX_LENGTH 16
#define CELL_INFO_MAX_LENGTH 3

/* No phone radio. */
#define PHONE_TYPE_NONE 0

/* Phone radio is GSM. */
#define PHONE_TYPE_GSM 1

/* Phone radio is CDMA. */
#define PHONE_TYPE_CDMA 2

/* Phone is via SIP. */
#define PHONE_TYPE_SIP 3

/* Network type is unknown */
#define NETWORK_TYPE_UNKNOWN 0

/* Current network is GPRS */
#define NETWORK_TYPE_GPRS 1

/* Current network is EDGE */
#define NETWORK_TYPE_EDGE 2

/* Current network is UMTS */
#define NETWORK_TYPE_UMTS 3

/* Current network is CDMA: Either IS95A or IS95B */
#define NETWORK_TYPE_CDMA 4

/* Current network is EVDO revision 0 */
#define NETWORK_TYPE_EVDO_0 5

/* Current network is EVDO revision A */
#define NETWORK_TYPE_EVDO_A 6

/* Current network is 1xRTT */
#define NETWORK_TYPE_1XRTT 7

/* Current network is HSDPA */
#define NETWORK_TYPE_HSDPA 8

/* Current network is HSUPA */
#define NETWORK_TYPE_HSUPA 9

/* Current network is HSPA */
#define NETWORK_TYPE_HSPA 10

/* Current network is iDen */
#define NETWORK_TYPE_IDEN 11

/* Current network is EVDO revision B */
#define NETWORK_TYPE_EVDO_B 12

/* Current network is LTE */
#define NETWORK_TYPE_LTE 13

/* Current network is eHRPD */
#define NETWORK_TYPE_EHRPD 14

/* Current network is HSPA+ */
#define NETWORK_TYPE_HSPAP 15

/* Current network is GSM */
#define NETWORK_TYPE_GSM 16

/* Current network is TD_SCDMA */
#define NETWORK_TYPE_TD_SCDMA 17

/* Current network is IWLAN */
#define NETWORK_TYPE_IWLAN 18

/* Current network is LTE CA (carrier aggregation) */
#define NETWORK_TYPE_LTE_CA 19

/* Current network is NR (New Radio) 5G. This will only be returned for 5G SA. For 5G NSA, the network type will be NETWORK_TYPE_LTE. */
#define NETWORK_TYPE_NR 20

struct provider_network_wifiinfo {
    char bssid[BSSID_MAX_LENGTH];
    char ssid[SSID_MAX_LENGTH];
    uint32_t ip_address;
    uint32_t rssi;
    int8_t is_connected;
};

struct provider_network_cellinfo {
    char mcc_string[MCC_MAX_LENGTH];
    char mnc_string[MNC_MAX_LENGTH];
    int32_t cid;
    int32_t lac;
    int8_t dbm;
    uint8_t is_registered;
};

struct lbs_wifi {
    char mac_address[MAC_MAX_LENGTH];
    uint32_t wifiinfo_count;
    struct provider_network_wifiinfo wifiinfo[WIFI_INFO_MAX_LENGTH];
};

struct lbs_telephony {
    uint32_t phone_type;
    uint32_t data_network_type;
    char imei[IMEI_MAX_LENGTH];
    char subscriber_id[SUBSCRIBER_ID_MAX_LENGTH];
    char phone_number[PHONE_NUMBER_MAX_LENGTH];
    uint32_t cellinfo_count;
    struct provider_network_cellinfo cellinfo[CELL_INFO_MAX_LENGTH];
};

ORB_DECLARE(location_network);
ORB_DECLARE(location_fused);
ORB_DECLARE(lbs_wifi);
ORB_DECLARE(lbs_telephony);

#endif
