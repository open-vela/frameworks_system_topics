/*
 * Copyright (C) 2020 Xiaomi Corporation
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

#include <uORB/common/log.h>
#include <media/pcm16.h>
#include <uORBTopics.h>

ORB_DEFINE(media_pcm16_1ch, struct media_pcm16_1ch, NULL, media_pcm16_1ch);
ORB_DEFINE(media_pcm16_2ch, struct media_pcm16_2ch, NULL, media_pcm16_2ch);
ORB_DEFINE(media_pcm16_3ch, struct media_pcm16_3ch, NULL, media_pcm16_3ch);
ORB_DEFINE(media_pcm16_4ch, struct media_pcm16_4ch, NULL, media_pcm16_4ch);
ORB_DEFINE(media_pcm16_5ch, struct media_pcm16_5ch, NULL, media_pcm16_5ch);
ORB_DEFINE(media_pcm16_6ch, struct media_pcm16_6ch, NULL, media_pcm16_6ch);
ORB_DEFINE(media_pcm16_7ch, struct media_pcm16_7ch, NULL, media_pcm16_7ch);
ORB_DEFINE(media_pcm16_8ch, struct media_pcm16_8ch, NULL, media_pcm16_8ch);
