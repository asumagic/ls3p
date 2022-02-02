#pragma once

#include "nlohmann/json.hpp"
#include <ls3p/messages/common.hpp>
#include <ls3p/messages/base/Message.hpp>

namespace ls3p::messages::base
{

struct RequestMessage : Message
{
    std::string method;
    nlohmann::json params;
    std::variant<Integer, std::string> id;
};

inline void from_json(const nlohmann::json& j, RequestMessage& m)
{
    using nlohmann::json;

    from_json(j, static_cast<Message&>(m));
    j.at("method").get_to(m.method);
    j.at("params").get_to(m.params);
    util::validate_type<json::value_t::array, json::value_t::object>(m.params);
    j.at("id").get_to(m.id);
}

}