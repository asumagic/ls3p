#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::workspace
{

struct WorkspaceFoldersServerCapabilities
{
    std::optional<bool> supported;

    std::optional<std::variant<std::string, bool>> change_notifications;

    LS3P_ARCHIVE(WorkspaceFoldersServerCapabilities)
    {
        archive
            ("supported", supported)
            ("changeNotifications", change_notifications);
    }
};

struct WorkspaceFolder
{
    DocumentUri uri;
    std::string name;

    LS3P_ARCHIVE(WorkspaceFolder)
    {
        archive
            ("uri", uri)
            ("name", name);
    }
};

}