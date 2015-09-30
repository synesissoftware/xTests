############################################################################
# File:     makefile
#
# Purpose:  Makefile for the xTests:C project, for the Visual C++ 10 (Win32)
#           compiler, on Win32
#
# Created:  16th December 2007
# Updated:  30th September 2015
#
############################################################################


############################################################################
# Environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG			=	vc10
ARCH_TAG            =   
OS_TAG				=   
PROJ_TAG			=	xtests
PROJ_VER_MAJOR		=   0
PROJ_TAG_VER		=   $(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG	=	$(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

SHWILD_VER_MAJOR	=	0
SHWILD_TAG_VER		=	shwild.$(SHWILD_VER_MAJOR)

UNIXEM_VER_MAJOR	=	1
UNIXEM_TAG_VER      =   unixem.$(XTESTS_VER_MAJOR)

PROJ_MAKEFILE_NAME	=	makefile

########################################
# Testing verbosity

TEST_VERBOSITY		=	2

########################################
# Directories

PROJ_BASE_DIR			=   ..\..
PROJ_BIN_DIR			=   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR			=   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR			=   .
PROJ_SRC_DIR			=   $(PROJ_BASE_DIR)\src
PROJ_EXAMPLES_DIR		=   $(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR		=   $(PROJ_BASE_DIR)\samples
PROJ_TEST_ROOT_DIR		=   $(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR	=   $(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_SCRATCH_DIR	=   $(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR		=   $(PROJ_TEST_ROOT_DIR)\unit

SHWILD_PROJ_INCLUDE		=	
!ifdef XTESTS_SHWILD_BASE_DIR
SHWILD_INCLUDE_DIR		=   $(XTESTS_SHWILD_BASE_DIR)\include
SHWILD_SRC_DIR			=   $(XTESTS_SHWILD_BASE_DIR)\src
SHWILD_PROJ_INCLUDE		=	-I$(SHWILD_INCLUDE_DIR)
!else
SHWILD_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
SHWILD_SRC_DIR			=   $(PROJ_SRC_DIR)\shwild
!endif # !XTESTS_SHWILD_BASE_DIR

########################################
# tools

CC						=   cl
CPPC					=   cl
AR						=   lib
LD						=   link
RM						=   del /f
CP						=   copy
RC						=   rc




# Lib

LIBS_LEADER 			=	

# lib paths

ENV_LIBPATHS		=
COMMON_LIBPATHS			=


LIBPATHS=\
 $(LIBS_LEADER)\
 $(COMMON_LIBPATHS)\
 $(ENV_LIBPATHS)\
 \


# lib names

TARGET_LIB_MT_D = \
 kernel32.lib user32.lib advapi32.lib uuid.lib wininet.lib ole32.lib oleaut32.lib \
 \

TARGET_LIB_DLL_D = \
 kernel32.lib user32.lib advapi32.lib uuid.lib wininet.lib ole32.lib oleaut32.lib \
 \

TARGET_LIB_DLL_R = \
 kernel32.lib user32.lib advapi32.lib uuid.lib wininet.lib ole32.lib oleaut32.lib \
 \

TARGET_LIB_MT_R = \
 kernel32.lib user32.lib advapi32.lib uuid.lib wininet.lib ole32.lib oleaut32.lib \
 \


# #defines

COMMON_DEFS 		=	-DWIN32

CUSTOM_DEFS			=	

# includes

COMMON_INCLUDES		=	



# CC flags

CC_F_NOLOGO           =   -nologo
CC_F_COMPILE_ONLY     =   -c
CC_F_WARNING_MAX      =   -W4
CC_F_WARNING_ERR      =   -WX
CC_F_MINIMUM_SIZE     =   -O1
CC_F_MAXIMUM_SPEED	=	-O2

CC_FLAGS_BASE =\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CC_FLAGS_MT_D =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_DLL_D =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_DLL_R =\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_MT_R =\
 $(CC_FLAGS_BASE)\
 \


# CPPC flags

CPPC_F_NOLOGO           =   -nologo
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_WARNING_MAX      =   -W4 -wd4800
CPPC_F_WARNING_ERR      =   -WX
CPPC_F_EXCEPTIONS_ON	=	-EHsc
CPPC_F_EXCEPTIONS_OFF	=	-wd4530
CPPC_F_EXCEPTIONS		=	
CPPC_F_RTTI_ON			=	-GR
CPPC_F_RTTI_OFF 		=	-GR-
CPPC_F_RTTI				=	
CPPC_F_MINIMUM_SIZE     =   -O1
CPPC_F_MAXIMUM_SPEED	=	-O2

CPPC_FLAGS_BASE =\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

CPPC_FLAGS_MT_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_DLL_D =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_DLL_R =\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_R =\
 $(CPPC_FLAGS_BASE)\
 \


# CC defines

CC_DEFS_BASE =\
 $(COMMON_DEFS)\
 $(CUSTOM_DEFS)\
 \


CC_DEFS_MT_D =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_DLL_D =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_DLL_R =\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_MT_R =\
 $(CC_DEFS_BASE)\
 \


# CPPC defines

CPPC_DEFS_BASE =\
 $(COMMON_DEFS)\
 $(CUSTOM_DEFS)\
 \


CPPC_DEFS_MT_D =\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_DLL_D =\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_DLL_R =\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_MT_R =\
 $(CPPC_DEFS_BASE)\
 \



# CC includes

CC_INCLUDES_BASE =\
 \
 -I$(PROJ_INCLUDE_DIR)\
 $(SHWILD_PROJ_INCLUDE)\
 -I$(STLSOFT)\include\
 $(COMMON_INCLUDES)\
 \


CC_INCLUDES_MT_D =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_DLL_D =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_DLL_R =\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_MT_R =\
 $(CC_INCLUDES_BASE)\
 \



CC_SHWILD_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_D =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_DLL_D =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_DLL_R =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_R =\
 $(CC_SHWILD_INCLUDES_BASE)\
 \


CC_XTESTS_INCLUDES_BASE =\
 $(CC_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_D =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_DLL_D =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_DLL_R =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_R =\
 $(CC_XTESTS_INCLUDES_BASE)\
 \


# CPPC includes

CPPC_INCLUDES_BASE =\
 \
 -I$(PROJ_INCLUDE_DIR)\
 $(SHWILD_PROJ_INCLUDE)\
 -I$(STLSOFT)\include\
 $(COMMON_INCLUDES)\
 \


CPPC_INCLUDES_MT_D =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_DLL_D =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_DLL_R =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_MT_R =\
 $(CPPC_INCLUDES_BASE)\
 \



CPPC_SHWILD_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DLL_D =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DLL_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_R =\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE =\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_DLL_D =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_DLL_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_R =\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \



# CC args (= flags + defines + includes)

CC_ARGS_MT_D=\
 $(CC_FLAGS_MT_D)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -Zi -Fd$*.pdb\
 $(CC_DEFS_MT_D)\
 -DXTESTS_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_MT_D)
CC_ARGS_DLL_D=\
 $(CC_FLAGS_DLL_D)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MDd -D_DEBUG -Zi -Fd$*.pdb $(CC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CC_DEFS_DLL_D)\
 -DXTESTS_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_DLL_D)
CC_ARGS_DLL_R=\
 $(CC_FLAGS_DLL_R)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MD -DNDEBUG $(CC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CC_DEFS_DLL_R)\
 -DXTESTS_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_DLL_R)
CC_ARGS_MT_R=\
 $(CC_FLAGS_MT_R)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MT -DNDEBUG $(CC_F_MAXIMUM_SPEED)\
 $(CC_DEFS_MT_R)\
 -DXTESTS_NO_IMPLICIT_LINK\
 $(CC_INCLUDES_MT_R)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_D=\
 $(CPPC_FLAGS_MT_D)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -Zi -Fd$*.pdb\
 $(CPPC_DEFS_MT_D)\
 -DXTESTS_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_D)
CPPC_ARGS_DLL_D=\
 $(CPPC_FLAGS_DLL_D)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MDd -D_DEBUG -Zi -Fd$*.pdb $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_D)\
 -DXTESTS_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_DLL_D)
CPPC_ARGS_DLL_R=\
 $(CPPC_FLAGS_DLL_R)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MD -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) -D_AFXDLL\
 $(CPPC_DEFS_DLL_R)\
 -DXTESTS_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_DLL_R)
CPPC_ARGS_MT_R=\
 $(CPPC_FLAGS_MT_R)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MT -DNDEBUG $(CPPC_F_MAXIMUM_SPEED)\
 $(CPPC_DEFS_MT_R)\
 -DXTESTS_NO_IMPLICIT_LINK\
 $(CPPC_INCLUDES_MT_R)



# AR args

AR_ARGS 			=	-nologo


# LD flags

LD_F_NOLOGO				=   -nologo

LD_FLAGS_BASE =\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_DLL_D =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_DLL_R =\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_R =\
 $(LD_FLAGS_BASE)\
 \


# LD includes

LD_INCLUDES_BASE =\
 $(LIBPATHS)\
 \

LD_INCLUDES_MT_D =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_DLL_D =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_DLL_R =\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_R =\
 $(LD_INCLUDES_BASE)\
 \


# LD args

LD_ARGS_MT_D= $(LD_FLAGS_MT_D)  $(LD_INCLUDES_MT_D)
LD_ARGS_DLL_D= $(LD_FLAGS_DLL_D)  $(LD_INCLUDES_DLL_D)
LD_ARGS_DLL_R= $(LD_FLAGS_DLL_R)  $(LD_INCLUDES_DLL_R)
LD_ARGS_MT_R= $(LD_FLAGS_MT_R)  $(LD_INCLUDES_MT_R)

############################################################################
# Headers

CORE_HEADERS=\
 $(PROJ_INCLUDE_DIR)\flecxx\xtests\xtests.h\
 $(PROJ_INCLUDE_DIR)\flecxx\xtests\implicit_link.h\
 $(PROJ_INCLUDE_DIR)\flecxx\xtests\internal\safestr.h\
 \

SHWILD_HEADERS=\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.h\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.hpp\
 \

############################################################################
# Names

############################################################
# Targets

########################################
# Libraries

# core
LIB_CORE_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_CORE_DLL_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_CORE_DLL_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).dll.lib
LIB_CORE_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.lib

# shwild - testing only
LIB_SHWILD_MT_D			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_SHWILD_DLL_D			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_SHWILD_DLL_R			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG).dll.lib
LIB_SHWILD_MT_R			=	$(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG).mt.lib

########################################
# Examples

OBJ_EX_C_runner_MT_D	=   $(PROJ_OBJ_DIR)\example.c.runner.mt.debug.obj
OBJ_EX_C_runner_DLL_D	=   $(PROJ_OBJ_DIR)\example.c.runner.dll.debug.obj
OBJ_EX_C_runner_DLL_R	=   $(PROJ_OBJ_DIR)\example.c.runner.dll.obj
OBJ_EX_C_runner_MT_R	=   $(PROJ_OBJ_DIR)\example.c.runner.mt.obj

OBJ_EX_C_tests_MT_D		=   $(PROJ_OBJ_DIR)\example.c.tests.mt.debug.obj
OBJ_EX_C_tests_DLL_D		=   $(PROJ_OBJ_DIR)\example.c.tests.dll.debug.obj
OBJ_EX_C_tests_DLL_R		=   $(PROJ_OBJ_DIR)\example.c.tests.dll.obj
OBJ_EX_C_tests_MT_R		=   $(PROJ_OBJ_DIR)\example.c.tests.mt.obj

########################################
# Tests


##############################
# Component Tests


##############################
# Scratch Tests

OBJ_TEST_SCRT_basics1_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.basics1.mt.debug.obj
OBJ_TEST_SCRT_basics1_DLL_D =   $(PROJ_OBJ_DIR)\test.scratch.basics1.dll.debug.obj
OBJ_TEST_SCRT_basics1_DLL_R =   $(PROJ_OBJ_DIR)\test.scratch.basics1.dll.obj
OBJ_TEST_SCRT_basics1_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.basics1.mt.obj

OBJ_TEST_SCRT_basics2_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.basics2.mt.debug.obj
OBJ_TEST_SCRT_basics2_DLL_D =   $(PROJ_OBJ_DIR)\test.scratch.basics2.dll.debug.obj
OBJ_TEST_SCRT_basics2_DLL_R =   $(PROJ_OBJ_DIR)\test.scratch.basics2.dll.obj
OBJ_TEST_SCRT_basics2_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.basics2.mt.obj

OBJ_TEST_SCRT_failall1_MT_D =   $(PROJ_OBJ_DIR)\test.scratch.fail_all.1.mt.debug.obj
OBJ_TEST_SCRT_failall1_DLL_D =   $(PROJ_OBJ_DIR)\test.scratch.fail_all.1.dll.debug.obj
OBJ_TEST_SCRT_failall1_DLL_R =   $(PROJ_OBJ_DIR)\test.scratch.fail_all.1.dll.obj
OBJ_TEST_SCRT_failall1_MT_R =   $(PROJ_OBJ_DIR)\test.scratch.fail_all.1.mt.obj

############################################################
# Objects

########################################
# Libraries

# core

OBJ_lib_core_MT_D =	$(PROJ_OBJ_DIR)\core.mt.debug.obj
PDB_lib_core_MT_D	=	$(PROJ_OBJ_DIR)\core.mt.debug.pdb

OBJ_CORE_MT_D=\
 $(OBJ_lib_core_MT_D)\
 \

PDB_CORE_MT_D=\
 $(PDB_lib_core_MT_D)\
 \

OBJ_lib_core_DLL_D =	$(PROJ_OBJ_DIR)\core.dll.debug.obj
PDB_lib_core_DLL_D	=	$(PROJ_OBJ_DIR)\core.dll.debug.pdb

OBJ_CORE_DLL_D=\
 $(OBJ_lib_core_DLL_D)\
 \

PDB_CORE_DLL_D=\
 $(PDB_lib_core_DLL_D)\
 \

OBJ_lib_core_DLL_R =	$(PROJ_OBJ_DIR)\core.dll.obj

OBJ_CORE_DLL_R=\
 $(OBJ_lib_core_DLL_R)\
 \

OBJ_lib_core_MT_R =	$(PROJ_OBJ_DIR)\core.mt.obj

OBJ_CORE_MT_R=\
 $(OBJ_lib_core_MT_R)\
 \


# shwild

OBJ_shw_api_MT_D            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.debug.obj
OBJ_shw_matches_MT_D        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.debug.obj
OBJ_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.debug.obj
PDB_shw_api_MT_D            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.debug.pdb
PDB_shw_matches_MT_D        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.debug.pdb
PDB_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.debug.pdb

OBJ_SHWILD_MT_D=\
 $(OBJ_shw_api_MT_D)\
 $(OBJ_shw_matches_MT_D)\
 $(OBJ_shw_pattern_MT_D)\
 \

PDB_SHWILD_MT_D=\
 $(PDB_shw_api_MT_D)\
 $(PDB_shw_matches_MT_D)\
 $(PDB_shw_pattern_MT_D)\
 \

OBJ_shw_api_DLL_D            = $(PROJ_OBJ_DIR)\shwild.pan.api.dll.debug.obj
OBJ_shw_matches_DLL_D        = $(PROJ_OBJ_DIR)\shwild.pan.matches.dll.debug.obj
OBJ_shw_pattern_DLL_D        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.dll.debug.obj
PDB_shw_api_DLL_D            = $(PROJ_OBJ_DIR)\shwild.pan.api.dll.debug.pdb
PDB_shw_matches_DLL_D        = $(PROJ_OBJ_DIR)\shwild.pan.matches.dll.debug.pdb
PDB_shw_pattern_DLL_D        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.dll.debug.pdb

OBJ_SHWILD_DLL_D=\
 $(OBJ_shw_api_DLL_D)\
 $(OBJ_shw_matches_DLL_D)\
 $(OBJ_shw_pattern_DLL_D)\
 \

PDB_SHWILD_DLL_D=\
 $(PDB_shw_api_DLL_D)\
 $(PDB_shw_matches_DLL_D)\
 $(PDB_shw_pattern_DLL_D)\
 \

OBJ_shw_api_DLL_R            = $(PROJ_OBJ_DIR)\shwild.pan.api.dll.obj
OBJ_shw_matches_DLL_R        = $(PROJ_OBJ_DIR)\shwild.pan.matches.dll.obj
OBJ_shw_pattern_DLL_R        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.dll.obj

OBJ_SHWILD_DLL_R=\
 $(OBJ_shw_api_DLL_R)\
 $(OBJ_shw_matches_DLL_R)\
 $(OBJ_shw_pattern_DLL_R)\
 \

OBJ_shw_api_MT_R            = $(PROJ_OBJ_DIR)\shwild.pan.api.mt.obj
OBJ_shw_matches_MT_R        = $(PROJ_OBJ_DIR)\shwild.pan.matches.mt.obj
OBJ_shw_pattern_MT_R        = $(PROJ_OBJ_DIR)\shwild.pan.pattern.mt.obj

OBJ_SHWILD_MT_R=\
 $(OBJ_shw_api_MT_R)\
 $(OBJ_shw_matches_MT_R)\
 $(OBJ_shw_pattern_MT_R)\
 \



########################################
# Examples

TARG_EX_C_runner_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.runner.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_runner_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.runner.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_C_runner_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.runner.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_C_runner_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.runner.$(COMP_ARCH_OS_TAG).mt.exe

TARG_EX_C_tests_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.tests.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_C_tests_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.tests.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_C_tests_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.tests.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_C_tests_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.tests.$(COMP_ARCH_OS_TAG).mt.exe

########################################
# Tests

##############################
# Component Tests


##############################
# Scratch Tests

TARG_TEST_SCRT_basics1_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.basics1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_basics1_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.basics1.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_SCRT_basics1_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.basics1.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_SCRT_basics1_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.basics1.$(COMP_ARCH_OS_TAG).mt.exe

TARG_TEST_SCRT_basics2_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.basics2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_basics2_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.basics2.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_SCRT_basics2_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.basics2.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_SCRT_basics2_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.basics2.$(COMP_ARCH_OS_TAG).mt.exe

TARG_TEST_SCRT_failall1_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.fail_all.1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_failall1_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.fail_all.1.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_SCRT_failall1_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.fail_all.1.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_SCRT_failall1_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.fail_all.1.$(COMP_ARCH_OS_TAG).mt.exe

##############################
# Unit Tests


# Target groups

########################################
# Objects

# core
OBJ_CORE=\
 $(OBJ_CORE_MT_D)\
 $(OBJ_CORE_DLL_D)\
 $(OBJ_CORE_DLL_R)\
 $(OBJ_CORE_MT_R)\
 \

# shwild
OBJ_SHWILD=\
 $(OBJ_SHWILD_MT_D)\
 $(OBJ_SHWILD_DLL_D)\
 $(OBJ_SHWILD_DLL_R)\
 $(OBJ_SHWILD_MT_R)\
 \

# examples
OBJ_EXAMPLE=\
 $(OBJ_EX_C_runner_MT_D)\
 $(OBJ_EX_C_tests_MT_D)\
 $(OBJ_EX_C_runner_DLL_D)\
 $(OBJ_EX_C_tests_DLL_D)\
 $(OBJ_EX_C_runner_DLL_R)\
 $(OBJ_EX_C_tests_DLL_R)\
 $(OBJ_EX_C_runner_MT_R)\
 $(OBJ_EX_C_tests_MT_R)\
 \

# Component Tests
OBJ_TEST_COMPONENT=\
 \

# Scratch Tests
OBJ_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_basics1_MT_D)\
 $(OBJ_TEST_SCRT_basics2_MT_D)\
 $(OBJ_TEST_SCRT_failall1_MT_D)\
 $(OBJ_TEST_SCRT_basics1_DLL_D)\
 $(OBJ_TEST_SCRT_basics2_DLL_D)\
 $(OBJ_TEST_SCRT_failall1_DLL_D)\
 $(OBJ_TEST_SCRT_basics1_DLL_R)\
 $(OBJ_TEST_SCRT_basics2_DLL_R)\
 $(OBJ_TEST_SCRT_failall1_DLL_R)\
 $(OBJ_TEST_SCRT_basics1_MT_R)\
 $(OBJ_TEST_SCRT_basics2_MT_R)\
 $(OBJ_TEST_SCRT_failall1_MT_R)\
 \

# Unit Tests
OBJ_TEST_UNIT=\
 \

########################################
# Libraries

TARGETS_LIB_CORE=\
 $(LIB_CORE_MT_D)\
 $(LIB_CORE_DLL_D)\
 $(LIB_CORE_DLL_R)\
 $(LIB_CORE_MT_R)\
 \

TARGETS_LIB_ALL=\
 $(TARGETS_LIB_CORE)\
 \

TARGETS_LIB_SHWILD=\
 $(LIB_SHWILD_MT_D)\
 $(LIB_SHWILD_DLL_D)\
 $(LIB_SHWILD_DLL_R)\
 $(LIB_SHWILD_MT_R)\
 \

########################################
# Programs

TARGETS_EXAMPLE_C=\
 $(TARG_EX_C_runner_MT_D)\
 $(TARG_EX_C_tests_MT_D)\
 $(TARG_EX_C_runner_DLL_D)\
 $(TARG_EX_C_tests_DLL_D)\
 $(TARG_EX_C_runner_DLL_R)\
 $(TARG_EX_C_tests_DLL_R)\
 $(TARG_EX_C_runner_MT_R)\
 $(TARG_EX_C_tests_MT_R)\
 \

TARGETS_EXAMPLE_CPP=\
 \

TARGETS_EXAMPLE=\
 $(TARGETS_EXAMPLE_C)\
 $(TARGETS_EXAMPLE_CPP)\
 \


TARGETS_SAMPLE=\
 \


TARGETS_TEST_COMPONENT=\
 \

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_basics1_MT_D)\
 $(TARG_TEST_SCRT_basics2_MT_D)\
 $(TARG_TEST_SCRT_failall1_MT_D)\
 $(TARG_TEST_SCRT_basics1_DLL_D)\
 $(TARG_TEST_SCRT_basics2_DLL_D)\
 $(TARG_TEST_SCRT_failall1_DLL_D)\
 $(TARG_TEST_SCRT_basics1_DLL_R)\
 $(TARG_TEST_SCRT_basics2_DLL_R)\
 $(TARG_TEST_SCRT_failall1_DLL_R)\
 $(TARG_TEST_SCRT_basics1_MT_R)\
 $(TARG_TEST_SCRT_basics2_MT_R)\
 $(TARG_TEST_SCRT_failall1_MT_R)\
 \

TARGETS_TEST_UNIT=\
 \


############################################################
# Third-party libraries

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

compile.libs.core:			$(PROJ_MAKEFILE_NAME)	$(OBJ_CORE)

compile.libs:										compile.libs.core

compile.libs.shwild:		$(PROJ_MAKEFILE_NAME)	$(OBJ_SHWILD)

compile.libs.3pty:									compile.libs.shwild

compile.libs.all:                                   compile.libs compile.libs.3pty

compile.examples:			$(PROJ_MAKEFILE_NAME)	$(OBJ_EXAMPLE)

compile.samples:			$(PROJ_MAKEFILE_NAME)	$(OBJ_SAMPLE)

compile.test.component:		$(PROJ_MAKEFILE_NAME)	$(OBJ_TEST_COMPONENT)

compile.test.scratch:		$(PROJ_MAKEFILE_NAME)	$(OBJ_TEST_SCRATCH)

compile.test.unit:			$(PROJ_MAKEFILE_NAME)	$(OBJ_TEST_UNIT)

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
	-$(TARG_TEST_SCRT_failall1_MT_D) --verbosity=$(TEST_VERBOSITY)
	-$(TARG_TEST_SCRT_failall1_DLL_D) --verbosity=$(TEST_VERBOSITY)
	-$(TARG_TEST_SCRT_failall1_DLL_R) --verbosity=$(TEST_VERBOSITY)
	-$(TARG_TEST_SCRT_failall1_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics1_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics1_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics1_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics1_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics2_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics2_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics2_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_SCRT_basics2_MT_R) --verbosity=$(TEST_VERBOSITY)

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
	@-if exist core.obj $(RM) core.obj
	@-if exist core.*.obj $(RM) core.*.obj
	@-if exist core.pdb $(RM) core.pdb
	@-if exist core.*.pdb $(RM) core.*.pdb
	@-if exist $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG)*.lib

clean.libs.shwild:
	@echo Cleaning shwild libraries ...
	@-if exist shwild.*.obj $(RM) shwild.*.obj
	@-if exist shwild.*.pdb $(RM) shwild.*.pdb
	@-if exist $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).xt.$(COMP_ARCH_OS_TAG)*.lib

clean.test.component:
	@echo cleaning Test:Component programs ...

clean.test.scratch:
	@echo cleaning Test:Scratch programs ...
	@-if exist $(TARG_TEST_SCRT_basics1_MT_D) $(RM) $(TARG_TEST_SCRT_basics1_MT_D)
	@-if exist $(OBJ_TEST_SCRT_basics1_MT_D) $(RM) $(OBJ_TEST_SCRT_basics1_MT_D)
	@-if exist $(TARG_TEST_SCRT_basics2_MT_D) $(RM) $(TARG_TEST_SCRT_basics2_MT_D)
	@-if exist $(OBJ_TEST_SCRT_basics2_MT_D) $(RM) $(OBJ_TEST_SCRT_basics2_MT_D)
	@-if exist $(TARG_TEST_SCRT_failall1_MT_D) $(RM) $(TARG_TEST_SCRT_failall1_MT_D)
	@-if exist $(OBJ_TEST_SCRT_failall1_MT_D) $(RM) $(OBJ_TEST_SCRT_failall1_MT_D)
	@-if exist $(PDB_TEST_SCRT_basics1_MT_D) $(RM) $(PDB_TEST_SCRT_basics1_MT_D)
	@-if exist $(PDB_TEST_SCRT_basics2_MT_D) $(RM) $(PDB_TEST_SCRT_basics2_MT_D)
	@-if exist $(PDB_TEST_SCRT_failall1_MT_D) $(RM) $(PDB_TEST_SCRT_failall1_MT_D)
	@-if exist test.*.pdb $(RM) test.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.*.$(COMP_ARCH_OS_TAG)*.exe $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.*.$(COMP_ARCH_OS_TAG)*.exe
	@-if exist $(TARG_TEST_SCRT_basics1_DLL_D) $(RM) $(TARG_TEST_SCRT_basics1_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_basics1_DLL_D) $(RM) $(OBJ_TEST_SCRT_basics1_DLL_D)
	@-if exist $(TARG_TEST_SCRT_basics2_DLL_D) $(RM) $(TARG_TEST_SCRT_basics2_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_basics2_DLL_D) $(RM) $(OBJ_TEST_SCRT_basics2_DLL_D)
	@-if exist $(TARG_TEST_SCRT_failall1_DLL_D) $(RM) $(TARG_TEST_SCRT_failall1_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_failall1_DLL_D) $(RM) $(OBJ_TEST_SCRT_failall1_DLL_D)
	@-if exist $(PDB_TEST_SCRT_basics1_DLL_D) $(RM) $(PDB_TEST_SCRT_basics1_DLL_D)
	@-if exist $(PDB_TEST_SCRT_basics2_DLL_D) $(RM) $(PDB_TEST_SCRT_basics2_DLL_D)
	@-if exist $(PDB_TEST_SCRT_failall1_DLL_D) $(RM) $(PDB_TEST_SCRT_failall1_DLL_D)
	@-if exist test.*.pdb $(RM) test.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.*.$(COMP_ARCH_OS_TAG)*.exe $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.*.$(COMP_ARCH_OS_TAG)*.exe
	@-if exist $(TARG_TEST_SCRT_basics1_DLL_R) $(RM) $(TARG_TEST_SCRT_basics1_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_basics1_DLL_R) $(RM) $(OBJ_TEST_SCRT_basics1_DLL_R)
	@-if exist $(TARG_TEST_SCRT_basics2_DLL_R) $(RM) $(TARG_TEST_SCRT_basics2_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_basics2_DLL_R) $(RM) $(OBJ_TEST_SCRT_basics2_DLL_R)
	@-if exist $(TARG_TEST_SCRT_failall1_DLL_R) $(RM) $(TARG_TEST_SCRT_failall1_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_failall1_DLL_R) $(RM) $(OBJ_TEST_SCRT_failall1_DLL_R)
	@-if exist test.*.pdb $(RM) test.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.*.$(COMP_ARCH_OS_TAG)*.exe $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.*.$(COMP_ARCH_OS_TAG)*.exe
	@-if exist $(TARG_TEST_SCRT_basics1_MT_R) $(RM) $(TARG_TEST_SCRT_basics1_MT_R)
	@-if exist $(OBJ_TEST_SCRT_basics1_MT_R) $(RM) $(OBJ_TEST_SCRT_basics1_MT_R)
	@-if exist $(TARG_TEST_SCRT_basics2_MT_R) $(RM) $(TARG_TEST_SCRT_basics2_MT_R)
	@-if exist $(OBJ_TEST_SCRT_basics2_MT_R) $(RM) $(OBJ_TEST_SCRT_basics2_MT_R)
	@-if exist $(TARG_TEST_SCRT_failall1_MT_R) $(RM) $(TARG_TEST_SCRT_failall1_MT_R)
	@-if exist $(OBJ_TEST_SCRT_failall1_MT_R) $(RM) $(OBJ_TEST_SCRT_failall1_MT_R)
	@-if exist test.*.pdb $(RM) test.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.*.$(COMP_ARCH_OS_TAG)*.exe $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.*.$(COMP_ARCH_OS_TAG)*.exe

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
# Libraries

########################################
# shwild library - 'shwild.X.pan.core.a'

$(LIB_SHWILD_MT_D): $(OBJ_SHWILD_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_D)

$(OBJ_shw_api_MT_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_DLL_D): $(OBJ_SHWILD_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_DLL_D)

$(OBJ_shw_api_DLL_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_DLL_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_DLL_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_DLL_R): $(OBJ_SHWILD_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_DLL_R)

$(OBJ_shw_api_DLL_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_DLL_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_DLL_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_MT_R): $(OBJ_SHWILD_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_R)

$(OBJ_shw_api_MT_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

########################################
# Main library - 'xtests.X.core.a'

$(LIB_CORE_MT_D): $(OBJ_CORE_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_D)

$(OBJ_lib_core_MT_D):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xtests.core.cpp
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\xtests.core.cpp

$(LIB_CORE_DLL_D): $(OBJ_CORE_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_DLL_D)

$(OBJ_lib_core_DLL_D):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xtests.core.cpp
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\xtests.core.cpp

$(LIB_CORE_DLL_R): $(OBJ_CORE_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_DLL_R)

$(OBJ_lib_core_DLL_R):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xtests.core.cpp
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\xtests.core.cpp

$(LIB_CORE_MT_R): $(OBJ_CORE_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_R)

$(OBJ_lib_core_MT_R):	$(PROJ_MAKEFILE_NAME) $(PROJ_SRC_DIR)\xtests.core.cpp
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_SRC_DIR)\xtests.core.cpp

##################################################
# Examples

$(TARG_EX_C_runner_MT_D):	\
			$(OBJ_EX_C_runner_MT_D)\
			$(LIB_CORE_MT_D)\
			$(LIB_SHWILD_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_C_runner_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_C_runner_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c

$(TARG_EX_C_runner_DLL_D):	\
			$(OBJ_EX_C_runner_DLL_D)\
			$(LIB_CORE_DLL_D)\
			$(LIB_SHWILD_DLL_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_C_runner_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_C_runner_DLL_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c

$(TARG_EX_C_runner_DLL_R):	\
			$(OBJ_EX_C_runner_DLL_R)\
			$(LIB_CORE_DLL_R)\
			$(LIB_SHWILD_DLL_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_C_runner_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_C_runner_DLL_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c

$(TARG_EX_C_runner_MT_R):	\
			$(OBJ_EX_C_runner_MT_R)\
			$(LIB_CORE_MT_R)\
			$(LIB_SHWILD_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_C_runner_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_C_runner_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.runner\example.c.runner.c

$(TARG_EX_C_tests_MT_D):	\
			$(OBJ_EX_C_tests_MT_D)\
			$(LIB_CORE_MT_D)\
			$(LIB_SHWILD_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_C_tests_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_C_tests_MT_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c

$(TARG_EX_C_tests_DLL_D):	\
			$(OBJ_EX_C_tests_DLL_D)\
			$(LIB_CORE_DLL_D)\
			$(LIB_SHWILD_DLL_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_C_tests_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_C_tests_DLL_D):	$(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c

$(TARG_EX_C_tests_DLL_R):	\
			$(OBJ_EX_C_tests_DLL_R)\
			$(LIB_CORE_DLL_R)\
			$(LIB_SHWILD_DLL_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_C_tests_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_C_tests_DLL_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c

$(TARG_EX_C_tests_MT_R):	\
			$(OBJ_EX_C_tests_MT_R)\
			$(LIB_CORE_MT_R)\
			$(LIB_SHWILD_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_C_tests_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_C_tests_MT_R):	$(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example.c.tests\example.c.tests.c

##################################################
# Tests

##############################
# Component Tests

##############################
# Scratch Tests

$(TARG_TEST_SCRT_basics1_MT_D):	\
			$(OBJ_TEST_SCRT_basics1_MT_D)\
			$(LIB_CORE_MT_D)\
			$(LIB_SHWILD_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_basics1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_basics1_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c

$(TARG_TEST_SCRT_basics1_DLL_D):	\
			$(OBJ_TEST_SCRT_basics1_DLL_D)\
			$(LIB_CORE_DLL_D)\
			$(LIB_SHWILD_DLL_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_basics1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_SCRT_basics1_DLL_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c

$(TARG_TEST_SCRT_basics1_DLL_R):	\
			$(OBJ_TEST_SCRT_basics1_DLL_R)\
			$(LIB_CORE_DLL_R)\
			$(LIB_SHWILD_DLL_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_basics1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_SCRT_basics1_DLL_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c

$(TARG_TEST_SCRT_basics1_MT_R):	\
			$(OBJ_TEST_SCRT_basics1_MT_R)\
			$(LIB_CORE_MT_R)\
			$(LIB_SHWILD_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_basics1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_basics1_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) $(CC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics1\test.scratch.basics1.c

$(TARG_TEST_SCRT_basics2_MT_D):	\
			$(OBJ_TEST_SCRT_basics2_MT_D)\
			$(LIB_CORE_MT_D)\
			$(LIB_SHWILD_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_basics2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_basics2_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp

$(TARG_TEST_SCRT_basics2_DLL_D):	\
			$(OBJ_TEST_SCRT_basics2_DLL_D)\
			$(LIB_CORE_DLL_D)\
			$(LIB_SHWILD_DLL_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_basics2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_SCRT_basics2_DLL_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp

$(TARG_TEST_SCRT_basics2_DLL_R):	\
			$(OBJ_TEST_SCRT_basics2_DLL_R)\
			$(LIB_CORE_DLL_R)\
			$(LIB_SHWILD_DLL_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_basics2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_SCRT_basics2_DLL_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp

$(TARG_TEST_SCRT_basics2_MT_R):	\
			$(OBJ_TEST_SCRT_basics2_MT_R)\
			$(LIB_CORE_MT_R)\
			$(LIB_SHWILD_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_basics2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_basics2_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.basics2\test.scratch.basics2.cpp

$(TARG_TEST_SCRT_failall1_MT_D):	\
			$(OBJ_TEST_SCRT_failall1_MT_D)\
			$(LIB_CORE_MT_D)\
			$(LIB_SHWILD_MT_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_failall1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_failall1_MT_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp

$(TARG_TEST_SCRT_failall1_DLL_D):	\
			$(OBJ_TEST_SCRT_failall1_DLL_D)\
			$(LIB_CORE_DLL_D)\
			$(LIB_SHWILD_DLL_D)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_failall1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_SCRT_failall1_DLL_D):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp

$(TARG_TEST_SCRT_failall1_DLL_R):	\
			$(OBJ_TEST_SCRT_failall1_DLL_R)\
			$(LIB_CORE_DLL_R)\
			$(LIB_SHWILD_DLL_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_failall1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_SCRT_failall1_DLL_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp

$(TARG_TEST_SCRT_failall1_MT_R):	\
			$(OBJ_TEST_SCRT_failall1_MT_R)\
			$(LIB_CORE_MT_R)\
			$(LIB_SHWILD_MT_R)\
			$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_failall1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIBS_3PTY_TEST_SCRATCH)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_failall1_MT_R):	$(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp $(TEST_CPP_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_INCLUDES) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.fail_all.1\test.scratch.fail_all.1.cpp

##############################
# Unit Tests

############################### end of file ################################
