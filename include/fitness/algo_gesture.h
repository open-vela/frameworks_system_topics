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

#pragma once

#include <uORB/uORB.h>

#define DATA_LEN (4)

/***************************************************响指
 ******************************************************/
typedef enum {
    SNAP_GESTURE_REST = 0, // 静止
    SNAP_GESTURE_FINGER = 1, // 手势动作为打响指
    SNAP_GESTURE_NUM_TYPES = 2, // 双次打响指(算法不会出这个值)
    SNAP_GESTURE_OTHER = 9, // 没有完成指定手势
} snapResult;

typedef enum {
    SNAP_CTRLSTATUS_WAITING = 0,
    SNAP_CTRLSTATUS_READY = 1,
    SNAP_STABLE = 3, // 请保持水平
    SNAP_QUICK = 4, // 请快速握拳
    SNAP_FIST_TIGHT = 5, // 请握紧一点
    SNAP_WEAR_TIGHT = 6, // 请佩戴紧一点
} snapStatus;

/***************************************************握拳
 ******************************************************/
typedef enum {
    mi_fist_status_waiting = 0,
    mi_fist_status_ready = 1,
    mi_fist_status_error = 2,
    mi_fist_status_stable = 3, // 请保持水平
    mi_fist_status_quick = 4, // 请快速握拳
    mi_fist_status_fist_tight = 5, // 请握紧一点
    mi_fist_status_wear_tight = 6, // 请佩戴紧一点
} fistStatus;

typedef enum {
    mi_fist_gesture_rest = 0, // 静止
    mi_fist_gesture_singlefist = 1, // 手势动作为单次握拳
    mi_fist_gesture_doublefist = 2, // 手势动作为连续两次握拳
    mi_fist_gesture_singlesnapfinger = 4, // 手势动作为单次搓手指
    mi_fist_gesture_doublesnapfinger = 5, // 手势动作为连续两次搓手指
    mi_fist_gesture_other = 9, // 没有完成指定手势，不做任何操作
} fistResult;

/************************************************快捷手势
 ******************************************************/
// 快捷手势无status
typedef enum {
    TYPE_GUESTURE_FINGER = 0, // 识别为响指
    TYPE_GUESTURE_SHAKE = 1, // 摇一摇
    TYPE_GUESTURE_WRIST = 2, // 翻腕
} quickResult;

/***********************************************pison手势
 ******************************************************/
typedef enum {
    PISON_OPEN_PLAM = 0, // 张开手掌
    PISON_POINT_FINGER = 1, // 伸出食指
    PISON_MONEY_FINGER = 2, // 搓手指
    PISON_PINCH_FINGER = 3, // 捏合
    PISON_TAP_FINGER = 4, // 捏合松开
    PISON_DOUBLE_TAP_FINGER = 5, // 捏2下
    PISON_DOUBLE_MONEY_FINGER = 6, // 搓2下
} HandResult;

typedef enum {
    PISON_DRAG_STOP = 0, // 无拖拽
    PISON_DRAG_MOVE = 1, // 有拖拽
} HandStatus;

/***********************************************MiEng手势
 ******************************************************/
typedef enum {
    MI_ENG_GESTURE_STATUS_DRAG_STOP = 0, // 无拖拽
    MI_ENG_GESTURE_STATUS_DRAG_RUN = 1, // 有拖拽
} MiEngStatus;

typedef enum {
    MI_ENG_GESTURE_FIST = 0, // 握拳
    MI_ENG_GESTURE_PINCH = 1, // 拖拽
    MI_ENG_GESTURE_PINCHTWICE = 2, // 捏2下
    MI_ENG_GESTURE_MONEY = 3, // 搓2下
    MI_ENG_GESTURE_SHAKE = 4, // 晃一晃
    MI_ENG_GESTURE_WRIST = 5, // 翻腕
    MI_ENG_GESTURE_FINGERSNAP = 6, // 打响指
    MI_ENG_GESTURE_OTHER = 7, // 其他
    MI_ENG_GESTURE_REST = 8, // 休息状态
} MiEngResult;

/*************************************subscribe instance
 * 自研手势不能同时订阅
 ******************************************************/
enum {
    GUESTURE_SNAP_INSTANCE = 0, // 响指
    GUESTURE_FIST_INSTANCE = 1, // 握拳
    GUESTURE_QUICK_INSTANCE = 2, // 快捷手势(摇一摇,翻腕)
    GUESTURE_MI_INSTANCE = 3, // 自研手势(晃一晃，翻手腕，打响指)
    GUESTURE_MI_INSTANCE1 = 4, // 自研手势1(捏2次，搓2次)
    GUESTURE_MI_INSTANCE2 = 5, // 自研手势2(握拳，拖拽，捏2次)
    GUESTURE_PISON_DRAG_INSTANCE = 6, // pison手势(拖拽)
};

/*******************************************手势发布topic
 ******************************************************/
struct algo_gesture {
    uint64_t timeStamp_us; // 发布时间戳
    uint8_t status; // 设备是否处于手势交互控制状态
    uint8_t result; // 手势动作识别结果
    float data[DATA_LEN]; // 设备在X-Y平面映射中data[0]-X,data[1]-Y轴向的相对位移,data[2]-X,data[3]-Y轴的绝对角度
};

ORB_DECLARE(algo_gesture);
