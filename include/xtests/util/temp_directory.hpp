/* /////////////////////////////////////////////////////////////////////////
 * File:        xtests/util/temp_directory.hpp
 *
 * Purpose:     Definition of the temp_directory class.
 *
 * Created:     1st October 2015
 * Updated:     4th November 2015
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


/** \file xtests/util/temp_directory.hpp
 *
 * [C++ only] Definition of the temp_directory class.
 */

#ifndef XTESTS_INCL_XTESTS_UTIL_HPP_TEMP_DIRECTORY
#define XTESTS_INCL_XTESTS_UTIL_HPP_TEMP_DIRECTORY

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_DIRECTORY_MAJOR    0
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_DIRECTORY_MINOR    1
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_DIRECTORY_REVISION 7
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_DIRECTORY_EDIT     9
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
# error temp_directory can only be used in a compilation unit in which exception support is enabled
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#ifndef XTESTS_INCL_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION
# include <xtests/util/filesystem_exception.hpp>
#endif /* !XTESTS_INCL_XTESTS_UTIL_HPP_FILESYSTEM_EXCEPTION */

#include <platformstl/filesystem/directory_functions.hpp>
#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/readdir_sequence.hpp>

#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)

# include <errno.h>
# include <unistd.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

# include <comstl/util/guid.hpp>
#else

# error Operating system not discriminated
#endif

#include <stlsoft/memory/auto_buffer.hpp>

#include <stlsoft/shims/access/string/fwd.h>

#include <string>

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

/// Creates and manages a temporary directory for use in testing
class temp_directory
{
public: // Types
    /// The character type
    typedef char                            char_type;
    /// The size type
    typedef size_t                          size_type;
    /// This type
    typedef temp_directory                  class_type;

    /// Flags that control behaviour of ctor and/or dtor
    enum Flags
    {
            None                    =   0
        ,   EmptyOnOpen             =   0x0001
        ,   EmptyOnClose            =   0x0002
        ,   RemoveOnOpen            =   0x0004
        ,   RemoveOnClose           =   0x0008
    };

    class could_not_create_temporary_directory_exception;

private:
    typedef std::basic_string<char_type>                string_type_;
    typedef platformstl::filesystem_traits<char_type>   fs_traits_type_;
    typedef fs_traits_type_::file_handle_type           file_handle_type_;

public: // Construction
    /// Establishes an empty temporary file according to the given
    /// flags
    explicit temp_directory(Flags flags);
private:
    temp_directory(class_type const&);
    class_type& operator =(class_type const&);
public:
    ~temp_directory() STLSOFT_NOEXCEPT;

public: // Accessors
    /// Length of the path of the temporary directory
    size_type           size() const;
    /// C-style string pointer to the path of the temporary directory
    char_type const*    c_str() const;

private: // Implementation
    static
    void
    create_(
        Flags           flags
    ,   string_type_&   path
    );

    static
    void
    create_directory_(
        string_type_&   path
    );

    static
    bool
    remove_subdirectories_(
        string_type_&   path
    );

private: // Fields
    Flags const     m_flags;
    string_type_    m_path;
};

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

inline
temp_directory::Flags
operator |(
    temp_directory::Flags    lhs
,   temp_directory::Flags    rhs
)
{
    return static_cast<temp_directory::Flags>(int(lhs) | int(rhs));
}

#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

class temp_directory::could_not_create_temporary_directory_exception
    : public filesystem_exception
{
public: // Types
    typedef could_not_create_temporary_directory_exception  class_type;
private:
    typedef filesystem_exception                            parent_class_type;
public:
    typedef parent_class_type::result_code_type             result_code_type;

public: // Construction
    explicit
    could_not_create_temporary_directory_exception(
        result_code_type    rc
    );
    could_not_create_temporary_directory_exception(
        result_code_type    rc
    ,   char_type const*    message
    );
    could_not_create_temporary_directory_exception(
        result_code_type    rc
    ,   string_type const&  message
    );
};

inline
temp_directory::could_not_create_temporary_directory_exception::could_not_create_temporary_directory_exception(
    result_code_type    rc
)
    : parent_class_type(rc)
{}

inline
temp_directory::could_not_create_temporary_directory_exception::could_not_create_temporary_directory_exception(
    result_code_type    rc
,   char_type const*    message
)
    : parent_class_type(rc, message)
{}

inline
temp_directory::could_not_create_temporary_directory_exception::could_not_create_temporary_directory_exception(
    result_code_type    rc
,   string_type const&  message
)
    : parent_class_type(rc, message)
{}


inline
/* static */
bool
temp_directory::remove_subdirectories_(
    string_type_&   path
)
{
    // Can't use platformstl::remove_directory_recurse() because it
    // deletes the directory itself, so instead do a search for
    // all files and sub-directories and despatch them accordingly

    using ::platformstl::readdir_sequence;


    bool succeeded = true;


    readdir_sequence files(path, readdir_sequence::files | readdir_sequence::fullPath);

    { for(readdir_sequence::const_iterator i = files.begin(); files.end() != i; ++i)
    {
        if(!fs_traits_type_::delete_file(stlsoft::c_str_ptr(*i)))
        {
            succeeded = false;
        }
    }}


    readdir_sequence directories(path, readdir_sequence::directories | readdir_sequence::fullPath);

    { for(readdir_sequence::const_iterator i = directories.begin(); directories.end() != i; ++i)
    {
        if(!platformstl::remove_directory_recurse(*i))
        {
            succeeded = false;
        }
    }}


    return succeeded;
}


inline
/* static */
void
temp_directory::create_directory_(
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

                        if(fs_traits_type_::create_directory(buff.data()))
                        {
                            path.assign(buff.data(), n3 + comstl::COMSTL_CCH_GUID);

                            return;
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

    throw could_not_create_temporary_directory_exception(e, "could not create directory in any of the possible locations");
#else

    char tmp_path[] = "/tmp/xtests-temp-dir.XXXXXXXX";

# ifdef _WIN32
    char* const tmp_path_win_ = &tmp_path[0] + 4;
#  define tmp_path  tmp_path_win_
# endif

    if(NULL == ::mkdtemp(tmp_path))
    {
        int const e = errno;

        throw could_not_create_temporary_directory_exception(e, "could not create directory in any of the possible locations");
    }

    path = tmp_path;

# ifdef _WIN32
#  undef tmp_path
# endif

#endif
}

inline
/* static */
void
temp_directory::create_(
    temp_directory::Flags           flags
,   temp_directory::string_type_&   path
)
{
    // Algorithm:
    //
    // 1. Generate a unique, new directory name
    // 2. Empty it, if required
    // 3. Delete it, if required


    // 1. Generate a unique, new directory name

    create_directory_(path);

    // 2. Empty it, if required
    if(0 != (EmptyOnOpen & flags))
    {
        remove_subdirectories_(path);
    }

    // 3. Delete it, if required

    if(0 != (RemoveOnOpen & flags))
    {
        fs_traits_type_::remove_directory(path.c_str());
    }
}


inline
/* explicit */ temp_directory::temp_directory(
    temp_directory::Flags flags
)
    : m_flags(flags)
    , m_path()
{
    create_(m_flags, m_path);
}

inline
temp_directory::~temp_directory() STLSOFT_NOEXCEPT
{
    bool removed_recursively = false;

    if(0 != (EmptyOnClose & m_flags))
    {
        removed_recursively = remove_subdirectories_(m_path);
    }

    if( !removed_recursively &&
        0 != (RemoveOnClose & m_flags))
    {
        fs_traits_type_::remove_directory(m_path.c_str());
    }
}

inline
temp_directory::size_type
temp_directory::size() const
{
    return m_path.size();
}

inline
temp_directory::char_type const*
temp_directory::c_str() const
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
    temp_directory const& t
)
{
    return t.size();
}

inline
char const*
c_str_data_a(
    temp_directory const& t
)
{
    return t.c_str();
}

inline
char const*
c_str_ptr_a(
    temp_directory const& t
)
{
    return t.c_str();
}


inline
size_t
c_str_len(
    temp_directory const& t
)
{
    return t.size();
}

inline
char const*
c_str_data(
    temp_directory const& t
)
{
    return t.c_str();
}

inline
char const*
c_str_ptr(
    temp_directory const& t
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
        ::xtests::cpp::util::temp_directory const& t
    )
    {
        return t.size();
    }

    inline
    char const*
    c_str_data_a(
        ::xtests::cpp::util::temp_directory const& t
    )
    {
        return t.c_str();
    }

    inline
    char const*
    c_str_ptr_a(
        ::xtests::cpp::util::temp_directory const& t
    )
    {
        return t.c_str();
    }


    inline
    size_t
    c_str_len(
        ::xtests::cpp::util::temp_directory const& t
    )
    {
        return t.size();
    }

    inline
    char const*
    c_str_data(
        ::xtests::cpp::util::temp_directory const& t
    )
    {
        return t.c_str();
    }

    inline
    char const*
    c_str_ptr(
        ::xtests::cpp::util::temp_directory const& t
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

#endif /* XTESTS_INCL_XTESTS_UTIL_HPP_TEMP_DIRECTORY */

/* ///////////////////////////// end of file //////////////////////////// */

