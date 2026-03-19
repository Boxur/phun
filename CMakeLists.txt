cmake_minimum_required (VERSION "3.10")

project("phun")

add_executable(phun
	"src/main.cpp"
)

target_include_directories(phun PRIVATE "include")