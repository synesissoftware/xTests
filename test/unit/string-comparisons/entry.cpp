/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/string-comparisons/entry.cpp
 *
 * Purpose: Unit-tests for multibyte and wide string comparison macros,
 *          including length-limited forms, `std::string`, and equal-any-of,
 *          exact and case-insensitive.
 *
 * Created: 21st October 2024
 * Updated: 31st October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <xtests/terse-api.h>

/* /////////////////////////////////////
 * general includes
 */

/* STLSoft header files */
#include <stlsoft/util/string/snprintf.h>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stddef.h>
#include <stdlib.h>

/* /////////////////////////////////////
 * final includes
 */

/* xTests header files */
#include <xtests/internal/checked_main.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_MS_COMPARE_TO_N();
    static void TEST_MS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N();
    static void TEST_MS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS();
    static void TEST_MS_COMPARE_TO_N_WITH_std_string();
    static void TEST_MS_EQUAL_ANY_OF();
    static void TEST_MS_EQUAL_ANY_OF_APPROX();
    static void TEST_WS_COMPARE_TO_N();
    static void TEST_WS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N();
    static void TEST_WS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS();
    static void TEST_WS_COMPARE_TO_N_WITH_std_wstring();
    static void TEST_WS_COMPARE_TO_N_WITH_ptrdiff_t();

    static void test_Pantheios_broken_example();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.string-comparisons", verbosity))
    {
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N);
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N);
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS);
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N_WITH_std_string);
        XTESTS_RUN_CASE(TEST_MS_EQUAL_ANY_OF);
        XTESTS_RUN_CASE(TEST_MS_EQUAL_ANY_OF_APPROX);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N_WITH_std_wstring);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N_WITH_ptrdiff_t);

        XTESTS_RUN_CASE(test_Pantheios_broken_example);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void TEST_MS_COMPARE_TO_N()
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

static void TEST_MS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N()
{
    /* Expected is longer than |n|. Both the C API and the C++ template
     * path must bound cchExpected to |n|.
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

    std::string const   expected_s(expected);
    std::string const   actual_eq_s(actual_eq);

    TEST_MS_EQ_N(expected_s, actual_eq_s, 3);
    TEST_MS_EQ_N(expected_s, actual_eq_s, -3);
    TEST_MS_NE_N(expected_s, actual_eq_s, 4);
    TEST_MS_NE_N(expected_s, actual_eq_s, -4);
}

static void TEST_MS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS()
{
    /* Neither buffer is NUL-terminated. |n| equals the readable extent, so
     * length discovery must not call strlen() past the arrays.
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

static void TEST_MS_COMPARE_TO_N_WITH_std_string()
{
    std::string const   s1("abc");
    std::string const   s2("abcdef");
    std::string const   s3("AbCdEf");

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
        TEST_MS_EQ_N(s1, s2, s1.size());
        TEST_MS_EQ_N_APPROX(s1, s2, s1.size());
        TEST_MS_NE_N(s1, s3, 3);
        TEST_MS_EQ_N_APPROX(s1, s3, 3);
        TEST_MS_NE_N(s2, s3, 3);
        TEST_MS_EQ_N_APPROX(s2, s3, 3);
    }

    {
        TEST_MS_EQ_N(s1, s2, -long(s1.size()));
        TEST_MS_EQ_N_APPROX(s1, s2, -long(s1.size()));
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

static void TEST_MS_EQUAL_ANY_OF()
{
    char const* const   colours[]   =   {
        "red",
        "green",
        "blue",
    };
    std::string const   actual("green");

    TEST_MS_EQ_ANY_OF(colours, STLSOFT_NUM_ELEMENTS(colours), "red");
    TEST_MS_EQ_ANY_OF(colours, STLSOFT_NUM_ELEMENTS(colours), actual);
    TEST_MS_EQ_ANY_OF2("red", std::string("green"), actual);
    TEST_MS_EQ_ANY_OF3("red", actual, std::string("blue"), "blue");
}

static void TEST_MS_EQUAL_ANY_OF_APPROX()
{
    char const* const   colours[]   =   {
        "red",
        "green",
        "blue",
    };
    std::string const   actual("Green");

    TEST_MS_EQ_ANY_OF_APPROX(colours, STLSOFT_NUM_ELEMENTS(colours), "RED");
    TEST_MS_EQ_ANY_OF_APPROX(colours, STLSOFT_NUM_ELEMENTS(colours), actual);
    TEST_MS_EQ_ANY_OF2_APPROX("red", std::string("green"), actual);
    TEST_MS_EQ_ANY_OF3_APPROX("red", actual, std::string("blue"), "BLUE");
}

static void TEST_WS_COMPARE_TO_N()
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

static void TEST_WS_COMPARE_TO_N_WHEN_EXPECTED_LONGER_THAN_N()
{
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

    std::wstring const  expected_s(expected);
    std::wstring const  actual_eq_s(actual_eq);

    TEST_WS_EQ_N(expected_s, actual_eq_s, 3);
    TEST_WS_EQ_N(expected_s, actual_eq_s, -3);
    TEST_WS_NE_N(expected_s, actual_eq_s, 4);
    TEST_WS_NE_N(expected_s, actual_eq_s, -4);
}

static void TEST_WS_COMPARE_TO_N_WITH_NON_NUL_TERMINATED_BUFFERS()
{
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

static void TEST_WS_COMPARE_TO_N_WITH_std_wstring()
{
    std::wstring const  s1(L"abc");
    std::wstring const  s2(L"abcdef");
    std::wstring const  s3(L"AbCdEf");

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
        TEST_WS_EQ_N(s1, s2, s1.size());
        TEST_WS_EQ_N_APPROX(s1, s2, s1.size());
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

static void TEST_WS_COMPARE_TO_N_WITH_ptrdiff_t()
{
    wchar_t const*  expected    =   L"abc";
    wchar_t const*  actual      =   L"abcdef";
    ptrdiff_t       n_exact     =   3;
    ptrdiff_t       n_limit     =   -4;
    ptrdiff_t       n_too_long  =   4;

    /* Prefer the C API overload of xtests_testWideStringsN (wchar_t const*,
     * ptrdiff_t) over the C++ template when both arguments are pointers and
     * n is an explicit ptrdiff_t.
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

static void test_Pantheios_broken_example()
{
   struct s {
       static
       void
       pantheios_util_formatYearToString4(
           unsigned    year
       ,   char      (*ar)[4]
       ) ss_noexcept_k
       {
           (*ar)[0]    =   '0' + ((year / 1000) % 10);
           (*ar)[1]    =   '0' + ((year /  100) % 10);
           (*ar)[2]    =   '0' + ((year /   10) % 10);
           (*ar)[3]    =   '0' + ((year /    1) % 10);
       }
   };

   {
       char  sz[4];
       char  expected_non_nul[] = { '0', '0', '0', '0' };

       s::pantheios_util_formatYearToString4(0, &sz);

       TEST_MS_EQ_N("0000", sz, 4);
       /* Both sides non-NUL-terminated, exact length 4. */
       TEST_MS_EQ_N(expected_non_nul, sz, 4);
       TEST_MS_EQ_N(expected_non_nul, sz, -4);
   }

   {
       char  sz[4];

       for (unsigned year = 1; year != 1000; ++year)
       {
           s::pantheios_util_formatYearToString4(year, &sz);

           char expected[5];

           snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), ("%04d"), year);

           TEST_MS_EQ_N(expected, sz, 4);
       }
   }
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

