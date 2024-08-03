
add_executable(test.scratch.integer_comparisons.c
	test.scratch.integer_comparisons.c.c
)

target_link_libraries(test.scratch.integer_comparisons.c
	PRIVATE
		core
)

target_compile_options(test.scratch.integer_comparisons.c PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

