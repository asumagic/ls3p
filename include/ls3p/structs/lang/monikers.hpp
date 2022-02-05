#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::lang
{

struct MonikerClientCapabilities
{
    std::optional<bool> dynamic_registration;

    LS3P_ARCHIVE(MonikerClientCapabilities)
    {
        archive
            ("dynamicRegistration", dynamic_registration);
    }
};

// TODO: MonikerOptions
// TODO: MonikerRegistrationOptions
// TODO: MonikerParams
// TODO: UniquenessLevel
// TODO: MonikerKind
// TODO: Moniker

}