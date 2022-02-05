#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::base
{

struct Message
{
    LS3P_ARCHIVE(Message)
    {
        archive.static_field("jsonrpc", std::string_view("2.0"));
    }
};

}