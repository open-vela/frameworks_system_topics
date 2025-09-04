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

struct algo_pedometer {
    uint64_t timestamp_us; // topic发布时间戳

    /**
     * _rt后缀的数据: 实时性更高, 但准确度较低
     * 不带后缀的数据: 准确度更高, 但实时性较低
     */

    // 总步数
    uint32_t count;
    uint32_t count_rt;

    // 步数增量
    uint16_t delta;
    uint16_t delta_rt;

    // 步频-步/分钟
    uint32_t step_frequency;
    uint32_t step_frequency_rt;
};

ORB_DECLARE(algo_pedometer);
