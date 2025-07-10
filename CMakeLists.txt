cmake_minimum_required (VERSION 3.8)
set(CXX_STANDARD_REQUIRED 17)
project ("BrokenEyes")

set(
	SRC_FILES
	"src/main.cpp"
	"src/utils.cpp"
	"src/utils.hpp"
)

add_executable(${PROJECT_NAME} ${SRC_FILES})