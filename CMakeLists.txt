cmake_minimum_required(VERSION 3.0)
project(Snake C CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-gcc)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(${PROJECT_NAME} common/src/main.cpp common/src/Player.cpp common/src/Player.h common/src/Audio.cpp common/src/Audio.h common/src/utility.h common/src/utility.cpp common/src/window.h common/src/window.cpp common/src/GAMESTATE.h)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(Snake PRIVATE ${raylib_INCLUDE_DIRS})
target_link_libraries(Snake PRIVATE ${raylib_LIBRARIES})
target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/common/assets/") # Set the asset path macro to the absolute path on the dev machine
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets/") # Set the asset path macro in release mode

# libs/raylib/src/libraylib.a  libs/raylib/src/external/glfw/src/libglfw3.a  -Wl,-Bstatic  -lrt  -Wl,-Bdynamic  -lm  -ldl  -lX11  -lm  -lpthread  -lGL  -lGLU
