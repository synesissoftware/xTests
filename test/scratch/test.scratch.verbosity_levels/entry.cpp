/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.verbosity_levels/entry.cpp
 *
 * Purpose: Illustrates some canonical failures (C++ code).
 *
 * Created: 28th January 2017
 * Updated: 23rd April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/terse-api.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <deque>
#include <exception>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.hpp>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_succeeded();
static void test_integer_failed();
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

static void test_exception_expected_runtime_error();
static void test_exception_unexpected();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.scratch.verbosity_levels", verbosity))
    {
        XTESTS_RUN_CASE(test_succeeded);
        XTESTS_RUN_CASE(test_integer_failed);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        XTESTS_RUN_CASE_THAT_THROWS(test_exception_expected_runtime_error, std::runtime_error);
        XTESTS_RUN_CASE(test_exception_unexpected);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_succeeded()
{
    XTESTS_TEST(sizeof(float) <= sizeof(double));
    XTESTS_TEST(sizeof(double) <= sizeof(long double));
}

static void test_integer_failed()
{
    int const i1 = 0;
    int const i2 = 0;

    TEST_INT_NE(i1, i2);
}
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

static void test_exception_expected_runtime_error()
{
    throw std::runtime_error("an error");
}

static void test_exception_unexpected()
{
    throw std::runtime_error("an error");
}
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/* ///////////////////////////// end of file //////////////////////////// */

