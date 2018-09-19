cmake_minimum_required(VERSION 3.2)
project(kraken C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SRC
    filesystem/io.cpp
    memory/buffer.cpp
    lexer/lexer.cpp
    lexer/token.cpp
    support/console.cpp
    support/error.cpp
)

include_directories(../${INC_DIR})

add_library(kraken SHARED STATIC ${SRC})

install(TARGETS kraken DESTINATION ../${BIN_DIR})
