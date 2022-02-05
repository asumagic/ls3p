#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::base
{

template<class T>
struct ProgressParams
{
    ProgressToken token;
    T value;

    LS3P_ARCHIVE(ProgressParams<T>)
    {
        archive
            ("token", token)
            ("value", value);
    }
};

}