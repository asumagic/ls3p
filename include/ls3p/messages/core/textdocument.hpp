#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/core/location.hpp>

namespace ls3p::messages::core
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

}