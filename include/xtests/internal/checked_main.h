/* /////////////////////////////////////////////////////////////////////////
 * File:    xtests/internal/checked_main.h
 *
 * Purpose: Provides platform-specific checking around `main()` in a C
 *          compilation unit.
 *
 * Created: 28th September 2024
 * Updated: 28th September 2024
 *
 * Home:    https://github.com/synesissoftware/xTests/
 *
 * Copyright (c) 2024, Matthew Wilson and Synesis Information Systems
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
 *   ontributors may be used to endorse or promote products derived from
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


/** \file xtests/internal/checked_main.h
 *
 * [C-only] Provides platform-specific checking around `main()` in a C
 *     compilation unit.
 */


#ifdef XTESTS_INCL_XTESTS_INTERNAL_H_CHECKED_MAIN
# error Already include xtests/internal/checked_main.h
#endif
#ifdef XTESTS_INCL_XTESTS_INTERNAL_HPP_CHECKED_MAIN
# error Cannot include both xtests/internal/checked_main.h and xtests/internal/checked_main.hpp
#endif

#define XTESTS_INCL_XTESTS_INTERNAL_H_CHECKED_MAIN

#ifdef __cplusplus
# error Should not be used in a C++ compilation-unit - instead include xtests/internal/checked_main.hpp
#endif


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * function declarations
 */

int main_impl(int argc, char* argv[]);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
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

    res = main_impl(argc, argv);

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define main        main_impl


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ///////////////////////////// end of file //////////////////////////// */

