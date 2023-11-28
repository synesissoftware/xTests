/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.fail_all.1.cpp
 *
 * Purpose:     Implementation file for the test.scratch.fail_all.1 project.
 *
 * Created:     26th January 2009
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/string/string_view.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <stdexcept>
#include <string>

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

namespace
{
    static void test_int_comparison_failures(void);
    static void test_multibyte_string_comparison_failures(void);
    static void test_wide_string_comparison_failures(void);
    static void test_character_comparison_failures(void);
    static void test_floating_point_comparison_failures(void);
    static void test_boolean_comparison_failures(void);
    static void test_pointer_comparison_failures(void);
    static void test_explicit_failures(void);
    static void test_missing_expected_exception_failures(void);
    static void test_unexpected_exception_failures(void);

} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.scratch.fail_all.1", verbosity))
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
    catch(std::exception &x)
    {
        ::fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
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

/* ////////////////////////////////////////////////////////////////////// */

namespace
{
    template <typename I>
    void test_int_comparison_failures_(I /* dummyToMakeVC6InstantiateCorrectly */)
    {
        XTESTS_TEST_INTEGER_EQUAL(static_cast<I>(0), static_cast<I>(-1));
        XTESTS_TEST_INTEGER_EQUAL(static_cast<I>(1), static_cast<I>(0));

        XTESTS_TEST_INTEGER_LESS(static_cast<I>(0), static_cast<I>(1));

        XTESTS_TEST_INTEGER_GREATER(static_cast<I>(1), static_cast<I>(0));
    }

    static void test_int_comparison_failures(void)
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

    static void test_multibyte_string_comparison_failures(void)
    {
        const char src[] = "abcdefghijklmnopqrstuvwxyz";

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", "xyz");
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("abc", "xyz");
        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("abc", "abc");

//      stlsoft::string_view    "

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(stlsoft::string_view(src, 3), "abcd", 4);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("abcd", "abc", -4);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX("abc", "xyz", 1);
        XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(stlsoft::string_view(src, 3), "Abc", -2);

        XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("abc", "xyz");
        XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX(stlsoft::string_view(src, 3), "xyz");
        XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN("abc", stlsoft::string_view(src, 3));
    }

    static void test_wide_string_comparison_failures(void)
    {
        XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", L"xyz");
        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"abc", L"xyz");
        XTESTS_TEST_WIDE_STRING_NOT_EQUAL(L"abc", L"abc");

        XTESTS_TEST_WIDE_STRING_EQUAL_N(L"abc", L"abcd", 4);
        XTESTS_TEST_WIDE_STRING_EQUAL_N(L"abcd", L"abc", -4);
        XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(L"abc", L"xyz", 1);
        XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(L"abc", L"Abc", -2);

        XTESTS_TEST_WIDE_STRING_CONTAIN(L"abc", L"xyz");
        XTESTS_TEST_WIDE_STRING_CONTAIN_APPROX(L"abc", L"xyz");
        XTESTS_TEST_WIDE_STRING_NOT_CONTAIN(L"abc", L"abc");
    }

    static void test_character_comparison_failures(void)
    {
        XTESTS_TEST_CHARACTER_EQUAL('a', 'b');

#ifdef __BORLANDC__
        XTESTS_TEST_CHARACTER_EQUAL((wchar_t)'a', (wchar_t)'b');
#else
        XTESTS_TEST_CHARACTER_EQUAL(L'a', L'b');
#endif
    }

    static void test_floating_point_comparison_failures(void)
    {
        XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(12345678.9, -1.23e-100);
    }

    static void test_boolean_comparison_failures(void)
    {
        XTESTS_TEST_BOOLEAN_TRUE(false);
        XTESTS_TEST_BOOLEAN_FALSE(true);
    }

    static void test_pointer_comparison_failures(void)
    {
        int i = 0;

        XTESTS_TEST_POINTER_EQUAL(NULL, &i);
    }

    static void test_explicit_failures(void)
    {
        XTESTS_TEST_FAIL("this failure was explicit");
    }

    static void test_missing_expected_exception_failures(void)
    {}

    static void test_unexpected_exception_failures(void)
    {
        throw std::runtime_error("<this was not expected!>");
    }

} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */

