#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::workspace
{

struct DidChangeWatchedFilesClientCapabilities
{
    std::optional<bool> dynamic_registration;

    LS3P_ARCHIVE(DidChangeWatchedFilesClientCapabilities)
    {
        archive
            ("dynamicRegistration", dynamic_registration);
    }
};

}