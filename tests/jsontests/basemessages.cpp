#include <catch2/catch.hpp>

#include <ls3p/messages/base/CancelParams.hpp>
#include <ls3p/messages/base/NotificationMessage.hpp>
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