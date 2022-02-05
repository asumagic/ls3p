#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::core
{

struct Command
{
    std::string title;
    std::string command;
    std::vector<nlohmann::json> arguments;

    LS3P_ARCHIVE(Command)
    {
        archive
            ("title", title)
            ("command", command)
            ("arguments", arguments);
    }
};

}