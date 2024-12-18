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

#include <connectivity/bt.h>

ORB_DEFINE(bt_state, struct bt_state, NULL);
ORB_DEFINE(bt_stack_state, struct bt_stack_state, NULL);
ORB_DEFINE(a2dp_state, struct a2dp_state, NULL);
ORB_DEFINE(hfp_state, struct hfp_state, NULL);
