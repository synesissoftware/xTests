/* /////////////////////////////////////////////////////////////////////////
 * File:    xtests/xtests.h (formerly part of Synesis' internal test codebase)
 *
 * Purpose: Main header file for xTests, a simple unit/component-testing
 *          library for C and C++.
 *
 * Created: 20th June 1999
 * Updated: 30th June 2025
 *
 * Home:    https://github.com/synesissoftware/xTests/
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1999-2019, Matthew Wilson and Synesis Software
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


/** \file xtests/xtests.h
 *
 * [C, C++] Simple unit/component-testing library.
 */

#ifndef XTESTS_INCL_XTESTS_H_XTESTS
#define XTESTS_INCL_XTESTS_H_XTESTS

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION
# define XTESTS_VER_XTESTS_H_XTESTS_MAJOR       3
# define XTESTS_VER_XTESTS_H_XTESTS_MINOR       51
# define XTESTS_VER_XTESTS_H_XTESTS_REVISION    9
# define XTESTS_VER_XTESTS_H_XTESTS_EDIT        409
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

/**
 * \def _XTESTS_VER_MAJOR
 *
 * The Major version number of the xTests library
 *
 * \def _XTESTS_VER_MINOR
 *
 * Minor version number of the xTests library
 *
 * \def _XTESTS_VER_PATCH
 *
 * The patch number of the xTests library
 *
 * \def _XTESTS_VER
 *
 * The composite version of the xTests library
 */

#define _XTESTS_VER_MAJOR       0
#define _XTESTS_VER_MINOR       26
#define _XTESTS_VER_PATCH       4
#define _XTESTS_VER_ALPHABETA   0x42

#define _XTESTS_VER \
    (0\
        |   (   _XTESTS_VER_MAJOR       << 24   ) \
        |   (   _XTESTS_VER_MINOR       << 16   ) \
        |   (   _XTESTS_VER_PATCH       <<  8   ) \
        |   (   _XTESTS_VER_ALPHABETA   <<  0   ) \
    )

#define _XTESTS_VER_REVISION    _XTESTS_VER_PATCH


/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

/* STLSoft version */

#if defined(STLSOFT_VER) && \
    STLSOFT_VER >= 0x010c0000

# define XTESTS_STLSOFT_1_12_OR_LATER
#elif _STLSOFT_VER < 0x010b01c2

# error xTests requires version 1.11.1 release candidate 2, or later, of STLSoft; obtain from https://github.com/synesissoftware/
#endif /* _STLSOFT_VER */


/* (No) C++ API */

#ifndef _XTESTS_NO_CPP_API

# if 0
# elif !defined(__cplusplus)

#  define _XTESTS_NO_CPP_API
# elif defined(STLSOFT_COMPILER_IS_WATCOM)

#  define _XTESTS_NO_CPP_API
# endif
#endif /* !_XTESTS_NO_CPP_API */


/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */

#ifdef __cplusplus
# include <platformstl/platformstl.h>
# if defined(PLATFORMSTL_OS_IS_UNIX)
 /* We include threading.h to prevent the definition of _REENTRANT standard
  * headers on some UNIX operating systems from confusing the feature
  * discrimination in UNIXSTL and having it think that we're multithreading
  * when we're not.
  */
#  include <unixstl/synch/util/features.h>
# elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# endif /* PLATFORMSTL_OS_IS_???? */
# ifndef _XTESTS_NO_CPP_API
#  ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
#   include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */
#  ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS
#   include <stlsoft/limits/integral_limits.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS */
#  ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
#   include <stlsoft/meta/is_integral_type.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */
#  ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE
#   include <stlsoft/meta/is_same_type.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE */
#  ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE
#   include <stlsoft/meta/is_signed_type.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE */
#  ifndef STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF
#   include <stlsoft/meta/select_first_type_if.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF */
#  ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
#   include <stlsoft/meta/yesno.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#  if !defined(STLSOFT_MINIMUM_SAS_INCLUDES)
#   ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
#    include <stlsoft/shims/access/string.hpp>
#   endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#   ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW
#    include <stlsoft/string/string_view.hpp>
#   endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW */
#  endif /* STLSOFT_MINIMUM_SAS_INCLUDES */
#  ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_TRAITS
#   include <stlsoft/traits/integral_traits.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_TRAITS */
# endif /* !_XTESTS_NO_CPP_API */
# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)
#  include <new>
#  include <stdexcept>
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
# if defined(STLSOFT_CF_RTTI_SUPPORT)
#  include <typeinfo>
# endif /* STLSOFT_CF_RTTI_SUPPORT */

# include <algorithm>
#endif /* __cplusplus */

#if 0 ||\
    defined(SHWILD_VER) /* shwild is already included */ ||\
    defined(XTESTS_HAS_SHWILD) /* shwild detected in CMake */ ||\
    0

# ifndef XTESTS_USE_SHWILD
#  define XTESTS_USE_SHWILD
# endif /* !XTESTS_USE_SHWILD */
#endif /* SHWILD_VER */

#ifdef XTESTS_USE_SHWILD
# ifndef _XTESTS_NO_CPP_API
#  include <shwild/shwild.hpp>
# endif /* !_XTESTS_NO_CPP_API */
#endif /* XTESTS_USE_SHWILD */

#ifdef __cplusplus
#  ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING
#   include <stlsoft/conversion/sas_to_string.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING */
#endif /* __cplusplus */

#include <stddef.h>
#include <stdio.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(_STLSOFT_NO_NAMESPACE)
# ifndef _XTESTS_NO_NAMESPACE
#  define _XTESTS_NO_NAMESPACE
# endif /* !_XTESTS_NO_NAMESPACE */
#endif /* _STLSOFT_NO_NAMESPACE */

#ifndef _XTESTS_NO_NAMESPACE
namespace xtests
{
namespace c
{
#endif /* !_XTESTS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * features
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

    STLSOFT_INLINE
    int
    xtests_internal_while_0_(void)
    {
        return 0;
    }

# define XTESTS_WHILE_0_CLAUSE()                            XTESTS_NS_C_QUAL(xtests_internal_while_0_)()

 /* XTESTS_NORETURN_ */
# if 0
# elif defined(__cplusplus) &&\
       __cplusplus >= 201703L

#  define XTESTS_NORETURN_                                  [[noreturn]]
# elif 0 || \
       defined(STLSOFT_COMPILER_IS_CLANG) || \
       defined(STLSOFT_COMPILER_IS_GCC) || \
       0

#  define XTESTS_NORETURN_                                  __attribute__((noreturn))
# elif 0 || \
       defined(STLSOFT_COMPILER_IS_MSVC) || \
       0

#  define XTESTS_NORETURN_                                  __declspec(noreturn)
# endif

 /* XTESTS_EXTERN_C */
# ifndef XTESTS_EXTERN_C

#  ifdef __cplusplus

#   define XTESTS_EXTERN_C                                  extern "C"
#  else /* ? __cplusplus */

#   define XTESTS_EXTERN_C                                  extern
#  endif /* __cplusplus */
# endif /* XTESTS_EXTERN_C */

 /* XTESTS_CALL */
# ifndef XTESTS_CALL

#  define XTESTS_CALL(x)                                    XTESTS_EXTERN_C x
# endif /* !XTESTS_CALL */

 /* XTESTS_CALL_NORETURN */
# ifndef XTESTS_CALL_NORETURN
#  ifdef __cplusplus

#   define XTESTS_CALL_NORETURN(x)                          extern "C" XTESTS_NORETURN_ x
#  else /* ? __cplusplus */

#   define XTESTS_CALL_NORETURN(x)                          extern XTESTS_NORETURN_ x
#  endif /* __cplusplus */
# endif /* !XTESTS_CALL */

# ifdef STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT

#  if 0
#  elif 0 || \
        defined(STLSOFT_COMPILER_IS_GCC) || \
        0

#   ifdef __cplusplus

#    define XTESTS_GET_FUNCTION_()                          __FUNCTION__
#   else /* ? __cplusplus */

#    define XTESTS_GET_FUNCTION_()                          __func__
#   endif /* __cplusplus */
#  else

#   define XTESTS_GET_FUNCTION_()                           __FUNCTION__
#  endif
# else /* ? STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT */

#  define XTESTS_GET_FUNCTION_()                            STLSOFT_STATIC_CAST(char const*, 0)
# endif /* STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT */

#define XTESTS_FLF_()                                       __FILE__, __LINE__, XTESTS_GET_FUNCTION_()

/* FALLTHROUGH
 *
 * Options:
 *
 * 1 - C++17 (or later) -> `[[fallthrough]]`;
 * 2 - C++11 (or later) AND GCC -> `[[gnu::fallthrough]]`;
 * 3 - C23 (or later) -> `[[fallthrough]]`;
 * 4 - GCC -> `__attribute__ ((fallthrough))`;
 * 5 - otherwise -> stub statement
 */
# if 0
# elif 1 &&\
       defined(__cplusplus) &&\
       __cplusplus >= 201703L &&\
       1

   /* C++17 (or later) */
#  define XTESTS_FALLTHROUGH_()                             [[fallthrough]]
# elif 1 &&\
       defined(__cplusplus) &&\
       __cplusplus >= 201103L &&\
       (    0 ||\
            defined(STLSOFT_COMPILER_IS_GCC) ||\
            0) &&\
       1

#  define XTESTS_FALLTHROUGH_()                             [[gnu::fallthrough]]
# elif 1 &&\
       defined(__STDC_VERSION__) &&\
       __STDC_VERSION__ >= 202311L &&\
       1

   /* C23 (or later) */
#  define XTESTS_FALLTHROUGH_()                             [[fallthrough]]
# elif 0 || \
       defined(STLSOFT_COMPILER_IS_GCC) ||\
       0

#  define XTESTS_FALLTHROUGH_()                             __attribute__ ((fallthrough))
# else

#  define XTESTS_FALLTHROUGH_()                             do {} while (XTESTS_WHILE_0_CLAUSE())
# endif

# ifndef _XTESTS_NO_NAMESPACE

#  define XTESTS_NS_QUAL(ns, sym)                           ns::sym
# else /* ? _XTESTS_NO_NAMESPACE */

#  define XTESTS_NS_QUAL(ns, sym)                           sym
# endif /* _XTESTS_NO_NAMESPACE */

# define XTESTS_NS_C_QUAL(sym)                              XTESTS_NS_QUAL( ::xtests::c, sym)
# define XTESTS_NS_CPP_QUAL(sym)                            XTESTS_NS_QUAL( ::xtests::cpp, sym)

# if defined(STLSOFT_CF_RTTI_SUPPORT) && \
     (  !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1310)

#  define XTESTS_REPORT_EXCEPTION_(f, l, x)                 XTESTS_NS_C_QUAL(xtests_caseExcepted)((f), (l), typeid(x).name(), x.what())
# else /* ? STLSOFT_CF_RTTI_SUPPORT */

#  define XTESTS_REPORT_EXCEPTION_(f, l, x)                 XTESTS_NS_C_QUAL(xtests_caseExcepted)((f), (l), "<exception-type unknown: rtti not available>", x.what())
# endif /* STLSOFT_CF_RTTI_SUPPORT */


# define XTESTS_REPORT_PREREQ_FAIL_(f, l, fn, m, q)         XTESTS_NS_C_QUAL(xtests_writeFailMessage)((f), (l), (fn), (m), (q))

# define XTESTS_GET_SETUPPARAM_()                           XTESTS_NS_C_QUAL(xtests_getSetupParam)()

# ifdef __cplusplus

#  define XTESTS_TEST_FUNCTION_INVOKE_(fn, param)           XTESTS_NS_CPP_QUAL(test_function_invoker)::invoke(fn, param)
# else /* ? __cplusplus */

#  define XTESTS_TEST_FUNCTION_INVOKE_(fn, param)           (*fn)()
# endif /* __cplusplus */

# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)

#  if defined(STLSOFT_COMPILER_IS_GCC)

    /* GCC 4.2 on Mac has a strange defect whereby the thrown exception
     * doesn't get caught. When placed in a try-catch-throw, it works.
     * Smells like a code generation defect - particularly likely when
     * only some of the FF build configuration variants experience it -
     * and this workaround seems effective.
     */
#   define XTESTS_INVOKE_TEST_CASE_FN_INNER_(fn, param)     do { try { XTESTS_TEST_FUNCTION_INVOKE_(fn, param); } catch (...) { throw; } } while (XTESTS_WHILE_0_CLAUSE())
#  else /* ? compiler */

#   define XTESTS_INVOKE_TEST_CASE_FN_INNER_(fn, param)     XTESTS_TEST_FUNCTION_INVOKE_(fn, param)
#  endif /* compiler */



#  define XTESTS_INVOKE_TEST_CASE_FN_(file, line, fn, name)                             \
                                                                                        \
    do                                                                                  \
    {                                                                                   \
        try                                                                             \
        {                                                                               \
            void* param = XTESTS_GET_SETUPPARAM_();                                     \
                                                                                        \
            XTESTS_INVOKE_TEST_CASE_FN_INNER_(fn, param);                               \
        }                                                                               \
        catch (XTESTS_NS_CPP_QUAL(prerequisite_failed_exception)& x)                    \
        {                                                                               \
            XTESTS_REPORT_PREREQ_FAIL_((file), (line), XTESTS_GET_FUNCTION_(), "test prerequisite failed", x.what());   \
        }                                                                               \
        catch (XTESTS_NS_CPP_QUAL(requirement_failed_exception)& /* x */)               \
        {                                                                               \
        }                                                                               \
        catch (std::bad_alloc& x)                                                       \
        {                                                                               \
            XTESTS_REPORT_EXCEPTION_((file), (line), x);                                \
                                                                                        \
            throw;                                                                      \
        }                                                                               \
        catch (std::exception& x)                                                       \
        {                                                                               \
            XTESTS_REPORT_EXCEPTION_((file), (line), x);                                \
        }                                                                               \
    } while (XTESTS_WHILE_0_CLAUSE())

#  define XTESTS_INVOKE_TEST_CASE_FN_THROWS_(file, line, fn, name, type)                \
                                                                                        \
    do                                                                                  \
    {                                                                                   \
        try                                                                             \
        {                                                                               \
            void* param = XTESTS_GET_SETUPPARAM_();                                     \
                                                                                        \
            XTESTS_INVOKE_TEST_CASE_FN_INNER_(fn, param);                               \
                                                                                        \
            XTESTS_NS_C_QUAL(xtests_caseExceptionExpected)((file), (line), #type);      \
        }                                                                               \
        catch (XTESTS_NS_CPP_QUAL(prerequisite_failed_exception)& x)                    \
        {                                                                               \
            XTESTS_REPORT_PREREQ_FAIL_((file), (line), XTESTS_GET_FUNCTION_(), "test prerequisite failed", x.what());   \
        }                                                                               \
        catch (XTESTS_NS_CPP_QUAL(requirement_failed_exception)& /* x */)               \
        {                                                                               \
        }                                                                               \
        catch (type& /* x */)                                                           \
        {                                                                               \
            XTESTS_TEST_PASSED();                                                       \
        }                                                                               \
        catch (std::bad_alloc& x)                                                       \
        {                                                                               \
            XTESTS_REPORT_EXCEPTION_((file), (line), x);                                \
                                                                                        \
            throw;                                                                      \
        }                                                                               \
        catch (std::exception& x)                                                       \
        {                                                                               \
            XTESTS_REPORT_EXCEPTION_((file), (line), x);                                \
        }                                                                               \
    } while (XTESTS_WHILE_0_CLAUSE())


#  define XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC_(file, line, name, desc, fn, type) \
                                                                                        \
    do                                                                                  \
    {                                                                                   \
        if (XTESTS_CASE_BEGIN(name, desc))                                              \
        {                                                                               \
            XTESTS_INVOKE_TEST_CASE_FN_THROWS_((file), (line), fn, name, type);         \
                                                                                        \
            XTESTS_CASE_END(name);                                                      \
        }                                                                               \
                                                                                        \
    } while (XTESTS_WHILE_0_CLAUSE())
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

#  define XTESTS_INVOKE_TEST_CASE_FN_(file, line, fn, name)  (*fn)()
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


# define XTESTS_RUN_CASE_WITH_NAME_AND_DESC_(file, line, name, desc, fn)                \
                                                                                        \
    do                                                                                  \
    {                                                                                   \
        if (XTESTS_CASE_BEGIN(name, desc))                                              \
        {                                                                               \
            XTESTS_INVOKE_TEST_CASE_FN_((file), (line), fn, name);                      \
                                                                                        \
            XTESTS_CASE_END(name);                                                      \
        }                                                                               \
                                                                                        \
    } while (XTESTS_WHILE_0_CLAUSE())



# if defined(STLSOFT_COMPILER_IS_DMC)

#  define XTESTS_INVOKE_c_str_data_a_(x)                    STLSOFT_NS_QUAL(c_str_data_a)(x)
#  define XTESTS_INVOKE_c_str_data_w_(x)                    STLSOFT_NS_QUAL(c_str_data_w)(x)
#  define XTESTS_INVOKE_c_str_len_a_(x)                     STLSOFT_NS_QUAL(c_str_len_a)(x)
#  define XTESTS_INVOKE_c_str_len_w_(x)                     STLSOFT_NS_QUAL(c_str_len_w)(x)
#  define XTESTS_INVOKE_c_str_ptr_a_(x)                     STLSOFT_NS_QUAL(c_str_ptr_a)(x)
#  define XTESTS_INVOKE_c_str_ptr_w_(x)                     STLSOFT_NS_QUAL(c_str_ptr_w)(x)
# elif defined(STLSOFT_COMPILER_IS_GCC)

#  define XTESTS_INVOKE_c_str_data_a_(x)                    c_str_data_a(x)
#  define XTESTS_INVOKE_c_str_data_w_(x)                    c_str_data_w(x)
#  define XTESTS_INVOKE_c_str_len_a_(x)                     c_str_len_a(x)
#  define XTESTS_INVOKE_c_str_len_w_(x)                     c_str_len_w(x)
#  define XTESTS_INVOKE_c_str_ptr_a_(x)                     c_str_ptr_a(x)
#  define XTESTS_INVOKE_c_str_ptr_w_(x)                     c_str_ptr_w(x)
# else /* ? compiler */

#  define XTESTS_INVOKE_c_str_data_a_(x)                    c_str_data_a(x)
#  define XTESTS_INVOKE_c_str_data_w_(x)                    c_str_data_w(x)
#  define XTESTS_INVOKE_c_str_len_a_(x)                     c_str_len_a(x)
#  define XTESTS_INVOKE_c_str_len_w_(x)                     c_str_len_w(x)
#  define XTESTS_INVOKE_c_str_ptr_a_(x)                     c_str_ptr_a(x)
#  define XTESTS_INVOKE_c_str_ptr_w_(x)                     c_str_ptr_w(x)
# endif /* compiler */

# define XTESTS_GET_EXPECTED_SLICE_MB_(expected)            STLSOFT_NS_QUAL(c_str_len_a)(expected), STLSOFT_NS_QUAL(c_str_data_a)(expected)
# define XTESTS_GET_EXPECTED_SLICE_WIDE_(expected)          STLSOFT_NS_QUAL(c_str_len_w)(expected), STLSOFT_NS_QUAL(c_str_data_w)(expected)

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     (   _MSC_VER >= 1500 || \
         (   _MSC_VER >= 1400 && \
             defined(_MSC_FULL_VER) && \
             _MSC_FULL_VER >= 140050320))

#  define XTESTS_DECLARE_DEPRECATION(symtype, oldfn, newfn) __declspec(deprecated("The " symtype " " STLSOFT_STRINGIZE(oldfn) " is deprecated and will be removed from a future version of xTests; use " STLSOFT_STRINGIZE(newfn) " instead"))
#  define XTESTS_CALL_DEPRECATED(rt, oldfn, newfn)          XTESTS_DECLARE_DEPRECATION("function", oldfn, newfn) XTESTS_CALL(rt)
# else /* ? compiler */

#  define XTESTS_DECLARE_DEPRECATION(symtype, oldfn, newfn)
#  define XTESTS_CALL_DEPRECATED(rt, oldfn, newfn)          XTESTS_CALL(rt)
# endif /* compiler */


 /* function pointer casts */
# define XTESTS_VOID_FUNCTION_CAST_(f)                      STLSOFT_C_CAST(  void(*)(void),    f  )
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * constants & definitions
 */

/** Flags to be passed to xtests_startRunner
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * \see XTESTS_START_RUNNER_WITH_FLAGS()
 * \see XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM()
 * \see XTESTS_START_RUNNER_WITH_REPORTER_AND_FLAGS()
 * \see XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS()
 * \see XTESTS_START_RUNNER_WITH_SETUP_FNS()
 * \see XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS()
 */
enum xtests_runner_flags_t
{
        xtestsRunnerFlagsNoWindowsDebugString   =   0x0001
    ,   xtestsReportOnlyNonEmptyCases           =   0x0002
};
#ifndef __cplusplus
typedef enum xtests_runner_flags_t                          xtests_runner_flags_t;
#endif /* !__cplusplus */

/** \def XTESTS_FP_APPROXIMATE_FACTOR
 *
 * \ingroup group__xtests__misc
 *
 * The factor within which floating point numbers are deemed to be
 * approximately equal.
 */
#define XTESTS_FP_APPROXIMATE_FACTOR                        (1.000001)


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \defgroup group__xtests__test_runner_functions Test Runner Functions
 *
 * Functions that are used to define, start, report on, and complete test
 * runners.
 */

/** \defgroup group__xtests__test_case_functions Test Case Functions
 *
 * Functions that are used to define, start, and complete test cases.
 */

/** \defgroup group__xtests__test_assertion_functions Test Assertion Functions
 *
 * Functions that are used to exercise tests.
 */

/** \defgroup group__xtests__utiliy_functions Utility Functions
 *
 * Utility functions that supplement use of the library.
 */

/** \defgroup group__xtests__misc Miscellaneous Constructs
 *
 * Miscellaneous constructs that support the use of the public interface of
 * the library.
 */


/* ///////////////////////////////////////////////////////////////////
 * test runner functions
 */

/** \def XTESTS_START_RUNNER(name, verbosity)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Starts a test runner that will report to stdout
 *
 * A test runner is a logically-related group of test cases.
 *
 * \param name The name of the test-runner
 * \param verbosity The verbosity (see xtests_verbosity_t) at which the
 *   runner will be executed
 */
#define XTESTS_START_RUNNER(name, verbosity)                \
    (0 == XTESTS_NS_C_QUAL(xtests_startRunner)((name), (verbosity), NULL, NULL, NULL, 0, NULL, NULL, NULL))

/** \def XTESTS_START_RUNNER_WITH_SETUP_FNS(name, verbosity, setup, teardown, setupParam)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Starts a test runner that will report to stdout
 *
 * A test runner is a logically-related group of test cases.
 *
 * \param name The name of the test-runner
 * \param verbosity The verbosity (see xtests_verbosity_t) at which the
 *   runner will be executed
 * \param setup The function to be called before each test
 * \param teardown The function to be called after each test
 * \param setupParam A caller-supplied parameter that is passed with
 *   each invocation of the setup and teardown functions
 *
 * \see xTests_Setup_t
 * \see xTests_Teardown_t
 */
#define XTESTS_START_RUNNER_WITH_SETUP_FNS(name, verbosity, setup, teardown, setupParam)    \
    (0 == XTESTS_NS_C_QUAL(xtests_startRunner)((name), (verbosity), NULL, NULL, NULL, 0, (setup), (teardown), (setupParam)))

/** \def XTESTS_START_RUNNER_WITH_STREAM(name, verbosity, stm)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Starts a test runner
 *
 * A test runner is a logically-related group of test cases.
 *
 * \param name The name of the test-runner
 * \param verbosity The verbosity (see xtests_verbosity_t) at which the
 *   runner will be executed
 * \param stm The stream to which output will be written
 */
#define XTESTS_START_RUNNER_WITH_STREAM(name, verbosity, stm)                       \
    (0 == XTESTS_NS_C_QUAL(xtests_startRunner)((name), (verbosity), NULL, NULL, stm, 0, NULL, NULL, NULL))

/** \def XTESTS_START_RUNNER_WITH_REPORTER(name, verbosity, reporter, reporterParam)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Starts a test runner with the given callback reporter
 *
 * A test runner is a logically-related group of test cases.
 *
 * \param name The name of the test-runner
 * \param verbosity The verbosity (see xtests_verbosity_t) at which the
 *   runner will be executed
 * \param reporter The reporter instance
 * \param reporterParam A caller-supplied parameter that is passed with
 *   every callback
 */
#define XTESTS_START_RUNNER_WITH_REPORTER(name, verbosity, reporter, reporterParam) \
    (0 == XTESTS_NS_C_QUAL(xtests_startRunner)((name), (verbosity), (reporter), (reporterParam), NULL, 0, NULL, NULL, NULL))

/** \def XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM(name, verbosity, reporter, reporterParam, stm)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Starts a test runner with the given callback reporter
 *
 * A test runner is a logically-related group of test cases.
 *
 * \param name The name of the test-runner
 * \param verbosity The verbosity (see xtests_verbosity_t) at which the
 *   runner will be executed
 * \param reporter The reporter instance
 * \param reporterParam A caller-supplied parameter that is passed with
 *   every callback
 * \param stm The stream to which output will be written
 */
#define XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM(name, verbosity, reporter, reporterParam, stm) \
    (0 == XTESTS_NS_C_QUAL(xtests_startRunner)((name), (verbosity), (reporter), (reporterParam), stm, 0, NULL, NULL, NULL))

/** \def XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS(name, verbosity, reporter, reporterParam, stm, flags)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Starts a test runner with the given callback reporter
 *
 * A test runner is a logically-related group of test cases.
 *
 * \param name The name of the test-runner
 * \param verbosity The verbosity (see xtests_verbosity_t) at which the
 *   runner will be executed
 * \param reporter The reporter instance
 * \param reporterParam A caller-supplied parameter that is passed with
 *   every callback
 * \param stm The stream to which output will be written
 * \param flags The \link xtests::c::xtests_runner_flags_t flags\endlink
 *   that moderate the runner behaviour
 */
#define XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS(name, verbosity, reporter, reporterParam, stm, flags)    \
    (0 == XTESTS_NS_C_QUAL(xtests_startRunner)((name), (verbosity), (reporter), (reporterParam), (stm), (flags), NULL, NULL, NULL))

/** \def XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(name, verbosity, reporter, reporterParam, stm, flags, setup, teardown, setupParam)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Starts a test runner with the given callback reporter
 *
 * A test runner is a logically-related group of test cases.
 *
 * \param name The name of the test-runner
 * \param verbosity The verbosity (see xtests_verbosity_t) at which the
 *   runner will be executed
 * \param reporter The reporter instance
 * \param reporterParam A caller-supplied parameter that is passed with
 *   every invocation of the reporter
 * \param stm The stream to which output will be written
 * \param flags The \link xtests::c::xtests_runner_flags_t flags\endlink
 *   that moderate the runner behaviour
 * \param setup The function to be called before each test
 * \param teardown The function to be called after each test
 * \param setupParam A caller-supplied parameter that is passed with
 *   each invocation of the setup and teardown functions
 */
#define XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(name, verbosity, reporter, reporterParam, stm, flags, setup, teardown, setupParam) \
    (0 == XTESTS_NS_C_QUAL(xtests_startRunner)((name), (verbosity), (reporter), (reporterParam), (stm), (flags), (setup), (teardown), (setupParam)))

/** \def XTESTS_START_RUNNER_WITH_FLAGS(name, verbosity, flags)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Starts a test runner that will report to stdout
 *
 * A test runner is a logically-related group of test cases.
 *
 * \param name The name of the test-runner
 * \param verbosity The verbosity (see xtests_verbosity_t) at which the
 *   runner will be executed
 * \param flags The \link xtests::c::xtests_runner_flags_t flags\endlink
 *   that moderate the runner behaviour
 */
#define XTESTS_START_RUNNER_WITH_FLAGS(name, verbosity, flags)                          \
    (0 == XTESTS_NS_C_QUAL(xtests_startRunner)((name), (verbosity), NULL, NULL, NULL, (flags), NULL, NULL, NULL))

/** \def XTESTS_PRINT_RESULTS()
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Prints the test results of the currently executing test.
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_START_RUNNER() or XTESTS_START_RUNNER_WITH_REPORTER(), and
 *   before invocation of XTESTS_END_RUNNER() or
 *   XTESTS_END_RUNNER_UPDATE_EXITCODE().
 */
#define XTESTS_PRINT_RESULTS()                              \
    XTESTS_NS_C_QUAL(xtests_printRunnerResults)()

/** \def XTESTS_END_RUNNER()
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Ends a test runner
 */
#define XTESTS_END_RUNNER()                                 \
    XTESTS_NS_C_QUAL(xtests_endRunner)(NULL)

/** \def XTESTS_ABEND(terminationMessage)
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Carries out abnormal end of tests, and process termination
 *
 * \param terminationMessage Message to be emitted upon termination
 */
#define XTESTS_ABEND(terminationMessage)                    \
    XTESTS_NS_C_QUAL(xtests_abend)(terminationMessage)

/** \def XTESTS_END_RUNNER_UPDATE_EXITCODE()
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Ends a test runner, and modifies a caller-supplied exit code parameter
 *
 * \param retCode A pointer to a variable of type <code>int</code> that will
 *   receive an exit code.
 *
 * \remarks The variable should have been initialised to
 *   <code>EXIT_SUCCESS</code>, and each invocation of
 *   XTESTS_END_RUNNER_UPDATE_EXITCODE() (for each separate test-runner
 *   in a given application) will only set it to <code>EXIT_FAILURE</code>
 *   in the case where that runner has failed one or more tests.
 */
#define XTESTS_END_RUNNER_UPDATE_EXITCODE(retCode)          \
    STLSOFT_STATIC_CAST(void, XTESTS_NS_C_QUAL(xtests_endRunner)(retCode))


/* ///////////////////////////////////////////////////////////////////
 * test case functions
 */

/** \def XTESTS_CASE_BEGIN(name, desc)
 *
 * \ingroup group__xtests__test_case_functions
 *
 * Begins a test case, of the given name and description
 *
 * \param name The name of the test case
 * \param desc The description of the test case. May be <code>NULL</code>
 *   or the empty string (<code>""</code>).
 */
#define XTESTS_CASE_BEGIN(name, desc)                       \
    (0 == XTESTS_NS_C_QUAL(xtests_beginTestCase)((name), (desc)))

/** \def XTESTS_CASE_END(name, desc)
 *
 * \ingroup group__xtests__test_case_functions
 *
 * Ends the current test case
 *
 * \param name The name of the test case
 *
 * \note The <code>name</code> parameter is ignored in the current
 *   implementation, which can only run one test case at a time.
 */
#define XTESTS_CASE_END(name)                               \
    STLSOFT_STATIC_CAST(void, XTESTS_NS_C_QUAL(xtests_endTestCase)((name)))

/** \def XTESTS_RUN_CASE_WITH_NAME_AND_DESC(name, desc, fn)
 *
 * \ingroup group__xtests__test_case_functions
 *
 * Runs the given test case function, specifying a name and description
 *
 * \param name Name of the test case
 * \param desc Description of the test case
 * \param fn A function, taking no parameters and returning
 *   <code>void</code>, that executes a number of tests representing a test
 *   case.
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_RUN_CASE_WITH_NAME_AND_DESC(name, desc, fn)  \
    XTESTS_RUN_CASE_WITH_NAME_AND_DESC_(__FILE__, __LINE__, name, desc, fn)

/** \def XTESTS_RUN_CASE_WITH_DESC(fn, desc)
 *
 * \ingroup group__xtests__test_case_functions
 *
 * Runs the given test case function, specifying a description
 *
 * \param fn A function, taking no parameters and returning
 *   <code>void</code>, that executes a number of tests representing a test
 *   case.
 * \param desc Description of the test case
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_RUN_CASE_WITH_DESC(fn, desc)                 \
    XTESTS_RUN_CASE_WITH_NAME_AND_DESC_(__FILE__, __LINE__, #fn, desc, fn)

/** \def XTESTS_RUN_CASE(fn)
 *
 * \ingroup group__xtests__test_case_functions
 *
 * Runs the given test case function
 *
 * \param fn A function, taking no parameters and returning
 *   <code>void</code>, that executes a number of tests representing a test
 *   case.
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_RUN_CASE(fn)                                 \
    XTESTS_RUN_CASE_WITH_NAME_AND_DESC_(__FILE__, __LINE__, #fn, "", fn)

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

/** \def XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC(name, desc, fn, type)
 *
 * \ingroup group__xtests__test_case_functions
 *
 * [C++-only] Runs the given test case function, specifying a name and
 * description, and the type of an exception that is expected
 *
 * \param name Name of the test case
 * \param desc Description of the test case
 * \param fn A function, taking no parameters and returning
 *   <code>void</code>, that executes a number of tests representing a test
 *   case.
 * \param type The type of the exception that is expected to be thrown
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC(name, desc, fn, type)   \
    XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC_(__FILE__, __LINE__, name, desc, fn, type)

/** \def XTESTS_RUN_CASE_THAT_THROWS_WITH_DESC(fn, desc, type)
 *
 * \ingroup group__xtests__test_case_functions
 *
 * [C++-only] Runs the given test case function, specifying a description,
 * and the type of an exception that is expected
 *
 * \param fn A function, taking no parameters and returning
 *   <code>void</code>, that executes a number of tests representing a test
 *   case.
 * \param desc Description of the test case
 * \param type The type of the exception that is expected to be thrown
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_RUN_CASE_THAT_THROWS_WITH_DESC(fn, desc, type)  \
    XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC_(__FILE__, __LINE__, #fn, desc, fn, type)

/** \def XTESTS_RUN_CASE_THAT_THROWS(fn, type)
 *
 * \ingroup group__xtests__test_case_functions
 *
 * [C++-only] Runs the given test case function, specifying the type of an
 * exception that is expected
 *
 * \param fn A function, taking no parameters and returning
 *   <code>void</code>, that executes a number of tests representing a test
 *   case.
 * \param type The type of the exception that is expected to be thrown
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_RUN_CASE_THAT_THROWS(fn, type)              \
    XTESTS_RUN_CASE_THAT_THROWS_WITH_NAME_AND_DESC_(__FILE__, __LINE__, #fn, "", fn, type)
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/* ///////////////////////////////////////////////////////////////////
 * test assertion functions
 */

/* /////////////////////////////////////////////////////////
 * directed-result assertions
 */

/** \def XTESTS_TEST_FAIL_WITH_QUALIFIER(msg, qualifier)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Causes a test failure to be expressed, passing an explanatory message and
 * a message qualifier.
 *
 * \param msg The message explaining the failure condition
 * \param qualifier The message qualifier.
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_FAIL_WITH_QUALIFIER(msg, qualifier)                     \
    XTESTS_NS_C_QUAL(xtests_writeFailMessage)(XTESTS_FLF_(), msg, qualifier)

/** \def XTESTS_TEST_FAIL(msg)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Causes a test failure to be expressed, passing an explanatory message.
 *
 * \param msg The message explaining the failure condition
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_FAIL(msg)                                               \
    XTESTS_TEST_FAIL_WITH_QUALIFIER(msg, STLSOFT_STATIC_CAST(char const*, NULL))

/** \def XTESTS_TEST_PASSED()
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Causes a test success to be expressed.
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_PASSED()                                                \
    XTESTS_NS_C_QUAL(xtests_testPassed)(XTESTS_FLF_(), "")

/** \def XTESTS_TEST_WITH_MESSAGE(expr, msg)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Causes a test to be exercised, passing an explanatory message to be used
 * in the case of failure.
 *
 * \param expr The expression whose truth is to be evaluated
 * \param msg The message explaining the failure condition
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WITH_MESSAGE(expr, msg)                                 \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? ((expr)                                                           \
            ? XTESTS_NS_C_QUAL(xtests_testPassed)(XTESTS_FLF_(), msg)       \
            : XTESTS_NS_C_QUAL(xtests_testFailed)(XTESTS_FLF_(), msg))      \
    : (0))

/** \def XTESTS_TEST(expr)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Causes a test to be exercised.
 *
 * \param expr The expression whose truth is to be evaluated
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST(expr)                                                   \
    XTESTS_TEST_WITH_MESSAGE(expr, #expr)


/* /////////////////////////////////////////////////////////
 * test UDTs
 */

/** \def XTESTS_TEST_EQUAL_WITH_MESSAGE(expected, actual, msg)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two user-defined type values are exactly equal, passing an
 * explanatory message to be used in the case of failure..
 *
 * \param expected The expected value
 * \param actual The actual value
 *
 * \remarks The values must be comparable with the equality operator
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_EQUAL_WITH_MESSAGE(expected, actual, msg)               \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? (((expected) == (actual))                                         \
            ? XTESTS_NS_C_QUAL(xtests_testUdtPassed)(XTESTS_FLF_(), #expected " == " #actual, #expected, #actual, XTESTS_NS_C_QUAL(xtestsComparisonEqual), msg)     \
            : XTESTS_NS_C_QUAL(xtests_testUdtFailed)(XTESTS_FLF_(), #expected " == " #actual, #expected, #actual, XTESTS_NS_C_QUAL(xtestsComparisonEqual), msg))    \
    : (0))

/** \def XTESTS_TEST_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two user-defined type values are exactly equal.
 *
 * \param expected The expected value
 * \param actual The actual value
 *
 * \remarks The values must be comparable with the equality operator
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_EQUAL(expected, actual)                                 \
    XTESTS_TEST_EQUAL_WITH_MESSAGE(expected, actual, NULL)

/** \def XTESTS_TEST_NOT_EQUAL_WITH_MESSAGE(expected, actual, msg)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two user-defined type values are not equal, passing an
 * explanatory message to be used in the case of failure..
 *
 * \param expected The expected value
 * \param actual The actual value
 *
 * \remarks The values must be comparable with the equality operator
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_NOT_EQUAL_WITH_MESSAGE(expected, actual, msg)           \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? (((expected) != (actual))                                         \
            ? XTESTS_NS_C_QUAL(xtests_testUdtPassed)(XTESTS_FLF_(), #expected " != " #actual, #expected, #actual, XTESTS_NS_C_QUAL(xtestsComparisonNotEqual), msg)     \
            : XTESTS_NS_C_QUAL(xtests_testUdtFailed)(XTESTS_FLF_(), #expected " != " #actual, #expected, #actual, XTESTS_NS_C_QUAL(xtestsComparisonNotEqual), msg))    \
    : (0))

/** \def XTESTS_TEST_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two user-defined type values are not equal.
 *
 * \param expected The expected value
 * \param actual The actual value
 *
 * \remarks The values must be comparable with the equality operator
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_NOT_EQUAL(expected, actual)                             \
    XTESTS_TEST_NOT_EQUAL_WITH_MESSAGE(expected, actual, NULL)


/* /////////////////////////////////////////////////////////
 * test enumerations
 */

/** \def XTESTS_TEST_ENUM_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two enumerator values are exactly equal.
 *
 * \param expected The expected enumerator value
 * \param actual The actual enumerator value
 *
 * \remarks The enumerators should be of the same type
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_ENUM_EQUAL(expected, actual)                            \
    XTESTS_TEST_INTEGER_EQUAL_EXACT(STLSOFT_STATIC_CAST(int, (expected)), STLSOFT_STATIC_CAST(int, (actual)))

/** \def XTESTS_TEST_ENUM_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two enumerator values are not equal.
 *
 * \param expected The expected enumerator value
 * \param actual The actual enumerator value
 *
 * \remarks The enumerators should be of the same type
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_ENUM_NOT_EQUAL(expected, actual)                        \
    XTESTS_TEST_INTEGER_NOT_EQUAL(STLSOFT_STATIC_CAST(int, (expected)), STLSOFT_STATIC_CAST(int, (actual)))


/* /////////////////////////////////////////////////////////
 * test integers
 */

#ifndef _XTESTS_NO_CPP_API

/** \def XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two integer values are exactly equal.
 *
 * \param expected The expected integer value
 * \param actual The actual integer value
 *
 * \remarks The integers should be of the same type
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual)                  \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual))) \
        : (0))

/** \def XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two integer values are not equal.
 *
 * \param expected The expected integer value
 * \param actual The actual integer value
 *
 * \remarks The integers should be of the same type
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual)                    \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual))) \
        : (0))

/** \def XTESTS_TEST_INTEGER_GREATER(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual integer value is greater than the expected value.
 *
 * \param expected The expected integer value
 * \param actual The actual integer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_GREATER(expected, actual)                      \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonGreaterThan))) \
        : (0))

/** \def XTESTS_TEST_INTEGER_LESS(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual integer value is less than the expected value.
 *
 * \param expected The expected integer value
 * \param actual The actual integer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_LESS(expected, actual)                         \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonLessThan))) \
        : (0))

/** \def XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual integer value is greater than or equal to the
 * expected value.
 *
 * \param expected The expected integer value
 * \param actual The actual integer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual)             \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonGreaterThanOrEqual))) \
        : (0))

/** \def XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual integer value is less than or equal to the expected
 * value.
 *
 * \param expected The expected integer value
 * \param actual The actual integer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)                \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonLessThanOrEqual))) \
        : (0))

/** \def XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(begin, end, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a given integer value matches any of the elements in a
 * given range.
 *
 * \param begin Start iterator of the match range
 * \param end End iterator of the match range
 * \param actual The actual integer value
 *
 * \remarks The value type of the iterators should be the same as the
 *   type of the tested value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(begin, end, actual)         \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer_any_in_range(XTESTS_FLF_(), "XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(" #begin ", " #end ", " #actual ")", (begin), (end), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual))) \
        : (0))

/** \def XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(begin, end, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a given integer value matches none of the elements in a
 * given range.
 *
 * \param begin Start iterator of the match range
 * \param end End iterator of the match range
 * \param actual The actual integer value
 *
 * \remarks The value type of the iterators should be the same as the
 *   type of the tested value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE(begin, end, actual)     \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer_any_in_range(XTESTS_FLF_(), "XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE(" #begin ", " #end ", " #actual ")", (begin), (end), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual))) \
        : (0))

#if 0
/** \def XTESTS_TEST_INTEGER_EQUAL_ANY_OF(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a given integer value matches any of the given expected values.
 *
 * \param expected The expected value(s)
 * \param actual The actual integer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_EQUAL_ANY_OF(expected, actual)                 \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_integer_one_of(                    \
            XTESTS_FLF_()                                                   \
        ,   "XTESTS_TEST_INTEGER_EQUAL_ANY_OF(" #expected ", " #actual ")"  \
        ,   (expected)                                                      \
        ,   (actual)                                                        \
        , XTESTS_NS_C_QUAL(xtestsComparisonEqual)))                         \
        : (0))
#endif /* 0 */

/** \def XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(expected0, expected1, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a given integer value matches one of two given expected values.
 *
 * \param expected0 The first expected value
 * \param expected1 The second expected value
 * \param actual The actual integer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(expected0, expected1, actual)    \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ?  XTESTS_NS_CPP_QUAL(xtests_test_integer_one_of(                   \
            XTESTS_FLF_()                                                   \
        ,   "XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(" #expected0 ", " #expected1 ", " #actual ")"    \
        ,   (actual)                                                        \
        ,   (expected0)                                                     \
        ,   (expected1)                                                     \
        , XTESTS_NS_C_QUAL(xtestsComparisonEqual)))                         \
        : (0))

/** \def XTESTS_TEST_INTEGER_EQUAL_ANY_OF3(expected0, expected1, expected2, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a given integer value matches one of three given expected values.
 *
 * \param expected0 The first expected value
 * \param expected1 The second expected value
 * \param expected2 The third expected value
 * \param actual The actual integer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_INTEGER_EQUAL_ANY_OF3(expected0, expected1, expected2, actual) \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                         \
     ?  XTESTS_NS_CPP_QUAL(xtests_test_integer_one_of(                              \
            XTESTS_FLF_()                                                           \
        ,   "XTESTS_TEST_INTEGER_EQUAL_ANY_OF3(" #expected0 ", " #expected1 ", " #expected2 ", " #actual ")" \
        ,   (actual)                                                                \
        ,   (expected0)                                                             \
        ,   (expected1)                                                             \
        ,   (expected2)                                                             \
        , XTESTS_NS_C_QUAL(xtestsComparisonEqual)))                                 \
        : (0))


/* /////////////////////////////////////////////////////////
 * test booleans
 */

/** \def XTESTS_TEST_BOOLEAN_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two boolean values are exactly equal.
 *
 * \param expected The expected boolean value
 * \param actual The actual boolean value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_BOOLEAN_EQUAL(expected, actual)                        \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_boolean(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual))) \
        : (0))

/** \def XTESTS_TEST_BOOLEAN_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two boolean values are not equal.
 *
 * \param expected The expected boolean value
 * \param actual The actual boolean value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_BOOLEAN_NOT_EQUAL(expected, actual)                    \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_boolean(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual))) \
        : (0))

/** \def XTESTS_TEST_BOOLEAN_TRUE(actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that an expression is true
 *
 * \param actual The boolean expression that is expected to be true
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_BOOLEAN_TRUE(actual)                                   \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_boolean(XTESTS_FLF_(), "", true, (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual))) \
        : (0))

/** \def XTESTS_TEST_BOOLEAN_FALSE(actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that an expression is false
 *
 * \param actual The boolean expression that is expected to be false
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_BOOLEAN_FALSE(actual)                                  \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_boolean(XTESTS_FLF_(), "", false, (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual))) \
        : (0))


/* /////////////////////////////////////////////////////////
 * test characters
 */

/** \def XTESTS_TEST_CHARACTER_EQUAL_EXACT(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two character values are exactly equal.
 *
 * \param expected The expected character value
 * \param actual The actual character value
 *
 * \remarks The characters should be of the same type
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_CHARACTER_EQUAL_EXACT(expected, actual)                \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_character(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual))) \
        : (0))

/** \def XTESTS_TEST_CHARACTER_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two character values are not equal.
 *
 * \param expected The expected character value
 * \param actual The actual character value
 *
 * \remarks The characters should be of the same type
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_CHARACTER_NOT_EQUAL(expected, actual)                  \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_character(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual))) \
        : (0))

/** \def XTESTS_TEST_CHARACTER_GREATER(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual character value is greater than the expected value.
 *
 * \param expected The expected character value
 * \param actual The actual character value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_CHARACTER_GREATER(expected, actual)                    \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_character(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonGreaterThan))) \
        : (0))

/** \def XTESTS_TEST_CHARACTER_LESS(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual character value is less than the expected value.
 *
 * \param expected The expected character value
 * \param actual The actual character value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_CHARACTER_LESS(expected, actual)                       \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_character(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonLessThan))) \
        : (0))

/** \def XTESTS_TEST_CHARACTER_GREATER_OR_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual character value is greater than or equal to the
 * expected value.
 *
 * \param expected The expected character value
 * \param actual The actual character value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_CHARACTER_GREATER_OR_EQUAL(expected, actual)           \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_character(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonGreaterThanOrEqual))) \
        : (0))

/** \def XTESTS_TEST_CHARACTER_LESS_OR_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual character value is less than or equal to the expected
 * value.
 *
 * \param expected The expected character value
 * \param actual The actual character value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_CHARACTER_LESS_OR_EQUAL(expected, actual)              \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_character(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonLessThanOrEqual))) \
        : (0))


/* /////////////////////////////////////////////////////////
 * test floating-points
 */

/** \def XTESTS_TEST_FLOATINGPOINT_EQUAL_EXACT(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two floating point values are exactly equal
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_FLOATINGPOINT_EQUAL_EXACT(expected, actual)            \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_floating_point(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual))) \
        : (0))

/** \def XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_EXACT(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two floating point values are not exactly equal
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_EXACT(expected, actual)        \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_floating_point(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual))) \
        : (0))

/** \def XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two floating point values are approximately
 * equal (as defined by xtests_setFloatingPointCloseFactor()).
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(expected, actual)           \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_floating_point(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxEqual))) \
        : (0))

/** \def XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two floating point values are not approximately
 * equal (as defined by xtests_setFloatingPointCloseFactor()).
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(expected, actual)       \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_floating_point(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxNotEqual))) \
        : (0))

/** \def XTESTS_TEST_FLOATINGPOINT_GREATER(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual floating point value is greater than the expected
 * value.
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_FLOATINGPOINT_GREATER(expected, actual)                 \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_floating_point(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonGreaterThan))) \
        : (0))

/** \def XTESTS_TEST_FLOATINGPOINT_LESS(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual floating point value is less than the expected
 * value.
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_FLOATINGPOINT_LESS(expected, actual)                   \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_floating_point(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonLessThan))) \
        : (0))

/** \def XTESTS_TEST_FLOATINGPOINT_GREATER_OR_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual floating point value is greater than or equal to
 * the expected value.
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_FLOATINGPOINT_GREATER_OR_EQUAL(expected, actual)       \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_floating_point(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonGreaterThanOrEqual))) \
        : (0))

/** \def XTESTS_TEST_FLOATINGPOINT_LESS_OR_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual floating point value is less than or equal to the
 * expected value.
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
# define XTESTS_TEST_FLOATINGPOINT_LESS_OR_EQUAL(expected, actual)          \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_CPP_QUAL(xtests_test_floating_point(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonLessThanOrEqual))) \
        : (0))



/* /////////////////////////////////////////////////////////
 * requiring tests
 *
 * These cause an exception of type XXXXX to be thrown if the condition
 * fails, thereby preventing the execution of any further tests that
 * rely on previously established assertions, which may result in undefined
 * behaviour (and possible program failure).
 */

/** \def XTESTS_REQUIRE(test)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Causes the current test case to exit immediately if the given test
 * fails, without considering any other tests
 *
 * \param test The test that must succeed
 *
 * \note This is only available in C++ compilation units
 */
# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)

#  define XTESTS_REQUIRE(test)                              XTESTS_NS_CPP_QUAL(xtests_require)(!(!(test)))
# else /* STLSOFT_CF_EXCEPTION_SUPPORT */

#  define XTESTS_REQUIRE(test)                              XTESTS_NS_C_QUAL(xtests_require_C)(!(!(test)))
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#else /* ? !_XTESTS_NO_CPP_API */

# if 0 ||\
     defined(STLSOFT_CF__Generic_KEYWORD_SUPPORT) ||\
     (1 &&\
        defined(__STDC__) &&\
        __STDC__==1 &&\
        __STDC_VERSION__ >= 201112L &&\
     1) ||\
     0

#  define xtests_testFailed_llx(expected)                   _Generic(expected, unsigned long long: xtests_testFailed_ulonglong, default: xtests_testFailed_longlong)

#  define XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual)                 \
    (                                                                       \
        XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())               \
            ? xtests_internal_while_0_()                                    \
            : ((expected) == (actual))                                      \
                ? xtests_testPassed(XTESTS_FLF_(), #expected " == " #actual)    \
                : xtests_testFailed_llx((expected))(XTESTS_FLF_(), #expected " == " #actual, expected, actual, xtestsComparisonEqual)   \
    )
#  define XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual)                   \
    (                                                                       \
        XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())               \
            ? xtests_internal_while_0_()                                    \
            : ((expected) != (actual))                                      \
                ? xtests_testPassed(XTESTS_FLF_(), #expected " != " #actual)    \
                : xtests_testFailed_llx((expected))(XTESTS_FLF_(), #expected " != " #actual, expected, actual, xtestsComparisonNotEqual)    \
    )
#  define XTESTS_TEST_INTEGER_GREATER(expected, actual)                     \
    (                                                                       \
        XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())               \
            ? xtests_internal_while_0_()                                    \
            : ((expected) < (actual))                                       \
                ? xtests_testPassed(XTESTS_FLF_(), #expected " < " #actual) \
                : xtests_testFailed_llx((expected))(XTESTS_FLF_(), #expected " < " #actual, expected, actual, xtestsComparisonGreaterThan)   \
    )
#  define XTESTS_TEST_INTEGER_LESS(expected, actual)                        \
    (                                                                       \
        XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())               \
            ? xtests_internal_while_0_()                                    \
            : ((expected) > (actual))                                       \
                ? xtests_testPassed(XTESTS_FLF_(), #expected " > " #actual) \
                : xtests_testFailed_llx((expected))(XTESTS_FLF_(), #expected " > " #actual, expected, actual, xtestsComparisonLessThan) \
    )
#  define XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual)            \
    (                                                                       \
        XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())               \
            ? xtests_internal_while_0_()                                    \
            : ((expected) <= (actual))                                      \
                ? xtests_testPassed(XTESTS_FLF_(), #expected " <= " #actual)    \
                : xtests_testFailed_llx((expected))(XTESTS_FLF_(), #expected " <= " #actual, expected, actual, xtestsComparisonGreaterThanOrEqual)  \
    )
#  define XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)               \
    (                                                                       \
        XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())               \
            ? xtests_internal_while_0_()                                    \
            : ((expected) >= (actual))                                      \
                ? xtests_testPassed(XTESTS_FLF_(), #expected " >= " #actual)    \
                : xtests_testFailed_llx((expected))(XTESTS_FLF_(), #expected " >= " #actual, expected, actual, xtestsComparisonLessThanOrEqual) \
    )
# else

#  define XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual)             XTESTS_TEST_WITH_MESSAGE((expected) == (actual), #expected " == " #actual)
#  define XTESTS_TEST_INTEGER_NOT_EQUAL(expected, actual)               XTESTS_TEST_WITH_MESSAGE((expected) != (actual), #expected " != " #actual)
#  define XTESTS_TEST_INTEGER_GREATER(expected, actual)                 XTESTS_TEST_WITH_MESSAGE((expected) < (actual), #expected " < " #actual)
#  define XTESTS_TEST_INTEGER_LESS(expected, actual)                    XTESTS_TEST_WITH_MESSAGE((expected) > (actual), #expected " > " #actual)
#  define XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(expected, actual)        XTESTS_TEST_WITH_MESSAGE((expected) <= (actual), #expected " <= " #actual)
#  define XTESTS_TEST_INTEGER_LESS_OR_EQUAL(expected, actual)           XTESTS_TEST_WITH_MESSAGE((expected) >= (actual), #expected " >= " #actual)
# endif

# define XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(expected0, expected1, actual)                \
    XTESTS_TEST_WITH_MESSAGE(((expected0) == (actual)) || ((expected1) == (actual)), #actual " should be equal to either of " #expected0 " or " #expected1)
# define XTESTS_TEST_INTEGER_EQUAL_ANY_OF3(expected0, expected1, expected2, actual)     \
    XTESTS_TEST_WITH_MESSAGE(((expected0) == (actual)) || ((expected1) == (actual)) || ((expected2) == (actual)), #actual " should be equal to one of " #expected0 " or " #expected1 " or " #expected2)

# define XTESTS_TEST_BOOLEAN_EQUAL(expected, actual)                    XTESTS_TEST_WITH_MESSAGE((expected) == (actual), #expected " == " #actual)
# define XTESTS_TEST_BOOLEAN_NOT_EQUAL(expected, actual)                XTESTS_TEST_WITH_MESSAGE((expected) != (actual), #expected " != " #actual)
# define XTESTS_TEST_BOOLEAN_TRUE(actual)                               XTESTS_TEST((actual))
# define XTESTS_TEST_BOOLEAN_FALSE(actual)                              XTESTS_TEST(!(actual))

# define XTESTS_TEST_CHARACTER_EQUAL_EXACT(expected, actual)            XTESTS_TEST_WITH_MESSAGE((expected) == (actual), #expected " == " #actual)
# define XTESTS_TEST_CHARACTER_NOT_EQUAL(expected, actual)              XTESTS_TEST_WITH_MESSAGE((expected) != (actual), #expected " != " #actual)
# define XTESTS_TEST_CHARACTER_GREATER(expected, actual)                XTESTS_TEST_WITH_MESSAGE((expected) < (actual), #expected " < " #actual)
# define XTESTS_TEST_CHARACTER_LESS(expected, actual)                   XTESTS_TEST_WITH_MESSAGE((expected) > (actual), #expected " > " #actual)
# define XTESTS_TEST_CHARACTER_GREATER_OR_EQUAL(expected, actual)       XTESTS_TEST_WITH_MESSAGE((expected) <= (actual), #expected " <= " #actual)
# define XTESTS_TEST_CHARACTER_LESS_OR_EQUAL(expected, actual)          XTESTS_TEST_WITH_MESSAGE((expected) >= (actual), #expected " >= " #actual)

# define XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(expected, actual)       XTESTS_TEST(xtests_floatingPointClose((expected), (actual)))
# define XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(expected, actual)   XTESTS_TEST(!xtests_floatingPointClose((expected), (actual)))
#endif /* !_XTESTS_NO_CPP_API */


/* /////////////////////////////////////////////////////////
 * test numeric macros simplified
 */

/** \def XTESTS_TEST_INTEGER_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two integer values (of the same type) are equal.
 *
 * \param expected The expected integer value
 * \param actual The actual integer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_INTEGER_EQUAL(expected, actual)                         \
    XTESTS_TEST_INTEGER_EQUAL_EXACT(expected, actual)

/** \def XTESTS_TEST_FLOATINGPOINT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two floating point values (of the same type) are equal.
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_FLOATINGPOINT_EQUAL(expected, actual)                   \
    XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX(expected, actual)

/** \def XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two floating point values (of the same type) are not equal.
 *
 * \param expected The expected floating point value
 * \param actual The actual floating point value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL(expected, actual)               \
    XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX(expected, actual)


/** \def XTESTS_TEST_CHARACTER_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two character values (of the same type) are equal.
 *
 * \param expected The expected character value
 * \param actual The actual character value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_CHARACTER_EQUAL(expected, actual)                       \
    XTESTS_TEST_CHARACTER_EQUAL_EXACT(expected, actual)



/* /////////////////////////////////////////////////////////
 * test multibyte strings
 */

/** \def XTESTS_TEST_MULTIBYTE_STRING_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (multibyte) strings are equal.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_EQUAL(expected, actual)                \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStrings)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (multibyte) strings are approximately equal (by ignoring
 * case).
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(expected, actual)         \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStrings)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (multibyte) strings are not equal.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(expected, actual)            \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStrings)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (multibyte) strings are not equal (when ignoring
 * case).
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_APPROX(expected, actual)     \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStrings)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxNotEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(expected, actual, n)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (multibyte) strings are equal up to a given limit.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 * \param n The exact number of characters to compare if non-negative; the
 *  (inverse) maximum number of characters to compare if negative;
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(expected, actual, n)           \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStringsN)(XTESTS_FLF_(), "", (expected), (actual), n, XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(expected, actual, n)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (multibyte) strings are approximately equal (by ignoring
 * case), up to a given limit.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 * \param n The exact number of characters to compare if non-negative; the
 *  (inverse) maximum number of characters to compare if negative;
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX(expected, actual, n)    \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStringsN)(XTESTS_FLF_(), "", (expected), (actual), n, XTESTS_NS_C_QUAL(xtestsComparisonApproxEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(expected, actual, n)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (multibyte) strings are not equal.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 * \param n The exact number of characters to compare if non-negative; the
 *  (inverse) maximum number of characters to compare if negative;
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N(expected, actual, n)       \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStringsN)(XTESTS_FLF_(), "", (expected), (actual), n, XTESTS_NS_C_QUAL(xtestsComparisonNotEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (multibyte) strings are not equal (when ignoring
 * case).
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 * \param n The exact number of characters to compare if non-negative; the
 *  (inverse) maximum number of characters to compare if negative;
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)    \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                     \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStringsN)(XTESTS_FLF_(), "", (expected), (actual), n, XTESTS_NS_C_QUAL(xtestsComparisonApproxNotEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the string contains the expected sub-sequence.
 *
 * \param expected The substring to find with the actual string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expected, actual)              \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStringContains)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the string contains the expected sub-sequence (disregarding
 * case).
 *
 * \param expected The substring to find with the actual string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX(expected, actual)       \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStringContains)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the string does not contain the expected sub-sequence.
 *
 * \param expected The substring to find with the actual string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN(expected, actual)          \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStringContains)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the string does not contain the expected sub-sequence
 * (disregarding case).
 *
 * \param expected The substring to find with the actual string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_NOT_CONTAIN_APPROX(expected, actual)   \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testMultibyteStringContains)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxNotEqual)) \
        : (0))

/** \def XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a (multibyte) string slice is the same length
 * and has the same contents as an expected value.
 *
 * \param expected The expected value of the string
 * \param actual The string slice to be evaluated, which is expected to have
 *   the member <code>#len</code> and <code>#ptr</code>
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL(expected, actual)          \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
     ?  XTESTS_NS_C_QUAL(xtests_testMultibyteStringSlice)(XTESTS_FLF_(), "", XTESTS_GET_EXPECTED_SLICE_MB_(expected), (actual).len, (actual).ptr, XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
     : (0))

#ifdef XTESTS_USE_SHWILD

/** \def XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a (multibyte) string matches a given pattern.
 *
 * \param pattern The pattern constraining the expected values of the string
 * \param value The value to be evaluated
 *
 * \note This macro will be defined only given prior inclusion of one of
 *   **shwild**'s headers (**shwild/shwild.h** or **shwild/shwild.hpp**).
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */

/** \def XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH(pattern, value)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a (multibyte) string does not match a given pattern.
 *
 * \param pattern The pattern constraining the expected values of the string
 * \param value The value to be evaluated
 *
 * \note This macro will be defined only given prior inclusion of one of
 *   **shwild**'s headers (**shwild/shwild.h** or **shwild/shwild.hpp**).
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */

# ifndef _XTESTS_NO_CPP_API

#  ifdef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING

#   define XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value)             \
    (                                                                       \
        (0 == shwild::match((pattern), STLSOFT_NS_QUAL(sas_to_string_m)((value)).c_str(), 0))   \
            ?   XTESTS_TEST_PASSED()                                        \
            :   XTESTS_TEST_FAIL_WITH_QUALIFIER(("actual value (given in qualifier) did not match pattern '" + STLSOFT_NS_QUAL(sas_to_string_m)((pattern)) + "'").c_str(), STLSOFT_NS_QUAL(sas_to_string_m)((value)).c_str())   \
    )
#   define XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH(pattern, value)      \
    (                                                                       \
        (0 != shwild::match((pattern), STLSOFT_NS_QUAL(sas_to_string_m)((value)).c_str(), 0))   \
            ?   XTESTS_TEST_PASSED()                                        \
            :   XTESTS_TEST_FAIL_WITH_QUALIFIER(("actual value (given in qualifier) matches unexpectedly the pattern '" + STLSOFT_NS_QUAL(sas_to_string_m)((pattern)) + "'").c_str(), STLSOFT_NS_QUAL(sas_to_string_m)((value)).c_str())   \
    )
#  endif /* STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAS_TO_STRING */
# else /* ? _XTESTS_NO_CPP_API */

#  define XTESTS_TEST_MULTIBYTE_STRING_MATCHES(pattern, value)              \
    (                                                                       \
        (0 == shwild_match((pattern), (value), 0))                          \
            ?   XTESTS_TEST_PASSED()                                        \
            :   XTESTS_TEST_FAIL_WITH_QUALIFIER("actual value (given in qualifier) did not match the pattern", (value))   \
    )
#  define XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH(pattern, value)       \
    (                                                                       \
        (0 != shwild_match((pattern), (value), 0))                          \
            ?   XTESTS_TEST_PASSED()                                        \
            :   XTESTS_TEST_FAIL_WITH_QUALIFIER("actual value (given in qualifier) matches unexpectedly the pattern", (value))   \
    )
# endif /* !_XTESTS_NO_CPP_API */
#endif /* XTESTS_USE_SHWILD */


/* /////////////////////////////////////////////////////////
 * test wide strings
 */

/** \def XTESTS_TEST_WIDE_STRING_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (wide) strings are equal.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_EQUAL(expected, actual)                     \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStrings)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (wide) strings are approximately equal (by ignoring case).
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(expected, actual)              \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStrings)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (wide) strings are not equal.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_NOT_EQUAL(expected, actual)                 \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStrings)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_NOT_EQUAL_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (wide) strings are not equal (when ignoring
 * case).
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_NOT_EQUAL_APPROX(expected, actual)          \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStrings)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxNotEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_EQUAL_N(expected, actual, n)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (wide) strings are equal up to a given limit.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 * \param n The maximum number of characters to compare
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_EQUAL_N(expected, actual, n)                \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringsN)(XTESTS_FLF_(), "", (expected), (actual), n, XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(expected, actual, n)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (wide) strings are approximately equal (by ignoring
 * case), up to a given limit.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 * \param n The maximum number of characters to compare
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX(expected, actual, n)         \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringsN)(XTESTS_FLF_(), "", (expected), (actual), n, XTESTS_NS_C_QUAL(xtestsComparisonApproxEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(expected, actual, n)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (wide) strings are not equal.
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 * \param n The maximum number of characters to compare
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N(expected, actual, n)            \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringsN)(XTESTS_FLF_(), "", (expected), (actual), n, XTESTS_NS_C_QUAL(xtestsComparisonNotEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two (wide) strings are not equal (when ignoring case).
 *
 * \param expected The expected value of the string
 * \param actual The actual value of the string
 * \param n The maximum number of characters to compare
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_NOT_EQUAL_N_APPROX(expected, actual, n)     \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringsN)(XTESTS_FLF_(), "", (expected), (actual), n, XTESTS_NS_C_QUAL(xtestsComparisonApproxNotEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_CONTAIN(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the string contains the expected sub-sequence.
 *
 * \param expected The substring to find with the actual string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_CONTAIN(expected, actual)                   \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringContains)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_CONTAIN_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the string contains the expected sub-sequence (disregarding
 * case).
 *
 * \param expected The substring to find with the actual string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_CONTAIN_APPROX(expected, actual)            \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringContains)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_NOT_CONTAIN(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the string does not contain the expected sub-sequence.
 *
 * \param expected The substring to find with the actual string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_NOT_CONTAIN(expected, actual)               \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringContains)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_NOT_CONTAIN_APPROX(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the string does not contain the expected sub-sequence.
 *
 * \param expected The substring to find with the actual string
 * \param actual The actual value of the string
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_NOT_CONTAIN_APPROX(expected, actual)        \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringContains)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonApproxNotEqual)) \
        : (0))

/** \def XTESTS_TEST_WIDE_STRING_SLICE_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that a (wide) string slice is the same length
 * and has the same contents as an expected value.
 *
 * \param expected The expected value of the string
 * \param actual The string slice to be evaluated
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_WIDE_STRING_SLICE_EQUAL(expected, actual)               \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testWideStringSlice)(XTESTS_FLF_(), "", XTESTS_GET_EXPECTED_SLICE_WIDE_(expected), (actual).len, (actual).ptr, XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))


/* /////////////////////////////////////////////////////////
 * test pointers
 */

/** \def XTESTS_TEST_POINTER_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two pointers are equal.
 *
 * \param expected The expected value of the pointer
 * \param actual The actual value of the pointer
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_POINTER_EQUAL(expected, actual)                         \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testPointers)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))

/** \def XTESTS_TEST_POINTER_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two pointer values are not equal.
 *
 * \param expected The expected pointer value
 * \param actual The actual pointer value
 *
 * \remarks The pointers should be of the same type
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_POINTER_NOT_EQUAL(expected, actual)                     \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testPointers)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual)) \
        : (0))

/** \def XTESTS_TEST_POINTER_GREATER(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual pointer value is greater than the expected value.
 *
 * \param expected The expected pointer value
 * \param actual The actual pointer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_POINTER_GREATER(expected, actual)                       \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testPointers)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonGreaterThan)) \
        : (0))

/** \def XTESTS_TEST_POINTER_LESS(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual pointer value is less than the expected value.
 *
 * \param expected The expected pointer value
 * \param actual The actual pointer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_POINTER_LESS(expected, actual)                          \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testPointers)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonLessThan)) \
        : (0))

/** \def XTESTS_TEST_POINTER_GREATER_OR_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual pointer value is greater than or equal to the
 * expected value.
 *
 * \param expected The expected pointer value
 * \param actual The actual pointer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_POINTER_GREATER_OR_EQUAL(expected, actual)              \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testPointers)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonGreaterThanOrEqual)) \
        : (0))

/** \def XTESTS_TEST_POINTER_LESS_OR_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that the actual pointer value is less than or equal to the expected
 * value.
 *
 * \param expected The expected pointer value
 * \param actual The actual pointer value
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_POINTER_LESS_OR_EQUAL(expected, actual)                 \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testPointers)(XTESTS_FLF_(), "", (expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonLessThanOrEqual)) \
        : (0))


/* /////////////////////////////////////////////////////////
 * test function pointers
 */

/** \def XTESTS_TEST_FUNCTION_POINTER_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two pointers are equal.
 *
 * \param expected The expected value of the pointer
 * \param actual The actual value of the pointer
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_FUNCTION_POINTER_EQUAL(expected, actual)                \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testFunctionPointers)(XTESTS_FLF_(), "", XTESTS_VOID_FUNCTION_CAST_(expected), XTESTS_VOID_FUNCTION_CAST_(actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual)) \
        : (0))

/** \def XTESTS_TEST_FUNCTION_POINTER_NOT_EQUAL(expected, actual)
 *
 * \ingroup group__xtests__test_assertion_functions
 *
 * Tests that two pointer values are not equal.
 *
 * \param expected The expected pointer value
 * \param actual The actual pointer value
 *
 * \remarks The pointers should be of the same type
 *
 * \note This can only be invoked after a successful invocation of
 *   XTESTS_CASE_BEGIN() and before invocation of XTESTS_CASE_END().
 */
#define XTESTS_TEST_FUNCTION_POINTER_NOT_EQUAL(expected, actual)            \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed())                 \
        ? XTESTS_NS_C_QUAL(xtests_testFunctionPointers)(XTESTS_FLF_(), "", XTESTS_VOID_FUNCTION_CAST_(expected), XTESTS_VOID_FUNCTION_CAST_(actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual)) \
        : (0))


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifdef __cplusplus
# ifndef _XTESTS_NO_CPP_API
#  ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

/* c_str_len_n_X(s, n)
 *
 * prevents len-limited strlen() from overstepping
 */

inline
size_t
c_str_len_n_a(
    char const* s
,   size_t      n
)
{
    size_t len = 0;

    for (; len != n && '\0' != *s; ++s, ++len)
    {}

    return len;
}

inline
size_t
c_str_len_n_w(
    wchar_t const* s
,   size_t          n
)
{
    size_t len = 0;

    for (; len != n && '\0' != *s; ++s, ++len)
    {}

    return len;
}

template <typename S>
inline
size_t
c_str_len_n_a(
    S const&    s
,   size_t      n
)
{
    STLSOFT_NS_USING(c_str_len_a);

    size_t len = XTESTS_INVOKE_c_str_len_a_(s);

    return (len < n) ? len : n;
}

template <typename S>
inline
size_t
c_str_len_n_w(
    S const&    s
,   size_t      n
)
{
    STLSOFT_NS_USING(c_str_len_w);

    size_t len = XTESTS_INVOKE_c_str_len_w_(s);

    return (len < n) ? len : n;
}
#  endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */
# endif /* !_XTESTS_NO_CPP_API */
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** The verbosity level to be applied when executing a test runner
 *
 * \ingroup group__xtests__test_runner_functions
 *
 * Verbosity affects the output from an xTests test program. Output comes
 * in the following forms:
 *
 * - a test failure (highly granular)
 * - a test case summary
 * - a test runner summary
 *
 * \see XTESTS_START_RUNNER()
 * \see XTESTS_START_RUNNER_WITH_REPORTER()
 */
enum xtests_verbosity_t
{
        XTESTS_VERBOSITY_SILENT                       =   -1  /*!< There is no output of any kind; status must be indicated by program return code */
    ,   XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR      =   0   /*!< Outputs only a runner summary only on error */
    ,   XTESTS_VERBOSITY_RUNNER_SUMMARY               =   1   /*!< Outputs only a runner summary */
    ,   XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR  =   2   /*!< Outputs a runner summary and the first case summary only on error */
    ,   XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR        =   3   /*!< Outputs a runner summary and a summary for each test case in error */
    ,   XTESTS_VERBOSITY_CASE_SUMMARY                 =   4   /*!< Outputs a runner summary and a summary for each test case */

    ,   XTESTS_VERBOSITY_VERBOSE                      =   9   /*!< Maximum amount of output */
};
#ifndef __cplusplus
typedef enum xtests_verbosity_t                             xtests_verbosity_t;
#endif /* !__cplusplus */


#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

enum xtests_comparison_t
{
    /* NOTE: NEVER CHANGE THE ORDER OF THESE ENUMERATORS !!!!!!!!!!! */

        xtestsComparisonEqual               =   0
    ,   xtestsComparisonNotEqual
    ,   xtestsComparisonGreaterThan
    ,   xtestsComparisonLessThan
    ,   xtestsComparisonGreaterThanOrEqual
    ,   xtestsComparisonLessThanOrEqual
    ,   xtestsComparisonApproxEqual
    ,   xtestsComparisonApproxNotEqual

    /* NOTE: NEVER CHANGE THE ORDER OF THESE ENUMERATORS !!!!!!!!!!! */

    ,   xtestsComparison_max_enumerator

};
# ifndef __cplusplus
typedef enum xtests_comparison_t                            xtests_comparison_t;
# endif /* !__cplusplus */


# ifdef __cplusplus

enum xtests_variable_type_t
{
        xtestsVariableNone                  =   0
    ,   xtestsVariableBoolean               =   1
    ,   xtestsVariableOpaquePointer         =   3
    ,   xtestsVariableMultibyteCharacter    =   5
    ,   xtestsVariableWideCharacter         =   6
    ,   xtestsVariableMultibyteString       =   7
    ,   xtestsVariableWideString            =   8
    ,   xtestsVariableSignedChar            =   11
    ,   xtestsVariableUnsignedChar          =   12
    ,   xtestsVariableShort                 =   13
    ,   xtestsVariableUnsignedShort         =   14
    ,   xtestsVariableInt                   =   15
    ,   xtestsVariableUnsignedInt           =   16
    ,   xtestsVariableLong                  =   17
    ,   xtestsVariableUnsignedLong          =   18
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    ,   xtestsVariableLongLong              =   19
    ,   xtestsVariableUnsignedLongLong      =   20
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    ,   xtestsVariableDouble                =   31
    ,   xtestsVariableUdt                   =   32
};

enum xtests_test_type_t
{
        xtestsTestFullComparison            =   0
    ,   xtestsTestPartialComparison         =   1
    ,   xtestsTestContainment               =   2
};

union xtests_variable_value_t
{
    int                             booleanValue;
    int                             intValue;
    unsigned int                    uintValue;
    long                            longValue;
    unsigned long                   ulongValue;
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    STLSOFT_NS_QUAL(ss_sint64_t)    longlongValue;
    STLSOFT_NS_QUAL(ss_uint64_t)    ulonglongValue;
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    char                            multibyteCharacterValue;
    wchar_t                         wideCharacterValue;
    char const*                     multibyteStringValue;
    wchar_t const*                  wideStringValue;
    double                          doubleValue;
    void const volatile*            opaquePointerValue;

    explicit xtests_variable_value_t(bool b);
    explicit xtests_variable_value_t(char ch);
    explicit xtests_variable_value_t(wchar_t ch, xtests_variable_type_t type /* = xtestsVariableMultibyteCharacter */);
    explicit xtests_variable_value_t(signed   int i);
    explicit xtests_variable_value_t(unsigned int i);
    explicit xtests_variable_value_t(signed   long i);
    explicit xtests_variable_value_t(unsigned long i);
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    explicit xtests_variable_value_t(STLSOFT_NS_QUAL(ss_sint64_t) const& i);
    explicit xtests_variable_value_t(STLSOFT_NS_QUAL(ss_uint64_t) const& i);
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    explicit xtests_variable_value_t(char const* s);
    explicit xtests_variable_value_t(wchar_t const* s);
    explicit xtests_variable_value_t(char const* s, size_t n);
    explicit xtests_variable_value_t(wchar_t const* s, size_t n);
    explicit xtests_variable_value_t(double const& d);
    explicit xtests_variable_value_t(void const volatile* pv);
};

struct xtests_variable_t
{
    xtests_variable_type_t  variableType;
    xtests_test_type_t      testType;
    xtests_variable_value_t value;
    size_t                  valueLen;

public:
    explicit xtests_variable_t(char ch);
    explicit xtests_variable_t(wchar_t ch, xtests_variable_type_t type /* = xtestsVariableMultibyteCharacter */);
    explicit xtests_variable_t(bool b);
    explicit xtests_variable_t(int b, xtests_variable_type_t type /* = xtestsVariableBoolean */);
    explicit xtests_variable_t(signed   char i);
    explicit xtests_variable_t(unsigned char i);
    explicit xtests_variable_t(signed   short i);
    explicit xtests_variable_t(unsigned short i);
    explicit xtests_variable_t(signed   int i);
    explicit xtests_variable_t(unsigned int i);
    explicit xtests_variable_t(signed   long i);
    explicit xtests_variable_t(unsigned long i);
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    explicit xtests_variable_t(STLSOFT_NS_QUAL(ss_sint64_t) const& i);
    explicit xtests_variable_t(STLSOFT_NS_QUAL(ss_uint64_t) const& i);
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    explicit xtests_variable_t(char const* s, size_t n, xtests_test_type_t testType = xtestsTestFullComparison);
    explicit xtests_variable_t(wchar_t const* s, size_t n, xtests_test_type_t testType = xtestsTestFullComparison);
    explicit xtests_variable_t(char const* s, xtests_test_type_t testType = xtestsTestFullComparison);
    explicit xtests_variable_t(wchar_t const* s, xtests_test_type_t testType = xtestsTestFullComparison);
    explicit xtests_variable_t(double const& d);
    explicit xtests_variable_t(void const volatile* pv);
    explicit xtests_variable_t(char const* s, xtests_variable_type_t type); // UDT
};

/** Summary of results for a single test case, or for all test cases
 * in a test runner
 */
struct xTests_runner_results_t
{
    typedef STLSOFT_NS_QUAL(ss_uint32_t)                    uint32_t;

    char const*     name;
    uint32_t        numCases;
    uint32_t        numTests;
    uint32_t        numFailedCases;
    uint32_t        numFailedTests;
    uint32_t        numMissingExpectedExceptions;
    uint32_t        numUnexpectedExceptions;
};

/** Interface to a type whose instances may be used to report results
 */
struct xTests_Reporter_t
{
protected:
#  if defined(STLSOFT_COMPILER_IS_GCC)
    virtual ~xTests_Reporter_t()
    {}
#  else /* ? compiler */
    ~xTests_Reporter_t()
    {}
private:
    virtual void dummy_dtor()
    {}
#  endif /* compiler */

public: /* Overrides */
    virtual void onStartRunner(void* reporterParam, char const* name, int verbosity) = 0;

      virtual void onBeginTestCase(void* reporterParam, char const* name, char const* desc, int verbosity) = 0;

        virtual void onTestPassed(void* reporterParam, char const* file, int line, char const* function, char const* expr, xtests_comparison_t comparison, int verbosity) = 0;

        virtual void onTestFailed(void* reporterParam, char const* file, int line, char const* function, char const* expr, xtests_variable_t const* expectedValue, xtests_variable_t const* actualValue, ptrdiff_t length, xtests_comparison_t comparison, int verbosity) = 0;

        virtual void onWriteFailMessage(void* reporterParam, char const* file, int line, char const* function, char const* message, char const* qualifyingInformation, int verbosity) = 0;

        virtual void onCaseExcepted(void* reporterParam, char const* file, int line, char const* caseName, char const* exceptionType, char const* exceptionMessage, int verbosity) = 0;

        virtual void onCaseExceptionExpected(void* reporterParam, char const* file, int line, char const* caseName, char const* exceptionType, int verbosity) = 0;

      virtual void onEndTestCase(void* reporterParam, char const* name, xTests_runner_results_t const* results, int verbosity) = 0;

      virtual void onPrintRunnerResults(void* reporterParam, xTests_runner_results_t const* results, int verbosity) = 0;

      virtual void onAbend(void* reporterParam, char const* message, int verbosity) = 0;

      virtual void onDefect(void* reporterParam, char const* message, char const* qualifier, int verbosity) = 0;

    virtual void onEndRunner(void* reporterParam, char const* name, int verbosity) = 0;
};
# else /* ? __cplusplus */
struct xTests_Reporter_t;
typedef struct xTests_Reporter_t                            xTests_Reporter_t;
# endif /* __cplusplus */


#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/** Function that is used to setup the test environment for each test case
 *
 * \param param The caller-supplied parameter passed to xtests_startRunner()
 *   (via XTESTS_START_RUNNER_WITH_SETUP_FNS() or
 *   XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS())
 *
 * \return A value that indicates whether setup was successful
 * \retval 0 Setup was successful
 * \retval !0 Setup failed. In this case, the test case will not be executed.
 */
typedef int (*xTests_Setup_t)(void* param);

/** Function that is used to teardown the test environment for each test
 *   case
 *
 * \param param The caller-supplied parameter passed to xtests_startRunner()
 *   (via XTESTS_START_RUNNER_WITH_SETUP_FNS() or
 *   XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS())
 *
 * \return Ignored in the current version.
 */
typedef int (*xTests_Teardown_t)(void* param);

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

XTESTS_CALL(int)
xtests_startRunner(
    char const*         name
,   int                 verbosity
,   xTests_Reporter_t*  reporter        /* = NULL => reports to console (fprintf); also reports via OutputDebugString() on windows */
,   void*               reporterParam   /* = NULL */
,   FILE*               stm             /* = NULL => stdout */
,   int                 flags           /* = 0 */
,   xTests_Setup_t      setup
,   xTests_Teardown_t   teardown
,   void*               setupParam
);

XTESTS_CALL(int)
xtests_endRunner(int* retCode);

XTESTS_CALL(void)
xtests_printRunnerResults(void);

XTESTS_CALL_NORETURN(void)
xtests_abend(char const* message);

XTESTS_CALL(void*)
xtests_getSetupParam(void);

XTESTS_CALL(int)
xtests_beginTestCase(
    char const* name
,   char const* desc
);

XTESTS_CALL(int)
xtests_endTestCase(char const* name);


XTESTS_CALL(int)
xtests_testPassed(
    char const* file
,   int         line
,   char const* function
,   char const* expr
);

XTESTS_CALL(int)
xtests_testFailed(
    char const* file
,   int         line
,   char const* function
,   char const* expr
);

XTESTS_CALL(int)
xtests_testUdtPassed(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   xtests_comparison_t comp
,   char const*         message     /* = NULL */
);

XTESTS_CALL(int)
xtests_testUdtFailed(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   xtests_comparison_t comp
,   char const*         message     /* = NULL */
);

XTESTS_CALL(int)
xtests_testFailed_int(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   int                 expected
,   int                 actual
,   xtests_comparison_t comp
);

XTESTS_CALL(int)
xtests_testFailed_long(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   long                expected
,   long                actual
,   xtests_comparison_t comp
);
XTESTS_CALL(int)
xtests_testFailed_ulong(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   unsigned long       expected
,   unsigned long       actual
,   xtests_comparison_t comp
);
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
XTESTS_CALL(int)
xtests_testFailed_longlong(
    char const*                     file
,   int                             line
,   char const*                     function
,   char const*                     expr
,   STLSOFT_NS_QUAL(ss_sint64_t)    expected
,   STLSOFT_NS_QUAL(ss_sint64_t)    actual
,   xtests_comparison_t             comp
);
XTESTS_CALL(int)
xtests_testFailed_ulonglong(
    char const*                     file
,   int                             line
,   char const*                     function
,   char const*                     expr
,   STLSOFT_NS_QUAL(ss_uint64_t)    expected
,   STLSOFT_NS_QUAL(ss_uint64_t)    actual
,   xtests_comparison_t             comp
);
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

XTESTS_CALL(int)
xtests_testFailed_boolean(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   int                 expected
,   int                 actual
,   xtests_comparison_t comp
);

XTESTS_CALL(int)
xtests_testFailed_double(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   double              expected
,   double              actual
,   xtests_comparison_t comp
);

XTESTS_CALL(int)
xtests_testMultibyteStrings(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   xtests_comparison_t comp
);

XTESTS_CALL(int)
xtests_testMultibyteStringsN(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   ptrdiff_t           n /* exact if +ve; limit if -ve */
,   xtests_comparison_t comp
);

XTESTS_CALL(int)
xtests_testMultibyteStringsN_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   ptrdiff_t           n /* exact if +ve; limit if -ve */
,   size_t              cchExpected
,   size_t              cchActual
,   xtests_comparison_t comp
);
# ifndef _XTESTS_NO_CPP_API

template<
    typename S
>
inline
void
xtests_abend(S const& message)
{
    STLSOFT_NS_USING(c_str_ptr_a);

    xtests_abend(XTESTS_INVOKE_c_str_ptr_a_(XTESTS_INVOKE_c_str_ptr_a_(message)));
}


template <typename I>
struct xtests_string_len_signed_form;

template <>
struct xtests_string_len_signed_form<signed int>
{
    static long from(signed int i) STLSOFT_NOEXCEPT { return i; }
};

template <>
struct xtests_string_len_signed_form<unsigned int>
{
    static long from(unsigned int i) STLSOFT_NOEXCEPT { return static_cast<long>(i); }
};
#  ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

template <>
struct xtests_string_len_signed_form< STLSOFT_NS_QUAL(ss_sint32_t)>
{
    static long from(STLSOFT_NS_QUAL(ss_sint32_t) i) STLSOFT_NOEXCEPT { return i; }
};
template <>
struct xtests_string_len_signed_form< STLSOFT_NS_QUAL(ss_uint32_t)>
{
    static long from(STLSOFT_NS_QUAL(ss_uint32_t) i) STLSOFT_NOEXCEPT { return static_cast<long>(i); }
};
#  endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

template <>
struct xtests_string_len_signed_form<signed char>
{
    static long from(signed char i) STLSOFT_NOEXCEPT { return i; }
};

template <>
struct xtests_string_len_signed_form<unsigned char>
{
    static long from(unsigned char i) STLSOFT_NOEXCEPT { return static_cast<long>(i); }
};

template <>
struct xtests_string_len_signed_form<signed short>
{
    static long from(signed short i) STLSOFT_NOEXCEPT { return i; }
};

template <>
struct xtests_string_len_signed_form<unsigned short>
{
    static long from(unsigned short i) STLSOFT_NOEXCEPT { return static_cast<long>(i); }
};
#  ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE

template <>
struct xtests_string_len_signed_form< STLSOFT_NS_QUAL(ss_sint16_t)>
{
    static long from(STLSOFT_NS_QUAL(ss_sint16_t) i) STLSOFT_NOEXCEPT { return i; }
};
template <>
struct xtests_string_len_signed_form< STLSOFT_NS_QUAL(ss_uint16_t)>
{
    static long from(STLSOFT_NS_QUAL(ss_uint16_t) i) STLSOFT_NOEXCEPT { return static_cast<long>(i); }
};
#  endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */

template <>
struct xtests_string_len_signed_form<signed long>
{
    static long from(long i) STLSOFT_NOEXCEPT { return i; }
};

template <>
struct xtests_string_len_signed_form<unsigned long>
{
    static long from(unsigned long i) STLSOFT_NOEXCEPT { return static_cast<long>(i); }
};
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT

template <>
struct xtests_string_len_signed_form< STLSOFT_NS_QUAL(ss_sint64_t)>
{
    static STLSOFT_NS_QUAL(ss_sint64_t) from(STLSOFT_NS_QUAL(ss_sint64_t) i) STLSOFT_NOEXCEPT { return i; }
};

template <>
struct xtests_string_len_signed_form< STLSOFT_NS_QUAL(ss_uint64_t)>
{
    static STLSOFT_NS_QUAL(ss_sint64_t) from(STLSOFT_NS_QUAL(ss_uint64_t) i) STLSOFT_NOEXCEPT { return static_cast<STLSOFT_NS_QUAL(ss_sint64_t)>(i); }
};
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


template<
    typename S0
,   typename S1
>
inline
int
xtests_testMultibyteStrings(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   S0 const&           expected
,   S1 const&           actual
,   xtests_comparison_t comp
)
{
    return xtests_testMultibyteStrings(
        file, line, function
    ,   expr
    ,   STLSOFT_NS_QUAL(sas_to_string_m)(expected).c_str()
    ,   STLSOFT_NS_QUAL(sas_to_string_m)(actual).c_str()
    ,   comp
    );
}

template<
    typename S0
,   typename S1
,   typename I
>
inline
int
xtests_testMultibyteStringsN_t(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   S0 const&           expected
,   S1 const&           actual
,   I                   n /* exact if +ve; limit if -ve */
,   xtests_comparison_t comp
)
{
    STLSOFT_NS_USING(c_str_data_a);

    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type) < I > ::value);
    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_signed_type) < I > ::value);

    return xtests_testMultibyteStringsN_(
        file
    ,   line
    ,   function
    ,   expr
    ,   XTESTS_INVOKE_c_str_data_a_(expected)
    ,   XTESTS_INVOKE_c_str_data_a_(actual)
    ,   n
    ,   c_str_len_n_a(expected, STLSOFT_STATIC_CAST(size_t, (n < 0) ? -n : n))
    ,   c_str_len_n_a(actual, STLSOFT_STATIC_CAST(size_t, (n < 0) ? -n : n))
    ,   comp
    );
}

template<
    typename S0
,   typename S1
,   typename I
>
inline
int
xtests_testMultibyteStringsN(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   S0 const&           expected
,   S1 const&           actual
,   I                   n /* exact if +ve; limit if -ve */
,   xtests_comparison_t comp
)
{
    STLSOFT_NS_USING(c_str_data_a);

    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type)<I>::value);

    typedef xtests_string_len_signed_form<I>                I_signed_form_t;

    return xtests_testMultibyteStringsN_t(
        file
    ,   line
    ,   function
    ,   expr
    ,   expected
    ,   actual
    ,   I_signed_form_t::from(n)
    ,   comp
    );
}
# endif /* !_XTESTS_NO_CPP_API */

XTESTS_CALL(int)
xtests_testWideStrings(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   xtests_comparison_t comp
);

XTESTS_CALL(int)
xtests_testWideStringsN_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   ptrdiff_t           n /* exact if +ve; limit if -ve */
,   size_t              cchExpected
,   size_t              cchActual
,   xtests_comparison_t comp
);

XTESTS_CALL(int)
xtests_testWideStringsN(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   int                 n /* exact if +ve; limit if -ve */
,   xtests_comparison_t comp
);
# ifndef _XTESTS_NO_CPP_API

template<
    typename S0
,   typename S1
>
inline
int
xtests_testWideStrings(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   S0 const&           expected
,   S1 const&           actual
,   xtests_comparison_t comp
)
{
    return xtests_testWideStrings(
        file, line, function
    ,   expr
    ,   STLSOFT_NS_QUAL(sas_to_string_w)(expected).c_str()
    ,   STLSOFT_NS_QUAL(sas_to_string_w)(actual).c_str()
    ,   comp
    );
}

template<
    typename S0
,   typename S1
,   typename I
>
inline
int
xtests_testWideStringsN_t(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   S0 const&           expected
,   S1 const&           actual
,   I                   n /* exact if +ve; limit if -ve */
,   xtests_comparison_t comp
)
{
    STLSOFT_NS_USING(c_str_data_w);

    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type)<I>::value);

    return xtests_testWideStringsN_(
        file
    ,   line
    ,   function
    ,   expr
    ,   XTESTS_INVOKE_c_str_data_w_(expected)
    ,   XTESTS_INVOKE_c_str_data_w_(actual)
    ,   n
    ,   c_str_len_n_w(expected, STLSOFT_STATIC_CAST(size_t, (n < 0) ? -n : n))
    ,   c_str_len_n_w(actual, STLSOFT_STATIC_CAST(size_t, (n < 0) ? -n : n))
    ,   comp
    );
}

template<
    typename S0
,   typename S1
,   typename I
>
inline
int
xtests_testWideStringsN(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   S0 const&           expected
,   S1 const&           actual
,   I                   n /* exact if +ve; limit if -ve */
,   xtests_comparison_t comp
)
{
    STLSOFT_NS_USING(c_str_data_w);

    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type)<I>::value);

    typedef xtests_string_len_signed_form<I>                I_signed_form_t;

    return xtests_testWideStringsN_t(
        file
    ,   line
    ,   function
    ,   expr
    ,   expected
    ,   actual
    ,   I_signed_form_t::from(n)
    ,   comp
    );
}
# endif /* !_XTESTS_NO_CPP_API */

XTESTS_CALL(int)
xtests_testMultibyteStringContains(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   xtests_comparison_t comp
);
# ifndef _XTESTS_NO_CPP_API

template<
    typename S0
,   typename S1
>
inline
int
xtests_testMultibyteStringContains(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   S0 const&           expected
,   S1 const&           actual
,   xtests_comparison_t comp
)
{
    return xtests_testMultibyteStringContains(
        file, line, function
    ,   expr
    ,   STLSOFT_NS_QUAL(sas_to_string_m)(expected).c_str()
    ,   STLSOFT_NS_QUAL(sas_to_string_m)(actual).c_str()
    ,   comp
    );
}
# endif /* !_XTESTS_NO_CPP_API */

XTESTS_CALL(int)
xtests_testWideStringContains(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   xtests_comparison_t comp
);
# ifndef _XTESTS_NO_CPP_API

template<
    typename S0
,   typename S1
>
inline
int
xtests_testWideStringContains(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   S0 const&           expected
,   S1 const&           actual
,   xtests_comparison_t comp
)
{
    return xtests_testWideStringContains(
        file, line, function
    ,   expr
    ,   STLSOFT_NS_QUAL(sas_to_string_w)(expected).c_str()
    ,   STLSOFT_NS_QUAL(sas_to_string_w)(actual).c_str()
    ,   comp
    );
}
# endif /* !_XTESTS_NO_CPP_API */

XTESTS_CALL(int)
xtests_testMultibyteStringSlice(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   size_t                  expectedLen
,   char const*             expectedPtr
,   size_t                  actualLen
,   char const*             actualPtr
,   xtests_comparison_t     comp
);

XTESTS_CALL(int)
xtests_testWideStringSlice(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   size_t                  expectedLen
,   wchar_t const*          expectedPtr
,   size_t                  actualLen
,   wchar_t const*          actualPtr
,   xtests_comparison_t     comp
);


XTESTS_CALL(int)
xtests_testPointers(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   void volatile const*    expected
,   void volatile const*    actual
,   xtests_comparison_t     comp
);

XTESTS_CALL(int)
xtests_testFunctionPointers(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   void                    (*expected)(void)
,   void                    (*actual)(void)
,   xtests_comparison_t     comp
);

XTESTS_CALL(int)
xtests_testCharactersA(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   char                    expected
,   char                    actual
,   xtests_comparison_t     comp
);
XTESTS_CALL(int)
xtests_testCharactersW(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   wchar_t                 expected
,   wchar_t                 actual
,   xtests_comparison_t     comp
);

XTESTS_CALL(int)
xtests_writeFailMessage(
    char const* file
,   int         line
,   char const* function
,   char const* message
,   char const* qualifyingInformation
);
# ifndef _XTESTS_NO_CPP_API

template<
    typename S0
,   typename S1
>
inline
int
xtests_writeFailMessage(
    char const* file
,   int         line
,   char const* function
,   S0 const&   message
,   S1 const&   qualifyingInformation
)
{
    return xtests_writeFailMessage(
        file
    ,   line
    ,   function
    ,   STLSOFT_NS_QUAL(sas_to_string_m)(message).c_str()
    ,   STLSOFT_NS_QUAL(sas_to_string_m)(qualifyingInformation).c_str()
    );
}
# endif /* !_XTESTS_NO_CPP_API */

XTESTS_CALL(void)
xtests_caseExcepted(
    char const* file
,   int         line
,   char const* exceptionType
,   char const* exceptionMessage
);

XTESTS_CALL(void)
xtests_caseExceptionExpected(
    char const* file
,   int         line
,   char const* exceptionType
);


XTESTS_CALL(int)
xtests_floatingPointClose(
    double expected
,   double actual
);

/** Sets the floating-point number closesness factor, used in
 *   XTESTS_TEST_FLOATINGPOINT_EQUAL_APPROX()
 *
 * \param factor The factor. Must be >= 1.0 and < 2.0
 * \param old Optional pointer to receive the previous value. May be NULL
 *
 * \see XTESTS_FLOATINGPOINT_FACTOR_SCOPE
 */
XTESTS_CALL(double)
xtests_setFloatingPointCloseFactor(
    double  factor
,   double* old /* = NULL */
);
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * C++-only functionality
 */

#ifndef _XTESTS_NO_NAMESPACE
} /* namespace c */
namespace cpp
{
    using ::xtests::c::xtests_comparison_t;

#endif /* !_XTESTS_NO_NAMESPACE */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION
# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)

/* This exception class is used to bring an early end to a test case as a
 * result of a required test failing.
 *
 * NOTE: it is NOT derived from std::exception, because it has
 * to be proof from any catches created by the user.
 */
class requirement_failed_exception
{
};

/* This exception class is used to bring an early end to a test case as a
 * result of a prerequisite failing.
 *
 * NOTE: it is NOT derived from std::exception, because it has
 * to be proof from any catches created by the user
 */
class prerequisite_failed_exception
{
public:
    typedef prerequisite_failed_exception                   class_type;

public:
    explicit
    prerequisite_failed_exception()
    {}
    virtual ~prerequisite_failed_exception() STLSOFT_NOEXCEPT
    {}
private:
    void operator =(class_type const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

public: /* Overrides */
    virtual char const* what() const = 0;
};
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */
#ifndef _XTESTS_NO_CPP_API
# ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

class test_function_invoker
{
public:
#  ifdef STLSOFT_CF_CDECL_SUPPORTED
    static
    void
    invoke(
        void    (STLSOFT_CDECL *pfn)(void)
    ,   void*                /* param */
    )
    {
        (*pfn)();
    }

    static
    void
    invoke(
        void    (STLSOFT_CDECL *pfn)(void* param)
    ,   void*                   param
    )
    {
        (*pfn)(param);
    }
#  endif /* STLSOFT_CF_CDECL_SUPPORTED */
#  ifdef STLSOFT_CF_STDCALL_SUPPORTED

    static
    void
    invoke(
        void  (STLSOFT_STDCALL *pfn)(void)
    ,   void*                /* param */
    )
    {
        (*pfn)();
    }

    static
    void
    invoke(
        void  (STLSOFT_STDCALL *pfn)(void* param)
    ,   void*                   param
    )
    {
        (*pfn)(param);
    }
#  endif /* STLSOFT_CF_STDCALL_SUPPORTED */
};
#  if defined(STLSOFT_CF_EXCEPTION_SUPPORT)

inline
void
xtests_require(int success)
{
    if (!success)
    {
        throw requirement_failed_exception();
    }
}
#  endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
# endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/** Scoping class that sets the floating-point close factor for a
 *   controlled scope
 */
class xtest_floatingpoint_factor_scope
{
public:
    /** Sets the floating point close factor to the given value */
    xtest_floatingpoint_factor_scope(double const& factor)
        : m_original(XTESTS_NS_C_QUAL(xtests_setFloatingPointCloseFactor)(factor, NULL))
    {}
    /** Resets the floating point close factor to the original value */
    ~xtest_floatingpoint_factor_scope() STLSOFT_NOEXCEPT
    {
        XTESTS_NS_C_QUAL(xtests_setFloatingPointCloseFactor)(m_original, NULL);
    }
private:
    xtest_floatingpoint_factor_scope(xtest_floatingpoint_factor_scope const&) STLSOFT_COPY_CONSTRUCTION_PROSCRIBED;
    void operator =(xtest_floatingpoint_factor_scope const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

private:
    const double m_original;
};

/** \def XTESTS_FLOATINGPOINT_FACTOR_SCOPE
 *
 * \ingroup group__xtests__misc
 *
 * [C++ only] Macro used to declare an instance of the
 * class xtests::cpp::xtest_floatingpoint_factor_scope, which causes the
 * floating point factor to be set to a new value for the lifetime of the
 * object, and then returned to its prior value
<pre>
  XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL(5.05, 5.06);

  XTESTS_FLOATINGPOINT_FACTOR_SCOPE factor_scoper(1.1); // highly permissive factor

  XTESTS_TEST_FLOATINGPOINT_EQUAL(5.05, 5.06);
</pre>
 */
# define XTESTS_FLOATINGPOINT_FACTOR_SCOPE                  XTESTS_NS_CPP_QUAL(xtest_floatingpoint_factor_scope)

# ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

template <typename T>
struct xtests_failure_reporter;

template <>
struct xtests_failure_reporter<signed int>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, int expected, int actual, xtests_comparison_t comp)
    {
#  ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_int(file, line, function, expr, expected, actual, comp));
    }
};

template <>
struct xtests_failure_reporter<unsigned int>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, unsigned int expected, unsigned int actual, xtests_comparison_t comp)
    {
#  ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_ulong(file, line, function, expr, static_cast<unsigned long>(expected), static_cast<unsigned long>(actual), comp));
    }
};

template <>
struct xtests_failure_reporter<signed char>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, signed char expected, signed char actual, xtests_comparison_t comp)
    {
        STLSOFT_STATIC_CAST(void, xtests_failure_reporter<signed int>::xtests_report_failure_equal(file, line, function, expr, static_cast<signed int>(expected), static_cast<signed int>(actual), comp));
    }
};

template <>
struct xtests_failure_reporter<unsigned char>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, unsigned char expected, unsigned char actual, xtests_comparison_t comp)
    {
        STLSOFT_STATIC_CAST(void, xtests_failure_reporter<signed int>::xtests_report_failure_equal(file, line, function, expr, static_cast<signed int>(expected), static_cast<signed int>(actual), comp));
    }
};

template <>
struct xtests_failure_reporter<signed short>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, int expected, int actual, xtests_comparison_t comp)
    {
        STLSOFT_STATIC_CAST(void, xtests_failure_reporter<signed int>::xtests_report_failure_equal(file, line, function, expr, static_cast<signed int>(expected), static_cast<signed int>(actual), comp));
    }
};

template <>
struct xtests_failure_reporter<unsigned short>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, int expected, int actual, xtests_comparison_t comp)
    {
        STLSOFT_STATIC_CAST(void, xtests_failure_reporter<signed int>::xtests_report_failure_equal(file, line, function, expr, static_cast<signed int>(expected), static_cast<signed int>(actual), comp));
    }
};
#  ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE

template <>
struct xtests_failure_reporter< STLSOFT_NS_QUAL(ss_sint16_t)>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, STLSOFT_NS_QUAL(ss_sint16_t) expected, STLSOFT_NS_QUAL(ss_sint16_t) actual, xtests_comparison_t comp)
    {
#   ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#   endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_int(file, line, function, expr, static_cast<signed int>(expected), static_cast<signed int>(actual), comp));
    }
};
template <>
struct xtests_failure_reporter< STLSOFT_NS_QUAL(ss_uint16_t)>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, STLSOFT_NS_QUAL(ss_uint16_t) expected, STLSOFT_NS_QUAL(ss_uint16_t) actual, xtests_comparison_t comp)
    {
#   ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#   endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_int(file, line, function, expr, static_cast<signed int>(expected), static_cast<signed int>(actual), comp));
    }
};
#  endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */
#  ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

template <>
struct xtests_failure_reporter< STLSOFT_NS_QUAL(ss_sint32_t)>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, STLSOFT_NS_QUAL(ss_sint32_t) expected, STLSOFT_NS_QUAL(ss_sint32_t) actual, xtests_comparison_t comp)
    {
#   ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#   endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_int(file, line, function, expr, static_cast<signed int>(expected), static_cast<signed int>(actual), comp));
    }
};
template <>
struct xtests_failure_reporter< STLSOFT_NS_QUAL(ss_uint32_t)>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, STLSOFT_NS_QUAL(ss_uint32_t) expected, STLSOFT_NS_QUAL(ss_uint32_t) actual, xtests_comparison_t comp)
    {
#   ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#   endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_int(file, line, function, expr, static_cast<signed int>(expected), static_cast<signed int>(actual), comp));
    }
};
#  endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

template <>
struct xtests_failure_reporter<signed long>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, long expected, long actual, xtests_comparison_t comp)
    {
#  ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_long(file, line, function, expr, expected, actual, comp));
    }
};

template <>
struct xtests_failure_reporter<unsigned long>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, unsigned long expected, unsigned long actual, xtests_comparison_t comp)
    {
#  ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_ulong(file, line, function, expr, expected, actual, comp));
    }
};
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT

template <>
struct xtests_failure_reporter< STLSOFT_NS_QUAL(ss_sint64_t)>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, STLSOFT_NS_QUAL(ss_sint64_t) expected, STLSOFT_NS_QUAL(ss_sint64_t) actual, xtests_comparison_t comp)
    {
#   ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#   endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_longlong(file, line, function, expr, expected, actual, comp));
    }
};

template <>
struct xtests_failure_reporter< STLSOFT_NS_QUAL(ss_uint64_t)>
{
    static void xtests_report_failure_equal(char const* file, int line, char const* function, char const* expr, STLSOFT_NS_QUAL(ss_uint64_t) expected, STLSOFT_NS_QUAL(ss_uint64_t) actual, xtests_comparison_t comp)
    {
#   ifndef _XTESTS_NO_NAMESPACE
        using namespace ::xtests::c;
#   endif /* _XTESTS_NO_NAMESPACE */

        STLSOFT_STATIC_CAST(void, xtests_testFailed_ulonglong(file, line, function, expr, expected, actual, comp));
    }
};
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


template<
    typename T1
,   typename T2
>
struct xtests_integer_failure_reporter_selector
{
private:
    enum { are_types_same       =   (0 != STLSOFT_NS_QUAL(is_same_type)<T1, T2>::value) };
    enum { T1_is_larger_than_T2 =   sizeof(T1) > sizeof(T2)                     };

    typedef typename STLSOFT_NS_QUAL(select_first_type_if)<
        T1
    ,   T2
    ,   T1_is_larger_than_T2
    >::type                                                 larger_type_;

public:
    typedef xtests_failure_reporter<larger_type_>           type;
};

template<
    typename I1
,   typename I2
>
inline
void
xtests_reportFailedIntegerComparison(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type)<I1>::value);
    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type)<I2>::value);

#  if defined(STLSOFT_COMPILER_IS_BORLAND)

    xtests_integer_failure_reporter_selector<I1, I2>::type::xtests_report_failure_equal(file, line, function, expr, expected, actual, comp);
#  else /* ? compiler */

    typedef typename xtests_integer_failure_reporter_selector<
        I1
    ,   I2
    >::type                                                 failure_reporter_t;

    failure_reporter_t::xtests_report_failure_equal(file, line, function, expr, expected, actual, comp);
#  endif /* compiler */
}
#  if defined(STLSOFT_COMPILER_IS_MSVC) && \
       _MSC_VER >= 1310 && \
       !defined(_WIN64) && \
       defined(_Wp64)

/* This special overload is to allow for cases such as:
 *
 *     XTESTS_TEST_INTEGER_EQUAL(4, sink.size());
 */
inline
void
xtests_reportFailedIntegerComparison(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   unsigned int        expected
,   size_t              actual
,   xtests_comparison_t comp
)
{
#   ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#   endif /* _XTESTS_NO_NAMESPACE */

    STLSOFT_STATIC_CAST(void, xtests_testFailed_ulong(file, line, function, expr, static_cast<unsigned long>(expected), static_cast<unsigned long>(actual), comp));
}
#  endif

inline
void
xtests_reportFailedFloatingPointComparison(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   double const&       expected
,   double const&       actual
,   xtests_comparison_t comp
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    STLSOFT_STATIC_CAST(void, xtests_testFailed_double(file, line, function, expr, expected, actual, comp));
}


/* TODO: move to STLSoft */
inline STLSOFT_NS_QUAL(ss_sint64_t) into_maximum_type(signed long long v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_sint64_t) into_maximum_type(signed long v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_sint64_t) into_maximum_type(signed int v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_sint64_t) into_maximum_type(signed short v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_sint64_t) into_maximum_type(signed char v) STLSOFT_NOEXCEPT { return v; }

inline STLSOFT_NS_QUAL(ss_uint64_t) into_maximum_type(unsigned long long v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_uint64_t) into_maximum_type(unsigned long v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_uint64_t) into_maximum_type(unsigned int v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_uint64_t) into_maximum_type(unsigned short v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_uint64_t) into_maximum_type(unsigned char v) STLSOFT_NOEXCEPT { return v; }

#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE

inline STLSOFT_NS_QUAL(ss_sint64_t) into_maximum_type(STLSOFT_NS_QUAL(ss_sint16_t) v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_uint64_t) into_maximum_type(STLSOFT_NS_QUAL(ss_uint16_t) v) STLSOFT_NOEXCEPT { return v; }
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE

inline STLSOFT_NS_QUAL(ss_sint64_t) into_maximum_type(STLSOFT_NS_QUAL(ss_sint32_t) v) STLSOFT_NOEXCEPT { return v; }
inline STLSOFT_NS_QUAL(ss_uint64_t) into_maximum_type(STLSOFT_NS_QUAL(ss_uint32_t) v) STLSOFT_NOEXCEPT { return v; }
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

/* TODO: move to STLSoft */
inline
bool
integer_values_are_comparable(
    STLSOFT_NS_QUAL(ss_sint64_t)    s_val
,   STLSOFT_NS_QUAL(ss_uint64_t)    u_val
) STLSOFT_NOEXCEPT
{
    if (s_val < 0)
    {
        return false;
    }

    if (u_val > static_cast<STLSOFT_NS_QUAL(ss_uint64_t)>(STLSOFT_NS_QUAL(integral_limits)<STLSOFT_NS_QUAL(ss_sint64_t)>::maximum()))
    {
        return false;
    }

    return true;
}

inline
bool
integer_values_are_comparable(
    STLSOFT_NS_QUAL(ss_uint64_t)    u_val
,   STLSOFT_NS_QUAL(ss_sint64_t)    s_val
) STLSOFT_NOEXCEPT
{
    return integer_values_are_comparable(s_val, u_val);
}


template<
    typename I
,   typename II
>
inline
int
xtests_test_integer_compare_to_range_(
    char const*         /* file */
,   int                 /* line */
,   char const*         /* function */
,   char const*         /* expr */
,   II                  begin
,   II                  end
,   I const&            actual
,   xtests_comparison_t comp
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    switch (comp)
    {
    case xtestsComparisonEqual:

        for (; begin != end; ++begin)
        {
            I const& expected = *begin;

            if (expected == actual)
            {
                return true;
            }
        }

        return false;
    case xtestsComparisonNotEqual:

        for (; begin != end; ++begin)
        {
            I const& expected = *begin;

            if (expected == actual)
            {
                return false;
            }
        }

        return true;
    case xtestsComparisonApproxEqual:
    case xtestsComparisonApproxNotEqual:
    case xtestsComparisonGreaterThan:
    case xtestsComparisonLessThan:
    case xtestsComparisonGreaterThanOrEqual:
    case xtestsComparisonLessThanOrEqual:

        xtests_abend("invalid test comparison type: only == and != are valid when testing membership of ranges");
        break;
    default:

        STLSOFT_MESSAGE_ASSERT("unrecognised enumerator", false);
    case xtestsComparison_max_enumerator:
        xtests_abend("invalid test comparison type: test framework may be out of date!");
        break;
    }

    xtests_abend("should not get here!");

    return -1;
}

template<
    typename I
,   typename II
>
inline
int
xtests_test_integer_any_in_range(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   II                  begin
,   II                  end
,   I const&            actual
,   xtests_comparison_t comp
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    int const comparisonSucceeded = xtests_test_integer_compare_to_range_(file, line, function, expr, begin, end, actual, comp);

    if (comparisonSucceeded)
    {
        xtests_testPassed(file, line, function, expr);
    }
    else
    {
#if 0

        xtests_reportFailedIntegerComparison(file, line, function, expr, expected, actual, comp);
#else /* ? 0 */

        xtests_testFailed(file, line, function, expr);
#endif /* 0 */
    }

    return comparisonSucceeded;
}

template<
    typename I1
,   typename I2
>
inline
int
xtests_test_integer_when_same_sign_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type) < I1 > ::value);
    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type) < I2 > ::value);

    int comparisonSucceeded = false;

    switch (comp)
    {
    case xtestsComparisonEqual:
    case xtestsComparisonApproxEqual:

        if (expected == actual)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonNotEqual:
    case xtestsComparisonApproxNotEqual:

        if (expected != actual)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonGreaterThan:

        if (actual > expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonLessThan:

        if (actual < expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonGreaterThanOrEqual:

        if (actual >= expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonLessThanOrEqual:

        if (actual <= expected)
        {
            comparisonSucceeded = true;
        }
        break;
    default:

        STLSOFT_MESSAGE_ASSERT("unrecognised enumerator", false);
    case xtestsComparison_max_enumerator:

        xtests_abend("invalid test comparison type: test framework may be out of date!");
        break;
    }

    if (comparisonSucceeded)
    {
        xtests_testPassed(file, line, function, expr);
    }
    else
    {
        xtests_reportFailedIntegerComparison(file, line, function, expr, expected, actual, comp);
    }

    return comparisonSucceeded;
}

/** Compare two integers of the same type in the given manner.
 *
 */
template<
    typename I1
,   typename I2
>
inline
int
xtests_test_integer_is_same_type_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
,   STLSOFT_NS_QUAL(yes_type)
)
{
    return xtests_test_integer_when_same_sign_(
        file
    ,   line
    ,   function
    ,   expr
    ,   expected
    ,   actual
    ,   comp
    );
}

/** Compare two integers of the largest signed and unsigned types in the
 * given manner, including determining whether they are actually comparable.
 *
 */
template<
    typename I1
,   typename I2
>
inline
int
xtests_test_integer_is_different_sign_max_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
)
{
    // this is the only function where the integer types / signs are not
    // resolvable entirely at compile-time, so algorithm:
    //
    // 1. promote both to their largest possible type/value;
    // 2. determine whether their actual values are comparable;

    if (!integer_values_are_comparable(expected, actual))
    {
        char        buff[21];
        std::string message;

        message.append(file);
        message.append(1, ':');
        message.append(STLSOFT_NS_QUAL(integer_to_decimal_string)(&buff[0], STLSOFT_NUM_ELEMENTS(buff), line));
        message.append(1, ':');
        message.append(function);
        message.append(1, ':');
        message.append(1, ' ');
        message.append("cannot compare integers of different signs with value(s) outside the shared range");

        throw std::logic_error(message);
    }
    // else
    {
        // One is signed, but not negative, and the other is unsigned but
        // within the range of the (non-negative) signed, so we can cast to
        // either and process

        STLSOFT_NS_QUAL(ss_sint64_t) const  expected_s64    =   static_cast<STLSOFT_NS_QUAL(ss_sint64_t)>(expected);
        STLSOFT_NS_QUAL(ss_sint64_t) const  actual_s64      =   static_cast<STLSOFT_NS_QUAL(ss_sint64_t)>(actual);

        return xtests_test_integer_when_same_sign_(
            file
        ,   line
        ,   function
        ,   expr
        ,   expected_s64
        ,   actual_s64
        ,   comp
        );
    }
}

/** Compare two integers of different sign (and different type) in the given
 * manner.
 *
 */
template<
    typename I1
,   typename I2
>
inline
int
xtests_test_integer_is_same_sign_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
,   STLSOFT_NS_QUAL(no_type)
)
{
    return xtests_test_integer_is_different_sign_max_(
        file
    ,   line
    ,   function
    ,   expr
    ,   XTESTS_NS_CPP_QUAL(into_maximum_type)(expected)
    ,   XTESTS_NS_CPP_QUAL(into_maximum_type)(actual)
    ,   comp
    );
}

/** Compare two integers of same sign (but different type) in the given
 * manner.
 *
 */
template<
    typename I1
,   typename I2
>
inline
int
xtests_test_integer_is_same_sign_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
,   STLSOFT_NS_QUAL(yes_type)
)
{
    return xtests_test_integer_when_same_sign_(
        file
    ,   line
    ,   function
    ,   expr
    ,   expected
    ,   actual
    ,   comp
    );
}

/** Compare two integers of different type in the given manner.
 *
 */
template<
    typename I1
,   typename I2
>
inline
int
xtests_test_integer_is_same_type_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
,   STLSOFT_NS_QUAL(no_type)
)
{
    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type) < I1 > ::value);
    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type) < I2 > ::value);

    enum { _I1_and_I2_have_same_sign = ((0 != STLSOFT_NS_QUAL(is_signed_type)<I1>::value) == (0 != STLSOFT_NS_QUAL(is_signed_type)<I2>::value)) };

    typedef ss_typename_type_k STLSOFT_NS_QUAL(value_to_yesno_type)<_I1_and_I2_have_same_sign>::type    are_same_sign_t;

    return xtests_test_integer_is_same_sign_(
        file
    ,   line
    ,   function
    ,   expr
    ,   expected
    ,   actual
    ,   comp
    ,   are_same_sign_t()
    );
}

/** Compare two integers of arbitrary size/sign in the given manner.
 *
 */
template<
    typename I1
,   typename I2
>
inline
int
xtests_test_integer_underlying_type_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
)
{
    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type) < I1 > ::value);
    STLSOFT_STATIC_ASSERT(0 != STLSOFT_NS_QUAL(is_integral_type) < I2 > ::value);

    typedef ss_typename_type_k STLSOFT_NS_QUAL(is_same_type)<I1, I2>::type  I1_and_I2_are_same_type_t;

    return xtests_test_integer_is_same_type_(
        file
    ,   line
    ,   function
    ,   expr
    ,   expected
    ,   actual
    ,   comp
    ,   I1_and_I2_are_same_type_t()
    );
}

/** Compare two integer like values of arbitrary type in the given manner.
 *
 */
template<
    typename I1
,   typename I2
>
inline
int
xtests_test_integer(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           expected
,   I2 const&           actual
,   xtests_comparison_t comp
)
{
    return xtests_test_integer_underlying_type_(
        file
    ,   line
    ,   function
    ,   expr
    ,   STLSOFT_NS_QUAL(integral_traits)<I1>::get_underlying_value(expected)
    ,   STLSOFT_NS_QUAL(integral_traits)<I2>::get_underlying_value(actual)
    ,   comp
    );
}


struct boolean_test_must_involve_boolean_parameters {};

template <typename T>
struct boolean_argument_traits
{
    typedef ss_typename_type_k STLSOFT_NS_QUAL(no_type)     yesno_type;
};
template <>
struct boolean_argument_traits<bool>
{
    typedef STLSOFT_NS_QUAL(yes_type)                       yesno_type;
};
template <>
struct boolean_argument_traits<signed int>
{
    typedef STLSOFT_NS_QUAL(yes_type)                       yesno_type;
};

template <typename T>
inline
boolean_test_must_involve_boolean_parameters
xtests_test_boolean_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   bool                expected
,   T const&            actual
,   xtests_comparison_t comp
,   STLSOFT_NS_QUAL(no_type)
);

template <typename T>
inline
int
xtests_test_boolean_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   bool                expected
,   T const&            actual
,   xtests_comparison_t comp
,   STLSOFT_NS_QUAL(yes_type)
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    bool const actual_as_bool = !!actual;

    int comparisonSucceeded = false;

    switch (comp)
    {
    case xtestsComparisonEqual:
    case xtestsComparisonApproxEqual:

        if (expected == actual_as_bool)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonNotEqual:
    case xtestsComparisonApproxNotEqual:

        if (expected != actual_as_bool)
        {
            comparisonSucceeded = true;
        }
        break;
#if 0 /* NOTE: currently don't support ordering of `bool` */

    case xtestsComparisonGreaterThan:

        if (actual_as_bool > expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonLessThan:

        if (actual_as_bool < expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonGreaterThanOrEqual:

        if (actual_as_bool >= expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonLessThanOrEqual:

        if (actual_as_bool <= expected)
        {
            comparisonSucceeded = true;
        }
        break;
#endif
    default:

        STLSOFT_MESSAGE_ASSERT("unrecognised enumerator", false);
    case xtestsComparison_max_enumerator:

        xtests_abend("invalid test comparison type: test framework may be out of date!");
        break;
    }

    if (comparisonSucceeded)
    {
        xtests_testPassed(file, line, function, expr);
    }
    else
    {
        STLSOFT_STATIC_CAST(void, xtests_testFailed_boolean(file, line, function, expr, expected, actual_as_bool, comp));
    }

    return comparisonSucceeded;
}

template <typename T>
inline
int
xtests_test_boolean(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   bool                expected
,   T const&            actual
,   xtests_comparison_t comp
)
{
    typedef ss_typename_type_k boolean_argument_traits<T>::yesno_type yesno_t;

    return xtests_test_boolean_(file, line, function, expr, expected, actual, comp, yesno_t());
}

template<
    typename I0
,   typename I1
>
inline
int
xtests_test_integer_one_of(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           actual
,   I0 const&           expected0
,   I0 const&           expected1
,   I0 const&           expected2
,   I0 const&           expected3
,   I0 const&           expected4
,   I0 const&           expected5
,   I0 const&           expected6
,   I0 const&           expected7
,   xtests_comparison_t comp
)
{
    I0 const range[] = {
        expected0
    ,   expected1
    ,   expected2
    ,   expected3
    ,   expected4
    ,   expected5
    ,   expected6
    ,   expected7
    };

    return xtests_test_integer_any_in_range(file, line, function, expr, &range[0], &range[0] + STLSOFT_NUM_ELEMENTS(range), actual, comp);
}

template<
    typename I0
,   typename I1
>
inline
int
xtests_test_integer_one_of(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           actual
,   I0 const&           expected0
,   I0 const&           expected1
,   I0 const&           expected2
,   I0 const&           expected3
,   I0 const&           expected4
,   I0 const&           expected5
,   I0 const&           expected6
,   xtests_comparison_t comp
)
{
    return xtests_test_integer_one_of(
        file, line, function, expr
    ,   actual
    ,   expected0, expected1, expected2, expected3, expected4, expected5, expected6, expected0
    ,   comp
    );
}

template<
    typename I0
,   typename I1
>
inline
int
xtests_test_integer_one_of(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           actual
,   I0 const&           expected0
,   I0 const&           expected1
,   I0 const&           expected2
,   I0 const&           expected3
,   I0 const&           expected4
,   I0 const&           expected5
,   xtests_comparison_t comp
)
{
    return xtests_test_integer_one_of(
        file, line, function, expr
    ,   actual
    ,   expected0, expected1, expected2, expected3, expected4, expected5, expected0, expected0
    ,   comp
    );
}

template<
    typename I0
,   typename I1
>
inline
int
xtests_test_integer_one_of(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           actual
,   I0 const&           expected0
,   I0 const&           expected1
,   I0 const&           expected2
,   I0 const&           expected3
,   I0 const&           expected4
,   xtests_comparison_t comp
)
{
    return xtests_test_integer_one_of(
        file, line, function, expr
    ,   actual
    ,   expected0, expected1, expected2, expected3, expected4, expected0, expected0, expected0
    ,   comp
    );
}

template<
    typename I0
,   typename I1
>
inline
int
xtests_test_integer_one_of(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           actual
,   I0 const&           expected0
,   I0 const&           expected1
,   I0 const&           expected2
,   I0 const&           expected3
,   xtests_comparison_t comp
)
{
    return xtests_test_integer_one_of(
        file, line, function, expr
    ,   actual
    ,   expected0, expected1, expected2, expected3, expected0, expected0, expected0, expected0
    ,   comp
    );
}

template<
    typename I0
,   typename I1
>
inline
int
xtests_test_integer_one_of(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           actual
,   I0 const&           expected0
,   I0 const&           expected1
,   I0 const&           expected2
,   xtests_comparison_t comp
)
{
    return xtests_test_integer_one_of(
        file, line, function, expr
    ,   actual
    ,   expected0, expected1, expected2, expected0, expected0, expected0, expected0, expected0
    ,   comp
    );
}

template<
    typename I0
,   typename I1
>
inline
int
xtests_test_integer_one_of(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   I1 const&           actual
,   I0 const&           expected0
,   I0 const&           expected1
,   xtests_comparison_t comp
)
{
    return xtests_test_integer_one_of(
        file, line, function, expr
    ,   actual
    ,   expected0, expected1, expected0, expected0, expected0, expected0, expected0, expected0
    ,   comp
    );
}


inline
int
xtests_test_character(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char                expected
,   char                actual
,   xtests_comparison_t comp
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    return xtests_testCharactersA(file, line, function, expr, expected, actual, comp);
}
inline
int
xtests_test_character(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t             expected
,   wchar_t             actual
,   xtests_comparison_t comp
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    return xtests_testCharactersW(file, line, function, expr, expected, actual, comp);
}

inline
int
xtests_test_floating_point(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   double const&       expected
,   double const&       actual
,   xtests_comparison_t comp
)
{
#  ifndef _XTESTS_NO_NAMESPACE
    using namespace ::xtests::c;
#  endif /* _XTESTS_NO_NAMESPACE */

    int comparisonSucceeded = false;

    switch (comp)
    {
    case xtestsComparisonEqual:

        if (expected == actual)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonApproxEqual:

        if (xtests_floatingPointClose(expected, actual))
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonNotEqual:

        if (expected != actual)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonApproxNotEqual:

        if (!xtests_floatingPointClose(expected, actual))
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonGreaterThan:

        if (actual > expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonLessThan:

        if (actual < expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonGreaterThanOrEqual:

        if (actual >= expected)
        {
            comparisonSucceeded = true;
        }
        break;
    case xtestsComparisonLessThanOrEqual:

        if (actual <= expected)
        {
            comparisonSucceeded = true;
        }
        break;
    default:

        STLSOFT_MESSAGE_ASSERT("unrecognised enumerator", false);
    case xtestsComparison_max_enumerator:

        xtests_abend("invalid test comparison type: test framework may be out of date!");
        break;
    }

    if (comparisonSucceeded)
    {
        STLSOFT_STATIC_CAST(void, xtests_testPassed(file, line, function, expr));
    }
    else
    {
        STLSOFT_STATIC_CAST(void, xtests_reportFailedFloatingPointComparison(file, line, function, expr, expected, actual, comp));
    }

    return comparisonSucceeded;
}
# endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */
#endif /* !_XTESTS_NO_CPP_API */
#ifndef _XTESTS_NO_NAMESPACE
} /* namespace cpp */
namespace c
{
#endif /* !_XTESTS_NO_NAMESPACE */
#ifdef _XTESTS_NO_CPP_API

# define XTESTS_REQUIRE(test)                               XTESTS_NS_C_QUAL(xtests_require_C)(!(!(test)))
#endif /* _XTESTS_NO_CPP_API */

/** [INTERNAL] Worker function for XTESTS_REQUIRE() (in C compilation units)
 */
XTESTS_CALL(int)
xtests_require_C(
    int success
);

/** [INTERNAL] Worker function
 */
XTESTS_CALL(int)
xTests_hasRequiredConditionFailed(void);


/* ///////////////////////////////////////////////////////////////////
 * utility functions
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

/** Parses the command-line for '--verbosity'
 *
 * \param argc The argument count;
 * \param argv Pointer to first element of array (of size argc + 1) of
 *   argument pointers, the first one of which is the name of the program,
 *   and the last one of which is NULL;
 * \param verbosity Pointer to variable to receive the verbosity. May not be
 *   NULL;
 *
 * \retval 0 No verbosity was parsed from the command-line
 * \retval !0 Verbosity was parsed from the command-line
 */
XTESTS_CALL(int)
xtests_commandLine_parseVerbosity(
    int     argc
,   char*   argv[]
,   int*    verbosity
);

/** Parses the command-line for '--help'
 *
 * \param argc The argument count;
 * \param argv Pointer to first element of array (of size argc + 1) of
 *   argument pointers, the first one of which is the name of the program,
 *   and the last one of which is NULL;
 * \param stm The stream to which to write the usage message, in the case
 *   where '--help' is found. May not be NULL;
 * \param exitCode The exit code passed to <code>::exit()</code>;
 */
XTESTS_CALL(void)
xtests_commandLine_parseHelp(
    int     argc
,   char*   argv[]
,   FILE*   stm
,   int     exitCode
);

/** Parses the command-line for '--help'
 *
 * \param argc The argument count;
 * \param argv Pointer to first element of array (of size argc + 1) of
 *   argument pointers, the first one of which is the name of the program,
 *   and the last one of which is NULL;
 * \param stm The stream to which to write the usage message, in the case
 *   where '--help' is found. May not be NULL;
 * \param exitCode Pointer to variable that contains the exit code to be
 *   passed to <code>::exit()</code>. May be NULL, in which case
 *   <code>::exit()</code> is not called. This is implemented as a pointer
 *   to facilitate testing;
 */
XTESTS_CALL(void)
xtests_commandLine_parseHelp2(
    int         argc
,   char*       argv[]
,   FILE*       stm
,   int const*  exitCode
);

/** Parses the command-line for '--help' and '--verbosity'
 *
 * \param argc The argument count;
 * \param argv Pointer to first element of array (of size argc + 1) of
 *   argument pointers, the first one of which is the name of the program,
 *   and the last one of which is NULL;
 * \param stm The stream to which to write the usage message, in the case
 *   where '--help' is found. May not be NULL;
 * \param usageExitCode Pointer to variable that will contain the exit code
 *   to be passed to <code>::exit()</code>, which is not called if this is
 *   NULL. This is implemented as a pointer to facilitate testing;
 *
 * \retval 2 '--help' was parsed from the command-line, and usageExitCode is
 *   NULL;
 * \retval 1 '--verbosity' was parsed from the command-line;
 * \retval 0 No verbosity was parsed from the command-line;
 * \retval <0 A failure occurred, and the return value is the negative value
 *   of a value from <errno.h>;
 */
XTESTS_CALL(int)
xtests_commandLine_parseHelpOrVerbosity(
    int         argc
,   char*       argv[]
,   FILE*       stm
,   int const*  usageExitCode
,   int const*  defaultVerbosity
,   int*        verbosity
);
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/** \def XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, pverbosity)
 *
 * \ingroup group__xtests__utiliy_functions
 *
 * \brief Parses help or verbosity from the command-line
 *
 * Parses the '--help' flag from the command-line and, if found, issues
 * usage information to the standard output stream and exits (with
 * `EXIT_SUCCESS`)
 *
 * Parse the verbosity from the command-line arguments, looking for an
 * argument of the form `"--verbosity=<N>"`, where `N` is a non-negative
 * integer. If no such command-line argument is found, then looks for (in
 * order) the environment variables `"XTESTS_VERBOSITY"` and
 * `"TEST_VERBOSITY"`.
 *
 * \param argc The <code>argc</code> parameter passed into
 *   <code>main()</code>
 * \param argv The <code>argv</code> parameter passed into
 *   <code>main()</code>
 * \param pverbosity A pointer to an integer to receive the verbosity. Will
 *   be set to xtestsVerbositySummaryOnSuccess even if no verbosity argument
 *   is found. May not be NULL.
 *
 * \return The index of argument containing the verbosity, or 0 to indicate
 *   failure
 */
#define XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY(argc, argv, pverbosity)  \
    do {                                                                    \
        int const exitCode = EXIT_SUCCESS;                                  \
                                                                            \
        STLSOFT_STATIC_CAST(void,                                           \
            XTESTS_NS_C_QUAL(xtests_commandLine_parseHelpOrVerbosity)(      \
                (argc)                                                      \
            ,   (argv)                                                      \
            ,   (stdout)                                                    \
            ,   &exitCode                                                   \
            ,   NULL                                                        \
            ,   (pverbosity)                                                \
            )                                                               \
        );                                                                  \
    } while (XTESTS_WHILE_0_CLAUSE())


/** \def XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, pverbosity)
 *
 * \ingroup group__xtests__utiliy_functions
 *
 * \brief Parses a verbosity from the command-line
 *
 * Parse the verbosity from the command-line arguments, looking for an
 * argument of the form `"--verbosity=<N>"`, where `N` is a non-negative
 * integer. If no such command-line argument is found, then looks for (in
 * order) the environment variables `"XTESTS_VERBOSITY"` and
 * `"TEST_VERBOSITY"`.
 *
 * \param argc The <code>argc</code> parameter passed into
 *   <code>main()</code>
 * \param argv The <code>argv</code> parameter passed into
 *   <code>main()</code>
 * \param pverbosity A pointer to an integer to receive the verbosity. Will
 *   be set to xtestsVerbositySummaryOnSuccess even if no verbosity argument
 *   is found. May not be NULL.
 *
 * \return The index of argument containing the verbosity, or 0 to indicate
 *   failure
 */
#define XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, pverbosity)          \
    STLSOFT_STATIC_CAST(void, XTESTS_NS_C_QUAL(xtests_commandLine_parseVerbosity)((argc), (argv), (pverbosity)))

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

# define XTESTS_COMMANDLINE_PARSEVERBOSITY                  XTESTS_COMMANDLINE_PARSE_VERBOSITY
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */


#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION /* The following seems to break Doxygen, so we don't document it :-( */

/** \def XTESTS_COMMANDLINE_PARSE_VERBOSITY_WITH_DEFAULT(argc, argv, pverbosity, defaultVerbosity)
 *
 * \ingroup group__xtests__utiliy_functions
 *
 * Parses a verbosity from the command-line
 *
 * Parse the verbosity from the command-line arguments, looking for an
 * argument of the form "--verbosity=<N>", where N is a non-negative
 * integer.
 *
 * \param argc The <code>argc</code> parameter passed into
 *   <code>main()</code>
 * \param argv The <code>argv</code> parameter passed into
 *   <code>main()</code>
 * \param pverbosity A pointer to an integer to receive the verbosity. Will
 *   be set to xtestsVerbositySummaryOnSuccess even if no verbosity argument
 *   is found. May not be NULL.
 * \param defaultVerbosity The default verbosity to be applied if none
 *   specified on the command-line.
 *
 * \see XTESTS_COMMANDLINE_PARSEVERBOSITY()
 */
# define XTESTS_COMMANDLINE_PARSE_VERBOSITY_WITH_DEFAULT(argc, argv, pverbosity, defaultVerbosity)  \
    STLSOFT_STATIC_CAST(void, ((0 != XTESTS_NS_C_QUAL(xtests_commandLine_parseVerbosity)((argc), (argv), (pverbosity)))) ? 1 : ((*(pverbosity) = (defaultVerbosity)), 0))

# define XTESTS_COMMANDLINE_PARSEVERBOSITY_DEFAULT          XTESTS_COMMANDLINE_PARSE_VERBOSITY_WITH_DEFAULT
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/** \def XTESTS_COMMANDLINE_PARSE_HELP(argc, argv)
 *
 * \ingroup group__xtests__utiliy_functions
 *
 * Parses the '--help' flag from the command-line and, if found, issues
 * usage information to the standard output stream and exits (with
 * `EXIT_SUCCESS`)
 *
 * \param argc The <code>argc</code> parameter passed into
 *   <code>main()</code>
 * \param argv The <code>argv</code> parameter passed into
 *   <code>main()</code>
 *
 * \return nothing
 */
#define XTESTS_COMMANDLINE_PARSE_HELP(argc, argv)                           \
    STLSOFT_STATIC_CAST(void, XTESTS_NS_C_QUAL(xtests_commandLine_parseHelp)((argc), (argv), stdout, EXIT_SUCCESS))

/** \def XTESTS_ARRAY_END_POST(ar)
 *
 * \ingroup group__xtests__utiliy_functions
 *
 * Evaluates the end-point of an array, based on its static array size.
 */
#ifdef __DMC__
# define XTESTS_ARRAY_END_POST(ar)                          (&(ar)[0] + STLSOFT_NUM_ELEMENTS(ar))
#else /* ? compiler */
# define XTESTS_ARRAY_END_POST(ar)                          (&0[(ar)] + STLSOFT_NUM_ELEMENTS(ar))
#endif /* compiler */


/* ///////////////////////////////////////////////////////////////////
 * miscellaneous constructs
 */


/* /////////////////////////////////////////////////////////////////////////
 * obsolete names
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION
# define XTESTS_FAIL_WITH_QUALIFIER(msg, qualifier)         XTESTS_TEST_FAIL_WITH_QUALIFIER(msg, qualifier)
# define XTESTS_FAIL(msg)                                   XTESTS_TEST_FAIL(msg)
# define XTESTS_PASSED()                                    XTESTS_TEST_PASSED()
# define XTESTS_TEST_MULTIBYTE_STRINGS_EQUAL                XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef _XTESTS_NO_NAMESPACE
} /* namespace c */
} /* namespace xtests */
#endif /* !_XTESTS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !XTESTS_INCL_XTESTS_H_XTESTS */

/* ///////////////////////////// end of file //////////////////////////// */

