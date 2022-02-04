#pragma once

#include <ls3p/messages/common.hpp>
#include <variant>

namespace ls3p::messages
{

struct OptionalVersionedTextDocumentIdentifier
{
    std::variant<int, std::monostate> version;
};

}