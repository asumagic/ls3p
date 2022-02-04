#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages
{

struct TextDocumentIdentifier
{
    DocumentUri uri;
};

struct OptionalVersionedTextDocumentIdentifier : TextDocumentIdentifier
{
    std::variant<int, std::monostate> version;
};

}