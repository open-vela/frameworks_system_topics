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

#include <system/state.h>
#include <uORB/common/log.h>
#include <uORBTopics.h>

ORB_DEFINE(wifi_state, struct wireless_state, NULL, wifi_state);
ORB_DEFINE(bt_state, struct wireless_state, NULL, bt_state);
ORB_DEFINE(wear_state, struct wear_state, NULL, wear_state);
ORB_DEFINE(sleep_state, struct sleep_state, NULL, sleep_state);
ORB_DEFINE(battery_state, struct battery_state, NULL, battery_state);
