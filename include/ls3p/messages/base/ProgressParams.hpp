#pragma once

#include <ls3p/messages/common.hpp>

namespace ls3p::messages::base
{

template<class T>
struct ProgressParams
{
    ProgressToken token;
    T value;
};

}