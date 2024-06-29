
add_executable(test.component.temp_file
	test.component.temp_file.cpp
)

target_link_libraries(test.component.temp_file
	xTests.core
)

target_compile_options(test.component.temp_file PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)
