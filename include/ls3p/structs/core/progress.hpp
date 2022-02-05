#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/location.hpp>

namespace ls3p::structs::core
{

struct WorkDoneProgressBegin
{
    std::string title;
    std::optional<bool> cancellable;
    std::optional<std::string> message;
    std::optional<UInteger> percentage;

    LS3P_ARCHIVE(WorkDoneProgressBegin)
    {
        archive
            .static_field("kind", std::string_view("begin"))
            ("title", title)
            ("cancellable", cancellable)
            ("message", message)
            ("percentage", percentage);
    }
};

struct WorkDoneProgressReport
{
    std::optional<bool> cancellable;
    std::optional<std::string> message;
    std::optional<UInteger> percentage;

    LS3P_ARCHIVE(WorkDoneProgressReport)
    {
        archive
            .static_field("kind", std::string_view("report"))
            ("cancellable", cancellable)
            ("message", message)
            ("percentage", percentage);
    }
};

struct WorkDoneProgressEnd
{
    std::optional<std::string> message;

    LS3P_ARCHIVE(WorkDoneProgressEnd)
    {
        archive
            .static_field("kind", std::string_view("end"))
            ("message", message);
    }
};

struct WorkDoneProgressOptions
{
    std::optional<bool> work_done_progress;

    LS3P_ARCHIVE(WorkDoneProgressOptions)
    {
        archive
            ("workDoneProgress", work_done_progress);
    }
};

// TODO: window.workDoneProgress: how should this be implemented?

struct PartialResultParams
{
    std::optional<ProgressToken> partial_result_token;

    LS3P_ARCHIVE(PartialResultParams)
    {
        archive
            ("partialResultToken", partial_result_token);
    }
};

}