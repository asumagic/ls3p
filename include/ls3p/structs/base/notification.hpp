#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/base/message.hpp>

namespace ls3p::structs::base
{

struct NotificationMessage : Message
{
    std::string method;
    std::optional<nlohmann::json> params;

    LS3P_ARCHIVE(NotificationMessage)
    {
        archive
            ("method", method)
            ("params", params);
    }
};

}