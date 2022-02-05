#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::workspace
{

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