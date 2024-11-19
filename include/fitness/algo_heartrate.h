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

#pragma once

#include <uORB/uORB.h>

struct algo_heartrate {
  uint64_t timestamp_us; // topic发布时间戳
  uint32_t bpm;          // 心率值bpm
  int heartrate_section;
  int heartrate_section_max;
  int heartrate_section_min;
};

ORB_DECLARE(algo_heartrate);
