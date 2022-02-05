#pragma once
#include <ls3p/messages/common.hpp>
#include <ls3p/messages/core/TextEdit.hpp>

namespace ls3p::messages::core
{

namespace trace_value
{

static constexpr std::string_view
    OFF = "off",
    MESSAGES = "messages",
    VERBOSE = "verbose";

}

/// \see trace_value
using TraceValue = std::string;

}