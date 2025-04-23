/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.temp_directory/entry.cpp
 *
 * Purpose: Component-tests for `xtests::cpp::util::temp_directory`.
 *
 * Created: 20th February 2025
 * Updated: 23rd April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <xtests/util/temp_directory.hpp>

#include <xtests/terse-api.h>

#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/FILE_stream.hpp>
#include <platformstl/filesystem/path.hpp>
#include <platformstl/filesystem/readdir_sequence.hpp>

#include <xtests/internal/checked_main.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_None();
    static void test_EmptyOnOpen();
    static void test_EmptyOnClose();
    static void test_RemoveOnClose();
    static void test_RemoveOnOpen();
    static void test_EmptyOnClose_RemoveOnClose();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.temp_directory", verbosity))
    {
        XTESTS_RUN_CASE(test_None);
        XTESTS_RUN_CASE(test_EmptyOnOpen);
        XTESTS_RUN_CASE(test_EmptyOnClose);
        XTESTS_RUN_CASE(test_RemoveOnClose);
        XTESTS_RUN_CASE(test_RemoveOnOpen);
        XTESTS_RUN_CASE(test_EmptyOnClose_RemoveOnClose);

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
    using xtests::cpp::util::temp_directory;

    typedef platformstl::filesystem_traits<char>            fs_traits_t;
    typedef platformstl::path                               path_t;
    using platformstl::readdir_sequence;

    using stlsoft::ss_size_t;

    typedef std::pair<
        ss_size_t   // number of file entries
    ,   ss_size_t   // number of directory entries
    >                                                       counts_t;

    counts_t
    count_top_level_contents(
        char const* dir_path
    )
    {
        ss_size_t   num_files   =   0;
        ss_size_t   num_dirs    =   0;

        if (fs_traits_t::file_exists(dir_path))
        {
            {
                readdir_sequence files(dir_path, readdir_sequence::files);

                for (readdir_sequence::const_iterator i = files.begin(); files.end() != i; ++i, ++num_files)
                {
                }
            }

            {
                readdir_sequence directories(dir_path, readdir_sequence::directories);

                for (readdir_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i, ++num_dirs)
                {
                }
            }
        }

        return std::make_pair(num_files, num_dirs);
    }

    bool
    create_file_in_dir(
        char const* dir_path
    ,   char const* file_name
    )
    {
        path_t path(dir_path);

        path /= file_name;

        fs_traits_t::file_handle_type h = fs_traits_t::open_file(path.c_str(), O_CREAT, 0);

        if (fs_traits_t::invalid_file_handle_value() == h)
        {
            return false;
        }
        else
        {
            fs_traits_t::close_file(h);

            return true;
        }
    }


static void test_None()
{
    std::string path;

    {
        temp_directory  tf(temp_directory::None);

        path.assign(tf.c_str());

        {
            counts_t const  counts_during = count_top_level_contents(tf.c_str());

            TEST_INT_EQ(0u, counts_during.first);
            TEST_INT_EQ(0u, counts_during.second);
        }

        {
            bool const  created_1 = create_file_in_dir(tf.c_str(), "file-1");
            bool const  created_2 = create_file_in_dir(tf.c_str(), "file-2");

            TEST_BOOLEAN_TRUE(created_1);
            TEST_BOOLEAN_TRUE(created_2);
        }
    }

    {
        counts_t const counts_after = count_top_level_contents(path.c_str());

        TEST_INT_EQ(2u, counts_after.first);
        TEST_INT_EQ(0u, counts_after.second);
    }

    fs_traits_t::delete_file((path + "/file-1").c_str());
    fs_traits_t::delete_file((path + "/file-2").c_str());

    TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));

    fs_traits_t::remove_directory(path.c_str());
}

static void test_EmptyOnOpen()
{
    std::string path;

    {
        temp_directory  tf(temp_directory::None);

        path.assign(tf.c_str());

        {
            counts_t const  counts_during = count_top_level_contents(tf.c_str());

            TEST_INT_EQ(0u, counts_during.first);
            TEST_INT_EQ(0u, counts_during.second);
        }
    }

    {
        counts_t const counts_after = count_top_level_contents(path.c_str());

        TEST_INT_EQ(0u, counts_after.first);
        TEST_INT_EQ(0u, counts_after.second);
    }

    TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));

    fs_traits_t::remove_directory(path.c_str());
}

static void test_EmptyOnClose()
{
    std::string path;

    {
        temp_directory  tf(temp_directory::EmptyOnClose);

        path.assign(tf.c_str());

        {
            counts_t const  counts_during = count_top_level_contents(tf.c_str());

            TEST_INT_EQ(0u, counts_during.first);
            TEST_INT_EQ(0u, counts_during.second);
        }

        {
            bool const  created_1 = create_file_in_dir(tf.c_str(), "file-1");
            bool const  created_2 = create_file_in_dir(tf.c_str(), "file-2");

            TEST_BOOLEAN_TRUE(created_1);
            TEST_BOOLEAN_TRUE(created_2);
        }
    }

    {
        counts_t const counts_after = count_top_level_contents(path.c_str());

        TEST_INT_EQ(0u, counts_after.first);
        TEST_INT_EQ(0u, counts_after.second);
    }

    TEST_BOOLEAN_TRUE(fs_traits_t::file_exists(path.c_str()));

    fs_traits_t::remove_directory(path.c_str());
}

static void test_RemoveOnClose()
{
    std::string path;

    {
        temp_directory  tf(temp_directory::RemoveOnClose);

        path.assign(tf.c_str());

        {
            counts_t const  counts_during = count_top_level_contents(tf.c_str());

            TEST_INT_EQ(0u, counts_during.first);
            TEST_INT_EQ(0u, counts_during.second);
        }
    }

    {
        counts_t const counts_after = count_top_level_contents(path.c_str());

        TEST_INT_EQ(0u, counts_after.first);
        TEST_INT_EQ(0u, counts_after.second);
    }

    TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
}

static void test_RemoveOnOpen()
{
    std::string path;

    {
        temp_directory  tf(temp_directory::RemoveOnOpen);

        path.assign(tf.c_str());

        TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));

        {
            counts_t const  counts_during = count_top_level_contents(tf.c_str());

            TEST_INT_EQ(0u, counts_during.first);
            TEST_INT_EQ(0u, counts_during.second);
        }
    }

    {
        counts_t const counts_after = count_top_level_contents(path.c_str());

        TEST_INT_EQ(0u, counts_after.first);
        TEST_INT_EQ(0u, counts_after.second);
    }

    TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
}

static void test_EmptyOnClose_RemoveOnClose()
{
    std::string path;

    {
        temp_directory  tf(temp_directory::EmptyOnClose | temp_directory::RemoveOnClose);

        path.assign(tf.c_str());

        {
            counts_t const  counts_during = count_top_level_contents(tf.c_str());

            TEST_INT_EQ(0u, counts_during.first);
            TEST_INT_EQ(0u, counts_during.second);
        }

        {
            bool const  created_1 = create_file_in_dir(tf.c_str(), "file-1");
            bool const  created_2 = create_file_in_dir(tf.c_str(), "file-2");

            TEST_BOOLEAN_TRUE(created_1);
            TEST_BOOLEAN_TRUE(created_2);
        }
    }

    {
        counts_t const counts_after = count_top_level_contents(path.c_str());

        TEST_INT_EQ(0u, counts_after.first);
        TEST_INT_EQ(0u, counts_after.second);
    }

    TEST_BOOLEAN_FALSE(fs_traits_t::file_exists(path.c_str()));
}
} // anonymous namespace


 /* ///////////////////////////// end of file //////////////////////////// */

