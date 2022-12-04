cmake_minimum_required(VERSION 3.2)

project(outcome)

message("Generating for system " ${CMAKE_SYSTEM_key})

set(CONAN_DISABLE_CHECK_COMPILER true)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 20)

include_directories(include/)
include_directories(include/outcome/)
set(CMAKE_EXPORT_NO_PACKAGE_REGISTRY OFF)

set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)

file(GLOB SOURCES src/*.cpp)

add_library(outcome_lib STATIC ${SOURCES})
add_executable(outcome ${SOURCES})
target_link_libraries(outcome ${CONAN_LIBS})

set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -ggdb -pedantic -fsanitize=address -fno-omit-frame-pointer -O2 "
)
