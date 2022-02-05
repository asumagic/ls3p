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

    LS3P_ARCHIVE(DocumentFilter)
    {
        archive
            ("language", language)
            ("scheme", scheme)
            ("pattern", pattern);
    }
};

using DocumentSelector = std::vector<DocumentFilter>;

struct TextDocumentRegistrationOptions
{
    std::variant<DocumentSelector, std::monostate> document_selector;

    LS3P_ARCHIVE(TextDocumentRegistrationOptions)
    {
        archive
            ("documentSelector", document_selector);
    }
};

struct StaticRegistrationOptions
{
    std::optional<std::string> id;

    LS3P_ARCHIVE(StaticRegistrationOptions)
    {
        archive
            ("id", id);
    }
};

}