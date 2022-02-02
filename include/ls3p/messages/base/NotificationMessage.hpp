#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/base/Message.hpp>

namespace ls3p::messages::base
{

struct NotificationMessage : Message
{
    std::string method;

    std::optional<nlohmann::json> params;
};

}