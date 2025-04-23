/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.basics1/entry.c
 *
 * Purpose: Illustrates various xTests facilities available to C code.
 *
 * Created: 15th December 2007
 * Updated: 23rd April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/terse-api.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_2(void);
static void test_3(void);
static void test_3_any_of(void);
static void test_5(void);

static void test_4_1(void);
static void test_4_2(void);

static void test_require(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

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

        /* test 3 */
        XTESTS_RUN_CASE_WITH_DESC(test_3, "evaluating relationships between numbers");
        XTESTS_RUN_CASE_WITH_DESC(test_3_any_of, "evaluating matching groups of numbers");

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


/* /////////////////////////////////////////////////////////////////////////
 * test function definitions
 */

static void test_2(void)
{
    XTESTS_TEST(sizeof(float) <= sizeof(double));
    XTESTS_TEST(sizeof(double) <= sizeof(long double));
}

static void test_3(void)
{
    { int i; for (i = -1000; i != 1000; ++i)
    {
        { int j; for (j = -1000; j != 1000; ++j)
        {
            if (i == j)
            {
                TEST_INT_EQ(i, j);
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

static void test_3_any_of(void)
{
    {
        int const actual = 123;

        XTESTS_TEST_INTEGER_EQUAL_ANY_OF3(122, 123, 124, actual);
    }
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

    TEST_INT_EQ(i1, i1);
    TEST_INT_EQ(i2, i2);
    TEST_INT_EQ(i3, i3);
    TEST_INT_EQ(i4, i4);
    TEST_INT_EQ(i5, i5);
    TEST_INT_EQ(i6, i6);
    TEST_INT_EQ(i7, i7);
    TEST_INT_EQ(i8, i8);
}

static void test_4_1(void)
{
    char    s1[]    =   "abc";
    char    s2[]    =   "abcdef";
    char    s3[]    =   "AbCdEf";

    TEST_MS_EQ_N(s1, s2, 0);
    TEST_MS_EQ_N(s1, s2, 1);
    TEST_MS_EQ_N(s1, s2, 2);
    TEST_MS_EQ_N(s1, s2, 3);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 4);
    TEST_MS_EQ_N(s1, s2, -4);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 5);
    TEST_MS_EQ_N(s1, s2, -5);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 6);
    TEST_MS_EQ_N(s1, s2, -6);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 7);
    TEST_MS_EQ_N(s1, s2, -7);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(s1, s2, 8);
    TEST_MS_EQ_N(s1, s2, -8);

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

#if defined(_MSC_VER) &&\
    _MSC_VER >= 1935

# pragma warning(push)
# pragma warning(disable : 6011)
#endif

static void test_require(void)
{
    int* const pi = NULL;

    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, pi));

    /* should not get here */
    TEST_INT_EQ(0, *pi);
}

#if defined(_MSC_VER) &&\
    _MSC_VER >= 1935

# pragma warning(pop)
#endif


/* ///////////////////////////// end of file //////////////////////////// */

