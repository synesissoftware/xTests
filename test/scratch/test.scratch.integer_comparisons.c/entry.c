/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.integer_comparisons.c/entry.c
 *
 * Purpose: Scratch tests of integer comparisons, given the new
 *          implementations in terms of `_Generic`.
 *
 * Created: 3rd August 2024
 * Updated: 31st May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/terse-api.h>

/* Standard C Header Files */
#include <limits.h>

#include <xtests/internal/checked_main.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_passes(void);
static void test_fails(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.scratch.integer_comparisons.c", verbosity))
    {
        XTESTS_RUN_CASE(test_passes);
        XTESTS_RUN_CASE(test_fails);


        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function definitions
 */

static void test_passes(void)
{
    /* == */
    {
        {
            short const expected    =   -100;
            short const actual      =   -100;

            XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +100;

            XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
        }

        {
            int const expected    =   -100;
            int const actual      =   -100;

            XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
        }

        {
            unsigned int const expected   =   +100;
            unsigned int const actual     =   +100;

            XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
        }

        {
            long const expected    =   -100;
            long const actual      =   -100;

            XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
        }

        {
            unsigned long const expected   =   +100;
            unsigned long const actual     =   +100;

            XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
        }

        {
            long long const expected    =   -100;
            long long const actual      =   -100;

            XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +100;

            XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
        }

    }

    /* != */
    {
        {
            short const expected    =   -101;
            short const actual      =   -100;

            TEST_INT_NE(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +101;

            TEST_INT_NE(expected, actual);
        }

        {
            int const expected  =   -101;
            int const actual    =   -100;

            TEST_INT_NE(expected, actual);
        }

        {
            unsigned int const expected =   +100;
            unsigned int const actual   =   +101;

            TEST_INT_NE(0, actual);
            TEST_INT_NE(expected, actual);
        }

        {
            long const expected =   -101;
            long const actual   =   -100;

            TEST_INT_NE(expected, actual);
        }

        {
            unsigned long const expected    =   +100;
            unsigned long const actual      =   +101;

            TEST_INT_NE(expected, actual);
        }

        {
            long long const expected    =   -101;
            long long const actual      =   -100;

            TEST_INT_NE(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +101;

            TEST_INT_NE(expected, actual);
        }

    }

    /* < */
    {
        {
            short const expected    =   -100;
            short const actual      =   -101;

            TEST_INT_LT(expected, actual);
        }

        {
            unsigned short const expected   =   +101;
            unsigned short const actual     =   +100;

            TEST_INT_LT(expected, actual);
        }

        {
            int const expected  =   -100;
            int const actual    =   -101;

            TEST_INT_LT(expected, actual);
        }

        {
            unsigned int const expected =   +101;
            unsigned int const actual   =   +100;

            TEST_INT_LT(expected, actual);
        }

        {
            long const expected =   -100;
            long const actual   =   -101;

            TEST_INT_LT(expected, actual);
        }

        {
            unsigned long const expected    =   +101;
            unsigned long const actual      =   +100;

            TEST_INT_LT(expected, actual);
        }

        {
            long long const expected    =   -100;
            long long const actual      =   -101;

            TEST_INT_LT(expected, actual);
        }

        {
            unsigned long long const expected   =   +101;
            unsigned long long const actual     =   +100;

            TEST_INT_LT(expected, actual);
        }

    }

    /* <= */
    {
        {
            short const expected    =   -100;
            short const actual      =   -101;

            TEST_INT_LE(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +100;

            TEST_INT_LE(expected, actual);
        }

        {
            int const expected  =   -100;
            int const actual    =   -101;

            TEST_INT_LE(expected, actual);
        }

        {
            unsigned int const expected =   +100;
            unsigned int const actual   =   +100;

            TEST_INT_LE(expected, actual);
        }

        {
            long const expected =   -100;
            long const actual   =   -101;

            TEST_INT_LE(expected, actual);
        }

        {
            unsigned long const expected    =   +100;
            unsigned long const actual      =   +100;

            TEST_INT_LE(expected, actual);
        }

        {
            long long const expected    =   -100;
            long long const actual      =   -101;

            TEST_INT_LE(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +100;

            TEST_INT_LE(expected, actual);
        }
    }

    /* > */
    {
        {
            short const expected    =   -101;
            short const actual      =   -100;

            TEST_INT_GT(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +101;

            TEST_INT_GT(0, actual);
            TEST_INT_GT(expected, actual);
        }

        {
            int const expected  =   -101;
            int const actual    =   -100;

            TEST_INT_GT(expected, actual);
        }

        {
            unsigned int const expected =   +100;
            unsigned int const actual   =   +101;

            TEST_INT_GT(expected, actual);
        }

        {
            long const expected =   -101;
            long const actual   =   -100;

            TEST_INT_GT(expected, actual);
        }

        {
            unsigned long const expected    =   +100;
            unsigned long const actual      =   +101;

            TEST_INT_GT(expected, actual);
        }

        {
            long long const expected    =   -101;
            long long const actual      =   -100;

            TEST_INT_GT(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +101;

            TEST_INT_GT(expected, actual);
        }
    }

    /* >= */
    {
        {
            short const expected    =   -101;
            short const actual      =   -100;

            TEST_INT_GE(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +101;

            TEST_INT_GE(expected, actual);
        }

        {
            int const expected  =   -101;
            int const actual    =   -100;

            TEST_INT_GE(expected, actual);
        }

        {
            unsigned int const expected =   +100;
            unsigned int const actual   =   +101;

            TEST_INT_GE(expected, actual);
        }

        {
            long const expected =   -101;
            long const actual   =   -100;

            TEST_INT_GE(expected, actual);
        }

        {
            unsigned long const expected    =   +100;
            unsigned long const actual      =   +101;

            TEST_INT_GE(expected, actual);
        }

        {
            long long const expected    =   -101;
            long long const actual      =   -100;

            TEST_INT_GE(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +101;

            TEST_INT_GE(expected, actual);
        }

    }

}

static void test_fails(void)
{
    /* == (short) */
    {
        short const expected    =   123;
        short const actual      =   124;

        XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual);
    }

    /* != (unsigned short) */
    {
        unsigned short const expected   =   123;
        unsigned short const actual     =   123;

        TEST_INT_NE(expected, actual);
    }

    /* < (int) */
    {
        int const expected  =   123;
        int const actual    =   123;

        TEST_INT_LT(expected, actual);
    }

    /* <= (unsigned int) */
    {
        unsigned short const expected   =   123;
        unsigned short const actual     =   124;

        TEST_INT_LE(expected, actual);
    }

    /* > (long) */
    {
        long const expected =   124;
        long const actual   =   123;

        TEST_INT_GT(expected, actual);
    }

    /* > (unsigned long) */
    {
        unsigned long const expected    =   124;
        unsigned long const actual      =   123;

        TEST_INT_GE(expected, actual);
    }

    /* > (long long) */
    {
        long long const expected    =   LLONG_MAX;
        long long const actual      =   LLONG_MIN;

        TEST_INT_GT(expected, actual);
    }

    /* >= (unsigned long long) */
    {
        unsigned long long const expected   =   ULLONG_MAX;
        unsigned long long const actual     =   0;

        TEST_INT_GE(expected, actual);
    }
}

/* ///////////////////////////// end of file //////////////////////////// */

