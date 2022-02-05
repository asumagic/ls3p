#include <catch2/catch.hpp>

#include <ls3p/util/exceptions.hpp>
#include <ls3p/structs/base.hpp>
#include <nlohmann/json.hpp>

using nlohmann::json;
using namespace ls3p::structs;

TEST_CASE("Test NotificationMessage parsing", "[parsing]")
{
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

TEST_CASE("Test ProgressParams parsing", "[parsing]")
{
    const auto message = json::parse(R"(
        {
            "token": 123,
            "value": 456
        }
    )").get<base::ProgressParams<int>>();

    REQUIRE(std::get<int>(message.token) == 123);
    REQUIRE(message.value == 456);
}

TEST_CASE("Test RequestMessage parsing", "[request]")
{
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

TEST_CASE("Test ResponseMessage (payload case) parsing", "[request]")
{
    const auto message = json::parse(R"(
        {
            "id": 123,
            "params": 456
        }
    )").get<base::ResponseMessage>();

    REQUIRE(std::get<int>(message.id) == 123);
    REQUIRE(std::get<int>(message.params.value()) == 456);
    REQUIRE(!message.error.has_value());
}

TEST_CASE("Test ResponseMessage (params+error fields) exception", "[request]")
{
    REQUIRE_THROWS_AS(
        json::parse(R"(
            {
                "id": 123,
                "params": 456,
                "error": {
                    "code": -32601,
                    "message": "oh noes an error >w<"
                }
            }
        )").get<base::ResponseMessage>(),
        ls3p::util::ValidationError
    );
}

TEST_CASE("Test ResponseMessage (+ResponseError) parsing", "[request]")
{
    const auto message = json::parse(R"(
        {
            "id": 123,
            "error": {
                "code": -32601,
                "message": "oh noes an error >w<",
                "data": {
                    "details": "that error code is large oh no"
                }
            }
        }
    )").get<base::ResponseMessage>();

    REQUIRE(std::get<int>(message.id) == 123);

    const auto& err = message.error.value();
    REQUIRE(err.code == -32601);
    REQUIRE(err.message == "oh noes an error >w<");
    REQUIRE(std::get<nlohmann::json>(err.data.value()).at("details") == "that error code is large oh no");
}