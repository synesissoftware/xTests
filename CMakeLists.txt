
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

project(xTests)

# TODO: should change this to depend on an STLSoft CMake-project
if(NOT DEFINED ENV{STLSOFT})

	message(FATAL_ERROR "This build requires the environment variable STLSOFT be defined")
else()

	set(STLSOFT_INCLUDE_DIR $ENV{STLSOFT}/include)

	message("including \$STLSOFT/include - '${STLSOFT_INCLUDE_DIR}'")
endif()

include_directories(${STLSOFT_INCLUDE_DIR})


if(UNIX)

    add_definitions(-DUNIX)
endif()

if(WIN32)

    message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif()


add_subdirectory(./projects/core)

add_subdirectory(./examples/c/example.c.runner)
add_subdirectory(./examples/c/example.c.tests)

add_subdirectory(./test/scratch/test.scratch.basics1)
add_subdirectory(./test/scratch/test.scratch.basics2)
add_subdirectory(./test/scratch/test.scratch.fail_all.1)
add_subdirectory(./test/scratch/test.scratch.setup.fail)
add_subdirectory(./test/scratch/test.scratch.string_slices.c)
add_subdirectory(./test/scratch/test.scratch.temp_directory)
add_subdirectory(./test/scratch/test.scratch.temp_file)
add_subdirectory(./test/scratch/test.scratch.verbosity_levels)


install(
	TARGETS xTests
	)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h*"
	)

