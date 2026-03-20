cmake_minimum_required (VERSION "3.13")

project("phun")
set(CMAKE_CXX_STANDARD			 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS		OFF)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(phun "${MY_SOURCES}")
target_include_directories(phun PRIVATE "include")