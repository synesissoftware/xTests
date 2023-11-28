############################################################################
# File:     makefile
#
# Purpose:  Makefile for the xTests:C project,
#           for the Visual C++ 6.0 (UNIXem) compiler,
#           on the UNIX platform
#
# Created:  16th December 2007
# Updated:  29th November 2023
#
############################################################################


############################################################################
# environment check

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

!ifndef PTHREADS_WIN32
!error PTHREADS_WIN32 must be defined
!endif # !PTHREADS_WIN32

!ifndef UNIXEM
!error UNIXEM must be defined
!endif # !UNIXEM

############################################################################
# symbols

########################################
# project & compiler version

COMP_TAG            =   vc6
ARCH_TAG            =   
OS_TAG              =   .unix
PROJ_TAG			=	xtests
PROJ_VER_MAJOR      =   0
PROJ_MOD_TAG        =   core
PROJ_TAG_VER        =   $(PROJ_TAG).$(PROJ_VER_MAJOR).$(PROJ_MOD_TAG)
COMP_ARCH_OS_TAG    =   $(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

########################################
# dependencies

SHWILD_VER_MAJOR    =   0
SHWILD_TAG_VER      =   shwild.$(SHWILD_VER_MAJOR)

XCOVER_VER_MAJOR    =   0
XCOVER_TAG_VER      =   xcover.$(XCOVER_VER_MAJOR)

UNIXEM_VER_MAJOR    =   1
UNIXEM_TAG_VER      =   unixem.$(XTESTS_VER_MAJOR)

PROJ_MAKEFILE_NAME  =   makefile

########################################
# testing verbosity

TEST_VERBOSITY      =   2


############################################################################
# directories

########################################
# project directories

PROJ_BASE_DIR           =   ..\..
PROJ_BIN_DIR            =   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR        =   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR            =   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR            =   .
PROJ_SRC_DIR            =   $(PROJ_BASE_DIR)\src
PROJ_EXAMPLES_DIR       =   $(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR        =   $(PROJ_BASE_DIR)\samples
PROJ_TEST_ROOT_DIR      =   $(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR =   $(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_SCRATCH_DIR   =   $(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR      =   $(PROJ_TEST_ROOT_DIR)\unit

########################################
# 3rd-party directories

SHWILD_PROJ_INCLUDE		=	
!ifdef XTESTS_SHWILD_BASE_DIR
SHWILD_INCLUDE_DIR		=   $(XTESTS_SHWILD_BASE_DIR)\include
SHWILD_SRC_DIR			=   $(XTESTS_SHWILD_BASE_DIR)\src
SHWILD_PROJ_INCLUDE		=	-I$(SHWILD_INCLUDE_DIR)
!else
SHWILD_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
SHWILD_SRC_DIR			=   $(PROJ_SRC_DIR)\shwild
!endif # !XTESTS_SHWILD_BASE_DIR

############################################################################
# tools

CC                      =   cl
CPPC                    =   cl
AR                      =   lib
LD                      =   link
RM                      =   del /f
CP                      =   copy
RC                      =   rc

############################################################
# compiler

########################################
# includes

INCLUDES_LEADER         =   

PROJ_INCLUDE            =   -I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES         =   -I$(SYNESIS_DEV)/include -I$(SYNESIS_DEV)/libraries/include

STLSOFT_INCLUDES		=\
 -I"$(STLSOFT)\include"\
 \

THIRDPARTY_INCLUDES		=\
 $(SHWILD_PROJ_INCLUDE)\
 -I"$(PTHREADS_WIN32)\include"\
 -I"$(UNIXEM)\include"\
 \

# CC

CC_INCLUDES_BASE =\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(STLSOFT_INCLUDES)\
 $(THIRDPARTY_INCLUDES)\
 \

CC_INCLUDES_UX_MT_D =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_UX_MT_R =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_UX_ST_D =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_UX_ST_R =\
 $(CC_INCLUDES_BASE)\
 \


CC_SHWILD_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_UX_MT_D =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_UX_MT_R =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_UX_ST_D =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_UX_ST_R =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \


CC_XTESTS_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_UX_MT_D =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_UX_MT_R =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_UX_ST_D =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_UX_ST_R =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \


CC_INCLUDES_TEST=\
 $(CC_INCLUDES_BASE)\
 \

# CPPC

CPPC_INCLUDES_BASE =\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(STLSOFT_INCLUDES)\
 $(THIRDPARTY_INCLUDES)\
 \

CPPC_INCLUDES_UX_MT_D =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_UX_MT_R =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_UX_ST_D =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_UX_ST_R =\
 $(CPPC_INCLUDES_BASE)\
 \


CPPC_SHWILD_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_UX_MT_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_UX_MT_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_UX_ST_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_UX_ST_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_UX_MT_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_UX_MT_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_UX_ST_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_UX_ST_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \


CPPC_INCLUDES_TEST=\
 $(CPPC_INCLUDES_BASE)\
 \

########################################
# defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DXTESTS_NO_IMPLICIT_LINK\
 \

COMMON_DEFS             =   -DUNIX

CUSTOM_DEFS             =

# CC

CC_CUSTOM_DEFS          =   $(CUSTOM_DEFS)

CC_DEFS_BASE =\
 $(CC_CUSTOM_DEFS)\
 $(COMMON_DEFS)\
 \

CC_DEFS_UX_MT_D =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_UX_MT_R =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_UX_ST_D =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_UX_ST_R =\
 $(CC_DEFS_BASE)\
 \


# CPPC

CPPC_CUSTOM_DEFS        =   $(CUSTOM_DEFS)

CPPC_DEFS_BASE =\
 $(CPPC_CUSTOM_DEFS)\
 $(COMMON_DEFS)\
 \

CPPC_DEFS_UX_MT_D =\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_UX_MT_R =\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_UX_ST_D =\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_UX_ST_R =\
 $(CPPC_DEFS_BASE)\
 \


########################################
# flags

# CC

CC_F_NOLOGO             =   -nologo
CC_F_COMPILE_ONLY       =   -c
CC_F_FORCE_INCLUDE      =   
CC_F_WARNING_MAX        =   -W3
CC_F_WARNING_ERR        =   -WX
CC_F_MINIMUM_SIZE       =   -O1
CC_F_MAXIMUM_SPEED      =   -O2

CC_TOOL_FLAGS           =   

CC_FLAGS_BASE =\
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_FORCE_INCLUDE)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CC_FLAGS_UX_MT_D =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_UX_MT_R =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_UX_ST_D =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_UX_ST_R =\
 $(CC_FLAGS_BASE)\
 \

#CPPC

CPPC_F_NOLOGO           =   -nologo
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_FORCE_INCLUDE    =   
CPPC_F_WARNING_MAX      =   -W3
CPPC_F_WARNING_ERR      =   -WX
CPPC_F_EXCEPTIONS_ON    =   -GX
CPPC_F_EXCEPTIONS_OFF   =   -GX-
CPPC_F_EXCEPTIONS       =   
CPPC_F_RTTI_ON          =   -GR
CPPC_F_RTTI_OFF         =   -GR-
CPPC_F_RTTI             =   
CPPC_F_MINIMUM_SIZE     =   -O1
CPPC_F_MAXIMUM_SPEED    =   -O2

CPPC_TOOL_FLAGS         =   

CPPC_FLAGS_BASE =\
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_FORCE_INCLUDE)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

CPPC_FLAGS_UX_MT_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_UX_MT_R =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_UX_ST_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_UX_ST_R =\
 $(CPPC_FLAGS_BASE)\
 \


########################################
# arguments

# CC args (= flags + defines + includes)

CC_ARGS_UX_MT_D=\
 $(CC_FLAGS_UX_MT_D)\
 $(CC_DEFS_UX_MT_D)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_UX_MT_D)\
 -MTd -Zi -Fd$*.pdb -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -D_REENTRANT -DUNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS $(CC_CUSTOM_DEFS_DEBUG)
CC_ARGS_UX_MT_D_TEST=\
 $(CC_FLAGS_UX_MT_D)\
 $(CC_DEFS_UX_MT_D)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 -MTd -Zi -Fd$*.pdb -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -D_REENTRANT -DUNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS $(CC_CUSTOM_DEFS_DEBUG)\
 $(CC_INCLUDES_TEST)
CC_ARGS_UX_MT_R=\
 $(CC_FLAGS_UX_MT_R)\
 $(CC_DEFS_UX_MT_R)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_UX_MT_R)\
 -MT -DNDEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CC_F_MAXIMUM_SPEED) $(CC_CUSTOM_DEFS_RELEASE)
CC_ARGS_UX_MT_R_TEST=\
 $(CC_FLAGS_UX_MT_R)\
 $(CC_DEFS_UX_MT_R)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 -MT -DNDEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CC_F_MAXIMUM_SPEED) $(CC_CUSTOM_DEFS_RELEASE)\
 $(CC_INCLUDES_TEST)
CC_ARGS_UX_ST_D=\
 $(CC_FLAGS_UX_ST_D)\
 $(CC_DEFS_UX_ST_D)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_UX_ST_D)\
 -MLd -Zi -Fd$*.pdb -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CC_CUSTOM_DEFS_DEBUG)
CC_ARGS_UX_ST_D_TEST=\
 $(CC_FLAGS_UX_ST_D)\
 $(CC_DEFS_UX_ST_D)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 -MLd -Zi -Fd$*.pdb -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CC_CUSTOM_DEFS_DEBUG)\
 $(CC_INCLUDES_TEST)
CC_ARGS_UX_ST_R=\
 $(CC_FLAGS_UX_ST_R)\
 $(CC_DEFS_UX_ST_R)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CC_INCLUDES_UX_ST_R)\
 -ML -DNDEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CC_CUSTOM_DEFS_RELEASE)
CC_ARGS_UX_ST_R_TEST=\
 $(CC_FLAGS_UX_ST_R)\
 $(CC_DEFS_UX_ST_R)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 -ML -DNDEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CC_CUSTOM_DEFS_RELEASE)\
 $(CC_INCLUDES_TEST)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_UX_MT_D=\
 $(CPPC_FLAGS_UX_MT_D)\
 $(CPPC_DEFS_UX_MT_D)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CPPC_INCLUDES_UX_MT_D)\
 -MTd -Zi -Fd$*.pdb -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -D_REENTRANT -DUNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS $(CPPC_F_WITH_EXCEPTIONS) $(CPPC_CUSTOM_DEFS_DEBUG)
CPPC_ARGS_UX_MT_D_TEST=\
 $(CPPC_FLAGS_UX_MT_D)\
 $(CPPC_DEFS_UX_MT_D)\
 -MTd -Zi -Fd$*.pdb -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -D_REENTRANT -DUNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS $(CPPC_F_WITH_EXCEPTIONS) $(CPPC_CUSTOM_DEFS_DEBUG)\
 $(CPPC_INCLUDES_TEST)
CPPC_ARGS_UX_MT_R=\
 $(CPPC_FLAGS_UX_MT_R)\
 $(CPPC_DEFS_UX_MT_R)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CPPC_INCLUDES_UX_MT_R)\
 -MT -DNDEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CPPC_F_WITH_EXCEPTIONS) $(CPPC_F_MAXIMUM_SPEED) $(CPPC_CUSTOM_DEFS_RELEASE)
CPPC_ARGS_UX_MT_R_TEST=\
 $(CPPC_FLAGS_UX_MT_R)\
 $(CPPC_DEFS_UX_MT_R)\
 -MT -DNDEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CPPC_F_WITH_EXCEPTIONS) $(CPPC_F_MAXIMUM_SPEED) $(CPPC_CUSTOM_DEFS_RELEASE)\
 $(CPPC_INCLUDES_TEST)
CPPC_ARGS_UX_ST_D=\
 $(CPPC_FLAGS_UX_ST_D)\
 $(CPPC_DEFS_UX_ST_D)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CPPC_INCLUDES_UX_ST_D)\
 -MLd -Zi -Fd$*.pdb -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) $(CPPC_CUSTOM_DEFS_DEBUG)
CPPC_ARGS_UX_ST_D_TEST=\
 $(CPPC_FLAGS_UX_ST_D)\
 $(CPPC_DEFS_UX_ST_D)\
 -MLd -Zi -Fd$*.pdb -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) $(CPPC_CUSTOM_DEFS_DEBUG)\
 $(CPPC_INCLUDES_TEST)
CPPC_ARGS_UX_ST_R=\
 $(CPPC_FLAGS_UX_ST_R)\
 $(CPPC_DEFS_UX_ST_R)\
 $(CMN_DEF_NO_IMPLICIT_LINK)\
 $(CPPC_INCLUDES_UX_ST_R)\
 -ML -DNDEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) $(CPPC_CUSTOM_DEFS_RELEASE)
CPPC_ARGS_UX_ST_R_TEST=\
 $(CPPC_FLAGS_UX_ST_R)\
 $(CPPC_DEFS_UX_ST_R)\
 -ML -DNDEBUG -D_STLSOFT_FORCE_ANY_COMPILER $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) $(CPPC_CUSTOM_DEFS_RELEASE)\
 $(CPPC_INCLUDES_TEST)

############################################################
# archiver

AR_F_NOLOGO             =   -nologo

AR_ARGS                 =   -nologo

############################################################
# linker

########################################
# flags

LD_F_NOLOGO             =   -nologo

LD_FLAGS_BASE           =\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_UX_MT_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_UX_MT_R =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_UX_ST_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_UX_ST_R =\
 $(LD_FLAGS_BASE)\
 \


########################################
# paths

LIBPATHS_ENV            =

LIBPATHS_COMMON         =   -libpath:$(SYNESIS_DEV)/lib 

LIBPATHS_3PTY           =\
 -libpath:"$(PTHREADS_WIN32)\lib"\
 -libpath:"$(UNIXEM)\lib"\
 \

LIBPATHS=\
 $(LIBPATHS_COMMON)\
 $(LIBPATHS_3PTY)\
 $(LIBPATHS_ENV)\
 \

LIBPATHS_TEST =\
 $(LIBPATHS)\
 -libpath:$(OPENRJ_ROOT)\lib\
 \

########################################
# arguments

LD_ARGS_UX_MT_D      =   libWinSysLog.vc6.debug.lib unixem.1.vc6.mt.debug.lib -debug $(LD_FLAGS_UX_MT_D) $(LIBPATHS)
LD_ARGS_UX_MT_D_TEST =   libWinSysLog.vc6.debug.lib unixem.1.vc6.mt.debug.lib -debug $(LD_FLAGS_UX_MT_D) $(LIBPATHS_TEST)
LD_ARGS_UX_MT_R      =   libWinSysLog.$(COMP_TAG).mt.lib unixem.1.$(COMP_TAG).mt.lib -release $(LD_FLAGS_UX_MT_R) $(LIBPATHS)
LD_ARGS_UX_MT_R_TEST =   libWinSysLog.$(COMP_TAG).mt.lib unixem.1.$(COMP_TAG).mt.lib -release $(LD_FLAGS_UX_MT_R) $(LIBPATHS_TEST)
LD_ARGS_UX_ST_D      =   libWinSysLog.vc6.debug.lib unixem.1.vc6.debug.lib -debug $(LD_FLAGS_UX_ST_D) $(LIBPATHS)
LD_ARGS_UX_ST_D_TEST =   libWinSysLog.vc6.debug.lib unixem.1.vc6.debug.lib -debug $(LD_FLAGS_UX_ST_D) $(LIBPATHS_TEST)
LD_ARGS_UX_ST_R      =   libWinSysLog.vc6.lib unixem.1.vc6.lib -release $(LD_FLAGS_UX_ST_R) $(LIBPATHS)
LD_ARGS_UX_ST_R_TEST =   libWinSysLog.vc6.lib unixem.1.vc6.lib -release $(LD_FLAGS_UX_ST_R) $(LIBPATHS_TEST)

############################################################################
# names

############################################################
# source

SRCS_HDR_CORE=\
 $(PROJ_INCLUDE_DIR)\xtests\xtests.h\
 $(PROJ_INCLUDE_DIR)\xtests\implicit_link.h\
 $(PROJ_INCLUDE_DIR)\xtests\internal\safestr.h\
 \
 $(PROJ_INCLUDE_DIR)\xtests\util\filesystem_exception.hpp\
 $(PROJ_INCLUDE_DIR)\xtests\util\path.hpp\
 $(PROJ_INCLUDE_DIR)\xtests\util\temp_directory.hpp\
 $(PROJ_INCLUDE_DIR)\xtests\util\temp_file.hpp\
 \

SHWILD_HEADERS=\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.h\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.hpp\
 \

############################################################
# objects / program-databases

########################################
# libraries

# core

OBJ_lib_core_UX_MT_D         =   $(PROJ_OBJ_DIR)\core.mt.debug.obj
PDB_lib_core_UX_MT_D         =   $(PROJ_OBJ_DIR)\core.mt.debug.pdb

OBJS_CORE_UX_MT_D=\
 $(OBJ_lib_core_UX_MT_D)\
 \

PDBS_CORE_UX_MT_D=\
 $(PDB_lib_core_UX_MT_D)\
 \

OBJ_lib_core_UX_MT_R         =   $(PROJ_OBJ_DIR)\core.mt.obj

OBJS_CORE_UX_MT_R=\
 $(OBJ_lib_core_UX_MT_R)\
 \

OBJ_lib_core_UX_ST_D         =   $(PROJ_OBJ_DIR)\core.debug.obj
PDB_lib_core_UX_ST_D         =   $(PROJ_OBJ_DIR)\core.debug.pdb

OBJS_CORE_UX_ST_D=\
 $(OBJ_lib_core_UX_ST_D)\
 \

PDBS_CORE_UX_ST_D=\
 $(PDB_lib_core_UX_ST_D)\
 \

OBJ_lib_core_UX_ST_R         =   $(PROJ_OBJ_DIR)\core.obj

OBJS_CORE_UX_ST_R=\
 $(OBJ_lib_core_UX_ST_R)\
 \


OBJS_CORE=\
 $(OBJS_CORE_UX_MT_D)\
 $(OBJS_CORE_UX_MT_R)\
 $(OBJS_CORE_UX_ST_D)\
 $(OBJS_CORE_UX_ST_R)\
 \

# shwild - testing only

OBJ_shw_api_UX_MT_D          =   $(PROJ_OBJ_DIR)\shwild.api.mt.debug.obj
OBJ_shw_matches_UX_MT_D      =   $(PROJ_OBJ_DIR)\shwild.matches.mt.debug.obj
OBJ_shw_pattern_UX_MT_D      =   $(PROJ_OBJ_DIR)\shwild.pattern.mt.debug.obj
PDB_shw_api_UX_MT_D          =   $(PROJ_OBJ_DIR)\shwild.api.mt.debug.pdb
PDB_shw_matches_UX_MT_D      =   $(PROJ_OBJ_DIR)\shwild.matches.mt.debug.pdb
PDB_shw_pattern_UX_MT_D      =   $(PROJ_OBJ_DIR)\shwild.pattern.mt.debug.pdb

OBJS_SHWILD_UX_MT_D=\
 $(OBJ_shw_api_UX_MT_D)\
 $(OBJ_shw_matches_UX_MT_D)\
 $(OBJ_shw_pattern_UX_MT_D)\
 \

PDBS_SHWILD_UX_MT_D=\
 $(PDB_shw_api_UX_MT_D)\
 $(PDB_shw_matches_UX_MT_D)\
 $(PDB_shw_pattern_UX_MT_D)\
 \

OBJ_shw_api_UX_MT_R          =   $(PROJ_OBJ_DIR)\shwild.api.mt.obj
OBJ_shw_matches_UX_MT_R      =   $(PROJ_OBJ_DIR)\shwild.matches.mt.obj
OBJ_shw_pattern_UX_MT_R      =   $(PROJ_OBJ_DIR)\shwild.pattern.mt.obj

OBJS_SHWILD_UX_MT_R=\
 $(OBJ_shw_api_UX_MT_R)\
 $(OBJ_shw_matches_UX_MT_R)\
 $(OBJ_shw_pattern_UX_MT_R)\
 \

OBJ_shw_api_UX_ST_D          =   $(PROJ_OBJ_DIR)\shwild.api.debug.obj
OBJ_shw_matches_UX_ST_D      =   $(PROJ_OBJ_DIR)\shwild.matches.debug.obj
OBJ_shw_pattern_UX_ST_D      =   $(PROJ_OBJ_DIR)\shwild.pattern.debug.obj
PDB_shw_api_UX_ST_D          =   $(PROJ_OBJ_DIR)\shwild.api.debug.pdb
PDB_shw_matches_UX_ST_D      =   $(PROJ_OBJ_DIR)\shwild.matches.debug.pdb
PDB_shw_pattern_UX_ST_D      =   $(PROJ_OBJ_DIR)\shwild.pattern.debug.pdb

OBJS_SHWILD_UX_ST_D=\
 $(OBJ_shw_api_UX_ST_D)\
 $(OBJ_shw_matches_UX_ST_D)\
 $(OBJ_shw_pattern_UX_ST_D)\
 \

PDBS_SHWILD_UX_ST_D=\
 $(PDB_shw_api_UX_ST_D)\
 $(PDB_shw_matches_UX_ST_D)\
 $(PDB_shw_pattern_UX_ST_D)\
 \

OBJ_shw_api_UX_ST_R          =   $(PROJ_OBJ_DIR)\shwild.api.obj
OBJ_shw_matches_UX_ST_R      =   $(PROJ_OBJ_DIR)\shwild.matches.obj
OBJ_shw_pattern_UX_ST_R      =   $(PROJ_OBJ_DIR)\shwild.pattern.obj

OBJS_SHWILD_UX_ST_R=\
 $(OBJ_shw_api_UX_ST_R)\
 $(OBJ_shw_matches_UX_ST_R)\
 $(OBJ_shw_pattern_UX_ST_R)\
 \


OBJS_SHWILD=\
 $(OBJS_SHWILD_UX_MT_D)\
 $(OBJS_SHWILD_UX_MT_R)\
 $(OBJS_SHWILD_UX_ST_D)\
 $(OBJS_SHWILD_UX_ST_R)\
 \

# *

OBJS_LIBS =\
 $(OBJS_CORE)\
 $(OBJS_SHWILD)\
 \

########################################
# examples

OBJ_EX_C_runner_UX_MT_D	=   $(PROJ_OBJ_DIR)\example.c.runner.mt.debug.obj
OBJ_EX_C_runner_UX_MT_R	=   $(PROJ_OBJ_DIR)\example.c.runner.mt.obj
OBJ_EX_C_runner_UX_ST_D	=   $(PROJ_OBJ_DIR)\example.c.runner.debug.obj
OBJ_EX_C_runner_UX_ST_R	=   $(PROJ_OBJ_DIR)\example.c.runner.obj

OBJ_EX_C_tests_UX_MT_D		=   $(PROJ_OBJ_DIR)\example.c.tests.mt.debug.obj
OBJ_EX_C_tests_UX_MT_R		=   $(PROJ_OBJ_DIR)\example.c.tests.mt.obj
OBJ_EX_C_tests_UX_ST_D		=   $(PROJ_OBJ_DIR)\example.c.tests.debug.obj
OBJ_EX_C_tests_UX_ST_R		=   $(PROJ_OBJ_DIR)\example.c.tests.obj

OBJS_EXAMPLES =\
 $(OBJ_EX_C_runner_UX_MT_D)\
 $(OBJ_EX_C_runner_UX_MT_R)\
 $(OBJ_EX_C_runner_UX_ST_D)\
 $(OBJ_EX_C_runner_UX_ST_R)\
 $(OBJ_EX_C_tests_UX_MT_D)\
 $(OBJ_EX_C_tests_UX_MT_R)\
 $(OBJ_EX_C_tests_UX_ST_D)\
 $(OBJ_EX_C_tests_UX_ST_R)\
 \

##############################
# scratch tests

OBJ_TEST_SCRT_basics1_UX_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.basics1.mt.debug.obj
OBJ_TEST_SCRT_basics1_UX_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.basics1.mt.obj
OBJ_TEST_SCRT_basics1_UX_ST_D =   $(PROJ_OBJ_DIR)\test.scratch.basics1.debug.obj
OBJ_TEST_SCRT_basics1_UX_ST_R =   $(PROJ_OBJ_DIR)\test.scratch.basics1.obj

OBJ_TEST_SCRT_basics2_UX_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.basics2.mt.debug.obj
OBJ_TEST_SCRT_basics2_UX_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.basics2.mt.obj
OBJ_TEST_SCRT_basics2_UX_ST_D =   $(PROJ_OBJ_DIR)\test.scratch.basics2.debug.obj
OBJ_TEST_SCRT_basics2_UX_ST_R =   $(PROJ_OBJ_DIR)\test.scratch.basics2.obj

OBJ_TEST_SCRT_failall1_UX_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.fail_all.1.mt.debug.obj
OBJ_TEST_SCRT_failall1_UX_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.fail_all.1.mt.obj
OBJ_TEST_SCRT_failall1_UX_ST_D =   $(PROJ_OBJ_DIR)\test.scratch.fail_all.1.debug.obj
OBJ_TEST_SCRT_failall1_UX_ST_R =   $(PROJ_OBJ_DIR)\test.scratch.fail_all.1.obj

########################################
# unit tests


##############################
# component tests





########################################
# Objects

# examples
OBJS_EXAMPLE=\
 $(OBJ_EX_C_runner_UX_MT_D)\
 $(OBJ_EX_C_tests_UX_MT_D)\
 $(OBJ_EX_C_runner_UX_MT_R)\
 $(OBJ_EX_C_tests_UX_MT_R)\
 $(OBJ_EX_C_runner_UX_ST_D)\
 $(OBJ_EX_C_tests_UX_ST_D)\
 $(OBJ_EX_C_runner_UX_ST_R)\
 $(OBJ_EX_C_tests_UX_ST_R)\
 \

# Component Tests
OBJS_TEST_COMPONENT=\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_basics1_UX_MT_D)\
 $(OBJ_TEST_SCRT_basics2_UX_MT_D)\
 $(OBJ_TEST_SCRT_failall1_UX_MT_D)\
 $(OBJ_TEST_SCRT_basics1_UX_MT_R)\
 $(OBJ_TEST_SCRT_basics2_UX_MT_R)\
 $(OBJ_TEST_SCRT_failall1_UX_MT_R)\
 $(OBJ_TEST_SCRT_basics1_UX_ST_D)\
 $(OBJ_TEST_SCRT_basics2_UX_ST_D)\
 $(OBJ_TEST_SCRT_failall1_UX_ST_D)\
 $(OBJ_TEST_SCRT_basics1_UX_ST_R)\
 $(OBJ_TEST_SCRT_basics2_UX_ST_R)\
 $(OBJ_TEST_SCRT_failall1_UX_ST_R)\
 \

# Unit Tests
OBJS_TEST_UNIT=\
 \

########################################
# OBJS

OBJS =\
 $(OBJS_LIBS)\
 \
 $(OBJS_EXAMPLES)\
 $(OBJS_SAMPLES)\
 $(OBJS_TESTS)\
 \

############################################################
# libs

LIBS_EXPLICIT_UX_MT_D =\
 pthreadVC.lib advapi32.lib kernel32.lib ole32.lib oleaut32.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

LIBS_EXPLICIT_UX_MT_R =\
 pthreadVC.lib advapi32.lib kernel32.lib ole32.lib oleaut32.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

LIBS_EXPLICIT_UX_ST_D =\
 pthreadVC.lib advapi32.lib kernel32.lib ole32.lib oleaut32.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \

LIBS_EXPLICIT_UX_ST_R =\
 pthreadVC.lib advapi32.lib kernel32.lib ole32.lib oleaut32.lib user32.lib uuid.lib wininet.lib ws2_32.lib \
 \


LIBS_3PTY_UX_MT_D =\
 \

LIBS_3PTY_UX_MT_D_TEST =\
 $(LIBS_3PTY_UX_MT_D)\
 \

LIBS_3PTY_UX_MT_R =\
 \

LIBS_3PTY_UX_MT_R_TEST =\
 $(LIBS_3PTY_UX_MT_R)\
 \

LIBS_3PTY_UX_ST_D =\
 \

LIBS_3PTY_UX_ST_D_TEST =\
 $(LIBS_3PTY_UX_ST_D)\
 \

LIBS_3PTY_UX_ST_R =\
 \

LIBS_3PTY_UX_ST_R_TEST =\
 $(LIBS_3PTY_UX_ST_R)\
 \


LIBS_EXAMPLES_UX_MT_D=\
 $(LIB_CORE_UX_MT_D)\
 \


LIBS_EXAMPLES_UX_MT_R=\
 $(LIB_CORE_UX_MT_R)\
 \


LIBS_EXAMPLES_UX_ST_D=\
 $(LIB_CORE_UX_ST_D)\
 \


LIBS_EXAMPLES_UX_ST_R=\
 $(LIB_CORE_UX_ST_R)\
 \


LIBS_SAMPLES_UX_MT_D=\
 $(LIB_CORE_UX_MT_D)\
 \


LIBS_SAMPLES_UX_MT_R=\
 $(LIB_CORE_UX_MT_R)\
 \


LIBS_SAMPLES_UX_ST_D=\
 $(LIB_CORE_UX_ST_D)\
 \


LIBS_SAMPLES_UX_ST_R=\
 $(LIB_CORE_UX_ST_R)\
 \


LIBS_TESTS_UX_MT_D=\
 $(LIB_CORE_UX_MT_D)\
 $(LIB_SHWILD_UX_MT_D)\
 \


LIBS_TESTS_UX_MT_R=\
 $(LIB_CORE_UX_MT_R)\
 $(LIB_SHWILD_UX_MT_R)\
 \


LIBS_TESTS_UX_ST_D=\
 $(LIB_CORE_UX_ST_D)\
 $(LIB_SHWILD_UX_ST_D)\
 \


LIBS_TESTS_UX_ST_R=\
 $(LIB_CORE_UX_ST_R)\
 $(LIB_SHWILD_UX_ST_R)\
 \



############################################################################
# targets

########################################
# libraries

# core

LIB_CORE_UX_MT_D                 =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_CORE_UN_UX_MT_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).mt.debug.lib
LIB_CORE_UX_MT_R                 =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_UN_UX_MT_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).mt.lib
LIB_CORE_UX_ST_D                 =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).debug.lib
LIB_CORE_UN_UX_ST_D				=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
LIB_CORE_UX_ST_R                 =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).lib
LIB_CORE_UN_UX_ST_R				=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).lib

TARGETS_LIB_CORE=\
 $(LIB_CORE_UX_MT_D)\
 $(LIB_CORE_UX_MT_R)\
 $(LIB_CORE_UX_ST_D)\
 $(LIB_CORE_UX_ST_R)\
 \

# shwild - testing only

LIB_SHWILD_UX_MT_D               =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_SHWILD_UX_MT_R               =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG).mt.lib
LIB_SHWILD_UX_ST_D               =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG).debug.lib
LIB_SHWILD_UX_ST_R               =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG).lib

TARGETS_LIB_SHWILD=\
 $(LIB_SHWILD_UX_MT_D)\
 $(LIB_SHWILD_UX_MT_R)\
 $(LIB_SHWILD_UX_ST_D)\
 $(LIB_SHWILD_UX_ST_R)\
 \

# *

TARGETS_LIB_ALL=\
 $(TARGETS_LIB_CORE)\
 \

TARGETS_LIBS=\
 $(TARGETS_LIB_CORE)\
 $(TARGETS_LIB_SHWILD)\
 \

########################################
# examples

TARG_EX_C_runner_UX_MT_D         =   $(PROJ_BIN_DIR)\$(PROJ_TAG).example.c.runner.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_tests_UX_MT_D          =   $(PROJ_BIN_DIR)\$(PROJ_TAG).example.c.tests.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_runner_UX_MT_R         =   $(PROJ_BIN_DIR)\$(PROJ_TAG).example.c.runner.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_tests_UX_MT_R          =   $(PROJ_BIN_DIR)\$(PROJ_TAG).example.c.tests.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_C_runner_UX_ST_D         =   $(PROJ_BIN_DIR)\$(PROJ_TAG).example.c.runner.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_C_tests_UX_ST_D          =   $(PROJ_BIN_DIR)\$(PROJ_TAG).example.c.tests.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_C_runner_UX_ST_R         =   $(PROJ_BIN_DIR)\$(PROJ_TAG).example.c.runner.$(COMP_ARCH_OS_TAG).exe
TARG_EX_C_tests_UX_ST_R          =   $(PROJ_BIN_DIR)\$(PROJ_TAG).example.c.tests.$(COMP_ARCH_OS_TAG).exe

TARGETS_EXAMPLE_C=\
 $(TARG_EX_C_runner_UX_MT_D)\
 $(TARG_EX_C_tests_UX_MT_D)\
 $(TARG_EX_C_runner_UX_MT_R)\
 $(TARG_EX_C_tests_UX_MT_R)\
 $(TARG_EX_C_runner_UX_ST_D)\
 $(TARG_EX_C_tests_UX_ST_D)\
 $(TARG_EX_C_runner_UX_ST_R)\
 $(TARG_EX_C_tests_UX_ST_R)\
 \

TARGETS_EXAMPLE_CPP=\
 \

TARGETS_EXAMPLE=\
 $(TARGETS_EXAMPLE_C)\
 $(TARGETS_EXAMPLE_CPP)\
 \

########################################
# samples

TARGETS_SAMPLE=\
 \

########################################
# scratch tests

TARG_TEST_SCRT_basics1_UX_MT_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.basics1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_basics2_UX_MT_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.basics2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_failall1_UX_MT_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.fail_all.1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_basics1_UX_MT_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.basics1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_basics2_UX_MT_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.basics2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_failall1_UX_MT_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.fail_all.1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_basics1_UX_ST_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.basics1.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_SCRT_basics2_UX_ST_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.basics2.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_SCRT_failall1_UX_ST_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.fail_all.1.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_SCRT_basics1_UX_ST_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.basics1.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_SCRT_basics2_UX_ST_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.basics2.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_SCRT_failall1_UX_ST_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG).test.scratch.fail_all.1.$(COMP_ARCH_OS_TAG).exe

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_basics1_UX_MT_D)\
 $(TARG_TEST_SCRT_basics2_UX_MT_D)\
 $(TARG_TEST_SCRT_failall1_UX_MT_D)\
 $(TARG_TEST_SCRT_basics1_UX_MT_R)\
 $(TARG_TEST_SCRT_basics2_UX_MT_R)\
 $(TARG_TEST_SCRT_failall1_UX_MT_R)\
 $(TARG_TEST_SCRT_basics1_UX_ST_D)\
 $(TARG_TEST_SCRT_basics2_UX_ST_D)\
 $(TARG_TEST_SCRT_failall1_UX_ST_D)\
 $(TARG_TEST_SCRT_basics1_UX_ST_R)\
 $(TARG_TEST_SCRT_basics2_UX_ST_R)\
 $(TARG_TEST_SCRT_failall1_UX_ST_R)\
 \

########################################
# component tests


TARGETS_TEST_COMPONENT=\
 \

########################################
# unit tests


TARGETS_TEST_UNIT=\
 \

########################################
# TARGETS

TARGETS =\
 $(TARGETS_LIBS)\
 \
 $(TARGETS_TESTS)\
 $(TARGETS_EXAMPLES)\
 $(TARGETS_SAMPLES)\
 \

############################################################################
# External Targets (invokable by make)

# primary

_default:					build

usage:
	@echo "make [usage | compile | build | test | clean] - default is 'build'"

# infrastructure

check.lib.dir:				$(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:				$(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)


# compile targets

compile.libs.core:			$(PROJ_MAKEFILE_NAME)	$(OBJS_CORE)

compile.libs:										compile.libs.core

compile.libs.shwild:		$(PROJ_MAKEFILE_NAME)	$(OBJS_SHWILD)

compile.libs.3pty:									compile.libs.shwild

compile.libs.all:                                   compile.libs compile.libs.3pty

compile.examples:			$(PROJ_MAKEFILE_NAME)	$(OBJS_EXAMPLE)

compile.samples:			$(PROJ_MAKEFILE_NAME)	$(OBJS_SAMPLE)

compile.test.component:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_COMPONENT)

compile.test.scratch:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_SCRATCH)

compile.test.unit:			$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_UNIT)

compile.test:										compile.test.unit compile.test.component compile.test.scratch

compile:											compile.libs compile.libs.3pty compile.test compile.examples compile.samples

compile.all:										compile




# build targets

build.libs.core:			check.lib.dir			$(TARGETS_LIB_CORE)

build.libs:											build.libs.core

build.libs.shwild:			check.lib.dir			$(TARGETS_LIB_SHWILD)

build.libs.3pty:									build.libs.shwild

build.libs.all:										build.libs build.libs.3pty

build.examples:				check.bin.dir			$(TARGETS_EXAMPLE)

build.samples:				check.bin.dir			$(TARGETS_SAMPLE)

build.test.component:		check.bin.dir			$(TARGETS_TEST_COMPONENT)

build.test.scratch:			check.bin.dir			$(TARGETS_TEST_SCRATCH)

build.test.unit:			check.bin.dir			$(TARGETS_TEST_UNIT)

build.test:											build.test.unit build.test.component build.test.scratch

build:												build.libs build.test build.examples build.samples

build.all:											build



# test targets

test.component_:
	@echo Running Test:Component programs ...

test.scratch_:
	@echo Running Test:Scratch programs ...
	-$(TARG_TEST_SCRT_failall1_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	-$(TARG_TEST_SCRT_failall1_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	-$(TARG_TEST_SCRT_failall1_UX_ST_D) --verbosity=$(TEST_VERBOSITY)
	-$(TARG_TEST_SCRT_failall1_UX_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics1_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics1_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics1_UX_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics1_UX_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics2_UX_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics2_UX_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics2_UX_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics2_UX_ST_R) --verbosity=$(TEST_VERBOSITY)

test.unit_:
	@echo Running Test:Unit programs ...

test.component:			$(PROJ_MAKEFILE_NAME)	build.test.component test.component_

test.scratch:			$(PROJ_MAKEFILE_NAME)	build.test.scratch test.scratch_

test.unit:				$(PROJ_MAKEFILE_NAME)	build.test.unit test.unit_

test:											test.unit test.component

test.all:										test test.scratch
test-all:				test.all


# clean targets

clean.libs.core:
	@echo Cleaning Core libraries ...
	@-if exist $(LIB_CORE_UX_MT_D) $(RM) $(LIB_CORE_UX_MT_D)
	@-if exist $(LIB_CORE_UN_UX_MT_D) $(RM) $(LIB_CORE_UN_UX_MT_D)
	@-if exist $(LIB_CORE_UX_MT_R) $(RM) $(LIB_CORE_UX_MT_R)
	@-if exist $(LIB_CORE_UN_UX_MT_R) $(RM) $(LIB_CORE_UN_UX_MT_R)
	@-if exist $(LIB_CORE_UX_ST_D) $(RM) $(LIB_CORE_UX_ST_D)
	@-if exist $(LIB_CORE_UN_UX_ST_D) $(RM) $(LIB_CORE_UN_UX_ST_D)
	@-if exist $(LIB_CORE_UX_ST_R) $(RM) $(LIB_CORE_UX_ST_R)
	@-if exist $(LIB_CORE_UN_UX_ST_R) $(RM) $(LIB_CORE_UN_UX_ST_R)
	@-if exist $(OBJS_CORE_UX_MT_D) $(RM) $(OBJS_CORE_UX_MT_D)
	@-if exist $(PDBS_CORE_UX_MT_D) $(RM) $(PDBS_CORE_UX_MT_D)
	@-if exist $(OBJS_CORE_UX_MT_R) $(RM) $(OBJS_CORE_UX_MT_R)
	@-if exist $(OBJS_CORE_UX_ST_D) $(RM) $(OBJS_CORE_UX_ST_D)
	@-if exist $(PDBS_CORE_UX_ST_D) $(RM) $(PDBS_CORE_UX_ST_D)
	@-if exist $(OBJS_CORE_UX_ST_R) $(RM) $(OBJS_CORE_UX_ST_R)

clean.libs.shwild:
	@echo Cleaning shwild libraries ...
	@-if exist $(LIB_SHWILD_UX_MT_D) $(RM) $(LIB_SHWILD_UX_MT_D)
	@-if exist $(LIB_SHWILD_UX_MT_R) $(RM) $(LIB_SHWILD_UX_MT_R)
	@-if exist $(LIB_SHWILD_UX_ST_D) $(RM) $(LIB_SHWILD_UX_ST_D)
	@-if exist $(LIB_SHWILD_UX_ST_R) $(RM) $(LIB_SHWILD_UX_ST_R)
	@-if exist $(OBJ_shw_api_UX_MT_D) $(RM) $(OBJ_shw_api_UX_MT_D)
	@-if exist $(OBJ_shw_matches_UX_MT_D) $(RM) $(OBJ_shw_matches_UX_MT_D)
	@-if exist $(OBJ_shw_pattern_UX_MT_D) $(RM) $(OBJ_shw_pattern_UX_MT_D)
	@-if exist $(PDB_shw_api_UX_MT_D) $(RM) $(PDB_shw_api_UX_MT_D)
	@-if exist $(PDB_shw_matches_UX_MT_D) $(RM) $(PDB_shw_matches_UX_MT_D)
	@-if exist $(PDB_shw_pattern_UX_MT_D) $(RM) $(PDB_shw_pattern_UX_MT_D)
	@-if exist $(OBJ_shw_api_UX_MT_R) $(RM) $(OBJ_shw_api_UX_MT_R)
	@-if exist $(OBJ_shw_matches_UX_MT_R) $(RM) $(OBJ_shw_matches_UX_MT_R)
	@-if exist $(OBJ_shw_pattern_UX_MT_R) $(RM) $(OBJ_shw_pattern_UX_MT_R)
	@-if exist $(OBJ_shw_api_UX_ST_D) $(RM) $(OBJ_shw_api_UX_ST_D)
	@-if exist $(OBJ_shw_matches_UX_ST_D) $(RM) $(OBJ_shw_matches_UX_ST_D)
	@-if exist $(OBJ_shw_pattern_UX_ST_D) $(RM) $(OBJ_shw_pattern_UX_ST_D)
	@-if exist $(PDB_shw_api_UX_ST_D) $(RM) $(PDB_shw_api_UX_ST_D)
	@-if exist $(PDB_shw_matches_UX_ST_D) $(RM) $(PDB_shw_matches_UX_ST_D)
	@-if exist $(PDB_shw_pattern_UX_ST_D) $(RM) $(PDB_shw_pattern_UX_ST_D)
	@-if exist $(OBJ_shw_api_UX_ST_R) $(RM) $(OBJ_shw_api_UX_ST_R)
	@-if exist $(OBJ_shw_matches_UX_ST_R) $(RM) $(OBJ_shw_matches_UX_ST_R)
	@-if exist $(OBJ_shw_pattern_UX_ST_R) $(RM) $(OBJ_shw_pattern_UX_ST_R)

clean.test.component:
	@echo cleaning Test:Component programs ...

clean.test.scratch:
	@echo cleaning Test:Scratch programs ...
	@-if exist $(TARG_TEST_SCRT_basics1_UX_MT_D) $(RM) $(TARG_TEST_SCRT_basics1_UX_MT_D)
	@-if exist $(OBJ_TEST_SCRT_basics1_UX_MT_D) $(RM) $(OBJ_TEST_SCRT_basics1_UX_MT_D)
	@-if exist $(TARG_TEST_SCRT_basics2_UX_MT_D) $(RM) $(TARG_TEST_SCRT_basics2_UX_MT_D)
	@-if exist $(OBJ_TEST_SCRT_basics2_UX_MT_D) $(RM) $(OBJ_TEST_SCRT_basics2_UX_MT_D)
	@-if exist $(TARG_TEST_SCRT_failall1_UX_MT_D) $(RM) $(TARG_TEST_SCRT_failall1_UX_MT_D)
	@-if exist $(OBJ_TEST_SCRT_failall1_UX_MT_D) $(RM) $(OBJ_TEST_SCRT_failall1_UX_MT_D)
	@-if exist $(PDB_TEST_SCRT_basics1_UX_MT_D) $(RM) $(PDB_TEST_SCRT_basics1_UX_MT_D)
	@-if exist $(PDB_TEST_SCRT_basics2_UX_MT_D) $(RM) $(PDB_TEST_SCRT_basics2_UX_MT_D)
	@-if exist $(PDB_TEST_SCRT_failall1_UX_MT_D) $(RM) $(PDB_TEST_SCRT_failall1_UX_MT_D)
	@-if exist $(TARG_TEST_SCRT_basics1_UX_MT_R) $(RM) $(TARG_TEST_SCRT_basics1_UX_MT_R)
	@-if exist $(OBJ_TEST_SCRT_basics1_UX_MT_R) $(RM) $(OBJ_TEST_SCRT_basics1_UX_MT_R)
	@-if exist $(TARG_TEST_SCRT_basics2_UX_MT_R) $(RM) $(TARG_TEST_SCRT_basics2_UX_MT_R)
	@-if exist $(OBJ_TEST_SCRT_basics2_UX_MT_R) $(RM) $(OBJ_TEST_SCRT_basics2_UX_MT_R)
	@-if exist $(TARG_TEST_SCRT_failall1_UX_MT_R) $(RM) $(TARG_TEST_SCRT_failall1_UX_MT_R)
	@-if exist $(OBJ_TEST_SCRT_failall1_UX_MT_R) $(RM) $(OBJ_TEST_SCRT_failall1_UX_MT_R)
	@-if exist $(TARG_TEST_SCRT_basics1_UX_ST_D) $(RM) $(TARG_TEST_SCRT_basics1_UX_ST_D)
	@-if exist $(OBJ_TEST_SCRT_basics1_UX_ST_D) $(RM) $(OBJ_TEST_SCRT_basics1_UX_ST_D)
	@-if exist $(TARG_TEST_SCRT_basics2_UX_ST_D) $(RM) $(TARG_TEST_SCRT_basics2_UX_ST_D)
	@-if exist $(OBJ_TEST_SCRT_basics2_UX_ST_D) $(RM) $(OBJ_TEST_SCRT_basics2_UX_ST_D)
	@-if exist $(TARG_TEST_SCRT_failall1_UX_ST_D) $(RM) $(TARG_TEST_SCRT_failall1_UX_ST_D)
	@-if exist $(OBJ_TEST_SCRT_failall1_UX_ST_D) $(RM) $(OBJ_TEST_SCRT_failall1_UX_ST_D)
	@-if exist $(PDB_TEST_SCRT_basics1_UX_ST_D) $(RM) $(PDB_TEST_SCRT_basics1_UX_ST_D)
	@-if exist $(PDB_TEST_SCRT_basics2_UX_ST_D) $(RM) $(PDB_TEST_SCRT_basics2_UX_ST_D)
	@-if exist $(PDB_TEST_SCRT_failall1_UX_ST_D) $(RM) $(PDB_TEST_SCRT_failall1_UX_ST_D)
	@-if exist $(TARG_TEST_SCRT_basics1_UX_ST_R) $(RM) $(TARG_TEST_SCRT_basics1_UX_ST_R)
	@-if exist $(OBJ_TEST_SCRT_basics1_UX_ST_R) $(RM) $(OBJ_TEST_SCRT_basics1_UX_ST_R)
	@-if exist $(TARG_TEST_SCRT_basics2_UX_ST_R) $(RM) $(TARG_TEST_SCRT_basics2_UX_ST_R)
	@-if exist $(OBJ_TEST_SCRT_basics2_UX_ST_R) $(RM) $(OBJ_TEST_SCRT_basics2_UX_ST_R)
	@-if exist $(TARG_TEST_SCRT_failall1_UX_ST_R) $(RM) $(TARG_TEST_SCRT_failall1_UX_ST_R)
	@-if exist $(OBJ_TEST_SCRT_failall1_UX_ST_R) $(RM) $(OBJ_TEST_SCRT_failall1_UX_ST_R)

clean.test.unit:
	@echo cleaning Test:Unit programs ...

clean.libs: 									clean.libs.core

clean.libs.3pty:								clean.libs.shwild

clean.libs.all: 								clean.libs clean.libs.3pty

clean.examples:			$(PROJ_MAKEFILE_NAME)

clean.samples:			$(PROJ_MAKEFILE_NAME)

clean.test:										clean.test.component clean.test.scratch clean.test.unit

clean:					$(PROJ_MAKEFILE_NAME)	clean.libs.all clean.test clean.examples clean.samples



############################################################################
# build targets

##################################################
# libraries

########################################
# shwild library - 'shwild.X.core.a'

$(LIB_SHWILD_UX_MT_D): $(OBJS_SHWILD_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_SHWILD_UX_MT_D)

$(OBJ_shw_api_UX_MT_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_D) $(CPPC_SHWILD_INCLUDES_UX_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_UX_MT_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_D) $(CPPC_SHWILD_INCLUDES_UX_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_UX_MT_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_D) $(CPPC_SHWILD_INCLUDES_UX_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_UX_MT_R): $(OBJS_SHWILD_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_SHWILD_UX_MT_R)

$(OBJ_shw_api_UX_MT_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_R) $(CPPC_SHWILD_INCLUDES_UX_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_UX_MT_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_R) $(CPPC_SHWILD_INCLUDES_UX_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_UX_MT_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_R) $(CPPC_SHWILD_INCLUDES_UX_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_UX_ST_D): $(OBJS_SHWILD_UX_ST_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_SHWILD_UX_ST_D)

$(OBJ_shw_api_UX_ST_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_D) $(CPPC_SHWILD_INCLUDES_UX_ST_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_UX_ST_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_D) $(CPPC_SHWILD_INCLUDES_UX_ST_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_UX_ST_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_D) $(CPPC_SHWILD_INCLUDES_UX_ST_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_UX_ST_R): $(OBJS_SHWILD_UX_ST_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_SHWILD_UX_ST_R)

$(OBJ_shw_api_UX_ST_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_R) $(CPPC_SHWILD_INCLUDES_UX_ST_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_UX_ST_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_R) $(CPPC_SHWILD_INCLUDES_UX_ST_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_UX_ST_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_R) $(CPPC_SHWILD_INCLUDES_UX_ST_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

########################################
# Main library - 'xtests.X.core.a'

$(LIB_CORE_UX_MT_D): $(OBJS_CORE_UX_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_UX_MT_D)

$(OBJ_lib_core_UX_MT_D):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xtests.core.cpp
	$(CPPC) $(CPPC_ARGS_UX_MT_D) -Fo$@ $(PROJ_SRC_DIR)\xtests.core.cpp

$(LIB_CORE_UX_MT_R): $(OBJS_CORE_UX_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_UX_MT_R)

$(OBJ_lib_core_UX_MT_R):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xtests.core.cpp
	$(CPPC) $(CPPC_ARGS_UX_MT_R) -Fo$@ $(PROJ_SRC_DIR)\xtests.core.cpp

$(LIB_CORE_UX_ST_D): $(OBJS_CORE_UX_ST_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_UX_ST_D)

$(OBJ_lib_core_UX_ST_D):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xtests.core.cpp
	$(CPPC) $(CPPC_ARGS_UX_ST_D) -Fo$@ $(PROJ_SRC_DIR)\xtests.core.cpp

$(LIB_CORE_UX_ST_R): $(OBJS_CORE_UX_ST_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_UX_ST_R)

$(OBJ_lib_core_UX_ST_R):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xtests.core.cpp
	$(CPPC) $(CPPC_ARGS_UX_ST_R) -Fo$@ $(PROJ_SRC_DIR)\xtests.core.cpp

##################################################
# examples

$(TARG_EX_C_runner_UX_MT_D):	\
			$(OBJ_EX_C_runner_UX_MT_D)\
			$(LIBS_EXAMPLES_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_runner_UX_MT_D)\
		$(LIBS_EXAMPLES_UX_MT_D)\
		$(LIBS_3PTY_UX_MT_D_TEST)\
		$(LIBS_EXPLICIT_UX_MT_D)

$(OBJ_EX_C_runner_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c

$(TARG_EX_C_runner_UX_MT_R):	\
			$(OBJ_EX_C_runner_UX_MT_R)\
			$(LIBS_EXAMPLES_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_runner_UX_MT_R)\
		$(LIBS_EXAMPLES_UX_MT_R)\
		$(LIBS_3PTY_UX_MT_R_TEST)\
		$(LIBS_EXPLICIT_UX_MT_R)

$(OBJ_EX_C_runner_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c

$(TARG_EX_C_runner_UX_ST_D):	\
			$(OBJ_EX_C_runner_UX_ST_D)\
			$(LIBS_EXAMPLES_UX_ST_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_D) -out:$@ \
		$(OBJ_EX_C_runner_UX_ST_D)\
		$(LIBS_EXAMPLES_UX_ST_D)\
		$(LIBS_3PTY_UX_ST_D_TEST)\
		$(LIBS_EXPLICIT_UX_ST_D)

$(OBJ_EX_C_runner_UX_ST_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_ST_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c

$(TARG_EX_C_runner_UX_ST_R):	\
			$(OBJ_EX_C_runner_UX_ST_R)\
			$(LIBS_EXAMPLES_UX_ST_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_R) -out:$@ \
		$(OBJ_EX_C_runner_UX_ST_R)\
		$(LIBS_EXAMPLES_UX_ST_R)\
		$(LIBS_3PTY_UX_ST_R_TEST)\
		$(LIBS_EXPLICIT_UX_ST_R)

$(OBJ_EX_C_runner_UX_ST_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_ST_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c

$(TARG_EX_C_tests_UX_MT_D):	\
			$(OBJ_EX_C_tests_UX_MT_D)\
			$(LIBS_EXAMPLES_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_EX_C_tests_UX_MT_D)\
		$(LIBS_EXAMPLES_UX_MT_D)\
		$(LIBS_3PTY_UX_MT_D_TEST)\
		$(LIBS_EXPLICIT_UX_MT_D)

$(OBJ_EX_C_tests_UX_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c

$(TARG_EX_C_tests_UX_MT_R):	\
			$(OBJ_EX_C_tests_UX_MT_R)\
			$(LIBS_EXAMPLES_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_EX_C_tests_UX_MT_R)\
		$(LIBS_EXAMPLES_UX_MT_R)\
		$(LIBS_3PTY_UX_MT_R_TEST)\
		$(LIBS_EXPLICIT_UX_MT_R)

$(OBJ_EX_C_tests_UX_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c

$(TARG_EX_C_tests_UX_ST_D):	\
			$(OBJ_EX_C_tests_UX_ST_D)\
			$(LIBS_EXAMPLES_UX_ST_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_D) -out:$@ \
		$(OBJ_EX_C_tests_UX_ST_D)\
		$(LIBS_EXAMPLES_UX_ST_D)\
		$(LIBS_3PTY_UX_ST_D_TEST)\
		$(LIBS_EXPLICIT_UX_ST_D)

$(OBJ_EX_C_tests_UX_ST_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_ST_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c

$(TARG_EX_C_tests_UX_ST_R):	\
			$(OBJ_EX_C_tests_UX_ST_R)\
			$(LIBS_EXAMPLES_UX_ST_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_R) -out:$@ \
		$(OBJ_EX_C_tests_UX_ST_R)\
		$(LIBS_EXAMPLES_UX_ST_R)\
		$(LIBS_3PTY_UX_ST_R_TEST)\
		$(LIBS_EXPLICIT_UX_ST_R)

$(OBJ_EX_C_tests_UX_ST_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_ST_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c

##################################################
# tests

##############################
# component tests

##############################
# scratch tests

$(TARG_TEST_SCRT_basics1_UX_MT_D):	\
			$(OBJ_TEST_SCRT_basics1_UX_MT_D)\
			$(LIBS_TESTS_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_basics1_UX_MT_D)\
		$(LIBS_TESTS_UX_MT_D)\
		$(LIBS_3PTY_UX_MT_D_TEST)\
		$(LIBS_EXPLICIT_UX_MT_D)

$(OBJ_TEST_SCRT_basics1_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c

$(TARG_TEST_SCRT_basics1_UX_MT_R):	\
			$(OBJ_TEST_SCRT_basics1_UX_MT_R)\
			$(LIBS_TESTS_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_basics1_UX_MT_R)\
		$(LIBS_TESTS_UX_MT_R)\
		$(LIBS_3PTY_UX_MT_R_TEST)\
		$(LIBS_EXPLICIT_UX_MT_R)

$(OBJ_TEST_SCRT_basics1_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c

$(TARG_TEST_SCRT_basics1_UX_ST_D):	\
			$(OBJ_TEST_SCRT_basics1_UX_ST_D)\
			$(LIBS_TESTS_UX_ST_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_D) -out:$@ \
		$(OBJ_TEST_SCRT_basics1_UX_ST_D)\
		$(LIBS_TESTS_UX_ST_D)\
		$(LIBS_3PTY_UX_ST_D_TEST)\
		$(LIBS_EXPLICIT_UX_ST_D)

$(OBJ_TEST_SCRT_basics1_UX_ST_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_ST_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c

$(TARG_TEST_SCRT_basics1_UX_ST_R):	\
			$(OBJ_TEST_SCRT_basics1_UX_ST_R)\
			$(LIBS_TESTS_UX_ST_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_R) -out:$@ \
		$(OBJ_TEST_SCRT_basics1_UX_ST_R)\
		$(LIBS_TESTS_UX_ST_R)\
		$(LIBS_3PTY_UX_ST_R_TEST)\
		$(LIBS_EXPLICIT_UX_ST_R)

$(OBJ_TEST_SCRT_basics1_UX_ST_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_UX_ST_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c

$(TARG_TEST_SCRT_basics2_UX_MT_D):	\
			$(OBJ_TEST_SCRT_basics2_UX_MT_D)\
			$(LIBS_TESTS_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_basics2_UX_MT_D)\
		$(LIBS_TESTS_UX_MT_D)\
		$(LIBS_3PTY_UX_MT_D_TEST)\
		$(LIBS_EXPLICIT_UX_MT_D)

$(OBJ_TEST_SCRT_basics2_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp

$(TARG_TEST_SCRT_basics2_UX_MT_R):	\
			$(OBJ_TEST_SCRT_basics2_UX_MT_R)\
			$(LIBS_TESTS_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_basics2_UX_MT_R)\
		$(LIBS_TESTS_UX_MT_R)\
		$(LIBS_3PTY_UX_MT_R_TEST)\
		$(LIBS_EXPLICIT_UX_MT_R)

$(OBJ_TEST_SCRT_basics2_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp

$(TARG_TEST_SCRT_basics2_UX_ST_D):	\
			$(OBJ_TEST_SCRT_basics2_UX_ST_D)\
			$(LIBS_TESTS_UX_ST_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_D) -out:$@ \
		$(OBJ_TEST_SCRT_basics2_UX_ST_D)\
		$(LIBS_TESTS_UX_ST_D)\
		$(LIBS_3PTY_UX_ST_D_TEST)\
		$(LIBS_EXPLICIT_UX_ST_D)

$(OBJ_TEST_SCRT_basics2_UX_ST_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp

$(TARG_TEST_SCRT_basics2_UX_ST_R):	\
			$(OBJ_TEST_SCRT_basics2_UX_ST_R)\
			$(LIBS_TESTS_UX_ST_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_R) -out:$@ \
		$(OBJ_TEST_SCRT_basics2_UX_ST_R)\
		$(LIBS_TESTS_UX_ST_R)\
		$(LIBS_3PTY_UX_ST_R_TEST)\
		$(LIBS_EXPLICIT_UX_ST_R)

$(OBJ_TEST_SCRT_basics2_UX_ST_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp

$(TARG_TEST_SCRT_failall1_UX_MT_D):	\
			$(OBJ_TEST_SCRT_failall1_UX_MT_D)\
			$(LIBS_TESTS_UX_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_failall1_UX_MT_D)\
		$(LIBS_TESTS_UX_MT_D)\
		$(LIBS_3PTY_UX_MT_D_TEST)\
		$(LIBS_EXPLICIT_UX_MT_D)

$(OBJ_TEST_SCRT_failall1_UX_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp

$(TARG_TEST_SCRT_failall1_UX_MT_R):	\
			$(OBJ_TEST_SCRT_failall1_UX_MT_R)\
			$(LIBS_TESTS_UX_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_failall1_UX_MT_R)\
		$(LIBS_TESTS_UX_MT_R)\
		$(LIBS_3PTY_UX_MT_R_TEST)\
		$(LIBS_EXPLICIT_UX_MT_R)

$(OBJ_TEST_SCRT_failall1_UX_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp

$(TARG_TEST_SCRT_failall1_UX_ST_D):	\
			$(OBJ_TEST_SCRT_failall1_UX_ST_D)\
			$(LIBS_TESTS_UX_ST_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_D) -out:$@ \
		$(OBJ_TEST_SCRT_failall1_UX_ST_D)\
		$(LIBS_TESTS_UX_ST_D)\
		$(LIBS_3PTY_UX_ST_D_TEST)\
		$(LIBS_EXPLICIT_UX_ST_D)

$(OBJ_TEST_SCRT_failall1_UX_ST_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp

$(TARG_TEST_SCRT_failall1_UX_ST_R):	\
			$(OBJ_TEST_SCRT_failall1_UX_ST_R)\
			$(LIBS_TESTS_UX_ST_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_UX_ST_R) -out:$@ \
		$(OBJ_TEST_SCRT_failall1_UX_ST_R)\
		$(LIBS_TESTS_UX_ST_R)\
		$(LIBS_3PTY_UX_ST_R_TEST)\
		$(LIBS_EXPLICIT_UX_ST_R)

$(OBJ_TEST_SCRT_failall1_UX_ST_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_UX_ST_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp

##############################
# unit tests

############################### end of file ################################
