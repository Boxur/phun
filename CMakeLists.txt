cmake_minimum_required (VERSION 3.14)

project("phun")

include(FetchContent)

set(CMAKE_CXX_STANDARD			 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS		OFF)

FetchContent_Declare(
	raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE	
)
FetchContent_MakeAvailable(raylib)

add_executable(exec main/main.cpp)

add_subdirectory(Object)

target_link_libraries(exec Object)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(exec raylib)


