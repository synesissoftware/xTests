list(APPEND X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	4459
)
define_automated_test_program(test.component.temp_directory entry.cpp)
