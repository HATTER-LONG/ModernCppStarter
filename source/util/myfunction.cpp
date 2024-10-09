#include "greeter/util/myfunction.h"
#include <spdlog/spdlog.h>

using Greeter::Util::UtilTestClass;

UtilTestClass::UtilTestClass() { spdlog::info("UtilTestClass constructor"); }
UtilTestClass::~UtilTestClass() { spdlog::info("UtilTestClass destructor"); }
void UtilTestClass::print() { spdlog::info("UtilTestClass print"); }