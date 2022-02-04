#include "ls3p/messages/base/ProgressParams.hpp"
#include "ls3p/messages/base/RequestMessage.hpp"
#include <catch2/catch.hpp>

#include <ls3p/messages/base.hpp>
#include <nlohmann/json.hpp>

using nlohmann::json;
using namespace ls3p::messages;

TEST_CASE("Test NotificationMessage parsing", "[parsing]") {
    const auto message = json::parse(R"(
        {
            "method": "$/cancelRequest",
            "params": {
                "id": 123
            }
        }
    )").get<base::NotificationMessage>();
    
    REQUIRE(message.method == "$/cancelRequest");

    const auto cancel_params = message.params.value().get<base::CancelParams>();
    REQUIRE(std::get<int>(cancel_params.id) == 123);
}

TEST_CASE("Test ProgressParams parsing", "[parsing]") {
    const auto message = json::parse(R"(
        {
            "token": 123,
            "value": 456
        }
    )").get<base::ProgressParams<int>>();

    REQUIRE(std::get<int>(message.token) == 123);
    REQUIRE(message.value == 456);
}

TEST_CASE("Test RequestMessage parsing", "[request]") {
    const auto message = json::parse(R"(
        {
            "version": "2.0",
            "id": 123,
            "method": "foobar"
        }
    )").get<base::RequestMessage>();

    REQUIRE(std::get<int>(message.id) == 123);
    REQUIRE(message.method == "foobar");
    REQUIRE(!message.params.has_value());
}