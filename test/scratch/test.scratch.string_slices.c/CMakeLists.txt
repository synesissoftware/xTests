
add_executable(test.scratch.string_slices.c
	test.scratch.string_slices.c.c
)

target_link_libraries(test.scratch.string_slices.c
	PRIVATE
		xTests.core
)

target_compile_options(test.scratch.string_slices.c PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4

		/wd4130
	>
)

