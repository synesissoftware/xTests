
set(CORE_SRC_DIR ../../src)

message("CORE_SRC_DIR=${CORE_SRC_DIR}")

set(CORE_SRCS
	${CORE_SRC_DIR}/xtests.core.cpp
)

add_library(xtests ${CORE_SRCS})


target_compile_options(xtests PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall -Wextra -pedantic>
    $<$<CXX_COMPILER_ID:MSVC>: /WX /W4>
)

