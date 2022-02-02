#pragma once

#include <optional>
#include <variant>
#include <nlohmann/json.hpp>
#include <ls3p/util/exceptions.hpp>

namespace nlohmann
{

template<>
struct adl_serializer<std::monostate>
{
    static void to_json(json& j, std::monostate& v)
    {
        j = {};
    }

    static void from_json(const json& j, const std::monostate& v)
    {
        if (!j.is_null())
        {
            throw ls3p::util::ParsingException("Not a null value");
        }
    }
};

template<class... Ts>
struct adl_serializer<std::variant<Ts...>>
{
    template<class T>
    static bool try_get(json& j, std::variant<Ts...>& variant)
    {
        try
        {
            variant = j.get<T>();
            return true;
        }
        catch (const nlohmann::json::exception& e)
        {
            return false;
        }
        catch (const ls3p::util::ParsingException& e)
        {
            return false;
        }
    }

    static void to_json(json& j, const std::variant<Ts...>& v)
    {
        std::visit([&](auto&& value) { j = std::forward<decltype(value)>(value); }, v);
    }

    static void from_json(const json& j, std::variant<Ts...>& v)
    {
        if (!(try_get<Ts>(j, v) || ...))
        {
            throw ls3p::util::ParsingException("Failed to match any type for variant");
        }
    }
};

template<class T>
struct adl_serializer<std::optional<T>>
{
    static void to_json(json& j, const std::optional<T>& v)
    {
        if (v.has_value())
        {
            j = v.value();
        }
        else
        {
            v = std::nullopt;
        }
    }

    static void from_json(const json& j, std::optional<T>& v)
    {
        if (!j.is_null())
        {
            v = j.get<T>();
        }
        else
        {
            v = std::nullopt;
        }
    }
};

}