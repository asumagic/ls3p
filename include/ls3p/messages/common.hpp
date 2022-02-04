#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>
#include <ls3p/util/serializers.hpp>
#include <ls3p/util/exceptions.hpp>

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

template<class T>
struct _Parse
{
    static void parse(const nlohmann::json& j, const char* field, T& target)
    {
        j.at(field).get_to(target);
    }
};

template<class T>
struct _Parse<std::optional<T>>
{
    static void parse(const nlohmann::json& j, const char* field, std::optional<T>& target)
    {
        if (j.contains(field))
        {
            j[field].get_to(target);
        }
        else
        {
            target.reset();
        }
    }
};

// partial function template specialization is not possible, so do this stupid shit instead
template<class T>
void parse(const nlohmann::json& j, const char* field, T& target)
{
    _Parse<T>::parse(j, field, target);
}

}

namespace ls3p::messages
{

using Integer = std::int32_t;
using UInteger = std::uint32_t;
using Decimal = double;

// TODO: DocumentUri extra validation and API
using DocumentUri = std::string;
// TODO: URI extra validation and API
using URI = std::string;

using ProgressToken = std::variant<Integer, std::string>;

using ChangeAnnotationIdentifier = std::string;

using util::parse; // NOLINT(misc-unused-using-decls)

}