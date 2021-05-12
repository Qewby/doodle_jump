cmake_minimum_required(VERSION 3.19)
project(doodle_jump)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(doodle_jump ${SDL2_INCLUDE_DIRS})

add_executable(doodle_jump main.cpp Window.cpp Window.h Game.cpp Game.h Renderer.cpp Renderer.h)
target_link_libraries(doodle_jump ${SDL2_LIBRARIES})