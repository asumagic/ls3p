#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages
{

struct ChangeAnnotation
{
    std::string label;
    std::optional<bool> needs_confirmation;
    std::optional<std::string> description;
};

}