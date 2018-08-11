cmake_minimum_required(VERSION 3.2)
project("Kraken Compiler")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(EXT_DIR "ext")
set(BIN_DIR "bin")
set(INC_DIR "inc")
set(SRC_DIR "src")
set(TEST_DIR "test")

set(SRC ${SRC_DIR}/driver.cpp)

set(EXECUTABLE_NAME "kkc")

add_subdirectory(${EXT_DIR}/gtest-1.7.0)
add_subdirectory(${SRC_DIR})
add_subdirectory(${TEST_DIR})
include_directories(${INC_DIR})

add_executable(${EXECUTABLE_NAME} ${SRC})
target_link_libraries(${EXECUTABLE_NAME} kraken)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${BIN_DIR})
