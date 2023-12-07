
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

project(xTests)


include_directories(include)

if(NOT DEFINED STLSOFT AND NOT DEFINED ENV{STLSOFT})

    message(FATAL_ERROR "This build requires STLSOFT be defined as a CMake variable or an environment variable")
else()

    if(DEFINED STLSOFT)
        message("-- STLSOFT provided as CMake variable with value ${STLSOFT}")

        set(STLSOFT_INCLUDE_DIR ${STLSOFT}/include)
    else()
        message("-- STLSOFT provided as environment variable with value $ENV{STLSOFT}")

        set(STLSOFT_INCLUDE_DIR $ENV{STLSOFT}/include)
    endif()
endif()

include_directories(${STLSOFT_INCLUDE_DIR})


if(UNIX)

    add_definitions(-DUNIX)
    add_definitions(-Dunix)
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
    FILES_MATCHING
    PATTERN "*.h*"
    PATTERN "internal" EXCLUDE
)

