# xTests

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Components](#components)
4. [Examples](#examples)
5. [Project Information](#project-information)

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

xTests is completely free and includes source released under a BSD-style
license.

## Installation

Detailed instructions - via **CMake**, via bundling, via custom makefile
parameters - are provided in the accompanying [INSTALL.md](./INSTALL.md)
file.

## Components

(Click :arrow_forward: To Expand/Contract the sections)

<details>
<summary markdown="span">Utility Functions that are used to exercise tests</summary>
<details>
<summary markdown="span">Test runner functions</summary>

| Function Name & Usage (Test runner functions)                                                                                      |
|:-----------------------------------------------------------------------------------------------------------------------------------|
|**XTESTS_START_RUNNER(name, verbosity)**<br>- Starts a test runner that will report to stdout<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed |
|**XTESTS_START_RUNNER_WITH_STREAM(name, verbosity, stm)**<br>- Starts a test runner<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **stm** The stream to which output will be written |
|**XTESTS_START_RUNNER_WITH_REPORTER(name, verbosity, reporter, reporterParam)**<br>- Starts a test runner with the given callback reporter<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **reporter** The reporter instance<br>- param **reporterParam** A caller-supplied parameter that is passed with every callback |
|**XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM(name, verbosity, reporter, reporterParam, stm)**<br>- Starts a test runner with the given callback reporter<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **reporter** The reporter instance<br>- param **reporterParam** A caller-supplied parameter that is passed with every callback<br>- param **stm** The stream to which output will be written
|**XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS(name, verbosity, reporter, reporterParam, stm, flags)**<br>- Starts a test runner with the given callback reporter<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **reporter** The reporter instance<br>- param **reporterParam** A caller-supplied parameter that is passed with every callback<br>- param **stm** The stream to which output will be written<br>- param **flags** The flags that moderate the runner behaviour<br>- see xtests::c::xtests_runner_flags_t |
|**XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(name, verbosity, reporter, reporterParam, stm, flags, setup, teardown, setupParam)**<br>- Starts a test runner with the given callback reporter<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **reporter** The reporter instance<br>- param **reporterParam** A caller-supplied parameter that is passed with every invocation of the reporter<br>- param **stm** The stream to which output will be written<br>- param **flags** The \link xtests::c::xtests_runner_flags_t flags\endlink that moderate the runner behaviour<br>- param **setup** The function to be called before each test<br>- param **teardown** The function to be called after each test<br>- param **setupParam** A caller-supplied parameter that is passed with each invocation of the setup and teardown functions |
|**XTESTS_START_RUNNER_WITH_FLAGS(name, verbosity, flags)**<br>- Starts a test runner that will report to stdout<br>- A test runner is a logically-related group of test cases.<br>- param **name** The name of the test-runner<br>- param **verbosity** The verbosity (see xtests_verbosity_t) at which the runner will be executed<br>- param **flags** The \link xtests::c::xtests_runner_flags_t flags\endlink that moderate the runner behaviour |
|**XTESTS_PRINT_RESULTS()**<br>- Prints the test results of the currently executing test.<br>- note This can only be invoked after a successful invocation of XTESTS_START_RUNNER() or XTESTS_START_RUNNER_WITH_REPORTER(), and before invocation of XTESTS_END_RUNNER() or XTESTS_END_RUNNER_UPDATE_EXITCODE(). |
|**XTESTS_END_RUNNER()**<br>- Ends a test runner |
|**XTESTS_ABEND(terminationMessage)**<br>- Abnormal end of tests, and process termination |
|**XTESTS_END_RUNNER_UPDATE_EXITCODE()**<br>- Ends a test runner, and modifies a caller-supplied exit code parameter<br>- param **retCode** A pointer to a variable of type <code>int</code> that will receive an exit code.<br>- remarks The variable should have been initialised to <code>EXIT_SUCCESS</code>, and each invocation of XTESTS_END_RUNNER_UPDATE_EXITCODE() (for each separate test-runner in a given application) will only set it to <code>EXIT_FAILURE</code> in the case where that runner has failed one or more tests. |

</details> 
<details>
<summary markdown="span">Test case functions</summary> 

| Function Name & Usage (Test case functions)                                                                                        |
|:-----------------------------------------------------------------------------------------------------------------------------------|
|**XTESTS_CASE_BEGIN(name, desc)**<br>- Begins a test case, of the given name and description<br>- param **name** The name of the test case<br>param **desc** The description of the test case. May be <code>NULL</code> or the empty string (<code>""</code>). |
|**XTESTS_CASE_END(name, desc)**<br>- Ends the current test case<br>- param **name** The name of the test case<br>- note The <code>name</code> parameter is ignored in the current implementation, which can only run one test case at a time. |
|**XTESTS_RUN_CASE_WITH_NAME_AND_DESC(name, desc, fn)**<br>- Runs the given test case function, specifying a name and description<br>- param **name** Name of the test case<br>- param **desc** Description of the test case<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case.<br>- note This can only be invoked after a successful invocation of XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END(). |
|**XTESTS_RUN_CASE_WITH_DESC(fn, desc)**<br>- Runs the given test case function, specifying a description<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case.<br>- param **desc** Description of the test case<br>- note This can only be invoked after a successful invocation of XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END(). |
|**XTESTS_RUN_CASE(fn)**<br>- Runs the given test case function<br>- param **fn** A function, taking no parameters and returning <code>void</code>, that executes a number of tests representing a test case.<br>- note This can only be invoked after a successful invocation of XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END(). |

</details>
</details>
<details>
<summary markdown="span">Enum XTEST Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Enum     |XTESTS_TEST_ENUM_EQUAL(expected, actual)                               |
| Enum     |XTESTS_TEST_ENUM_NOT_EQUAL(expected, actual)                           |

</details>
<details>
<summary markdown="span">Numeric - Integer, Floating Point  XTEST Macros</summary>
<details>
<summary markdown="span">Integer XTEST Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Integer  |XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual)                      |
| Integer  |XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual)                        |
| Integer  |XTESTS_TEST_INTEGER_GREATER(expected, actual)                          |
| Integer  |XTESTS_TEST_INTEGER_LESS(expected, actual)                             |
| Integer  |XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual)                 |
| Integer  |XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)                    |
| Integer  |XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)                    |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(expected, actual)               |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(expected, actual)           |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_OF(expected, actual)                         |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_OF2(expected1, expected2, actual)            |
| Integer  |XTESTS_TEST_INTEGER_EQUAL_OF3(expected1, expected2, expectd3, actual)  |

</details>
<details>
<summary markdown="span">Floating Point XTEST Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| F-Point  |XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(expected, actual)               |
| F-Point  |XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(expected, actual)           |

</details>
</details>
<details>
<summary markdown="span">Boolean XTEST Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Boolean  |XTESTS_TEST_BOOLEAN_EQUAL(expected, actual)                            |
| Boolean  |XTESTS_TEST_BOOLEAN_NOT_EQUAL(expected, actual)                        |
| Boolean  |XTESTS_TEST_BOOLEAN_TRUE(actual)                                       |
| Boolean  |XTESTS_TEST_BOOLEAN_FALSE(actual)                                      |

</details>
<details>
<summary markdown="span">Character/Wide String/Multi-Byte String XTEST Macros</summary>
<details>
<summary markdown="span">Character XTEST Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| Character|XTESTS_TEST_CHARACTER_EQUAL_EXACT(expected, actual)                    |
| Character|XTESTS_TEST_CHARACTER_NOT_EQUAL(expected, actual)                      |
| Character|XTESTS_TEST_CHARACTER_GREATER(expected, actual)                        |
| Character|XTESTS_TEST_CHARACTER_LESS(expected, actual)                           |
| Character|XTESTS_TEST_CHARACTER_GREATER_OR_EQUAL(expected, actual)               |
| Character|XTESTS_TEST_CHARACTER_LESS_OR_EQUAL(expected, actual)                  |

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
<details>
<summary markdown="span">String - MBCS Macros</summary>

| Category |Test Item                                                              |
|:---------|:----------------------------------------------------------------------|
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_EQUAL(expected, actual)                   |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(expected, actual)            |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(expected, actual)               |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX(expected, actual)        |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(expected, actual, n)              |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(expected, actual, n)       |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(expected, actual, n)          |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)   |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expected, actual)                 |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX(expected, actual)          |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN(expected, actual)             |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX(expected, actual)      |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(expected, actual)             |
| MBCS     |XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value) *1                |

*1 Depends on shwild

</details>
</details>
<details>
<summary markdown="span">Pointer XTEST Macros</summary>

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

## Examples

Examples are provided in the ```examples``` directory, along with a markdown description for each.

## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/xTests "GitHub Page")

### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/xTests.

If you'd like to help out with the project, please raise an issue via [GitHub Page](https://github.com/synesissoftware/xTests/issues "GitHub Page") - you'll be very welcome!

### Dependencies

#### STLSoft

**xTests** depends on the STLSoft libraries, version 1.9.134 (or later). Version 1.10.1 beta19 (or later) is recommended.

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

