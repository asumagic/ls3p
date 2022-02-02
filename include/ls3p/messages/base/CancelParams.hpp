#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages::base
{

struct CancelParams
{
    std::variant<Integer, std::string> id;
};

}