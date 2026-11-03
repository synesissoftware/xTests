/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/string-comparisons-n/main.cpp
 *
 * Purpose: Example of length-limited wide and multibyte string comparison
 *          macros (`TEST_WS_EQ_N` / `TEST_MS_EQ_N`): exact length when `n`
 *          is non-negative, and maximum length when `n` is negative; also
 *          illustrates `std::wstring`, non-NUL-terminated buffers, and
 *          deliberate assertion failures.
 *
 * Created: 11th October 2026
 * Updated: 29th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/terse-api.h>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stddef.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void test_exact_length();
    static void test_maximum_length();
    static void test_with_std_wstring();
    static void test_non_nul_terminated_buffers();
    static void test_deliberate_failures();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("example.cpp.string-comparisons-n", verbosity))
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
            test_with_std_wstring
        ,   "C++ std::wstring works with the same _N macros"
        );
        XTESTS_RUN_CASE_WITH_DESC(
            test_non_nul_terminated_buffers
        ,   "fixed-size buffers without a trailing NUL, with |n| = extent"
        );
        XTESTS_RUN_CASE_WITH_DESC(
            test_deliberate_failures
        ,   "deliberate failures: exact-n mismatch, short side, limit form"
        );

        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

static void test_exact_length()
{
    /* Positive n is an exact length: the first n characters must match,
     * and both strings must be at least n characters long.
     */
    wchar_t const*  short_prefix    =   L"abc";
    wchar_t const*  longer          =   L"abcdef";
    wchar_t const*  longer_mismatch =   L"abcXYZ";

    TEST_WS_EQ_N(short_prefix, longer, 3);
    TEST_WS_NE_N(short_prefix, longer, 4);

    TEST_WS_EQ_N(longer, longer_mismatch, 3);
    TEST_WS_NE_N(longer, longer_mismatch, 4);

    TEST_MS_EQ_N("abc", "abcdef", 3);
    TEST_MS_NE_N("abc", "abcdef", 4);
}

static void test_maximum_length()
{
    /* Negative n is a maximum (limit): comparison length is min(|n|,
     * length of expected). Prefix agreement within that limit succeeds
     * even when the full strings differ.
     */
    wchar_t const*  short_prefix    =   L"abc";
    wchar_t const*  longer          =   L"abcdef";
    wchar_t const*  longer_mismatch =   L"abcXYZ";

    TEST_WS_EQ_N(short_prefix, longer, -4);
    TEST_WS_EQ_N(short_prefix, longer, -8);

    TEST_WS_EQ_N(longer, longer_mismatch, -3);
    TEST_WS_NE_N(longer, longer_mismatch, -4);

    TEST_MS_EQ_N("abc", "abcdef", -4);
    TEST_MS_EQ_N("abcdef", "abcXYZ", -3);
    TEST_MS_NE_N("abcdef", "abcXYZ", -4);
}

static void test_with_std_wstring()
{
    std::wstring const  short_prefix(L"abc");
    std::wstring const  longer(L"abcdef");
    std::wstring const  longer_mismatch(L"abcXYZ");

    TEST_WS_EQ_N(short_prefix, longer, 3);
    TEST_WS_NE_N(short_prefix, longer, 4);

    TEST_WS_EQ_N(short_prefix, longer, -4);
    TEST_WS_EQ_N(longer, longer_mismatch, -3);
    TEST_WS_NE_N(longer, longer_mismatch, -4);
}

static void test_non_nul_terminated_buffers()
{
    /* When the buffers have no trailing NUL, pass |n| equal to the
     * readable extent so length discovery does not walk past the array.
     */
    wchar_t     expected[]  =   { L'y', L'e', L'a', L'r' };
    wchar_t     actual_eq[] =   { L'y', L'e', L'a', L'r' };
    wchar_t     actual_ne[] =   { L'y', L'e', L'a', L'X' };
    ptrdiff_t   n_exact     =   4;
    ptrdiff_t   n_limit     =   -4;

    TEST_WS_EQ_N(expected, actual_eq, n_exact);
    TEST_WS_EQ_N(expected, actual_eq, n_limit);
    TEST_WS_NE_N(expected, actual_ne, n_exact);
    TEST_WS_NE_N(expected, actual_ne, n_limit);
}

static void test_deliberate_failures()
{
    /* These assertions fail on purpose, so a run shows the length-limited
     * report: content mismatch at exact n, a side shorter than n, a
     * negative-n prefix mismatch, and the same for multibyte and
     * `std::wstring`.
     */
    wchar_t const*  short_prefix    =   L"abc";
    wchar_t const*  longer          =   L"abcdef";
    wchar_t const*  longer_mismatch =   L"abcXYZ";

    TEST_WS_EQ_N(longer, longer_mismatch, 4);
    TEST_WS_EQ_N(short_prefix, longer, 4);
    TEST_WS_EQ_N(longer, longer_mismatch, -4);
    TEST_WS_NE_N(short_prefix, longer, 3);

    TEST_MS_EQ_N("abcdef", "abcXYZ", 4);
    TEST_MS_EQ_N("abc", "abcdef", 4);
    TEST_MS_EQ_N("abcdef", "abcXYZ", -4);

    std::wstring const  w_longer(L"abcdef");
    std::wstring const  w_mismatch(L"abcXYZ");

    TEST_WS_EQ_N(w_longer, w_mismatch, 4);
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */


