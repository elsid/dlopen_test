cmake_minimum_required(VERSION 3.16.0)

project(dlopen_test CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(registry SHARED registry.cpp object.cpp plugin.cpp)

add_library(plugin_a SHARED plugin_a.cpp)
target_link_libraries(plugin_a registry)

add_executable(dlopen_test main.cpp)
target_link_libraries(dlopen_test registry)

option(DLOPEN_TEST_ENABLE_EXPORTS "Add ENABLE_EXPORTS to the dlopen_test" OFF)

if(DLOPEN_TEST_ENABLE_EXPORTS)
    set_target_properties(dlopen_test PROPERTIES ENABLE_EXPORTS ON)
endif()
