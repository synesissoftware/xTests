/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.custom_integral_types/entry.cpp
 *
 * Purpose: Illustrates facility for comparing custom integral types.
 *
 * Created: 23rd November 2024
 * Updated: 23rd November 2024
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

/* Standard C++ Header Files */

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.hpp>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

static void test_int_wrapper();
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

struct int_wrapper
{
    int value;
};

namespace stlsoft {

    template<>
    struct integral_traits<int_wrapper>
    {
        static
        int
        get_underlying_value(
            int_wrapper const& iw
        )
        {
            return iw.value;
        }
    };

} /* namespace stlsoft */


int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSE_HELP(argc, argv);
    XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.scratch.custom_integral_types", verbosity))
    {
        XTESTS_RUN_CASE(test_int_wrapper);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * function implementations
 */

namespace {

static void test_int_wrapper()
{
    {
        int_wrapper lhs { 0 };
        int_wrapper rhs { 0 };

        XTESTS_TEST_INTEGER_EQUAL(lhs, rhs);
    }

    {
        int_wrapper lhs { 0 };
        int_wrapper rhs { 1 };

        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(lhs, rhs);
    }

}
} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

