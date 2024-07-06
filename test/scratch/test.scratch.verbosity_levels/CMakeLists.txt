
add_executable(test.scratch.verbosity_levels
	test.scratch.verbosity_levels.cpp
)

target_link_libraries(test.scratch.verbosity_levels
	PRIVATE
		STLSoft::STLSoft
		xTests.core
)

target_compile_options(test.scratch.verbosity_levels PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

