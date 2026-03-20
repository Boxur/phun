cmake_minimum_required (VERSION "3.13")

project("phun")
set(CMAKE_CXX_STANDARD			 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS		OFF)

add_library(phun STATIC src/ObjectBase.cpp src/ObjectManager.cpp)
target_include_directories(phun PRIVATE "include")

add_executable(exec src/main.cpp)
target_include_directories(exec PRIVATE "include")
target_link_libraries(exec phun)