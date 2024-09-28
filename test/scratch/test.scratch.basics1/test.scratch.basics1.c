/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.basics1.c
 *
 * Purpose: Illustrates various xTests facilities available to C code.
 *
 * Created: 15th December 2007
 * Updated: 28th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_2(void);
static void test_4(void);
static void test_5(void);

static void test_4_1(void);
static void test_4_2(void);

static void test_require(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.scratch.basics1.c", verbosity))
    {
        /* test 1 */
        if (XTESTS_CASE_BEGIN("test-1", "checking integer values"))
        {
            XTESTS_TEST(sizeof(char) <= sizeof(short));
            XTESTS_TEST(sizeof(short) <= sizeof(int));
            XTESTS_TEST(sizeof(int) <= sizeof(long));

            XTESTS_CASE_END("test-1");
        }

        /* test 2 */
        XTESTS_RUN_CASE(test_2);

        /* test 4 */
        XTESTS_RUN_CASE_WITH_DESC(test_4, "evaluating relationships between numbers");

        /* test 5 */
        XTESTS_RUN_CASE_WITH_DESC(test_5, "ensuring all integral types are supported");

        /* test 4.1 */
        XTESTS_RUN_CASE_WITH_DESC(test_4_1, "length-limited string comparisons");
        /* test 4.2 */
        XTESTS_RUN_CASE_WITH_DESC(test_4_2, "length-limited string comparisons");

        /* test require */
        XTESTS_RUN_CASE_WITH_DESC(test_require, "illustrates use of XTESTS_REQUIRE");



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

    res = main_(argc, argv);

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function definitions
 */

static void test_2(void)
{
    XTESTS_TEST(sizeof(float) <= sizeof(double));
    XTESTS_TEST(sizeof(double) <= sizeof(long double));
}

static void test_4(void)
{
    { int i; for (i = -1000; i != 1000; ++i)
    {
        { int j; for (j = -1000; j != 1000; ++j)
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

static void test_5(void)
{
    signed char     i1 = 1;
    unsigned char   i2 = 2;
    signed short    i3 = 3;
    unsigned short  i4 = 4;
    signed int      i5 = 5;
    unsigned int    i6 = 6;
    signed long     i7 = 7;
    unsigned long   i8 = 8;

    XTESTS_TEST_INTEGER_EQUAL(i1, i1);
    XTESTS_TEST_INTEGER_EQUAL(i2, i2);
    XTESTS_TEST_INTEGER_EQUAL(i3, i3);
    XTESTS_TEST_INTEGER_EQUAL(i4, i4);
    XTESTS_TEST_INTEGER_EQUAL(i5, i5);
    XTESTS_TEST_INTEGER_EQUAL(i6, i6);
    XTESTS_TEST_INTEGER_EQUAL(i7, i7);
    XTESTS_TEST_INTEGER_EQUAL(i8, i8);
}

static void test_4_1(void)
{
    char    s1[]    =   "abc";
    char    s2[]    =   "abcdef";
    char    s3[]    =   "AbCdEf";

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

static void test_4_2(void)
{
    wchar_t s1[]    =   L"abc";
    wchar_t s2[]    =   L"abcdef";
    wchar_t s3[]    =   L"AbCdEf";

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

static void test_require(void)
{
    int* const pi = NULL;

    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, pi));

    XTESTS_TEST_INTEGER_EQUAL(0, *pi);
}


/* ///////////////////////////// end of file //////////////////////////// */

