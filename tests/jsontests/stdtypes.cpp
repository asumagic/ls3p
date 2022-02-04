#include <catch2/catch.hpp>

#include <ls3p/messages/common.hpp>
#include <nlohmann/json.hpp>

using nlohmann::json;
using namespace ls3p::messages;

TEST_CASE("Test std::optional<> parsing", "[parsing]") {
    std::optional<int> value;
    parse(json::parse(R"({ "value": 123 })"), "value", value);
    REQUIRE(value.has_value());
    REQUIRE(value.value() == 123);

    parse(json::parse(R"({})"), "value", value);
    REQUIRE(!value.has_value());
}