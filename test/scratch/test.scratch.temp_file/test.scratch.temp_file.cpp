/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.temp_file.cpp
 *
 * Purpose: Use of `xtests::cpp::util::temp_file`.
 *
 * Created: 1st October 2015
 * Updated: 28th September 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

/* xTests Header Files */
#include <xtests/util/temp_file.hpp>

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

using xtests::cpp::util::temp_file;


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /*argc*/, char* /*argv*/[])
{
    fprintf(stderr, "creating temporary file ...\n");

    temp_file   tf(temp_file::DeleteOnClose);

    fprintf(stdout, "tf: '%s'\n", tf.c_str());

    fprintf(stderr, "exiting ...\n");

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

