#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/core/Range.hpp>

namespace ls3p::messages::core
{

struct Location
{
    DocumentUri uri;
    Range range;
};

inline void from_json(const nlohmann::json& j, Location& p)
{
    using nlohmann::json;

    parse(j, "uri", p.uri);
    parse(j, "range", p.range);
}

}