#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/location.hpp>

namespace ls3p::structs::core
{

struct WorkDoneProgressBegin
{
    // NOTE: must assert on kind == "begin"
    std::string title;
    std::optional<bool> cancellable;
    std::optional<std::string> message;
    std::optional<UInteger> percentage;
};

struct WorkDoneProgressReport
{
    // NOTE: must assert on kind == "report"
    std::optional<bool> cancellable;
    std::optional<std::string> message;
    std::optional<UInteger> percentage;
};

struct WorkDoneProgressEnd
{
    // NOTE: must assert on kind == "end"
    std::optional<std::string> message;
};

struct WorkDoneProgressOptions
{
    std::optional<bool> work_done_progress;
};

// TODO: window.workDoneProgress: how should this be implemented?

struct PartialResultParams
{
    std::optional<ProgressToken> partial_result_token;
};

}