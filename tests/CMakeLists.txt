project(testhttpserver)

find_package(Qt5 REQUIRED COMPONENTS Core Network Widgets Test)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

include_directories(${TEST_SOURCE_DIR}/)

set(SOURCESTEST ${CMAKE_SOURCE_DIR}/tests/testhttpserver.h
    ${CMAKE_SOURCE_DIR}/tests/testhttpserver.cpp
    ${CMAKE_SOURCE_DIR}/tests/main.cpp
)

add_executable(testhttpserver ${SOURCESTEST})

target_link_libraries(testhttpserver httpserverlib Qt5::Test)
