cmake_minimum_required(VERSION 3.0)
project(Snake C CXX)

set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-gcc)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(${PROJECT_NAME} src/main.cpp src/Player.cpp src/Player.h)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(Snake PRIVATE ${raylib_INCLUDE_DIRS})
target_link_libraries(Snake PRIVATE ${raylib_LIBRARIES})
target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets/") # Set the asset path macro in release mode

# libs/raylib/src/libraylib.a  libs/raylib/src/external/glfw/src/libglfw3.a  -Wl,-Bstatic  -lrt  -Wl,-Bdynamic  -lm  -ldl  -lX11  -lm  -lpthread  -lGL  -lGLU


# cmake_minimum_required(VERSION 3.15)
# project(Snake C CXX)

# # Définir les options de compilation
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# # Configuration globale de raylib
# set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
# set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
# set(USE_EXTERNAL_GLFW OFF CACHE BOOL "" FORCE)
# set(OPENGL_VERSION "3.3" CACHE STRING "" FORCE)
# set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# # Fonction pour configurer le projet pour une plateforme spécifique
# function(configure_platform PLATFORM)
#     if(${PLATFORM} STREQUAL "Windows")
#         set(CMAKE_C_COMPILER /usr/bin/x86_64-w64-mingw32-gcc)
#         set(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-g++)
#         set(CMAKE_SYSTEM_NAME Windows)
#         set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)
#         set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#         set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#         set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#         set(PLATFORM_LIBS winmm gdi32 opengl32)
        
#         # Configuration spécifique pour raylib Windows
#         set(PLATFORM_CPP "PLATFORM_DESKTOP" CACHE STRING "" FORCE)
#     else()
#         set(CMAKE_C_COMPILER gcc)
#         set(CMAKE_CXX_COMPILER g++)
#         set(PLATFORM_LIBS GL m pthread dl rt)
        
#         # Configuration spécifique pour raylib Linux (DRM)
#         set(PLATFORM_CPP "PLATFORM_DRM" CACHE STRING "" FORCE)
#         add_definitions(-DPLATFORM_DRM)
#     endif()

#     # Désactiver X11 et Wayland pour toutes les plateformes
#     set(USE_WAYLAND OFF CACHE BOOL "" FORCE)
#     set(USE_X11 OFF CACHE BOOL "" FORCE)

#     # Configurer raylib
#     add_subdirectory(libs/raylib ${CMAKE_BINARY_DIR}/${PLATFORM}/raylib)

#     # Créer l'exécutable
#     add_executable(Snake_${PLATFORM} src/main.cpp src/Player.cpp)
#     set_target_properties(Snake_${PLATFORM} PROPERTIES
#         RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${PLATFORM})

#     # Lier les bibliothèques
#     target_link_libraries(Snake_${PLATFORM} PRIVATE raylib ${PLATFORM_LIBS})

#     # Définir le chemin des assets
#     target_compile_definitions(Snake_${PLATFORM} PUBLIC 
#         ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

#     if(${PLATFORM} STREQUAL "Windows")
#         # Options de liaison statique pour MinGW
#         target_link_options(Snake_${PLATFORM} PRIVATE -static-libgcc -static-libstdc++)
#     endif()
# endfunction()

# # Configurer pour Windows
# configure_platform("Windows")

# # Configurer pour Linux
# configure_platform("Linux")


# # # cmake_minimum_required(VERSION 3.0)
# # # project(Snake CXX)

# # # set(CMAKE_CXX_STANDARD 20)
# # # set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # # # Adding Raylib
# # # include(FetchContent)
# # # set(FETCHCONTENT_QUIET FALSE)
# # # set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
# # # set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

# # # FetchContent_Declare(
# # #     raylib
# # #     GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
# # #     GIT_TAG "master"
# # #     GIT_PROGRESS TRUE
# # # )

# # # FetchContent_MakeAvailable(raylib)

# # # # Adding our source files
# # # file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
# # # set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

# # # # Declaring our executable
# # # add_executable(${PROJECT_NAME})
# # # target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
# # # target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
# # # target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# # # # Setting ASSETS_PATH
# # # # target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
# # # target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets/") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable