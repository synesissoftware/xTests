/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.utility.cmdline/entry.cpp
 *
 * Purpose: Unit-tests for utility functions.
 *
 * Created: 30th December 2024
 * Updated: 30th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * checks
 */


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
#include <shwild/shwild.hpp>

/* xTests header files */
#include <xtests/util/temp_file.hpp>

/* STLSoft header files */
#include <platformstl/filesystem/FILE_stream.hpp>
#include <platformstl/filesystem/file_lines.hpp>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    static void TEST_parseHelp2_NO_ARGUMENTS();
    static void TEST_parseHelp2_WITH_help_FLAG();
    static void TEST_parseHelp2_WITH_help_FLAG_AFTER_DOUBLEDASH();

    static void TEST_parseVerbosity_NO_ARGUMENTS();
    static void TEST_parseVerbosity_WITH_SINGLE_verbosity_OPTION();
    static void TEST_parseVerbosity_WITH_verbosity_OPTION_FOLLOWED_BY_SECOND_verbosity_OPTION();
    static void TEST_parseVerbosity_WITH_SINGLE_verbosity_OPTION_AFTER_DOUBLEDASH();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

namespace {

    const int ASSUMED_DEFAULT_VERBOSITY = 3;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.utility.cmdline", verbosity))
    {
        XTESTS_RUN_CASE(TEST_parseHelp2_NO_ARGUMENTS);
        XTESTS_RUN_CASE(TEST_parseHelp2_WITH_help_FLAG);
        XTESTS_RUN_CASE(TEST_parseHelp2_WITH_help_FLAG_AFTER_DOUBLEDASH);

        XTESTS_RUN_CASE(TEST_parseVerbosity_NO_ARGUMENTS);
        XTESTS_RUN_CASE(TEST_parseVerbosity_WITH_SINGLE_verbosity_OPTION);
        XTESTS_RUN_CASE(TEST_parseVerbosity_WITH_verbosity_OPTION_FOLLOWED_BY_SECOND_verbosity_OPTION);
        XTESTS_RUN_CASE(TEST_parseVerbosity_WITH_SINGLE_verbosity_OPTION_AFTER_DOUBLEDASH);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace {

    using XTESTS_NS_C_QUAL(xtests_commandLine_parseHelp2);
    using XTESTS_NS_C_QUAL(xtests_commandLine_parseVerbosity);

    using ::xtests::cpp::util::temp_file;


static void TEST_parseHelp2_NO_ARGUMENTS()
{
    char* argv[] =
    {
        "my-program",
        NULL
    };

    temp_file   tf(temp_file::CloseOnOpen | temp_file::DeleteOnClose | temp_file::EmptyOnOpen);

    {
        platformstl::FILE_stream stm(tf.c_str(), "w");

        xtests_commandLine_parseHelp2(STLSOFT_NUM_ELEMENTS(argv) - 1, argv, stlsoft::get_FILE_ptr(stm), NULL);
    }

    {
        platformstl::file_lines const lines(tf.c_str());

        XTESTS_TEST_INTEGER_EQUAL(0u, lines.size());
    }
}

static void TEST_parseHelp2_WITH_help_FLAG()
{
    char* argv[] =
    {
        "my-program",
        "--help",
        NULL
    };

    temp_file   tf(temp_file::CloseOnOpen | temp_file::DeleteOnClose | temp_file::EmptyOnOpen);

    {
        platformstl::FILE_stream stm(tf.c_str(), "w");

        xtests_commandLine_parseHelp2(STLSOFT_NUM_ELEMENTS(argv) - 1, argv, stlsoft::get_FILE_ptr(stm), NULL);
    }

    {
        platformstl::file_lines const lines(tf.c_str());

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(15u, lines.size()));

        XTESTS_TEST_MULTIBYTE_STRING_MATCHES("USAGE: my-program*", lines[0]);
    }
}

static void TEST_parseHelp2_WITH_help_FLAG_AFTER_DOUBLEDASH()
{
    char* argv[] =
    {
        "my-program",
        "--",
        "--help",
        NULL
    };

    temp_file   tf(temp_file::CloseOnOpen | temp_file::DeleteOnClose | temp_file::EmptyOnOpen);

    {
        platformstl::FILE_stream stm(tf.c_str(), "w");

        xtests_commandLine_parseHelp2(STLSOFT_NUM_ELEMENTS(argv) - 1, argv, stlsoft::get_FILE_ptr(stm), NULL);
    }

    {
        platformstl::file_lines const lines(tf.c_str());

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, lines.size()));
    }
}


static void TEST_parseVerbosity_NO_ARGUMENTS()
{
    char* argv[] =
    {
        "my-program",
        NULL
    };

    int         verbosity = -12345678;
    int const   r = xtests_commandLine_parseVerbosity(STLSOFT_NUM_ELEMENTS(argv) - 1, argv, &verbosity);

    XTESTS_TEST_INTEGER_EQUAL(0, r);
    XTESTS_TEST_INTEGER_EQUAL(ASSUMED_DEFAULT_VERBOSITY, verbosity);
}

static void TEST_parseVerbosity_WITH_SINGLE_verbosity_OPTION()
{
    char* argv[] =
    {
        "my-program",
        "--verbosity=99",
        NULL
    };

    int         verbosity = -12345678;
    int const   r = xtests_commandLine_parseVerbosity(STLSOFT_NUM_ELEMENTS(argv) - 1, argv, &verbosity);

    XTESTS_TEST_INTEGER_EQUAL(1, r);
    XTESTS_TEST_INTEGER_EQUAL(99, verbosity);
}

static void TEST_parseVerbosity_WITH_verbosity_OPTION_FOLLOWED_BY_SECOND_verbosity_OPTION()
{
    char* argv[] =
    {
        "my-program",
        "--verbosity=99",
        "--verbosity=999",
        NULL
    };

    int         verbosity = -12345678;
    int const   r = xtests_commandLine_parseVerbosity(STLSOFT_NUM_ELEMENTS(argv) - 1, argv, &verbosity);

    XTESTS_TEST_INTEGER_EQUAL(1, r);
    XTESTS_TEST_INTEGER_EQUAL(99, verbosity);
}

static void TEST_parseVerbosity_WITH_SINGLE_verbosity_OPTION_AFTER_DOUBLEDASH()
{
    char* argv[] =
    {
        "my-program",
        "--",
        "--verbosity=99",
        NULL
    };

    int         verbosity = -12345678;
    int const   r = xtests_commandLine_parseVerbosity(STLSOFT_NUM_ELEMENTS(argv) - 1, argv, &verbosity);

    XTESTS_TEST_INTEGER_EQUAL(0, r);
    XTESTS_TEST_INTEGER_EQUAL(3, verbosity);
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

