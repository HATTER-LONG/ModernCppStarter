#include <greeter/net/greeter.h>

#include <cxxopts.hpp>
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>
#include <unordered_map>

auto main(int argc, char** argv) -> int {
    const std::unordered_map<std::string, Greeter::LanguageCode> languages{
        {"en", Greeter::LanguageCode::EN},
        {"de", Greeter::LanguageCode::DE},
        {"es", Greeter::LanguageCode::ES},
        {"fr", Greeter::LanguageCode::FR},
    };

    cxxopts::Options options(*argv, "A program to welcome the world!");

    std::string language;
    std::string name;

    // clang-format off
  options.add_options()
    ("h,help", "Show help")
    ("v,version", "Print the current version number")
    ("n,name", "Name to greet", cxxopts::value(name)->default_value("World"))
    ("l,lang", "Language code to use", cxxopts::value(language)->default_value("en"))
  ;
    // clang-format on

    auto result = options.parse(argc, argv);

    if(result["help"].as<bool>()) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if(result["version"].as<bool>()) {
        spdlog::info("Greeter, version 1.0");
        return 0;
    }

    auto lang_it = languages.find(language);
    if(lang_it == languages.end()) {
        spdlog::error("unknown language code: {}", language);
        return 1;
    }

    Greeter::CGreeter const greeter(name);
    spdlog::info("greeter message: {}", greeter.greet(lang_it->second));

    return 0;
}
