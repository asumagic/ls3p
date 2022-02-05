#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/base/message.hpp>

namespace ls3p::messages::base
{

struct NotificationMessage : Message
{
    std::string method;
    std::optional<nlohmann::json> params;
};

inline void from_json(const nlohmann::json& j, NotificationMessage& m)
{
    using nlohmann::json;

    parse(j, "method", m.method);
    parse(j, "params", m.params);
}

}