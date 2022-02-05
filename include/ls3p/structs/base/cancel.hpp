#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::base
{

struct CancelParams
{
    std::variant<Integer, std::string> id;
};

inline void from_json(const nlohmann::json& j, CancelParams& m)
{
    using nlohmann::json;

    parse(j, "id", m.id);
}

}