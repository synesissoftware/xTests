# xTests {#mainpage}

**xTests** is a small, lightweight, portable unit- and component-test
framework for **C** and **C++**. It is designed to be simple enough to
bundle with other libraries and exercise them in their automated builds.


## Components

| Module | Header | Summary |
| ------ | ------ | ------- |
| @ref group__xtests__test_runner_functions | `<xtests/xtests.h>` | Start/end runners, print results, command-line helpers |
| @ref group__xtests__test_case_functions | `<xtests/xtests.h>` | Register and run named test cases |
| @ref group__xtests__test_assertion_functions | `<xtests/xtests.h>` | Typed assertion macros (`XTESTS_TEST_*`) |
| @ref group__xtests__utiliy_functions | `<xtests/xtests.h>` | Utility helpers used by the assertion layer |
| @ref group__xtests__misc | `<xtests/xtests.h>` | Miscellaneous constructs (verbosity, floating-point scope, …) |
| Terse API | `<xtests/terse-api.h>` | Short aliases such as `TEST_INT_EQ` |
| C++ utilities | `<xtests/util/temp_file.hpp>`, `<xtests/util/temp_directory.hpp>` | Temporary file and directory helpers for tests |


## Quick start

```c
#include <xtests/xtests.h>

#include <stdlib.h>

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("minimal_c_test", verbosity))
    {
        if (XTESTS_CASE_BEGIN("math", "Checking addition"))
        {
            XTESTS_TEST_INTEGER_EQUAL(4, 2 + 2);

            XTESTS_CASE_END("math");
        }

        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}
```

Include `<xtests/xtests.h>` (or `<xtests/terse-api.h>`), start a runner,
execute cases, print results, and end the runner. See the **Examples**
section of the generated documentation for complete programs under
**examples/**.


<!-- ########################### end of file ########################### -->
