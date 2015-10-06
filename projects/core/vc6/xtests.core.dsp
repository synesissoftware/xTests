# Microsoft Developer Studio Project File - Name="xtests.core" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=xtests.core - Win32 Unicode Debug Multithreaded
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "xtests.core.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xtests.core.mak" CFG="xtests.core - Win32 Unicode Debug Multithreaded"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "xtests.core - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "xtests.core - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "xtests.core - Win32 Debug Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE "xtests.core - Win32 Debug pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "xtests.core - Win32 Unicode Debug Multithreaded" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "xtests.core - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.lib"
# ADD LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.lib"

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.debug.lib"

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMT"
# PROP BASE Intermediate_Dir "DebugMT"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMT"
# PROP Intermediate_Dir "DebugMT"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.mt.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.mt.debug.lib"

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugUnix"
# PROP BASE Intermediate_Dir "DebugUnix"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugUnix"
# PROP Intermediate_Dir "DebugUnix"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "_MBCS" /D "_LIB" /D "UNIX" /D "_DEBUG" /D "_STLSOFT_FORCE_ANY_COMPILER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /I "$(UNIXEM)/include" /D "_MBCS" /D "_LIB" /D "UNIX" /D "_DEBUG" /D "_STLSOFT_FORCE_ANY_COMPILER" /YX /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.unix.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.unix.debug.lib"

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Unicode Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "UDebugMt"
# PROP BASE Intermediate_Dir "UDebugMt"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "UDebugMT"
# PROP Intermediate_Dir "UDebugMT"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /Zi /Od /I "../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /YX /FD /GZ /c
# SUBTRACT CPP /Fr
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.mt.debug.lib"
# ADD LIB32 /nologo /out:"../../../lib/xtests.0.core.vc6.widestring.mt.debug.lib"

!ENDIF 

# Begin Target

# Name "xtests.core - Win32 Release"
# Name "xtests.core - Win32 Debug"
# Name "xtests.core - Win32 Debug Multithreaded"
# Name "xtests.core - Win32 Debug pseudoUNIX"
# Name "xtests.core - Win32 Unicode Debug Multithreaded"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\src\xtests.core.cpp

!IF  "$(CFG)" == "xtests.core - Win32 Release"

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug"

# ADD CPP /Zi

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug Multithreaded"

# ADD BASE CPP /Zi
# ADD CPP /Zi

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug pseudoUNIX"

# ADD BASE CPP /Zi
# ADD CPP /Zi

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Unicode Debug Multithreaded"

# ADD BASE CPP /Zi
# ADD CPP /Zi

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\src\xtests.internal.string.c

!IF  "$(CFG)" == "xtests.core - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug Multithreaded"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Debug pseudoUNIX"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "xtests.core - Win32 Unicode Debug Multithreaded"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "STLSoft Header Files"

# PROP Default_Filter ""
# Begin Group "STLSoft"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_features.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\allocator_selector.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\std\alt.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\memory\auto_buffer.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\basic_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\c_string.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\capabilities.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\case_functions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\conversion\char_conversions.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\char_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\collections\util\collections.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\constraints.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\error\conversion_error.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\ctype_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\std\exception.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string\fwd.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\head_version.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\integral_printf_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_integral_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_pointer_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\is_same_type.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\iterator_helper.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\lead_version.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std\library_discriminator.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\util\meta_.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\msvc.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\n_types.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\cccap\obsolete.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\algorithms\pod.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\internal\safestr.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\shim_string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\sign_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\size_of.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\size_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\util\std_swap.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\stlsoft.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\shims\access\string.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\string_traits.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\string\string_traits_fwd.hpp"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\stlsoft\meta\yesno.hpp"
# End Source File
# End Group
# Begin Group "PlatformSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\platformstl\platformstl.h"
# End Source File
# End Group
# Begin Group "UNIXSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\unixstl\synch\util\features.h"
# End Source File
# Begin Source File

SOURCE="$(STLSOFT)\include\unixstl\unixstl.h"
# End Source File
# End Group
# Begin Group "WinSTL"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(STLSOFT)\include\winstl\winstl.h"
# End Source File
# End Group
# End Group
# Begin Group "UNIXem Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(UNIXEM)\include\unistd.h"
# End Source File
# Begin Source File

SOURCE="$(UNIXEM)\include\unixem\unistd.h"
# End Source File
# Begin Source File

SOURCE="$(UNIXEM)\include\unixem\unixem.h"
# End Source File
# End Group
# Begin Group "xTests Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\xtests\internal\safestr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\xtests\xtests.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\xtests.internal.exception_macros.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\xtests.internal.string.h
# End Source File
# End Group
# End Group
# Begin Group "Distribution Files"

# PROP Default_Filter "txt"
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\AUTHORS.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\CHANGES.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\FAQ.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\HISTORY.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\INSTALL.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\KNOWN_ISSUES.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\LICENSE.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\NEWS.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\README.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\TODO.txt"
# End Source File
# End Group
# Begin Source File

SOURCE=..\ideas.txt
# End Source File
# End Target
# End Project
