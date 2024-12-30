/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example.cpp.temp_file/main.cpp
 *
 * Purpose: Example use of `xtests::cpp::util::temp_file`, illustrating:
 *              - use of various flags, including `DeleteOnOpen`, etc.;
 *              - use of hint-directory, which overrides the default temp
 *                directory for a given platform;
 *              - specifying temporary file's initial contents from an
 *                array;
 *
 * Created: ... mid 2010s ...
 * Updated: 31st December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */

/** \file example.cpp.temp_file/main.cpp
 */


#include <xtests/util/temp_file.hpp>

#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/path_functions.h>

#include <iostream>

#include <stdlib.h>
#include <string.h>

#include <xtests/internal/checked_main.hpp> // wraps the ostensible `main()` in exception handling


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace {

using xtests::cpp::util::temp_file;

typedef platformstl::filesystem_traits<char>                fs_traits_t;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * helper function declarations
 */

namespace {

    fs_traits_t::large_size_type
    get_file_size(temp_file const& tf);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    char const* const   program_name    =   platformstl::platformstl_C_get_executable_name_from_path(argv[0]).ptr;
    char const*         hint_dir;

    { for (int i = 1; i != argc; ++i)
    {
        if (0 == ::strcmp(argv[i], "--help"))
        {
            std::cout
                << "USAGE: "
                << program_name
                << " [ <hint-directory> ]"
                << std::endl;

            return EXIT_SUCCESS;
        }
    }}

    switch (argc)
    {
    case 1:

        hint_dir = ".";
        break;
    case 2:

        hint_dir = argv[1];
        break;
    default:

        std::cerr
            << program_name
            << ": too many arguments; use --help for usage"
            << std::endl;

        return EXIT_FAILURE;
    }


    /* 2: various uses of `xtests::cpp::util::temp_file` */

    /* Use `None`, which means no special behaviour */
    {
        std::cout << "temp_file::None (without hint directory):" << std::endl;

        temp_file tf(temp_file::None);

        std::cout << "\tpath:     \t" << tf << std::endl;
        std::cout << "\texist?:   \t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:    \t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:     \t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
        std::cout << "\tfile-size:\t" << get_file_size(tf) << std::endl;
    }

    /* Use `None`, but in a specific directory */
    {
        std::cout << "temp_file::None (with hint directory '" << hint_dir << "'):" << std::endl;

        temp_file tf(temp_file::None, hint_dir);

        std::cout << "\tpath:     \t" << tf << std::endl;
        std::cout << "\texist?:   \t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:    \t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:     \t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
        std::cout << "\tfile-size:\t" << get_file_size(tf) << std::endl;
    }

    /* Use `DeleteOnClose`, which causes the file to be deleted when the
     * `temp_file` instance is destroyed
     */
    {
        std::cout << "temp_file::DeleteOnClose :" << std::endl;

        temp_file tf(temp_file::DeleteOnClose);

        std::cout << "\tpath:     \t" << tf << std::endl;
        std::cout << "\texist?:   \t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:    \t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:     \t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
        std::cout << "\tfile-size:\t" << get_file_size(tf) << std::endl;
    }

    /* Use `DeleteOnOpen`, which causes the file to be deleted when the
     * `temp_file` instance is constructed
     */
    {
        std::cout << "temp_file::DeleteOnOpen :" << std::endl;

        temp_file tf(temp_file::DeleteOnOpen);

        std::cout << "\tpath:     \t" << tf << std::endl;
        std::cout << "\texist?:   \t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:    \t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:     \t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
        std::cout << "\tfile-size:\t" << get_file_size(tf) << std::endl;
    }

    /* Use both `DeleteOnOpen` and `DeleteOnClose`
     */
    {
        std::cout << "temp_file::DeleteOnClose | temp_file::DeleteOnOpen :" << std::endl;

        temp_file tf(temp_file::DeleteOnClose | temp_file::DeleteOnOpen);

        std::cout << "\tpath:     \t" << tf << std::endl;
        std::cout << "\texist?:   \t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:    \t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:     \t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
        std::cout << "\tfile-size:\t" << get_file_size(tf) << std::endl;
    }

    /* Specifying some initial contents
     */
    {
        std::cout << "some initial contents :" << std::endl;

        int const initial_contents[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

        temp_file tf(temp_file::DeleteOnClose | temp_file::EmptyOnOpen, &initial_contents, sizeof(initial_contents));

        std::cout << "\tpath:     \t" << tf << std::endl;
        std::cout << "\texist?:   \t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:    \t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:     \t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
        std::cout << "\tfile-size:\t" << get_file_size(tf) << std::endl;
    }

    /* Specifying some initial contents, but in a specific directory
     */
    {
        std::cout << "some initial contents (with hint directory '" << hint_dir << "') :" << std::endl;

        int const initial_contents[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

        temp_file tf(temp_file::DeleteOnClose | temp_file::EmptyOnOpen, hint_dir, &initial_contents, sizeof(initial_contents));

        std::cout << "\tpath:     \t" << tf << std::endl;
        std::cout << "\texist?:   \t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:    \t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:     \t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
        std::cout << "\tfile-size:\t" << get_file_size(tf) << std::endl;
    }


    return EXIT_SUCCESS;
}


/* /////////////////////////////////////////////////////////////////////////
 * helper function implementations
 */

namespace {

    fs_traits_t::large_size_type
    get_file_size(temp_file const& tf)
    {
        fs_traits_t::stat_data_type sd;

        if (!fs_traits_t::stat(tf.c_str(), &sd))
        {
            return 0;
        }
        else
        {
            return fs_traits_t::get_file_size(sd);
        }
    }
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

