/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.temp_file.cpp
 *
 * Purpose:     Implementation file for the test.scratch.temp_file project.
 *
 * Created:     1st October 2015
 * Updated:     12th October 2019
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2015-2019, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


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

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

using xtests::cpp::util::temp_file;

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /*argc*/, char** /*argv*/)
{
    temp_file   tf(temp_file::DeleteOnClose);

    fprintf(stdout, "tf: '%s'\n", tf.c_str());


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
