
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

size_t
xtests_strnlen_(
    char const* s
,   size_t      limit
)
{
    size_t n = 0;

    for(; 0 != limit && '\0' != *s; --limit, ++s)
    {
        ++n;
    }

    return n;
}

size_t
xtests_wcsnlen_(
    wchar_t const*  s
,   size_t          limit
)
{
    size_t n = 0;

    for(; 0 != limit && L'\0' != *s; --limit, ++s)
    {
        ++n;
    }

    return n;
}

void
xtests_strncpy_(
    char*           d
,   size_t          n
,   char const*     s
,   size_t          l
)
{
    if (l < n)
    {
        ::memcpy(d, s, sizeof(char) * l);
        d[l] = '\0';
    }
    else
    {
        ::memcpy(d, s, sizeof(char) * n);
    }
}

void
xtests_wcsncpy_(
    wchar_t*        d
,   size_t          n
,   wchar_t const*  s
,   size_t          l
)
{
    if (l < n)
    {
        ::memcpy(d, s, sizeof(wchar_t) * l);
        d[l] = '\0';
    }
    else
    {
        ::memcpy(d, s, sizeof(wchar_t) * n);
    }
}

size_t
xtests_strnlen_a_(
    char const*     s
,   size_t          limit
)
{
    size_t  n = 0;

    for(; '\0' != *s && n != limit; ++n, ++s)
    {}

    return n;
}

size_t
xtests_strnlen_w_(
    wchar_t const*  s
,   size_t          limit
)
{
    size_t  n = 0;

    for(; '\0' != *s && n != limit; ++n, ++s)
    {}

    return n;
}

int
xtests_strcmp_a_(
    char const*     str1
,   char const*     str2
)
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
        return ::strcmp(str1, str2);
    }
}

int
xtests_strcmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
)
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
        return ::wcscmp(str1, str2);
    }
}

int
xtests_stricmp_a_(
    char const*     str1
,   char const*     str2
)
{
    if (str1 == str2)
    {
        return 0;
    }
    else if (NULL == str1)
    {
        STLSOFT_ASSERT(NULL != str2);

        return -1;
    }
    else if (NULL == str2)
    {
        STLSOFT_ASSERT(NULL != str1);

        return +1;
    }
    else
    {
        const size_t    len1    =   ::strlen(str1);
        const size_t    len2    =   ::strlen(str2);
        char_buffer_t_  str1_(1 + len1);
        char_buffer_t_  str2_(1 + len2);

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        if (str1_.empty() ||
            str2_.empty())
        {
            return 1;
        }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        xtests_strcpy_(&str1_[0], str1_.size(), str1);
        xtests_strcpy_(&str2_[0], str2_.size(), str2);

        ::stlsoft::make_upper(str1_);
        ::stlsoft::make_upper(str2_);

        return ::strcmp(str1_.data(), str2_.data());
    }
}

int
xtests_stricmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
)
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
        const size_t        len1    =   ::wcslen(str1);
        const size_t        len2    =   ::wcslen(str2);
        char_buffer_w_t_    str1_(1 + len1);
        char_buffer_w_t_    str2_(1 + len2);

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        if (str1_.empty() ||
            str2_.empty())
        {
            return 1;
        }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        xtests_wcscpy_(&str1_[0], str1_.size(), str1);
        xtests_wcscpy_(&str2_[0], str2_.size(), str2);

        ::stlsoft::make_upper(str1_);
        ::stlsoft::make_upper(str2_);

        return ::wcscmp(str1_.data(), str2_.data());
    }
}

int
xtests_strncmp_a_(
    char const*     str1
,   char const*     str2
,   size_t          n
)
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
        return ::strncmp(str1, str2, n);
    }
}

int
xtests_strncmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
)
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
        return ::wcsncmp(str1, str2, n);
    }
}

int
xtests_strnicmp_a_(
    char const*     str1
,   char const*     str2
,   size_t          n
)
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
        const size_t    len1    =   xtests_strnlen_a_(str1, n);
        const size_t    len2    =   xtests_strnlen_a_(str2, n);
        char_buffer_t_  str1_(len1);
        char_buffer_t_  str2_(len2);

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        if (str1_.empty() ||
            str2_.empty())
        {
            return 1;
        }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        xtests_strncpy_(&str1_[0], str1_.size(), str1, len1);
        xtests_strncpy_(&str2_[0], str2_.size(), str2, len2);

        ::stlsoft::make_upper(str1_);
        ::stlsoft::make_upper(str2_);

        return ::strncmp(str1_.data(), str2_.data(), n);
    }
}

int
xtests_strnicmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
)
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
        const size_t        len1    =   xtests_strnlen_w_(str1, n);
        const size_t        len2    =   xtests_strnlen_w_(str2, n);
        char_buffer_w_t_    str1_(len1);
        char_buffer_w_t_    str2_(len2);

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        if (str1_.empty() ||
            str2_.empty())
        {
            return 1;
        }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        xtests_wcsncpy_(&str1_[0], str1_.size(), str1, len1);
        xtests_wcsncpy_(&str2_[0], str2_.size(), str2, len2);

        ::stlsoft::make_upper(str1_);
        ::stlsoft::make_upper(str2_);

        return ::wcsncmp(str1_.data(), str2_.data(), n);
    }
}

char const*
xtests_strstr_(
    char const*     str1
,   char const*     str2
)
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
        return ::strstr(str1, str2);
    }
}

wchar_t const*
xtests_strstr_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
)
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
        return ::wcsstr(str1, str2);
    }
}

char const*
xtests_stristr_(
    char const*     str1
,   char const*     str2
)
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
        const size_t    len1    =   ::strlen(str1);
        const size_t    len2    =   ::strlen(str2);
        char_buffer_t_  str1_(1 + len1);
        char_buffer_t_  str2_(1 + len2);

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        if (str1_.empty() ||
            str2_.empty())
        {
            return NULL;
        }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        xtests_strcpy_(&str1_[0], str1_.size(), str1);
        xtests_strcpy_(&str2_[0], str2_.size(), str2);

        ::stlsoft::make_upper(str1_);
        ::stlsoft::make_upper(str2_);

        return ::strstr(str1_.data(), str2_.data());
    }
}

wchar_t const*
xtests_stristr_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
)
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
        const size_t        len1    =   ::wcslen(str1);
        const size_t        len2    =   ::wcslen(str2);
        char_buffer_w_t_    str1_(1 + len1);
        char_buffer_w_t_    str2_(1 + len2);

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        if (str1_.empty() ||
            str2_.empty())
        {
            return NULL;
        }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        xtests_wcscpy_(&str1_[0], str1_.size(), str1);
        xtests_wcscpy_(&str2_[0], str2_.size(), str2);

        ::stlsoft::make_upper(str1_);
        ::stlsoft::make_upper(str2_);

        return ::wcsstr(str1_.data(), str2_.data());
    }
}

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


/* ///////////////////////////// end of file //////////////////////////// */

