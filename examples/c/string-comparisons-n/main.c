/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/string-comparisons-n/main.c
 *
 * Purpose: Example of length-limited multibyte string comparison macros
 *          (`TEST_MS_EQ_N` / `TEST_MS_NE_N`): exact length when `n` is
 *          non-negative, and maximum length when `n` is negative; also
 *          illustrates comparison of non-NUL-terminated buffers.
 *
 * Created: 11th October 2026
 * Updated: 16th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/terse-api.h>

/* Standard C Header Files */
#include <stddef.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_exact_length(void);
static void test_maximum_length(void);
static void test_non_nul_terminated_buffers(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("example.c.string-comparisons-n", verbosity))
    {
        XTESTS_RUN_CASE_WITH_DESC(
            test_exact_length
        ,   "n > 0 requires both sides to supply at least n characters"
        );
        XTESTS_RUN_CASE_WITH_DESC(
            test_maximum_length
        ,   "n < 0 compares at most |n| characters (limit form)"
        );
        XTESTS_RUN_CASE_WITH_DESC(
            test_non_nul_terminated_buffers
        ,   "fixed-size buffers without a trailing NUL, with |n| = extent"
        );

        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_exact_length(void)
{
    /* Positive n is an exact length: the first n characters must match,
     * and both strings must be at least n characters long.
     */
    char const* short_prefix    =   "abc";
    char const* longer          =   "abcdef";
    char const* longer_mismatch =   "abcXYZ";

    TEST_MS_EQ_N(short_prefix, longer, 3);
    TEST_MS_NE_N(short_prefix, longer, 4);

    TEST_MS_EQ_N(longer, longer_mismatch, 3);
    TEST_MS_NE_N(longer, longer_mismatch, 4);
}

static void test_maximum_length(void)
{
    /* Negative n is a maximum (limit): comparison length is min(|n|,
     * length of expected). Prefix agreement within that limit succeeds
     * even when the full strings differ.
     */
    char const* short_prefix    =   "abc";
    char const* longer          =   "abcdef";
    char const* longer_mismatch =   "abcXYZ";

    TEST_MS_EQ_N(short_prefix, longer, -4);
    TEST_MS_EQ_N(short_prefix, longer, -8);

    TEST_MS_EQ_N(longer, longer_mismatch, -3);
    TEST_MS_NE_N(longer, longer_mismatch, -4);
}

static void test_non_nul_terminated_buffers(void)
{
    /* When the buffers have no trailing NUL, pass |n| equal to the
     * readable extent so length discovery does not walk past the array.
     */
    char        expected[]  =   { 'y', 'e', 'a', 'r' };
    char        actual_eq[] =   { 'y', 'e', 'a', 'r' };
    char        actual_ne[] =   { 'y', 'e', 'a', 'X' };
    ptrdiff_t   n_exact     =   4;
    ptrdiff_t   n_limit     =   -4;

    TEST_MS_EQ_N(expected, actual_eq, n_exact);
    TEST_MS_EQ_N(expected, actual_eq, n_limit);
    TEST_MS_NE_N(expected, actual_ne, n_exact);
    TEST_MS_NE_N(expected, actual_ne, n_limit);
}


/* ///////////////////////////// end of file //////////////////////////// */
