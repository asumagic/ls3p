#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::base
{

struct Message
{
    static void validate_version(const std::string& str)
    {
        if (str != "2.0")
        {
            throw util::ValidationError("Expected JSON-RPC 2.0 message");
        }
    }
};

inline void from_json(const nlohmann::json& j, Message& m)
{
    Message::validate_version(j.at("version"));
}

inline void to_json(nlohmann::json& j, const Message& m)
{
    j["version"] = "2.0";
}

}