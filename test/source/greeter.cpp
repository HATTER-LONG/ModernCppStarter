#include <catch2/catch_all.hpp>
#include <greeter/net/greeter.h>
#include <spdlog/spdlog.h>

#include <string>

namespace {
TEST_CASE("Greeter", "[greeter]") {
    using Greeter::CGreeter;
    using Greeter::LanguageCode;

    CGreeter const greeter("Tests");

    CHECK(greeter.greet(LanguageCode::EN) == "Hello, Tests!");
    CHECK(greeter.greet(LanguageCode::DE) == "Hallo Tests!");
    CHECK(greeter.greet(LanguageCode::ES) == "¡Hola Tests!");
    CHECK(greeter.greet(LanguageCode::FR) == "Bonjour Tests!");
}

} // namespace
