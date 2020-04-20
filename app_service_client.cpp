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

#include "sync/app_service_client.hpp"
#include "sync/sync_manager.hpp"
#include "sync/app_utils.hpp"

namespace realm {
namespace app {

void AppServiceClient::call_function(const std::string& name,
                                     const std::string& args_json,
                                     const util::Optional<std::string>& service_name,
                                     std::function<void (util::Optional<AppError>, util::Optional<std::string>)> completion_block) const
{
    auto handler = [completion_block](const Response& response) {
        
        if (auto error = check_for_errors(response)) {
            return completion_block(error, util::none);
        }

        completion_block(util::none, util::Optional<std::string>(response.body));
    };
    
    std::string route = util::format("%1/app/%2/functions/call", m_base_route, m_app_id);
    
    auto args = nlohmann::json::parse(args_json);
    args.push_back({ "name" , name });
    if (service_name) {
        args.push_back({ "service" , *service_name });
    }
    
    Request request {
        .method = HttpMethod::post,
        .url = route,
        .body = args.dump()
    };
    m_auth_request_client->do_authenticated_request(request,
                                                    SyncManager::shared().get_current_user(),
                                                    handler);
    
}

void AppServiceClient::call_function(const std::string& name,
                                const std::string& args_json,
                                std::function<void (util::Optional<AppError>, util::Optional<std::string>)> completion_block) const
{
    call_function(name, args_json, service_name, completion_block);
}

}
}
