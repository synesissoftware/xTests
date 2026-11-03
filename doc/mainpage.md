# xTests {#mainpage}

**xTests** is a simple, easy-to-use, efficient unit- and component-testing
library for **C** and **C++**. It is small, lightweight, and portable enough
to bundle with other libraries and exercise them in their automated builds.

It relies on no platform-specific or compiler-specific constructs. The only
library it relies on is the 100% header-only, open-source **STLSoft** library.


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

The library consists of the following key layers:

* **Test Runner and Test Case Functions**: Functions used to establish the runner environment, manage test setup/teardown fixtures, and run isolated test cases (e.g., `XTESTS_START_RUNNER`, `XTESTS_CASE_BEGIN`, `XTESTS_CASE_END`).
* **Test Assertion Macros**: A rich suite of assertion macros covering:
  * Booleans (`XTESTS_TEST_BOOLEAN_EQUAL`, etc.)
  * Integers (`XTESTS_TEST_INTEGER_EQUAL`, etc.)
  * Floating-point numbers with epsilon tolerance (`XTESTS_TEST_DOUBLE_EQUAL`, etc.)
  * Pointers (`XTESTS_TEST_POINTER_EQUAL`, etc.)
  * Multibyte and Wide character strings (`XTESTS_TEST_MULTIBYTE_STRING_EQUAL`, `XTESTS_TEST_WIDE_STRING_EQUAL`, etc.)
  * Pattern matching (`XTESTS_TEST_MULTIBYTE_STRING_MATCHES` when optionally integrated with **shwild**)
  * Custom User-Defined Types (UDTs)
* **RAII Utilities**: Helper classes for managing temporary files and directories under test in C++:
  * `xtests::cpp::util::temp_file`
  * `xtests::cpp::util::temp_directory`


## Quick start

Here is a simple example program demonstrating how to define test cases and assertions using the C API:

```c
#include <xtests/xtests.h>

#include <stdlib.h>

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("quickstart.example", verbosity))
    {
        if (XTESTS_CASE_BEGIN("integer_tests", "Testing basic integer equality"))
        {
            XTESTS_TEST_INTEGER_EQUAL(42, 42);
            XTESTS_TEST_INTEGER_NOT_EQUAL(42, 24);

            XTESTS_CASE_END("integer_tests");
        }

        if (XTESTS_CASE_BEGIN("string_tests", "Testing string comparisons"))
        {
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL("hello", "hello");

            XTESTS_CASE_END("string_tests");
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


## Integration and Installation

For installation instructions via **CMake** or details on how to **bundle** **xTests** directly into your own projects, please consult the [INSTALL.md](https://github.com/synesissoftware/xTests/blob/master/INSTALL.md) guide.


## Related projects

Many open-source libraries in the **freelibs** ecosystem use **xTests** for their unit- and component-testing:

* [**b64**](https://github.com/synesissoftware/b64)
* [**CLASP**](https://github.com/synesissoftware/CLASP)
* [**cstring**](https://github.com/synesissoftware/cstring)
* [**Diagnosticism**](https://github.com/synesissoftware/Diagnosticism)
* [**FastFormat**](https://github.com/synesissoftware/FastFormat)
* [**Pantheios**](https://github.com/synesissoftware/Pantheios)
* [**recls**](https://github.com/synesissoftware/recls)
* [**shwild**](https://github.com/synesissoftware/shwild)
* [**STLSoft**](https://github.com/synesissoftware/STLSoft)


<!-- ########################### end of file ########################### -->
