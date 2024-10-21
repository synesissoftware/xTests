/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.temp_file.cpp
 *
 * Purpose: Component-tests for `xtests::cpp::util::temp_file`.
 *
 * Created: 5th May 2024
 * Updated: 21st October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <xtests/util/temp_file.hpp>

#include <xtests/xtests.h>

#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/FILE_stream.hpp>

#include <xtests/internal/checked_main.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_None(void);
    static void test_DeleteOnClose(void);
    static void test_DeleteOnOpen(void);
    static void test_DeleteOnOpen_DeleteOnClose(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.temp_file", verbosity))
    {
        XTESTS_RUN_CASE(test_None);
        XTESTS_RUN_CASE(test_DeleteOnClose);
        XTESTS_RUN_CASE(test_DeleteOnOpen);
        XTESTS_RUN_CASE(test_DeleteOnOpen_DeleteOnClose);

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
    using xtests::cpp::util::temp_file;

    typedef platformstl::filesystem_traits<char>    fs_traits_t;


static void test_None()
{
    std::string path;

    {
        temp_file tf(temp_file::None);

        path.assign(tf.c_str());

        XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));
        XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::is_file(path.c_str()));
    }

    XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));
    XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::is_file(path.c_str()));

    fs_traits_t::unlink_file(path.c_str());

    XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
    XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::is_file(path.c_str()));
}

static void test_DeleteOnClose()
{
    std::string path;

    {
        temp_file tf(temp_file::DeleteOnClose);

        path.assign(tf.c_str());

        XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));
        XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::is_file(path.c_str()));
    }

    XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
    XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::is_file(path.c_str()));
}

static void test_DeleteOnOpen()
{
    std::string path;

    {
        temp_file tf(temp_file::DeleteOnOpen);

        path.assign(tf.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
        XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::is_file(path.c_str()));

        // since the file was deleted-on-open, we create it

        platformstl::FILE_stream stm(path, "w");

        XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));
        XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::is_file(path.c_str()));
    }

    XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));
    XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::is_file(path.c_str()));

    fs_traits_t::unlink_file(path.c_str());

    XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
    XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::is_file(path.c_str()));
}

static void test_DeleteOnOpen_DeleteOnClose()
{
    std::string path;

    {
        temp_file tf(temp_file::DeleteOnClose | temp_file::DeleteOnOpen);

        path.assign(tf.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
        XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::is_file(path.c_str()));

        // since the file was deleted-on-open, we create it

        platformstl::FILE_stream stm(path, "w");

        XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));
        XTESTS_TEST_BOOLEAN_TRUE(fs_traits_t::is_file(path.c_str()));
    }

    XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
    XTESTS_TEST_BOOLEAN_FALSE(fs_traits_t::is_file(path.c_str()));
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

