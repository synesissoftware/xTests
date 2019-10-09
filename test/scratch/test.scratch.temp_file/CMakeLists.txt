if(WIN32)
  add_executable (test.scratch.temp_file test.scratch.temp_file.cpp)
  add_dependencies (test.scratch.temp_file STLSoft::STLSoft)
  target_link_libraries (test.scratch.temp_file xtests.core)
  add_test (test.scratch.temp_file ./test.scratch.temp_file)
endif()

