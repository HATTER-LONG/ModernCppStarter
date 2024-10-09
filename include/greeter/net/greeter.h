#pragma once

#include <string>

namespace Greeter {

/**  Language codes to be used with the Greeter class */
enum class LanguageCode { EN, DE, ES, FR };

/**
 * @brief A class for saying hello in multiple languages
 */
class CGreeter {
    std::string m_name;

public:
    /**
     * @brief Creates a new greeter
     * @param name the name to greet
     */
    explicit CGreeter(std::string name);

    /**
     * @brief Creates a localized string containing the greeting
     * @param lang the language to greet in
     * @return a string containing the greeting
     */
    std::string greet(LanguageCode lang = LanguageCode::EN) const;
};

} // namespace Greeter
