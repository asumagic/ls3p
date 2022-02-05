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

struct FromArchiver
{
    const nlohmann::json& j;

    template<class T>
    const FromArchiver& operator()(const char* name, T& target) const
    {
        parse(j, name, target);
        return *this;
    }
};

struct ToArchiver
{
    nlohmann::json& j;

    template<class T>
    const ToArchiver& operator()(const char* name, T& target) const
    {
        j[name] = target;
        return *this;
    }
};

}

namespace ls3p::structs
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

/// \brief Helper macro to define an "archive" function to automatically expose from_json and to_json functions.
/// \details
/// Define this within a struct you want from_json and to_json to be automatically created from.
/// A function scope must follow. "archive" is passed as a parameter, which is either an instance of
/// \p FromArchiver or \p ToArchiver which both provide a call operator.
/// Example usage:
/// LS3P_ARCHIVE(MyClass) {
///     archive
///         ("field1", field1)
///         ("field2", field2);
/// }
#define LS3P_ARCHIVE(class_name) \
    friend inline void from_json(const nlohmann::json& j, class_name& s) \
    { \
        s.archive(ls3p::util::FromArchiver{j}); \
    } \
    friend inline void to_json(nlohmann::json& j, class_name& s) \
    { \
        s.archive(ls3p::util::ToArchiver{j}); \
    } \
    template<class Archive> \
    inline void archive(const Archive& archive)