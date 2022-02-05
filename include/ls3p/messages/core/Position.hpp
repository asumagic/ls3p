#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages::core
{

struct Position
{
    UInteger line;
    UInteger character;
};

inline void from_json(const nlohmann::json& j, Position& p)
{
    using nlohmann::json;

    parse(j, "line", p.line);
    parse(j, "character", p.character);
}

}