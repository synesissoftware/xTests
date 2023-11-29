xTests - Install
================

Updated:    30th November 2023


The following steps are required to install xTests:

    1. Obtain the latest distribution of xTests, from
       https://github.com/synesissoftware/xTests/

    2. Unzip it to a directory of your choice, e.g ~/3pty/xtests-0.20.1

    3. Define an environment variable XTESTS_C_ROOT, whose
       value is the directory in which you unzipped
       it, e.g. XTESTS_C_ROOT=~/3pty/xtests-0.20.1

    4. Download the latest distribution of STLSoft (see NOTE below)

    5. Unzip it to a directory of your choice, e.g ~/3pty/stlsoft-1.10

    6. Define an environment variable STLSOFT, whose value is the directory
       in which you unzipped it, e.g. STLSOFT=~/3pty/stlsoft-1.10

    7. Open a command shell in the appropriate directory that matches your
       compiler:

       * if you're compiling with Visual C++ 7.1 then cd to build/vc71
       * if you're compiling for UNIX with GCC 4.2, then cd
         to build/gcc42.unix
       * if you're compiling for Win-x64 with Visual C++ 9, then cd
         to build/vc9.x64

    8. Build using make:

       * to build the xTests core libraries: "make build.libs.core"
       * to build all libraries, examples and test: "make build"
       * to build and run unit/component tests: "make test"
       * to build and run performance tests: "make test.performance"

NOTE: xTests depends on the (header-only) STLSoft libraries - version
  1.9.134 or later - available from
  https://github.com/synesissoftware/STLSoft-1.9. It is recommended to use
  STLSoft 1.10 or later, available from
  https://github.com/synesissoftware/STLSoft-1.10

=============================== end of file ================================

