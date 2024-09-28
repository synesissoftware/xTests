/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example.c.factorial/example.c.factorial.c
 *
 * Purpose: Example of use of separate test-case function(s) and in-runner
 *          test case(s).
 *
 * Created: 7th December 2023
 * Updated: 28th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */

/** \file example.c.factorial.c
 */


#include <xtests/xtests.h>

#include <stdio.h>
#include <assert.h>

#include <xtests/internal/checked_main.h>


/* /////////////////////////////////////////////////////////////////////////
 * function(s) to tests
 */

/* a somewhat-flaky factorial function */
int factorial(int v)
{
    assert(v >= 0);

    switch (v)
    {
        case 0:
        case 1:
            return 1;
        default:
            return v * factorial(v - 1);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * test casse functions
 */

void test_factorial_edge_cases(void)
{
    XTESTS_TEST_INTEGER_EQUAL(1, factorial(0));
    XTESTS_TEST_INTEGER_EQUAL(1, factorial(1));
}


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("example.factorial.factorial", verbosity))
    {
        /* runs test case "test_factorial_edge_cases" */
        XTESTS_RUN_CASE_WITH_DESC(test_factorial_edge_cases, "checking edge cases");

        /* runs test case "test-case-range" */
        if (XTESTS_CASE_BEGIN("test-case-range", "checking wider range of input numbers"))
        {
            XTESTS_TEST_INTEGER_EQUAL(2, factorial(2));
            XTESTS_TEST_INTEGER_EQUAL(6, factorial(3));
            /* . . . */
            XTESTS_TEST_INTEGER_EQUAL(479001600, factorial(12));

            XTESTS_CASE_END("test-case-1");
        }


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ///////////////////////////// end of file //////////////////////////// */

