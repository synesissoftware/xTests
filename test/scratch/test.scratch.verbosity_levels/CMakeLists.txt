if(WIN32)
  add_executable (test.scratch.verbosity_levels test.scratch.verbosity_levels.cpp)
  add_dependencies (test.scratch.verbosity_levels STLSoft::STLSoft)
  target_link_libraries (test.scratch.verbosity_levels xtests.core)
  add_test (test.scratch.verbosity_levels ./test.scratch.verbosity_levels)
endif()


