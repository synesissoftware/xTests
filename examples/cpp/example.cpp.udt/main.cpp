/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example.cpp.udt/main.cpp
 *
 * Purpose: Example use of unit-testing of a user-defined type.
 *
 * Created: 10th January 2025
 * Updated: 23rd April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */

/** \file example.cpp.udt.cpp
 */


/* /////////////////////////////////////////////////////////////////////////
 * checks
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <xtests/terse-api.h>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/util/temp_file.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void TEST_PriceQuantity_1();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

namespace {

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace {

    using stlsoft::ss_int64_t;

    struct PriceQuantity
    {
        ss_int64_t  p;
        ss_int64_t  q;
    };

    inline
    bool
    operator ==(
        PriceQuantity const&    lhs
    ,   PriceQuantity const&    rhs
    ) STLSOFT_NOEXCEPT
    {
        return lhs.p == rhs.p && lhs.q == rhs.q;
    }

    inline
    bool
    operator !=(
        PriceQuantity const&    lhs
    ,   PriceQuantity const&    rhs
    ) STLSOFT_NOEXCEPT
    {
        return !operator ==(lhs, rhs);
    }
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("example.cpp.udt", verbosity))
    {
        XTESTS_RUN_CASE(TEST_PriceQuantity_1);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

static void TEST_PriceQuantity_1()
{
    PriceQuantity pq1 = { 1000, 10 };
    PriceQuantity pq2 = { 1001, 11 };

    TEST_NOT_EQUAL(pq1, pq2);
    TEST_EQUAL(pq1, pq1);

    TEST_NOT_EQUAL(pq1, pq1);
    TEST_EQUAL(pq1, pq2);
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

