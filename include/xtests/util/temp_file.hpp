/* /////////////////////////////////////////////////////////////////////////
 * File:        xtests/util/temp_file.hpp
 *
 * Purpose:     Definition of the temp_file class.
 *
 * Created:     8th May 2014
 * Updated:     10th January 2017
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014-2017, Matthew Wilson and Synesis Software
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


/** \file xtests/util/temp_file.hpp
 *
 * [C++ only] Definition of the temp_file class.
 */

#ifndef XTESTS_INCL_XTESTS_UTIL_HPP_TEMP_FILE
#define XTESTS_INCL_XTESTS_UTIL_HPP_TEMP_FILE

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_FILE_MAJOR     0
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_FILE_MINOR     1
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_FILE_REVISION  9
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_FILE_EDIT      14
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
# error temp_file can only be used in a compilation unit in which exception support is enabled
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifndef XTESTS_INCL_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION
# include <xtests/util/filesystem_exception.hpp>
#endif /* !XTESTS_INCL_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION */

#include <platformstl/filesystem/filesystem_traits.hpp>

#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)

# include <errno.h>
# include <unistd.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

#  include <comstl/util/guid.hpp>
#  include <winstl/winstl.h>
#else

# error Operating system not discriminated
#endif

#include <stlsoft/conversion/truncation_cast.hpp>
#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/shims/access/string/fwd.h>
#include <stlsoft/smartptr/scoped_handle.hpp>

#include <string>

#include <stdio.h>

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
 * classes
 */

/// Creates and manages a temporary file for use in testing
class temp_file
{
public: // Types
    /// The character type
    typedef char                                            char_type;
    /// The size type
    typedef size_t                                          size_type;
    /// This type
    typedef temp_file                                       class_type;

    /// Flags that control behaviour of ctor and/or dtor
    enum Flags
    {
            None            =   0
        ,   DeleteOnClose   =   0x0002
        ,   EmptyOnOpen     =   0x0004
        ,   EmptyOnClose    =   0x0008
        ,   DeleteOnOpen    =   0x0010
        ,   CloseOnOpen     =   0x0020
    };

    class could_not_create_temporary_file_exception;

private:
    typedef std::basic_string<char_type>                string_type_;
    typedef platformstl::filesystem_traits<char_type>   fs_traits_type_;
    typedef fs_traits_type_::file_handle_type           file_handle_type_;

public: // Construction
    /// Establishes an empty temporary file according to the given
    /// flags
    explicit
    temp_file(Flags flags);
    /// Establishes a non-empty temporary file according to the given
    /// flags
    temp_file(
        Flags       flags
    ,   void const* pv
    ,   size_t      cb
    );
private:
    temp_file(class_type const&);               // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed
public:
    ~temp_file() STLSOFT_NOEXCEPT;

public: // Accessors
    /// Length of the path of the temporary file
    size_type           size() const;
    /// C-style string pointer to the path of the temporary file
    char_type const*    c_str() const;

private: // Implementation
    static
    file_handle_type_
    create_file_(
        string_type_&   path
    );

    static
    file_handle_type_
    create_(
        Flags           flags
    ,   string_type_&   path
    ,   void const*     pv
    ,   size_t          cb
    );

    static
    fs_traits_type_::result_code_type
    empty_file_(
        file_handle_type_ hFile
    );

private: // Fields
    Flags const             m_flags;
    string_type_            m_path;
    file_handle_type_ const m_hFile;
};

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

inline
temp_file::Flags
operator |(
    temp_file::Flags    lhs
,   temp_file::Flags    rhs
)
{
    return static_cast<temp_file::Flags>(int(lhs) | int(rhs));
}

#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

class temp_file::could_not_create_temporary_file_exception
    : public filesystem_exception
{
public: // Types
    typedef could_not_create_temporary_file_exception  class_type;
private:
    typedef filesystem_exception                            parent_class_type;
public:
    typedef parent_class_type::result_code_type             result_code_type;

public: // Construction
    explicit
    could_not_create_temporary_file_exception(
        result_code_type    rc
    );
    could_not_create_temporary_file_exception(
        result_code_type    rc
    ,   char_type const*    message
    );
    could_not_create_temporary_file_exception(
        result_code_type    rc
    ,   string_type const&  message
    );
};

inline
temp_file::could_not_create_temporary_file_exception::could_not_create_temporary_file_exception(
    result_code_type    rc
)
    : parent_class_type(rc)
{}

inline
temp_file::could_not_create_temporary_file_exception::could_not_create_temporary_file_exception(
    result_code_type    rc
,   char_type const*    message
)
    : parent_class_type(rc, message)
{}

inline
temp_file::could_not_create_temporary_file_exception::could_not_create_temporary_file_exception(
    result_code_type    rc
,   string_type const&  message
)
    : parent_class_type(rc, message)
{}


inline
/* static */
temp_file::fs_traits_type_::result_code_type
temp_file::empty_file_(
    temp_file::file_handle_type_ hFile
)
{
#if defined(PLATFORMSTL_OS_IS_WINDOWS)

    if( INVALID_SET_FILE_POINTER == ::SetFilePointer(hFile, 0, NULL, SEEK_SET) ||
        !::SetEndOfFile(hFile))
    {
        DWORD const e = ::GetLastError();

        return e;
    }

    return ERROR_SUCCESS;
#else

    if(off_t(-1) == ::lseek(hFile, SEEK_SET, 0))
    {
        return errno;
    }

    return 0;
#endif
}


inline
/* static */
temp_file::file_handle_type_
temp_file::create_file_(
    string_type_&   path
)
{
    //
    // This is done by:
    //
    // - getting a unique path name
    //

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

    // On Windows, we'll work in one of %TEMP%, %TMP%, %USERPROFILE%, or

    static LPCSTR const s_roots[] =
    {
            "%TEMP%"
        ,   "%TMP%"
        ,   "%USERPROFILE%"
        ,   "."
    };

    comstl::guid                unique_name;
    DWORD                       e = ERROR_SUCCESS;
    stlsoft::auto_buffer<char>  buff(1);

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(s_roots); )
    {
        LPCSTR const root = s_roots[i];

        size_t n1 = fs_traits_type_::expand_environment_strings(root, NULL, 0);

        if(0 != n1)
        {
            if(buff.resize(n1))
            {
                size_t const n2 = fs_traits_type_::expand_environment_strings(root, &buff[0], buff.size() + (1 + comstl::COMSTL_CCH_GUID));

                if(0 != n2)
                {
                    if(n2 < buff.size() - (1 + comstl::COMSTL_CCH_GUID))
                    {
                        fs_traits_type_::ensure_dir_end(&buff[0] + (n2 - 2));

                        size_t const    n3  =   fs_traits_type_::str_len(buff.data());
                        char* const     p3  =   buff.data() + n3;

                        fs_traits_type_::char_copy(p3, stlsoft::c_str_ptr_a(unique_name), comstl::COMSTL_CCH_GUID);
                        p3[comstl::COMSTL_CCH_GUID] = '\0';

                        file_handle_type_ const hFile = fs_traits_type_::create_file(buff.data(), GENERIC_WRITE, 0, NULL, CREATE_NEW, 0, NULL);

                        if(fs_traits_type_::invalid_file_handle_value() != hFile)
                        {
                            path.assign(buff.data(), n3 + comstl::COMSTL_CCH_GUID);

                            return hFile;
                        }
                        else
                        {
                            e = fs_traits_type_::get_last_error();
                        }
                    }
                }
            }
        }

        ++i;
    }}

    throw could_not_create_temporary_file_exception(e, "could not create file in any of the possible locations");
#else

    char tmp_path[] = "/tmp/xtests-temp-dir.XXXXXXXX";

# ifdef _WIN32
    // Can't bank on "/tmp" directory existing, so just do it in "./"
    char* const tmp_path_win_ = &tmp_path[0] + 3;
    0[tmp_path_win_] = '.';
#  define tmp_path  tmp_path_win_
# endif

    int f;

    if(-1 != (f = ::mkstemp(tmp_path)))
    {
        file_handle_type_ const hFile = fs_traits_type_::open_file(tmp_path, O_WRONLY | O_CREAT | O_TRUNC, S_IWRITE);

        int const e = errno;

        fs_traits_type_::close_file(f);

        errno = e;

        if(fs_traits_type_::invalid_file_handle_value() != hFile)
        {
            path = tmp_path;

            return hFile;
        }
    }

    int const e = errno;

    throw could_not_create_temporary_file_exception(e, "could not create file in any of the possible locations");

# ifdef _WIN32
#  undef tmp_path
# endif

#endif
}

inline
/* static */
temp_file::file_handle_type_
temp_file::create_(
    temp_file::Flags            flags
,   temp_file::string_type_&    path
,   void const*                 pv
,   size_t                      cb
)
{
    STLSOFT_ASSERT(0 == cb || NULL != pv);

    // Algorithm:
    //
    // 1. Generate a unique, new file name
    // 2. Empty it, if required
    // 3. Write the contents, if specified


    // 1. Generate a unique, new file name

    file_handle_type_ const hFile = create_file_(path);


    if(fs_traits_type_::invalid_file_handle_value() == hFile)
    {
        fs_traits_type_::result_code_type const rc = fs_traits_type_::get_last_error();

        throw could_not_create_temporary_file_exception(rc, "could not create file");
    }

    if(0 != (DeleteOnOpen & flags))
    {
        fs_traits_type_::close_file(hFile);

        fs_traits_type_::delete_file(path.c_str());

        return fs_traits_type_::invalid_file_handle_value();
    }


    stlsoft::scoped_handle<fs_traits_type_::file_handle_type> scoper(hFile, fs_traits_type_::close_file, fs_traits_type_::invalid_file_handle_value());

    // 2. Empty it, if required

    if(0 != (EmptyOnOpen & flags))
    {
        fs_traits_type_::result_code_type const rc = empty_file_(hFile);

        if(0 != rc)
        {
            throw could_not_create_temporary_file_exception(rc, "could not reset contents of temporary file");
        }
    }

    // 3. Write the contents, if specified

    if(0 != cb)
    {
# if 0
# elif defined(PLATFORMSTL_OS_IS_UNIX)

        int const r = write(hFile, pv, static_cast<unsigned int>(cb));

        if(r < 0)
        {
            int const e = errno;

            throw could_not_create_temporary_file_exception(e, "could not write file contents");
        }

# elif defined(PLATFORMSTL_OS_IS_WINDOWS)

        DWORD numWritten;

        if(!::WriteFile(hFile, pv, stlsoft::truncation_cast<DWORD>(cb), &numWritten, NULL))
        {
            DWORD const e = ::GetLastError();

            throw could_not_create_temporary_file_exception(e, "could not write file contents");
        }
# else
#  error Platform not discrminated
# endif
    }

    if(0 != (CloseOnOpen & flags))
    {
        scoper.close();
    }

    return scoper.detach();
}


inline
/* explicit */ temp_file::temp_file(
    temp_file::Flags flags
)
    : m_flags(flags)
    , m_path()
    , m_hFile(create_(flags, m_path, NULL, 0))
{
    STLSOFT_ASSERT(fs_traits_type_::invalid_file_handle_value() != m_hFile || 0 != (CloseOnOpen & m_flags) || 0 != (DeleteOnOpen & m_flags));
}

inline
/* explicit */ temp_file::temp_file(
    Flags       flags
,   void const* pv
,   size_t      cb
)
    : m_flags(flags)
    , m_path()
    , m_hFile(create_(flags, m_path, pv, cb))
{
    STLSOFT_ASSERT(fs_traits_type_::invalid_file_handle_value() != m_hFile || 0 != (CloseOnOpen & m_flags) || 0 != (DeleteOnOpen & m_flags));
}

inline
temp_file::~temp_file() STLSOFT_NOEXCEPT
{
    if(0 != (EmptyOnClose & m_flags))
    {
        empty_file_(m_hFile);
    }

    if(fs_traits_type_::invalid_file_handle_value() != m_hFile)
    {
        fs_traits_type_::close_file(m_hFile);
    }

    if(0 != (DeleteOnClose & m_flags))
    {
        fs_traits_type_::delete_file(m_path.c_str());
    }
}

inline
temp_file::size_type
temp_file::size() const
{
    return m_path.size();
}

inline
temp_file::char_type const*
temp_file::c_str() const
{
    return m_path.c_str();
}

#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

inline
size_t
c_str_len_a(
    temp_file const& t
)
{
    return t.size();
}

inline
char const*
c_str_data_a(
    temp_file const& t
)
{
    return t.c_str();
}

inline
char const*
c_str_ptr_a(
    temp_file const& t
)
{
    return t.c_str();
}


inline
size_t
c_str_len(
    temp_file const& t
)
{
    return t.size();
}

inline
char const*
c_str_data(
    temp_file const& t
)
{
    return t.c_str();
}

inline
char const*
c_str_ptr(
    temp_file const& t
)
{
    return t.c_str();
}

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

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

# if !defined(_STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_NO_NAMESPACE)
namespace stlsoft
{
# endif

    inline
    size_t
    c_str_len_a(
        ::xtests::cpp::util::temp_file const& t
    )
    {
        return t.size();
    }

    inline
    char const*
    c_str_data_a(
        ::xtests::cpp::util::temp_file const& t
    )
    {
        return t.c_str();
    }

    inline
    char const*
    c_str_ptr_a(
        ::xtests::cpp::util::temp_file const& t
    )
    {
        return t.c_str();
    }


    inline
    size_t
    c_str_len(
        ::xtests::cpp::util::temp_file const& t
    )
    {
        return t.size();
    }

    inline
    char const*
    c_str_data(
        ::xtests::cpp::util::temp_file const& t
    )
    {
        return t.c_str();
    }

    inline
    char const*
    c_str_ptr(
        ::xtests::cpp::util::temp_file const& t
    )
    {
        return t.c_str();
    }

# if !defined(_STLSOFT_NO_NAMESPACE) && \
    !defined(STLSOFT_NO_NAMESPACE)
} /* namespace stlsoft */
# endif

#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* XTESTS_INCL_XTESTS_UTIL_HPP_TEMP_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
