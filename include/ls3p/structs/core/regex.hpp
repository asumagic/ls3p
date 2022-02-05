#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::core
{

struct RegularExpressionsClientCapabilities
{
    std::string engine;
    std::optional<std::string> version;

    LS3P_ARCHIVE(RegularExpressionsClientCapabilities)
    {
        archive
            ("engine", engine)
            ("version", version);
    }
};

}