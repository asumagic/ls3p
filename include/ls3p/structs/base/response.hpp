#pragma once

#include <ls3p/structs/common.hpp>
#include <ls3p/structs/base/message.hpp>

namespace ls3p::structs::base
{

enum class ErrorCode : Integer
{
    PARSE_ERROR = -32700,
    INVALID_REQUEST = -32600,
    METHOD_NOT_FOUND = -32601,
    INVALID_PARAMS = -32602,
    INTERNAL_ERROR = -32603,

    SERVER_NOT_INITIALIED = -32002,
    UNKNOWN_ERROR_CODE = -32001,

    LSP_RESERVED_START = -32899,
    CONTENT_MODIFIED = -32801,
    REQUEST_CANCELLED = -32800,
    LSP_RESERVED_END = -32800
};

struct ResponseError
{
    Integer code;
    std::string message;
    std::optional<std::variant<Integer, bool, std::string, std::monostate, nlohmann::json>> data;
};

inline void from_json(const nlohmann::json& j, ResponseError& m)
{
    parse(j, "code", m.code);
    parse(j, "message", m.message);
    parse(j, "data", m.data);
}

struct ResponseMessage : Message
{
    std::variant<Integer, std::string, std::monostate> id;
    std::optional<std::variant<Integer, bool, std::string, std::monostate, nlohmann::json>> params;
    std::optional<ResponseError> error;
};

inline void from_json(const nlohmann::json& j, ResponseMessage& m)
{
    parse(j, "id", m.id);
    parse(j, "params", m.params);
    parse(j, "error", m.error);

    if (m.params && m.error)
    {
        throw util::ParsingException("Only params or error may be present at a time");
    }
}

}