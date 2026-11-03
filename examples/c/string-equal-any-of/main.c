/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/string-equal-any-of/main.c
 *
 * Purpose: Example of multibyte string equal-any-of macros, where the
 *          actual value must equal one element of a set
 *          (`TEST_MS_EQ_ANY_OF`, `TEST_MS_EQ_ANY_OF2`,
 *          `TEST_MS_EQ_ANY_OF3`, and the `_APPROX` forms), including
 *          deliberate assertion failures.
 *
 * Created: 29th October 2026
 * Updated: 31st October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/terse-api.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stddef.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_fixed_arity(void);
static void test_set(void);
static void test_buffer_actual(void);
static void test_approx(void);
static void test_deliberate_failures(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER(__FILE__, verbosity))
    {
        XTESTS_RUN_CASE_WITH_DESC(
            test_fixed_arity
        ,   "two- and three-element expected lists, actual last"
        );
        XTESTS_RUN_CASE_WITH_DESC(
            test_set
        ,   "array of expected strings; each position may match"
        );
        XTESTS_RUN_CASE_WITH_DESC(
            test_buffer_actual
        ,   "the actual value may be a writable character buffer"
        );
        XTESTS_RUN_CASE_WITH_DESC(
            test_approx
        ,   "case-insensitive membership, as with TEST_MS_EQ_APPROX"
        );
        XTESTS_RUN_CASE_WITH_DESC(
            test_deliberate_failures
        ,   "deliberate failures: miss, empty set, and approx miss"
        );

        XTESTS_PRINT_RESULTS();
        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_fixed_arity(void)
{
    /* Expected strings come first; the value under test is last, as with
     * TEST_INT_EQ_ANY_OF2 / TEST_INT_EQ_ANY_OF3.
     */
    TEST_MS_EQ_ANY_OF2("red", "green", "red");
    TEST_MS_EQ_ANY_OF2("red", "green", "green");

    TEST_MS_EQ_ANY_OF3("red", "green", "blue", "red");
    TEST_MS_EQ_ANY_OF3("red", "green", "blue", "green");
    TEST_MS_EQ_ANY_OF3("red", "green", "blue", "blue");
}

static void test_set(void)
{
    char const* const colours[] = {
        "red",
        "green",
        "blue",
        "",
    };

    TEST_MS_EQ_ANY_OF(colours, STLSOFT_NUM_ELEMENTS(colours), "red");
    TEST_MS_EQ_ANY_OF(colours, STLSOFT_NUM_ELEMENTS(colours), "green");
    TEST_MS_EQ_ANY_OF(colours, STLSOFT_NUM_ELEMENTS(colours), "blue");
    TEST_MS_EQ_ANY_OF(colours, STLSOFT_NUM_ELEMENTS(colours), "");
}

static void test_buffer_actual(void)
{
    char const* const answers[] = {
        "yes",
        "no",
    };
    char        actual[]        =   "yes";

    TEST_MS_EQ_ANY_OF(answers, STLSOFT_NUM_ELEMENTS(answers), actual);
    TEST_MS_EQ_ANY_OF2("yes", "no", actual);
}

static void test_approx(void)
{
    /* Same membership as the exact macros, ignoring case, as with
     * TEST_MS_EQ_APPROX.
     */
    char const* const colours[] = {
        "red",
        "green",
        "blue",
    };

    TEST_MS_EQ_ANY_OF_APPROX(colours, STLSOFT_NUM_ELEMENTS(colours), "RED");
    TEST_MS_EQ_ANY_OF_APPROX(colours, STLSOFT_NUM_ELEMENTS(colours), "Green");
    TEST_MS_EQ_ANY_OF2_APPROX("red", "green", "GREEN");
    TEST_MS_EQ_ANY_OF3_APPROX("red", "green", "blue", "Blue");
}

static void test_deliberate_failures(void)
{
    /* These assertions fail on purpose, so a run shows a value outside the
     * expected list (joined as "red | green | blue"), an empty set, which
     * is reported as "(empty)", and a case-insensitive miss.
     */
    char const* const colours[] = {
        "red",
        "green",
        "blue",
    };
    char        actual[]        =   "maybe";

    TEST_MS_EQ_ANY_OF2("red", "green", "blue");
    TEST_MS_EQ_ANY_OF3("red", "green", "blue", "yellow");
    TEST_MS_EQ_ANY_OF(colours, STLSOFT_NUM_ELEMENTS(colours), "yellow");
    TEST_MS_EQ_ANY_OF2("yes", "no", actual);
    TEST_MS_EQ_ANY_OF(colours, 0, "red");

    TEST_MS_EQ_ANY_OF2_APPROX("red", "green", "blue");
    TEST_MS_EQ_ANY_OF_APPROX(colours, STLSOFT_NUM_ELEMENTS(colours), "yellow");
}

/* ///////////////////////////// end of file //////////////////////////// */


