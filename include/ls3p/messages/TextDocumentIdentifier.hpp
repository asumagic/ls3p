#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/AnnotatedTextEdit.hpp>
#include <ls3p/messages/TextEdit.hpp>

namespace ls3p::messages
{

struct TextDocumentIdentifier
{
    DocumentUri uri;

    std::variant<
        std::vector<TextEdit>,
        std::vector<AnnotatedTextEdit>
    > edits;
};

}