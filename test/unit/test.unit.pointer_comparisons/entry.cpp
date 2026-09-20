/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.pointer_comparisons/entry.cpp
 *
 * Purpose: Unit-tests for pointer assertion macros, including
 *          XTESTS_TEST_POINTER_NULL / XTESTS_TEST_POINTER_NOT_NULL.
 *
 * Created: 20th September 2026
 * Updated: 20th September 2026
 *
 * Home:    https://github.com/synesissoftware/xTests/
 *
 * Copyright (c) 2026, Matthew Wilson and Synesis Information Systems
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer;
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution;
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <xtests/terse-api.h>

/* /////////////////////////////////////
 * general includes
 */

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////
 * final includes
 */

#include <xtests/internal/checked_main.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_POINTER_NULL_PASSES_WHEN_ACTUAL_IS_NULL();
    static void TEST_POINTER_NOT_NULL_PASSES_WHEN_ACTUAL_IS_NOT_NULL();
    static void TEST_POINTER_EQUAL_NULL_PASSES_WHEN_ACTUAL_IS_NULL();
    static void TEST_POINTER_NOT_EQUAL_NULL_PASSES_WHEN_ACTUAL_IS_NOT_NULL();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.pointer_comparisons", verbosity))
    {
        XTESTS_RUN_CASE(TEST_POINTER_NULL_PASSES_WHEN_ACTUAL_IS_NULL);
        XTESTS_RUN_CASE(TEST_POINTER_NOT_NULL_PASSES_WHEN_ACTUAL_IS_NOT_NULL);
        XTESTS_RUN_CASE(TEST_POINTER_EQUAL_NULL_PASSES_WHEN_ACTUAL_IS_NULL);
        XTESTS_RUN_CASE(TEST_POINTER_NOT_EQUAL_NULL_PASSES_WHEN_ACTUAL_IS_NOT_NULL);

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

static void TEST_POINTER_NULL_PASSES_WHEN_ACTUAL_IS_NULL()
{
    int* p = NULL;

    XTESTS_TEST_POINTER_NULL(p);
    TEST_POINTER_NULL(p);
    TEST_PTR_NULL(p);
}

static void TEST_POINTER_NOT_NULL_PASSES_WHEN_ACTUAL_IS_NOT_NULL()
{
    int  x;
    int* p = &x;

    XTESTS_TEST_POINTER_NOT_NULL(p);
    TEST_POINTER_NOT_NULL(p);
    TEST_PTR_NOT_NULL(p);
}

static void TEST_POINTER_EQUAL_NULL_PASSES_WHEN_ACTUAL_IS_NULL()
{
    int* p = NULL;

    TEST_PTR_EQ(NULL, p);
}

static void TEST_POINTER_NOT_EQUAL_NULL_PASSES_WHEN_ACTUAL_IS_NOT_NULL()
{
    int  x = -1;
    int* p = &x;

    TEST_PTR_NE(NULL, p);
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */
