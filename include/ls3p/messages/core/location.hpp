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