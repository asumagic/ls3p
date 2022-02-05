#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::workspace
{

struct DidChangeConfigurationClientCapabilities
{
    std::optional<bool> dynamic_registration;

    LS3P_ARCHIVE(DidChangeConfigurationClientCapabilities)
    {
        archive
            ("dynamicRegistration", dynamic_registration);
    }
};

struct DidChangeConfigurationParams
{
    // TODO: LSPAny
    nlohmann::json settings;

    LS3P_ARCHIVE(DidChangeConfigurationParams)
    {
        archive
            ("settings", settings);
    }
};

}