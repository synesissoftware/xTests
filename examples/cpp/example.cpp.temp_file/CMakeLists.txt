
add_executable(example.cpp.temp_file
	example.cpp.temp_file.cpp
)

target_link_libraries(example.cpp.temp_file
	PRIVATE
		core
)

target_compile_options(example.cpp.temp_file PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4

		/wd4459
	>
)

