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

#ifndef __TOPICS_INCLUDE_SYSTEM_MESSAGE_H
#define __TOPICS_INCLUDE_SYSTEM_MESSAGE_H

#include <uORB/uORB.h>

#define MESSAGE_NAME_MAX  29
#define MESSAGE_ARGS_MAX  199

struct message_state {
    uint64_t timestamp;
    char name[MESSAGE_NAME_MAX + 1]; /* message name */
    char args[MESSAGE_ARGS_MAX + 1]; /* the arguments, should be in json format */
};

/* register this as object request broker structure */

ORB_DECLARE(message_state);

#endif /* __TOPICS_INCLUDE_SYSTEM_MESSAGE_H */
