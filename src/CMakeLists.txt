
add_library(xTests.core xtests.core.cpp)

if (APPLE)

    message("-- -- adding '/usr/local/include' to include-directories for 'src'")

    include_directories("/usr/local/include")
endif()

#[====[
target_link_libraries(xTests.core STLSoft::STLSoft)
]====]

# for now, we just include xtests.h, as it's not clear how to use the PUBLIC_HEADER mechanism to install files into subdirectories (such as xtests/util/temp_file.hpp)
set(XTESTS_PUBLIC_HEADERS
    # "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h"
    # "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/test/util/compiler_warnings_suppression.first_include.h"
    # "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/test/util/compiler_warnings_suppression.last_include.h"
    # "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/util/filesystem_exception.hpp"
    # "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/util/temp_directory.hpp"
    # "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/util/temp_file.hpp"
)

set_target_properties(xTests.core PROPERTIES
    OUTPUT_NAME "xtests.core"
    PUBLIC_HEADER "${XTESTS_PUBLIC_HEADERS}"
)

target_include_directories(xTests.core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_options(xTests.core PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

# ##########################################################
# install

install(TARGETS xTests.core
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/xtests
)

# ############################## end of file ############################# #

