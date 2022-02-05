#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::base
{

struct CancelParams
{
    std::variant<Integer, std::string> id;

    LS3P_ARCHIVE(CancelParams)
    {
        archive("id", id);
    }
};

}