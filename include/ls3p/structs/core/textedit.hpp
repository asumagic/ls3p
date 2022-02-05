#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/location.hpp>
#include <ls3p/structs/core/textdocument.hpp>

namespace ls3p::structs::core
{

struct ChangeAnnotation
{
    std::string label;
    std::optional<bool> needs_confirmation;
    std::optional<std::string> description;

    LS3P_ARCHIVE(ChangeAnnotation)
    {
        archive
            ("label", label)
            ("needsConfirmation", needs_confirmation)
            ("description", description);
    }
};

struct TextEdit
{
    Range range;
    std::string new_text;

    LS3P_ARCHIVE(TextEdit)
    {
        archive
            ("range", range)
            ("newText", new_text);
    }
};

struct AnnotatedTextEdit : TextEdit
{
    ChangeAnnotationIdentifier annotation_id;

    LS3P_ARCHIVE(AnnotatedTextEdit)
    {
        archive
            ("annotationId", annotation_id);
    }
};

struct TextDocumentEdit
{
    std::optional<OptionalVersionedTextDocumentIdentifier> text_document;

    std::variant<
        std::vector<TextEdit>,
        std::vector<AnnotatedTextEdit>
    > edits;

    LS3P_ARCHIVE(TextDocumentEdit)
    {
        archive
            ("textDocument", text_document)
            ("edits", edits);
    }
};

}