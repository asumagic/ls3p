#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/location.hpp>

namespace ls3p::structs::core
{

struct TextDocumentIdentifier
{
    DocumentUri uri;

    LS3P_ARCHIVE(TextDocumentIdentifier)
    {
        archive
            ("uri", uri);
    }
};

struct OptionalVersionedTextDocumentIdentifier : TextDocumentIdentifier
{
    std::variant<Integer, std::monostate> version;

    LS3P_ARCHIVE(OptionalVersionedTextDocumentIdentifier)
    {
        archive
            ("version", version);
    }
};

struct VersionedTextDocumentIdentifier : TextDocumentIdentifier
{
    Integer version;

    LS3P_ARCHIVE(VersionedTextDocumentIdentifier)
    {
        archive
            ("version", version);
    }
};

struct TextDocumentItem
{
    DocumentUri uri;
    std::string language_id;
    Integer version;
    std::string text;

    LS3P_ARCHIVE(TextDocumentItem)
    {
        archive
            ("uri", uri)
            ("languageId", language_id)
            ("version", version)
            ("text", text);
    }
};

struct TextDocumentPositionParams
{
    TextDocumentIdentifier text_document;
    Position position;

    LS3P_ARCHIVE(TextDocumentPositionParams)
    {
        archive
            ("textDocument", text_document)
            ("position", position);
    }
};

}