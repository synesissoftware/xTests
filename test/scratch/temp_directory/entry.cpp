/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.temp_directory/entry.cpp
 *
 * Purpose: Use of `xtests::cpp::util::temp_directory`.
 *
 * Created: 1st October 2015
 * Updated: 20th November 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/util/temp_directory.hpp>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <exception>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#include <xtests/internal/checked_main.hpp>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

using xtests::cpp::util::temp_directory;


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /*argc*/, char* /*argv*/[])
{
    fprintf(stderr, "creating temporary directory ...\n");

    temp_directory  td(temp_directory::RemoveOnClose | temp_directory::EmptyOnClose);

    fprintf(stdout, "td: '%s'\n", td.c_str());

    fprintf(stderr, "creating sub-directory ...\n");

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

    ::CreateDirectoryA((std::string(td.c_str()) + "\\abc").c_str(), NULL);
#else

    ::mkdir((std::string(td.c_str()) + "/abc").c_str(), S_IRWXU);
#endif

    fprintf(stderr, "exiting ...\n");

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

