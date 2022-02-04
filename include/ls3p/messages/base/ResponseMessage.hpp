#pragma once

#include <ls3p/util/exceptions.hpp>
#include <ls3p/messages/common.hpp>
#include <ls3p/messages/base/Message.hpp>
#include <ls3p/messages/base/ResponseError.hpp>

namespace ls3p::messages::base
{

struct ResponseMessage : Message
{
    std::variant<Integer, std::string, std::monostate> id;
    std::optional<std::variant<Integer, bool, std::string, std::monostate, nlohmann::json>> params;
    std::optional<ResponseError> error;
};

inline void from_json(const nlohmann::json& j, ResponseMessage& m)
{
    using nlohmann::json;

    parse(j, "id", m.id);
    parse(j, "params", m.params);
    parse(j, "error", m.error);

    if (m.params && m.error)
    {
        throw util::ParsingException("Only params or error may be present at a time");
    }
}

}