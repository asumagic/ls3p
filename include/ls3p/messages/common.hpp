#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>
#include <nlohmann/json.hpp>
#include <ls3p/util/serializers.hpp>
#include <ls3p/util/exceptions.hpp>

namespace ls3p::messages
{

using Integer = std::int32_t;
using UInteger = std::uint32_t;
using Decimal = double;

using ProgressToken = std::variant<Integer, std::string>;

}

namespace ls3p::util
{

template<nlohmann::json::value_t... AcceptableTypes>
void validate_type(const nlohmann::json& json)
{
    if (!((json.type() == AcceptableTypes) || ...))
    {
        throw util::ParsingException("Could not match value against possible types");
    }
}

}