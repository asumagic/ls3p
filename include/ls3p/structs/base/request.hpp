#pragma once

#include "nlohmann/json.hpp"
#include <ls3p/structs/common.hpp>
#include <ls3p/structs/base/message.hpp>

namespace ls3p::structs::base
{

struct RequestMessage : Message
{
    std::string method;
    std::optional<nlohmann::json> params;
    std::variant<Integer, std::string> id;

    LS3P_ARCHIVE(RequestMessage)
    {
        using nlohmann::json;

        archive
            .template with_base<Message>(*this)
            ("method", method)
            ("params", params)
            ("id", id);
        
        if constexpr (Archive::is_parser)
        {
            if (params.has_value())
            {
                util::validate_type<json::value_t::array, json::value_t::object>(params.value());
            }
        }
    }
};

}