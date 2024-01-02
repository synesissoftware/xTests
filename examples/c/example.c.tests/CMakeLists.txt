
add_executable(example.c.tests
    example.c.tests.c
)

target_link_libraries(example.c.tests
    xTests.core
)

target_compile_options(example.c.tests PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall -Wextra -pedantic>
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)

