
set(CORE_SRCS
	xtests.core.cpp
)

add_library(xTests.core
	${CORE_SRCS}
)

if (APPLE)

	message("-- -- adding '/usr/local/include' to include-directories for 'src'")

	include_directories("/usr/local/include")
endif()

if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

	message(FATAL_ERROR "Use of CMake on Windows not currently supported")
endif(WIN32)


# specify the primary public headers for the library, which controls whether
# they'll be installed
#
# NOTE: it is not yet known (to me, at least) how to include additional
# header files from sub-directories, so this is done below in an additional
# `install()` step
set(CORE_PUBLIC_HEADERS
	"${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h"
)

set_target_properties(xTests.core PROPERTIES
	OUTPUT_NAME "xtests.core"
	PUBLIC_HEADER "${CORE_PUBLIC_HEADERS}"
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
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME_LOWER}
)

# for now, we just include xtests.h, as it's not clear how to use the
# PUBLIC_HEADER mechanism to install files into subdirectories (such as xtests/util/temp_file.hpp)


# additional headers into specific sub-directories
install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/util
	DESTINATION include/${PROJECT_NAME_LOWER}
	FILES_MATCHING
	PATTERN "*.h*"
)


# ############################## end of file ############################# #

