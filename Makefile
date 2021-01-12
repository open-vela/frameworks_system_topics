#
# Copyright (C) 2020 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include $(APPDIR)/Make.defs

src/uORBTopics.c: $(wildcard include/*/*.h)
	./topics.sh -c > src/uORBTopics.c
	./topics.sh -h > src/uORBTopics.h

context:: src/uORBTopics.c

CSRCS    += $(wildcard src/*/*.c) src/uORBTopics.c
CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/uORB}
CFLAGS   += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/frameworks/topics/src/}

clean::
	$(call DELFILE, src/uORBTopics.c)

include $(APPDIR)/Application.mk
