cmake_minimum_required(VERSION 3.14...3.22)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Project ----

# Note: update this to your new project's name and version
project(
  Greeter
  VERSION 1.0
  LANGUAGES CXX
)

# ---- Include guards ----
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
    "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info
include(cmake/CPM.cmake)

# PackageProject.cmake will be used to make our target installable
CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.8.0")
CPMAddPackage(
  NAME fmt
  GIT_TAG 11.0.2
  GITHUB_REPOSITORY fmtlib/fmt
  OPTIONS "FMT_INSTALL YES" # create an installable target
)

CPMAddPackage(
  NAME spdlog
  GITHUB_REPOSITORY gabime/spdlog
  GIT_TAG v1.14.1
  OPTIONS "SPDLOG_FMT_EXTERNAL YES" "SPDLOG_INSTALL YES"
)

add_subdirectory(source/util)
add_subdirectory(source/net)
