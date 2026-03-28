cmake_minimum_required (VERSION 3.14)

set(CMAKE_CXX_STANDARD			 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS		OFF)

file(GLOB_RECURSE LIB CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

if(LIB)
    add_library(Object STATIC "${LIB}")    
endif()

target_include_directories(Object PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(Math)

target_link_libraries(Object PUBLIC Math)