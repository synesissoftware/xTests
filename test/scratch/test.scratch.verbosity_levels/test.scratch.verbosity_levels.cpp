/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.verbosity_levels.cpp
 *
 * Purpose: Implementation file for the test.scratch.verbosity_levels project.
 *
 * Created: 28th January 2017
 * Updated: 28th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/xtests.h>

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

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_succeeded();
static void test_integer_failed();
static void test_exception_expected_runtime_error();
static void test_exception_unexpected();


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP(argc, argv);
    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.scratch.verbosity_levels", verbosity))
    {
        XTESTS_RUN_CASE(test_succeeded);
        XTESTS_RUN_CASE(test_integer_failed);
        XTESTS_RUN_CASE_THAT_THROWS(test_exception_expected_runtime_error, std::runtime_error);
        XTESTS_RUN_CASE(test_exception_unexpected);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        res = main_(argc, argv);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch (std::exception &x)
    {
        ::fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch (...)
    {
        ::fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
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

    XTESTS_TEST_INTEGER_NOT_EQUAL(i1, i2);
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

