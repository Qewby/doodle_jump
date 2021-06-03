cmake_minimum_required(VERSION 3.19)
project(doodle_jump)
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)
find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set (SOURCE_FILES main.cpp Window.cpp Window.h Game.cpp Game.h Renderer.cpp
        Renderer.h IDrawable.h Doodle.cpp Doodle.h EventListener.cpp EventListener.h platforms/Platform.h platforms/SimplePlatform.cpp platforms/SimplePlatform.h platforms/Platform.cpp Field.cpp Field.h CollisionHandler.cpp CollisionHandler.h platforms/PlatformFactory.cpp platforms/PlatformFactory.h platforms/EmptyPlatform.cpp platforms/EmptyPlatform.h ScoreLine.cpp ScoreLine.h StartMenu.cpp StartMenu.h EndGameMenu.cpp EndGameMenu.h)
set (PROJECT_NAME doodle_jump)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
