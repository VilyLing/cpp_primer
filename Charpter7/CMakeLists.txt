cmake_minimum_required(VERSION 3.10)

project(Chapter7)

set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(src SrcFiles)

add_executable(Chapter7 ${SrcFiles})

include_directories(${PROJECT_SOURCE_DIR}/inc)
