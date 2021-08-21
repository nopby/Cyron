cmake_minimum_required(VERSION 3.0.0)

# Name our project
project(Cyron)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Enable warnings
add_compile_options(-Wall -Wextra -Wpedantic)

# Default to a release build
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

#
# Cyron
#

# Define the Cyron static library
file(GLOB_RECURSE cyron_sources RELATIVE ${PROJECT_SOURCE_DIR} "Cyron/src/**.cpp")
add_library(Cyron STATIC
  ${cyron_sources}
)

target_compile_definitions(Cyron PRIVATE CYRON_PLATFORM_LINUX)

# Include directories for Cyron
target_include_directories(Cyron PUBLIC
  Cyron/src/
)

#
# Sandbox
#

# Include directories for the sandbox application


# Define sandbox application
file(GLOB_RECURSE sandbox_sources RELATIVE ${PROJECT_SOURCE_DIR} "Sandbox/src/**.cpp" )
add_executable(Sandbox ${sandbox_sources})

target_include_directories(Sandbox PUBLIC
    Cyron/src/
)

# Link sandbox with the Cyron library
target_link_libraries(Sandbox PUBLIC Cyron)