#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/core/Position.hpp>

namespace ls3p::messages::core
{

struct Range
{
    Position start, end;
};

inline void from_json(const nlohmann::json& j, Range& p)
{
    using nlohmann::json;

    parse(j, "start", p.start);
    parse(j, "end", p.end);
}

}