#include "ls3p/transport.hpp"
#include <catch2/catch.hpp>

#include <ls3p/jsonrpc.hpp>

class DummyTransportInterface : public ls3p::TransportInterface
{
    public:
    void send(const nlohmann::json& j) override {}
    void read(char* buffer, std::size_t min_bytes) override {}
};

class DummyRpcServer : public ls3p::HttpJsonRpcServer
{
    public:
    using ls3p::HttpJsonRpcServer::HttpJsonRpcServer;

    void parse_json_content(const nlohmann::json& json) override {}
};

TEST_CASE("JSON-RPC HTTP header parsing", "[jsonrpc]")
{
    DummyTransportInterface dummy_transport;
    DummyRpcServer server(dummy_transport);

    std::string_view header_test = "Content-Type: application/json-rpc\r\nContent-Length: 6969\r\n\r\n";
    const auto header = server.parse_http_header(header_test);

    REQUIRE(header.at("Content-Type") == "application/json-rpc");
    REQUIRE(header.at("Content-Length") == "6969");
}