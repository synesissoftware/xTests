/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example.cpp.temp_file/example.cpp.temp_file.cpp
 *
 * Purpose: Example use of `xtests::cpp::util::temp_file`.
 *
 * Created: ... mid 2010s ...
 * Updated: 30th December 2024
 *
 * ////////////////////////////////////////////////////////////////////// */

/** \file example.cpp.temp_file.cpp
 */


#include <xtests/util/temp_file.hpp>

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

using xtests::cpp::util::temp_file;

typedef platformstl::filesystem_traits<char>                fs_traits_t;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    char const* const   progran_name    =   platformstl::platformstl_C_get_executable_name_from_path(argv[0]).ptr;
    char const*         hint_dir;

    { for (int i = 1; i != argc; ++i)
    {
        if (0 == ::strcmp(argv[i], "--help"))
        {
            std::cout
                << "USAGE: "
                << progran_name
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
            << progran_name
            << ": too many arguments; use --help for usage"
            << std::endl;

        return EXIT_FAILURE;
    }

    {
        std::cout << "temp_file::None : " << std::endl;

        temp_file tf(temp_file::None);

        std::cout << "\tpath:\t" << tf << std::endl;
        std::cout << "\texist?:\t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:\t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:\t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
    }

    {
        std::cout << "temp_file::DeleteOnClose : " << std::endl;

        temp_file tf(temp_file::DeleteOnClose);

        std::cout << "\tpath:\t" << tf << std::endl;
        std::cout << "\texist?:\t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:\t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:\t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
    }

    {
        std::cout << "temp_file::DeleteOnOpen : " << std::endl;

        temp_file tf(temp_file::DeleteOnOpen);

        std::cout << "\tpath:\t" << tf << std::endl;
        std::cout << "\texist?:\t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:\t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:\t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
    }

    {
        std::cout << "temp_file::DeleteOnClose | temp_file::DeleteOnOpen : " << std::endl;

        temp_file tf(temp_file::DeleteOnClose | temp_file::DeleteOnOpen);

        std::cout << "\tpath:\t" << tf << std::endl;
        std::cout << "\texist?:\t" << fs_traits_t::file_exists(tf.c_str()) << std::endl;
        std::cout << "\tfile?:\t" << fs_traits_t::is_file(tf.c_str()) << std::endl;
        std::cout << "\tdir?:\t" << fs_traits_t::is_directory(tf.c_str()) << std::endl;
    }


    ((void)&hint_dir);


    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

