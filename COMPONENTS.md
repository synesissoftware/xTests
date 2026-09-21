# xTests - Components <!-- omit in toc -->

Catalog of the public **xTests** API. Each construct has a short description and a small example. Complete programs live in [README.md](./README.md#examples).


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Headers](#headers)
- [Verbosity and runner flags](#verbosity-and-runner-flags)
  - [`xtests_verbosity_t`](#xtests_verbosity_t)
  - [`xtests_runner_flags_t`](#xtests_runner_flags_t)
  - [`xTests_Setup_t` / `xTests_Teardown_t`](#xtests_setup_t--xtests_teardown_t)
- [Test runner functions](#test-runner-functions)
  - [`XTESTS_START_RUNNER(name, verbosity)`](#xtests_start_runnername-verbosity)
  - [`XTESTS_START_RUNNER_WITH_SETUP_FNS(name, verbosity, setup, teardown, setupParam)`](#xtests_start_runner_with_setup_fnsname-verbosity-setup-teardown-setupparam)
  - [`XTESTS_START_RUNNER_WITH_STREAM(name, verbosity, stm)`](#xtests_start_runner_with_streamname-verbosity-stm)
  - [`XTESTS_START_RUNNER_WITH_REPORTER(name, verbosity, reporter, reporterParam)`](#xtests_start_runner_with_reportername-verbosity-reporter-reporterparam)
  - [`XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM(name, verbosity, reporter, reporterParam, stm)`](#xtests_start_runner_with_reporter_and_streamname-verbosity-reporter-reporterparam-stm)
  - [`XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS(name, verbosity, reporter, reporterParam, stm, flags)`](#xtests_start_runner_with_reporter_and_stream_and_flagsname-verbosity-reporter-reporterparam-stm-flags)
  - [`XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(...)`](#xtests_start_runner_with_reporter_and_stream_and_flags_and_setup_fns)
  - [`XTESTS_START_RUNNER_WITH_FLAGS(name, verbosity, flags)`](#xtests_start_runner_with_flagsname-verbosity-flags)
  - [`XTESTS_PRINT_RESULTS()`](#xtests_print_results)
  - [`XTESTS_END_RUNNER()`](#xtests_end_runner)
  - [`XTESTS_ABEND(terminationMessage)`](#xtests_abendterminationmessage)
  - [`XTESTS_END_RUNNER_UPDATE_EXITCODE(retCode)`](#xtests_end_runner_update_exitcoderetcode)
- [Test case functions](#test-case-functions)
  - [`XTESTS_CASE_BEGIN(name, desc)`](#xtests_case_beginname-desc)
  - [`XTESTS_CASE_END(name)`](#xtests_case_endname)
  - [`XTESTS_RUN_CASE_WITH_NAME_AND_DESC(name, desc, fn)`](#xtests_run_case_with_name_and_descname-desc-fn)
  - [`XTESTS_RUN_CASE_WITH_DESC(fn, desc)`](#xtests_run_case_with_descfn-desc)
  - [`XTESTS_RUN_CASE(fn)`](#xtests_run_casefn)
  - [`XTESTS_RUN_CASE_THAT_THROWS(fn, type)`](#xtests_run_case_that_throwsfn-type)
  - [`XTESTS_RUN_CASE_THAT_THROWS_WITH_DESC(fn, desc, type)`](#xtests_run_case_that_throws_with_descfn-desc-type)
  - [`XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC(name, desc, fn, type)`](#xtests_run_case_that_throws_with_name_and_descname-desc-fn-type)
- [Directed-result assertion macros](#directed-result-assertion-macros)
  - [`XTESTS_TEST_PASSED()`](#xtests_test_passed)
  - [`XTESTS_TEST_FAIL(msg)`](#xtests_test_failmsg)
  - [`XTESTS_TEST_FAIL_WITH_QUALIFIER(msg, qualifier)`](#xtests_test_fail_with_qualifiermsg-qualifier)
  - [`XTESTS_TEST(expr)`](#xtests_testexpr)
  - [`XTESTS_TEST_WITH_MESSAGE(expr, msg)`](#xtests_test_with_messageexpr-msg)
  - [`XTESTS_REQUIRE(test)`](#xtests_requiretest)
- [User-defined type assertion macros](#user-defined-type-assertion-macros)
  - [`XTESTS_TEST_EQUAL(expected, actual)`](#xtests_test_equalexpected-actual)
  - [`XTESTS_TEST_EQUAL_WITH_MESSAGE(expected, actual, msg)`](#xtests_test_equal_with_messageexpected-actual-msg)
  - [`XTESTS_TEST_NOT_EQUAL(expected, actual)`](#xtests_test_not_equalexpected-actual)
  - [`XTESTS_TEST_NOT_EQUAL_WITH_MESSAGE(expected, actual, msg)`](#xtests_test_not_equal_with_messageexpected-actual-msg)
- [Integer assertion macros](#integer-assertion-macros)
  - [`XTESTS_TEST_INTEGER_EQUAL(expected, actual)`](#xtests_test_integer_equalexpected-actual)
  - [`XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual)`](#xtests_test_integer_equal_exactexpected-actual)
  - [`XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual)`](#xtests_test_integer_not_equalexpected-actual)
  - [`XTESTS_TEST_INTEGER_GREATER(expected, actual)`](#xtests_test_integer_greaterexpected-actual)
  - [`XTESTS_TEST_INTEGER_LESS(expected, actual)`](#xtests_test_integer_lessexpected-actual)
  - [`XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual)`](#xtests_test_integer_greater_or_equalexpected-actual)
  - [`XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)`](#xtests_test_integer_less_or_equalexpected-actual)
  - [`XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(begin, end, actual)`](#xtests_test_integer_equal_any_in_rangebegin-end-actual)
  - [`XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(begin, end, actual)`](#xtests_test_integer_equal_any_not_in_rangebegin-end-actual)
  - [`XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(expected0, expected1, actual)`](#xtests_test_integer_equal_any_of2expected0-expected1-actual)
  - [`XTESTS_TEST_INTEGER_EQUAL_ANY_OF3(expected0, expected1, expected2, actual)`](#xtests_test_integer_equal_any_of3expected0-expected1-expected2-actual)
- [Floating-point assertion macros](#floating-point-assertion-macros)
  - [`XTESTS_TEST_FLOATINGPOINT_EQUAL(expected, actual)`](#xtests_test_floatingpoint_equalexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL(expected, actual)`](#xtests_test_floatingpoint_not_equalexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(expected, actual)`](#xtests_test_floatingpoint_equal_approxexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(expected, actual)`](#xtests_test_floatingpoint_not_equal_approxexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_EQUAL_EXACT(expected, actual)`](#xtests_test_floatingpoint_equal_exactexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_EXACT(expected, actual)`](#xtests_test_floatingpoint_not_equal_exactexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_GREATER(expected, actual)`](#xtests_test_floatingpoint_greaterexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_LESS(expected, actual)`](#xtests_test_floatingpoint_lessexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_GREATER_OR_EQUAL(expected, actual)`](#xtests_test_floatingpoint_greater_or_equalexpected-actual)
  - [`XTESTS_TEST_FLOATINGPOINT_LESS_OR_EQUAL(expected, actual)`](#xtests_test_floatingpoint_less_or_equalexpected-actual)
- [Character assertion macros](#character-assertion-macros)
  - [`XTESTS_TEST_CHARACTER_EQUAL(expected, actual)`](#xtests_test_character_equalexpected-actual)
  - [`XTESTS_TEST_CHARACTER_EQUAL_EXACT(expected, actual)`](#xtests_test_character_equal_exactexpected-actual)
  - [`XTESTS_TEST_CHARACTER_NOT_EQUAL(expected, actual)`](#xtests_test_character_not_equalexpected-actual)
  - [`XTESTS_TEST_CHARACTER_GREATER(expected, actual)`](#xtests_test_character_greaterexpected-actual)
  - [`XTESTS_TEST_CHARACTER_LESS(expected, actual)`](#xtests_test_character_lessexpected-actual)
  - [`XTESTS_TEST_CHARACTER_GREATER_OR_EQUAL(expected, actual)`](#xtests_test_character_greater_or_equalexpected-actual)
  - [`XTESTS_TEST_CHARACTER_LESS_OR_EQUAL(expected, actual)`](#xtests_test_character_less_or_equalexpected-actual)
- [Multibyte string assertion macros](#multibyte-string-assertion-macros)
  - [`XTESTS_TEST_MULTIBYTE_STRING_EQUAL(expected, actual)`](#xtests_test_multibyte_string_equalexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(expected, actual)`](#xtests_test_multibyte_string_equal_approxexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(expected, actual)`](#xtests_test_multibyte_string_not_equalexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX(expected, actual)`](#xtests_test_multibyte_string_not_equal_approxexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(expected, actual, n)`](#xtests_test_multibyte_string_equal_nexpected-actual-n)
  - [`XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(expected, actual, n)`](#xtests_test_multibyte_string_equal_n_approxexpected-actual-n)
  - [`XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(expected, actual, n)`](#xtests_test_multibyte_string_not_equal_nexpected-actual-n)
  - [`XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)`](#xtests_test_multibyte_string_not_equal_n_approxexpected-actual-n)
  - [`XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expected, actual)`](#xtests_test_multibyte_string_containexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX(expected, actual)`](#xtests_test_multibyte_string_contain_approxexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN(expected, actual)`](#xtests_test_multibyte_string_not_containexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX(expected, actual)`](#xtests_test_multibyte_string_not_contain_approxexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(expected, actual)`](#xtests_test_multibyte_string_slice_equalexpected-actual)
  - [`XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value)`](#xtests_test_multibyte_string_matchespattern-value)
  - [`XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH(pattern, value)`](#xtests_test_multibyte_string_does_not_matchpattern-value)
- [Wide string assertion macros](#wide-string-assertion-macros)
  - [`XTESTS_TEST_WIDE_STRING_EQUAL(expected, actual)`](#xtests_test_wide_string_equalexpected-actual)
  - [`XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(expected, actual)`](#xtests_test_wide_string_equal_approxexpected-actual)
  - [`XTESTS_TEST_WIDE_STRING_NOT_EQUAL(expected, actual)`](#xtests_test_wide_string_not_equalexpected-actual)
  - [`XTESTS_TEST_WIDE_STRING_NOT_EQUAL_APPROX(expected, actual)`](#xtests_test_wide_string_not_equal_approxexpected-actual)
  - [`XTESTS_TEST_WIDE_STRING_EQUAL_N(expected, actual, n)`](#xtests_test_wide_string_equal_nexpected-actual-n)
  - [`XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(expected, actual, n)`](#xtests_test_wide_string_equal_n_approxexpected-actual-n)
  - [`XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(expected, actual, n)`](#xtests_test_wide_string_not_equal_nexpected-actual-n)
  - [`XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)`](#xtests_test_wide_string_not_equal_n_approxexpected-actual-n)
  - [`XTESTS_TEST_WIDE_STRING_CONTAIN(expected, actual)`](#xtests_test_wide_string_containexpected-actual)
  - [`XTESTS_TEST_WIDE_STRING_CONTAIN_APPROX(expected, actual)`](#xtests_test_wide_string_contain_approxexpected-actual)
  - [`XTESTS_TEST_WIDE_STRING_NOT_CONTAIN(expected, actual)`](#xtests_test_wide_string_not_containexpected-actual)
  - [`XTESTS_TEST_WIDE_STRING_NOT_CONTAIN_APPROX(expected, actual)`](#xtests_test_wide_string_not_contain_approxexpected-actual)
  - [`XTESTS_TEST_WIDE_STRING_SLICE_EQUAL(expected, actual)`](#xtests_test_wide_string_slice_equalexpected-actual)
- [Boolean assertion macros](#boolean-assertion-macros)
  - [`XTESTS_TEST_BOOLEAN_EQUAL(expected, actual)`](#xtests_test_boolean_equalexpected-actual)
  - [`XTESTS_TEST_BOOLEAN_NOT_EQUAL(expected, actual)`](#xtests_test_boolean_not_equalexpected-actual)
  - [`XTESTS_TEST_BOOLEAN_TRUE(actual)`](#xtests_test_boolean_trueactual)
  - [`XTESTS_TEST_BOOLEAN_FALSE(actual)`](#xtests_test_boolean_falseactual)
- [Enum assertion macros](#enum-assertion-macros)
  - [`XTESTS_TEST_ENUM_EQUAL(expected, actual)`](#xtests_test_enum_equalexpected-actual)
  - [`XTESTS_TEST_ENUM_NOT_EQUAL(expected, actual)`](#xtests_test_enum_not_equalexpected-actual)
- [Pointer assertion macros](#pointer-assertion-macros)
  - [`XTESTS_TEST_POINTER_EQUAL(expected, actual)`](#xtests_test_pointer_equalexpected-actual)
  - [`XTESTS_TEST_POINTER_NOT_EQUAL(expected, actual)`](#xtests_test_pointer_not_equalexpected-actual)
  - [`XTESTS_TEST_POINTER_GREATER(expected, actual)`](#xtests_test_pointer_greaterexpected-actual)
  - [`XTESTS_TEST_POINTER_LESS(expected, actual)`](#xtests_test_pointer_lessexpected-actual)
  - [`XTESTS_TEST_POINTER_GREATER_OR_EQUAL(expected, actual)`](#xtests_test_pointer_greater_or_equalexpected-actual)
  - [`XTESTS_TEST_POINTER_LESS_OR_EQUAL(expected, actual)`](#xtests_test_pointer_less_or_equalexpected-actual)
  - [`XTESTS_TEST_FUNCTION_POINTER_EQUAL(expected, actual)`](#xtests_test_function_pointer_equalexpected-actual)
  - [`XTESTS_TEST_FUNCTION_POINTER_NOT_EQUAL(expected, actual)`](#xtests_test_function_pointer_not_equalexpected-actual)
- [Utility functions](#utility-functions)
  - [`XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, pverbosity)`](#xtests_commandline_parse_help_or_verbosityargc-argv-pverbosity)
  - [`XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, pverbosity)`](#xtests_commandline_parse_verbosityargc-argv-pverbosity)
  - [`XTESTS_COMMANDLINE_PARSE_VERBOSITY_WITH_DEFAULT(argc, argv, pverbosity, defaultVerbosity)`](#xtests_commandline_parse_verbosity_with_defaultargc-argv-pverbosity-defaultverbosity)
  - [`XTESTS_COMMANDLINE_PARSE_HELP(argc, argv)`](#xtests_commandline_parse_helpargc-argv)
  - [`XTESTS_ARRAY_END_POST(ar)`](#xtests_array_end_postar)
- [Miscellaneous constructs](#miscellaneous-constructs)
  - [`XTESTS_FP_APPROXIMATE_FACTOR`](#xtests_fp_approximate_factor)
  - [`XTESTS_FLOATINGPOINT_FACTOR_SCOPE`](#xtests_floatingpoint_factor_scope)
- [Terse API](#terse-api)
- [C++ test helpers](#c-test-helpers)
  - [`xtests::cpp::util::temp_file`](#xtestscpputiltemp_file)
  - [`xtests::cpp::util::temp_directory`](#xtestscpputiltemp_directory)
- [Implicit linking](#implicit-linking)


## Introduction

**xTests** is a small C and C++ unit- and component-test framework. A program:

1. parses verbosity (and optionally `--help`) from the command-line;
2. starts a **test runner**;
3. runs **test cases** (inline, or as `void` functions);
4. issues **assertions** inside those cases;
5. prints results and ends the runner, updating the process exit code.

Unless a snippet is a runner, command-line, or helper fragment, examples assume an active case — after a successful `XTESTS_START_RUNNER(...)` and `XTESTS_CASE_BEGIN(...)` (or `XTESTS_RUN_CASE(...)`). Comparison macros take **expected** then **actual**. Relational macros (`GREATER`, `LESS`, …) mean *actual* compared with *expected* (`XTESTS_TEST_INTEGER_GREATER(3, 4)` passes because `4 > 3`).


## Headers

* **xtests/xtests.h** — canonical API (`XTESTS_*` macros, verbosity and flags enumerations);
* **xtests/terse-api.h** — includes **xtests.h** and defines short aliases (`TEST_INT_EQ`, `START_RUNNER`, …);
* **xtests/implicit_link.h** — Windows implicit linking of the **xtests.core** archive (no-op on compilers without implicit link);
* **xtests/util/temp_file.hpp** — C++ RAII temporary file ([C++ test helpers](#c-test-helpers));
* **xtests/util/temp_directory.hpp** — C++ RAII temporary directory ([C++ test helpers](#c-test-helpers));

```c
#include <xtests/xtests.h>
```

```c
#include <xtests/terse-api.h>
```


## Verbosity and runner flags


### `xtests_verbosity_t`

Controls how much a runner writes. Values (from **xtests.h**):

* `XTESTS_VERBOSITY_SILENT` (`-1`) — no output; status is the process return code;
* `XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR` (`0`) — runner summary only on error;
* `XTESTS_VERBOSITY_RUNNER_SUMMARY` (`1`) — runner summary always;
* `XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR` (`2`) — runner summary plus the first failing case;
* `XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR` (`3`) — runner summary plus each failing case;
* `XTESTS_VERBOSITY_CASE_SUMMARY` (`4`) — runner summary plus every case;
* `XTESTS_VERBOSITY_VERBOSE` (`9`) — maximum output;

```c
int verbosity = XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR;
```


### `xtests_runner_flags_t`

Flags passed to the `*_WITH_FLAGS*` runner macros:

* `xtestsRunnerFlagsNoWindowsDebugString` (`0x0001`) — do not also write via `OutputDebugString` on Windows;
* `xtestsReportOnlyNonEmptyCases` (`0x0002`) — omit empty cases from the report;

```c
unsigned flags = xtestsReportOnlyNonEmptyCases;
```


### `xTests_Setup_t` / `xTests_Teardown_t`

Optional callbacks invoked before and after each case when the runner is started with setup functions. Setup must return `0` to run the case; a non-zero setup result skips the case.

```c
static int setup(void* param)
{
    (void)param;
    return 0;
}

static int teardown(void* param)
{
    (void)param;
    return 0;
}
```


## Test runner functions

A **test runner** is a logically-related group of test cases.


### `XTESTS_START_RUNNER(name, verbosity)`

Starts a runner that reports to stdout.

* **name** — runner name;
* **verbosity** — `xtests_verbosity_t` (or parsed `int`);

```c
if (XTESTS_START_RUNNER("my.tests", verbosity))
{
    /* cases … */
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
}
```


### `XTESTS_START_RUNNER_WITH_SETUP_FNS(name, verbosity, setup, teardown, setupParam)`

Starts a runner that reports to stdout and calls **setup** / **teardown** around each case.

```c
if (XTESTS_START_RUNNER_WITH_SETUP_FNS("my.tests", verbosity, setup, teardown, NULL))
{
    /* cases … */
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
}
```


### `XTESTS_START_RUNNER_WITH_STREAM(name, verbosity, stm)`

Starts a runner that writes to **stm** instead of stdout.

```c
if (XTESTS_START_RUNNER_WITH_STREAM("my.tests", verbosity, stderr))
{
    /* cases … */
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
}
```


### `XTESTS_START_RUNNER_WITH_REPORTER(name, verbosity, reporter, reporterParam)`

Starts a runner with a callback reporter (`xTests_Reporter_t*`). **reporterParam** is passed to every callback.

```c
xTests_Reporter_t* reporter = /* custom reporter */;

if (XTESTS_START_RUNNER_WITH_REPORTER("my.tests", verbosity, reporter, NULL))
{
    /* cases … */
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
}
```


### `XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM(name, verbosity, reporter, reporterParam, stm)`

Callback reporter plus an explicit stream.

```c
if (XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM("my.tests", verbosity, reporter, NULL, stderr))
{
    /* cases … */
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
}
```


### `XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS(name, verbosity, reporter, reporterParam, stm, flags)`

Callback reporter, stream, and `xtests_runner_flags_t` flags.

```c
if (XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS(
        "my.tests", verbosity, reporter, NULL, stderr, xtestsReportOnlyNonEmptyCases))
{
    /* cases … */
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
}
```


### `XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(...)`

Full form: reporter, stream, flags, and setup/teardown.

```c
if (XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(
        "my.tests"
    ,   verbosity
    ,   reporter
    ,   NULL
    ,   stderr
    ,   xtestsReportOnlyNonEmptyCases
    ,   setup
    ,   teardown
    ,   NULL
    ))
{
    /* cases … */
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
}
```


### `XTESTS_START_RUNNER_WITH_FLAGS(name, verbosity, flags)`

Starts a runner that reports to stdout, with flags.

```c
if (XTESTS_START_RUNNER_WITH_FLAGS("my.tests", verbosity, xtestsReportOnlyNonEmptyCases))
{
    /* cases … */
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
}
```


### `XTESTS_PRINT_RESULTS()`

Prints results for the current runner. Call after the cases and before `XTESTS_END_RUNNER()` / `XTESTS_END_RUNNER_UPDATE_EXITCODE()`.

```c
XTESTS_PRINT_RESULTS();
```


### `XTESTS_END_RUNNER()`

Ends the current runner.

```c
XTESTS_END_RUNNER();
```


### `XTESTS_ABEND(terminationMessage)`

Abnormal end of tests and process termination, emitting **terminationMessage**.

```c
XTESTS_ABEND("cannot continue: missing fixture data");
```


### `XTESTS_END_RUNNER_UPDATE_EXITCODE(retCode)`

Ends the runner and, if any case failed, sets `*retCode` to `EXIT_FAILURE`. Initialise `*retCode` to `EXIT_SUCCESS`; multiple runners in one process only ever fail the code, never restore success.

```c
int retCode = EXIT_SUCCESS;

XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
```


## Test case functions


### `XTESTS_CASE_BEGIN(name, desc)`

Begins a case. **desc** may be `NULL` or `""`. Returns true if the case started (so assertions may run).

```c
if (XTESTS_CASE_BEGIN("addition", "2 + 2"))
{
    XTESTS_TEST_INTEGER_EQUAL(4, 2 + 2);
    XTESTS_CASE_END("addition");
}
```


### `XTESTS_CASE_END(name)`

Ends the current case. **name** is ignored in the current implementation (only one case may run at a time).

```c
XTESTS_CASE_END("addition");
```


### `XTESTS_RUN_CASE_WITH_NAME_AND_DESC(name, desc, fn)`

Runs a `void(void)` case function under the given name and description.

```c
void test_addition(void)
{
    XTESTS_TEST_INTEGER_EQUAL(4, 2 + 2);
}

XTESTS_RUN_CASE_WITH_NAME_AND_DESC("addition", "2 + 2", test_addition);
```


### `XTESTS_RUN_CASE_WITH_DESC(fn, desc)`

Runs **fn**, using the function name as the case name.

```c
XTESTS_RUN_CASE_WITH_DESC(test_addition, "2 + 2");
```


### `XTESTS_RUN_CASE(fn)`

Runs **fn** with an empty description.

```c
XTESTS_RUN_CASE(test_addition);
```


### `XTESTS_RUN_CASE_THAT_THROWS(fn, type)`

**C++ only.** Runs **fn** and expects an exception of **type**.

```cpp
void throws_runtime_error()
{
    throw std::runtime_error("boom");
}

XTESTS_RUN_CASE_THAT_THROWS(throws_runtime_error, std::runtime_error);
```


### `XTESTS_RUN_CASE_THAT_THROWS_WITH_DESC(fn, desc, type)`

**C++ only.** As `XTESTS_RUN_CASE_THAT_THROWS`, with a description.

```cpp
XTESTS_RUN_CASE_THAT_THROWS_WITH_DESC(throws_runtime_error, "must throw", std::runtime_error);
```


### `XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC(name, desc, fn, type)`

**C++ only.** As `XTESTS_RUN_CASE_THAT_THROWS`, with an explicit name and description.

```cpp
XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC(
    "throws", "must throw runtime_error", throws_runtime_error, std::runtime_error);
```


## Directed-result assertion macros


### `XTESTS_TEST_PASSED()`

Records a success without evaluating an expression.

```c
XTESTS_TEST_PASSED();
```


### `XTESTS_TEST_FAIL(msg)`

Records a failure with an explanatory message.

```c
XTESTS_TEST_FAIL("unreachable branch");
```


### `XTESTS_TEST_FAIL_WITH_QUALIFIER(msg, qualifier)`

Failure message plus a qualifier (often the unexpected value).

```c
XTESTS_TEST_FAIL_WITH_QUALIFIER("unexpected status", "E_FAIL");
```


### `XTESTS_TEST(expr)`

Succeeds when **expr** is true.

```c
XTESTS_TEST(2 + 2 == 4);
```


### `XTESTS_TEST_WITH_MESSAGE(expr, msg)`

As `XTESTS_TEST`, with a failure message.

```c
XTESTS_TEST_WITH_MESSAGE(2 + 2 == 4, "addition");
```


### `XTESTS_REQUIRE(test)`

If **test** fails, the rest of the case is skipped (further assertions that would rely on the failed condition are not executed). In C++ with exceptions this unwinds the case; in C it sets a required-condition flag.

```c
XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, p));
XTESTS_TEST_INTEGER_EQUAL(0, p->rc);
```


## User-defined type assertion macros

Values must be comparable with `==` / `!=`.


### `XTESTS_TEST_EQUAL(expected, actual)`

```cpp
XTESTS_TEST_EQUAL(Colour_Red, parse_colour("red"));
```


### `XTESTS_TEST_EQUAL_WITH_MESSAGE(expected, actual, msg)`

```cpp
XTESTS_TEST_EQUAL_WITH_MESSAGE(Colour_Red, parse_colour("red"), "parse red");
```


### `XTESTS_TEST_NOT_EQUAL(expected, actual)`

```cpp
XTESTS_TEST_NOT_EQUAL(Colour_Red, parse_colour("blue"));
```


### `XTESTS_TEST_NOT_EQUAL_WITH_MESSAGE(expected, actual, msg)`

```cpp
XTESTS_TEST_NOT_EQUAL_WITH_MESSAGE(Colour_Red, parse_colour("blue"), "parse blue");
```


## Integer assertion macros


### `XTESTS_TEST_INTEGER_EQUAL(expected, actual)`

Alias of `XTESTS_TEST_INTEGER_EQUAL_EXACT`.

```c
XTESTS_TEST_INTEGER_EQUAL(4, 2 + 2);
```


### `XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual)`

```c
XTESTS_TEST_INTEGER_EQUAL_EXACT(4, 2 + 2);
```


### `XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_INTEGER_NOT_EQUAL(5, 2 + 2);
```


### `XTESTS_TEST_INTEGER_GREATER(expected, actual)`

Passes when **actual** > **expected**.

```c
XTESTS_TEST_INTEGER_GREATER(3, 4);
```


### `XTESTS_TEST_INTEGER_LESS(expected, actual)`

Passes when **actual** < **expected**.

```c
XTESTS_TEST_INTEGER_LESS(5, 4);
```


### `XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual)`

```c
XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(4, 4);
```


### `XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)`

```c
XTESTS_TEST_INTEGER_LESS_OR_EQUAL(4, 4);
```


### `XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(begin, end, actual)`

**C++.** Passes when **actual** equals any element in `[begin, end)`.

```cpp
int const allowed[] = { 2, 4, 8 };
XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(&allowed[0], &allowed[0] + 3, 4);
```


### `XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(begin, end, actual)`

**C++.** Passes when **actual** equals none of the elements in `[begin, end)`.

```cpp
int const forbidden[] = { 1, 3, 5 };
XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(&forbidden[0], &forbidden[0] + 3, 4);
```


### `XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(expected0, expected1, actual)`

```c
XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(200, 201, status);
```


### `XTESTS_TEST_INTEGER_EQUAL_ANY_OF3(expected0, expected1, expected2, actual)`

```c
XTESTS_TEST_INTEGER_EQUAL_ANY_OF3(200, 201, 204, status);
```


## Floating-point assertion macros

Approximate comparisons use `XTESTS_FP_APPROXIMATE_FACTOR` (see [Miscellaneous constructs](#miscellaneous-constructs)). `XTESTS_TEST_FLOATINGPOINT_EQUAL` / `NOT_EQUAL` are aliases of the `_APPROX` forms.


### `XTESTS_TEST_FLOATINGPOINT_EQUAL(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_EQUAL(1.0, 1.0);
```


### `XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL(1.0, 2.0);
```


### `XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(1.0, 1.0000001);
```


### `XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(1.0, 1.1);
```


### `XTESTS_TEST_FLOATINGPOINT_EQUAL_EXACT(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_EQUAL_EXACT(1.0, 1.0);
```


### `XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_EXACT(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_EXACT(1.0, 1.0000001);
```


### `XTESTS_TEST_FLOATINGPOINT_GREATER(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_GREATER(1.0, 2.0);
```


### `XTESTS_TEST_FLOATINGPOINT_LESS(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_LESS(2.0, 1.0);
```


### `XTESTS_TEST_FLOATINGPOINT_GREATER_OR_EQUAL(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_GREATER_OR_EQUAL(1.0, 1.0);
```


### `XTESTS_TEST_FLOATINGPOINT_LESS_OR_EQUAL(expected, actual)`

```c
XTESTS_TEST_FLOATINGPOINT_LESS_OR_EQUAL(1.0, 1.0);
```


## Character assertion macros


### `XTESTS_TEST_CHARACTER_EQUAL(expected, actual)`

```c
XTESTS_TEST_CHARACTER_EQUAL('A', name[0]);
```


### `XTESTS_TEST_CHARACTER_EQUAL_EXACT(expected, actual)`

```c
XTESTS_TEST_CHARACTER_EQUAL_EXACT('A', name[0]);
```


### `XTESTS_TEST_CHARACTER_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_CHARACTER_NOT_EQUAL('Z', name[0]);
```


### `XTESTS_TEST_CHARACTER_GREATER(expected, actual)`

```c
XTESTS_TEST_CHARACTER_GREATER('A', 'B');
```


### `XTESTS_TEST_CHARACTER_LESS(expected, actual)`

```c
XTESTS_TEST_CHARACTER_LESS('B', 'A');
```


### `XTESTS_TEST_CHARACTER_GREATER_OR_EQUAL(expected, actual)`

```c
XTESTS_TEST_CHARACTER_GREATER_OR_EQUAL('A', 'A');
```


### `XTESTS_TEST_CHARACTER_LESS_OR_EQUAL(expected, actual)`

```c
XTESTS_TEST_CHARACTER_LESS_OR_EQUAL('A', 'A');
```


## Multibyte string assertion macros

`_APPROX` forms are case-insensitive. `_N` forms compare at most **n** characters (`n < 0` means “full length” on the signed-length overloads).


### `XTESTS_TEST_MULTIBYTE_STRING_EQUAL(expected, actual)`

```c
XTESTS_TEST_MULTIBYTE_STRING_EQUAL("hello", greet());
```


### `XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(expected, actual)`

```c
XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("HELLO", greet());
```


### `XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("bye", greet());
```


### `XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX(expected, actual)`

```c
XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX("BYE", greet());
```


### `XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(expected, actual, n)`

```c
XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("hello, world", greet(), 5);
```


### `XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(expected, actual, n)`

```c
XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX("HELLO, WORLD", greet(), 5);
```


### `XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(expected, actual, n)`

```c
XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N("world", greet(), 5);
```


### `XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)`

```c
XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX("WORLD", greet(), 5);
```


### `XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expected, actual)`

```c
XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("ell", "hello");
```


### `XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX(expected, actual)`

```c
XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX("ELL", "hello");
```


### `XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN(expected, actual)`

```c
XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN("xyz", "hello");
```


### `XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX(expected, actual)`

```c
XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX("XYZ", "hello");
```


### `XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(expected, actual)`

**actual** must have `len` and `ptr` members (a string slice).

```c
struct { size_t len; char const* ptr; } slice = { 5, "hello, world" };
XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("hello", slice);
```


### `XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value)`

Defined only when **shwild** is present (`shwild/shwild.h` or `shwild/shwild.hpp` included, so `XTESTS_USE_SHWILD` is set). **shwild** is optional; **xTests** does not require it, and **shwild** itself uses **xTests**.

```c
XTESTS_TEST_MULTIBYTE_STRING_MATCHES("X[0-9]*", "X8abc");
```


### `XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH(pattern, value)`

Same **shwild** condition as `XTESTS_TEST_MULTIBYTE_STRING_MATCHES`.

```c
XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("X[0-9]*", "Y0");
```


## Wide string assertion macros

Same shapes as the multibyte macros, for `wchar_t` strings.


### `XTESTS_TEST_WIDE_STRING_EQUAL(expected, actual)`

```c
XTESTS_TEST_WIDE_STRING_EQUAL(L"hello", wide_greet());
```


### `XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(expected, actual)`

```c
XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"HELLO", wide_greet());
```


### `XTESTS_TEST_WIDE_STRING_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_WIDE_STRING_NOT_EQUAL(L"bye", wide_greet());
```


### `XTESTS_TEST_WIDE_STRING_NOT_EQUAL_APPROX(expected, actual)`

```c
XTESTS_TEST_WIDE_STRING_NOT_EQUAL_APPROX(L"BYE", wide_greet());
```


### `XTESTS_TEST_WIDE_STRING_EQUAL_N(expected, actual, n)`

```c
XTESTS_TEST_WIDE_STRING_EQUAL_N(L"hello, world", wide_greet(), 5);
```


### `XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(expected, actual, n)`

```c
XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(L"HELLO, WORLD", wide_greet(), 5);
```


### `XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(expected, actual, n)`

```c
XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(L"world", wide_greet(), 5);
```


### `XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)`

```c
XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(L"WORLD", wide_greet(), 5);
```


### `XTESTS_TEST_WIDE_STRING_CONTAIN(expected, actual)`

```c
XTESTS_TEST_WIDE_STRING_CONTAIN(L"ell", L"hello");
```


### `XTESTS_TEST_WIDE_STRING_CONTAIN_APPROX(expected, actual)`

```c
XTESTS_TEST_WIDE_STRING_CONTAIN_APPROX(L"ELL", L"hello");
```


### `XTESTS_TEST_WIDE_STRING_NOT_CONTAIN(expected, actual)`

```c
XTESTS_TEST_WIDE_STRING_NOT_CONTAIN(L"xyz", L"hello");
```


### `XTESTS_TEST_WIDE_STRING_NOT_CONTAIN_APPROX(expected, actual)`

```c
XTESTS_TEST_WIDE_STRING_NOT_CONTAIN_APPROX(L"XYZ", L"hello");
```


### `XTESTS_TEST_WIDE_STRING_SLICE_EQUAL(expected, actual)`

```c
struct { size_t len; wchar_t const* ptr; } slice = { 5, L"hello, world" };
XTESTS_TEST_WIDE_STRING_SLICE_EQUAL(L"hello", slice);
```


## Boolean assertion macros


### `XTESTS_TEST_BOOLEAN_EQUAL(expected, actual)`

```c
XTESTS_TEST_BOOLEAN_EQUAL(1, is_ready());
```


### `XTESTS_TEST_BOOLEAN_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_BOOLEAN_NOT_EQUAL(1, is_empty());
```


### `XTESTS_TEST_BOOLEAN_TRUE(actual)`

```c
XTESTS_TEST_BOOLEAN_TRUE(is_ready());
```


### `XTESTS_TEST_BOOLEAN_FALSE(actual)`

```c
XTESTS_TEST_BOOLEAN_FALSE(is_empty());
```


## Enum assertion macros

Enumerators are compared as `int`. They should be of the same type.


### `XTESTS_TEST_ENUM_EQUAL(expected, actual)`

```c
XTESTS_TEST_ENUM_EQUAL(Colour_Red, parse_colour("red"));
```


### `XTESTS_TEST_ENUM_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_ENUM_NOT_EQUAL(Colour_Red, parse_colour("blue"));
```


## Pointer assertion macros


### `XTESTS_TEST_POINTER_EQUAL(expected, actual)`

```c
XTESTS_TEST_POINTER_EQUAL(p, q);
```


### `XTESTS_TEST_POINTER_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_POINTER_NOT_EQUAL(NULL, p);
```


### `XTESTS_TEST_POINTER_GREATER(expected, actual)`

```c
XTESTS_TEST_POINTER_GREATER(base, base + 1);
```


### `XTESTS_TEST_POINTER_LESS(expected, actual)`

```c
XTESTS_TEST_POINTER_LESS(base + 1, base);
```


### `XTESTS_TEST_POINTER_GREATER_OR_EQUAL(expected, actual)`

```c
XTESTS_TEST_POINTER_GREATER_OR_EQUAL(base, p);
```


### `XTESTS_TEST_POINTER_LESS_OR_EQUAL(expected, actual)`

```c
XTESTS_TEST_POINTER_LESS_OR_EQUAL(base + n, p);
```


### `XTESTS_TEST_FUNCTION_POINTER_EQUAL(expected, actual)`

```c
XTESTS_TEST_FUNCTION_POINTER_EQUAL(&handler, slot->fn);
```


### `XTESTS_TEST_FUNCTION_POINTER_NOT_EQUAL(expected, actual)`

```c
XTESTS_TEST_FUNCTION_POINTER_NOT_EQUAL(NULL, slot->fn);
```


## Utility functions


### `XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, pverbosity)`

If `--help` is present, writes usage to stdout and exits with `EXIT_SUCCESS`. Otherwise parses `--verbosity=<N>`, then `XTESTS_VERBOSITY`, then `TEST_VERBOSITY`.

```c
int verbosity;

XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);
```


### `XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, pverbosity)`

Parses `--verbosity=<N>` (then the same environment variables). Does not handle `--help`.

```c
int verbosity;

XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);
```


### `XTESTS_COMMANDLINE_PARSE_VERBOSITY_WITH_DEFAULT(argc, argv, pverbosity, defaultVerbosity)`

As `XTESTS_COMMANDLINE_PARSE_VERBOSITY`, applying **defaultVerbosity** when nothing is specified.

```c
int verbosity;

XTESTS_COMMANDLINE_PARSE_VERBOSITY_WITH_DEFAULT(
    argc, argv, &verbosity, XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR);
```


### `XTESTS_COMMANDLINE_PARSE_HELP(argc, argv)`

If `--help` is present, writes usage and exits with `EXIT_SUCCESS`.

```c
XTESTS_COMMANDLINE_PARSE_HELP(argc, argv);
```


### `XTESTS_ARRAY_END_POST(ar)`

End pointer of a static array (one-past-last). Useful with the in-range integer macros.

```c
int const allowed[] = { 2, 4, 8 };

XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(&allowed[0], XTESTS_ARRAY_END_POST(allowed), 4);
```


## Miscellaneous constructs


### `XTESTS_FP_APPROXIMATE_FACTOR`

Default factor (`1.000001`) within which floating-point values are deemed approximately equal.

```c
double const factor = XTESTS_FP_APPROXIMATE_FACTOR;
```


### `XTESTS_FLOATINGPOINT_FACTOR_SCOPE`

**C++ only.** Declares an `xtests::cpp::xtest_floatingpoint_factor_scope` that sets the close factor for its lifetime, then restores the previous value.

```cpp
XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL(5.05, 5.06);

{
    XTESTS_FLOATINGPOINT_FACTOR_SCOPE factor_scoper(1.1);

    XTESTS_TEST_FLOATINGPOINT_EQUAL(5.05, 5.06);
}
```


## Terse API

**xtests/terse-api.h** includes **xtests.h** and aliases the canonical macros to short names. The README factorial example uses this header. Representative mappings (not exhaustive; every `XTESTS_*` public macro that exists at include time gets a counterpart):

| Canonical | Terse | Extra short |
| --------- | ----- | ----------- |
| `XTESTS_START_RUNNER` | `START_RUNNER` | |
| `XTESTS_RUN_CASE` | `RUN_CASE` | |
| `XTESTS_TEST_INTEGER_EQUAL` | `TEST_INTEGER_EQUAL` | `TEST_INT_EQ` |
| `XTESTS_TEST_INTEGER_NOT_EQUAL` | `TEST_INTEGER_NOT_EQUAL` | `TEST_INT_NE` |
| `XTESTS_TEST_MULTIBYTE_STRING_EQUAL` | `TEST_MULTIBYTE_STRING_EQUAL` | `TEST_MS_EQ` |
| `XTESTS_TEST_WIDE_STRING_EQUAL` | `TEST_WIDE_STRING_EQUAL` | `TEST_WS_EQ` |
| `XTESTS_TEST_BOOLEAN_TRUE` | `TEST_BOOLEAN_TRUE` | |
| `XTESTS_TEST_POINTER_NOT_EQUAL` | `TEST_POINTER_NOT_EQUAL` | `TEST_PTR_NE` |
| `XTESTS_REQUIRE` | `REQUIRE` | |
| `XTESTS_TEST_FAIL` | `TEST_FAIL` | `FAIL` |

```c
#include <xtests/terse-api.h>

TEST_INT_EQ(4, 2 + 2);
TEST_MS_EQ("hello", greet());
REQUIRE(TEST_PTR_NE(NULL, p));
```


## C++ test helpers

These headers require exception support. Both types are string-accessible (`c_str()`, STLSoft shims).


### `xtests::cpp::util::temp_file`

Creates and manages a temporary file. Flags include `DeleteOnClose`, `EmptyOnOpen`, `EmptyOnClose`, `DeleteOnOpen`, and `CloseOnOpen`.

```cpp
#include <xtests/util/temp_file.hpp>

xtests::cpp::util::temp_file tf(
    xtests::cpp::util::temp_file::DeleteOnClose
,   "payload"
,   7
);

XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("", tf.c_str());
```


### `xtests::cpp::util::temp_directory`

Creates and manages a temporary directory. Flags include `EmptyOnOpen`, `EmptyOnClose`, `RemoveOnOpen`, and `RemoveOnClose`.

```cpp
#include <xtests/util/temp_directory.hpp>

xtests::cpp::util::temp_directory td(
    xtests::cpp::util::temp_directory::EmptyOnClose |
    xtests::cpp::util::temp_directory::RemoveOnClose
);

XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("", td.c_str());
```


## Implicit linking

On compilers that support it (notably Visual C++), including **xtests/implicit_link.h** in a translation unit of the link unit pulls in the matching **xtests.core** archive. On other compilers the header has no effect. CMake consumers should prefer `find_package(xTests)` and `xTests::core` (see [INSTALL.md](./INSTALL.md)).

```c
#include <xtests/xtests.h>
#include <xtests/implicit_link.h>
```


<!-- ########################### end of file ########################### -->

