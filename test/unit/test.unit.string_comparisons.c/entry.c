/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.string_comparisons.c/entry.c
 *
 * Purpose: Unit-tests for length-limited multibyte and wide string
 *          comparison macros via the C API
 *          (`xtests_testMultibyteStringsN` /
 *          `xtests_testWideStringsN`).
 *
 * Created: 11th October 2026
 * Updated: 11th October 2026
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

/* Standard C Header Files */
#include <stddef.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.h>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_MS_COMPARE_TO_N(void);
static void TEST_WS_COMPARE_TO_N(void);
static void TEST_WS_COMPARE_TO_N_WITH_ptrdiff_t(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.string_comparisons.c", verbosity))
    {
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N_WITH_ptrdiff_t);

        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void TEST_MS_COMPARE_TO_N(void)
{
    char    s1[]    =   "abc";
    char    s2[]    =   "abcdef";
    char    s3[]    =   "AbCdEf";

    {
        TEST_MS_EQ_N(s1, s2, 0);
        TEST_MS_EQ_N_APPROX(s1, s2, 0);
        TEST_MS_EQ_N(s1, s3, 0);
        TEST_MS_EQ_N_APPROX(s1, s3, 0);
        TEST_MS_EQ_N(s2, s3, 0);
        TEST_MS_EQ_N_APPROX(s2, s3, 0);
    }

    {
        TEST_MS_EQ_N(s1, s2, 2);
        TEST_MS_EQ_N_APPROX(s1, s2, 2);
        TEST_MS_NE_N(s1, s3, 2);
        TEST_MS_EQ_N_APPROX(s1, s3, 2);
        TEST_MS_NE_N(s2, s3, 2);
        TEST_MS_EQ_N_APPROX(s2, s3, 2);
    }

    {
        TEST_MS_EQ_N(s1, s2, -2);
        TEST_MS_EQ_N_APPROX(s1, s2, -2);
        TEST_MS_NE_N(s1, s3, -2);
        TEST_MS_EQ_N_APPROX(s1, s3, -2);
        TEST_MS_NE_N(s2, s3, -2);
        TEST_MS_EQ_N_APPROX(s2, s3, -2);
    }

    {
        TEST_MS_EQ_N(s1, s2, 3);
        TEST_MS_EQ_N_APPROX(s1, s2, 3);
        TEST_MS_NE_N(s1, s3, 3);
        TEST_MS_EQ_N_APPROX(s1, s3, 3);
        TEST_MS_NE_N(s2, s3, 3);
        TEST_MS_EQ_N_APPROX(s2, s3, 3);
    }

    {
        TEST_MS_EQ_N(s1, s2, -3);
        TEST_MS_EQ_N_APPROX(s1, s2, -3);
        TEST_MS_NE_N(s1, s3, -3);
        TEST_MS_EQ_N_APPROX(s1, s3, -3);
        TEST_MS_NE_N(s2, s3, -3);
        TEST_MS_EQ_N_APPROX(s2, s3, -3);
    }

    {
        TEST_MS_NE_N(s1, s2, 4);
        TEST_MS_NE_N_APPROX(s1, s2, 4);
        TEST_MS_NE_N(s1, s3, 4);
        TEST_MS_NE_N_APPROX(s1, s3, 4);
        TEST_MS_NE_N(s2, s3, 4);
        TEST_MS_EQ_N_APPROX(s2, s3, 4);
    }

    {
        TEST_MS_EQ_N(s1, s2, -4);
        TEST_MS_EQ_N_APPROX(s1, s2, -4);
        TEST_MS_NE_N(s1, s3, -4);
        TEST_MS_EQ_N_APPROX(s1, s3, -4);
        TEST_MS_NE_N(s2, s3, -4);
        TEST_MS_EQ_N_APPROX(s2, s3, -4);
    }
}

static void TEST_WS_COMPARE_TO_N(void)
{
    wchar_t s1[]    =   L"abc";
    wchar_t s2[]    =   L"abcdef";
    wchar_t s3[]    =   L"AbCdEf";

    {
        TEST_WS_EQ_N(s1, s2, 0);
        TEST_WS_EQ_N_APPROX(s1, s2, 0);
        TEST_WS_EQ_N(s1, s3, 0);
        TEST_WS_EQ_N_APPROX(s1, s3, 0);
        TEST_WS_EQ_N(s2, s3, 0);
        TEST_WS_EQ_N_APPROX(s2, s3, 0);
    }

    {
        TEST_WS_EQ_N(s1, s2, 2);
        TEST_WS_EQ_N_APPROX(s1, s2, 2);
        TEST_WS_NE_N(s1, s3, 2);
        TEST_WS_EQ_N_APPROX(s1, s3, 2);
        TEST_WS_NE_N(s2, s3, 2);
        TEST_WS_EQ_N_APPROX(s2, s3, 2);
    }

    {
        TEST_WS_EQ_N(s1, s2, -2);
        TEST_WS_EQ_N_APPROX(s1, s2, -2);
        TEST_WS_NE_N(s1, s3, -2);
        TEST_WS_EQ_N_APPROX(s1, s3, -2);
        TEST_WS_NE_N(s2, s3, -2);
        TEST_WS_EQ_N_APPROX(s2, s3, -2);
    }

    {
        TEST_WS_EQ_N(s1, s2, 3);
        TEST_WS_EQ_N_APPROX(s1, s2, 3);
        TEST_WS_NE_N(s1, s3, 3);
        TEST_WS_EQ_N_APPROX(s1, s3, 3);
        TEST_WS_NE_N(s2, s3, 3);
        TEST_WS_EQ_N_APPROX(s2, s3, 3);
    }

    {
        TEST_WS_EQ_N(s1, s2, -3);
        TEST_WS_EQ_N_APPROX(s1, s2, -3);
        TEST_WS_NE_N(s1, s3, -3);
        TEST_WS_EQ_N_APPROX(s1, s3, -3);
        TEST_WS_NE_N(s2, s3, -3);
        TEST_WS_EQ_N_APPROX(s2, s3, -3);
    }

    {
        TEST_WS_NE_N(s1, s2, 4);
        TEST_WS_NE_N_APPROX(s1, s2, 4);
        TEST_WS_NE_N(s1, s3, 4);
        TEST_WS_NE_N_APPROX(s1, s3, 4);
        TEST_WS_NE_N(s2, s3, 4);
        TEST_WS_EQ_N_APPROX(s2, s3, 4);
    }

    {
        TEST_WS_EQ_N(s1, s2, -4);
        TEST_WS_EQ_N_APPROX(s1, s2, -4);
        TEST_WS_NE_N(s1, s3, -4);
        TEST_WS_EQ_N_APPROX(s1, s3, -4);
        TEST_WS_NE_N(s2, s3, -4);
        TEST_WS_EQ_N_APPROX(s2, s3, -4);
    }
}

static void TEST_WS_COMPARE_TO_N_WITH_ptrdiff_t(void)
{
    wchar_t const*  expected    =   L"abc";
    wchar_t const*  actual      =   L"abcdef";
    ptrdiff_t       n_exact     =   3;
    ptrdiff_t       n_limit     =   -4;
    ptrdiff_t       n_too_long  =   4;

    /* Exercises the C API of xtests_testWideStringsN with an explicit
     * ptrdiff_t length (the type of the public n parameter).
     */
    TEST_WS_EQ_N(expected, actual, n_exact);
    TEST_WS_EQ_N(expected, actual, n_limit);
    TEST_WS_NE_N(expected, actual, n_too_long);

    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testWideStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testWideStringsN(expected, actual, n_exact, Equal)"
        ,   expected
        ,   actual
        ,   n_exact
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testWideStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testWideStringsN(expected, actual, n_limit, Equal)"
        ,   expected
        ,   actual
        ,   n_limit
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
}


/* ///////////////////////////// end of file //////////////////////////// */
