#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/caps/ClientCapabilities.hpp>

namespace ls3p::messages
{

struct InitializeParams
{
    public:
    std::optional<int> process_id;

    struct ClientInfo
    {
        std::string name;
        std::optional<std::string> version;
    };

    std::optional<ClientInfo> client_info;

    std::optional<std::string> locale;

    nlohmann::json initialization_options;

    ClientCapabilities capabilities;

    // TODO: trace

    std::vector<WorkspaceFolder> workspace_folders;
};

}