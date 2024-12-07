/* /////////////////////////////////////////////////////////////////////////
 * File:    src/xtests.core.cpp (formerly part of Synesis' internal test codebase)
 *
 * Purpose: Primary implementation file for xTests core library.
 *
 * Created: 20th June 1999
 * Updated: 8th December 2024
 *
 * Home:    https://github.com/synesissoftware/xTests/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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




/* xTests Header Files */
#ifndef _XTESTS_NO_CPP_API
# define _XTESTS_NO_CPP_API
#endif /* !_XTESTS_NO_CPP_API */
#include <xtests/xtests.h>
#include <xtests/internal/safestr.h>

#include "xtests.internal.string.h"
#include "xtests.internal.exception_macros.hpp"

/* Warning suppressions */
#if defined(STLSOFT_COMPILER_IS_MSVC)
# ifdef XTESTS_USING_SAFE_STR_FUNCTIONS
#  pragma warning(disable : 4996)
# endif /* XTESTS_USING_SAFE_STR_FUNCTIONS */
# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)
#  pragma warning(disable : 4702)
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
#  pragma warning(disable : 4530)
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* compiler */

#if defined(XTESTS_USE_PANTHEIOS)
# include <pantheios/pantheios.h>
#endif /* XTESTS_USE_PANTHEIOS */

/* STLSoft Header Files */
#include <platformstl/platformstl.h>
#include <platformstl/filesystem/path_functions.h>
#include <platformstl/system/console_functions.h>
#include <platformstl/system/environment_variable.hpp>
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/shims/access/string/std/c_string.h>
#include <stlsoft/string/case_functions.hpp>
#include <stlsoft/string/string_traits_fwd.hpp>
#include <stlsoft/string/string_view.hpp>
#if defined(STLSOFT_COMPILER_IS_WATCOM) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1300)
#else /* ? compiler */
# ifndef XTESTS_STLSOFT_1_12_OR_LATER
#  include <stlsoft/util/must_init.hpp>
# endif /* !STLSoft 1.12+ */
#endif /* compiler */
#ifdef XTESTS_STLSOFT_1_12_OR_LATER
# include <stlsoft/traits/integral_printf_format_traits.hpp>
#else /* ? STLSoft 1.12+ */
# include <stlsoft/util/integral_printf_traits.hpp>
#endif /* STLSoft 1.12+ */
#include <stlsoft/util/string/snprintf.h>

/* Standard C++ Header Files */
#include <map>
#include <string>

/* Standard C Header Files */
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * compatiblity tests
 */

/* Warning suppressions */
#if defined(STLSOFT_COMPILER_IS_MSVC)
# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
#  pragma warning(default : 4530)
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
# if defined(STLSOFT_CF_RTTI_SUPPORT)
# else /* ? STLSOFT_CF_RTTI_SUPPORT */
#  pragma warning(default : 4541)
# endif /* STLSOFT_CF_RTTI_SUPPORT */
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#define XTESTS_VERBOSITY_VALID_MISSING_CASES    \
                                                \
                case 5:                         \
                case 6:                         \
                case 7:                         \
                case 8:                         \
                                                \


/* /////////////////////////////////////////////////////////////////////////
 * compatiblity
 */

/* Windows debugging support
 *
 * XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ == 0   =>  no support
 * XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ == 1   =>  Windows build
 * XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ == 2   =>  Windows-emulation build
 */

#ifdef XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_
# undef XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_
#endif /* XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ */

#if defined(WIN32) || \
    defined(WIN64)

# define XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_          1
#elif (   defined(STLSOFT_COMPILER_IS_MSVC) || \
          defined(STLSOFT_COMPILER_IS_UNKNOWN)) && \
      defined(_MSC_VER) && \
      !defined(WIN32) && \
      defined(UNIX) && \
      defined(_WIN32)

# define XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_          2
#else

# define XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_          0
#endif

#ifdef XTESTS_USING_SAFE_STR_FUNCTIONS
# define xtests_strcpy_(d, n, s)                            ::strcpy_s(d, n, s)
# define xtests_wcscpy_(d, n, s)                            ::wcscpy_s(d, n, s)
//# define xtests_strncpy_(d, n, s, l)                        ::strncpy_s(d, n, s, l)
//# define xtests_wcsncpy_(d, n, s, l)                        ::wcsncpy_s(d, n, s, l)
# define xtests_sprintf_2_(s, n, fmt, a0, a1)               ::sprintf_s(s, n, fmt, a0, a1)
# define xtests_sprintf_3_(s, n, fmt, a0, a1, a2)           ::sprintf_s(s, n, fmt, a0, a1, a2)
# define xtests_vsnprintf_(s, z, n, fmt, args)              ::vsnprintf_s(s, z, n, fmt, args)
#else /* ? XTESTS_USING_SAFE_STR_FUNCTIONS */
# define xtests_strcpy_(d, n, s)                            ::strcpy(d, s)
# define xtests_wcscpy_(d, n, s)                            ::wcscpy(d, s)
//# define xtests_strncpy_(d, n, s, l)                        ::strncpy(d, s, l)
//# define xtests_wcsncpy_(d, n, s, l)                        ::wcsncpy(d, s, l)
# if defined(__clang__) && \
     __clang_major__ >= 14
#  define xtests_sprintf_2_(s, n, fmt, a0, a1)              ::snprintf(s, n, fmt, a0, a1)
#  define xtests_sprintf_3_(s, n, fmt, a0, a1, a2)          ::snprintf(s, n, fmt, a0, a1, a2)
# else
#  define xtests_sprintf_2_(s, n, fmt, a0, a1)              ::sprintf(s, fmt, a0, a1)
#  define xtests_sprintf_3_(s, n, fmt, a0, a1, a2)          ::sprintf(s, fmt, a0, a1, a2)
# endif
# if defined(STLSOFT_COMPILER_IS_DMC) || \
     (   (   defined(WIN32) || \
             defined(WIN64)) && \
         (   defined(STLSOFT_COMPILER_IS_INTEL) || \
             (   defined(STLSOFT_COMPILER_IS_COMO) && \
                 defined(_MSC_VER)))) || \
     defined(STLSOFT_COMPILER_IS_MSVC)
#  define xtests_vsnprintf_(s, z, n, fmt, args)             ::_vsnprintf(s, n, fmt, args)
# else /* ? compiler / OS */
#  define xtests_vsnprintf_(s, z, n, fmt, args)             ::vsnprintf(s, n, fmt, args)
# endif /* compiler / OS */
#endif /* XTESTS_USING_SAFE_STR_FUNCTIONS */


#if defined(STLSOFT_COMPILER_IS_DMC)
# define RETURN_UNUSED(x)                                   return x
#else /* ? compiler */
# define RETURN_UNUSED(x)
#endif /* compiler */

#define XTESTS_ANSI_BG_BLACK_                               (40)
#define XTESTS_ANSI_BG_RED_                                 (41)
#define XTESTS_ANSI_BG_GREEN_                               (42)
#define XTESTS_ANSI_BG_YELLOW_                              (43)
#define XTESTS_ANSI_BG_BLUE_                                (44)
#define XTESTS_ANSI_BG_MAGENTA_                             (45)
#define XTESTS_ANSI_BG_CYAN_                                (46)
#define XTESTS_ANSI_BG_WHITE_                               (47)
#define XTESTS_ANSI_BG_BRIGHT_BLACK_                        (100)
#define XTESTS_ANSI_BG_BRIGHT_RED_                          (101)
#define XTESTS_ANSI_BG_BRIGHT_GREEN_                        (102)
#define XTESTS_ANSI_BG_BRIGHT_YELLOW_                       (103)
#define XTESTS_ANSI_BG_BRIGHT_BLUE_                         (104)
#define XTESTS_ANSI_BG_BRIGHT_MAGENTA_                      (105)
#define XTESTS_ANSI_BG_BRIGHT_CYAN_                         (106)
#define XTESTS_ANSI_BG_BRIGHT_WHITE_                        (107)

#define XTESTS_ANSI_FG_BLACK_                               (30)
#define XTESTS_ANSI_FG_RED_                                 (31)
#define XTESTS_ANSI_FG_GREEN_                               (32)
#define XTESTS_ANSI_FG_YELLOW_                              (33)
#define XTESTS_ANSI_FG_BLUE_                                (34)
#define XTESTS_ANSI_FG_MAGENTA_                             (35)
#define XTESTS_ANSI_FG_CYAN_                                (36)
#define XTESTS_ANSI_FG_WHITE_                               (37)
#define XTESTS_ANSI_FG_BRIGHT_BLACK_                        (90)
#define XTESTS_ANSI_FG_BRIGHT_RED_                          (91)
#define XTESTS_ANSI_FG_BRIGHT_GREEN_                        (92)
#define XTESTS_ANSI_FG_BRIGHT_YELLOW_                       (93)
#define XTESTS_ANSI_FG_BRIGHT_BLUE_                         (94)
#define XTESTS_ANSI_FG_BRIGHT_MAGENTA_                      (95)
#define XTESTS_ANSI_FG_BRIGHT_CYAN_                         (96)
#define XTESTS_ANSI_FG_BRIGHT_WHITE_                        (97)


/* /////////////////////////////////////////////////////////////////////////
 * Windows debugging support
 */

#if XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_
static void xtests_OutputDebugStringA_(char const*);
# define OutputDebugStringA                                 xtests_OutputDebugStringA_
#endif /* XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ */


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

namespace
{

    typedef stlsoft::auto_buffer<char>                      char_buffer_t_;
    typedef stlsoft::auto_buffer<wchar_t>                   char_buffer_w_t_;
} // anonymous namespace

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */
# ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

    STLSOFT_TEMPLATE_SPECIALISATION
    struct string_traits< char_buffer_t_>
    {
        typedef char_buffer_t_::value_type                  char_type;
    };

    STLSOFT_TEMPLATE_SPECIALISATION
    struct string_traits< char_buffer_w_t_>
    {
        typedef char_buffer_w_t_::value_type                char_type;
    };
# endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */
#ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* _STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef _XTESTS_NO_NAMESPACE
namespace xtests
{
namespace c
{
#endif /* !_XTESTS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
namespace
{
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */

    typedef stlsoft::ss_sint32_t                            sint32_t;
    typedef stlsoft::ss_uint32_t                            uint32_t;
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef stlsoft::ss_sint64_t                            sint64_t;
    typedef stlsoft::ss_uint64_t                            uint64_t;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef std::string                                     string_t;

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

    struct TestInfo
    {
        string_t    name;
        string_t    description;
        unsigned    totalConditions;
        unsigned    failedConditions;
        unsigned    unexpectedExceptions;
        unsigned    expectedExceptions;

        TestInfo(char const* name, char const* description)
            : name(name)
            , description(description)
            , totalConditions(0)
            , failedConditions(0)
            , unexpectedExceptions(0)
            , expectedExceptions(0)
        {}

        bool haveAllTestsPassed() const
        {
            return (0 == failedConditions && 0 ==  unexpectedExceptions && 0 == expectedExceptions);
        }
    };
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

    typedef std::map<string_t, TestInfo>                    test_map_t;


#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

    class RunnerInfo
    {
    public: // construction
        RunnerInfo(
            char const*         name
        ,   int                 verbosity
        ,   xTests_Reporter_t*  reporter
        ,   void*               reporterParam
        ,   FILE*               stm
        ,   int                 flags
        ,   xTests_Setup_t      setup
        ,   xTests_Teardown_t   teardown
        ,   void*               setupParam
        );
    private:
        void operator =(RunnerInfo const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

    public:
        int BeginCase(char const* name, char const* description);
        int EndCase(char const* name);
        void*
        GetSetupParam() const;

        int RegisterSuccessfulCondition(
            char const* file
        ,   int         line
        ,   char const* function
        ,   char const* expr
        );
        int RegisterFailedCondition(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        );
        int RegisterFailedCondition_long(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   long                    expected
        ,   long                    actual
        ,   xtests_comparison_t     comp
        );
        int RegisterFailedCondition_ulong(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   unsigned long           expected
        ,   unsigned long           actual
        ,   xtests_comparison_t     comp
        );
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
        int RegisterFailedCondition_sint64(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   sint64_t                expected
        ,   sint64_t                actual
        ,   xtests_comparison_t     comp
        );
        int RegisterFailedCondition_uint64(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   uint64_t                expected
        ,   uint64_t                actual
        ,   xtests_comparison_t     comp
        );
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
        int RegisterFailedCondition_boolean(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   bool                    expected
        ,   bool                    actual
        ,   xtests_comparison_t     comp
        );
        int RegisterFailedCondition_double(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   double const&           expected
        ,   double const&           actual
        ,   xtests_comparison_t     comp
        );
        int TestMultibyteStrings(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   char const*             expected
        ,   char const*             actual
        ,   xtests_comparison_t     comp
        );
        int TestMultibyteStringsN(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   char const*             expected
        ,   char const*             actual
        ,   ptrdiff_t               n /* exact if +ve; limit if -ve */
        ,   size_t                  cchExpected
        ,   size_t                  cchActual
        ,   xtests_comparison_t     comp
        );
        int TestWideStrings(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   wchar_t const*          expected
        ,   wchar_t const*          actual
        ,   xtests_comparison_t     comp
        );
        int TestWideStringsN(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   wchar_t const*          expected
        ,   wchar_t const*          actual
        ,   int                     n /* exact if +ve; limit if -ve */
        ,   size_t                  cchExpected
        ,   size_t                  cchActual
        ,   xtests_comparison_t     comp
        );
        int TestMultibyteStringContains(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   char const*             expected
        ,   char const*             actual
        ,   xtests_comparison_t     comp
        );
        int TestWideStringContains(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   wchar_t const*          expected
        ,   wchar_t const*          actual
        ,   xtests_comparison_t     comp
        );
        int TestMultibyteStringSlice(
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
        int TestWideStringSlice(
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
        int TestPointers(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   void volatile const*    expected
        ,   void volatile const*    actual
        ,   xtests_comparison_t     comp
        );
        int TestFunctionPointers(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   void                    (*expected)(void)
        ,   void                    (*actual)(void)
        ,   xtests_comparison_t     comp
        );
        int TestCharacters(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   char                    expected
        ,   char                    actual
        ,   xtests_comparison_t     comp
        );
        int TestCharacters(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             expr
        ,   wchar_t                 expected
        ,   wchar_t                 actual
        ,   xtests_comparison_t     comp
        );
        int WriteFailMessage(
            char const*             file
        ,   int                     line
        ,   char const*             function
        ,   char const*             message
        ,   char const*             qualifyingInformation
        );
        void CaseExcepted(
            char const* file
        ,   int         line
        ,   char const* exceptionType
        ,   char const* exceptionMessage
        );
        void CaseExceptionExpected(
            char const* file
        ,   int         line
        ,   char const* exceptionType
        );

        void OnRequireFailed();
        int HasRequiredConditionFailed() const;

        void PrintStart();
        void PrintEnd();
        void PrintResults();
        void onAbend(char const* message);
        size_t NumberOfFailedTestCases() const;

    private:
#if defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT)
        typedef stlsoft::must_init<int>                     int_type;
        typedef stlsoft::must_init<uint32_t>                unsigned_type;
#else /* ? STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT */
        typedef int                                         int_type;
        typedef uint32_t                                    unsigned_type;
#endif /* STLSOFT_INCL_STLSOFT_UTIL_HPP_MUST_INIT */

    private:
        /* static */
        void Call_onTestFailed(
            xTests_Reporter_t* const    reporter
        ,   void*                       reporterParam
        ,   char const*                 file
        ,   int                         line
        ,   char const*                 function
        ,   char const*                 expr
        ,   xtests_variable_t const*    expectedValue
        ,   xtests_variable_t const*    actualValue
        ,   ptrdiff_t                   length
        ,   xtests_comparison_t         comparison
        ,   int                         verbosity
        );

    private:
        static
        xTests_Reporter_t*
        get_reporter_(
            xTests_Reporter_t*  reporter
        ,   FILE*               stm
        ,   int                 flags
        ,   int                 is_tty
        );
        void report_unstartedCase_defect_();

    private:
        xTests_Reporter_t* const    m_reporter;
        void* const                 m_reporterParam;
        string_t const              m_name;
        int_type const              m_verbosity;
        int const                   m_flags;
        xTests_Setup_t const        m_setup;
        xTests_Teardown_t const     m_teardown;
        void* const                 m_setupParam;
        test_map_t                  m_testCases;
        unsigned_type               m_totalConditions;
        unsigned_type               m_failedConditions;
        unsigned_type               m_unexpectedExceptions;
        unsigned_type               m_expectedExceptions;
        test_map_t::iterator        m_currentCase;
        bool                        m_requireFailed;
    };
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

    ////////////////////////////////////////////////////////////////////////
    // Non-local variables

    static RunnerInfo*      s_runner;
    static double           s_fpApproximateFactor   =   XTESTS_FP_APPROXIMATE_FACTOR;

#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
} // anonymous namespace
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
namespace
{
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */

    enum xtests_severity_t
    {
            xtestsEmergency     =   0
        ,   xtestsAlert         =   1
        ,   xtestsCritical      =   2
        ,   xtestsError         =   3
        ,   xtestsWarning       =   4
        ,   xtestsNotice        =   5
        ,   xtestsInformational =   6
        ,   xtestsDebug         =   7
    };

    static
    int
    xtests_output_(
        xtests_severity_t   sev
    ,   char const*         message
    )
    {
#if defined(XTESTS_USE_PANTHEIOS)

# if PANTHEIOS_VER >= 0x0100018b
        pantheios::logputs(sev, message);
# else /* ? PANTHEIOS_VER */
        pantheios::puts(sev, message);
# endif /* PANTHEIOS_VER */

        return 1;
#else /* ? XTESTS_USE_PANTHEIOS */

        FILE*   stm = (sev < xtestsNotice) ? stderr : stdout;

        /* NOTE: the empty string is required to forestall GCC 4.3+'s over-eager
         * warnings
         */
        return ::fprintf(stm, message, "");
#endif /* XTESTS_USE_PANTHEIOS */
    }

    void
    adapt_fputs(
        char const* s
    ,   size_t   /* n */
    ,   void*       param
    )
    {
        FILE* const stm = STLSOFT_STATIC_CAST(FILE*, param);

        STLSOFT_STATIC_CAST(void, ::fputs(s, stm));
    }
#if XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_

    void
    adapt_OutputDebugStringA(
        char const* s
    ,   size_t   /* n */
    ,   void*    /* param */
    )
    {
        OutputDebugStringA(s);
    }
#endif /* XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ */

    typedef void (*sink_pfn_t_)(char const* s, size_t n, void* param);

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

    struct xtests_sink_t_
    {
        sink_pfn_t_ pfn;
        void*       param;
    };
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

    int
    xtests_mxnprintf_(
        xtests_sink_t_ const*   sinks
    ,   size_t                  numSinks
    ,   size_t                  requiredLen
    ,   char const*             fmt
    ,   ...
    )
    {
        if (requiredLen < 100)
        {
            requiredLen = 100;
        }
        requiredLen += strlen(fmt);

        int             r = -1;
        char_buffer_t_  buff(1);

        { for (unsigned i = 0; i != 10; ++i)
        {
            if (!buff.resize(1 + 1 + requiredLen)) // adds two to allow x and n to be different (required by VC++ "safe" fns)
            {
                { for (size_t j = 0; j != numSinks; ++j)
                {
                    xtests_sink_t_ const&   sink = sinks[j];
                    static const char       oom[] = "out of memory\n";

                    sink.pfn(oom, STLSOFT_NUM_ELEMENTS(oom) - 1, sink.param);
                }}

                ::exit(EXIT_FAILURE);
            }

            va_list args;

            va_start(args, fmt);

            r = xtests_vsnprintf_(&buff[0], buff.size(), buff.size() - 1, fmt, args);

            va_end(args);

            if (r < 0)
            {
                requiredLen *= 1 + (1 + i); // adds 2 to avoid pointless first same-size repeat
            }
            else if (r < int(buff.size() - 1))
            {
                break;
            }
            else
            {
                requiredLen = size_t(r);
            }
        }}

        if (r >= 0)
        {
            size_t n = static_cast<size_t>(r);

            buff[n] = '\0';

            { for (size_t i = 0; i != numSinks; ++i)
            {
                xtests_sink_t_ const& sink = sinks[i];

                sink.pfn(&buff[0], n, sink.param);
            }}
        }

        return r;
    }

    stlsoft::string_view
    xtests_name_(
        char_buffer_t_& buff
    ,   char const*     name
    ,   int             is_tty
    )
    {
        STLSOFT_MESSAGE_ASSERT("`name` may not be null", NULL != name);

        size_t const cchName = ::strlen(name);

        if (is_tty)
        {
            buff.resize(11 + cchName + 1);

            int const n         =   stlsoft::snprintf(&buff[0], buff.size(), "\033[1;%dm%s\033[0m", XTESTS_ANSI_FG_BLUE_, name);
            int const buf_size  =   static_cast<int>(buff.size());

            STLSOFT_ASSERT(n < 0 || n == (buf_size - 1));

            if (n >= 0 && n < buf_size)
            {
                return stlsoft::string_view(buff.data(), static_cast<size_t>(n));
            }
        }

        return stlsoft::string_view(name, cchName);
    }

    char const*
    xtests_success_or_failure_(
        int     succeeded
    ,   char  (&buff)[101]
    ,   int     is_tty
    )
    {
        char const* const response = succeeded ? "SUCCESS" : "FAILURE";

        if (is_tty)
        {
            stlsoft::snprintf(&buff[0], 101, "\033[1;%dm%s\033[0m", succeeded ? XTESTS_ANSI_FG_GREEN_ : XTESTS_ANSI_FG_RED_, response);
        }
        else
        {
            strcpy(&buff[0], response);
        }

        return &buff[0];
    }

    char const*
    relation_equals_(
        xtests_comparison_t comparison
    )
    {
        char const* fmt;

        switch (comparison)
        {
        case xtestsComparisonEqual:                 fmt = "be equal to";                    break;
        case xtestsComparisonNotEqual:              fmt = "be not equal to";                break;
        case xtestsComparisonGreaterThan:           fmt = "be greater than";                break;
        case xtestsComparisonLessThan:              fmt = "be less than";                   break;
        case xtestsComparisonGreaterThanOrEqual:    fmt = "be greater than or equal to";    break;
        case xtestsComparisonLessThanOrEqual:       fmt = "be less than or equal to";       break;
        case xtestsComparisonApproxEqual:           fmt = "be approximately equal to";      break;
        case xtestsComparisonApproxNotEqual:        fmt = "be not approximately equal to";  break;
        default:

            xtests_abend("VIOLATION: invalid `comparison`");
            break;
        }

        return fmt;
    }

#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
} // anonymous namespace
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * API implementation
 */

XTESTS_CALL(int)
xtests_startRunner(
    char const*         name
,   int                 verbosity
,   xTests_Reporter_t*  reporter
,   void*               reporterParam
,   FILE*               stm
,   int                 flags
,   xTests_Setup_t      setup
,   xTests_Teardown_t   teardown
,   void*               setupParam
)
{
    STLSOFT_MESSAGE_ASSERT("Runner already initialised in this process!", NULL == s_runner);

    XTESTS_EXCEPTION_TRY_

        s_runner = new RunnerInfo(name, verbosity, reporter, reporterParam, stm, flags, setup, teardown, setupParam);

        if (NULL == s_runner)
        {
            return -2;
        }
        else
        {
            s_runner->PrintStart();

            return 0;
        }

    XTESTS_EXCEPTION_CATCH_RETURN_int_
}

XTESTS_CALL(int)
xtests_endRunner(int *retCode)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    /* Bit of Null Object Pattern (Variable Variant) to assist */

    int retCode_ = EXIT_SUCCESS;

    if (NULL == retCode)
    {
        retCode = &retCode_;
    }

    s_runner->PrintEnd();

    if (0 != s_runner->NumberOfFailedTestCases() &&
        EXIT_SUCCESS == *retCode)
    {
        *retCode = EXIT_FAILURE;
    }

    delete s_runner;

    s_runner = NULL;

    return *retCode;
}

XTESTS_CALL(void)
xtests_printRunnerResults()
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    s_runner->PrintResults();
}

XTESTS_CALL(void)
xtests_abend(char const* message)
{
    XTESTS_EXCEPTION_TRY_

        if (NULL != s_runner)
        {
            s_runner->onAbend(message);

            delete s_runner;

            s_runner = NULL;
        }

        xtests_output_(xtestsAlert, message);

    XTESTS_EXCEPTION_CATCH_QUENCH_ALL_

    ::exit(EXIT_FAILURE);
}

XTESTS_CALL(int)
xtests_beginTestCase(
    char const* name
,   char const* description
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->BeginCase(name, description);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot create test", "Cannot create test")
}

XTESTS_CALL(void*)
xtests_getSetupParam(void)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    return s_runner->GetSetupParam();
}

XTESTS_CALL(int)
xtests_endTestCase(char const* name)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->EndCase(name);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot end test", "Cannot end test")
}

XTESTS_CALL(int)
xtests_testPassed(
    char const* file
,   int         line
,   char const* function
,   char const* expr
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        s_runner->RegisterSuccessfulCondition(file, line, function, expr);

        return 1;

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(void)
xtests_caseExcepted(
    char const* file
,   int         line
,   char const* exceptionType
,   char const* exceptionMessage
)
{
    STLSOFT_ASSERT(NULL != exceptionType);
    STLSOFT_ASSERT(NULL != exceptionMessage);

    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    // Remove leading "class "
    if (exceptionType == ::strstr(exceptionType, "class "))
    {
        exceptionType += 6;
    }

    s_runner->CaseExcepted(file, line, exceptionType, exceptionMessage);
}

XTESTS_CALL(void)
xtests_caseExceptionExpected(
    char const* file
,   int         line
,   char const* exceptionType
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    s_runner->CaseExceptionExpected(file, line, exceptionType);
}

XTESTS_CALL(int)
xtests_testFailed(
    char const* file
,   int         line
,   char const* function
,   char const* expr
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->RegisterFailedCondition(file, line, function, expr);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_floatingPointClose(
    double  expected
,   double  actual
)
{
    if (expected == actual)
    {
        return 1;
    }
    else if (0.0 == expected)
    {
        return 0;
    }
    else
    {
        double result = actual / expected;

        if (result > (2.0 - s_fpApproximateFactor) &&
            result < s_fpApproximateFactor)
        {
            return true;
        }
    }

    return 0;
}

XTESTS_CALL(double)
xtests_setFloatingPointCloseFactor(
    double  factor
,   double* old /* = NULL */
)
{
    STLSOFT_ASSERT(0.0 != factor);
    STLSOFT_ASSERT(factor >= 1.0 && factor < 2.0);

    double  old_ = s_fpApproximateFactor;

    s_fpApproximateFactor = factor;

    if (NULL != old)
    {
        *old = old_;
    }

    return old_;
}

XTESTS_CALL(int)
xtests_testFailed_int(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   int                 expected
,   int                 actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->RegisterFailedCondition_long(file, line, function, expr, static_cast<long>(expected), static_cast<long>(actual), comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testFailed_long(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   long                expected
,   long                actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->RegisterFailedCondition_long(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testFailed_ulong(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   unsigned long       expected
,   unsigned long       actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->RegisterFailedCondition_ulong(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

XTESTS_CALL(int)
xtests_testFailed_longlong(
    char const*                     file
,   int                             line
,   char const*                     function
,   char const*                     expr
,   STLSOFT_NS_QUAL(ss_sint64_t)    expected
,   STLSOFT_NS_QUAL(ss_sint64_t)    actual
,   xtests_comparison_t             comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->RegisterFailedCondition_sint64(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testFailed_ulonglong(
    char const*                    file
,   int                             line
,   char const*                     function
,   char const*                     expr
,   STLSOFT_NS_QUAL(ss_uint64_t)    expected
,   STLSOFT_NS_QUAL(ss_uint64_t)    actual
,   xtests_comparison_t             comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->RegisterFailedCondition_uint64(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

XTESTS_CALL(int)
xtests_testFailed_boolean(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   int                 expected
,   int                 actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->RegisterFailedCondition_boolean(file, line, function, expr, 0 != expected, 0 != actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testFailed_double(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   double              expected
,   double              actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->RegisterFailedCondition_double(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testMultibyteStrings(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestMultibyteStrings(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

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
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestMultibyteStringsN(file, line, function, expr, expected, actual, n, cchExpected, cchActual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

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
)
{
    return xtests_testMultibyteStringsN_(
        file
    ,   line
    ,   function
    ,   expr
    ,   expected
    ,   actual
    ,   n
    ,   (0 != n && NULL != expected) ? ::strlen(expected) : 0u
    ,   (0 != n && NULL != actual) ? xtests_strnlen_(actual, static_cast<size_t>(::abs(static_cast<int>(n)))) : 0u
    ,   comp);
}

XTESTS_CALL(int)
xtests_testWideStrings(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestWideStrings(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testWideStringsN_(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   int                 n /* exact if +ve; limit if -ve */
,   size_t              cchExpected
,   size_t              cchActual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestWideStringsN(file, line, function, expr, expected, actual, n, cchExpected, cchActual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

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
)
{
    return xtests_testWideStringsN_(
        file
    ,   line
    ,   function
    ,   expr
    ,   expected
    ,   actual
    ,   n
    ,   (0 != n && NULL != expected) ? ::wcslen(expected) : 0u
    ,   (0 != n && NULL != actual) ? xtests_wcsnlen_(actual, static_cast<size_t>(::abs(n))) : 0u
    ,   comp);
}

XTESTS_CALL(int)
xtests_testMultibyteStringContains(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestMultibyteStringContains(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testWideStringContains(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestWideStringContains(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

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
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

    return s_runner->TestMultibyteStringSlice(file, line, function, expr, expectedLen, expectedPtr, actualLen, actualPtr, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

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
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

    return s_runner->TestWideStringSlice(file, line, function, expr, expectedLen, expectedPtr, actualLen, actualPtr, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testPointers(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   void volatile const*    expected
,   void volatile const*    actual
,   xtests_comparison_t     comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestPointers(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testFunctionPointers(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   void                    (*expected)(void)
,   void                    (*actual)(void)
,   xtests_comparison_t     comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestFunctionPointers(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testCharactersA(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char                expected
,   char                actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestCharacters(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_testCharactersW(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t             expected
,   wchar_t             actual
,   xtests_comparison_t comp
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->TestCharacters(file, line, function, expr, expected, actual, comp);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xtests_writeFailMessage(
    char const* file
,   int         line
,   char const* function
,   char const* message
,   char const* qualifyingInformation
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->WriteFailMessage(file, line, function, message, qualifyingInformation);

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}


XTESTS_CALL(int)
xtests_require_C(
    int success
)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        if (!success)
        {
            s_runner->OnRequireFailed();
        }

        return success;

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}

XTESTS_CALL(int)
xTests_hasRequiredConditionFailed(void)
{
    STLSOFT_MESSAGE_ASSERT("runner not initialised in this process!", NULL != s_runner);

    XTESTS_EXCEPTION_TRY_

        return s_runner->HasRequiredConditionFailed();

    XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_("cannot update test", "Cannot update test")
}


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

XTESTS_CALL(int)
xtests_commandLine_parseVerbosity(
    int     argc
,   char*   argv[]
,   int*    verbosity
)
{
    STLSOFT_ASSERT(NULL != verbosity);

    *verbosity = XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR;

    static const char   s_verb[]    =   "--verbosity=";
    static const size_t s_cchVerb   =   STLSOFT_NUM_ELEMENTS(s_verb) - 1;

    { for (int i = 1; i < argc; ++i)
    {
        STLSOFT_ASSERT(NULL != argv[i]);

        if (argv[i] == ::strstr(argv[i], s_verb))
        {
            char*   endptr;
            long    l = ::strtol(argv[i] + s_cchVerb, &endptr, 0);

            *verbosity = static_cast<int>(l);

            return 1;
        }
    }}

    /* at this point, "--verbosity=???" has not been specified, so consult
     * environment variable(s):
     *
     * - "XTESTS_VERBOSITY";
     * - "TEST_VERBOSITY";
     */

    static char const* const ENVIRONMENT_VARIABLES[] =
    {
        "XTESTS_VERBOSITY",
        "TEST_VERBOSITY",
    };

    for (unsigned i = 0; i != STLSOFT_NUM_ELEMENTS(ENVIRONMENT_VARIABLES); ++i)
    {

        platformstl::environment_variable envvar(ENVIRONMENT_VARIABLES[i]);

        if (!envvar.empty())
        {
            char*   endptr;
            long    l = ::strtol(envvar, &endptr, 0);

            *verbosity = static_cast<int>(l);

            return 1;
        }
    }

    return 0;
}

XTESTS_CALL(void)
xtests_commandLine_parseHelp(
    int     argc
,   char*   argv[]
,   FILE*   stm
,   int     exitCode
)
{
    static const char   s_verb[]    =   "--help";

    { for (int i = 1; i < argc; ++i)
    {
        STLSOFT_ASSERT(NULL != argv[i]);

        if (0 == ::strcmp(argv[i], s_verb))
        {
#ifdef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS

            STLSOFT_NS_USING(stlsoft_C_string_slice_a_t)
            PLATFORMSTL_NS_USING(platformstl_C_get_executable_name_from_path)

            stlsoft_C_string_slice_a_t const exe_name = platformstl_C_get_executable_name_from_path(argv[0]);
#else

            struct
            {
                size_t      len;
                char const* ptr;
            } exe_name = { ::strlen(argv[0]), argv[0] };
#endif

            ::fprintf(
                stm
            ,   "USAGE: %.*s [ --help | --verbosity=<verbosity> ]\n"
                "\n"
                "where:\n"
                "\t--help                  - displays this help and terminates\n"
                "\t--verbosity=<verbosity> - executes the tests with the given\n"
                "\t                          <verbosity>, which may be between\n"
                "\t                          -1 and 4 (inclusive). The values\n"
                "\t                          are interpreted as:\n"
                "\n"
                "\t                            -1 - no output\n"
                "\t                             0 - summary only on fail\n"
                "\t                             1 - summary only\n"
                "\t                             2 - summary and first failed case\n"
                "\t                             3 - summary and all failed cases\n"
                "\t                             4 - summary and all cases\n"
            ,   int(exe_name.len)
            ,   exe_name.ptr
            );

            ::exit(exitCode);
        }
    }}
}


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

xtests_variable_value_t::xtests_variable_value_t(bool b)
    : booleanValue(b)
{}

xtests_variable_value_t::xtests_variable_value_t(int i)
    : intValue(i)
{}

xtests_variable_value_t::xtests_variable_value_t(long i)
    : longValue(i)
{}

xtests_variable_value_t::xtests_variable_value_t(unsigned long i)
    : ulongValue(i)
{}
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

xtests_variable_value_t::xtests_variable_value_t(sint64_t const& i)
    : longlongValue(i)
{}

xtests_variable_value_t::xtests_variable_value_t(uint64_t const& i)
    : ulonglongValue(i)
{}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

xtests_variable_value_t::xtests_variable_value_t(char ch)
    : multibyteCharacterValue(ch)
{}

xtests_variable_value_t::xtests_variable_value_t(wchar_t ch, xtests_variable_type_t)
    : wideCharacterValue(ch)
{}

xtests_variable_value_t::xtests_variable_value_t(double const& d)
    : doubleValue(d)
{}

xtests_variable_value_t::xtests_variable_value_t(void const volatile* pv)
    : opaquePointerValue(pv)
{}

xtests_variable_value_t::xtests_variable_value_t(char const* s)
    : multibyteStringValue(s)
{}

xtests_variable_value_t::xtests_variable_value_t(wchar_t const* s)
    : wideStringValue(s)
{}


xtests_variable_t::xtests_variable_t(bool b)
    : variableType(xtestsVariableBoolean)
    , testType(xtestsTestFullComparison)
    , value(b)
    , valueLen(0u)
{}

xtests_variable_t::xtests_variable_t(char ch)
    : variableType(xtestsVariableMultibyteCharacter)
    , testType(xtestsTestFullComparison)
    , value(ch)
    , valueLen(0u)
{}

xtests_variable_t::xtests_variable_t(wchar_t ch, xtests_variable_type_t /* type */)
    : variableType(xtestsVariableWideCharacter)
    , testType(xtestsTestFullComparison)
    , value(ch, xtestsVariableWideCharacter)
    , valueLen(0u)
{}

xtests_variable_t::xtests_variable_t(long i)
    : variableType(xtestsVariableLong)
    , testType(xtestsTestFullComparison)
    , value(i)
    , valueLen(0u)
{}

xtests_variable_t::xtests_variable_t(unsigned long i)
    : variableType(xtestsVariableUnsignedLong)
    , testType(xtestsTestFullComparison)
    , value(i)
    , valueLen(0u)
{}
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

xtests_variable_t::xtests_variable_t(sint64_t const& i)
    : variableType(xtestsVariableLongLong)
    , testType(xtestsTestFullComparison)
    , value(i)
    , valueLen(0u)
{}

xtests_variable_t::xtests_variable_t(uint64_t const& i)
    : variableType(xtestsVariableUnsignedLongLong)
    , testType(xtestsTestFullComparison)
    , value(i)
    , valueLen(0u)
{}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

xtests_variable_t::xtests_variable_t(double const& d)
    : variableType(xtestsVariableDouble)
    , testType(xtestsTestFullComparison)
    , value(d)
    , valueLen(0u)
{}

xtests_variable_t::xtests_variable_t(void const volatile* pv)
    : variableType(xtestsVariableOpaquePointer)
    , testType(xtestsTestFullComparison)
    , value(pv)
    , valueLen(0u)
{}

xtests_variable_t::xtests_variable_t(char const* s, xtests_test_type_t testType)
    : variableType(xtestsVariableMultibyteString)
    , testType(testType)
    , value(s)
    , valueLen(::stlsoft::c_str_len_a(s))
{}

xtests_variable_t::xtests_variable_t(wchar_t const* s, xtests_test_type_t testType)
    : variableType(xtestsVariableWideString)
    , testType(testType)
    , value(s)
    , valueLen(::stlsoft::c_str_len_w(s))
{}

xtests_variable_t::xtests_variable_t(char const* s, size_t n, xtests_test_type_t testType)
    : variableType(xtestsVariableMultibyteString)
    , testType(testType)
    , value(s)
    , valueLen(n)
{}

xtests_variable_t::xtests_variable_t(wchar_t const* s, size_t n, xtests_test_type_t testType)
    : variableType(xtestsVariableWideString)
    , testType(testType)
    , value(s)
    , valueLen(n)
{}

#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
namespace
{
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */

/* static */
xTests_Reporter_t*
RunnerInfo::get_reporter_(
    xTests_Reporter_t*  reporter
,   FILE*               stm
,   int                 flags
,   int                 is_tty
)
{
#ifdef STLSOFT_COMPILER_IS_BORLAND

# define XTESTS_VERBOSITY_SILENT                            ::xtests::c::XTESTS_VERBOSITY_SILENT
# define XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR           ::xtests::c::XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR
# define XTESTS_VERBOSITY_RUNNER_SUMMARY                    ::xtests::c::XTESTS_VERBOSITY_RUNNER_SUMMARY
# define XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR       ::xtests::c::XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR
# define XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR             ::xtests::c::XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR
# define XTESTS_VERBOSITY_CASE_SUMMARY                      ::xtests::c::XTESTS_VERBOSITY_CASE_SUMMARY
# define XTESTS_VERBOSITY_VERBOSE                           ::xtests::c::XTESTS_VERBOSITY_VERBOSE
# define xtestsRunnerFlagsNoWindowsDebugString              ::xtests::c::xtestsRunnerFlagsNoWindowsDebugString
# define xtests_variable_type_t                             ::xtests::c::xtests_variable_type_t
# define xtests_test_type_t                                 ::xtests::c::xtests_test_type_t

# define xtestsComparisonEqual                              ::xtests::c::xtestsComparisonEqual
# define xtestsComparisonNotEqual                           ::xtests::c::xtestsComparisonNotEqual
# define xtestsComparisonGreaterThan                        ::xtests::c::xtestsComparisonGreaterThan
# define xtestsComparisonLessThan                           ::xtests::c::xtestsComparisonLessThan
# define xtestsComparisonGreaterThanOrEqual                 ::xtests::c::xtestsComparisonGreaterThanOrEqual
# define xtestsComparisonLessThanOrEqual                    ::xtests::c::xtestsComparisonLessThanOrEqual
# define xtestsComparisonApproxEqual                        ::xtests::c::xtestsComparisonApproxEqual
# define xtestsComparisonApproxNotEqual                     ::xtests::c::xtestsComparisonApproxNotEqual
# define xtestsComparison_max_enumerator                    ::xtests::c::xtestsComparison_max_enumerator

# define xtestsTestFullComparison                           ::xtests::c::xtestsTestFullComparison
# define xtestsTestPartialComparison                        ::xtests::c::xtestsTestPartialComparison
# define xtestsTestContainment                              ::xtests::c::xtestsTestContainment

# define xtestsVariableNone                                 ::xtests::c::xtestsVariableNone
# define xtestsVariableBoolean                              ::xtests::c::xtestsVariableBoolean
# define xtestsVariableOpaquePointer                        ::xtests::c::xtestsVariableOpaquePointer
# define xtestsVariableMultibyteCharacter                   ::xtests::c::xtestsVariableMultibyteCharacter
# define xtestsVariableWideCharacter                        ::xtests::c::xtestsVariableWideCharacter
# define xtestsVariableMultibyteString                      ::xtests::c::xtestsVariableMultibyteString
# define xtestsVariableWideString                           ::xtests::c::xtestsVariableWideString
# define xtestsVariableSignedChar                           ::xtests::c::xtestsVariableSignedChar
# define xtestsVariableUnsignedChar                         ::xtests::c::xtestsVariableUnsignedChar
# define xtestsVariableShort                                ::xtests::c::xtestsVariableShort
# define xtestsVariableUnsignedShort                        ::xtests::c::xtestsVariableUnsignedShort
# define xtestsVariableInt                                  ::xtests::c::xtestsVariableInt
# define xtestsVariableUnsignedInt                          ::xtests::c::xtestsVariableUnsignedInt
# define xtestsVariableLong                                 ::xtests::c::xtestsVariableLong
# define xtestsVariableUnsignedLong                         ::xtests::c::xtestsVariableUnsignedLong
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
#  define xtestsVariableLongLong                            ::xtests::c::xtestsVariableLongLong
#  define xtestsVariableUnsignedLongLong                    ::xtests::c::xtestsVariableUnsignedLongLong
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
# define xtestsVariableDouble                               ::xtests::c::xtestsVariableDouble

# define adapt_fputs                                        ::xtests::c::adapt_fputs
# define adapt_OutputDebugStringA                           ::xtests::c::adapt_OutputDebugStringA
#endif /* STLSOFT_COMPILER_IS_BORLAND */

    if (NULL == reporter)
    {
        if (NULL == stm)
        {
            stm = stdout;
        }

        // NOTE: Even though this is thread-unsafe in that there's a race
        // condition for the initialisation of the s_reporter instance (and
        // its vtable), there is no problem because multiple initialisation
        // will be benign.

        class fprintf_reporter
            : public xTests_Reporter_t
        {
        public: // construction
            explicit fprintf_reporter(
                FILE*   stm
            ,   int     flags
            ,   int     is_tty
            )
                : m_flags(flags)
                , is_tty(is_tty)
#if XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_
                , m_numSinks((xtestsRunnerFlagsNoWindowsDebugString & flags) ? 1u : 2u)
#else /* ? XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ */
                , m_numSinks(1)
#endif /* XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ */
            {
                m_sinks[0].pfn      =   adapt_fputs;
                m_sinks[0].param    =   stm;

#if XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_

                if (0 == (xtestsRunnerFlagsNoWindowsDebugString & m_flags))
                {
                    m_sinks[1].pfn      =   adapt_OutputDebugStringA;
                    m_sinks[1].param    =   NULL;
                }
#else /* ? XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ */

                STLSOFT_SUPPRESS_UNUSED(m_flags);
#endif /* XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ */
            }
        private:
            void operator =(fprintf_reporter const&) STLSOFT_COPY_ASSIGNMENT_PROSCRIBED;

        private: // overrides
            virtual void
            onStartRunner(
                void* /* reporterParam */
            ,   char const* name
            ,   int verbosity
            ) ss_override_k
            {
                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:

                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    {
                        char_buffer_t_  name_buff(0);

                        xtests_mxnprintf_( m_sinks, m_numSinks, stlsoft::c_str_len(name)
                        ,   "Test runner '%s' starting:\n"
                        ,   xtests_name_(name_buff, name, is_tty).data()
                        );
                    }
                    break;
                }
            }

            virtual void
            onBeginTestCase(
                void* /* reporterParam */
            ,   char const* /* name */
            ,   char const* /* desc */
            ,   int /* verbosity */
            ) ss_override_k
            {
            }

            virtual void
            onTestPassed(
                void* /* reporterParam */
            ,   char const* /* file */
            ,   int /* line */
            ,   char const* /* function */
            ,   char const* /* expr */
            ,   xtests_comparison_t /* comparison */
            ,   int /* verbosity */
            ) ss_override_k
            {
            }

            virtual void
            onTestFailed(
                void*                       /* reporterParam */
            ,   char const*                 file
            ,   int                         line
            ,   char const*                 function
            ,   char const*                 expr
            ,   xtests_variable_t const*    expectedValue
            ,   xtests_variable_t const*    actualValue
            ,   ptrdiff_t                   length
            ,   xtests_comparison_t         comparison
            ,   int                         verbosity
            ) ss_override_k
            {
                STLSOFT_MESSAGE_ASSERT("values must have same variable type", NULL == expectedValue || NULL == actualValue || actualValue->variableType == expectedValue->variableType);
                STLSOFT_MESSAGE_ASSERT("values must have same test type", NULL == expectedValue || NULL == actualValue || actualValue->testType == expectedValue->testType);

                xtests_variable_type_t variableType = xtestsVariableNone;

                if (NULL != expectedValue)
                {
                    variableType = expectedValue->variableType;
                }

                xtests_test_type_t testType = xtestsTestFullComparison;

                if (NULL != expectedValue)
                {
                    testType = expectedValue->testType;
                }

                switch (variableType)
                {
                case xtestsVariableBoolean:

                    onTestFailed_Boolean_(file, line, function, expr, static_cast<bool>(0 != expectedValue->value.booleanValue), static_cast<bool>(0 != actualValue->value.booleanValue), comparison, verbosity, is_tty);
                    break;
                case xtestsVariableOpaquePointer:

                    onTestFailed_OpaquePointer_(file, line, function, expr, expectedValue->value.opaquePointerValue, actualValue->value.opaquePointerValue,  comparison, verbosity, is_tty);
                    break;
                case xtestsVariableMultibyteCharacter:

                    onTestFailed_MultibyteCharacter_(file, line, function, expr, expectedValue->value.multibyteCharacterValue, actualValue->value.multibyteCharacterValue,  comparison, verbosity, is_tty);
                    break;
                case xtestsVariableWideCharacter:

                    onTestFailed_WideCharacter_(file, line, function, expr, expectedValue->value.wideCharacterValue, actualValue->value.wideCharacterValue,  comparison, verbosity, is_tty);
                    break;
                case xtestsVariableMultibyteString:

                    onTestFailed_MultibyteString_(file, line, function, expr, expectedValue->value.multibyteStringValue, expectedValue->valueLen, actualValue->value.multibyteStringValue, actualValue->valueLen, length, testType,  comparison, verbosity, is_tty);
                    break;
                case xtestsVariableWideString:

                    onTestFailed_WideString_(file, line, function, expr, expectedValue->value.wideStringValue, expectedValue->valueLen, actualValue->value.wideStringValue, actualValue->valueLen, length, testType,  comparison, verbosity, is_tty);
                    break;
                case xtestsVariableLong:

                    onTestFailed_SignedLong_(file, line, function, expr, expectedValue->value.longValue, actualValue->value.longValue,  comparison, verbosity, is_tty);
                    break;
                case xtestsVariableUnsignedLong:

                    onTestFailed_UnsignedLong_(file, line, function, expr, expectedValue->value.ulongValue, actualValue->value.ulongValue,  comparison, verbosity, is_tty);
                    break;
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

                case xtestsVariableLongLong:

                    onTestFailed_sint64_(file, line, function, expr, expectedValue->value.longlongValue, actualValue->value.longlongValue,  comparison, verbosity, is_tty);
                    break;
                case xtestsVariableUnsignedLongLong:

                    onTestFailed_uint64_(file, line, function, expr, expectedValue->value.ulonglongValue, actualValue->value.ulonglongValue,  comparison, verbosity, is_tty);
                    break;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
                case xtestsVariableDouble:

                    onTestFailed_Double_(file, line, function, expr, expectedValue->value.doubleValue, actualValue->value.doubleValue,  comparison, verbosity, is_tty);
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("not currently defined for this type", 0);
                case xtestsVariableNone:

                    onTestFailed_(file, line, function, expr,  comparison, verbosity, is_tty);
                    break;
                }
            }

            void
            onTestFailed_Boolean_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   bool                expectedValue
            ,   bool                actualValue
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
                static char const*  s_truthy_strings[] =
                {
                    "false"
                ,   "true"
                };


                std::string     fmt_;

                fmt_ += "%s(%d): test condition failed: ";

                // actual
                if (is_tty)
                {
                    fmt_ += "actual value \033[1;35m%s\033[0m";
                }
                else
                {
                    fmt_ += "actual value %s";
                }

                fmt_ += " should ";

                // comparison
                if (is_tty)
                {
                    fmt_ += "\033[1;36m";
                }
                fmt_ += relation_equals_(comparison);
                if (is_tty)
                {
                    fmt_ += "\033[0m";
                }

                // expected
                if (is_tty)
                {
                    fmt_ += " the expected value \033[1;35m%s\033[0m";
                }
                else
                {
                    fmt_ += " the expected value %s";
                }

                // function (?)
                if (is_tty)
                {
                    fmt_ += "%s\033[1;36m%s\033[0m";
                }
                else
                {
                    fmt_ += "%s%s";
                }

                // EOL
                fmt_ += '\n';

                char const*     fmt =   fmt_.c_str();

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   s_truthy_strings[!!actualValue]
                                ,   s_truthy_strings[!!expectedValue]
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }

            void
            onTestFailed_Double_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   double const&       expectedValue
            ,   double const&       actualValue
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
                std::string     fmt_;

                fmt_ += "%s(%d): test condition failed: ";

                // actual
                if (is_tty)
                {
                    fmt_ += "actual value \033[1;35m%G\033[0m";
                }
                else
                {
                    fmt_ += "actual value %G";
                }

                fmt_ += " should ";

                // comparison
                if (is_tty)
                {
                    fmt_ += "\033[1;36m";
                }
                fmt_ += relation_equals_(comparison);
                if (is_tty)
                {
                    fmt_ += "\033[0m";
                }

                // expected
                if (is_tty)
                {
                    fmt_ += " the expected value \033[1;35m%G\033[0m";
                }
                else
                {
                    fmt_ += " the expected value %G";
                }

                // function (?)
                if (is_tty)
                {
                    fmt_ += "%s\033[1;36m%s\033[0m";
                }
                else
                {
                    fmt_ += "%s%s";
                }

                // EOL
                fmt_ += '\n';

                char const*     fmt =   fmt_.c_str();

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   actualValue
                                ,   expectedValue
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }

            void
            onTestFailed_MultibyteCharacter_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   char                expectedValue
            ,   char                actualValue
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
                std::string     fmt_;

                fmt_ += "%s(%d): test condition failed: ";

                // actual
                if (is_tty)
                {
                    fmt_ += "actual character value '\033[1;35m%c\033[0m' (0x%02x)";
                }
                else
                {
                    fmt_ += "actual character value '%c' (0x%02x)";
                }

                fmt_ += " should ";

                // comparison
                if (is_tty)
                {
                    fmt_ += "\033[1;36m";
                }
                fmt_ += relation_equals_(comparison);
                if (is_tty)
                {
                    fmt_ += "\033[0m";
                }

                // expected
                if (is_tty)
                {
                    fmt_ += " the expected value '\033[1;35m%c\033[0m' (0x%02x)";
                }
                else
                {
                    fmt_ += " the expected value '%c' (0x%02x)";
                }

                // function (?)
                if (is_tty)
                {
                    fmt_ += "%s\033[1;36m%s\033[0m";
                }
                else
                {
                    fmt_ += "%s%s";
                }

                // EOL
                fmt_ += '\n';

                char const*     fmt =   fmt_.c_str();

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   actualValue, actualValue
                                ,   expectedValue, expectedValue
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }

            void
            onTestFailed_WideCharacter_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   wchar_t             expectedValue
            ,   wchar_t             actualValue
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
                static char const*  s_fmts[] =
                {
                        "%s(%d): test condition failed: actual character value '%C' (0x%04x) should "   "be equal to"                   " the expected value '%C' (0x%04x)%s%s\n"
                    ,   "%s(%d): test condition failed: actual character value '%C' (0x%04x) should "   "be not equal to"               " the expected value '%C' (0x%04x)%s%s\n"
                    ,   "%s(%d): test condition failed: actual character value '%C' (0x%04x) should "   "be greater than"               " the expected value '%C' (0x%04x)%s%s\n"
                    ,   "%s(%d): test condition failed: actual character value '%C' (0x%04x) should "   "be less than"                  " the expected value '%C' (0x%04x)%s%s\n"
                    ,   "%s(%d): test condition failed: actual character value '%C' (0x%04x) should "   "be greater than or equal to"   " the expected value '%C' (0x%04x)%s%s\n"
                    ,   "%s(%d): test condition failed: actual character value '%C' (0x%04x) should "   "be less than or equal to"      " the expected value '%C' (0x%04x)%s%s\n"
                    ,   "%s(%d): test condition failed: actual character value '%C' (0x%04x) should "   "be approximately equal to"     " the expected value '%C' (0x%04x)%s%s\n"
                    ,   "%s(%d): test condition failed: actual character value '%C' (0x%04x) should "   "be not approximately equal to" " the expected value '%C' (0x%04x)%s%s\n"
                };
                STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS_(s_fmts) == xtestsComparison_max_enumerator);
                char const*         fmt = s_fmts[comparison];

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   static_cast<char>(actualValue), actualValue
                                ,   static_cast<char>(expectedValue), expectedValue
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }

            void
            onTestFailed_MultibyteString_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   char const*         expectedValue
            ,   size_t              expectedValueLen
            ,   char const*         actualValue
            ,   size_t              actualValueLen
            ,   ptrdiff_t           length
            ,   xtests_test_type_t  testType
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
                // eliminate NULL pointers
                expectedValue   =   stlsoft::c_str_ptr_a(expectedValue);
                actualValue     =   stlsoft::c_str_ptr_a(actualValue);

                if (xtestsTestFullComparison == testType)
                {
                    std::string     fmt_;

                    fmt_ += "%s(%d): test condition failed: ";

                    // actual
                    if (is_tty)
                    {
                        fmt_ += "actual string value '\033[1;35m%s\033[0m'";
                    }
                    else
                    {
                        fmt_ += "actual string value '%s'";
                    }

                    fmt_ += " should ";

                    // comparison
                    if (is_tty)
                    {
                        fmt_ += "\033[1;36m";
                    }
                    fmt_ += relation_equals_(comparison);
                    if (is_tty)
                    {
                        fmt_ += "\033[0m";
                    }

                    // expected
                    if (is_tty)
                    {
                        fmt_ += " the expected value '\033[1;35m%s\033[0m'";
                    }
                    else
                    {
                        fmt_ += " the expected value '%s'";
                    }

                    // function (?)
                    if (is_tty)
                    {
                        fmt_ += "%s\033[1;36m%s\033[0m";
                    }
                    else
                    {
                        fmt_ += "%s%s";
                    }

                    // EOL
                    fmt_ += '\n';

                    char const*     fmt =   fmt_.c_str();

                    switch (verbosity)
                    {
                    case XTESTS_VERBOSITY_SILENT:
                    case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                        fmt = "";
                        break;
                    default:

                        STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                    case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_CASE_SUMMARY:
                    XTESTS_VERBOSITY_VALID_MISSING_CASES
                    case XTESTS_VERBOSITY_VERBOSE:

                        break;
                    }

                    xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                    ,   fmt
                                    ,   file, line
                                    ,   actualValue
                                    ,   expectedValue
                                    ,   (NULL != function) ? " in function " : ""
                                    ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                    );
                }
                else if (xtestsTestPartialComparison == testType)
                {
                    std::string     fmt_;

                    fmt_ += "%s(%d): test condition failed: ";

                    // actual
                    if (is_tty)
                    {
                        fmt_ += "actual string value '\033[1;35m%.*s\033[0m'";
                    }
                    else
                    {
                        fmt_ += "actual string value '%.*s'";
                    }

                    fmt_ += " should ";

                    // comparison
                    if (is_tty)
                    {
                        fmt_ += "\033[1;36m";
                    }
                    fmt_ += relation_equals_(comparison);
                    if (is_tty)
                    {
                        fmt_ += "\033[0m";
                    }

                    // expected
                    if (is_tty)
                    {
                        fmt_ += " the expected value '\033[1;35m%.*s\033[0m'";
                    }
                    else
                    {
                        fmt_ += " the expected value '%.*s'";
                    }

                    //  to the length %d
                    if (is_tty)
                    {
                        fmt_ += " to the length \033[1;35m%d\033[0m";
                    }
                    else
                    {
                        fmt_ += " to the length %d";
                    }

                    // function (?)
                    if (is_tty)
                    {
                        fmt_ += "%s\033[1;36m%s\033[0m";
                    }
                    else
                    {
                        fmt_ += "%s%s";
                    }

                    // EOL
                    fmt_ += '\n';

                    char const*     fmt =   fmt_.c_str();

                    switch (verbosity)
                    {
                    case XTESTS_VERBOSITY_SILENT:
                    case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                        fmt = "";
                        break;
                    default:

                        STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                    case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_CASE_SUMMARY:
                    XTESTS_VERBOSITY_VALID_MISSING_CASES
                    case XTESTS_VERBOSITY_VERBOSE:

                        break;
                    }

                    if (length < 0)
                    {
                        length = -length;
                    }

                    xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                    ,   fmt
                                    ,   file, line
                                    ,   int(actualValueLen), actualValue
                                    ,   int(expectedValueLen), expectedValue
                                    ,   length
                                    ,   (NULL != function) ? " in function " : ""
                                    ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                    );
                }
                else if (xtestsTestContainment == testType)
                {
                    std::string     fmt_;

                    fmt_ += "%s(%d): test condition failed: ";

                    // actual
                    if (is_tty)
                    {
                        fmt_ += "actual string value '\033[1;35m%s\033[0m'";
                    }
                    else
                    {
                        fmt_ += "actual string value '%s'";
                    }

                    fmt_ += " should ";

                    // comparison
                    if (is_tty)
                    {
                        fmt_ += "\033[1;36m";
                    }
                    switch (comparison)
                    {
                    case xtestsComparisonEqual:                 fmt_ += "contain";                      break;
                    case xtestsComparisonNotEqual:              fmt_ += "not contain";                  break;
                    case xtestsComparisonGreaterThan:           fmt_ += "";                             break;
                    case xtestsComparisonLessThan:              fmt_ += "";                             break;
                    case xtestsComparisonGreaterThanOrEqual:    fmt_ += "";                             break;
                    case xtestsComparisonLessThanOrEqual:       fmt_ += "";                             break;
                    case xtestsComparisonApproxEqual:           fmt_ += "contain approximately";        break;
                    case xtestsComparisonApproxNotEqual:        fmt_ += "not contain approximately";    break;
                    default:

                        xtests_abend("VIOLATION: invalid `comparison`");
                        break;
                    }
                    if (is_tty)
                    {
                        fmt_ += "\033[0m";
                    }

                    // expected
                    if (is_tty)
                    {
                        fmt_ += " the expected value '\033[1;35m%s\033[0m'";
                    }
                    else
                    {
                        fmt_ += " the expected value '%s'";
                    }

                    // function (?)
                    if (is_tty)
                    {
                        fmt_ += "%s\033[1;36m%s\033[0m";
                    }
                    else
                    {
                        fmt_ += "%s%s";
                    }

                    // EOL
                    fmt_ += '\n';

                    char const*     fmt =   fmt_.c_str();

                    switch (verbosity)
                    {
                    case XTESTS_VERBOSITY_SILENT:
                    case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                        fmt = "";
                        break;
                    default:

                        STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                    case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                    case XTESTS_VERBOSITY_CASE_SUMMARY:
                    XTESTS_VERBOSITY_VALID_MISSING_CASES
                    case XTESTS_VERBOSITY_VERBOSE:

                        break;
                    }

                    xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                    ,   fmt
                                    ,   file, line
                                    ,   actualValue
                                    ,   expectedValue
                                    ,   (NULL != function) ? " in function " : ""
                                    ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                    );
                }
                else
                {
                    STLSOFT_MESSAGE_ASSERT("unrecognised test type", 0);
                }
            }

            void
            onTestFailed_WideString_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*         expr
            ,   wchar_t const*      expectedValue
            ,   size_t              expectedValueLen
            ,   wchar_t const*      actualValue
            ,   size_t              actualValueLen
            ,   ptrdiff_t           length
            ,   xtests_test_type_t  testType
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
                stlsoft::w2a    expected(expectedValue, expectedValueLen);
                stlsoft::w2a    actual(actualValue, actualValueLen);

                onTestFailed_MultibyteString_(file, line, function, expr, expected, expected.size(), actual, actual.size(), length, testType,  comparison, verbosity, is_tty);
            }

            void
            onTestFailed_OpaquePointer_(
                char const*             file
            ,   int                     line
            ,   char const*             function
            ,   char const*           /* expr */
            ,   void const volatile*    expectedValue
            ,   void const volatile*    actualValue
            ,   xtests_comparison_t     comparison
            ,   int                     verbosity
            ,   int                 is_tty
            )
            {
                std::string     fmt_;

                fmt_ += "%s(%d): test condition failed: ";

                // actual
                if (is_tty)
                {
                    fmt_ += "actual pointer value \033[1;35m%p\033[0m";
                }
                else
                {
                    fmt_ += "actual pointer value %p";
                }

                fmt_ += " should ";

                // comparison
                if (is_tty)
                {
                    fmt_ += "\033[1;36m";
                }
                fmt_ += relation_equals_(comparison);
                if (is_tty)
                {
                    fmt_ += "\033[0m";
                }

                // expected
                if (is_tty)
                {
                    fmt_ += " the expected value \033[1;35m%p\033[0m";
                }
                else
                {
                    fmt_ += " the expected value %p";
                }

                // function (?)
                if (is_tty)
                {
                    fmt_ += "%s\033[1;36m%s\033[0m";
                }
                else
                {
                    fmt_ += "%s%s";
                }

                // EOL
                fmt_ += '\n';

                char const*     fmt =   fmt_.c_str();

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   actualValue
                                ,   expectedValue
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }

            void
            onTestFailed_SignedLong_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   signed long         expectedValue
            ,   signed long         actualValue
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
                std::string     fmt_;

                fmt_ += "%s(%d): test condition failed: ";

                // actual
                if (is_tty)
                {
                    fmt_ += "actual value \033[1;35m%ld\033[0m";
                }
                else
                {
                    fmt_ += "actual value %ld";
                }

                fmt_ += " should ";

                // comparison
                if (is_tty)
                {
                    fmt_ += "\033[1;36m";
                }
                fmt_ += relation_equals_(comparison);
                if (is_tty)
                {
                    fmt_ += "\033[0m";
                }

                // expected
                if (is_tty)
                {
                    fmt_ += " the expected value \033[1;35m%ld\033[0m";
                }
                else
                {
                    fmt_ += " the expected value %ld";
                }

                // function (?)
                if (is_tty)
                {
                    fmt_ += "%s\033[1;36m%s\033[0m";
                }
                else
                {
                    fmt_ += "%s%s";
                }

                // EOL
                fmt_ += '\n';

                char const*     fmt =   fmt_.c_str();

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   actualValue
                                ,   expectedValue
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }

            void
            onTestFailed_UnsignedLong_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   unsigned long       expectedValue
            ,   unsigned long       actualValue
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
                std::string     fmt_;

                fmt_ += "%s(%d): test condition failed: ";

                // actual
                if (is_tty)
                {
                    fmt_ += "actual value \033[1;35m%lu\033[0m";
                }
                else
                {
                    fmt_ += "actual value %lu";
                }

                fmt_ += " should ";

                // comparison
                if (is_tty)
                {
                    fmt_ += "\033[1;36m";
                }
                fmt_ += relation_equals_(comparison);
                if (is_tty)
                {
                    fmt_ += "\033[0m";
                }

                // expected
                if (is_tty)
                {
                    fmt_ += " the expected value \033[1;35m%lu\033[0m";
                }
                else
                {
                    fmt_ += " the expected value %lu";
                }

                // function (?)
                if (is_tty)
                {
                    fmt_ += "%s\033[1;36m%s\033[0m";
                }
                else
                {
                    fmt_ += "%s%s";
                }

                // EOL
                fmt_ += '\n';

                char const*     fmt =   fmt_.c_str();

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   actualValue
                                ,   expectedValue
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

            void
            onTestFailed_sint64_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   sint64_t            expectedValue
            ,   sint64_t            actualValue
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {
# ifdef XTESTS_STLSOFT_1_12_OR_LATER
                static char const*  s_fmt64 =   stlsoft::integral_printf_format_traits<stlsoft::sint64_t>::decimal_format_a();
# else /* ? STLSoft 1.12+ */
                static char const*  s_fmt64 =   stlsoft::integral_printf_traits       <stlsoft::sint64_t>::decimal_format_a();
# endif /* STLSoft 1.12+ */

                std::string     fmt_;

                fmt_ += "%s(%d): test condition failed: ";

                // actual
                if (is_tty)
                {
                    fmt_ += "actual value \033[1;35m";
                    fmt_ += s_fmt64;
                    fmt_ += "\033[0m";
                }
                else
                {
                    fmt_ += "actual value ";
                    fmt_ += s_fmt64;
                }

                fmt_ += " should ";

                // comparison
                if (is_tty)
                {
                    fmt_ += "\033[1;36m";
                }
                fmt_ += relation_equals_(comparison);
                if (is_tty)
                {
                    fmt_ += "\033[0m";
                }

                // expected
                if (is_tty)
                {
                    fmt_ += " the expected value \033[1;35m";
                    fmt_ += s_fmt64;
                    fmt_ += "\033[0m";
                }
                else
                {
                    fmt_ += " the expected value ";
                    fmt_ += s_fmt64;
                }

                // function (?)
                if (is_tty)
                {
                    fmt_ += "%s\033[1;36m%s\033[0m";
                }
                else
                {
                    fmt_ += "%s%s";
                }

                // EOL
                fmt_ += '\n';

                char const*     fmt =   fmt_.c_str();

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   actualValue
                                ,   expectedValue
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }

            void
            onTestFailed_uint64_(
                char const*         file
            ,   int                 line
            ,   char const*         function
            ,   char const*      /* expr */
            ,   uint64_t            expectedValue
            ,   uint64_t            actualValue
            ,   xtests_comparison_t comparison
            ,   int                 verbosity
            ,   int                 is_tty
            )
            {

# ifdef XTESTS_STLSOFT_1_12_OR_LATER
                static char const*  s_fmt64 =   stlsoft::integral_printf_format_traits<stlsoft::uint64_t>::decimal_format_a();
# else /* ? STLSoft 1.12+ */
                static char const*  s_fmt64 =   stlsoft::integral_printf_traits       <stlsoft::uint64_t>::decimal_format_a();
# endif /* STLSoft 1.12+ */

                std::string     fmt_;

                fmt_ += "%s(%d): test condition failed: ";

                // actual
                if (is_tty)
                {
                    fmt_ += "actual value \033[1;35m";
                    fmt_ += s_fmt64;
                    fmt_ += "\033[0m";
                }
                else
                {
                    fmt_ += "actual value ";
                    fmt_ += s_fmt64;
                }

                fmt_ += " should ";

                // comparison
                if (is_tty)
                {
                    fmt_ += "\033[1;36m";
                }
                fmt_ += relation_equals_(comparison);
                if (is_tty)
                {
                    fmt_ += "\033[0m";
                }

                // expected
                if (is_tty)
                {
                    fmt_ += " the expected value \033[1;35m";
                    fmt_ += s_fmt64;
                    fmt_ += "\033[0m";
                }
                else
                {
                    fmt_ += " the expected value ";
                    fmt_ += s_fmt64;
                }

                // function (?)
                if (is_tty)
                {
                    fmt_ += "%s\033[1;36m%s\033[0m";
                }
                else
                {
                    fmt_ += "%s%s";
                }

                // EOL
                fmt_ += '\n';

                char const*     fmt =   fmt_.c_str();

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   actualValue
                                ,   expectedValue
                                ,   (NULL != function) ? " in function " : ""
                                ,   STLSOFT_NS_QUAL(c_str_ptr)(function)
                                );
            }
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

            void
            onTestFailed_(
                char const*             file
            ,   int                     line
            ,   char const*             function
            ,   char const*             expr
            ,   xtests_comparison_t  /* comparison */
            ,   int                     verbosity
            ,   int                     is_tty
            )
            {
                static const char*  s_fmts[] =
                {
                        "%s(%d): test condition \"%s%s%s\" %sfailed%s\n"
                    ,   "%s(%d): test condition \"%s%s%s\" %sfailed%s in function %s%s%s\n"
                };
                char const*         fmt = s_fmts[NULL != function];

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    fmt = "";
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    break;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   is_tty ? "{" : ""
                                ,   expr
                                ,   is_tty ? "}" : ""
                                ,   is_tty ? "{" : ""
                                ,   is_tty ? "}" : ""
                                ,   is_tty ? "{" : ""
                                ,   function
                                ,   is_tty ? "}" : ""
                                );
            }

            virtual void onWriteFailMessage(void* /* reporterParam */, char const* file, int line, char const* function, char const* message, char const* qualifyingInformation, int verbosity) ss_override_k
            {
                static const char  s_fmt[] = "%s(%d): %s%s%s%s%s%s%s%s%s%s%s\n";

                char const* fn_pre;
                char const* fn_post;
                char const* msg_pre;
                char const* msg_post;

                if (is_tty)
                {
                    fn_pre      =   "\033[1;36m";
                    fn_post     =   "\033[0m";
                    msg_pre     =   "\033[1;35m";
                    msg_post    =   "\033[0m";
                }
                else
                {
                    fn_pre      =   "";
                    fn_post     =   "";
                    msg_pre     =   "";
                    msg_post    =   "";
                }

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                    ,   s_fmt
                                    ,   file, line
                                    ,   msg_pre
                                    ,   message
                                    ,   msg_post
                                    ,   (NULL != function) ? " in function " : ""
                                    ,   fn_pre
                                    ,   (NULL != function) ? function : ""
                                    ,   fn_post
                                    ,   (NULL != qualifyingInformation) ? ": " : ""
                                    ,   msg_pre
                                    ,   (NULL != qualifyingInformation) ? qualifyingInformation : ""
                                    ,   msg_post
                                    );
                    break;
                }
            }

            virtual void onCaseExcepted(void* /* reporterParam */, char const* file, int line, char const* caseName, char const* exceptionType, char const* exceptionMessage, int verbosity) ss_override_k
            {
                int level = 0;

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    break;
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:

                    level = 1;
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    level = 2;
                    break;
                }

                STLSOFT_ASSERT(level >= 0 && level < 3);

                static char const*  s_fmts[] =
                {
                        ""
                    ,   "%s(%d): %s%s%s: %sUX%s %srx%s '%s%s%s'; msg='%s%s%s'\n"
                    ,   "%s(%d): Test case '%s%s%s': %sreceived unexpected exception%s of type '%s%s%s', with message '%s%s%s'\n"
                };
                char const*         fmt = s_fmts[level];

                char const* case_pre;
                char const* case_post;
                char const* rsn_pre;
                char const* rsn_post;
                char const* msg_pre;
                char const* msg_post;
                char const* xt_pre;
                char const* xt_post;

                if (is_tty)
                {
                    case_pre    =   "\033[1;36m";
                    case_post   =   "\033[0m";
                    rsn_pre     =   "\033[1;36m";
                    rsn_post    =   "\033[0m";
                    msg_pre     =   "\033[1;36m";
                    msg_post    =   "\033[0m";
                    xt_pre      =   "\033[1;35m";
                    xt_post     =   "\033[0m";
                }
                else
                {
                    case_pre    =   "";
                    case_post   =   "";
                    rsn_pre     =   "";
                    rsn_post    =   "";
                    msg_pre     =   "";
                    msg_post    =   "";
                    xt_pre      =   "";
                    xt_post     =   "";
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   case_pre
                                ,   caseName
                                ,   case_post
                                ,   rsn_pre
                                ,   rsn_post
                                ,   xt_pre
                                ,   exceptionType
                                ,   xt_post
                                ,   msg_pre
                                ,   exceptionMessage
                                ,   msg_post
                                );
            }

            virtual void onCaseExceptionExpected(void* /* reporterParam */, char const* file, int line, char const* caseName, char const* exceptionType, int verbosity) ss_override_k
            {
                int level = 0;

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    break;
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:

                    level = 1;
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY:
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    level = 2;
                    break;
                }

                STLSOFT_ASSERT(level >= 0 && level < 3);

                static char const*  s_fmts[] =
                {
                        ""
                    ,   "%s(%d): %s%s%s: %sEX%s '%s%s%s' %snot rx%s\n"
                    ,   "%s(%d): Test case '%s%s%s': %sexpected exception%s of type '%s%s%s' was %snot received%s\n"
                };
                char const*         fmt = s_fmts[level];

                char const* case_pre;
                char const* case_post;
                char const* rsn_pre;
                char const* rsn_post;
                char const* rx_pre;
                char const* rx_post;
                char const* xt_pre;
                char const* xt_post;

                if (is_tty)
                {
                    case_pre    =   "\033[1;36m";
                    case_post   =   "\033[0m";
                    rsn_pre     =   "\033[1;36m";
                    rsn_post    =   "\033[0m";
                    rx_pre      =   "\033[1;36m";
                    rx_post     =   "\033[0m";
                    xt_pre      =   "\033[1;35m";
                    xt_post     =   "\033[0m";
                }
                else
                {
                    case_pre    =   "";
                    case_post   =   "";
                    rsn_pre     =   "";
                    rsn_post    =   "";
                    rx_pre      =   "";
                    rx_post     =   "";
                    xt_pre      =   "";
                    xt_post     =   "";
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   file, line
                                ,   case_pre
                                ,   caseName
                                ,   case_post
                                ,   rsn_pre
                                ,   rsn_post
                                ,   xt_pre
                                ,   exceptionType
                                ,   xt_post
                                ,   rx_pre
                                ,   rx_post
                                );
            }

            virtual void onEndTestCase(
                void*                        /* reporterParam */
            ,   char const*                  /* name */
            ,   xTests_runner_results_t const*  results
            ,   int                             verbosity
            ) ss_override_k
            {
                int level = 0;
                int allTestsHavePassed =
                    ( 0 == results->numFailedTests &&
                      0 == results->numUnexpectedExceptions &&
                      0 == results->numMissingExpectedExceptions);

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    level = 0;
                    break;
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:

                    if (!allTestsHavePassed)
                    {
                        if (0 == results[1].numFailedCases)
                        {
                            level = 2;
                        }
                    }
                    break;
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:

                    if (!allTestsHavePassed)
                    {
                        level = 2;
                    }
                    break;
                case XTESTS_VERBOSITY_CASE_SUMMARY:

                    level = 2;
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    level = 2;
                    break;
                }
                STLSOFT_ASSERT(level >= 0 && level < 3);

                static char const*  s_fmts[] =
                {
                        ""
                    ,   "\t%s: %u / %u / %u / %u / %u; result=%s\n"
                    ,   "\tTest case '%s': %u assertions; %u succeeded; %u failed; %u unexpected exceptions; %u missing expected exceptions; result=%s\n"
                };
                char const*         fmt = s_fmts[level];
                char                success_or_failure[101];
                char_buffer_t_      name_buff(0);

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   xtests_name_(name_buff, results->name, is_tty).data()
                                ,   results->numTests
                                ,   results->numTests - results->numFailedTests
                                ,   results->numFailedTests
                                ,   results->numUnexpectedExceptions
                                ,   results->numMissingExpectedExceptions
                                ,   xtests_success_or_failure_(
                                        allTestsHavePassed
                                    ,   success_or_failure
                                    ,   is_tty
                                    )
                                );
            }

            virtual void onPrintRunnerResults(
                void*                        /* reporterParam */
            ,   xTests_runner_results_t const*  results
            ,   int                             verbosity
            ) ss_override_k
            {
                int level = 0;

                switch (verbosity)
                {
                case XTESTS_VERBOSITY_SILENT:

                    level = 0;
                    break;
                case XTESTS_VERBOSITY_RUNNER_SUMMARY_ON_ERROR:

                    if (0 != results->numFailedCases)
                    {
                        level = 1;
                    }
                    break;
                case XTESTS_VERBOSITY_RUNNER_SUMMARY:

                    level = 1;
                    break;
                case XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR:
                case XTESTS_VERBOSITY_CASE_SUMMARY_ON_ERROR:

                    level = 1;
                    if (0 != results->numFailedCases)
                    {
                        level = 2;
                    }
                    break;
                case XTESTS_VERBOSITY_CASE_SUMMARY:

                    level = 2;
                    break;
                default:

                    STLSOFT_MESSAGE_ASSERT("verbosity not recognised", 0);
                XTESTS_VERBOSITY_VALID_MISSING_CASES
                case XTESTS_VERBOSITY_VERBOSE:

                    level = 2;
                    break;
                }

                STLSOFT_ASSERT(level >= 0 && level < 3);

                static char const*  s_fmts[] =
                {
                        ""
                    ,   "Test runner '%s' complete:"
                        "\t%u / %u / %u / %u / %u / %u; result=%s\n"
                        "\n"
                    ,   "------------------------------------------------------------\n"
                        "Test runner '%s' complete:\n"
                        "\t%u test case(s)\n"
                        "\t%u total assertion(s)\n"
                        "\t%u total assertion(s) succeeded\n"
                        "\t%u total assertion(s) failed\n"
                        "\t%u total unexpected exception(s)\n"
                        "\t%u total missing expected exception(s)\n"
                        "\tresult=%s\n"
                        "\n"
                };
                char const* const   fmt = s_fmts[level];
                char                success_or_failure[101];
                char_buffer_t_      name_buff(0);

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   fmt
                                ,   xtests_name_(name_buff, results->name, is_tty).data()
                                ,   static_cast<unsigned>(results->numCases)
                                ,   static_cast<unsigned>(results->numTests)
                                ,   static_cast<unsigned>(results->numTests - results->numFailedTests)
                                ,   static_cast<unsigned>(results->numFailedTests)
                                ,   static_cast<unsigned>(results->numUnexpectedExceptions)
                                ,   static_cast<unsigned>(results->numMissingExpectedExceptions)
                                ,   xtests_success_or_failure_(
                                        0u == results->numFailedTests &&
                                        0u == results->numUnexpectedExceptions &&
                                        0u == results->numMissingExpectedExceptions
                                    ,   success_or_failure
                                    ,   is_tty
                                    )
                                );
            }

            virtual void onAbend(
                void*        /* reporterParam */
            ,   char const*  /* message */
            ,   int          /* verbosity */
            ) ss_override_k
            {
            }

            virtual void onDefect(
                void*    /* reporterParam */
            ,   char const* message
            ,   char const* qualifier
            ,   int      /* verbosity */
            ) ss_override_k
            {
                if (NULL != qualifier &&
                    '\0' == *qualifier)
                {
                    qualifier = NULL;
                }

                xtests_mxnprintf_(  m_sinks, m_numSinks, 50
                                ,   (NULL != qualifier) ? "defect: %s: %s\n" : "defect: %s\n"
                                ,   message
                                ,   qualifier
                                );
            }

            virtual void onEndRunner(
                void*        /* reporterParam */
            ,   char const*  /* name */
            ,   int          /* verbosity */
            ) ss_override_k
            {
            }

        private: // fields
            int const       m_flags;
            int const       is_tty;
            size_t const    m_numSinks;
            xtests_sink_t_  m_sinks[2];
        };

#if defined(STLSOFT_COMPILER_IS_BORLAND) && \
    __BORLANDC__ >= 0x0610
# pragma warn -8104
#endif

        static fprintf_reporter s_reporter(stm, flags, is_tty);

#if defined(STLSOFT_COMPILER_IS_BORLAND) && \
    __BORLANDC__ >= 0x0610
# pragma warn .8104
#endif

        reporter = &s_reporter;
    }

    return reporter;
}

void
RunnerInfo::report_unstartedCase_defect_()
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw std::runtime_error("not in a test case; call XTESTS_CASE_BEGIN() ?");
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_reporter->onDefect(m_reporterParam, "not in a test case; call XTESTS_CASE_BEGIN() ?", NULL, m_verbosity);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}


RunnerInfo::RunnerInfo(
    char const*             name
,   int                     verbosity
,   xTests_Reporter_t*      reporter
,   void*                   reporterParam
,   FILE*                   stm
,   int                     flags
,   xTests_Setup_t const    setup
,   xTests_Teardown_t const teardown
,   void* const             setupParam
)
    : m_reporter(get_reporter_(
                        reporter
                    ,   stm
                    ,   flags
                    ,   platformstl::isatty(stdout)
                    ))
    , m_reporterParam(reporterParam)
    , m_name(name)
    , m_verbosity(verbosity)
    , m_flags(flags)
    , m_setup(setup)
    , m_teardown(teardown)
    , m_setupParam(setupParam)
    , m_testCases()
    , m_totalConditions(0)
    , m_failedConditions(0)
    , m_unexpectedExceptions(0)
    , m_expectedExceptions(0)
    , m_currentCase(m_testCases.end())
    , m_requireFailed(false)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    STLSOFT_MESSAGE_ASSERT("Invalid verbosity; must be in range [XTESTS_VERBOSITY_SILENT, XTESTS_VERBOSITY_VERBOSE]", verbosity >= XTESTS_VERBOSITY_SILENT && verbosity <= XTESTS_VERBOSITY_VERBOSE);
}

int
RunnerInfo::BeginCase(
    char const* name
,   char const* description
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() != m_testCases.find(name))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw std::runtime_error("test case already exists");
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_reporter->onDefect(m_reporterParam, "test case already exists", name, m_verbosity);

        return -1;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else if (m_testCases.end() != m_currentCase)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        throw std::runtime_error("a test case is already in progress; call XTESTS_CASE_END() ?");
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        m_reporter->onDefect(m_reporterParam, "a test case is already in progress; call XTESTS_CASE_END() ?", NULL, m_verbosity);

        return -1;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
    else
    {
        m_requireFailed = false;

        m_currentCase = m_testCases.insert(std::make_pair(string_t(name), TestInfo(name, description))).first;

        if (NULL != m_setup)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            try
            {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                int r = (*m_setup)(m_setupParam);

                if (0 != r)
                {
                    m_reporter->onDefect(m_reporterParam, "setup function returned a non-zero value", NULL, m_verbosity);

                    m_testCases.erase(m_currentCase);
                    m_currentCase = m_testCases.end();

                    return -1;
                }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            }
            catch (XTESTS_NS_CPP_QUAL(prerequisite_failed_exception)& x)
            {
                m_reporter->onDefect(m_reporterParam, "setup function failed", x.what(), m_verbosity);

                return -1;
            }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        m_reporter->onBeginTestCase(m_reporterParam, name, description, m_verbosity);
    }

    return 0;
}

int
RunnerInfo::EndCase(char const* /* name */)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo const& testInfo = (*m_currentCase).second;

        xTests_runner_results_t results[2];

        results[0].name                         =   testInfo.name.c_str();
        results[0].numCases                     =   0;
        results[0].numTests                     =   testInfo.totalConditions;
        results[0].numFailedCases               =   0;
        results[0].numFailedTests               =   testInfo.failedConditions;
        results[0].numUnexpectedExceptions      =   testInfo.unexpectedExceptions;
        results[0].numMissingExpectedExceptions =   testInfo.expectedExceptions;

        results[1].name                         =   "*";
        results[1].numCases                     =   static_cast<uint32_t>(m_testCases.size());
        results[1].numTests                     =   m_totalConditions;
        results[1].numFailedCases               =   static_cast<uint32_t>(NumberOfFailedTestCases());
        results[1].numFailedTests               =   m_failedConditions;
        results[1].numUnexpectedExceptions      =   m_expectedExceptions;
        results[1].numMissingExpectedExceptions =   m_unexpectedExceptions;


        // NOTE: The following are not x += y because Intel C/C++ gets awfully confused by that
        m_totalConditions       =   m_totalConditions + testInfo.totalConditions;
        m_failedConditions      =   m_failedConditions + testInfo.failedConditions;
        m_unexpectedExceptions  =   m_unexpectedExceptions + testInfo.unexpectedExceptions;
        m_expectedExceptions    =   m_expectedExceptions + testInfo.expectedExceptions;

        if (NULL != m_teardown)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            try
            {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                (*m_teardown)(m_setupParam);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            }
            catch (XTESTS_NS_CPP_QUAL(prerequisite_failed_exception)& x)
            {
                m_reporter->onDefect(m_reporterParam, "teardown function failed", x.what(), m_verbosity);

                return -1;
            }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        m_currentCase = m_testCases.end();

        if (0 != testInfo.totalConditions ||
            0 == (xtestsReportOnlyNonEmptyCases & m_flags))
        {
            m_reporter->onEndTestCase(m_reporterParam, results[0].name, &results[0], m_verbosity);
        }

        return 0;
    }

    RETURN_UNUSED(-1);
}

void*
RunnerInfo::GetSetupParam() const
{
    return m_setupParam;
}

int
RunnerInfo::RegisterSuccessfulCondition(
    char const* file
,   int         line
,   char const* function
,   char const* expr
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        m_reporter->onTestPassed(m_reporterParam, file, line, function, expr, xtestsComparisonEqual, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::RegisterFailedCondition(
    char const* file
,   int         line
,   char const* function
,   char const* expr
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.failedConditions;
        ++testInfo.totalConditions;

        Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, NULL, NULL, -1, xtestsComparisonEqual, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::RegisterFailedCondition_long(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   long                expected
,   long                actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.failedConditions;
        ++testInfo.totalConditions;

        xtests_variable_t   expectedValue(expected);
        xtests_variable_t   actualValue(actual);

        Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::RegisterFailedCondition_ulong(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   unsigned long       expected
,   unsigned long       actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.failedConditions;
        ++testInfo.totalConditions;

        xtests_variable_t   expectedValue(expected);
        xtests_variable_t   actualValue(actual);

        Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT

int
RunnerInfo::RegisterFailedCondition_sint64(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   sint64_t            expected
,   sint64_t            actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.failedConditions;
        ++testInfo.totalConditions;

        xtests_variable_t   expectedValue(expected);
        xtests_variable_t   actualValue(actual);

        Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::RegisterFailedCondition_uint64(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   uint64_t            expected
,   uint64_t            actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.failedConditions;
        ++testInfo.totalConditions;

        xtests_variable_t   expectedValue(expected);
        xtests_variable_t   actualValue(actual);

        Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

int
RunnerInfo::RegisterFailedCondition_boolean(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   bool                expected
,   bool                actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.failedConditions;
        ++testInfo.totalConditions;

        xtests_variable_t   expectedValue(expected);
        xtests_variable_t   actualValue(actual);

        Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::RegisterFailedCondition_double(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   double const&       expected
,   double const&       actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.failedConditions;
        ++testInfo.totalConditions;

        xtests_variable_t   expectedValue(expected);
        xtests_variable_t   actualValue(actual);

        Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestMultibyteStrings(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
        int comparisonSucceeded = false;

        switch (comp)
        {
        case xtestsComparisonEqual:

            if (0 == xtests_strcmp_a_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxEqual:

            if (0 == xtests_stricmp_a_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonNotEqual:

            if (0 != xtests_strcmp_a_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxNotEqual:

            if (0 != xtests_stricmp_a_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonGreaterThan:

            if (0 > xtests_strcmp_a_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonLessThan:

            if (0 < xtests_strcmp_a_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonGreaterThanOrEqual:

            if (0 >= xtests_strcmp_a_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonLessThanOrEqual:

            if (0 <= xtests_strcmp_a_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected);
            xtests_variable_t   actualValue(actual);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestMultibyteStringsN(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   ptrdiff_t           n
,   size_t              cchExpected
,   size_t              cchActual
,   xtests_comparison_t comp)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
        int     comparisonSucceeded =   false;
        size_t  ncmp;

        if (n >= 0)
        {
            ncmp = static_cast<size_t>(n);
        }
        else
        {
            // -ve n is means an upper limit, rather than an exact
            // correspondence, so we trim to size if necessary

            ncmp = static_cast<size_t>(-n);

            if (ncmp > cchExpected)
            {
                ncmp = cchExpected;
            }
        }

        if (cchActual < ncmp ||
            cchExpected < ncmp)
        {
            // actual string is less than required length, so comparison
            // fails
            switch (comp)
            {
            case xtestsComparisonEqual:
            case xtestsComparisonApproxEqual:

                break;
            case xtestsComparisonNotEqual:
            case xtestsComparisonApproxNotEqual:

                comparisonSucceeded = true;
                break;
            case xtestsComparisonGreaterThan:
            case xtestsComparisonLessThan:
            case xtestsComparisonGreaterThanOrEqual:
            case xtestsComparisonLessThanOrEqual:

                break;
            default:

                STLSOFT_ASSERT(0);
            case xtestsComparison_max_enumerator:

                xtests_abend("invalid test comparison type: test framework may be out of date!");
                break;
            }
        }
        else
        {
            switch (comp)
            {
            case xtestsComparisonEqual:

                if (0 == xtests_strncmp_a_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonApproxEqual:

                if (0 == xtests_strnicmp_a_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonNotEqual:

                if (0 != xtests_strncmp_a_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonApproxNotEqual:

                if (0 != xtests_strnicmp_a_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonGreaterThan:

                if (0 > xtests_strncmp_a_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonLessThan:

                if (0 < xtests_strncmp_a_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonGreaterThanOrEqual:

                if (0 >= xtests_strncmp_a_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonLessThanOrEqual:

                if (0 <= xtests_strncmp_a_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparison_max_enumerator:

                xtests_abend("invalid test comparison type: test framework may be out of date!");
                break;
            }
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected, cchExpected, xtestsTestPartialComparison);
            xtests_variable_t   actualValue(actual, cchActual, xtestsTestPartialComparison);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, n, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestWideStrings(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
        int comparisonSucceeded = false;

        switch (comp)
        {
        case xtestsComparisonEqual:

            if (0 == xtests_strcmp_w_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxEqual:

            if (0 == xtests_stricmp_w_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonNotEqual:

            if (0 != xtests_strcmp_w_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxNotEqual:

            if (0 != xtests_stricmp_w_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonGreaterThan:

            if (0 > xtests_strcmp_w_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonLessThan:

            if (0 < xtests_strcmp_w_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonGreaterThanOrEqual:

            if (0 >= xtests_strcmp_w_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonLessThanOrEqual:

            if (0 <= xtests_strcmp_w_(expected, actual))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected);
            xtests_variable_t   actualValue(actual);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestWideStringsN(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   int                 n
,   size_t              cchExpected
,   size_t              cchActual
,   xtests_comparison_t comp)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
        int     comparisonSucceeded = false;
        size_t  ncmp;

        if (n >= 0)
        {
            ncmp = static_cast<size_t>(n);
        }
        else
        {
            // -ve n is means an upper limit, rather than an exact
            // correspondence, so we trim to size if necessary

            ncmp = static_cast<size_t>(-n);

            if (ncmp > cchExpected)
            {
                ncmp = cchExpected;
            }
        }

        if (cchActual < ncmp ||
            cchExpected < ncmp)
        {
            // actual string is less than required length, so comparison
            // fails
            switch (comp)
            {
            case xtestsComparisonEqual:
            case xtestsComparisonApproxEqual:

                break;
            case xtestsComparisonNotEqual:
            case xtestsComparisonApproxNotEqual:

                comparisonSucceeded = true;
                break;
            case xtestsComparisonGreaterThan:
            case xtestsComparisonLessThan:
            case xtestsComparisonGreaterThanOrEqual:
            case xtestsComparisonLessThanOrEqual:

                break;
            case xtestsComparison_max_enumerator:

                xtests_abend("invalid test comparison type: test framework may be out of date!");
                break;
            }
        }
        else
        {
            switch (comp)
            {
            case xtestsComparisonEqual:

                if (0 == xtests_strncmp_w_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonApproxEqual:

                if (0 == xtests_strnicmp_w_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonNotEqual:

                if (0 != xtests_strncmp_w_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonApproxNotEqual:

                if (0 != xtests_strnicmp_w_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonGreaterThan:

                if (0 > xtests_strncmp_w_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonLessThan:

                if (0 < xtests_strncmp_w_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonGreaterThanOrEqual:

                if (0 >= xtests_strncmp_w_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparisonLessThanOrEqual:

                if (0 <= xtests_strncmp_w_(expected, actual, ncmp))
                {
                    comparisonSucceeded = true;
                }
                break;
            case xtestsComparison_max_enumerator:

                xtests_abend("invalid test comparison type: test framework may be out of date!");
                break;
            }
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected, cchExpected, xtestsTestPartialComparison);
            xtests_variable_t   actualValue(actual, cchActual, xtestsTestPartialComparison);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, n, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestMultibyteStringContains(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char const*         expected
,   char const*         actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
        int comparisonSucceeded = false;

        switch (comp)
        {
        case xtestsComparisonEqual:

            if (NULL != xtests_strstr_(actual, expected))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxEqual:

            if (NULL != xtests_stristr_(actual, expected))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonNotEqual:

            if (NULL == xtests_strstr_(actual, expected))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxNotEqual:

            if (NULL == xtests_stristr_(actual, expected))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonGreaterThan:
        case xtestsComparisonLessThan:
        case xtestsComparisonGreaterThanOrEqual:
        case xtestsComparisonLessThanOrEqual:

            xtests_abend("comparison type not valid for string containing tests");
            break;
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected, xtestsTestContainment);
            xtests_variable_t   actualValue(actual, xtestsTestContainment);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestWideStringContains(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t const*      expected
,   wchar_t const*      actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
        int comparisonSucceeded = false;

        switch (comp)
        {
        case xtestsComparisonEqual:

            if (NULL != xtests_strstr_w_(actual, expected))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxEqual:

            if (NULL != xtests_stristr_w_(actual, expected))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonNotEqual:

            if (NULL == xtests_strstr_w_(actual, expected))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxNotEqual:

            if (NULL == xtests_stristr_w_(actual, expected))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonGreaterThan:
        case xtestsComparisonLessThan:
        case xtestsComparisonGreaterThanOrEqual:
        case xtestsComparisonLessThanOrEqual:

            xtests_abend("comparison type not valid for string containing tests");
            break;
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected, xtestsTestContainment);
            xtests_variable_t   actualValue(actual, xtestsTestContainment);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestMultibyteStringSlice(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   size_t                  expectedLen
,   char const*             expectedPtr
,   size_t                  actualLen
,   char const*             actualPtr
,   xtests_comparison_t     comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;


        // Now do test, taking into account NULL pointers
        int             comparisonSucceeded =   false;
        bool const      sameLength          =   (expectedLen == actualLen);

        switch (comp)
        {
        case xtestsComparisonEqual:

            if (sameLength &&
                0 == xtests_strncmp_a_(expectedPtr, actualPtr, expectedLen))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxEqual:

            if (sameLength &&
                0 == xtests_strnicmp_a_(expectedPtr, actualPtr, expectedLen))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonNotEqual:

            if (!sameLength ||
                0 != xtests_strncmp_a_(expectedPtr, actualPtr, expectedLen))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxNotEqual:

            if (!sameLength ||
                0 != xtests_strnicmp_a_(expectedPtr, actualPtr, expectedLen))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonGreaterThan:
        case xtestsComparisonLessThan:
        case xtestsComparisonGreaterThanOrEqual:
        case xtestsComparisonLessThanOrEqual:

            XTESTS_FALLTHROUGH_();
            // fall through
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            char_buffer_t_  expectedBuffer(expectedLen + 1);
            char_buffer_t_  actualBuffer(actualLen + 1);

            xtests_strncpy_(&expectedBuffer[0], expectedBuffer.size(), expectedPtr, expectedLen);
            xtests_strncpy_(&actualBuffer[0], actualBuffer.size(), actualPtr, actualLen);

            xtests_variable_t   expectedValue(expectedBuffer.data(), expectedLen);
            xtests_variable_t   actualValue(actualBuffer.data(), actualLen);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestWideStringSlice(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   size_t                  expectedLen
,   wchar_t const*          expectedPtr
,   size_t                  actualLen
,   wchar_t const*          actualPtr
,   xtests_comparison_t     comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;


        // Now do test, taking into account NULL pointers
        int             comparisonSucceeded =   false;
        bool const      sameLength          =   (expectedLen == actualLen);

        switch (comp)
        {
        case xtestsComparisonEqual:

            if (sameLength &&
                0 == xtests_strncmp_w_(expectedPtr, actualPtr, expectedLen))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxEqual:

            if (sameLength &&
                0 == xtests_strnicmp_w_(expectedPtr, actualPtr, expectedLen))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonNotEqual:

            if (!sameLength ||
                0 != xtests_strncmp_w_(expectedPtr, actualPtr, expectedLen))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonApproxNotEqual:

            if (!sameLength ||
                0 != xtests_strnicmp_w_(expectedPtr, actualPtr, expectedLen))
            {
                comparisonSucceeded = true;
            }
            break;
        case xtestsComparisonGreaterThan:
        case xtestsComparisonLessThan:
        case xtestsComparisonGreaterThanOrEqual:
        case xtestsComparisonLessThanOrEqual:

            XTESTS_FALLTHROUGH_();
            // fall through
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            char_buffer_w_t_    expectedBuffer(expectedLen + 1);
            char_buffer_w_t_    actualBuffer(actualLen + 1);

            xtests_wcsncpy_(&expectedBuffer[0], expectedBuffer.size(), expectedPtr, expectedLen);
            xtests_wcsncpy_(&actualBuffer[0], actualBuffer.size(), actualPtr, actualLen);

            xtests_variable_t   expectedValue(expectedBuffer.data(), expectedLen);
            xtests_variable_t   actualValue(actualBuffer.data(), actualLen);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestPointers(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   void volatile const*    expected
,   void volatile const*    actual
,   xtests_comparison_t     comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
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
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected);
            xtests_variable_t   actualValue(actual);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestFunctionPointers(
    char const*             file
,   int                     line
,   char const*             function
,   char const*             expr
,   void                    (*expected)(void)
,   void                    (*actual)(void)
,   xtests_comparison_t     comp
)
{
    STLSOFT_ASSERT(xtestsComparisonEqual == comp || xtestsComparisonNotEqual == comp);

    STLSOFT_STATIC_ASSERT(sizeof(void*) == sizeof(void(*)(void)));

    union
    {
        void*   p;
        void    (*pfn)(void);

    } x, a;

    x.pfn = expected;
    a.pfn = actual;

    return TestPointers(
        file
    ,   line
    ,   function
    ,   expr
    ,   x.p
    ,   a.p
    ,   comp
    );
}

int
RunnerInfo::TestCharacters(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   char                expected
,   char                actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
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

            if (::toupper(expected) == ::toupper(actual))
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

            if (::toupper(expected) != ::toupper(actual))
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
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected);
            xtests_variable_t   actualValue(actual);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::TestCharacters(
    char const*         file
,   int                 line
,   char const*         function
,   char const*         expr
,   wchar_t             expected
,   wchar_t             actual
,   xtests_comparison_t comp
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.totalConditions;

        // Now do test, taking into account NULL pointers
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

            if (::towupper(expected) == ::towupper(actual))
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

            if (::towupper(expected) != ::towupper(actual))
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
        case xtestsComparison_max_enumerator:

            xtests_abend("invalid test comparison type: test framework may be out of date!");
            break;
        }

        if (comparisonSucceeded)
        {
            return 1;
        }
        else
        {
            ++testInfo.failedConditions;

            xtests_variable_t   expectedValue(expected, xtestsVariableWideCharacter);
            xtests_variable_t   actualValue(actual, xtestsVariableWideCharacter);

            Call_onTestFailed(m_reporter, m_reporterParam, file, line, function, expr, &expectedValue, &actualValue, -1, comp, m_verbosity);

            return 0;
        }
    }

    RETURN_UNUSED(-1);
}

int
RunnerInfo::WriteFailMessage(
    char const* file
,   int         line
,   char const* function
,   char const* message
,   char const* qualifyingInformation
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();

        return -1;
    }
    else
    {
        TestInfo& testInfo = (*m_currentCase).second;

        ++testInfo.failedConditions;
        ++testInfo.totalConditions;

        m_reporter->onWriteFailMessage(m_reporterParam, file, line, function, message, qualifyingInformation, m_verbosity);

        return 0;
    }

    RETURN_UNUSED(-1);
}

void
RunnerInfo::CaseExcepted(
    char const* file
,   int         line
,   char const* exceptionType
,   char const* exceptionMessage
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();
    }
    else
    {
        TestInfo&   testInfo = (*m_currentCase).second;

        ++testInfo.unexpectedExceptions;

        m_reporter->onCaseExcepted(m_reporterParam, file, line, testInfo.name.c_str(), exceptionType, exceptionMessage, m_verbosity);
    }
}

void
RunnerInfo::CaseExceptionExpected(
    char const* file
,   int         line
,   char const* exceptionType
)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (m_testCases.end() == m_currentCase)
    {
        report_unstartedCase_defect_();
    }
    else
    {
        TestInfo&   testInfo = (*m_currentCase).second;

        ++testInfo.expectedExceptions;

        m_reporter->onCaseExceptionExpected(m_reporterParam, file, line, testInfo.name.c_str(), exceptionType, m_verbosity);
    }
}

void
RunnerInfo::OnRequireFailed()
{
    m_requireFailed = true;
}

int
RunnerInfo::HasRequiredConditionFailed() const
{
    return m_requireFailed;
}

void
RunnerInfo::PrintStart()
{
    STLSOFT_ASSERT(NULL != m_reporter);

    m_reporter->onStartRunner(m_reporterParam, m_name.c_str(), m_verbosity);
}

void
RunnerInfo::PrintEnd()
{
    STLSOFT_ASSERT(NULL != m_reporter);

    m_reporter->onEndRunner(m_reporterParam, m_name.c_str(), m_verbosity);
}

void
RunnerInfo::PrintResults()
{
    STLSOFT_ASSERT(NULL != m_reporter);

    xTests_runner_results_t results;

    results.name                            =   m_name.c_str();
    results.numCases                        =   static_cast<uint32_t>(m_testCases.size());
    results.numTests                        =   m_totalConditions;
    results.numFailedCases                  =   static_cast<uint32_t>(NumberOfFailedTestCases());
    results.numFailedTests                  =   m_failedConditions;
    results.numMissingExpectedExceptions    =   m_expectedExceptions;
    results.numUnexpectedExceptions         =   m_unexpectedExceptions;

    m_reporter->onPrintRunnerResults(m_reporterParam, &results, m_verbosity);
}

void
RunnerInfo::onAbend(char const* message)
{
    STLSOFT_ASSERT(NULL != m_reporter);

    m_reporter->onAbend(m_reporterParam, message, m_verbosity);
}

size_t
RunnerInfo::NumberOfFailedTestCases() const
{
    STLSOFT_ASSERT(NULL != m_reporter);

    if (0u == m_failedConditions &&
        0u == m_unexpectedExceptions &&
        0u == m_expectedExceptions)
    {
        return 0u;
    }
    else
    {
        size_t numFailed = 0;

        { for (test_map_t::const_iterator b = m_testCases.begin(); b != m_testCases.end(); ++b)
        {
            TestInfo const& testInfo = (*b).second;

            if (!testInfo.haveAllTestsPassed())
            {
                ++numFailed;
            }
        }}

        return numFailed;
    }
}

void
RunnerInfo::Call_onTestFailed(
    xTests_Reporter_t* const    reporter
,   void*                       reporterParam
,   char const*                 file
,   int                         line
,   char const*                 function
,   char const*                 expr
,   xtests_variable_t const*    expectedValue
,   xtests_variable_t const*    actualValue
,   ptrdiff_t                   length
,   xtests_comparison_t         comparison
,   int                         verbosity
)
{
    if (verbosity != XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR ||
        0 == NumberOfFailedTestCases())
    {
        reporter->onTestFailed(reporterParam, file, line, function, expr, expectedValue, actualValue, length, comparison, verbosity);
    }
}

#ifdef STLSOFT_CF_NAMESPACE_SUPPORT
} // anonymous namespace
#endif /* STLSOFT_CF_NAMESPACE_SUPPORT */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef _XTESTS_NO_NAMESPACE
} /* namespace c */
} /* namespace xtests */
#endif /* !_XTESTS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * Windows debugging support
 */

#if XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_

# undef OutputDebugStringA
# include <windows.h>
static void xtests_OutputDebugStringA_(char const*s)
{
    OutputDebugStringA(s);
}
#endif /* XTESTS_SUPPORT_WINDOWS_OUTPUTDEBUGSTRING_ */


/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#include "xtests.internal.string.c"

/* ///////////////////////////// end of file //////////////////////////// */

