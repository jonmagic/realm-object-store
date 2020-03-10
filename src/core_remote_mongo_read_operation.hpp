////////////////////////////////////////////////////////////////////////////
//
// Copyright 2020 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or utilied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#ifndef CORE_REMOTE_MONGO_READ_OPERATION_HPP
#define CORE_REMOTE_MONGO_READ_OPERATION_HPP

#include "core_remote_mongo_client.hpp"

namespace realm {
namespace mongodb {

template<typename T>
class CoreRemoteMongoReadOperation {
    
public:
    CoreRemoteMongoReadOperation(std::string command,
                                 nlohmann::json args,
                                 CoreStitchServiceClient service) :
    m_command(command),
    m_args(args),
    m_service(service) { }
private:
    std::string m_command;
    nlohmann::json m_args;
    CoreStitchServiceClient m_service;
};

} // namespace mongodb
} // namespace realm

#endif /* core_remote_mongo_read_operation */
