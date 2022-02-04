#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/location.hpp>
#include <ls3p/messages/textid.hpp>

namespace ls3p::messages
{

using ChangeAnnotationIdentifier = std::string;

struct TextEdit
{
    Range range;
    std::string new_text;
};

struct AnnotatedTextEdit : TextEdit
{
    ChangeAnnotationIdentifier annotation_id;
};

struct TextDocumentEdit
{
    std::optional<OptionalVersionedTextDocumentIdentifier> text_document;

    std::variant<
        std::vector<TextEdit>,
        std::vector<AnnotatedTextEdit>
    > edits;
};

}