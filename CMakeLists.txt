cmake_minimum_required(VERSION 3.27)
project(oxygen_lib)

add_library(oxygen STATIC src/oxygen.hpp)

set_target_properties(oxygen PROPERTIES
    CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
	COMPILE_WARNING_AS_ERROR ON
)

target_sources(oxygen PRIVATE
    src/oxygen.cpp
)

# hardcoded test sucks, make sure to fix
include_directories(PUBLIC SYSTEM test/lib)
