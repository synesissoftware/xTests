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


/** \file src/xtests.internal.string.h
 *
 * Internal C-string helpers used by the xTests core implementation.
 *
 * These functions are not part of the public API. Several provide
 * NULL-tolerant behaviour beyond the corresponding C library routines,
 * so that assertion evaluation can compare optional / absent string
 * values without invoking undefined behaviour.
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <stlsoft/stlsoft.h>

#include <stddef.h>
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

/** Counts characters in a multibyte C-string, bounded by @a limit.
 *
 * Walks @a s until a NUL is found or @a limit characters have been
 * examined, whichever comes first.
 *
 * Implemented as a local scan rather than CRT @c strnlen, which is not
 * in ISO C90/C99 (POSIX.1-2008 / later) and is absent or feature-gated
 * on some toolchains xTests still supports.
 *
 * @param s Pointer to the string to measure. Must not be @c NULL.
 * @param limit Maximum number of characters to examine.
 *
 * @return The number of characters before the NUL, or @a limit if no
 *  NUL occurs within the first @a limit characters. Never greater than
 *  @a limit.
 *
 * @pre NULL != s
 * @pre @a s is either NUL-terminated within the first @a limit
 *  characters, or is readable for at least @a limit characters
 */
size_t
xTests_strnlen_(
    char const* s
,   size_t      limit
) STLSOFT_NOEXCEPT;

/** Counts characters in a wide C-string, bounded by @a limit.
 *
 * Wide-character counterpart of xTests_strnlen_(). Likewise avoids CRT
 * @c wcsnlen for the same portability reason.
 *
 * @param s Pointer to the string to measure. Must not be @c NULL.
 * @param limit Maximum number of wide characters to examine.
 *
 * @return The number of wide characters before the NUL, or @a limit if
 *  no NUL occurs within the first @a limit characters. Never greater
 *  than @a limit.
 *
 * @pre NULL != s
 * @pre @a s is either NUL-terminated within the first @a limit wide
 *  characters, or is readable for at least @a limit wide characters
 */
size_t
xTests_wcsnlen_(
    wchar_t const*  s
,   size_t          limit
) STLSOFT_NOEXCEPT;

/** Copies a length-bounded multibyte string into a capacity-bounded
 * destination buffer.
 *
 * Implemented in terms of <code>stlsoft_C_string_copy_a</code>, with a
 * small adjustment so that @a l of 0 still writes a terminating NUL when
 * @a n is non-zero (the STLSoft helper leaves @a d untouched in that case).
 *
 * Copies @a l characters from @a s into @a d, subject to the destination
 * capacity @a n:
 *
 * - if @a l is less than @a n, copies @a l characters and writes a
 *   terminating NUL at <code>d[l]</code>;
 * - if @a l is greater than or equal to @a n, copies exactly @a n
 *   characters and does <em>not</em> write a terminating NUL.
 *
 * @param d Destination buffer. Must not be @c NULL.
 * @param n Capacity of @a d, in characters (not including any extra
 *  slot implied by NUL-termination — see the rules above).
 * @param s Source string. Must not be @c NULL.
 * @param l Number of characters to take from @a s.
 *
 * @pre NULL != d
 * @pre NULL != s
 * @pre @a d has room for @a n characters; when @a l &lt; @a n it must
 *  also have room for the terminating NUL at <code>d[l]</code>
 * @pre @a s is readable for at least @a l characters
 *
 * @note This is intentionally unlike CRT @c strncpy: the source length
 *  is an explicit argument, and truncation (<code>l &gt;= n</code>)
 *  leaves @a d without a terminating NUL.
 */
void
xTests_strncpy_(
    char*           d
,   size_t          n
,   char const*     s
,   size_t          l
) STLSOFT_NOEXCEPT;

/** Copies a length-bounded wide string into a capacity-bounded
 * destination buffer.
 *
 * Wide-character counterpart of xTests_strncpy_(), implemented in terms of
 * <code>stlsoft_C_string_copy_w</code> (which already writes a NUL when
 * @a l is 0 and @a n is non-zero).
 *
 * @param d Destination buffer. Must not be @c NULL.
 * @param n Capacity of @a d, in wide characters.
 * @param s Source string. Must not be @c NULL.
 * @param l Number of wide characters to take from @a s.
 *
 * @pre NULL != d
 * @pre NULL != s
 * @pre @a d has room for @a n wide characters; when @a l &lt; @a n it
 *  must also have room for the terminating NUL at <code>d[l]</code>
 * @pre @a s is readable for at least @a l wide characters
 *
 * @note Truncation (<code>l &gt;= n</code>) leaves @a d without a
 *  terminating NUL.
 */
void
xTests_wcsncpy_(
    wchar_t*        d
,   size_t          n
,   wchar_t const*  s
,   size_t          l
) STLSOFT_NOEXCEPT;

/** Case-sensitive lexicographic comparison of two multibyte C-strings,
 * tolerating @c NULL.
 *
 * Comparison order:
 *
 * - if @a str1 and @a str2 are the same pointer, returns 0;
 * - if @a str1 is @c NULL, returns 0 when @a str2 is an empty string,
 *   otherwise a negative value;
 * - if @a str2 is @c NULL, returns 0 when @a str1 is an empty string,
 *   otherwise a positive value;
 * - otherwise returns <code>strcmp(str1, str2)</code>.
 *
 * Thus a @c NULL argument compares equal to an empty string, and less
 * than / greater than any non-empty string according to which side is
 * @c NULL.
 *
 * @param str1 First string; may be @c NULL.
 * @param str2 Second string; may be @c NULL.
 *
 * @retval 0 The strings are equal (including @c NULL vs empty).
 * @retval &lt;0 @a str1 is less than @a str2 (or @a str1 is @c NULL and
 *  @a str2 is non-empty).
 * @retval &gt;0 @a str1 is greater than @a str2 (or @a str2 is @c NULL
 *  and @a str1 is non-empty).
 *
 * @note Both arguments may be @c NULL; that case yields 0 because the
 *  pointers compare equal.
 */
int
xTests_strcmp_(
    char const*     str1
,   char const*     str2
) STLSOFT_NOEXCEPT;

/** Case-sensitive lexicographic comparison of two wide C-strings,
 * tolerating @c NULL.
 *
 * Wide-character counterpart of xTests_strcmp_(), implemented in terms
 * of @c wcscmp when both arguments are non-@c NULL.
 *
 * @param str1 First string; may be @c NULL.
 * @param str2 Second string; may be @c NULL.
 *
 * @retval 0 The strings are equal (including @c NULL vs empty).
 * @retval &lt;0 @a str1 is less than @a str2 (or @a str1 is @c NULL and
 *  @a str2 is non-empty).
 * @retval &gt;0 @a str1 is greater than @a str2 (or @a str2 is @c NULL
 *  and @a str1 is non-empty).
 */
int
xTests_wcscmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
) STLSOFT_NOEXCEPT;

/** Case-insensitive lexicographic comparison of two multibyte
 * C-strings, tolerating @c NULL.
 *
 * Comparison order:
 *
 * - if @a str1 and @a str2 are the same pointer, returns 0;
 * - if @a str1 is @c NULL, returns 0 when @a str2 is an empty string,
 *   otherwise a negative value;
 * - if @a str2 is @c NULL, returns 0 when @a str1 is an empty string,
 *   otherwise a positive value;
 * - otherwise returns
 *   <code>stlsoft_C_strnicmp(str1, str2, ~(size_t)0)</code>.
 *
 * @param str1 First string; may be @c NULL.
 * @param str2 Second string; may be @c NULL.
 *
 * @retval 0 The folded strings are equal (including @c NULL vs empty).
 * @retval &lt;0 @a str1 is less than @a str2 (or @a str1 is @c NULL and
 *  @a str2 is non-empty).
 * @retval &gt;0 @a str1 is greater than @a str2 (or @a str2 is @c NULL
 *  and @a str1 is non-empty).
 *
 * @note NULL-vs-empty handling matches xTests_strcmp_() /
 *  xTests_strnicmp_().
 *
 * @note Case folding follows <code>stlsoft_C_strnicmp</code> (ASCII
 *  letters fold by 32; other bytes unchanged).
 */
int
xTests_stricmp_(
    char const*     str1
,   char const*     str2
) STLSOFT_NOEXCEPT;

/** Case-insensitive lexicographic comparison of two wide C-strings,
 * tolerating @c NULL.
 *
 * Wide-character counterpart of xTests_stricmp_(), implemented in terms
 * of <code>stlsoft_C_wcsnicmp</code> when both arguments are
 * non-@c NULL.
 *
 * @param str1 First string; may be @c NULL.
 * @param str2 Second string; may be @c NULL.
 *
 * @retval 0 The folded strings are equal (including @c NULL vs empty).
 * @retval &lt;0 @a str1 is less than @a str2 (or @a str1 is @c NULL and
 *  @a str2 is non-empty).
 * @retval &gt;0 @a str1 is greater than @a str2 (or @a str2 is @c NULL
 *  and @a str1 is non-empty).
 *
 * @note Case folding follows <code>stlsoft_C_wcsnicmp</code>.
 */
int
xTests_wcsicmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
) STLSOFT_NOEXCEPT;

/** Case-sensitive lexicographic comparison of the first @a n characters
 * of two multibyte C-strings, tolerating @c NULL.
 *
 * Comparison order:
 *
 * - if @a str1 and @a str2 are the same pointer, returns 0;
 * - if @a n is 0, returns 0;
 * - if @a str1 is @c NULL, returns 0 when @a str2 is an empty string,
 *   otherwise a negative value;
 * - if @a str2 is @c NULL, returns 0 when @a str1 is an empty string,
 *   otherwise a positive value;
 * - otherwise returns <code>strncmp(str1, str2, n)</code>.
 *
 * @param str1 First string; may be @c NULL.
 * @param str2 Second string; may be @c NULL.
 * @param n Maximum number of characters to compare.
 *
 * @retval 0 The compared prefixes are equal (including when @a n is 0,
 *  or @c NULL vs empty).
 * @retval &lt;0 The @a str1 prefix is less than the @a str2 prefix (or
 *  @a str1 is @c NULL and @a str2 is non-empty).
 * @retval &gt;0 The @a str1 prefix is greater than the @a str2 prefix
 *  (or @a str2 is @c NULL and @a str1 is non-empty).
 *
 * @note When both arguments are non-@c NULL, characters beyond a NUL
 *  within the first @a n positions are not compared, per @c strncmp.
 */
int
xTests_strncmp_(
    char const*     str1
,   char const*     str2
,   size_t          n
) STLSOFT_NOEXCEPT;

/** Case-sensitive lexicographic comparison of the first @a n characters
 * of two wide C-strings, tolerating @c NULL.
 *
 * Wide-character counterpart of xTests_strncmp_(), implemented in terms
 * of @c wcsncmp when both arguments are non-@c NULL and @a n is
 * non-zero.
 *
 * @param str1 First string; may be @c NULL.
 * @param str2 Second string; may be @c NULL.
 * @param n Maximum number of wide characters to compare.
 *
 * @retval 0 The compared prefixes are equal (including when @a n is 0,
 *  or @c NULL vs empty).
 * @retval &lt;0 The @a str1 prefix is less than the @a str2 prefix (or
 *  @a str1 is @c NULL and @a str2 is non-empty).
 * @retval &gt;0 The @a str1 prefix is greater than the @a str2 prefix
 *  (or @a str2 is @c NULL and @a str1 is non-empty).
 */
int
xTests_wcsncmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
) STLSOFT_NOEXCEPT;

/** Case-insensitive lexicographic comparison of the first @a n
 * characters of two multibyte C-strings, tolerating @c NULL.
 *
 * Comparison order:
 *
 * - if @a str1 and @a str2 are the same pointer, returns 0;
 * - if @a n is 0, returns 0;
 * - if @a str1 is @c NULL, returns 0 when @a str2 is @c NULL or empty,
 *   otherwise a negative value;
 * - if @a str2 is @c NULL, returns 0 when @a str1 is empty, otherwise a
 *   positive value;
 * - otherwise returns
 *   <code>stlsoft_C_strnicmp(str1, str2, n)</code>.
 *
 * @param str1 First string; may be @c NULL.
 * @param str2 Second string; may be @c NULL.
 * @param n Maximum number of characters to compare.
 *
 * @retval 0 The compared (case-folded) prefixes are equal (including
 *  when @a n is 0, or @c NULL vs @c NULL / empty).
 * @retval &lt;0 The @a str1 prefix is less than the @a str2 prefix (or
 *  @a str1 is @c NULL and @a str2 is non-empty).
 * @retval &gt;0 The @a str1 prefix is greater than the @a str2 prefix
 *  (or @a str2 is @c NULL and @a str1 is non-empty).
 *
 * @note Both arguments may be @c NULL when @a n is non-zero; that case
 *  yields 0, matching xTests_stricmp_().
 */
int
xTests_strnicmp_(
    char const*     str1
,   char const*     str2
,   size_t          n
) STLSOFT_NOEXCEPT;

/** Case-insensitive lexicographic comparison of the first @a n
 * characters of two wide C-strings, tolerating @c NULL.
 *
 * Wide-character counterpart of xTests_strnicmp_(), implemented in
 * terms of <code>stlsoft_C_wcsnicmp</code> when both arguments are
 * non-@c NULL and @a n is non-zero.
 *
 * @param str1 First string; may be @c NULL.
 * @param str2 Second string; may be @c NULL.
 * @param n Maximum number of wide characters to compare.
 *
 * @retval 0 The compared (case-folded) prefixes are equal (including
 *  when @a n is 0, or @c NULL vs @c NULL / empty).
 * @retval &lt;0 The @a str1 prefix is less than the @a str2 prefix (or
 *  @a str1 is @c NULL and @a str2 is non-empty).
 * @retval &gt;0 The @a str1 prefix is greater than the @a str2 prefix
 *  (or @a str2 is @c NULL and @a str1 is non-empty).
 */
int
xTests_wcsnicmp_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
) STLSOFT_NOEXCEPT;

/** Finds the first occurrence of a multibyte substring, tolerating
 * @c NULL.
 *
 * Search order:
 *
 * - if @a str1 (haystack) is @c NULL, returns @c NULL;
 * - if @a str2 (needle) is @c NULL, returns @a str1;
 * - otherwise searches via <code>stlsoft_C_strnstrn</code> with the
 *   NUL-terminated lengths of both arguments;
 *
 * @param str1 Haystack string; may be @c NULL.
 * @param str2 Needle string; may be @c NULL.
 *
 * @return Pointer into @a str1 at the first match, or @c NULL if there
 *  is no match / @a str1 is @c NULL. When @a str2 is @c NULL, returns
 *  @a str1 (which may itself be @c NULL only if @a str1 was @c NULL,
 *  already handled above).
 *
 * @note A @c NULL needle is treated like an empty needle in the sense
 *  that the search "succeeds" at the start of a non-@c NULL haystack.
 *  This differs from CRT @c strstr, which does not accept @c NULL.
 */
char const*
xTests_strstr_(
    char const*     str1
,   char const*     str2
) STLSOFT_NOEXCEPT;

/** Finds the first occurrence of a wide substring, tolerating @c NULL.
 *
 * Wide-character counterpart of xTests_strstr_(), implemented in terms
 * of <code>stlsoft_C_wcsnstrn</code> when both arguments are non-@c NULL.
 *
 * @param str1 Haystack string; may be @c NULL.
 * @param str2 Needle string; may be @c NULL.
 *
 * @return Pointer into @a str1 at the first match, or @c NULL if there
 *  is no match / @a str1 is @c NULL. When @a str2 is @c NULL, returns
 *  @a str1.
 */
wchar_t const*
xTests_wcsstr_(
    wchar_t const*  str1
,   wchar_t const*  str2
) STLSOFT_NOEXCEPT;

/** Finds the first occurrence of a multibyte substring,
 * case-insensitively, tolerating @c NULL.
 *
 * Search order:
 *
 * - if @a str1 (haystack) is @c NULL, returns @c NULL;
 * - if @a str2 (needle) is @c NULL, returns @a str1;
 * - otherwise searches via <code>stlsoft_C_strnistrn</code> with the
 *     NUL-terminated lengths of both arguments;
 *
 * @param str1 Haystack string; may be @c NULL.
 * @param str2 Needle string; may be @c NULL.
 *
 * @return Pointer into @a str1 at the first case-insensitive match, or
 *  @c NULL if there is no match / @a str1 is @c NULL. When @a str2 is
 *  @c NULL, returns @a str1.
 *
 * @note Case folding follows <code>stlsoft_C_strnistrn</code>.
 */
char const*
xTests_stristr_(
    char const*     str1
,   char const*     str2
) STLSOFT_NOEXCEPT;

/** Finds the first occurrence of a wide substring, case-insensitively,
 * tolerating @c NULL.
 *
 * Wide-character counterpart of xTests_stristr_(), implemented in terms
 * of <code>stlsoft_C_wcsnistrn</code> when both arguments are
 * non-@c NULL.
 *
 * @param str1 Haystack string; may be @c NULL.
 * @param str2 Needle string; may be @c NULL.
 *
 * @return Pointer into @a str1 at the first case-insensitive match, or
 *  @c NULL if there is no match / @a str1 is @c NULL. When @a str2 is
 *  @c NULL, returns @a str1.
 *
 * @note Case folding follows <code>stlsoft_C_wcsnistrn</code>.
 */
wchar_t const*
xTests_wcsistr_(
    wchar_t const*  str1
,   wchar_t const*  str2
) STLSOFT_NOEXCEPT;


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

