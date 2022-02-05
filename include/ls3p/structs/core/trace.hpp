#pragma once
#include <ls3p/structs/common.hpp>

namespace ls3p::structs::core
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