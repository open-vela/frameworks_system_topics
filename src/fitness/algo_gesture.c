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

#include <topics/algo_gesture.h>

#ifdef CONFIG_DEBUG_UORB
static const char algo_gesture_format[] = "timestamp_us:%" PRIu64 ""
                                          "status:%hhu,result:%hhu,data[0]:%hf,"
                                          "data[1]:%hf,data[2]:%hf,data[3]:%hf";
#endif

ORB_DEFINE(algo_gesture, struct algo_gesture, algo_gesture_format);
