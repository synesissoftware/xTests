# xTests <!-- omit in toc -->

Simple, easy-to-use, efficient testing library, for C, C++. It's not particularly great, but it's small and portable enough to be bundled with other, more important, libraries.


![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/xTests.svg)](https://github.com/synesissoftware/xTests/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/xTests)](https://github.com/synesissoftware/xTests/commits/master)
[![CI](https://github.com/synesissoftware/xTests/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/xTests/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
- [Examples](#examples)
  - [Minimal C Example](#minimal-c-example)
  - [Minimal C++ Example](#minimal-c-example-1)
  - [Complete C Example (Factorial)](#complete-c-example-factorial)
- [Project Information](#project-information)
  - [Compatibility](#compatibility)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**xTests** is a testing library for C and C++. Specifically, it is a small,
lightweight, portable, simple unit- and component-test framework suitable
for exercising C and C++ libraries. Its primary design features are:

* **Portability**. It relies on no platform-specific or compiler-specific
constructs. The only library it relies on is the 100% header-only,
open-source **STLSoft** library. It works with a large number of C/C++
compilers. Importantly, it is sufficiently simple and lightweight that it
is bundled with several other open-source libraries, and is an integral
part of their automated unit- and component-testing in their builds;
* **Simplicity**. It doesn't require pre-processing of your source code by
scripting languages. It doesn't use macros to create secret classes that
use Schwarz counters to register test cases. It relies on you to simply
code what you want, and nothing that you don't want.

**xTests** is completely free and includes source released under a BSD-style
license.


## Installation

Detailed instructions — via **CMake**, via bundling — are provided in the accompanying [INSTALL.md](./INSTALL.md) file.


## Components

**xTests** is organised around a test runner, test cases, and typed assertion macros. Include **xtests/xtests.h** for the canonical `XTESTS_*` API, or **xtests/terse-api.h** for short aliases such as `TEST_INT_EQ`.

The full catalog — every public runner, case, assertion, and utility construct, with a short example for each — is in [**COMPONENTS.md**](./COMPONENTS.md).

A typical program parses verbosity, starts a runner, executes cases, prints results, and ends the runner. The [Examples](#examples) below show complete programs.


## Examples

Extensive examples are provided in the **examples** directory, along with a markdown description for each. Below are the simplest-possible starting examples for both C and C++, followed by a more complete C scenario.


### Minimal C Example

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
        if (XTESTS_CASE_BEGIN("math", "Checking basic addition"))
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


### Minimal C++ Example

```cpp
#include <xtests/xtests.h>
#include <vector>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("minimal_cpp_test", verbosity))
    {
        if (XTESTS_CASE_BEGIN("vector", "Checking vector size"))
        {
            std::vector<int> v;
            v.push_back(42);

            XTESTS_TEST_INTEGER_EQUAL(1, v.size());

            XTESTS_CASE_END("vector");
        }

        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}
```


### Complete C Example (Factorial)

Here is a more complete C example illustrating the use of the terse assertion API and separate test case functions:

```c
/* file: example.c.factorial.c */
#include <xtests/terse-api.h>
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
    TEST_INT_EQ(1, factorial(0));
    TEST_INT_EQ(1, factorial(1));
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
            TEST_INT_EQ(2, factorial(2));
            TEST_INT_EQ(6, factorial(3));
            /* . . . */
            TEST_INT_EQ(479001600, factorial(12));

            XTESTS_CASE_END("test-case-1");
        }


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}
```

**NOTE**: **C++** test programs have additional support for facilities such as the throwing of exceptions and native C++ User-Defined Type (UDT) comparisons.


## Project Information


### Compatibility

Compiler/language pairs exercised for **xTests** (library, examples, and tests)
with the public **STLSoft** dependency. Empty cells are not yet recorded.

> **Note (Clang + C90):** Apple Clang 15 fails C90 builds under the project's
> `-Werror -Wall -Wextra -pedantic` flags because **STLSoft** uses
> `extern inline` (extension token). C99 and later are fine on the same
> toolchain.

  | C++   | C   | Clang (macOS) | GCC (Linux) | GCC(MinGW) (Windows)  | Visual C++ 17.x (Windows) |
  | ----- | --- | :-----------: | :---------: | :-------------------: | :-----------------------: |
  | 23    | 23  | ✅             | ✅           |                       | ❌                         |
  | 23    | 17  | ✅             |             |                       |                           |
  | 20    | 23  | ✅             |             |                       |                           |
  | 20    | 17  | ✅             | ✅           |                       | ✅                         |
  | 20    | 11  | ✅             |             |                       |                           |
  | 20    | 99  | ✅             |             |                       |                           |
  | 20    | 90  | ❌             |             |                       |                           |
  | 17    | 17  | ✅             | ✅           |                       | ✅                         |
  | 17    | 11  | ✅             |             |                       |                           |
  | 17    | 99  | ✅             |             |                       |                           |
  | 17    | 90  | ❌             |             |                       |                           |
  | 14    | 11  | ✅             | ✅           |                       | ✅                         |
  | 14    | 99  | ✅             |             |                       |                           |
  | 14    | 90  | ❌             |             |                       |                           |
  | 11    | 11  | ✅             | ✅           |                       | ✅                         |
  | 11    | 99  | ✅             | ✅           |                       | ✅                         |
  | 11    | 90  | ❌             |             |                       | ✅                         |
  | 98    | 99  | ✅             | ❌           |                       | ✅                         |
  | 98    | 90  | ❌             |             |                       |                           |


### Where to get help

[GitHub Page](https://github.com/synesissoftware/xTests "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/xTests.

If you'd like to help out with the project, please raise an issue via [GitHub Page](https://github.com/synesissoftware/xTests/issues "GitHub Page") - you'll be very welcome!


### Dependencies


#### STLSoft <!-- omit in toc -->

**xTests** has two dependencies:

* [STLSoft 1.11](http://github.com/synesissoftware/STLSoft/) is required, both for the implementation and for the interface, providing:
  * essential compiler and platform discrimination;
  * string compatibility;
  * string conversions (for C++ API);
  * meta-programming (for C++ API);
* [shwild](http://github.com/synesissoftware/shwild/) is an optional dependency, which, if present, supports the string matching tests:
  * `XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value)`;
  * `XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH(pattern, value)`;


### Related projects

Projects in which **xTests** is used for testing include:

* [**b64**](https://github.com/synesissoftware/b64);
* [**chomp**](https://github.com/sistools/chomp);
* [**CLASP**](https://github.com/synesissoftware/CLASP);
* [**collect-c**](https://github.com/synesissoftware/collect-c);
* [**collect-cxx**](https://github.com/synesissoftware/collect-cxx);
* [**cstring**](https://github.com/synesissoftware/cstring);
* [**Diagnosticism**](https://github.com/synesissoftware/Diagnosticism);
* [**FastFormat**](https://github.com/synesissoftware/FastFormat);
* [**libCLImate**](https://github.com/synesissoftware/libCLImate);
* [**libpath**](https://github.com/synesissoftware/libpath);
* [**lstrip**](https://github.com/sistools/lstrip);
* [**mksock**](https://github.com/sistools/mksock);
* [**Pantheios.Extras.DiagUtil**](https://github.com/synesissoftware/Pantheios.Extras.DiagUtil);
* [**Pantheios.Extras.Main**](https://github.com/synesissoftware/Pantheios.Extras.Main);
* [**Pantheios.Extras.xHelpers**](https://github.com/synesissoftware/Pantheios.Extras.xHelpers);
* [**Pantheios**](https://github.com/synesissoftware/Pantheios);
* [**recls**](https://github.com/synesissoftware/recls);
* [**rstrip**](https://github.com/sistools/rstrip);
* [**ss-win-diskutil**](https://github.com/synesissoftware/ss-win-diskutil);
* [**STLSoft**](https://github.com/synesissoftware/STLSoft);
* [**STLSoft-1.10**](https://github.com/synesissoftware/STLSoft-1.10);
* [**STLSoft-1.11**](https://github.com/synesissoftware/STLSoft-1.11);
* [**SyLVReDxx**](https://github.com/synesissoftware/SyLVReDxx);
* [**UNIXem**](https://github.com/synesissoftware/UNIXem);
* [**xTests**](https://github.com/synesissoftware/xTests);


### License

**xTests** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
