#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/core/Position.hpp>

namespace ls3p::messages::core
{

namespace markup_kind
{

static constexpr std::string_view
    PLAIN_TEXT = "plaintext",
    MARKDOWN = "markdown";

}

/// \see markup_kind
using MarkupKind = std::string;

struct MarkupContent
{
    MarkupKind kind;

    std::string value;
};

struct MarkdownClientCapabilities
{
    std::string parser;
    std::optional<std::string> version;
};

}