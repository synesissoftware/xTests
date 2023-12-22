
SET (CORE_SRC_DIR ../../src)

FILE (GLOB CORE_SRCS
    ${CORE_SRC_DIR}/*.cpp
)

add_library(xTests ${CORE_SRCS})

target_compile_options(xTests PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
		-Wno-deprecated-declarations
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

