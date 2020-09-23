cmake_minimum_required(VERSION 3.10)

project(WimbleBall)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

find_package(Curses REQUIRED)
find_package(Threads REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})


add_executable(
    wimble_ball
    src/clock.cpp
    src/field.cpp
    src/football.cpp
    src/main.cpp
    src/player.cpp
    src/pauseable_timer.cpp
    src/score.cpp
    src/team.cpp
)

target_include_directories(
    wimble_ball PUBLIC
    include
)

target_link_libraries(
    wimble_ball
    ${CURSES_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
)