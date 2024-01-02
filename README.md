# xTests <!-- omit in toc -->

## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
  - [Related projects](#related-projects)
  - [License](#license)

## Introduction

**xTests** is a testing library for C and C++. Specifically, it is a small,
lightweight, portable, simple unit- and component-test framework suitable
for exercising C and C++ libraries. Its primary design features are:

- **Portability**. It relies on no platform-specific or compiler-specific
constructs. The only library it relies on is the 100% header-only,
open-source **STLSoft** library. It works with a large number of C/C++
compilers. Importantly, it is sufficiently simple and lightweight that it
is bundled with several other open-source libraries, and is an integral
part of their automated unit- and component-testing in their builds;
- **Simplicity**. It doesn't require pre-processing of your source code by
scripting languages. It doesn't use macros to create secret classes that
use Schwarz counters to register test cases. It relies on you to simply
code what you want, and nothing that you don't want.

**xTests** is completely free and includes source released under a BSD-style
license.

## Installation

Detailed instructions - via **CMake**, via bundling, via custom makefile
parameters - are provided in the accompanying [INSTALL.md](./INSTALL.md)
file.

## Components

(Click :arrow_forward: to expand/contract the sections)

<details>
<summary markdown="span">Test-runner and Test-case functions that are used to set up the test context</summary>
<blockquote>
 <details>
 <summary markdown="span">Test runner functions</summary>

| Function Name & Usage (Test runner functions)                                                                                      |
|:-----------------------------------------------------------------------------------------------------------------------------------|
|`XTESTS_START_RUNNER(name, verbosity)`<br>Starts a test runner that will report to stdout<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed |
|`XTESTS_START_RUNNER_WITH_STREAM(name, verbosity, stm)`<br>Starts a test runner<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **stm** The stream to which output will be written |
|`XTESTS_START_RUNNER_WITH_REPORTER(name, verbosity, reporter, reporterParam)`<br>Starts a test runner with the given callback reporter<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **reporter** The reporter instance<br>- param **reporterParam** A caller-supplied parameter that is passed with every callback |
|`XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM(name, verbosity, reporter, reporterParam, stm)`<br>Starts a test runner with the given callback reporter<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **reporter** The reporter instance<br>- param **reporterParam** A caller-supplied parameter that is passed with every callback<br>- param **stm** The stream to which output will be written
|`XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS(name, verbosity, reporter, reporterParam, stm, flags)`<br>Starts a test runner with the given callback reporter<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **reporter** The reporter instance<br>- param **reporterParam** A caller-supplied parameter that is passed with every callback<br>- param **stm** The stream to which output will be written<br>- param **flags** The flags that moderate the runner behaviour<br>- see xtests::c::xtests_runner_flags_t |
|`XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(name, verbosity, reporter, reporterParam, stm, flags, setup, teardown, setupParam)`<br>Starts a test runner with the given callback reporter<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **reporter** The reporter instance<br>- param **reporterParam** A caller-supplied parameter that is passed with every invocation of the reporter<br>- param **stm** The stream to which output will be written<br>- param **flags** The \link xtests::c::xtests_runner_flags_t flags\endlink that moderate the runner behaviour<br>- param **setup** The function to be called before each test<br>- param **teardown** The function to be called after each test<br>- param **setupParam** A caller-supplied parameter that is passed with each invocation of the setup and teardown functions |
|`XTESTS_START_RUNNER_WITH_FLAGS(name, verbosity, flags)`<br>Starts a test runner that will report to stdout<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **flags** The \link xtests::c::xtests_runner_flags_t flags\endlink that moderate the runner behaviour |
|`XTESTS_PRINT_RESULTS()`<br>Prints the test results of the currently executing test.<br>- note This can only be invoked after a successful invocation of XTESTS_START_RUNNER() or XTESTS_START_RUNNER_WITH_REPORTER(), and before invocation of XTESTS_END_RUNNER() or XTESTS_END_RUNNER_UPDATE_EXITCODE(). |
|`XTESTS_END_RUNNER()`<br>Ends a test runner |
|`XTESTS_ABEND(terminationMessage)`<br>Abnormal end of tests, and process termination.|
|`XTESTS_END_RUNNER_UPDATE_EXITCODE()`<br>Ends a test runner, and modifies a caller-supplied exit code parameter<br>- param **retCode** A pointer to a variable of type <code>int</code> that will receive an exit code.<br>- remarks The variable should have been initialised to <code>EXIT_SUCCESS</code>, and each invocation of XTESTS_END_RUNNER_UPDATE_EXITCODE() (for each separate test-runner in a given application) will only set it to <code>EXIT_FAILURE</code> in the case where that runner has failed one or more tests. |

 </details>
 <details>
 <summary markdown="span">Test case functions</summary>

| Function Name & Usage (Test case functions)                                                                                        |
|:-----------------------------------------------------------------------------------------------------------------------------------|
|`XTESTS_CASE_BEGIN(name, desc)`<br>Begins a test case, of the given name and description.<br>- param **name** The name of the test case<br>- param **desc** The description of the test case. May be <code>NULL</code> or the empty string (<code>""</code>). |
|`XTESTS_CASE_END(name, desc)`<br>Ends the current test case<br>- param **name** The name of the test case<br>**Note**: The <code>name</code> parameter is ignored in the current implementation, which can only run one test case at a time.|
|`XTESTS_RUN_CASE_WITH_NAME_AND_DESC(name, desc, fn)`<br>Runs the given test case function, specifying a name and description.<br>- param **name** Name of the test case<br>- param **desc** Description of the test case<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case.<br>**Note**: This can only be invoked after a successful invocation of `XTESTS_CASE_BEGIN()` and before invocation of `XTESTS_CASE_END()`.|
|`XTESTS_RUN_CASE_WITH_DESC(fn, desc)`<br>Runs the given test case function, specifying a description<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case.<br>- param **desc** Description of the test case<br>- note This can only be invoked after a successful invocation of XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END(). |
|`XTESTS_RUN_CASE(fn)`<br>Runs the given test case function<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case.<br>**Note**: This can only be invoked after a successful invocation of `XTESTS_CASE_BEGIN()` and before invocation of `XTESTS_CASE_END()`.|
|`XTESTS_RUN_CASE_THAT_THROWS(fn, type)`<br>[C++-only] Runs the given test case function.<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case;<br>- param **type** The type of the exception that is expected to be thrown;<br>**Note**: This can only be invoked after a successful invocation of `XTESTS_CASE_BEGIN()` and before invocation of `XTESTS_CASE_END()`.|
|`XTESTS_RUN_CASE_THAT_THROWS_WITH_DESC(fn, desc, type)`<br>[C++-only] Runs the given test case function.<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case;<br>- param **desc** Description of the test case;<br>- param **type** The type of the exception that is expected to be thrown;<br>**Note**: This can only be invoked after a successful invocation of `XTESTS_CASE_BEGIN()` and before invocation of `XTESTS_CASE_END()`.|
|`XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC(name, desc, fn, type)`<br>[C++-only] Runs the given test case function.<br>- param **name** Name of the test case;<br>- param **desc** Description of the test case;<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case;<br>- param **type** The type of the exception that is expected to be thrown;<br>**Note**: This can only be invoked after a successful invocation of `XTESTS_CASE_BEGIN()` and before invocation of `XTESTS_CASE_END()`.|

 </details>
</blockquote>
</details>

<details>
<summary markdown="span">Test assertion macros</summary>
<blockquote>

 <!-- integers and floating-point -->
 <details>
 <summary markdown="span">Numeric - Integer, Floating Point - Assertion Macros</summary>
 <blockquote>
  <details>
  <summary markdown="span">Integer Assertion Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Integer  |XTESTS_TEST_INTEGER_EQUAL(expected, actual)                            |
| Integer  |XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual)                        |
| Integer  |XTESTS_TEST_INTEGER_GREATER(expected, actual)                          |
| Integer  |XTESTS_TEST_INTEGER_LESS(expected, actual)                             |
| Integer  |XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual)                 |
| Integer  |XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)                    |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(expected, actual)               |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(expected, actual)           |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_OF2(expected1, expected2, actual)            |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_OF3(expected1, expected2, expectd3, actual)  |

  </details>

  <details>
  <summary markdown="span">Floating Point Assertion Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| F-Point  |XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(expected, actual)               |
| F-Point  |XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(expected, actual)           |
| F-Point  |XTESTS_TEST_FLOATINGPOINT_EQUAL_EXACT(expected, actual)                |
| F-Point  |XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_EXACT(expected, actual)            |

  </details>

 </blockquote>
 </details>

 <!-- characters and strings -->
 <details>
 <summary markdown="span">Character/String (Multi-Byte and Wide) Assertion Macros</summary>
 <blockquote>
  <details>
  <summary markdown="span">Character Assertion Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Character|XTESTS_TEST_CHARACTER_EQUAL(expected, actual)                          |
| Character|XTESTS_TEST_CHARACTER_NOT_EQUAL(expected, actual)                      |
| Character|XTESTS_TEST_CHARACTER_GREATER(expected, actual)                        |
| Character|XTESTS_TEST_CHARACTER_LESS(expected, actual)                           |
| Character|XTESTS_TEST_CHARACTER_GREATER_OR_EQUAL(expected, actual)               |
| Character|XTESTS_TEST_CHARACTER_LESS_OR_EQUAL(expected, actual)                  |

  </details>

  <details>
  <summary markdown="span">String - Multibyte Macros</summary>

| Category  |Test Item                                                             |
|:----------|:---------------------------------------------------------------------|
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_EQUAL(expected, actual)                  |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(expected, actual)           |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(expected, actual)              |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX(expected, actual)       |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(expected, actual, n)             |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(expected, actual, n)      |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(expected, actual, n)         |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)  |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expected, actual)                |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX(expected, actual)         |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN(expected, actual)            |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX(expected, actual)     |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(expected, actual)            |
| Multibyte |XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value) <sup>1</sup>     |

<em>1</em> `XTESTS_TEST_MULTIBYTE_STRING_MATCHES` is only enabled in the presence of the [**shwild**](https://github.com/synesissoftware/shwild) library - i.e. when the **shwild/shwild.h** header is detected - to avoid an undue (and circular, since **shwild** uses **xTests**) dependency.

  </details>

  <details>
  <summary markdown="span">String - Wide Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Wide     |XTESTS_TEST_WIDE_STRING_EQUAL(expected, actual)                        |
| Wide     |XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(expected, actual)                 |
| Wide     |XTESTS_TEST_WIDE_STRING_NOT_EQUAL(expected, actual)                    |
| Wide     |XTESTS_TEST_WIDE_STRING_NOT_EQUAL_APPROX(expected, actual)             |
| Wide     |XTESTS_TEST_WIDE_STRING_EQUAL_N(expected, actual, n)                   |
| Wide     |XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(expected, actual, n)            |
| Wide     |XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(expected, actual, n)               |
| Wide     |XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)        |
| Wide     |XTESTS_TEST_WIDE_STRING_CONTAIN(expected, actual)                      |
| Wide     |XTESTS_TEST_WIDE_STRING_CONTAIN_APPROX(expected, actual)               |
| Wide     |XTESTS_TEST_WIDE_STRING_NOT_CONTAIN(expected, actual)                  |
| Wide     |XTESTS_TEST_WIDE_STRING_NOT_CONTAIN_APPROX(expected, actual)           |
| Wide     |XTESTS_TEST_WIDE_STRING_SLICE_EQUAL(expected, actual)                  |

  </details>

 </blockquote>
 </details>

 <!-- booleans -->
 <details>
 <summary markdown="span">Boolean Assertion Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Boolean  |XTESTS_TEST_BOOLEAN_EQUAL(expected, actual)                            |
| Boolean  |XTESTS_TEST_BOOLEAN_NOT_EQUAL(expected, actual)                        |
| Boolean  |XTESTS_TEST_BOOLEAN_TRUE(actual)                                       |
| Boolean  |XTESTS_TEST_BOOLEAN_FALSE(actual)                                      |

 </details>

 <!-- enums -->
 <details>
 <summary markdown="span">Enum Assertion Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Enum     |XTESTS_TEST_ENUM_EQUAL(expected, actual)                               |
| Enum     |XTESTS_TEST_ENUM_NOT_EQUAL(expected, actual)                           |

 </details>

 <!-- pointers -->
 <details>
 <summary markdown="span">Pointer Assertion Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Pointer  |XTESTS_TEST_POINTER_EQUAL(expected, actual)                            |
| Pointer  |XTESTS_TEST_POINTER_NOT_EQUAL(expected, actual)                        |
| Pointer  |XTESTS_TEST_POINTER_GREATER(expected, actual)                          |
| Pointer  |XTESTS_TEST_POINTER_LESS(expected, actual)                             |
| Pointer  |XTESTS_TEST_POINTER_GREATER_OR_EQUAL(expected, actual)                 |
| Pointer  |XTESTS_TEST_POINTER_LESS_OR_EQUAL(expected, actual)                    |
| Pointer  |XTESTS_TEST_FUNCTION_POINTER_EQUAL(expected, actual)                   |
| Pointer  |XTESTS_TEST_FUNCTION_POINTER_NOT_EQUAL(expected, actual)               |

 </details>

 <!-- direct results -->
 <details>
 <summary markdown="span">Directed-result Assertion Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Utility  |XTESTS_TEST_PASSED()                                                   |
| Utility  |XTESTS_TEST_FAIL(msg)                                                  |
| Utility  |XTESTS_TEST_FAIL_WITH_QUALIFIER(msg, qualifier)                        |
| Utility  |XTESTS_TEST(expr)                                                      |
| Utility  |XTESTS_TEST_WITH_MESSAGE(expr, msg)                                    |
| Utility  |XTESTS_REQUIRE(test)                                                   |

 </details>

</blockquote>
</details>

<details>
<summary markdown="span">Utility functions and miscellaneous constructs</summary>
<blockquote>
 <details>
 <summary markdown="span">Utility functions</summary>

| Function Name & Usage (Utility functions)  |
|:-------------------------------------------|
|`XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, pverbosity)`<br>Parses the verbosity from the command-line arguments, looking for an argument of the form `"--verbosity=<N>"`, where `N` is a non-negative integer.<br>- param `argc`  The `argc` parameter passed into `main()`;<br>- param `argv` The `argv` parameter passed into `main()`;<br>- param `pverbosity` A pointer to an integer to receive the verbosity. Will be set to `xtestsVerbositySummaryOnSuccess` upon success, or if no verbosity argument is found. May not be `NULL`;|
|`XTESTS_COMMANDLINE_PARSE_VERBOSITY_WITH_DEFAULT(argc, argv, pverbosity, defaultVerbosity)`<br>Parses the verbosity from the command-line arguments, looking for an argument of the form `"--verbosity=<N>"`, where `N` is a non-negative integer.<br>- param `argc`  The `argc` parameter passed into `main()`;<br>- param `argv` The `argv` parameter passed into `main()`;<br>- param `pverbosity` A pointer to an integer to receive the verbosity. Will be set to `xtestsVerbositySummaryOnSuccess` upon success, or if no verbosity argument is found. May not be `NULL`;<br>- param `defaultVerbosity` The default verbosity to be applied if none specified on the command-line|
|`XTESTS_COMMANDLINE_PARSE_HELP(argc, argv)`<br>Parses the `"--help"` flag from the command-line and, if found, issues usage information to the standard output stream and exits (with `EXIT_SUCCESS`).<br>- param `argc`  The `argc` parameter passed into `main()`;<br>- param `argv` The `argv` parameter passed into `main()`;|

 </details>

 <details>
 <summary markdown="span">Miscellaneous constructs</summary>

| Constructs                                                                                                                       |
|:---------------------------------------------------------------------------------------------------------------------------------|
|`XTESTS_FLOATINGPOINT_FACTOR_SCOPE()`<br>[C++ only] Macro used to declare an instance of the class xtests::cpp::xtest_floatingpoint_factor_scope, which causes the floating point factor to be set to a new value for the lifetime of the object, and then returned to its prior value.|
|`XTESTS_FP_APPROXIMATE_FACTOR(argc, argv)`<br>The factor within which floating point numbers are deemed to be approximately equal.|

 </details>
</blockquote>
</details>

## Examples

Extensive examples are provided in the ```examples``` directory, along with a markdown description for each. Here, it is worth just providing a simplest-possible useful example, as shown below:

```c
/* file: example.c.factorial.c */
#include <xtests/xtests.h>
#include <stdio.h>
#include <assert.h>

/* a somewhat-flaky factorial function */
int factorial(int v)
{
    assert(v >= 0);

    switch (v)
    {
        case 0:
        case 1:
            return 1;
        default:
            return v * factorial(v - 1);
    }
}

void test_factorial_edge_cases()
{
    XTESTS_TEST_INTEGER_EQUAL(1, factorial(0));
    XTESTS_TEST_INTEGER_EQUAL(1, factorial(1));
}

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("example.factorial.runner", verbosity))
    {
        /* runs test case function "test_factorial_edge_cases" */
        XTESTS_RUN_CASE_WITH_DESC(test_factorial_edge_cases, "checking edge cases");

        /* runs test case "test-case-range" */
        if (XTESTS_CASE_BEGIN("test-case-range", "checking wider range of input numbers"))
        {
            XTESTS_TEST_INTEGER_EQUAL(2, factorial(2));
            XTESTS_TEST_INTEGER_EQUAL(6, factorial(3));
            /* . . . */
            XTESTS_TEST_INTEGER_EQUAL(479001600, factorial(12));

            XTESTS_CASE_END("test-case-1");
        }


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}
```

**NOTE**: the language shown in **C**, but a **C++** version of this example program would be very similar. **C++** test programs have additiona support for facilities such as the throwing of exceptions.


## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/xTests "GitHub Page")

### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/xTests.

If you'd like to help out with the project, please raise an issue via [GitHub Page](https://github.com/synesissoftware/xTests/issues "GitHub Page") - you'll be very welcome!

### Dependencies

#### STLSoft <!-- omit in toc -->

**xTests** depends on the **STLSoft** libraries, version 1.9.134 (or later). Version 1.10.1 (or later) is recommended.

* [STLSoft 1.9](http://github.com/synesissoftware/STLSoft-1.9/)
* [STLSoft 1.10](http://github.com/synesissoftware/STLSoft-1.10/) (Recommended)

### Related projects

Projects in which **xTests** is used for testing include:

* [**b64**](https://github.com/synesissoftware/b64)
* [**cstring**](https://github.com/synesissoftware/cstring)
* [**FastFormat**](https://github.com/synesissoftware/FastFormat)
* [**libpath**](https://github.com/synesissoftware/libpath)
* [**Pantheios**](https://github.com/synesissoftware/Pantheios)
* [**recls**](https://github.com/synesissoftware/recls)
* [**shwild**](https://github.com/synesissoftware/shwild)
* [**UNIXem**](https://github.com/synesissoftware/UNIXem)

### License

**xTests** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

