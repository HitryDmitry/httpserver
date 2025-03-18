# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/httpserver_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/httpserver_autogen.dir/ParseCache.txt"
  "CMakeFiles/httpserverlib_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/httpserverlib_autogen.dir/ParseCache.txt"
  "httpserver_autogen"
  "httpserverlib_autogen"
  "tests/CMakeFiles/testhttpserver_autogen.dir/AutogenUsed.txt"
  "tests/CMakeFiles/testhttpserver_autogen.dir/ParseCache.txt"
  "tests/testhttpserver_autogen"
  )
endif()
