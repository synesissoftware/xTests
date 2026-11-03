/* /////////////////////////////////////////////////////////////////////////
 * File:    src/xtests.internal.string.c
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


#include "xtests.internal.string.h"

#include <stlsoft/string/c_string/strnicmp.h>
#include <stlsoft/string/c_string/strnistrn.h>
#include <stlsoft/string/c_string/strnstrn.h>
#include <stlsoft/string/copy_functions.h>

#include <string.h>
#include <wchar.h>


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
xTests_strnlen_(
    char const* s
,   size_t      limit
) STLSOFT_NOEXCEPT
{
    size_t n = 0;

    for (; 0 != limit && '\0' != *s; --limit, ++s)
    {
        ++n;
    }

    return n;
}

size_t
xTests_wcsnlen_(
    wchar_t const*  s
,   size_t          limit
) STLSOFT_NOEXCEPT
{
    size_t n = 0;

    for (; 0 != limit && L'\0' != *s; --limit, ++s)
    {
        ++n;
    }

    return n;
}

void
xTests_strncpy_(
    char*           d
,   size_t          n
,   char const*     s
,   size_t          l
) STLSOFT_NOEXCEPT
{
    stlsoft_C_string_copy_a(d, n, s, l);

    /* stlsoft_C_string_copy_a leaves dest untouched when cchSrc is 0;
     * preserve the prior contract of writing a NUL when l < n.
     */
    if (0 == l &&
        0 != n)
    {
        d[0] = '\0';
    }
}

void
xTests_wcsncpy_(
    wchar_t*        d
,   size_t          n
,   wchar_t const*  s
,   size_t          l
) STLSOFT_NOEXCEPT
{
    stlsoft_C_string_copy_w(d, n, s, l);
}

int
xTests_strcmp_(
    char const*     str1
,   char const*     str2
) STLSOFT_NOEXCEPT
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        STLSOFT_ASSERT(NULL != str2);

        return ('\0' == *str2) ? 0 : -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return ('\0' == *str1) ? 0 : +1;
    }
    else
    {
        return strcmp(str1, str2);
    }
}

int
xTests_wcscmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
) STLSOFT_NOEXCEPT
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        STLSOFT_ASSERT(NULL != str2);

        return (L'\0' == *str2) ? 0 : -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return (L'\0' == *str1) ? 0 : +1;
    }
    else
    {
        return wcscmp(str1, str2);
    }
}

int
xTests_stricmp_(
    char const*     str1
,   char const*     str2
) STLSOFT_NOEXCEPT
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        STLSOFT_ASSERT(NULL != str2);

        return ('\0' == *str2) ? 0 : -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return ('\0' == *str1) ? 0 : +1;
    }
    else
    {
        return stlsoft_C_strnicmp(str1, str2, ~(size_t)0);
    }
}

int
xTests_wcsicmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
) STLSOFT_NOEXCEPT
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        STLSOFT_ASSERT(NULL != str2);

        return (L'\0' == *str2) ? 0 : -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return (L'\0' == *str1) ? 0 : +1;
    }
    else
    {
        return stlsoft_C_wcsnicmp(str1, str2, ~(size_t)0);
    }
}

int
xTests_strncmp_(
    char const*     str1
,   char const*     str2
,   size_t          n
) STLSOFT_NOEXCEPT
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (0 == n)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        STLSOFT_ASSERT(NULL != str2);

        return ('\0' == *str2) ? 0 : -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return ('\0' == *str1) ? 0 : +1;
    }
    else
    {
        return strncmp(str1, str2, n);
    }
}

int
xTests_wcsncmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
) STLSOFT_NOEXCEPT
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (0 == n)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        STLSOFT_ASSERT(NULL != str2);

        return (L'\0' == *str2) ? 0 : -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return (L'\0' == *str1) ? 0 : +1;
    }
    else
    {
        return wcsncmp(str1, str2, n);
    }
}

int
xTests_strnicmp_(
    char const*     str1
,   char const*     str2
,   size_t          n
) STLSOFT_NOEXCEPT
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (0 == n)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        return (NULL == str2 || '\0' == *str2) ? 0 : -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return ('\0' == *str1) ? 0 : +1;
    }
    else
    {
        return stlsoft_C_strnicmp(str1, str2, n);
    }
}

int
xTests_wcsnicmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
) STLSOFT_NOEXCEPT
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (0 == n)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        return (NULL == str2 || L'\0' == *str2) ? 0 : -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return (L'\0' == *str1) ? 0 : +1;
    }
    else
    {
        return stlsoft_C_wcsnicmp(str1, str2, n);
    }
}

char const*
xTests_strstr_(
    char const*     str1
,   char const*     str2
) STLSOFT_NOEXCEPT
{
    if (NULL == str1)
    {
        return NULL;
    }
    else if (NULL == str2)
    {
        return str1;
    }
    else
    {
        return stlsoft_C_strnstrn(str1, strlen(str1), str2, strlen(str2));
    }
}

wchar_t const*
xTests_wcsstr_(
    wchar_t const*  str1
,   wchar_t const*  str2
) STLSOFT_NOEXCEPT
{
    if (NULL == str1)
    {
        return NULL;
    }
    else if (NULL == str2)
    {
        return str1;
    }
    else
    {
        return stlsoft_C_wcsnstrn(str1, wcslen(str1), str2, wcslen(str2));
    }
}

char const*
xTests_stristr_(
    char const*     str1
,   char const*     str2
) STLSOFT_NOEXCEPT
{
    if (NULL == str1)
    {
        return NULL;
    }
    else if (NULL == str2)
    {
        return str1;
    }
    else
    {
        return stlsoft_C_strnistrn(str1, strlen(str1), str2, strlen(str2));
    }
}

wchar_t const*
xTests_wcsistr_(
    wchar_t const*  str1
,   wchar_t const*  str2
) STLSOFT_NOEXCEPT
{
    if (NULL == str1)
    {
        return NULL;
    }
    else if (NULL == str2)
    {
        return str1;
    }
    else
    {
        return stlsoft_C_wcsnistrn(str1, wcslen(str1), str2, wcslen(str2));
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * language
 */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ///////////////////////////// end of file //////////////////////////// */

