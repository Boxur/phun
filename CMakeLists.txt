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

function(addLib executable libDir)

file(GLOB_RECURSE LIB CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${libDir}/src/*.cpp")

if(LIB)
    add_library("${libDir}" STATIC "${LIB}")
    target_include_directories("${libDir}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/${libDir}/include")
    
    target_link_libraries("${executable}" "${libDir}")
endif()

target_include_directories("${executable}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/${libDir}/include")

endfunction()

add_executable(exec main/main.cpp)

addLib(exec Object)

addLib(exec Math)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(exec raylib)


