if(MSVC)

	if(MSVC_VERSION GREATER 1700)

		list(APPEND X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED 4459)
	endif()
endif(MSVC)
define_automated_test_program(example.cpp.temp_directory main.cpp)
