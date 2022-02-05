#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/base/message.hpp>

namespace ls3p::structs::base
{

struct NotificationMessage : Message
{
    std::string method;
    std::optional<nlohmann::json> params;
};

inline void from_json(const nlohmann::json& j, NotificationMessage& m)
{
    parse(j, "method", m.method);
    parse(j, "params", m.params);
}

}