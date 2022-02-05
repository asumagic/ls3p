#pragma once

#include <ls3p/transport.hpp>

#include <map>

namespace ls3p
{

/// \brief Thin abstraction to handle JSON-RPC requests with HTTP headers.
/// \details
/// RPC servers should override \p parse_json_content to handle JSON payloads.
/// This class does not abstract away requests, etc., it only allows obtaining payload from a \p TransportInterface
class HttpJsonRpcServer
{
    public:
    HttpJsonRpcServer(TransportInterface& transport) :
        m_transport(&transport)
    {}

    virtual ~HttpJsonRpcServer() = default;

    void run_blocking();
    void handle_request();

    static std::map<std::string_view, std::string_view> parse_http_header(std::string_view header);
    virtual void parse_json_content(const nlohmann::json& json) = 0;

    private:
    /// \brief Blocking consumption of a HTTP header from \p m_transport to a std::string until the final CRLF.
    std::string read_http_header();

    TransportInterface* m_transport;
};

}