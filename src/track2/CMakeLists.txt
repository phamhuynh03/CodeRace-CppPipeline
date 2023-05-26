cmake_minimum_required(VERSION 3.16)

project(CodeRace VERSION 1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

enable_testing()
find_package(cifuzz NO_SYSTEM_ENVIRONMENT_PATH)
enable_fuzz_testing()

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-w")

add_executable(application main.cpp code_with_bugs.cpp crc32.cpp)
set_target_properties(application PROPERTIES LINKER_LANGUAGE CXX)
add_fuzz_test(my_fuzz_test_1 my_fuzz_test_1.cpp)