file(GLOB_RECURSE util_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(${PROJECT_NAME}_Util ${util_sources})
target_include_directories(${PROJECT_NAME}_Util PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include> $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>)
target_link_libraries(${PROJECT_NAME}_Util PUBLIC spdlog::spdlog)
set_target_properties(${PROJECT_NAME}_Util PROPERTIES CXX_STANDARD 20)

# ---- Create an installable target ----
# this allows users to install and find the library via `find_package()`.
packageProject(
  NAME ${PROJECT_NAME}_Util
  VERSION ${PROJECT_VERSION}
  NAMESPACE ${PROJECT_NAME}
  BINARY_DIR ${PROJECT_BINARY_DIR}
  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/greeter/util
  INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}/greeter/util
  COMPATIBILITY SameMajorVersion
  DEPENDENCIES "fmt 11.0.2;spdlog 1.14.1"
)
