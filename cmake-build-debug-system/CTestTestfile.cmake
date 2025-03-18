# CMake generated Testfile for 
# Source directory: /home/dmitry/study/httpserver
# Build directory: /home/dmitry/study/httpserver/cmake-build-debug-system
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[MyTest]=] "/home/dmitry/study/httpserver/cmake-build-debug-system/tests/testhttpserver")
set_tests_properties([=[MyTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/dmitry/study/httpserver/CMakeLists.txt;22;add_test;/home/dmitry/study/httpserver/CMakeLists.txt;0;")
subdirs("tests")
