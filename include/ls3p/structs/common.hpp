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
        throw util::ValidationError("Could not match value against possible types");
    }
}

struct FromArchiver
{
    static constexpr bool is_parser = true;

    const nlohmann::json& j;

    template<class T>
    const FromArchiver& with_base(T& target) const
    {
        j.get_to(target);
        return *this;
    }

    template<class T>
    const FromArchiver& static_field(const char* name, const T& expected) const
    {
        if (j.at(name).get<T>() != expected)
        {
            throw util::ValidationError("Const field failed to match");
        }

        return *this;
    }

    template<class T>
    const FromArchiver& operator()(const char* name, T& target) const
    {
        j.at(name).get_to(target);
        return *this;
    }

    template<class T>
    const FromArchiver& operator()(const char* name, std::optional<T>& target) const
    {
        if (j.contains(name))
        {
            j[name].get_to(target.emplace());
        }
        else
        {
            target.reset();
        }

        return *this;
    }
};

struct ToArchiver
{
    static constexpr bool is_parser = false;

    nlohmann::json& j;

    template<class T>
    const ToArchiver& with_base(const T& source) const
    {
        j = source;
        return *this;
    }

    template<class T>
    const ToArchiver& static_field(const char* name, const T& source) const
    {
        j[name] = source;
        return *this;
    }

    template<class T>
    const ToArchiver& operator()(const char* name, const T& source) const
    {
        j[name] = source;
        return *this;
    }

    template<class T>
    const ToArchiver& operator()(const char* name, const std::optional<T>& source) const
    {
        if (source.has_value())
        {
            j[name] = source.value();
        }

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

}

// TODO: In LS3P_ARCHIVE, we could improve the exception handling to allow attaching extra context
//       to errors, in particular "during serialization", "during deserialization", the object type,
//       the field name, etc.

/// \brief Helper macro to define an "archive" function to automatically expose from_json and to_json functions.
/// \details
/// Define this within a struct you want from_json and to_json to be automatically created from.
///
/// A function scope must follow. One parameter is exposed in the scope:
/// - \p archive which is either an instance of \p FromArchiver or \p ToArchiver
///
/// Note that it is possible to detect whether we are in a parsing context - i.e. \p FromArchiver - by checking
/// the static constexpr bool field `Archive::is_parser`.
///
/// Example usage:
/// LS3P_ARCHIVE(MyClass) {
///     archive
///         ("field1", field1)
///         ("field2", field2);
/// }
#define LS3P_ARCHIVE(class_name) \
    friend inline void from_json(const nlohmann::json& j, class_name& s) \
    { \
        constexpr auto context = "Parsing " #class_name ":\n"; \
        try { \
            s.archive(ls3p::util::FromArchiver{j}); \
        } catch (const nlohmann::json::exception& e) { \
            throw ls3p::util::ValidationError(e.what()).with_context(context); \
        } catch (const ls3p::util::ValidationError& e) { \
            throw e.with_context(context); \
        } \
    } \
    friend inline void to_json(nlohmann::json& j, const class_name& s) \
    { \
        constexpr auto context = "Serializing " #class_name ":\n"; \
        try { \
            const_cast<class_name&>(s).archive(ls3p::util::ToArchiver{j}); \
        } catch (const nlohmann::json::exception& e) { \
            throw ls3p::util::ValidationError(e.what()).with_context(context); \
        } catch (const ls3p::util::ValidationError& e) { \
            throw e.with_context(context); \
        } \
    } \
    template<class Archive> \
    inline void archive(const Archive& archive)