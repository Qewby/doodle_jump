cmake_minimum_required(VERSION 3.19)
project(doodle_jump)
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)
find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 14)
set (SOURCE_FILES src/main.cpp src/Window.cpp src/Window.h src/Game.cpp src/Game.h src/Renderer.cpp
        src/Renderer.h src/IDrawable.h src/Doodle.cpp src/Doodle.h src/EventListener.cpp src/EventListener.h src/platforms/Platform.h src/platforms/SimplePlatform.cpp src/platforms/SimplePlatform.h src/platforms/Platform.cpp src/Field.cpp src/Field.h src/CollisionHandler.cpp src/CollisionHandler.h src/platforms/PlatformFactory.cpp src/platforms/PlatformFactory.h src/platforms/EmptyPlatform.cpp src/platforms/EmptyPlatform.h src/ScoreLine.cpp src/ScoreLine.h src/StartMenu.cpp src/StartMenu.h src/EndGameMenu.cpp src/EndGameMenu.h src/platforms/MovingPlatform.cpp src/platforms/MovingPlatform.h src/platforms/OneTimePlatform.cpp src/platforms/OneTimePlatform.h src/platforms/OneTimeMovingPlatform.cpp src/platforms/OneTimeMovingPlatform.h)
set (PROJECT_NAME doodle_jump)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
        )
add_dependencies(${PROJECT_NAME} copy_assets)

