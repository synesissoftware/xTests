add_executable (test.scratch.basics1 test.scratch.basics1.c)
target_link_libraries (test.scratch.basics1 xTests STLSoft::STLSoft)
add_test(NAME test.scratch.basics1 COMMAND ./test.scratch.basics1)
SET_SOURCE_FILES_PROPERTIES(test.scratch.basics1.c PROPERTIES LANGUAGE CXX)

