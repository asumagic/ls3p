#pragma once

#include <stdexcept>

namespace ls3p::util
{

class ParsingException : std::runtime_error
{
    public:
    using std::runtime_error::runtime_error;
};

}