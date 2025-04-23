/* /////////////////////////////////////////////////////////////////////////
 * File:    test.test.unit.string_comparisons/entry.cpp
 *
 * Purpose: Conmponent-tests for `xtests::cpp::util::temp_file`.
 *
 * Created: 21st October 2024
 * Updated: 23rd April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


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

/* STLSoft header files */
#include <stlsoft/util/string/snprintf.h>

/* Standard C++ header files */
#include <string>

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

    static void TEST_MS_COMPARE_TO_N();
    static void TEST_MS_COMPARE_TO_N_WITH_std_string();
    static void TEST_WS_COMPARE_TO_N();
    static void TEST_WS_COMPARE_TO_N_WITH_std_wstring();

    static void test_Pantheios_broken_example();
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
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N);
        XTESTS_RUN_CASE(TEST_MS_COMPARE_TO_N_WITH_std_string);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N);
        XTESTS_RUN_CASE(TEST_WS_COMPARE_TO_N_WITH_std_wstring);

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

static void TEST_MS_COMPARE_TO_N()
{
    char    s1[]    =   "abc";
    char    s2[]    =   "abcdef";
    char    s3[]    =   "AbCdEf";

    {
        TEST_MS_EQ_N(s1, s2, 0);
        TEST_MS_EQ_N_APPROX(s1, s2, 0);
        TEST_MS_EQ_N(s1, s3, 0);
        TEST_MS_EQ_N_APPROX(s1, s3, 0);
        TEST_MS_EQ_N(s2, s3, 0);
        TEST_MS_EQ_N_APPROX(s2, s3, 0);
    }

    {
        TEST_MS_EQ_N(s1, s2, 2);
        TEST_MS_EQ_N_APPROX(s1, s2, 2);
        TEST_MS_NE_N(s1, s3, 2);
        TEST_MS_EQ_N_APPROX(s1, s3, 2);
        TEST_MS_NE_N(s2, s3, 2);
        TEST_MS_EQ_N_APPROX(s2, s3, 2);
    }

    {
        TEST_MS_EQ_N(s1, s2, -2);
        TEST_MS_EQ_N_APPROX(s1, s2, -2);
        TEST_MS_NE_N(s1, s3, -2);
        TEST_MS_EQ_N_APPROX(s1, s3, -2);
        TEST_MS_NE_N(s2, s3, -2);
        TEST_MS_EQ_N_APPROX(s2, s3, -2);
    }

    {
        TEST_MS_EQ_N(s1, s2, 3);
        TEST_MS_EQ_N_APPROX(s1, s2, 3);
        TEST_MS_NE_N(s1, s3, 3);
        TEST_MS_EQ_N_APPROX(s1, s3, 3);
        TEST_MS_NE_N(s2, s3, 3);
        TEST_MS_EQ_N_APPROX(s2, s3, 3);
    }

    {
        TEST_MS_EQ_N(s1, s2, -3);
        TEST_MS_EQ_N_APPROX(s1, s2, -3);
        TEST_MS_NE_N(s1, s3, -3);
        TEST_MS_EQ_N_APPROX(s1, s3, -3);
        TEST_MS_NE_N(s2, s3, -3);
        TEST_MS_EQ_N_APPROX(s2, s3, -3);
    }

    {
        TEST_MS_NE_N(s1, s2, 4);
        TEST_MS_NE_N_APPROX(s1, s2, 4);
        TEST_MS_NE_N(s1, s3, 4);
        TEST_MS_NE_N_APPROX(s1, s3, 4);
        TEST_MS_NE_N(s2, s3, 4);
        TEST_MS_EQ_N_APPROX(s2, s3, 4);
    }

    {
        TEST_MS_EQ_N(s1, s2, -4);
        TEST_MS_EQ_N_APPROX(s1, s2, -4);
        TEST_MS_NE_N(s1, s3, -4);
        TEST_MS_EQ_N_APPROX(s1, s3, -4);
        TEST_MS_NE_N(s2, s3, -4);
        TEST_MS_EQ_N_APPROX(s2, s3, -4);
    }
}

static void TEST_MS_COMPARE_TO_N_WITH_std_string()
{
    std::string const   s1("abc");
    std::string const   s2("abcdef");
    std::string const   s3("AbCdEf");

    {
        TEST_MS_EQ_N(s1, s2, 0);
        TEST_MS_EQ_N_APPROX(s1, s2, 0);
        TEST_MS_EQ_N(s1, s3, 0);
        TEST_MS_EQ_N_APPROX(s1, s3, 0);
        TEST_MS_EQ_N(s2, s3, 0);
        TEST_MS_EQ_N_APPROX(s2, s3, 0);
    }

    {
        TEST_MS_EQ_N(s1, s2, 2);
        TEST_MS_EQ_N_APPROX(s1, s2, 2);
        TEST_MS_NE_N(s1, s3, 2);
        TEST_MS_EQ_N_APPROX(s1, s3, 2);
        TEST_MS_NE_N(s2, s3, 2);
        TEST_MS_EQ_N_APPROX(s2, s3, 2);
    }

    {
        TEST_MS_EQ_N(s1, s2, -2);
        TEST_MS_EQ_N_APPROX(s1, s2, -2);
        TEST_MS_NE_N(s1, s3, -2);
        TEST_MS_EQ_N_APPROX(s1, s3, -2);
        TEST_MS_NE_N(s2, s3, -2);
        TEST_MS_EQ_N_APPROX(s2, s3, -2);
    }

    {
        TEST_MS_EQ_N(s1, s2, s1.size());
        TEST_MS_EQ_N_APPROX(s1, s2, s1.size());
        TEST_MS_NE_N(s1, s3, 3);
        TEST_MS_EQ_N_APPROX(s1, s3, 3);
        TEST_MS_NE_N(s2, s3, 3);
        TEST_MS_EQ_N_APPROX(s2, s3, 3);
    }

    {
        TEST_MS_EQ_N(s1, s2, -long(s1.size()));
        TEST_MS_EQ_N_APPROX(s1, s2, -long(s1.size()));
        TEST_MS_NE_N(s1, s3, -3);
        TEST_MS_EQ_N_APPROX(s1, s3, -3);
        TEST_MS_NE_N(s2, s3, -3);
        TEST_MS_EQ_N_APPROX(s2, s3, -3);
    }

    {
        TEST_MS_NE_N(s1, s2, 4);
        TEST_MS_NE_N_APPROX(s1, s2, 4);
        TEST_MS_NE_N(s1, s3, 4);
        TEST_MS_NE_N_APPROX(s1, s3, 4);
        TEST_MS_NE_N(s2, s3, 4);
        TEST_MS_EQ_N_APPROX(s2, s3, 4);
    }

    {
        TEST_MS_EQ_N(s1, s2, -4);
        TEST_MS_EQ_N_APPROX(s1, s2, -4);
        TEST_MS_NE_N(s1, s3, -4);
        TEST_MS_EQ_N_APPROX(s1, s3, -4);
        TEST_MS_NE_N(s2, s3, -4);
        TEST_MS_EQ_N_APPROX(s2, s3, -4);
    }
}

static void TEST_WS_COMPARE_TO_N()
{
    wchar_t s1[]    =   L"abc";
    wchar_t s2[]    =   L"abcdef";
    wchar_t s3[]    =   L"AbCdEf";

    {
        TEST_WS_EQ_N(s1, s2, 0);
        TEST_WS_EQ_N_APPROX(s1, s2, 0);
        TEST_WS_EQ_N(s1, s3, 0);
        TEST_WS_EQ_N_APPROX(s1, s3, 0);
        TEST_WS_EQ_N(s2, s3, 0);
        TEST_WS_EQ_N_APPROX(s2, s3, 0);
    }

    {
        TEST_WS_EQ_N(s1, s2, 2);
        TEST_WS_EQ_N_APPROX(s1, s2, 2);
        TEST_WS_NE_N(s1, s3, 2);
        TEST_WS_EQ_N_APPROX(s1, s3, 2);
        TEST_WS_NE_N(s2, s3, 2);
        TEST_WS_EQ_N_APPROX(s2, s3, 2);
    }

    {
        TEST_WS_EQ_N(s1, s2, -2);
        TEST_WS_EQ_N_APPROX(s1, s2, -2);
        TEST_WS_NE_N(s1, s3, -2);
        TEST_WS_EQ_N_APPROX(s1, s3, -2);
        TEST_WS_NE_N(s2, s3, -2);
        TEST_WS_EQ_N_APPROX(s2, s3, -2);
    }

    {
        TEST_WS_EQ_N(s1, s2, 3);
        TEST_WS_EQ_N_APPROX(s1, s2, 3);
        TEST_WS_NE_N(s1, s3, 3);
        TEST_WS_EQ_N_APPROX(s1, s3, 3);
        TEST_WS_NE_N(s2, s3, 3);
        TEST_WS_EQ_N_APPROX(s2, s3, 3);
    }

    {
        TEST_WS_EQ_N(s1, s2, -3);
        TEST_WS_EQ_N_APPROX(s1, s2, -3);
        TEST_WS_NE_N(s1, s3, -3);
        TEST_WS_EQ_N_APPROX(s1, s3, -3);
        TEST_WS_NE_N(s2, s3, -3);
        TEST_WS_EQ_N_APPROX(s2, s3, -3);
    }

    {
        TEST_WS_NE_N(s1, s2, 4);
        TEST_WS_NE_N_APPROX(s1, s2, 4);
        TEST_WS_NE_N(s1, s3, 4);
        TEST_WS_NE_N_APPROX(s1, s3, 4);
        TEST_WS_NE_N(s2, s3, 4);
        TEST_WS_EQ_N_APPROX(s2, s3, 4);
    }

    {
        TEST_WS_EQ_N(s1, s2, -4);
        TEST_WS_EQ_N_APPROX(s1, s2, -4);
        TEST_WS_NE_N(s1, s3, -4);
        TEST_WS_EQ_N_APPROX(s1, s3, -4);
        TEST_WS_NE_N(s2, s3, -4);
        TEST_WS_EQ_N_APPROX(s2, s3, -4);
    }
}

static void TEST_WS_COMPARE_TO_N_WITH_std_wstring()
{
    std::wstring const  s1(L"abc");
    std::wstring const  s2(L"abcdef");
    std::wstring const  s3(L"AbCdEf");

    {
        TEST_WS_EQ_N(s1, s2, 0);
        TEST_WS_EQ_N_APPROX(s1, s2, 0);
        TEST_WS_EQ_N(s1, s3, 0);
        TEST_WS_EQ_N_APPROX(s1, s3, 0);
        TEST_WS_EQ_N(s2, s3, 0);
        TEST_WS_EQ_N_APPROX(s2, s3, 0);
    }

    {
        TEST_WS_EQ_N(s1, s2, 2);
        TEST_WS_EQ_N_APPROX(s1, s2, 2);
        TEST_WS_NE_N(s1, s3, 2);
        TEST_WS_EQ_N_APPROX(s1, s3, 2);
        TEST_WS_NE_N(s2, s3, 2);
        TEST_WS_EQ_N_APPROX(s2, s3, 2);
    }

    {
        TEST_WS_EQ_N(s1, s2, -2);
        TEST_WS_EQ_N_APPROX(s1, s2, -2);
        TEST_WS_NE_N(s1, s3, -2);
        TEST_WS_EQ_N_APPROX(s1, s3, -2);
        TEST_WS_NE_N(s2, s3, -2);
        TEST_WS_EQ_N_APPROX(s2, s3, -2);
    }

    {
        TEST_WS_EQ_N(s1, s2, s1.size());
        TEST_WS_EQ_N_APPROX(s1, s2, s1.size());
        TEST_WS_NE_N(s1, s3, 3);
        TEST_WS_EQ_N_APPROX(s1, s3, 3);
        TEST_WS_NE_N(s2, s3, 3);
        TEST_WS_EQ_N_APPROX(s2, s3, 3);
    }

    {
        TEST_WS_EQ_N(s1, s2, -3);
        TEST_WS_EQ_N_APPROX(s1, s2, -3);
        TEST_WS_NE_N(s1, s3, -3);
        TEST_WS_EQ_N_APPROX(s1, s3, -3);
        TEST_WS_NE_N(s2, s3, -3);
        TEST_WS_EQ_N_APPROX(s2, s3, -3);
    }

    {
        TEST_WS_NE_N(s1, s2, 4);
        TEST_WS_NE_N_APPROX(s1, s2, 4);
        TEST_WS_NE_N(s1, s3, 4);
        TEST_WS_NE_N_APPROX(s1, s3, 4);
        TEST_WS_NE_N(s2, s3, 4);
        TEST_WS_EQ_N_APPROX(s2, s3, 4);
    }

    {
        TEST_WS_EQ_N(s1, s2, -4);
        TEST_WS_EQ_N_APPROX(s1, s2, -4);
        TEST_WS_NE_N(s1, s3, -4);
        TEST_WS_EQ_N_APPROX(s1, s3, -4);
        TEST_WS_NE_N(s2, s3, -4);
        TEST_WS_EQ_N_APPROX(s2, s3, -4);
    }
}

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

       TEST_MS_EQ_N("0000", sz, 4);
   }

   {
       char  sz[4];

       for (unsigned year = 1; year != 1000; ++year)
       {
           s::pantheios_util_formatYearToString4(year, &sz);

           char expected[5];

           snprintf(expected, STLSOFT_NUM_ELEMENTS(expected), ("%04d"), year);

           TEST_MS_EQ_N(expected, sz, 4);
       }
   }
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

