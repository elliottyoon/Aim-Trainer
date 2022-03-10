# CMake generated Testfile for 
# Source directory: C:/Users/Graham/Documents/GitHub/Aim-Trainer
# Build directory: C:/Users/Graham/Documents/GitHub/Aim-Trainer/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Test_model_test "model_test")
set_tests_properties(Test_model_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Graham/Documents/GitHub/Aim-Trainer/.cs211/cmake/211commands.cmake;90;add_test;C:/Users/Graham/Documents/GitHub/Aim-Trainer/CMakeLists.txt;24;add_test_program;C:/Users/Graham/Documents/GitHub/Aim-Trainer/CMakeLists.txt;0;")
subdirs(".cs211/lib/catch")
subdirs(".cs211/lib/ge211")
