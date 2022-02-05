#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::base
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
    parse(j, "token", m.token);
    parse(j, "value", m.value);
}

}