/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.basics2.cpp
 *
 * Purpose: Implementation file for the test.scratch.basics2 project.
 *
 * Created: 15th December 2007
 * Updated: 29th November 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#if _STLSOFT_VER >= 0x010b0000
# include <stlsoft/algorithm/literal_copy.hpp>
#else
namespace stlsoft{
    template <typename A, typename O>
    O literal_copy(A const& a0, A const& a1, A const& a2, A const& a3, O o){
        *o++ = a0; *o++ = a1; *o++ = a2; *o++ = a3; return o;
    }
}
#endif
#include <stlsoft/string/string_view.hpp>

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

static void test_1_2();
static void test_1_3();
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
static void test_2_1();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
static void test_2_2();
static void test_2_3();
static void test_2_4();
static void test_2_5();
static void test_2_6();
static void test_2_7();
static void test_2_8();
static void test_3_1();
static void test_4_1();
static void test_4_2();
static void test_5_1();
static void test_5_2();
static void test_5_3();

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.scratch.basics1.runner-1", verbosity))
    {
        /* test 0.0 */
        if (XTESTS_CASE_BEGIN("test-0", "always passes"))
        {
            XTESTS_TEST_PASSED();

            XTESTS_CASE_END("test-0");
        }

        /* test 1.0 */
        if (XTESTS_CASE_BEGIN("test-1", "checking integer values"))
        {
            XTESTS_TEST(sizeof(char) <= sizeof(short));
            XTESTS_TEST(sizeof(short) <= sizeof(int));
            XTESTS_TEST(sizeof(int) <= sizeof(long));

            XTESTS_CASE_END("test-1");
        }

        /* test 1.2 */
        XTESTS_RUN_CASE(test_1_2);

        /* test 1.3 */
        XTESTS_RUN_CASE(test_1_3);


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    if (XTESTS_START_RUNNER("test.scratch.basics1.runner-2", verbosity))
    {
        /* test 2.1 */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        XTESTS_RUN_CASE_THAT_THROWS(test_2_1, std::runtime_error);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        /* test 2.2 */
        XTESTS_RUN_CASE_WITH_DESC(test_2_2, "evaluating relationships between numbers");

        /* test 2.3 */
        XTESTS_RUN_CASE(test_2_3);

        /* test 2.4 */
        XTESTS_RUN_CASE(test_2_4);

        /* test 2.5 */
        XTESTS_RUN_CASE(test_2_5);

        /* test 2.6 */
        XTESTS_RUN_CASE(test_2_6);

        /* test 2.7 */
        XTESTS_RUN_CASE(test_2_7);

        /* test 2.8 */
        XTESTS_RUN_CASE(test_2_8);


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    if (XTESTS_START_RUNNER("test.scratch.basics1.runner-3", verbosity))
    {
        /* test 3.1 */
        XTESTS_RUN_CASE(test_3_1);


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    if (XTESTS_START_RUNNER("test.scratch.basics1.runner-4", verbosity))
    {
        /* test 4.1 */
        XTESTS_RUN_CASE(test_4_1);

        /* test 4.2 */
        XTESTS_RUN_CASE(test_4_2);


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    if (XTESTS_START_RUNNER("test.scratch.basics1.runner-5", verbosity))
    {
        XTESTS_RUN_CASE(test_5_1);
        XTESTS_RUN_CASE(test_5_2);
        XTESTS_RUN_CASE(test_5_3);


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

static void test_1_2()
{
    XTESTS_TEST(sizeof(float) <= sizeof(double));
    XTESTS_TEST(sizeof(double) <= sizeof(long double));
}

static void test_1_3()
{
    int i1 = 0;
    int i2 = 0;

    XTESTS_TEST_POINTER_NOT_EQUAL(&i1, &i2);
}

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
static void test_2_1()
{
    throw std::runtime_error("an error");
}
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

static void test_2_2()
{
#ifdef _DEBUG
    const int min_  =   -100;
    const int max_  =   +100;
#else /* ? _DEBUG */
    const int min_  =   -1000;
    const int max_  =   +1000;
#endif /* _DEBUG */

    { int i; for(i = min_; i != max_; ++i)
    {
        { int j; for(j = min_; j != max_; ++j)
        {
            if (i == j)
            {
                XTESTS_TEST_INTEGER_EQUAL(i, j);
                XTESTS_TEST_INTEGER_EQUAL_EXACT(i, j);

                XTESTS_TEST_INTEGER_LESS_OR_EQUAL(j, i);
                XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(j, i);
            }
            else
            {
                XTESTS_TEST_INTEGER_NOT_EQUAL(i, j);

                if (i < j)
                {
                    XTESTS_TEST_INTEGER_LESS(j, i);
                    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(j, i);
                }
                else
                {
                    XTESTS_TEST_INTEGER_GREATER(j, i);
                    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(j, i);
                }
            }
        }}
    }}
}

static void test_2_3()
{
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", "abc");
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("abc", "aBC");
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("abc", "aBC");
}

static void test_2_4()
{
    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", L"abc");
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL(L"abc", L"aBC");
    XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"abc", L"aBC");
}

static void test_2_5()
{
    bool    b1  =   false;
    bool    b2  =   true;

    XTESTS_TEST_BOOLEAN_EQUAL(false, b1);
    XTESTS_TEST_BOOLEAN_EQUAL(true, b2);
    XTESTS_TEST_BOOLEAN_NOT_EQUAL(true, b1);
    XTESTS_TEST_BOOLEAN_NOT_EQUAL(false, b2);
}

static void test_2_6()
{
    char    c1  =   'b';
    char    c2  =   'c';

    wchar_t wc1 =   L'b';
    wchar_t wc2 =   L'c';

    XTESTS_TEST_CHARACTER_EQUAL('b', c1);
    XTESTS_TEST_CHARACTER_EQUAL('c', c2);
    XTESTS_TEST_CHARACTER_NOT_EQUAL('c', c1);
    XTESTS_TEST_CHARACTER_NOT_EQUAL('d', c2);

    XTESTS_TEST_CHARACTER_EQUAL(L'b', wc1);
    XTESTS_TEST_CHARACTER_EQUAL(L'c', wc2);
    XTESTS_TEST_CHARACTER_NOT_EQUAL(L'c', wc1);
    XTESTS_TEST_CHARACTER_NOT_EQUAL(L'd', wc2);
}

static void test_2_7()
{
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(std::string("abc"), "abc");
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", std::string("abc"));
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(std::string("abc"), "aBC");
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("abc", std::string("aBC"));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(std::string("abc"), "aBC");
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("abc", std::string("aBC"));
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX(std::string("abc"), "aBd");
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX("abc", std::string("aBd"));
}

static void test_2_8()
{
#if 0
    XTESTS_TEST_INTEGER_EQUAL(stlsoft::sint8_t(0), stlsoft::sint8_t(1));
    XTESTS_TEST_INTEGER_EQUAL(stlsoft::uint8_t(0), stlsoft::uint8_t(1));

    XTESTS_TEST_INTEGER_EQUAL(stlsoft::sint16_t(0), stlsoft::sint16_t(1));
    XTESTS_TEST_INTEGER_EQUAL(stlsoft::uint16_t(0), stlsoft::uint16_t(1));

    XTESTS_TEST_INTEGER_EQUAL(stlsoft::sint32_t(0), stlsoft::sint32_t(1));
    XTESTS_TEST_INTEGER_EQUAL(stlsoft::uint32_t(0), stlsoft::uint32_t(1));
#endif /* 0 */

    XTESTS_TEST_INTEGER_NOT_EQUAL(stlsoft::sint64_t(0), stlsoft::sint64_t(1));
    XTESTS_TEST_INTEGER_NOT_EQUAL(stlsoft::uint64_t(0), stlsoft::uint64_t(1));

    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<signed char>(0), static_cast<signed char>(1));
    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<unsigned char>(0), static_cast<unsigned char>(1));

    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<signed short>(0), static_cast<signed short>(1));
    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<unsigned short>(0), static_cast<unsigned short>(1));

    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<signed int>(0), static_cast<signed int>(1));
    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<unsigned int>(0), static_cast<unsigned int>(1));

    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<signed long>(0), static_cast<signed long>(1));
    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<unsigned long>(0), static_cast<unsigned long>(1));

    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<size_t>(0), static_cast<size_t>(1));
    XTESTS_TEST_INTEGER_NOT_EQUAL(static_cast<ptrdiff_t>(0), static_cast<ptrdiff_t>(1));
}

static void test_3_1()
{
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("abcdef", "abcdef");
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX("abcdef", "abcdef");

    XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN("abcdef", "Abcdef");
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX("abcdef", "Abcdef");

    XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN("abcdefg", "abcdef");
    XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX("abcdefg", "abcdef");

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("abcdef", "abcdefghi");
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX("abcdef", "abcdefghi");

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("defghi", "abcdefghi");
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX("defghi", "abcdefghi");

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("def", "abcdefghi");
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX("def", "abcdefghi");
}

static void test_4_1()
{
    char                    s2[]    =   "abcdef";
    stlsoft::string_view    s1(s2, 3);
    std::string             s3      =   "AbCdEf";

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, 0);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, 1);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, 2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, 3);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 4);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, -4);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 5);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, -5);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 6);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, -6);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 7);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, -7);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 8);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, -8);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, 0);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, 1);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, 2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, 3);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 4);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, -4);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 5);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, -5);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 6);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, -6);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 7);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, -7);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 8);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(s1, s3, -8);
}

static void test_4_2()
{
    wchar_t                 s2[]    =   L"abcdef";
    stlsoft::wstring_view   s1(s2, 3);
    std::wstring            s3      =   L"AbCdEf";

    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, 0);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, 1);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, 2);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, 3);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(s1, s2, 4);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, -4);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(s1, s2, 5);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, -5);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(s1, s2, 6);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, -6);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(s1, s2, 7);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, -7);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(s1, s2, 8);
    XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, -8);

    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, 0);
    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, 1);
    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, 2);
    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, 3);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 4);
    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, -4);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 5);
    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, -5);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 6);
    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, -6);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 7);
    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, -7);
    XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(s1, s3, 8);
    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(s1, s3, -8);
}

static void test_5_1()
{
    std::vector<int>    v(2);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, v.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, v[0]);
    XTESTS_TEST_INTEGER_EQUAL(0, v[1]);
}

static void test_5_2()
{
    std::vector<int>    v(2);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, v.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, v[0]);
    XTESTS_TEST_INTEGER_EQUAL(0, v[1]);
}

static void test_5_3()
{
    {
        int const   ints[] = { 1, 2, 3, 4 };

        int const*  from    =   &ints[0];
        int const*  to      =   &ints[0] + STLSOFT_NUM_ELEMENTS(ints);

        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 0);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 1);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 2);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 3);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 4);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 5);
    }

    {
        std::vector<int>    ints;

        stlsoft::literal_copy(1, 2, 3, 4, std::back_inserter(ints));

        std::vector<int>::const_iterator    from    =   ints.begin();
        std::vector<int>::const_iterator    to      =   ints.end();

        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 0);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 1);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 2);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 3);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 4);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 5);
    }

    {
        std::list<int>  ints;

        stlsoft::literal_copy(1, 2, 3, 4, std::back_inserter(ints));

        std::list<int>::const_iterator  from    =   ints.begin();
        std::list<int>::const_iterator  to      =   ints.end();

        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 0);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 1);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 2);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 3);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 4);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 5);
    }

    {
        std::deque<int> ints;

        stlsoft::literal_copy(1, 2, 3, 4, std::back_inserter(ints));

        std::deque<int>::const_iterator from    =   ints.begin();
        std::deque<int>::const_iterator to      =   ints.end();

        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 0);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 1);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 2);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 3);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 4);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 5);
    }


    {
        std::list<int>  ints;

        ints.push_back(3);

        std::list<int>::const_iterator  from    =   ints.begin();
        std::list<int>::const_iterator  to      =   ints.end();

        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 0);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 1);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 2);
        XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(from, to, 3);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 4);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 5);
    }

    {
        std::deque<int> ints;

        std::deque<int>::const_iterator from    =   ints.begin();
        std::deque<int>::const_iterator to      =   ints.end();

        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 0);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 1);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 2);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 3);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 4);
        XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(from, to, 5);
    }
}

/* ///////////////////////////// end of file //////////////////////////// */

