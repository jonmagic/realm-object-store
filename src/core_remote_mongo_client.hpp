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

#ifndef CORE_REMOTE_MONGO_CLIENT_HPP
#define CORE_REMOTE_MONGO_CLIENT_HPP

#include <string>
#include <map>
#include <realm/util/optional.hpp>
#include <core_stitch_service_client.hpp>

namespace realm {
namespace app {

class CoreRemoteMongoDatabase;

/// A client responsible for communication with the Stitch API
class CoreRemoteMongoClient {
public:

    CoreRemoteMongoClient(CoreStitchServiceClient service) : m_service(service) { }
    
    /// Gets a `CoreRemoteMongoDatabase` instance for the given database name.
    /// @param name the name of the database to retrieve
    CoreRemoteMongoDatabase operator[](std::string name);
  
    /// Gets a `CoreRemoteMongoDatabase` instance for the given database name.
    /// @param name the name of the database to retrieve
    CoreRemoteMongoDatabase db(std::string name);
    
private:
    CoreStitchServiceClient m_service;
};

} // namespace app
} // namespace realm

#endif /* core_remote_mongo_client_hpp */
