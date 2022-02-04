#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/Location.hpp>

namespace ls3p::messages
{

struct DiagnosticRelatedInformation
{
    Location location;
    std::string message;
};

}