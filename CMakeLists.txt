cmake_minimum_required (VERSION 3.14)

project("phun")

include(FetchContent)

set(CMAKE_CXX_STANDARD			 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS		OFF)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE OBJECT_LIB CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Object/src/*.cpp")

add_library(object STATIC "${OBJECT_LIB}")
target_include_directories(object PRIVATE "Object/include")

file(GLOB_RECURSE MATH_LIB CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Math/src/*.cpp")

add_library(math STATIC "${MATH_LIB}")
target_include_directories(math PRIVATE "Math/include")

add_executable(exec main/main.cpp)
target_include_directories(exec PRIVATE "Object/include" "Math/include")
target_link_libraries(exec object math SFML::Graphics)