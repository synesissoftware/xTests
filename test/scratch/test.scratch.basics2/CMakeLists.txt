add_executable(test.scratch.basics2 test.scratch.basics2.cpp)
target_link_libraries(test.scratch.basics2 xTests STLSoft::STLSoft)
add_test(NAME test.scratch.basics2 COMMAND ./test.scratch.basics2)

