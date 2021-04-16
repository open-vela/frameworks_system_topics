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

#ifndef __TOPICS_INCLUDE_MEDIA_PCM16_H
#define __TOPICS_INCLUDE_MEDIA_PCM16_H

#include <uORB/uORB.h>

begin_packed_struct struct media_pcm16_1ch {
    uint16_t ch[1];
} end_packed_struct;

begin_packed_struct struct media_pcm16_2ch {
    uint16_t ch[2];
} end_packed_struct;

begin_packed_struct struct media_pcm16_3ch {
    uint16_t ch[3];
} end_packed_struct;

begin_packed_struct struct media_pcm16_4ch {
    uint16_t ch[4];
} end_packed_struct;

begin_packed_struct struct media_pcm16_5ch {
    uint16_t ch[5];
} end_packed_struct;

begin_packed_struct struct media_pcm16_6ch {
    uint16_t ch[6];
} end_packed_struct;

begin_packed_struct struct media_pcm16_7ch {
    uint16_t ch[7];
} end_packed_struct;

begin_packed_struct struct media_pcm16_8ch {
    uint16_t ch[8];
} end_packed_struct;

/* register this as object request broker structure */

ORB_DECLARE(media_pcm16_1ch);
ORB_DECLARE(media_pcm16_2ch);
ORB_DECLARE(media_pcm16_3ch);
ORB_DECLARE(media_pcm16_4ch);
ORB_DECLARE(media_pcm16_5ch);
ORB_DECLARE(media_pcm16_6ch);
ORB_DECLARE(media_pcm16_7ch);
ORB_DECLARE(media_pcm16_8ch);

#endif /* __TOPICS_INCLUDE_MEDIA_PCM16_H */
