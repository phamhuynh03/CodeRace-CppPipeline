
add_executable(application main.cpp code_with_bugs.cpp crc32.cpp)
set_target_properties(application PROPERTIES LINKER_LANGUAGE CXX)
add_fuzz_test(my_fuzz_test_1 my_fuzz_test_1.cpp)