/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.shwild_patterns/entry.cpp
 *
 * Purpose: Unit-tests for shwild extensions.
 *
 * Created: 17th October 2024
 * Updated: 23rd April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * checks
 */

/* expects that CMake has defined XTESTS_HAS_SHWILD, and allowing for
 * manual/other compilation that must therefore have defined
 * XTESTS_USE_SHWILD
 */
#ifndef XTESTS_HAS_SHWILD
# ifndef XTESTS_USE_SHWILD
#  error XTESTS_HAS_SHWILD, which will be defined by CMake configuration, must be defined; otherwise, XTESTS_USE_SHWILD must be defined
# endif
#endif


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <xtests/xtests.h>

/* /////////////////////////////////////
 * general includes
 */

/* shwild header files */
#include <shwild/shwild.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_empty();
static void test_exact_matches();
static void test_wild1_1();
static void test_wild1_2();


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.shwild_patterns", verbosity))
    {
        XTESTS_RUN_CASE(test_empty);
        XTESTS_RUN_CASE(test_exact_matches);
        XTESTS_RUN_CASE(test_wild1_1);
        XTESTS_RUN_CASE(test_wild1_2);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_empty()
{
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("", "");

    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("", "a");
}

static void test_exact_matches()
{
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("1", "1");
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("abc", "abc");

    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("1", "2");
    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("2", "1");
}

static void test_wild1_1()
{
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("ab?", "ab_");
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("ab?", "ab-");
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("ab?", "aba");

    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("ab?", "Abc");
    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("ab?", "aBc");
}

static void test_wild1_2()
{
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("a?c", "a_c");
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("a?c", "a-c");
    XTESTS_TEST_MULTIBYTE_STRING_MATCHES("a?c", "abc");

    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("a?c", "Ac");
    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("a?c", "Abc");
    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("a?c", "abC");
    XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH("a?c", "abd");
}


/* ///////////////////////////// end of file //////////////////////////// */

