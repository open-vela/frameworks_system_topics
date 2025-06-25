/**************************************************************
 *
 * Copyright(c) 2025, Beijing Xiaomi Mobile Software Co., Ltd.
 * All Rights Reserved.
 *
 *************************************************************/

#pragma once

#include <uORB/uORB.h>

struct algo_wrist_attitude {
    uint64_t  timestamp; // 时间戳
    float     roll;      // 手腕转动角度
    float     pitch;     // 手腕上下角度
};

ORB_DECLARE(algo_wrist_attitude);