#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/location.hpp>

namespace ls3p::structs::core
{
struct Diagnostic
{
    struct CodeDescription
    {
        URI href;
    };

    struct RelatedInformation
    {
        Location location;
        std::string message;
    };

    enum class Severity : Integer
    {
        ERROR = 1,
        WARNING = 2,
        INFORMATION = 3,
        HINT = 4
    };

    enum class Tag : Integer
    {
        UNNECESSARY = 1,
        DEPRECATED = 2
    };

    Range range;
    std::optional<Severity> severity;
    std::optional<std::variant<Integer, std::string>> code;
    std::optional<CodeDescription> code_description;
    std::optional<std::string> source;
    std::string message;
    std::optional<std::vector<Tag>> tags;
    std::optional<RelatedInformation> related_information;
    std::optional<nlohmann::json> data;
};

}