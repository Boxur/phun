cmake_minimum_required (VERSION 3.14)

set(CMAKE_CXX_STANDARD			 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS		OFF)

file(GLOB_RECURSE LIB CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

if(LIB)
    add_library(Math STATIC "${LIB}")    
endif()

target_include_directories(Math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")