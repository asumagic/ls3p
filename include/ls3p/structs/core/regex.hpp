#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::core
{

struct RegularExpressionsClientCapabilities
{
    std::string engine;
    std::optional<std::string> version;
};

}