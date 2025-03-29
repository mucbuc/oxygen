project(example)
cmake_minimum_required(VERSION 3.27)

add_executable(example 
    src/example.cpp
)
add_subdirectory(lib/oxygen)
add_subdirectory(lib/asserter)

set_target_properties(example PROPERTIES
    CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
	COMPILE_WARNING_AS_ERROR ON
)


target_link_libraries(example PRIVATE
    oxygen
)

include_directories(PUBLIC SYSTEM lib)