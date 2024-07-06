
add_executable(example.c.factorial
	example.c.factorial.c
)

target_link_libraries(example.c.factorial
	PRIVATE
		STLSoft::STLSoft
		xTests.core
)

target_compile_options(example.c.factorial PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

