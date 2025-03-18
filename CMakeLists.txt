cmake_minimum_required(VERSION 3.21)
project(HTTPServer)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)


find_package(Qt5 REQUIRED COMPONENTS Core Network Widgets)

set(SOURCES ${CMAKE_SOURCE_DIR}/include/httpserver.h
        ${CMAKE_SOURCE_DIR}/source/httpserver.cpp
)

add_library(httpserverlib ${SOURCES})
target_link_libraries(httpserverlib Qt5::Core Qt5::Network Qt5::Widgets)
target_include_directories(httpserverlib PUBLIC ${CMAKE_SOURCE_DIR}/include)
add_executable(httpserver ${CMAKE_SOURCE_DIR}/source/main.cpp)

target_link_libraries(httpserver httpserverlib)

enable_testing (true)
add_test (NAME MyTest COMMAND testhttpserver)
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
