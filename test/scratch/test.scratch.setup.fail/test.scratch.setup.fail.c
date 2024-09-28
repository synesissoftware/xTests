/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.setup.fail.c
 *
 * Purpose: Illustrates failure of setup function.
 *
 * Created: 31st January 2010
 * Updated: 5th May 2024
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

static void test_1(void);

static int setup(void*);
static int teardown(void*);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER_WITH_SETUP_FNS("test.scratch.setup.fail", verbosity, setup, teardown, NULL))
    {
        XTESTS_RUN_CASE(test_1);

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

static void test_1(void)
{
    XTESTS_TEST_FAIL("should not get here");
}


/* ///////////////////////////// end of file //////////////////////////// */

