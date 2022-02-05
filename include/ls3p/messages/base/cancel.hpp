#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages::base
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