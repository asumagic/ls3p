#pragma once

#include <exception>
#include <stdexcept>

namespace ls3p::util
{

/// \brief Base class for all LS3P exceptions
class Exception : std::runtime_error
{
    public:
    using std::runtime_error::runtime_error;
};

/// \brief A struct failed (de)serialization due to a type or logical error
class ValidationError : Exception
{
    public:
    using Exception::Exception;
};

}