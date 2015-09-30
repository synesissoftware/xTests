/* /////////////////////////////////////////////////////////////////////////
 * File:        xtests/util/temp_file.hpp
 *
 * Purpose:     Definition of the temp_file class.
 *
 * Created:     8th May 2014
 * Updated:     6th September 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014, Matthew Wilson and Synesis Software
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
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_FILE_MINOR     0
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_FILE_REVISION  3
# define XTESTS_VER_XTESTS_UTIL_HPP_TEMP_FILE_EDIT      3
#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

# include <xtests/xtests.h>

#ifdef WIN32
# include <winstl/winstl.h>
#endif

# include <stlsoft/smartptr/scoped_handle.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error temp_file can only be used in a compilation unit in which exception support is enabled
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef _WIN32
# error Currently only defined for the Windows API
#endif /* !_WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace xtests
{
namespace cpp
{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

class temp_file
{
public: // Types
    typedef char                            char_type;
    typedef temp_file                       class_type;

    enum Flags
    {
            None            =   0
        ,   DeleteOnOpen    =   0x0001
        ,   DeleteOnClose   =   0x0002
    };

private:
    typedef std::basic_string<char_type>    string_type_;
    typedef HANDLE                          file_handle_type_;

public: // Construction
    /// Establishes an empty temporary file according to the given
    /// flags
    explicit temp_file(Flags flags);
    /// Establishes a non-empty temporary file according to the given
    /// flags
    temp_file(
        Flags       flags
    ,   void const* pv
    ,   size_t      cb
    );
private:
    temp_file(class_type const&);
    class_type& operator =(class_type const&);
public:
    ~temp_file() stlsoft_throw_0();

public: // Accessors
    char_type const*    c_str() const;

private: // Implementation
    static
    file_handle_type_
    create_(
        Flags           flags
    ,   string_type_&   path
    ,   void const*     pv
    ,   size_t          cb
    );

private: // Fields
    Flags const             m_flags;
    string_type_            m_path;
    file_handle_type_ const m_hFile;
};

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

inline
temp_file::Flags
operator |(
    temp_file::Flags    lhs
,   temp_file::Flags    rhs
)
{
    return static_cast<temp_file::Flags>(int(lhs) | int(rhs));
}

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef XTESTS_DOCUMENTATION_SKIP_SECTION

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
#ifndef INVALID_FILE_ATTRIBUTES
    DWORD const INVALID_FILE_ATTRIBUTES =   0xFFFFFFFF;
#endif /* !INVALID_FILE_ATTRIBUTES */

    char    tempPath[1 + MAX_PATH];
    DWORD   dw = ::GetTempFileNameA(".", "xtf", 0, &tempPath[0]);

    if(0 == dw)
    {
        XTESTS_TEST_FAIL("could not aquire temporary file");

        throw requirement_failed_exception("could not aquire temporary file");
    }

    path = tempPath;

    DWORD const attr1 = ::GetFileAttributesA(tempPath);

    if(0 != (DeleteOnOpen & flags))
    {
        if( INVALID_FILE_ATTRIBUTES != attr1 &&
            !::DeleteFileA(tempPath))
        {
            XTESTS_TEST_FAIL("could not delete temporary file");

            throw requirement_failed_exception("could not delete temporary file");
        }

        return INVALID_HANDLE_VALUE;
    }
    else
    {
        if(0 != cb)
        {
            HANDLE hFile = ::CreateFileA(tempPath, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

            if(INVALID_HANDLE_VALUE == hFile)
            {
                XTESTS_TEST_FAIL("could not open temporary file");

                throw requirement_failed_exception("could not open temporary file");
            }
            else
            {
                stlsoft::scoped_handle<HANDLE> scoper1(hFile, ::CloseHandle, INVALID_HANDLE_VALUE);

                if(NULL != pv)
                {
                    DWORD numWritten;

                    if(!::WriteFile(hFile, pv, static_cast<DWORD>(cb), &numWritten, NULL))
                    {
                        XTESTS_TEST_FAIL("could not write to temporary file");

                        throw requirement_failed_exception("could not write to temporary file");
                    }
                }
                else
                {
                    if( cb != ::SetFilePointer(hFile, static_cast<DWORD>(cb), NULL, SEEK_SET) ||
                        !::SetEndOfFile(hFile))
                    {
                        XTESTS_TEST_FAIL("could not set temporary file size");

                        throw requirement_failed_exception("could not set temporary file size");
                    }
                }
            }
        }

        return INVALID_HANDLE_VALUE;
    }
}


inline
/* explicit */ temp_file::temp_file(
    temp_file::Flags flags
)
    : m_flags(flags)
    , m_path()
    , m_hFile(create_(flags, m_path, NULL, 0))
{
    STLSOFT_ASSERT(INVALID_HANDLE_VALUE == m_hFile);
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
#if 0
    STLSOFT_ASSERT(INVALID_HANDLE_VALUE != m_hFile);
#endif /* 0 */
}

inline
temp_file::~temp_file() stlsoft_throw_0()
{
    ::CloseHandle(m_hFile);

    if(0 != (DeleteOnClose & m_flags))
    {
        ::DeleteFileA(m_path.c_str());
    }
}

inline
temp_file::char_type const*
temp_file::c_str() const
{
    return m_path.c_str();
}

#endif /* !XTESTS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace cpp */
} /* namespace xtests */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* XTESTS_INCL_XTESTS_UTIL_HPP_TEMP_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
