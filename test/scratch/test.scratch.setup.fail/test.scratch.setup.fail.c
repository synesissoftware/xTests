/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.setup.fail.c
 *
 * Purpose: Illustrates failure of setup function.
 *
 * Created: 31st January 2010
 * Updated: 28th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

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

static void test_never_visited(void);

static int setup(void*);
static int teardown(void*);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER_WITH_SETUP_FNS("test.scratch.setup.fail", verbosity, setup, teardown, NULL))
    {
        XTESTS_RUN_CASE(test_never_visited);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function definitions
 */

static int setup(void* param)
{
    STLSOFT_SUPPRESS_UNUSED(param);

    return 1;
}

static int teardown(void* param)
{
    STLSOFT_SUPPRESS_UNUSED(param);

    return 0;
}

static void test_never_visited(void)
{
    XTESTS_TEST_FAIL("should not get here");
}


/* ///////////////////////////// end of file //////////////////////////// */

