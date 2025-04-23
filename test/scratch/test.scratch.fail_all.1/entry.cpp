/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.fail_all.1/entry.cpp
 *
 * Purpose: Illustrates various test failures.
 *
 * Created: 26th January 2009
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
#include <stlsoft/string/string_view.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <stdexcept>
#include <string>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.hpp>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_int_comparison_failures();
    static void test_multibyte_string_comparison_failures();
    static void test_wide_string_comparison_failures();
    static void test_character_comparison_failures();
    static void test_floating_point_comparison_failures();
    static void test_boolean_comparison_failures();
    static void test_pointer_comparison_failures();
    static void test_explicit_failures();
    static void test_missing_expected_exception_failures();
    static void test_unexpected_exception_failures();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.scratch.fail_all.1", verbosity))
    {
        XTESTS_RUN_CASE_WITH_DESC(test_int_comparison_failures, "expects failures in integer comparisons");
        XTESTS_RUN_CASE_WITH_DESC(test_multibyte_string_comparison_failures, "expects failures in multibyte string comparisons");
        XTESTS_RUN_CASE_WITH_DESC(test_wide_string_comparison_failures, "expects failures in wide string comparisons");
        XTESTS_RUN_CASE_WITH_DESC(test_character_comparison_failures, "expects failures in integer comparisons");
        XTESTS_RUN_CASE_WITH_DESC(test_floating_point_comparison_failures, "expects failures in integer comparisons");
        XTESTS_RUN_CASE_WITH_DESC(test_boolean_comparison_failures, "expects failures in integer comparisons");

        XTESTS_RUN_CASE_WITH_DESC(test_pointer_comparison_failures, "expects failures in pointer comparisons");

        XTESTS_RUN_CASE_WITH_DESC(test_explicit_failures, "expects explicit failures");

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        XTESTS_RUN_CASE_THAT_THROWS_WITH_DESC(test_missing_expected_exception_failures, "expects failures due to missing expected exception", std::runtime_error);
#endif
        XTESTS_RUN_CASE_WITH_DESC(test_unexpected_exception_failures, "expects failures due to unexpected exception");

        /* XTESTS_ABEND("expected an abnormal exit"); */

        XTESTS_END_RUNNER();
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{
    template <typename I>
    void test_int_comparison_failures_(I /* dummyToMakeVC6InstantiateCorrectly */)
    {
        TEST_INT_EQ(static_cast<I>(0), static_cast<I>(-1));
        TEST_INT_EQ(static_cast<I>(1), static_cast<I>(0));

        TEST_INT_LE(static_cast<I>(0), static_cast<I>(1));

        TEST_INT_GT(static_cast<I>(1), static_cast<I>(0));
    }

    static void test_int_comparison_failures()
    {
        test_int_comparison_failures_(static_cast<short>(0));
        test_int_comparison_failures_(static_cast<unsigned short>(0));
        test_int_comparison_failures_(static_cast<int>(0));
        test_int_comparison_failures_(static_cast<unsigned int>(0));
        test_int_comparison_failures_(static_cast<long>(0));
        test_int_comparison_failures_(static_cast<unsigned long>(0));
        test_int_comparison_failures_(stlsoft::sint64_t(0));
        test_int_comparison_failures_(stlsoft::uint64_t(0));
    }

    static void test_multibyte_string_comparison_failures()
    {
        const char src[] = "abcdefghijklmnopqrstuvwxyz";

        TEST_MS_EQ("abc", "xyz");
        TEST_MS_EQ_APPROX("abc", "xyz");
        TEST_MS_NE("abc", "abc");

//      stlsoft::string_view    "

        TEST_MS_EQ_N(stlsoft::string_view(src, 3), "abcd", 4);
        TEST_MS_EQ_N("abcd", "abc", -4);
        TEST_MS_EQ_N_APPROX("abc", "xyz", 1);
        TEST_MS_NE_N_APPROX(stlsoft::string_view(src, 3), "Abc", -2);

        TEST_MS_CONTAIN("abc", "xyz");
        TEST_MS_CONTAIN_APPROX(stlsoft::string_view(src, 3), "xyz");
        TEST_MS_NOT_CONTAIN("abc", stlsoft::string_view(src, 3));
    }

    static void test_wide_string_comparison_failures()
    {
        TEST_WS_EQ(L"abc", L"xyz");
        TEST_WS_EQ_APPROX(L"abc", L"xyz");
        TEST_WS_NE(L"abc", L"abc");

        TEST_WS_EQ_N(L"abc", L"abcd", 4);
        TEST_WS_EQ_N(L"abcd", L"abc", -4);
        TEST_WS_EQ_N_APPROX(L"abc", L"xyz", 1);
        TEST_WS_NE_N_APPROX(L"abc", L"Abc", -2);

        TEST_WS_CONTAIN(L"abc", L"xyz");
        TEST_WS_CONTAIN_APPROX(L"abc", L"xyz");
        TEST_WS_NOT_CONTAIN(L"abc", L"abc");
    }

    static void test_character_comparison_failures()
    {
        TEST_CHAR_EQ('a', 'b');

#ifdef __BORLANDC__

        TEST_CHAR_EQ((wchar_t)'a', (wchar_t)'b');
#else

        TEST_CHAR_EQ(L'a', L'b');
#endif
    }

    static void test_floating_point_comparison_failures()
    {
        TEST_FP_EQ_APPROX(12345678.9, -1.23e-100);
    }

    static void test_boolean_comparison_failures()
    {
        TEST_BOOLEAN_TRUE(false);
        TEST_BOOLEAN_FALSE(true);
    }

    static void test_pointer_comparison_failures()
    {
        int i = 0;

        TEST_PTR_EQ(NULL, &i);
    }

    static void test_explicit_failures()
    {
        TEST_FAIL("this failure was explicit");
    }

    static void test_missing_expected_exception_failures()
    {}

    static void test_unexpected_exception_failures()
    {
        throw std::runtime_error("<this was not expected!>");
    }
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

