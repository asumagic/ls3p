#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::core
{

struct Position
{
    UInteger line;
    UInteger character;

    LS3P_ARCHIVE(Position)
    {
        archive
            ("line", line)
            ("character", character);
    }
};

struct Range
{
    Position start, end;

    LS3P_ARCHIVE(Range)
    {
        archive
            ("start", start)
            ("end", end);
    }
};

struct Location
{
    DocumentUri uri;
    Range range;

    LS3P_ARCHIVE(Location)
    {
        archive
            ("uri", uri)
            ("range", range);
    }
};

struct LocationLink
{
    std::optional<Range> origin_selection_range;
    DocumentUri target_uri;
    Range target_range;
    Range target_selection_range;

    LS3P_ARCHIVE(LocationLink)
    {
        archive
            ("originSelectionRange", origin_selection_range)
            ("targetUri", target_uri)
            ("targetRange", target_range)
            ("targetSelectionRange", target_selection_range);
    }
};

}