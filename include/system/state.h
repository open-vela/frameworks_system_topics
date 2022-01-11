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

#ifndef __TOPICS_INCLUDE_SYSTEM_STATE_H
#define __TOPICS_INCLUDE_SYSTEM_STATE_H

#include <uORB/uORB.h>
#include <sys/socket.h>

enum network_state_e {
    NETWORK_NONE = 0,
    NETWORK_WIFI,
    NETWORK_BT,
    NETWORK_OTHER,
};

typedef enum network_state_e network_state_t;

struct wireless_state {
    uint64_t timestamp; /* Units is microseconds */
    int conn; /* Conn type, <0:unknown, 0:disconnected 1:connected */
    int rssi; /* The sensitivity(RSSI). */
};

struct wear_state {
    uint64_t timestamp; /* Units is microseconds */
    int wear; /* Wear staus, <1:wore, 2:not wore */
};

struct sleep_state {
    uint64_t timestamp; /* Units is microseconds */
    int sleep; /* Sleep staus, <1:slept, 2:not slept */
};

struct battery_state {
    uint64_t timestamp; /* Units is microseconds */
    int state; /* Battery charging staus, <1:charging, 2:not charging */
    int level; /* Battery level in percent */
    int temp;  /* Battery temp */
};

struct network_state {
    uint64_t timestamp;   /* Units is microseconds */
    network_state_t type; /* Network Type. wifi, none, bluetooth, others. */
};

struct network_pubip {
    uint64_t timestamp; /* Units is microseconds */
    struct sockaddr_storage addr; /* Local public network ip. */
};

struct active_state {
    uint64_t timestamp; /* Units is microseconds */
    int active; /* App active status. <1:has activity, 2:no activity */
};

/* register this as object request broker structure */

ORB_DECLARE(wifi_state);
ORB_DECLARE(bt_state);
ORB_DECLARE(wear_state);
ORB_DECLARE(sleep_state);
ORB_DECLARE(battery_state);
ORB_DECLARE(network_state);
ORB_DECLARE(network_pubip);
ORB_DECLARE(active_state);

#endif
