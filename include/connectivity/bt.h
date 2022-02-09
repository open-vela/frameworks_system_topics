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

#ifndef __TOPICS_INCLUDE_CONNECTIVITY_BT_H
#define __TOPICS_INCLUDE_CONNECTIVITY_BT_H

#include <uORB/uORB.h>

enum profile_connection_state {
    PROFILE_CONN_DISCONNECTED = 0,
    PROFILE_CONN_CONNECTING,
    PROFILE_CONN_CONNECTED,
    PROFILE_CONN_DISCONNECTING
};

enum hf_audio_state {
    HFP_AUDIO_DISCONNECTED = 0,
    HFP_AUDIO_CONNECTING,
    HFP_AUDIO_CONNECTED,
    HFP_AUDIO_CONNECTED_MSBC,
};

enum a2dp_audio_state {
    A2DP_AUDIO_NOT_READY = 0,
    A2DP_AUDIO_STOPPED,
    A2DP_AUDIO_STARTED,
};

struct bt_state {
    uint64_t timestamp; /* Units is microseconds */
    uint8_t addr[6]; /* Peer device address */
    int conn; /* Conn type, <0:unknown, 0:disconnected 1:connected */
    int rssi; /* The sensitivity(RSSI). */
};

struct a2dp_state {
    uint64_t timestamp; /* Units is microseconds */
    uint8_t addr[6]; /* Peer device address*/
    enum profile_connection_state conn_state;
    enum a2dp_audio_state audio_state;
};

struct hfp_state {
    uint64_t timestamp; /* Units is microseconds */
    uint8_t addr[6]; /* Peer device address*/
    enum profile_connection_state conn_state;
    enum hf_audio_state audio_state;
};

/* register this as object request broker structure */

ORB_DECLARE(bt_state);
ORB_DECLARE(a2dp_state);
ORB_DECLARE(hfp_state);

#endif
