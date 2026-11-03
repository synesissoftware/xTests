
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

size_t
xTests_strnlen_(
    char const* s
,   size_t      limit
);
size_t
xTests_wcsnlen_(
    wchar_t const*  s
,   size_t          limit
);

void
xTests_strncpy_(
    char*           d
,   size_t          n
,   char const*     s
,   size_t          l
);
void
xTests_wcsncpy_(
    wchar_t*        d
,   size_t          n
,   wchar_t const*  s
,   size_t          l
);

size_t
xTests_strnlen_a_(
    char const*     s
,   size_t          limit
);
size_t
xTests_strnlen_w_(
    wchar_t const*  s
,   size_t          limit
);

int
xTests_strcmp_a_(
    char const*     str1
,   char const*     str2
);
int
xTests_strcmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

int
xTests_stricmp_a_(
    char const*     str1
,   char const*     str2
);
int
xTests_stricmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

int
xTests_strncmp_a_(
    char const*     str1
,   char const*     str2
,   size_t          n
);
int
xTests_strncmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
);

int
xTests_strnicmp_a_(
    char const*     str1
,   char const*     str2
,   size_t          n
);
int
xTests_strnicmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
);

char const*
xTests_strstr_(
    char const*     str1
,   char const*     str2
);
wchar_t const*
xTests_strstr_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

char const*
xTests_stristr_(
    char const*     str1
,   char const*     str2
);
wchar_t const*
xTests_stristr_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


/* ///////////////////////////// end of file //////////////////////////// */

