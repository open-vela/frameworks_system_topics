/**************************************************************
 *
 * Copyright(c) 2025, Beijing Xiaomi Mobile Software Co., Ltd.
 * All Rights Reserved.
 *
 *************************************************************/

#include <topics/algo_wrist_attitude.h>

#ifdef CONFIG_DEBUG_UORB
static const char attitude_format[] =
  "time %lld, roll %f, pitch %f\n";
#endif

ORB_DEFINE(algo_wrist_attitude, struct algo_wrist_attitude, attitude_format);