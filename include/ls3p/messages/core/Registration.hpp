#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/core/Position.hpp>

namespace ls3p::messages::core
{

struct DocumentFilter
{
    std::optional<std::string> language;
    std::optional<std::string> scheme;
    std::optional<std::string> pattern;
};

using DocumentSelector = std::vector<DocumentFilter>;

struct TextDocumentRegistrationOptions
{
    std::variant<DocumentSelector, std::monostate> document_selector;
};

struct StaticRegistrationOptions
{
    std::optional<std::string> id;
};

}