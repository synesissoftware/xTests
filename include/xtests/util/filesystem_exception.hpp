/* /////////////////////////////////////////////////////////////////////////
 * File:        xtests/util/filesystem_exception.hpp
 *
 * Purpose:     Definition of the filesystem_exception class.
 *
 * Created:     1st October 2015
 * Updated:     6th October 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2015, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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


/** \file xtests/util/filesystem_exception.hpp
 *
 * [C++ only] Definition of the filesystem_exception class.
 */

#ifndef XTESTS_INCL_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION
#define XTESTS_INCL_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION
# define XTESTS_VER_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION_MAJOR      0
# define XTESTS_VER_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION_MINOR      1
# define XTESTS_VER_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION_REVISION   2
# define XTESTS_VER_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION_EDIT       4
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 0
 */

#ifndef XTESTS_INCL_XTESTS_H_XTESTS
# include <xtests/xtests.h>
#endif /* !XTESTS_INCL_XTESTS_H_XTESTS */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error filesystem_exception can only be used in a compilation unit in which exception support is enabled
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <stlsoft/stlsoft.h>

#if defined(STLSOFT_LEAD_VER) && \
    STLSOFT_LEAD_VER >= 0x010a0114
# error Sort for 1.10 (alpha 20)+
#else
#endif

#include <platformstl/error/exceptions.hpp>
#include <platformstl/system/system_traits.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

namespace xtests
{
namespace cpp
{
namespace util
{

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

class filesystem_exception
    : public prerequisite_failed_exception
{
public: // Types
    typedef filesystem_exception                    class_type;
private:
    typedef prerequisite_failed_exception           parent_class_type;
public:
    typedef char                                    char_type;
private:
    typedef platformstl::system_traits<char_type>   traits_type_;
public:
    typedef traits_type_::result_code_type          result_code_type;
protected:
    class                                           embedded_exception_type
        : public platformstl::platform_exception
    {
    public: // Types
        typedef embedded_exception_type             class_type;
        typedef platformstl::platform_exception     parent_class_type;
        typedef parent_class_type::string_type      string_type;

    public: // Construction
        explicit
        class_type(
            result_code_type rc
        )
            : parent_class_type(rc)
        {}
        class_type(
            result_code_type    rc
        ,   char_type const*    message
        )
            : parent_class_type(message, rc)
        {}
        class_type(
            result_code_type    rc
        ,   string_type const&  message
        )
            : parent_class_type(message, rc)
        {}
    };
public:
    typedef traits_type_::result_code_type          result_code_type;
    typedef embedded_exception_type::string_type    string_type;

protected: // Construction
    explicit
    filesystem_exception(
        result_code_type    code
    );
    filesystem_exception(
        result_code_type    code
    ,   char_type const*    message
    );
    filesystem_exception(
        result_code_type    code
    ,   string_type const&  message
    );

public: // Overrides
    /* virtual */ char const* what() const
    {
        return m_embedded.what();
    }

private: // Fields
    embedded_exception_type const   m_embedded;
};

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

inline
filesystem_exception::filesystem_exception(
    result_code_type    rc
)
    : m_embedded(rc)
{}

inline
filesystem_exception::filesystem_exception(
    result_code_type    rc
,   char_type const*    message
)
    : m_embedded(rc, message)
{}

inline
filesystem_exception::filesystem_exception(
    result_code_type    rc
,   string_type const&  message
)
    : m_embedded(rc, message)
{}

#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

} /* namespace util */
} /* namespace cpp */
} /* namespace xtests */

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

namespace stlsoft
{

	inline
	char const*
	c_str_ptr_a(
		::xtests::cpp::util::filesystem_exception const& x
	)
	{
		return x.what();
	}

	inline
	char const*
	c_str_ptr(
		::xtests::cpp::util::filesystem_exception const& x
	)
	{
		return c_str_ptr_a(x);
	}

} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* XTESTS_INCL_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */
