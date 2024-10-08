#include <catch2/catch_all.hpp>
#include <greeter/greeter.h>
#include <greeter/version.h>
#include <spdlog/spdlog.h>

#include <string>

namespace {
void test_address_sanitizer() {
    // 越界访问
    int* array = new int[5];
    array[5] = 10; // 这里应该引发 ASan 错误
    array[6] = 10; // 这里应该引发 ASan 错误
    array[7] = 10; // 这里应该引发 ASan 错误
    spdlog::info("array[5] = {}", array[5]);
    // 使用释放后的内存
    int* ptr = new int;
    delete ptr;
    *ptr = 42; // 这里应该引发 ASan 错误

    // 内存泄漏
    int* leak = new int[10]; // 这里应该引发 ASan 错误
    (void)leak;
}

TEST_CASE("Greeter", "[greeter]") {
    using Greeter::CGreeter;
    using Greeter::LanguageCode;

    CGreeter const greeter("Tests");

    CHECK(greeter.greet(LanguageCode::EN) == "Hello, Tests!");
    CHECK(greeter.greet(LanguageCode::DE) == "Hallo Tests!");
    CHECK(greeter.greet(LanguageCode::ES) == "¡Hola Tests!");
    CHECK(greeter.greet(LanguageCode::FR) == "Bonjour Tests!");
    test_address_sanitizer();
}

TEST_CASE("Greeter version", "[greeter]") {
    static_assert(std::string_view(GREETER_VERSION) == std::string_view("1.0"));
    CHECK(std::string(GREETER_VERSION) == std::string("1.0"));
}
} // namespace
