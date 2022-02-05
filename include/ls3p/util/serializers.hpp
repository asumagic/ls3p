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
    static void to_json(json& j, const std::monostate& v)
    {
        j = {};
    }

    static void from_json(const json& j, std::monostate& v)
    {
        if (!j.is_null())
        {
            throw ls3p::util::ValidationError("Not a null value");
        }
    }
};

template<class... Ts>
struct adl_serializer<std::variant<Ts...>>
{
    template<class T>
    static bool try_get(const json& j, std::variant<Ts...>& variant)
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
        catch (const ls3p::util::ValidationError& e)
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
            throw ls3p::util::ValidationError("Failed to match any type for variant");
        }
    }
};

}