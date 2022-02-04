#pragma once

#include <ls3p/messages/Range.hpp>
#include <ls3p/messages/common.hpp>

namespace ls3p::messages
{

struct LocationLink
{
    std::optional<Range> origin_selection_range;
    DocumentUri target_uri;
    Range target_range;
    Range target_selection_range;
};

inline void from_json(const nlohmann::json& j, LocationLink& p)
{
    using nlohmann::json;

    parse(j, "originSelectionRange", p.origin_selection_range);
    parse(j, "targetUri", p.target_uri);
    parse(j, "targetRange", p.target_range);
    parse(j, "targetSelectionRange", p.target_selection_range);
}

}