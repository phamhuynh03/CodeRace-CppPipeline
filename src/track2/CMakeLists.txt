<<<<<<< HEAD
cmake_minimum_required(VERSION 3.16)
=======
cmake_minimum_required(VERSION 3.1)
>>>>>>> 492b906104cc8db99ca5eba5a851eddeb5552ca4

project(CodeRace VERSION 1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

<<<<<<< HEAD
enable_testing()
find_package(cifuzz)
enable_fuzz_testing()
=======
>>>>>>> 492b906104cc8db99ca5eba5a851eddeb5552ca4
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-w")

add_executable(application main.cpp code_with_bugs.cpp crc32.cpp)
set_target_properties(application PROPERTIES LINKER_LANGUAGE CXX)
<<<<<<< HEAD
add_fuzz_test(my_fuzz_test_1 my_fuzz_test_1.cpp)
=======

>>>>>>> 492b906104cc8db99ca5eba5a851eddeb5552ca4
