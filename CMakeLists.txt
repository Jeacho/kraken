cmake_minimum_required(VERSION 3.9)
project(kraken VERSION 1.0.1 DESCRIPTION "kraken programming language" LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

file(GLOB Sources "src/driver.cpp")

include_directories(inc)
add_subdirectory(src)

add_executable(kraken ${Sources})
target_link_libraries(kraken
    root_dir
    filesystem_dir
)
