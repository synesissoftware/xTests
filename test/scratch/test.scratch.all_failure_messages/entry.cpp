/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.all_failure_messages/entry.cpp
 *
 * Purpose: Illustrates each failure message.
 *
 * Created: 1st December 2024
 * Updated: 7th December 2024
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

/* Standard C++ Header Files */
#include <limits>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.hpp>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP(argc, argv);
    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.scratch.all_failure_messages", verbosity))
    {
        if (XTESTS_CASE_BEGIN("boolean", "illustrating boolean failure messages"))
        {
            TEST_BOOLEAN_EQUAL(false, true);
            TEST_BOOLEAN_NOT_EQUAL(false, false);

            XTESTS_CASE_END("boolean");
        }

        if (XTESTS_CASE_BEGIN("double", "illustrating double failure messages"))
        {
            TEST_FLOATINGPOINT_EQUAL_APPROX(-1.0, -1.0001);
            TEST_FP_EQ(-1.0, -1.0001);
            TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(-1.0, -1.0000001);
            TEST_FP_NE(-1.0, -1.0000001);
            TEST_FP_GT(-1.0, -1.0);
            TEST_FP_LT(-1.0, -1.0);
            TEST_FP_GE(-1.0, -1.1);
            TEST_FP_LE(-1.1, -1.0);
            TEST_FLOATINGPOINT_EQUAL_EXACT(-1.0, -1.0001);
            TEST_FLOATINGPOINT_NOT_EQUAL_EXACT(-1.0, -1.0);

            XTESTS_CASE_END("double");
        }

        if (XTESTS_CASE_BEGIN("multibyte character", "illustrating multibyte character failure messages"))
        {
            TEST_CHAR_EQ('a', 'b');
            TEST_CHAR_NE('a', 'a');
            TEST_CHAR_GT('b', 'a');
            TEST_CHAR_LT('a', 'b');
            TEST_CHAR_GE('b', 'a');
            TEST_CHAR_LE('a', 'b');

            XTESTS_CASE_END("multibyte character");
        }

        if (XTESTS_CASE_BEGIN("wide character", "illustrating wide character failure messages"))
        {
            XTESTS_CASE_END("wide character");
        }

        if (XTESTS_CASE_BEGIN("multibyte string", "illustrating multibyte string failure messages"))
        {
            TEST_MS_EQ("abc", "abcd");
            TEST_MS_NE("abc", "abc");
            TEST_MULTIBYTE_STRING_EQUAL_APPROX("abc", "def");
            TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX("abc", "ABC");

            XTESTS_CASE_END("multibyte string");
        }

        if (XTESTS_CASE_BEGIN("wide string", "illustrating wide string failure messages"))
        {
            TEST_WS_EQ(L"abc", L"abcd");
            TEST_WS_NE(L"abc", L"abc");
            TEST_WIDE_STRING_EQUAL_APPROX(L"abc", L"def");
            TEST_WIDE_STRING_NOT_EQUAL_APPROX(L"abc", L"ABC");

            XTESTS_CASE_END("wide string");
        }

        if (XTESTS_CASE_BEGIN("opaque pointer", "illustrating opaque pointer failure messages"))
        {
            int const int1 = 0;
            int const int2 = 0;
            int const ints[3] = { 0, 0 };

            TEST_PTR_EQ(&int1, &int2);
            TEST_PTR_NE(&int1, &int1);
            TEST_PTR_GT(&int1, &int1);
            TEST_PTR_LT(&int1, &int1);
            TEST_PTR_GE(&ints[1], &ints[0]);
            TEST_PTR_LE(&ints[0], &ints[1]);

            XTESTS_CASE_END("opaque pointer");
        }

        if (XTESTS_CASE_BEGIN("signed long", "illustrating signed long failure messages"))
        {
            // sint8_t
            {
                TEST_INT_EQ(0, stlsoft::ss_sint8_t(1));
                TEST_INT_NE(0, stlsoft::ss_sint8_t(0));
                TEST_INT_LT(0, stlsoft::ss_sint8_t(0));
                TEST_INT_GT(0, stlsoft::ss_sint8_t(0));
                TEST_INT_LE(0, stlsoft::ss_sint8_t(1));
                TEST_INT_GE(1, stlsoft::ss_sint8_t(0));
            }

            // sint16_t
            {
                TEST_INT_EQ(0, stlsoft::ss_sint16_t(1));
                TEST_INT_NE(0, stlsoft::ss_sint16_t(0));
                TEST_INT_LT(0, stlsoft::ss_sint16_t(0));
                TEST_INT_GT(0, stlsoft::ss_sint16_t(0));
                TEST_INT_LE(0, stlsoft::ss_sint16_t(1));
                TEST_INT_GE(1, stlsoft::ss_sint16_t(0));
            }

            // sint32_t
            {
                TEST_INT_EQ(0, stlsoft::ss_sint32_t(1));
                TEST_INT_NE(0, stlsoft::ss_sint32_t(0));
                TEST_INT_LT(0, stlsoft::ss_sint32_t(0));
                TEST_INT_GT(0, stlsoft::ss_sint32_t(0));
                TEST_INT_LE(0, stlsoft::ss_sint32_t(1));
                TEST_INT_GE(1, stlsoft::ss_sint32_t(0));
            }

            XTESTS_CASE_END("signed long");
        }

        if (XTESTS_CASE_BEGIN("unsigned long", "illustrating unsigned long failure messages"))
        {
            // uint8_t
            {
                TEST_INT_EQ(0u, stlsoft::ss_uint8_t(1));
                TEST_INT_NE(0u, stlsoft::ss_uint8_t(0));
                TEST_INT_LT(0u, stlsoft::ss_uint8_t(0));
                TEST_INT_GT(0u, stlsoft::ss_uint8_t(0));
                TEST_INT_LE(0u, stlsoft::ss_uint8_t(1));
                TEST_INT_GE(1u, stlsoft::ss_uint8_t(0));
            }

            // uint16_t
            {
                TEST_INT_EQ(0u, stlsoft::ss_uint16_t(1));
                TEST_INT_NE(0u, stlsoft::ss_uint16_t(0));
                TEST_INT_LT(0u, stlsoft::ss_uint16_t(0));
                TEST_INT_GT(0u, stlsoft::ss_uint16_t(0));
                TEST_INT_LE(0u, stlsoft::ss_uint16_t(1));
                TEST_INT_GE(1u, stlsoft::ss_uint16_t(0));
            }

            // uint32_t
            {
                TEST_INT_EQ(0u, stlsoft::ss_uint32_t(1));
                TEST_INT_NE(0u, stlsoft::ss_uint32_t(0));
                TEST_INT_LT(0u, stlsoft::ss_uint32_t(0));
                TEST_INT_GT(0u, stlsoft::ss_uint32_t(0));
                TEST_INT_LE(0u, stlsoft::ss_uint32_t(1));
                TEST_INT_GE(1u, stlsoft::ss_uint32_t(0));
            }

            XTESTS_CASE_END("unsigned long");
        }

        if (XTESTS_CASE_BEGIN("sint64", "illustrating sint64 failure messages"))
        {
            // sint64_t
            {
                TEST_INT_EQ(0, stlsoft::ss_sint64_t(1));
                TEST_INT_NE(0, stlsoft::ss_sint64_t(0));
                TEST_INT_LT(0, stlsoft::ss_sint64_t(0));
                TEST_INT_GT(0, stlsoft::ss_sint64_t(0));
                TEST_INT_LE(0, stlsoft::ss_sint64_t(1));
                TEST_INT_GE(1, stlsoft::ss_sint64_t(0));

                TEST_INT_EQ(std::numeric_limits<stlsoft::ss_sint64_t>::min(), std::numeric_limits<stlsoft::ss_sint64_t>::max());
            }

            XTESTS_CASE_END("sint64");
        }

        if (XTESTS_CASE_BEGIN("uint64", "illustrating uint64 failure messages"))
        {
            // uint64_t
            {
                TEST_INT_EQ(0u, stlsoft::ss_uint64_t(1));
                TEST_INT_NE(0u, stlsoft::ss_uint64_t(0));
                TEST_INT_LT(0u, stlsoft::ss_uint64_t(0));
                TEST_INT_GT(0u, stlsoft::ss_uint64_t(0));
                TEST_INT_LE(0u, stlsoft::ss_uint64_t(1));
                TEST_INT_GE(1u, stlsoft::ss_uint64_t(0));

                TEST_INT_EQ(std::numeric_limits<stlsoft::ss_uint64_t>::min(), std::numeric_limits<stlsoft::ss_uint64_t>::max());
            }

            XTESTS_CASE_END("uint64");
        }

        if (XTESTS_CASE_BEGIN("test failed", "illustrating test failed failure messages"))
        {

            XTESTS_CASE_END("test failed");
        }

        if (XTESTS_CASE_BEGIN("write fail", "illustrating write fail failure messages"))
        {

            XTESTS_CASE_END("write fail");
        }

        if (XTESTS_CASE_BEGIN("case excepted", "illustrating case excepted failure messages"))
        {

            XTESTS_CASE_END("case excepted");
        }

        if (XTESTS_CASE_BEGIN("case exception excepted", "illustrating case exception excepted failure messages"))
        {

            XTESTS_CASE_END("case exception excepted");
        }

        if (XTESTS_CASE_BEGIN("multibyte string (N)", "illustrating multibyte string failure messages"))
        {
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("abc", "abdef", 3);
            XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N("abc", "abcd", 3);

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX("abc", "DEF", 2);
            XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX("abc", "ABCD", 3);

            XTESTS_CASE_END("multibyte string (N)");
        }

        if (XTESTS_CASE_BEGIN("multibyte string (contains)", "illustrating multibyte string failure messages"))
        {
            XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("abc", "def");
            XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN("abc", "abcd");

            XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX("abc", "DEF");
            XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX("abc", "ABCD");

            XTESTS_CASE_END("multibyte string (contains)");
        }

        if (XTESTS_CASE_BEGIN("miscellaneous", "illustrating failure messages"))
        {
            TEST_FAIL("the message");
            TEST_FAIL_WITH_QUALIFIER("the message", "the qualifier");

            XTESTS_CASE_END("miscellaneous");
        }

        {
            struct expected_exceptions_not_throw
            {
                static void fn() STLSOFT_NOEXCEPT
                {
                }
            };

            XTESTS_RUN_CASE_THAT_THROWS(&expected_exceptions_not_throw::fn, std::runtime_error);
        }

        {
            struct unexpected_exceptions_thrown
            {
                static void fn()
                {
                    throw std::runtime_error("unexpected");
                }
            };

            XTESTS_RUN_CASE(&unexpected_exceptions_thrown::fn);
        }

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */


/* ///////////////////////////// end of file //////////////////////////// */

