/* /////////////////////////////////////////////////////////////////////////
 * File:    src/xtests.internal.string.h
 *
 * Purpose: Internal string API.
 *
 * Created: 30th September 2015
 * Updated: 3rd November 2026
 *
 * Home:    https://github.com/synesissoftware/xTests/
 *
 * Copyright (c) 2019-2026, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2015-2019, Matthew Wilson and Synesis Software
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

#include <stddef.h>


/* /////////////////////////////////////////////////////////////////////////
 * language
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * internal API functions
 */

size_t
xtests_strnlen_(
    char const* s
,   size_t      limit
);
size_t
xtests_wcsnlen_(
    wchar_t const*  s
,   size_t          limit
);

void
xtests_strncpy_(
    char*           d
,   size_t          n
,   char const*     s
,   size_t          l
);
void
xtests_wcsncpy_(
    wchar_t*        d
,   size_t          n
,   wchar_t const*  s
,   size_t          l
);

int
xtests_strcmp_(
    char const*     str1
,   char const*     str2
);
int
xtests_wcscmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

int
xtests_stricmp_(
    char const*     str1
,   char const*     str2
);
int
xtests_wcsicmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

int
xtests_strncmp_(
    char const*     str1
,   char const*     str2
,   size_t          n
);
int
xtests_wcsncmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
);

int
xtests_strnicmp_(
    char const*     str1
,   char const*     str2
,   size_t          n
);
int
xtests_wcsnicmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
);

char const*
xtests_strstr_(
    char const*     str1
,   char const*     str2
);
wchar_t const*
xtests_wcsstr_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

char const*
xtests_stristr_(
    char const*     str1
,   char const*     str2
);
wchar_t const*
xtests_wcsistr_(
    wchar_t const*  str1
,   wchar_t const*  str2
);


/* /////////////////////////////////////////////////////////////////////////
 * language
 */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ///////////////////////////// end of file //////////////////////////// */

