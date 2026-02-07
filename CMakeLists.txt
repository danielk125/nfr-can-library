cmake_minimum_required(VERSION 3.10)

add_library(nfr_canlib STATIC
    src/MCP2515.cpp
    src/virtual_timer.cpp
)

target_include_directories(nfr_canlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)