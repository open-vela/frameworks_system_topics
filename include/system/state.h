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
    int state; /* Battery charging staus, <1:start, 2:complete 3:stop */
    int level; /* Battery level in percent */
};

/* register this as object request broker structure */

ORB_DECLARE(wifi_state);
ORB_DECLARE(bt_state);
ORB_DECLARE(wear_state);
ORB_DECLARE(sleep_state);
ORB_DECLARE(battery_state);

#endif
