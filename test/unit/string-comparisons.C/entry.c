/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/string-comparisons.C/entry.c
 *
 * Purpose: Unit-tests for length-limited multibyte and wide string
 *          comparison macros via the C API
 *          (`xtests_testMultibyteStringsN` /
 *          `xtests_testWideStringsN`).
 *
 * Created: 11th October 2026
 * Updated: 16th October 2026
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
static void TEST_MS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N(void);
static void TEST_MS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS(void);
static void TEST_WS_COMPARE_TO_N(void);
static void TEST_WS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N(void);
static void TEST_WS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS(void);
static void TEST_WS_COMPARE_TO_N_WITH_ptrdiff_t(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.string-comparisons.C", verbosity))
    {
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N);
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N);
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS);
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

static void TEST_MS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N(void)
{
    /* Expected is longer than |n|. The C API must bound cchExpected to
     * |n| (as the C++ c_str_len_n_* path does), so exact and limit
     * comparisons that agree on the first |n| characters succeed.
     */
    char const* expected    =   "abcdef";
    char const* actual_eq   =   "abcXYZ";
    char const* actual_ne   =   "abWXYZ";

    {
        TEST_MS_EQ_N(expected, actual_eq, 3);
        TEST_MS_EQ_N(expected, actual_eq, -3);
        TEST_MS_NE_N(expected, actual_eq, 4);
        TEST_MS_NE_N(expected, actual_eq, -4);
    }

    {
        TEST_MS_NE_N(expected, actual_ne, 3);
        TEST_MS_NE_N(expected, actual_ne, -3);
    }

    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testMultibyteStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testMultibyteStringsN(expected, actual_eq, 3, Equal)"
        ,   expected
        ,   actual_eq
        ,   3
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testMultibyteStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testMultibyteStringsN(expected, actual_eq, -3, Equal)"
        ,   expected
        ,   actual_eq
        ,   -3
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
}

static void TEST_MS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS(void)
{
    /* Neither buffer is NUL-terminated. |n| equals the readable extent, so
     * the C API must not call strlen()/walk past the arrays when obtaining
     * cchExpected / cchActual.
     */
    char    expected_eq[]   =   { 'a', 'b', 'c', 'd' };
    char    actual_eq[]     =   { 'a', 'b', 'c', 'd' };
    char    actual_ne[]     =   { 'a', 'b', 'c', 'X' };
    char    expected_approx[]   =   { 'A', 'b', 'C', 'd' };
    char    actual_approx[]     =   { 'a', 'B', 'c', 'D' };
    ptrdiff_t const n_exact =   4;
    ptrdiff_t const n_limit =   -4;

    TEST_MS_EQ_N(expected_eq, actual_eq, n_exact);
    TEST_MS_EQ_N(expected_eq, actual_eq, n_limit);
    TEST_MS_NE_N(expected_eq, actual_ne, n_exact);
    TEST_MS_NE_N(expected_eq, actual_ne, n_limit);

    TEST_MS_EQ_N_APPROX(expected_approx, actual_approx, n_exact);
    TEST_MS_EQ_N_APPROX(expected_approx, actual_approx, n_limit);

    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testMultibyteStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testMultibyteStringsN(non-NUL, n_exact, Equal)"
        ,   expected_eq
        ,   actual_eq
        ,   n_exact
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testMultibyteStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testMultibyteStringsN(non-NUL, n_limit, Equal)"
        ,   expected_eq
        ,   actual_eq
        ,   n_limit
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
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

static void TEST_WS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N(void)
{
    /* Wide counterpart of TEST_MS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N.
     */
    wchar_t const*  expected    =   L"abcdef";
    wchar_t const*  actual_eq   =   L"abcXYZ";
    wchar_t const*  actual_ne   =   L"abWXYZ";

    {
        TEST_WS_EQ_N(expected, actual_eq, 3);
        TEST_WS_EQ_N(expected, actual_eq, -3);
        TEST_WS_NE_N(expected, actual_eq, 4);
        TEST_WS_NE_N(expected, actual_eq, -4);
    }

    {
        TEST_WS_NE_N(expected, actual_ne, 3);
        TEST_WS_NE_N(expected, actual_ne, -3);
    }

    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testWideStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testWideStringsN(expected, actual_eq, 3, Equal)"
        ,   expected
        ,   actual_eq
        ,   3
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testWideStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testWideStringsN(expected, actual_eq, -3, Equal)"
        ,   expected
        ,   actual_eq
        ,   -3
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
}

static void TEST_WS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS(void)
{
    /* Wide counterpart of
     * TEST_MS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS.
     */
    wchar_t expected_eq[]   =   { L'a', L'b', L'c', L'd' };
    wchar_t actual_eq[]     =   { L'a', L'b', L'c', L'd' };
    wchar_t actual_ne[]     =   { L'a', L'b', L'c', L'X' };
    wchar_t expected_approx[]   =   { L'A', L'b', L'C', L'd' };
    wchar_t actual_approx[]     =   { L'a', L'B', L'c', L'D' };
    ptrdiff_t const n_exact =   4;
    ptrdiff_t const n_limit =   -4;

    TEST_WS_EQ_N(expected_eq, actual_eq, n_exact);
    TEST_WS_EQ_N(expected_eq, actual_eq, n_limit);
    TEST_WS_NE_N(expected_eq, actual_ne, n_exact);
    TEST_WS_NE_N(expected_eq, actual_ne, n_limit);

    TEST_WS_EQ_N_APPROX(expected_approx, actual_approx, n_exact);
    TEST_WS_EQ_N_APPROX(expected_approx, actual_approx, n_limit);

    TEST_INT_EQ(
        1
    ,   XTESTS_NS_C_QUAL(xtests_testWideStringsN)(
            __FILE__
        ,   __LINE__
        ,   XTESTS_GET_FUNCTION_()
        ,   "xtests_testWideStringsN(non-NUL, n_exact, Equal)"
        ,   expected_eq
        ,   actual_eq
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
        ,   "xtests_testWideStringsN(non-NUL, n_limit, Equal)"
        ,   expected_eq
        ,   actual_eq
        ,   n_limit
        ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)
        )
    );
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
