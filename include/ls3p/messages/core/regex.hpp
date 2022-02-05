#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages::core
{

struct RegularExpressionsClientCapabilities
{
    std::string engine;
    std::optional<std::string> version;
};

}