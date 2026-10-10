/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.string_slices.c/entry.c
 *
 * Purpose: Unit-tests for multibyte and wide string slice comparison
 *          macros (`TEST_*_STRING_SLICE_EQUAL` /
 *          `TEST_*_STRING_SLICE_NOT_EQUAL`).
 *
 * Created: 16th February 2013
 * Updated: 11th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/terse-api.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>

#include <xtests/internal/checked_main.h>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_mb_against_empty_string(void);
static void test_mb_against_short_string(void);
static void test_mb_not_equal(void);
static void test_ws_against_empty_string(void);
static void test_ws_against_short_string(void);
static void test_ws_not_equal(void);


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
        XTESTS_RUN_CASE(test_mb_against_empty_string);
        XTESTS_RUN_CASE(test_mb_against_short_string);
        XTESTS_RUN_CASE(test_mb_not_equal);
        XTESTS_RUN_CASE(test_ws_against_empty_string);
        XTESTS_RUN_CASE(test_ws_against_short_string);
        XTESTS_RUN_CASE(test_ws_not_equal);

        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_mb_against_empty_string(void)
{
    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 0, ss_nullptr_k };

        TEST_MULTIBYTE_STRING_SLICE_EQUAL("", slice);
    }

    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 0, "" };

        TEST_MULTIBYTE_STRING_SLICE_EQUAL("", slice);
    }

    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 0, "abcdef" };

        TEST_MULTIBYTE_STRING_SLICE_EQUAL("", slice);
    }
}

static void test_mb_against_short_string(void)
{
    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 1, "abcdef" };

        TEST_MULTIBYTE_STRING_SLICE_EQUAL("a", slice);
    }

    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 3, "abcdef" };

        TEST_MULTIBYTE_STRING_SLICE_EQUAL("abc", slice);
    }

    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 6, "abcdef" };

        TEST_MULTIBYTE_STRING_SLICE_EQUAL("abcdef", slice);
    }
}

static void test_mb_not_equal(void)
{
    /* Length mismatch. */
    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 3, "abcdef" };

        TEST_MULTIBYTE_STRING_SLICE_NOT_EQUAL("ab", slice);
        TEST_MULTIBYTE_STRING_SLICE_NOT_EQUAL("abcd", slice);
    }

    /* Same length, different contents. */
    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 3, "abcdef" };

        TEST_MULTIBYTE_STRING_SLICE_NOT_EQUAL("abX", slice);
    }

    /* Empty slice is not equal to a non-empty expected string. */
    {
        struct slice_t
        {
            size_t      len;
            char const* ptr;

        } slice = { 0, ss_nullptr_k };

        TEST_MULTIBYTE_STRING_SLICE_NOT_EQUAL("a", slice);
    }
}

static void test_ws_against_empty_string(void)
{
    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 0, ss_nullptr_k };

        TEST_WIDE_STRING_SLICE_EQUAL(L"", slice);
    }

    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 0, L"" };

        TEST_WIDE_STRING_SLICE_EQUAL(L"", slice);
    }

    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 0, L"abcdef" };

        TEST_WIDE_STRING_SLICE_EQUAL(L"", slice);
    }
}

static void test_ws_against_short_string(void)
{
    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 1, L"abcdef" };

        TEST_WIDE_STRING_SLICE_EQUAL(L"a", slice);
    }

    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 3, L"abcdef" };

        TEST_WIDE_STRING_SLICE_EQUAL(L"abc", slice);
    }

    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 6, L"abcdef" };

        TEST_WIDE_STRING_SLICE_EQUAL(L"abcdef", slice);
    }
}

static void test_ws_not_equal(void)
{
    /* Length mismatch. */
    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 3, L"abcdef" };

        TEST_WIDE_STRING_SLICE_NOT_EQUAL(L"ab", slice);
        TEST_WIDE_STRING_SLICE_NOT_EQUAL(L"abcd", slice);
    }

    /* Same length, different contents. */
    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 3, L"abcdef" };

        TEST_WIDE_STRING_SLICE_NOT_EQUAL(L"abX", slice);
    }

    /* Empty slice is not equal to a non-empty expected string. */
    {
        struct slice_t
        {
            size_t          len;
            wchar_t const*  ptr;

        } slice = { 0, ss_nullptr_k };

        TEST_WIDE_STRING_SLICE_NOT_EQUAL(L"a", slice);
    }
}


/* ///////////////////////////// end of file //////////////////////////// */
