#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages::base
{

struct Message
{
    static void validate_version(const std::string& str)
    {
        if (str != "2.0")
        {
            throw util::ParsingException("Expected JSON-RPC 2.0 message");
        }
    }
};

inline void from_json(const nlohmann::json& j, Message& m)
{
    Message::validate_version(j.at("version"));
}

}