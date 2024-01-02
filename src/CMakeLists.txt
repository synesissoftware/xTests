
add_library(xTests xtests.core.cpp)

if (APPLE)

message("-- -- adding '/usr/local/include' to include-directories for 'src'")

    include_directories("/usr/local/include")
endif()

#[====[
target_link_libraries(xTests STLSoft::STLSoft)
]====]

# for now, we just include xtests.h, as it's not clear how to use the PUBLIC_HEADER mechanism to install files into subdirectories (such as xtests/util/temp_file.hpp)
set(XTESTS_PUBLIC_HEADERS
    "${CMAKE_SOURCE_DIR}/include/xtests/xtests.h"
)

set_target_properties(xTests PROPERTIES
    OUTPUT_NAME "xtests.core"
    PUBLIC_HEADER "${XTESTS_PUBLIC_HEADERS}"
)

target_include_directories(xTests PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_options(xTests PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

# ##########################################################
# install

install(TARGETS xTests
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/xtests
)

# ############################## end of file ############################# #

