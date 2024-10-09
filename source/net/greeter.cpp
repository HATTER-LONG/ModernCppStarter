#include <fmt/format.h>
#include <greeter/net/greeter.h>

namespace Greeter {

CGreeter::CGreeter([[maybe_unused]] std::string name) : m_name(std::move(name)) {}

std::string CGreeter::greet(LanguageCode lang) const {
    switch(lang) {
    default:
    case LanguageCode::EN:
        return fmt::format("Hello, {}!", m_name);
    case LanguageCode::DE:
        return fmt::format("Hallo {}!", m_name);
    case LanguageCode::ES:
        return fmt::format("¡Hola {}!", m_name);
    case LanguageCode::FR:
        return fmt::format("Bonjour {}!", m_name);
    }
}

} // namespace Greeter