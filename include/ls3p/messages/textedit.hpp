#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/location.hpp>
#include <ls3p/messages/textdoc.hpp>

namespace ls3p::messages
{

struct ChangeAnnotation
{
    std::string label;
    std::optional<bool> needs_confirmation;
    std::optional<std::string> description;
};

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