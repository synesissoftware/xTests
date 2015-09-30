/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/c/example.c.runner/example.c.runner.c
 *
 * Purpose:     Implementation file for the example.c.runner project.
 *
 * Created:     20th February 2008
 * Updated:     20th February 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("example.c.runner", verbosity))
    {
        /* test case 1 */
        if(XTESTS_CASE_BEGIN("test-case-1", "checking sizes of different integer types"))
        {
            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(sizeof(char), sizeof(short));
            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(sizeof(short), sizeof(int));
            XTESTS_TEST_INTEGER_LESS_OR_EQUAL(sizeof(int), sizeof(long));

            XTESTS_CASE_END("test-case-1");
        }

        /* test case 2 */
        if(XTESTS_CASE_BEGIN("test-case-2", "checking equality of sizes of signed and unsigned integer types"))
        {
            XTESTS_TEST_INTEGER_EQUAL_EXACT(sizeof(signed char), sizeof(unsigned char));
            XTESTS_TEST_INTEGER_EQUAL_EXACT(sizeof(signed short), sizeof(unsigned short));
            XTESTS_TEST_INTEGER_EQUAL_EXACT(sizeof(signed int), sizeof(unsigned int));
            XTESTS_TEST_INTEGER_EQUAL_EXACT(sizeof(signed long), sizeof(unsigned long));

            XTESTS_CASE_END("test-case-2");
        }

        /* test case 3 */
        if(XTESTS_CASE_BEGIN("test-case-3", "tests that always pass"))
        {
            XTESTS_TEST_PASSED();

            XTESTS_CASE_END("test-case-3");
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* //////////////////////////// end of file ///////////////////////////// */
