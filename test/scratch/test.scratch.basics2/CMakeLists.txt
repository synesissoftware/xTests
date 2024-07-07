
add_executable(test.scratch.basics2
	test.scratch.basics2.cpp
)

target_link_libraries(test.scratch.basics2
	PRIVATE
		xTests.core
)

target_compile_options(test.scratch.basics2 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

