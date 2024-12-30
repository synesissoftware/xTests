/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.string_slices.c.c
 *
 * Purpose: Illustrates xTests string slice comparison macros (C code).
 *
 * Created: 16th February 2013
 * Updated: 30th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.h>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_against_empty_string(void);
// static void test_against_empty_slice(void);
static void test_against_short_string(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.string_slices.c", verbosity))
    {
        XTESTS_RUN_CASE(test_against_empty_string);
        XTESTS_RUN_CASE(test_against_short_string);

        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_against_empty_string(void)
{
    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 0, ss_nullptr_k };

        XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("", slice);
    }

    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 0, "" };

        XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("", slice);
    }

    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 0, "abcdef" };

        XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("", slice);
    }
}

static void test_against_short_string(void)
{
    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 1, "abcdef" };

        XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("a", slice);
    }

    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 3, "abcdef" };

        XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc", slice);
    }

    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 6, "abcdef" };

        XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL("abcdef", slice);
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

