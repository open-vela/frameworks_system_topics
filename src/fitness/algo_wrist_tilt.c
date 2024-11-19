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

#include <topics/algo_wrist_tilt.h>

#ifdef CONFIG_DEBUG_UORB
static const char algo_wrist_tilt_format[] =
    "timestamp:%" PRIu64 ",event:%" PRIi32 "";
#endif

ORB_DEFINE(algo_wrist_tilt, struct algo_wrist_tilt, algo_wrist_tilt_format);
