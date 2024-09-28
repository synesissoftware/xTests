/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.integer_comparisons.c.c
 *
 * Purpose: Scratch tests of integer comparisons, given the new
 *          implementations in terms of `_Generic`.
 *
 * Created: 3rd August 2024
 * Updated: 28th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

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

    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

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

            XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +101;

            XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
        }

        {
            int const expected  =   -101;
            int const actual    =   -100;

            XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
        }

        {
            unsigned int const expected =   +100;
            unsigned int const actual   =   +101;

            XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
        }

        {
            long const expected =   -101;
            long const actual   =   -100;

            XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
        }

        {
            unsigned long const expected    =   +100;
            unsigned long const actual      =   +101;

            XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
        }

        {
            long long const expected    =   -101;
            long long const actual      =   -100;

            XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +101;

            XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
        }

    }

    /* < */
    {
        {
            short const expected    =   -100;
            short const actual      =   -101;

            XTESTS_TEST_INTEGER_LESS(expected, actual);
        }

        {
            unsigned short const expected   =   +101;
            unsigned short const actual     =   +100;

            XTESTS_TEST_INTEGER_LESS(expected, actual);
        }

        {
            int const expected  =   -100;
            int const actual    =   -101;

            XTESTS_TEST_INTEGER_LESS(expected, actual);
        }

        {
            unsigned int const expected =   +101;
            unsigned int const actual   =   +100;

            XTESTS_TEST_INTEGER_LESS(expected, actual);
        }

        {
            long const expected =   -100;
            long const actual   =   -101;

            XTESTS_TEST_INTEGER_LESS(expected, actual);
        }

        {
            unsigned long const expected    =   +101;
            unsigned long const actual      =   +100;

            XTESTS_TEST_INTEGER_LESS(expected, actual);
        }

        {
            long long const expected    =   -100;
            long long const actual      =   -101;

            XTESTS_TEST_INTEGER_LESS(expected, actual);
        }

        {
            unsigned long long const expected   =   +101;
            unsigned long long const actual     =   +100;

            XTESTS_TEST_INTEGER_LESS(expected, actual);
        }

    }

    /* <= */
    {
        {
            short const expected    =   -100;
            short const actual      =   -101;

            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +100;

            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
        }

        {
            int const expected  =   -100;
            int const actual    =   -101;

            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
        }

        {
            unsigned int const expected =   +100;
            unsigned int const actual   =   +100;

            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
        }

        {
            long const expected =   -100;
            long const actual   =   -101;

            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
        }

        {
            unsigned long const expected    =   +100;
            unsigned long const actual      =   +100;

            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
        }

        {
            long long const expected    =   -100;
            long long const actual      =   -101;

            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +100;

            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
        }
    }

    /* > */
    {
        {
            short const expected    =   -101;
            short const actual      =   -100;

            XTESTS_TEST_INTEGER_GREATER(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +101;

            XTESTS_TEST_INTEGER_GREATER(expected, actual);
        }

        {
            int const expected  =   -101;
            int const actual    =   -100;

            XTESTS_TEST_INTEGER_GREATER(expected, actual);
        }

        {
            unsigned int const expected =   +100;
            unsigned int const actual   =   +101;

            XTESTS_TEST_INTEGER_GREATER(expected, actual);
        }

        {
            long const expected =   -101;
            long const actual   =   -100;

            XTESTS_TEST_INTEGER_GREATER(expected, actual);
        }

        {
            unsigned long const expected    =   +100;
            unsigned long const actual      =   +101;

            XTESTS_TEST_INTEGER_GREATER(expected, actual);
        }

        {
            long long const expected    =   -101;
            long long const actual      =   -100;

            XTESTS_TEST_INTEGER_GREATER(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +101;

            XTESTS_TEST_INTEGER_GREATER(expected, actual);
        }
    }

    /* >= */
    {
        {
            short const expected    =   -101;
            short const actual      =   -100;

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
        }

        {
            unsigned short const expected   =   +100;
            unsigned short const actual     =   +101;

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
        }

        {
            int const expected  =   -101;
            int const actual    =   -100;

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
        }

        {
            unsigned int const expected =   +100;
            unsigned int const actual   =   +101;

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
        }

        {
            long const expected =   -101;
            long const actual   =   -100;

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
        }

        {
            unsigned long const expected    =   +100;
            unsigned long const actual      =   +101;

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
        }

        {
            long long const expected    =   -101;
            long long const actual      =   -100;

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
        }

        {
            unsigned long long const expected   =   +100;
            unsigned long long const actual     =   +101;

            XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
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

        XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual);
    }

    /* < (int) */
    {
        int const expected  =   123;
        int const actual    =   123;

        XTESTS_TEST_INTEGER_LESS(expected, actual);
    }

    /* <= (unsigned int) */
    {
        unsigned short const expected   =   123;
        unsigned short const actual     =   124;

        XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual);
    }

    /* > (long) */
    {
        long const expected =   124;
        long const actual   =   123;

        XTESTS_TEST_INTEGER_GREATER(expected, actual);
    }

    /* > (unsigned long) */
    {
        unsigned long const expected    =   124;
        unsigned long const actual      =   123;

        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
    }

    /* > (long long) */
    {
        long long const expected    =   LLONG_MAX;
        long long const actual      =   LLONG_MIN;

        XTESTS_TEST_INTEGER_GREATER(expected, actual);
    }

    /* >= (unsigned long long) */
    {
        unsigned long long const expected   =   ULLONG_MAX;
        unsigned long long const actual     =   0;

        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual);
    }
}

/* ///////////////////////////// end of file //////////////////////////// */

