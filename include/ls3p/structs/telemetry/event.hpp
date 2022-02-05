#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::telemetry
{

using TelemetryParams = std::variant<Integer, bool, std::string, nlohmann::json>;

}