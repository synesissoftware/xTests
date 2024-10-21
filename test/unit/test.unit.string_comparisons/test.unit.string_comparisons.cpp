/* /////////////////////////////////////////////////////////////////////////
 * File:    test.test.unit.string_comparisons.cpp
 *
 * Purpose: Conmponent-tests for `xtests::cpp::util::temp_file`.
 *
 * Created: 21st October 2024
 * Updated: 21st October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */



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

/* STLSoft header files */
#include <stlsoft/util/string/snprintf.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////
 * final includes
 */

/* xTests header files */
#include <xtests/internal/checked_main.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_Pantheios_broken_example(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.test.unit.string_comparisons", verbosity))
    {
        XTESTS_RUN_CASE(test_Pantheios_broken_example);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void test_Pantheios_broken_example()
{
   struct s {
       static
       void
       pantheios_util_formatYearToString4(
           unsigned    year
       ,   char      (*ar)[4]
       ) noexcept
       {
           (*ar)[0]    =   '0' + ((year / 1000) % 10);
           (*ar)[1]    =   '0' + ((year /  100) % 10);
           (*ar)[2]    =   '0' + ((year /   10) % 10);
           (*ar)[3]    =   '0' + ((year /    1) % 10);
       }
   };

   {
       char  sz[4];

       s::pantheios_util_formatYearToString4(0, &sz);

       XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("0000", sz, 4);
   }

   {
       char  sz[4];

       for (unsigned year = 1; year != 1000; ++year)
       {
           s::pantheios_util_formatYearToString4(year, &sz);

           char expected[5];

           snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), ("%04d"), year);

           XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(expected, sz, 4);
       }
   }
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

