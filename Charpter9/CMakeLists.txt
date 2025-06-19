cmake_minimum_required(VERSION 3.20)
project(Chapter9 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

aux_source_directory(src SrcFiles)
add_executable(app Main.cpp ${SrcFiles})

target_include_directories(app PUBLIC ${PROJECT_SOURCE_DIR}/inc)
