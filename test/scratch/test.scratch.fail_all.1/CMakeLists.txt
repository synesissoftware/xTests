add_executable (test.scratch.fail_all.1 test.scratch.fail_all.1.cpp)
target_link_libraries (test.scratch.fail_all.1 xTests STLSoft::STLSoft)
add_test (test.scratch.fail_all.1 ./test.scratch.fail_all.1)

