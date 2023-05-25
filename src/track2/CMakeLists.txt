cmake_minimum_required(VERSION 3.1)

project(CodeRace VERSION 1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-w")

add_executable(application main.cpp code_with_bugs.cpp crc32.cpp)
set_target_properties(application PROPERTIES LINKER_LANGUAGE CXX)

