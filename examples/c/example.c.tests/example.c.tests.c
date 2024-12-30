/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example.c.tests/example.c.tests.c
 *
 * Purpose: Example of use of separate test-case functions.
 *
 * Created: 20th February 2008
 * Updated: 30th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */

/** \file example.c.tests.c
 */


/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

#include <xtests/internal/checked_main.h>


/* /////////////////////////////////////////////////////////////////////////
 * test function declarations
 */

static void test_relative_sizes(void);
static void test_signedness_integer_sizes(void);
static void test_always_pass(void);
static void test_integer_values(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("example.c.tests", verbosity))
    {
        XTESTS_RUN_CASE_WITH_DESC(test_relative_sizes, "checking sizes of different integer types");
        XTESTS_RUN_CASE_WITH_DESC(test_signedness_integer_sizes, "checking equality of sizes of signed and unsigned integer types");
        XTESTS_RUN_CASE_WITH_DESC(test_always_pass, "tests that always pass");
        XTESTS_RUN_CASE_WITH_DESC(test_integer_values, "evaluating relationships between numbers");

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_relative_sizes(void)
{
    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(sizeof(char), sizeof(short));
    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(sizeof(short), sizeof(int));
    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(sizeof(int), sizeof(long));
}

static void test_signedness_integer_sizes(void)
{
    XTESTS_TEST_INTEGER_EQUAL_EXACT(sizeof(signed char), sizeof(unsigned char));
    XTESTS_TEST_INTEGER_EQUAL_EXACT(sizeof(signed short), sizeof(unsigned short));
    XTESTS_TEST_INTEGER_EQUAL_EXACT(sizeof(signed int), sizeof(unsigned int));
    XTESTS_TEST_INTEGER_EQUAL_EXACT(sizeof(signed long), sizeof(unsigned long));
}

static void test_always_pass(void)
{
    XTESTS_TEST_PASSED();
}

static void test_integer_values(void)
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


/* ///////////////////////////// end of file //////////////////////////// */

