



/*
 * macro:   XTESTS_EXCEPTION_TRY_
 *
 * purpose: starts a try block
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#define XTESTS_EXCEPTION_TRY_                           \
                                                        \
    try                                                 \
    {

#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
# define XTESTS_EXCEPTION_TRY_
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/*
 * macro:   XTESTS_EXCEPTION_CATCH_RETURN_int_
 *
 * purpose: has standard catches, return appropriate int values
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#define XTESTS_EXCEPTION_CATCH_RETURN_int_              \
                                                        \
    }                                                   \
    catch(std::bad_alloc&)                              \
    {                                                   \
        return -2;                                      \
    }                                                   \
    catch(std::exception&)                              \
    {                                                   \
        return -1;                                      \
    }                                                   \
    catch(...)                                          \
    {                                                   \
        return -3;                                      \
    }

#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
# define XTESTS_EXCEPTION_CATCH_RETURN_int_
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/*
 * macro:   XTESTS_EXCEPTION_CATCH_QUENCH_ALL_
 *
 * purpose: quenches all exceptions
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#define XTESTS_EXCEPTION_CATCH_QUENCH_ALL_              \
                                                        \
    }                                                   \
    catch(...)                                          \
    {}

#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
# define XTESTS_EXCEPTION_CATCH_QUENCH_ALL_
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/*
 * macro:   XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_(oom_msg, stdx_msg)
 *
 * purpose: handles std::bad_alloc and std::exception, with differing messages for each
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#define XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_(oom_msg, stdx_msg)          \
                                                                                    \
    }                                                                               \
    catch(std::bad_alloc& /* x */)                                                  \
    {                                                                               \
        xtests_output_(xtestsCritical, oom_msg " due to memory exhaustion\n");      \
                                                                                    \
        return 1;                                                                   \
    }                                                                               \
    catch(std::exception& x)                                                        \
    {                                                                               \
        std::string msg;                                                            \
                                                                                    \
        msg.reserve(200);                                                           \
                                                                                    \
        msg += stdx_msg ": ";                                                       \
        msg += x.what();                                                            \
        msg += "\n";                                                                \
                                                                                    \
        xtests_output_(xtestsCritical, msg.c_str());                                \
                                                                                    \
        return 1;                                                                   \
    }

#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
#define XTESTS_EXCEPTION_CATCH_CATCH_STD_WITH_MESSAGES_(oom_msg, stdx_msg)
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

/* ///////////////////////////// end of file //////////////////////////// */
