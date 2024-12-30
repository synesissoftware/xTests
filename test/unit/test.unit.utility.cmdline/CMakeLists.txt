list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	"writable-strings"
	"write-strings"
)
define_automated_test_program(test.unit.utility.cmdline entry.cpp)
