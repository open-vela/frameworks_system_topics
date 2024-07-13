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

#ifndef __TOPICS_INCLUDE_MIAI_MSG_H
#define __TOPICS_INCLUDE_MIAI_MSG_H

#include <uORB/uORB.h>

typedef enum event_type_e {
    MSG_TYPE_NULL = 0,
    MSG_TYPE_WAKEUP = 1,
    MSG_TYPE_NIGHT = 2,
    MSG_TYPE_BT_WIFICONFIG = 3,
    MSG_TYPE_BIND_STATE = 4,
    MSG_TYPE_SCREEN_BRIGHTNESS_SET = 5,
    MSG_TYPE_AUTO_BRIGHTNESS_SET = 6,
    MSG_TYPE_SCREEN_DISPLAY_SET = 7,
    MSG_TYPE_CHILD_LOCK = 8,
} event_type_t;

struct miai_event {
    uint64_t timestamp;
    uint32_t type;
    uint32_t state;
};

/* register this as object request broker structure */

ORB_DECLARE(miai_event);
#endif
