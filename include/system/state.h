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

#include <sys/socket.h>
#include <uORB/uORB.h>

enum network_state_e {
    NETWORK_NONE = 0,
    NETWORK_WIFI,
    NETWORK_BT,
    NETWORK_OTHER,
};

typedef enum network_state_e network_state_t;

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
    int state; /* Battery charging staus, <1:charging, 0:not charging, 2:fault */
    int online; /* Whether the charging cable is connected */
    int level; /* Battery level in percent */
    int temp; /* Battery temp */
    int curr; /* Battery current */
    int voltage; /* Battery voltage */
};

struct charger_state {
    uint64_t timestamp; /* Units is microseconds */
    int state; /* 0: reset; 1: charger abnormal; 2...n: others abnormal */
    int voltage; /* Units is mV */
    int current; /* Units is mA */
    int protocol;
};

struct device_temperature {
    uint64_t timestamp; /* Units is microseconds */
    float internal; /* internal temp */
    float shell; /* shell temp */
    float skin; /* skin temp */
    uint16_t raw_internal; /* adc value */
    uint16_t raw_shell; /* adc value */
    uint16_t raw_skin; /* adc value */
    uint16_t efuse_ref; /* adc trigger efuse */
};

struct network_state {
    uint64_t timestamp; /* Units is microseconds */
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

struct screen_onoff {
    uint64_t timestamp;
    int onoff; /* The screen is on or off, 1: on, 0: off */
};

struct screen_brightness {
    uint64_t timestamp;
    int brightness; /* The brightness of screen, range 1 ~ 255 */
};

struct screen_touch {
    uint64_t timestamp;
    int state; /* The screen touch event */
};

struct vibrator_state {
    uint64_t timestamp; /* Units is microseconds */
    uint8_t start; /* The vibrating status, 1: start, 0: stop */
};

typedef enum {
    MUTE_MODE_ON, /* media.mutemode enabled */
    MUTE_MODE_OFF, /* media.mutemode disabled */
    DND_MODE_ON, /* Do Not Disturb enabled */
    DND_MODE_OFF /* Do Not Disturb disabled */
} work_state_t;

struct work_mode {
    uint64_t timestamp;
    work_state_t mode_val;
};

struct gesture_type {
    uint64_t timestamp;
    int type; /* custom gesrure type */
};
/* register this as object request broker structure */

ORB_DECLARE(wear_state);
ORB_DECLARE(sleep_state);
ORB_DECLARE(battery_state);
ORB_DECLARE(charger_state);
ORB_DECLARE(device_temperature);
ORB_DECLARE(network_state);
ORB_DECLARE(network_pubip);
ORB_DECLARE(active_state);
ORB_DECLARE(screen_onoff);
ORB_DECLARE(screen_brightness);
ORB_DECLARE(screen_touch);
ORB_DECLARE(vibrator_state);
ORB_DECLARE(work_mode);
ORB_DECLARE(gesture_type);
#endif
