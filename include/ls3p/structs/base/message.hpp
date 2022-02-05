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

    LS3P_ARCHIVE(Message)
    {
        archive.static_field("jsonrpc", std::string_view("2.0"));
    }
};

}