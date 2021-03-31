
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

project(xtests)

include_directories(include)

if (NOT DEFINED ENV{STLSOFT})

	message(FATAL_ERROR "This build requires the environment variable STLSOFT be defined")
else()

	set(STLSOFT_INCLUDE_DIR $ENV{STLSOFT}/include)

	#message(FATAL_ERROR "STLSOFT_INCLUDE_DIR=${STLSOFT_INCLUDE_DIR}")

	message("including \$STLSOFT/include - '${STLSOFT_INCLUDE_DIR}'")
endif()

include_directories(${STLSOFT_INCLUDE_DIR})

add_subdirectory(./projects/core)

install(TARGETS xtests)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*"
)

