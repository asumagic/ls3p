#pragma once

#include <nlohmann/json.hpp>

namespace ls3p
{

class TransportInterface
{
    public:
    virtual ~TransportInterface() = default;

    virtual void send(const nlohmann::json& j) = 0;
    virtual void read(char* buffer, std::size_t min_bytes) = 0;
};

}