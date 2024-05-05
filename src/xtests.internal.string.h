
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

size_t
xtests_strnlen_(
    char const* s
,   size_t      limit
);
size_t
xtests_wcsnlen_(
    wchar_t const*  s
,   size_t          limit
);

void
xtests_strncpy_(
    char*           d
,   size_t          n
,   char const*     s
,   size_t          l
);
void
xtests_wcsncpy_(
    wchar_t*        d
,   size_t          n
,   wchar_t const*  s
,   size_t          l
);

size_t
xtests_strnlen_a_(
    char const*     s
,   size_t          limit
);
size_t
xtests_strnlen_w_(
    wchar_t const*  s
,   size_t          limit
);

int
xtests_strcmp_a_(
    char const*     str1
,   char const*     str2
);
int
xtests_strcmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

int
xtests_stricmp_a_(
    char const*     str1
,   char const*     str2
);
int
xtests_stricmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

int
xtests_strncmp_a_(
    char const*     str1
,   char const*     str2
,   size_t          n
);
int
xtests_strncmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
);

int
xtests_strnicmp_a_(
    char const*     str1
,   char const*     str2
,   size_t          n
);
int
xtests_strnicmp_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
,   size_t          n
);

char const*
xtests_strstr_(
    char const*     str1
,   char const*     str2
);
wchar_t const*
xtests_strstr_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

char const*
xtests_stristr_(
    char const*     str1
,   char const*     str2
);
wchar_t const*
xtests_stristr_w_(
    wchar_t const*  str1
,   wchar_t const*  str2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


/* ///////////////////////////// end of file //////////////////////////// */

