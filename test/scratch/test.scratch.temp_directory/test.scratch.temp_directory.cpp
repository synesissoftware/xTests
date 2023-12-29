/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.temp_directory.cpp
 *
 * Purpose: Use of `xtests::cpp::util::temp_directory`.
 *
 * Created: 1st October 2015
 * Updated: 29th November 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


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

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

using xtests::cpp::util::temp_directory;

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /*argc*/, char** /*argv*/)
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

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        res = main_(argc, argv);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
    catch(std::exception &x)
    {
        ::fprintf(stderr, "Unhandled failure: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(XTESTS_NS_CPP_QUAL(prerequisite_failed_exception)& x)
    {
        ::fprintf(stderr, "Unhandled failure: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        ::fprintf(stderr, "Unhandled unknown failure\n");

        res = EXIT_FAILURE;
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */

