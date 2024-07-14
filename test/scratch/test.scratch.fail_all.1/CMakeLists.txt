
add_executable(test.scratch.fail_all.1
	test.scratch.fail_all.1.cpp
)

target_link_libraries(test.scratch.fail_all.1
	PRIVATE
		core
)

target_compile_options(test.scratch.fail_all.1 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

