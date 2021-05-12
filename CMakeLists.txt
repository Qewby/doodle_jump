cmake_minimum_required(VERSION 3.19)
project(doodle_jump)

set(CMAKE_CXX_STANDARD 14)
set (SOURCE_FILES main.cpp Window.cpp Window.h Game.cpp Game.h Renderer.cpp
        Renderer.h IDrawable.h Doodle.cpp Doodle.h EventHandler.cpp EventHandler.h)

find_package(SDL2 REQUIRED)
include_directories(doodle_jump ${SDL2_INCLUDE_DIRS})

add_executable(doodle_jump ${SOURCE_FILES})
target_link_libraries(doodle_jump ${SDL2_LIBRARIES})