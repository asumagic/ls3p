#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages::base
{

template<class T>
struct ProgressParams
{
    ProgressToken token;
    T value;
};

template<class T>
inline void from_json(const nlohmann::json& j, ProgressParams<T>& m)
{
    using nlohmann::json;

    parse(j, "token", m.token);
    parse(j, "value", m.value);
}

}