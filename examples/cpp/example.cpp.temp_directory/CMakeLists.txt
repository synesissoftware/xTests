
add_executable(example.cpp.temp_directory
	example.cpp.temp_directory.cpp
)

target_link_libraries(example.cpp.temp_directory
	xTests.core
)

target_compile_options(example.cpp.temp_directory PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall -Wextra -pedantic>
	$<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)

