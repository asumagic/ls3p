#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/location.hpp>
#include <optional>
#include <string>

namespace ls3p::messages
{

struct TextDocumentIdentifier
{
    DocumentUri uri;
};

struct OptionalVersionedTextDocumentIdentifier : TextDocumentIdentifier
{
    std::variant<Integer, std::monostate> version;
};

struct VersionedTextDocumentIdentifier : TextDocumentIdentifier
{
    Integer version;
};

struct TextDocumentItem
{
    DocumentUri uri;
    std::string language_id;
    Integer version;
    std::string text;
};

struct TextDocumentPositionParams
{
    TextDocumentIdentifier text_document;
    Position position;
};

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

}