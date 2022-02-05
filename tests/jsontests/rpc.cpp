#include "ls3p/structs/base/request.hpp"
#include "ls3p/transport.hpp"
#include <catch2/catch.hpp>

#include <ls3p/jsonrpc.hpp>
#include <stdexcept>

class StringBackedTransport : public ls3p::TransportInterface
{
    public:
    StringBackedTransport(std::string source) :
        source(std::move(source))
    {}

    void send(const nlohmann::json& j) override
    {
        sent.push_back(j);
    }

    void read(char* buffer, std::size_t min_bytes) override
    {
        if (source.size() < min_bytes)
        {
            throw std::runtime_error("Depleted source string");
        }

        const auto sub_begin = source.begin();
        const auto sub_end = source.begin() + min_bytes;

        std::copy(sub_begin, sub_end, buffer);
        source.erase(sub_begin, sub_end);
    }

    std::vector<nlohmann::json> sent;
    std::string source;
};

class DummyRpcServer : public ls3p::HttpJsonRpcServer
{
    public:
    using ls3p::HttpJsonRpcServer::HttpJsonRpcServer;

    void parse_json_content(const nlohmann::json& json) override
    {
        payloads.push_back(json);
    }

    std::vector<nlohmann::json> payloads;
};

TEST_CASE("JSON-RPC HTTP header parsing", "[jsonrpc]")
{
    StringBackedTransport dummy_transport("");
    DummyRpcServer server(dummy_transport);

    std::string_view header_test = "Content-Type: application/json-rpc\r\nContent-Length: 6969\r\n\r\n";
    const auto header = server.parse_http_header(header_test);

    REQUIRE(header.at("Content-Type") == "application/json-rpc");
    REQUIRE(header.at("Content-Length") == "6969");
}

TEST_CASE("JSON-RPC request parsing", "[jsonrpc]")
{
    constexpr std::string_view content = R"(
        {
            "version": "2.0",
            "id": 0,
            "method": "$/test",
            "params": {}
        }
    )";

    StringBackedTransport transport(
        std::string("Content-Length: ") + std::to_string(content.size()) + std::string("\r\n\r\n") + std::string(content)
    );
    DummyRpcServer server(transport);

    try
    {
        server.run_blocking();
    }
    catch (const std::runtime_error& e)
    {
        // depleted, might be normal
    }
    
    REQUIRE(server.payloads.size() == 1);
    
    // sanity check of the payload - we only really want to test the JSON-RPC handling here
    const auto request = server.payloads[0].get<ls3p::structs::base::RequestMessage>();
    REQUIRE(std::get<int>(request.id) == 0);
    REQUIRE(request.method == "$/test");
}