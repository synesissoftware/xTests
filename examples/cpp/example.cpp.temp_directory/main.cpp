/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example.cpp.temp_directory/main.cpp
 *
 * Purpose: Example use of `xtests::cpp::util::temp_directory`.
 *
 * Created: ... mid 2010s ...
 * Updated: 31st December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */

/** \file example.cpp.temp_directory.cpp
 */


#include <xtests/util/temp_directory.hpp>

#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/path_functions.h>

#include <iostream>

#include <stdlib.h>
#include <string.h>

#include <xtests/internal/checked_main.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace {

using xtests::cpp::util::temp_directory;

typedef platformstl::filesystem_traits<char>                fs_traits_t;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    /* 1: command-line handling */

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


    /* 2: various uses of `xtests::cpp::util::temp_directory` */

    {
        std::cout << "temp_directory::None :" << std::endl;

        temp_directory tf(temp_directory::None);

        std::cout << "\tpath:\t" << tf << std::endl;
        std::cout << "\texist?:\t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:\t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:\t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
    }

    {
        std::cout << "temp_directory::RemoveOnClose :" << std::endl;

        temp_directory tf(temp_directory::RemoveOnClose);

        std::cout << "\tpath:\t" << tf << std::endl;
        std::cout << "\texist?:\t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:\t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:\t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
    }

    {
        std::cout << "temp_directory::RemoveOnOpen :" << std::endl;

        temp_directory tf(temp_directory::RemoveOnOpen);

        std::cout << "\tpath:\t" << tf << std::endl;
        std::cout << "\texist?:\t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:\t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:\t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
    }

    {
        std::cout << "temp_directory::RemoveOnClose | temp_directory::RemoveOnOpen :" << std::endl;

        temp_directory tf(temp_directory::RemoveOnClose | temp_directory::RemoveOnOpen);

        std::cout << "\tpath:\t" << tf << std::endl;
        std::cout << "\texist?:\t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:\t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:\t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
    }


    ((void)&hint_dir);


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

