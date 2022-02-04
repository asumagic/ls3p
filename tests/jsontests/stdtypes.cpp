#include <catch2/catch.hpp>

#include <ls3p/messages/common.hpp>
#include <nlohmann/json.hpp>
#include <variant>

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

TEST_CASE("Test std::variant<> parsing", "[parsing]") {
    std::variant<int, std::string, std::monostate> value;

    parse(json::parse(R"({ "value": 123 })"), "value", value);
    REQUIRE(std::holds_alternative<int>(value));
    REQUIRE(std::get<int>(value) == 123);

    parse(json::parse(R"({ "value": "hello" })"), "value", value);
    REQUIRE(std::holds_alternative<std::string>(value));
    REQUIRE(std::get<std::string>(value) == "hello");

    parse(json::parse(R"({ "value": null })"), "value", value);
    REQUIRE(std::holds_alternative<std::monostate>(value));
}