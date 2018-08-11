cmake_minimum_required(VERSION 3.2)
project(test_runner)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES test_entry.cpp
    adt/either_test.cpp
    filesystem/path_test.cpp
    filesystem/io_test.cpp
    memory/buffer_test.cpp
    support/console_test.cpp
)

include_directories(../${INC_DIR})
include_directories(../${EXT_DIR}/gtest-1.7.0/include)

add_executable(test_runner ${SOURCE_FILES})
target_link_libraries(test_runner kraken gtest)

install(TARGETS test_runner DESTINATION ${BIN_DIR})
