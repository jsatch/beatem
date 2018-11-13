cmake_minimum_required(VERSION 3.0.0)
project(beatem VERSION 0.1.0)

include(CTest)
enable_testing()

if(WIN32)
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/Users/Hernan/Development/games/beatem/cmake")
else()
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/Users/hernan/development/gamedev/GameEngine/Framework/cmake")
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED >=2.0.0)

include_directories(include ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
link_directories(libs)

add_executable(beatem
	src/Components/PositionComponent.cpp
	src/Components/SpriteComponent.cpp
	src/Components/AnimatedSpriteComponent.cpp
	src/Entities/BackgroundEntity.cpp
	src/Entities/ScottEntity.cpp
	src/TestScreen.cpp
	src/beatemup.cpp)

target_link_libraries(beatem jsgaen.lib ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
