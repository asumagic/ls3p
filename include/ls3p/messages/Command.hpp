#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages
{

struct Command
{
    std::string title;
    std::string command;
    std::vector<nlohmann::json> arguments;
};

}