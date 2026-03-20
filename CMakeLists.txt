cmake_minimum_required (VERSION "3.13")

project("phun")
set(CMAKE_CXX_STANDARD			 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS		OFF)

file(GLOB_RECURSE OBJECT_LIB CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/Object/*.cpp")

add_library(object STATIC "${OBJECT_LIB}")
target_include_directories(object PRIVATE "include/Object")

add_executable(exec src/main.cpp)
target_include_directories(exec PRIVATE "include/Object")
target_link_libraries(exec object)