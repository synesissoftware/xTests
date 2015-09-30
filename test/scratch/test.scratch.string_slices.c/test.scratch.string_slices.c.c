/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.string_slices.c.c
 *
 * Purpose:     Implementation file for the test.scratch.string_slices.c project.
 *
 * Created:     16th February 2013
 * Updated:     16th February 2013
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2013, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void test_1_2();
static void test_1_3();
static void test_2_1();
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

    if(XTESTS_START_RUNNER("test.scratch.string_slices.c.runner-1", verbosity))
    {
        /* test 0.0 */
        if(XTESTS_CASE_BEGIN("test-0", "always passes"))
        {
            XTESTS_TEST_PASSED();

            XTESTS_CASE_END("test-0");
        }

        /* test 1.0 */
        if(XTESTS_CASE_BEGIN("test-1", "checking integer values"))
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

    if(XTESTS_START_RUNNER("test.scratch.string_slices.c.runner-2", verbosity))
    {
        /* test 2.1 */
        XTESTS_RUN_CASE(test_2_1);

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

    if(XTESTS_START_RUNNER("test.scratch.string_slices.c.runner-3", verbosity))
    {
        /* test 3.1 */
        XTESTS_RUN_CASE(test_3_1);


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    if(XTESTS_START_RUNNER("test.scratch.string_slices.c.runner-4", verbosity))
    {
        /* test 4.1 */
        XTESTS_RUN_CASE(test_4_1);

        /* test 4.2 */
        XTESTS_RUN_CASE(test_4_2);


        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    if(XTESTS_START_RUNNER("test.scratch.string_slices.c.runner-5", verbosity))
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
}

static void test_1_3()
{
}

static void test_2_1()
{
    /* test that a slice differs from a c-style string */

    struct slice_t
    {
        size_t      len;
        char const* ptr;

    } slice = { 3, "abcdef" };


    XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abcdef", slice);
}

static void test_2_2()
{
}

static void test_2_3()
{
}

static void test_2_4()
{
}

static void test_2_5()
{
}

static void test_2_6()
{
}

static void test_2_7()
{
}

static void test_2_8()
{
}

static void test_3_1()
{
}

static void test_4_1()
{
}

static void test_4_2()
{
}

static void test_5_1()
{
}

static void test_5_2()
{
}

static void test_5_3()
{
}

/* ///////////////////////////// end of file //////////////////////////// */
