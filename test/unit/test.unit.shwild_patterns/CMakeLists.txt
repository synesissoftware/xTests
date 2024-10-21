
add_executable(test.unit.shwild_patterns
	test.unit.shwild_patterns.cpp
)

target_link_libraries(test.unit.shwild_patterns
	PRIVATE
		core
		shwild::core
)

target_compile_options(test.unit.shwild_patterns PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
		-Wno-unused-but-set-variable
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

