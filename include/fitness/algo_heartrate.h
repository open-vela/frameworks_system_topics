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

#define HR_INSTANCE_MANUAL 0 // 手动测量
#define HR_INSTANCE_LAST 1 // 最近一次测量
#define HR_INSTANCE_UNCONSCIOUS 2 // 后台心率测量
#define HR_INSTANCE_SPORT 3 // 运动心率
#define HR_INSTANCE_MONITOR 4 // 异常心率监测
#define HR_INSTANCE_RECOVER 5 // 恢复心率
#define HR_INSTANCE_MAX_CNT 6 // 心率topic实例数量

struct algo_heartrate {
    uint64_t timestamp_us; // topic发布时间戳
    uint32_t bpm; // 心率值bpm
    int heartrate_section;
    int heartrate_section_max;
    int heartrate_section_min;
};

ORB_DECLARE(algo_heartrate);
