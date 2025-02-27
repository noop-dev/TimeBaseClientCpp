/*
 * Copyright 2021 EPAM Systems, Inc
 *
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
#pragma once

#include "modify_subscription_request.h"

namespace DxApiImpl {
    class ModifyEntitiesRequest : public ModifySubscriptionRequest {
    public:
        ModifyEntitiesRequest(TickDbImpl &db, int64_t id, int64_t time, SubscrChangeAction changeMode, const std::string entities[], size_t numEntities)
            : ModifySubscriptionRequest(db, "changeEntities", id, time, changeMode)
        {
            if (entities != NULL) {
                for (int i = 0; i < numEntities; ++i) {
                    add("identities", entities[i]);
                }
            }
        }
    };
}