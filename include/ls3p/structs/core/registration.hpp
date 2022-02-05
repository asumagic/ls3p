#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/location.hpp>

namespace ls3p::structs::core
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