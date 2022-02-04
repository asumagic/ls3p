#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages
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