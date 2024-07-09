
add_executable(example.c.runner
	example.c.runner.c
)

target_link_libraries(example.c.runner
	PRIVATE
		xTests.core
)

target_compile_options(example.c.runner PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

