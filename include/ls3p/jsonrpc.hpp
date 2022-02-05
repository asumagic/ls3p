#pragma once

#include <ls3p/transport.hpp>

#include <map>

namespace ls3p
{

class HttpJsonRpcServer
{
    public:
    HttpJsonRpcServer(TransportInterface& transport) :
        m_transport(&transport)
    {}

    void run_blocking();
    void handle_request();

    static std::map<std::string_view, std::string_view> parse_http_header(std::string_view header);

    private:
    std::string read_http_header();

    TransportInterface* m_transport;
};

}