#include <catch2/catch_all.hpp>
#include <greeter/greeter.h>
#include <greeter/version.h>

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
    CHECK(true == false);
}

TEST_CASE("Greeter version", "[greeter]") {
    static_assert(std::string_view(GREETER_VERSION) == std::string_view("1.0"));
    CHECK(std::string(GREETER_VERSION) == std::string("1.0"));
}
} // namespace
