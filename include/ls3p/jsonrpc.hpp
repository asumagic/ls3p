#pragma once

#include <nlohmann/json.hpp>
#include <stdexcept>
#include <string>
#include <iostream>

namespace ls3p::jsonrpc
{

using json = nlohmann::json;

inline void validate_version(const std::string& str)
{
    if (str != "2.0")
    {
        throw std::runtime_error("Expected JSON-RPC 2.0 message");
    }
}

class Request
{
    public:
    std::string method;
    json params;
    std::string id;

    Request(const json& request) :
        method(std::move(request.at("method"))),
        params(std::move(request.at("params"))),
        id(parse_id(request.at("id")))
    {}

    private:
    // This returns a string no matter what.
    // A null entry means an empty string, which cannot be distinguished from an empty id string.
    static std::string parse_id(const json& value)
    {
        if (value.is_number())
        {
            return std::to_string(long(value));
        }
        else if (value.is_string())
        {
            return value;
        }
        else if (value.is_null())
        {
            return {};
        }

        throw std::runtime_error("Unexpected data type for Request.id");
    }
};

}