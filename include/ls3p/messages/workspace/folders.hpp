#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages::workspace
{

struct WorkspaceFolder
{
    DocumentUri uri;
    std::string name;
};

}