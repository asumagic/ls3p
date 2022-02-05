#pragma once

#include <exception>
#include <stdexcept>

namespace ls3p::util
{

/// \brief Base class for all LS3P exceptions
class Exception : public std::runtime_error
{
    public:
    using std::runtime_error::runtime_error;
};

/// \brief A struct failed (de)serialization due to a type or logical error
class ValidationError : public Exception
{
    public:
    using Exception::Exception;

    ValidationError with_context(const char* context) const
    {
        return ValidationError(std::string(context) + what());
    }
};

}