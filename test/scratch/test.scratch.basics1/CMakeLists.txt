
add_executable(test.scratch.basics1
    test.scratch.basics1.c
)

target_link_libraries(test.scratch.basics1
    xTests.core
)

target_compile_options(test.scratch.basics1 PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall -Wextra -pedantic>
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)

