#pragma once

#include "nlohmann/json.hpp"
#include <ls3p/messages/common.hpp>
#include <ls3p/messages/base/Message.hpp>

namespace ls3p::messages::base
{

struct RequestMessage : Message
{
    std::string method;
    std::optional<nlohmann::json> params;
    std::variant<Integer, std::string> id;
};

inline void from_json(const nlohmann::json& j, RequestMessage& m)
{
    using nlohmann::json;

    from_json(j, static_cast<Message&>(m));
    parse(j, "method", m.method);
    parse(j, "params", m.params);
    if (m.params.has_value())
    {
        util::validate_type<json::value_t::array, json::value_t::object>(m.params.value());
    }
    parse(j, "id", m.id);
}

}