
add_executable(test.scratch.setup.fail
    test.scratch.setup.fail.c
)

target_link_libraries(test.scratch.setup.fail
    xTests.core
)

target_compile_options(test.scratch.setup.fail PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall -Wextra -pedantic>
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)

