# xTests - History


30th December 2024 - 0.26.0-alpha2
----------------------------------

T.B.C.


23rd November 2024 - 0.26.0-alpha1
----------------------------------

 * now uses `stlsoft::integral_traits<>` for integer test macros (in C++) to allow for custom integral types to be tested;
 * added terse forms of macros, available by including **xtests/terse-api.h**;
 * `XTESTS_COMMANDLINE_PARSE_VERBOSITY()` now also recognises, if the command-line argument `"--verbosity= . . ."` is not found, the enviroment variables `"XTESTS_VERBOSITY"` and `"TEST_VERBOSITY"`;
 * minor improvements to project boilerplate files;
 * minor tidying to CMake facilities;
 * updated **STLSoft** constructs, incl. macros;


18th November 2024 - 0.25.4
---------------------------

 * added CMake MSVC MT support;


25th October 2024 - 0.25.3
--------------------------

 * Fix to colour output at high verbosity levels;


22nd October 2024 - 0.25.2
--------------------------

 * Added and applied CMake functions for examples and test programs;
 * Some refactoring in main header **include/xtests/xtests.h**;
 * VC++ 19+ warnings;
 * Fixed vulnerability in length-limited string comparisons;
 * Renamed project **test.scratch.string_slices.c** => **test.unit.string_slices.c**;


20th October 2024 - 0.25.0
--------------------------

 * NO CHANGES;


18th October 2024 - 0.24.0-alpha7
---------------------------------

 * Coloured output now bold;
 * Minor fixes to CMake build scripts;


17th October 2024 - 0.24.0-alpha6
---------------------------------

 * Expanded shwild integration (including CMake detection);
 * Significant enhancement and refactoring around use of CMake;
 * Added coloured output for test-case / runner names;
 * General tidying;
 * Compatibility with legacy versions of Visual C++;


15th October 2024 - 0.24.0-alpha5
---------------------------------

 * Refactored common aspects of example and test `main()` functions;
 * Language/compiler compatibility fixes, including **MinGW-W64** compatibility;
 * CMake build scripts enhancements;


5th August 2024 - 0.24.0-alpha4
-------------------------------

 * compatibility with STLSoft 1.11.1-alpha13 or later;


4th August 2024 - 0.24.0-alpha3
-------------------------------

 * minimal coloured console output;


4th August 2024 - 0.24.0-alpha2
-------------------------------

 * fixed VC++ / CMake configuration;


3rd August 2024 - 0.24.0-alpha1
-------------------------------

 * `XTESTS_TEST_INTEGER_EQUAL_EXACT()`, `XTESTS_TEST_INTEGER_NOT_EQUAL()`, `XTESTS_TEST_INTEGER_GREATER()`, `XTESTS_TEST_INTEGER_GREATER_OR_EQUAL()`, `XTESTS_TEST_INTEGER_LESS()`, `XTESTS_TEST_INTEGER_LESS_OR_EQUAL()` are all implemented in terms of `_Generic` (where supported) in C compilation units in order to be able to report the expected and actual values upon failure (as is done in C++ compilation units)
 * general tidying


14th July 2024 - 0.23.1
-----------------------

 * Various CMake standardisations and simplifications


9th July 2024 - 0.22.1
----------------------

 * Visual C++ 17 (2022) compatibility
 * CMake Windows compatibility
 * Small improvements for `temp_directory` and `temp_file`
 * now depends on STLSoft 1.11


28th January 2024 - 0.21.4
--------------------------

 * Clang 14+ compatibility
 * CMake scripts improvements
 * now depends on STLSoft 1.10.6


28th January 2024 - 0.21.3
--------------------------

 * Clang 14+ compatibility


28th January 2024 - 0.21.2
--------------------------

 * **CMake** support minor improvements;


11th January 2024 - 0.21.1
--------------------------

 * fixed include of **STLSoft** header-file in presence of **shwild**


2nd January 2024 - 0.21.0
-------------------------

 * added `XTESTS_TEST_MULTIBYTE_STRING_MATCHES()` that, in the presence of the shwild library, provides pattern matching


2nd January 2024 - 0.20.5
-------------------------

 * completed CMake support, with flexible mechanism to select STLSoft dependency


14th December 2023 - 0.20.4
---------------------------

 * added CMake support
 * added Doxygen
 * added makefile(s) for GCC generic version
 * fix to xtests::cpp::util::temp_directory
 * fix defect in example


13th December 2020 - 0.20.3
---------------------------

 * fixed xtests::cpp::util::temp_directory dtor semantics for EmptyOnClose and RemoveOnClose
 * compatibility with Visual Studio 2019 (16.8.2)


30th July 2020 - 0.20.2
-----------------------

 * added implicit-link support for VC++ 15 and VC++16
 * added makefile(s) for VC++ 15 and VC++16
 * various makefile improvements
 * GCC 8 compatibility


12th October 2019 - 0.20.1
--------------------------

 * added xtests::cpp::util::temp_file ctor that takes a callback function that is used to provide initial contents of the file
 * added VC++ 10 project and solution files
 * fixed range comparison tests
 * fixing up VC++-specific non-standard token-pasting
 * removed dependency on/discrimination for STLSoft 1.10 delta (though now works perfectly well with STLSoft 1.10 proper)


22nd July 2016 - 0.18.9
-----------------------

 * fix to 0.18.8 release
 * NOTE: requires STLSoft 1.9.128
 * bundles shwild 0.10.1


22nd July 2016 - 0.18.8
-----------------------

 * changed no-throw declaration from stlsoft_throw_0() to STLSOFT_NOEXCEPT
 * support for Borland C++ 6.2x
 * added makefiles for Borland 5.82, 6.1x, 6.2x
 * significant refactoring of structure of makefiles
 * strict C-compilation compatibility
 * NOTE: requires STLSoft 1.9.128
 * bundles shwild 0.10.1


7th October 2015 - 0.18.4
-------------------------

 * added temp_directory and temp_file utility classes
 * now supports test cases that have void* param (for setup param)
 * support for cdecl and stdcall test cases
 * support for Clang
 * support for VC++ 11
 * support for VC++ 12
 * support for VC++ 14
 * NOTE: requires STLSoft 1.9.121
 * bundles shwild 0.10.1


1st March 2013 - 0.17.1
-----------------------

 * added XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL() / XTESTS_TEST_WIDE_STRING_SLICE_EQUAL() macros for testing string slices
 * expected/unexpected exception event messages now include file+line
 * refactoring of implementation
 * tidying up of makefile gripes
 * NOTE: requires STLSoft 1.9.117
 * bundles shwild 0.9.18


16th February 2013 - 0.16.6
---------------------------

 * improved handling of booleans
 * VC++ 11 compatibility
 * NOTE: requires STLSoft 1.9.115
 * bundles shwild 0.9.18


2nd December 2011 - 0.16.3
--------------------------

 * workaround for strange behaviour (probably code-generation fault) in GCC 4.2 on Mac OS-X 10.7
 * NOTE: requires STLSoft 1.9.111


30th November 2011 - 0.16.2
---------------------------

 * various minor modifications for compatibility with recent versions of GCC 4.X
 * NOTE: requires STLSoft 1.9.111


13th August 2010 - 0.16.1
-------------------------

 * added function pointer testing, via XTESTS_TEST_FUNCTION_POINTER_EQUAL() and XTESTS_TEST_FUNCTION_POINTER_NOT_EQUAL()
 * added implicit-link support for VC++ 10
 * fixes for 64-bit compatibility
 * NOTE: requires STLSoft 1.9.100


21st June 2010 - 0.15.2
-----------------------

 * minimal compatibility enhancements
 * NOTE: requires STLSoft 1.9.99


4th April 2010 - 0.15.1
-----------------------

 * added in-range testing, via XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE() and XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE()
 * added XTESTS_ARRAY_END_POST
 * VC6 compatibility for signed __int16, unsigned __int16, & signed __int1632
 * NOTE: requires STLSoft 1.9.97


20th January 2010 - 0.14.4
--------------------------

 * workaround for erroneous Borland compilation error
 * NOTE: requires STLSoft 1.9.89


19th January 2010 - 0.14.3
--------------------------

 * removed erroneous debug information in UNIXem release builds
 * NOTE: requires STLSoft 1.9.89


11th August 2009 - 0.14.2
-------------------------

 * workaround for minor warning
 * NOTE: requires STLSoft 1.9.87


13th July 2009 - 0.14.1
-----------------------

 * added ability to display a summary of only the first case to fail
 * renamed and add to enumerators of xtests_verbosity_t
 * NOTE: requires STLSoft 1.9.85


8th July 2009 - 0.13.3
----------------------

 * workaround for Intel C/C++ compiler defect
 * NOTE: requires STLSoft 1.9.85


16th June 2009 - 0.13.2
-----------------------

 * added XTESTS_REQUIRE(), to allow testing to stop after test failure, to avoid contract violations
 * NOTE: requires STLSoft 1.9.85


1st May 2009 - 0.12.1
---------------------

 * added XTESTS_FLOATINGPOINT_FACTOR_SCOPE scoping class
 * added XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_EXACT, XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX, and XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL test macros
 * NOTE: requires STLSoft 1.9.78


25th April 2009 - 0.11.5
------------------------

 * fixed defect in XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS()
 * added implicit link support for Intel C/C++ 10 & 11
 * allows stream to be NULL, and assumes stdout if no reporter specified
 * NOTE: requires STLSoft 1.9.77


17th April 2009 - 0.11.4
------------------------

 * changes to defn of exceptions & RTTI, for conformance to other library (e.g. Pantheios) makefile templates
 * now allows compilation absent RTTI
 * NOTE: now requires STLSoft 1.9.77


15th April 2009 - 0.11.3
------------------------

 * fixed defect in internal snprintf() abstraction, which faults on Linux
 * NOTE: now requires STLSoft 1.9.77


9th March 2009 - 0.11.2
-----------------------

 * fixed defect in core, whereby snprintf() overrun led to fault
 * NOTE: now requires STLSoft 1.9.76


6th March 2009 - 0.11.1
-----------------------

 * added setup / teardown functionality
 * NOTE: now requires STLSoft 1.9.75


13th February 2009 - 0.10.4
---------------------------

 * added support for Borland 5.9.x and 6.1.x
 * added workaround for over-eager warnings in GCC 4.3
 * NOTE: now requires STLSoft 1.9.74

1st February 2009 - 0.10.3
--------------------------

 * added ability to suppress reporting of empty test cases
 * added XTESTS_START_RUNNER_WITH_FLAGS()
 * now uses Windows debugging support when emulating UNIX on Windows


27th January 2009 - 0.10.2
--------------------------

 Numerous substantial enhancements, including the following:

 * added facilities for length-limiting string comparison
 * added missing macros for case-insensitive string inequality
 * added full support for custom reporter functionality
 * corrected defect whereby s/uint64 integer failures were not counted towards the total
 * fixed various minor defects


29th December 2008 - 0.9.3
--------------------------

 * added XTESTS_TEST_ENUM_TRUE() and XTESTS_TEST_ENUM_FALSE()


18th November 2008 - 0.9.2
--------------------------

 * added XTESTS_TEST_BOOLEAN_TRUE() and XTESTS_TEST_BOOLEAN_FALSE()
 * avoid precipitating warnings about unused return values


25th October 2008 - 0.9.1
-------------------------

 * added xtestsComparisonApproxNotEqual comparison enumerator, and adjusted
   all comparison operations accordingly
 * added xtests_testMultibyteStringContains() and
   xtests_testWideStringContains(), and all corresponding test macros
 * cleared up some wrong (but benign) code exercised when compiling with
   exception-support switched off

25th October 2008 - 0.8.7
-------------------------

 * fixed defective != comparison of signed & unsigned 64-bit integers

19th October 2008 - 0.8.6
-------------------------

 * added more integer specialisations of xtests_failure_reporter<>

23rd August 2008 - 0.8.5
------------------------

 * added call to XTESTS_TEST_PASSED() when an expected exception is received
 * added more integer specialisations of xtests_failure_reporter<>
 * fixed a defect in the approximate comparison of negative floating-point
   numbers

10th August 2008 - 0.8.4
------------------------

 * fixed a bug in the reporting mechanism for boolean enforcement failures

16th June 2008 - 0.8.2
----------------------

 * elimination of compiler warning on VC++ 8+

5th June 2008 - 0.8.1
---------------------

 * added ability to specify output stream (FILE*) when starting a test
   runner

4th June 2008 - 0.7.4
---------------------

 * addition of missing makefiles in the distro

20th May 2008 - 0.7.3
---------------------

 * minor weakening of string comparison
 * bundles shwild 0.9.17

11th May 2008 - 0.7.2
---------------------

 * minor compatibility enhancements

4th May 2008 - 0.7.1
--------------------

 * added Win64-compatibility

29th April 2008 - 0.6.5
-----------------------

 * added compatibity with heterogeneous string types to
   xtests_writeFailMessage()

25th April 2008 - 0.6.4
-----------------------

 * fix for Sun Pro compatibility

22nd April 2008 - 0.6.3
-----------------------

 * fix for Borland compilation error with widestring macros

21st April 2008 - 0.6.2
-----------------------

 * added makefiles for VC9, GCC 4.1 and GCC 4.2
 * altered library names to use UNIX libXXXX naming convention in
   UNIX builds

20th April 2008 - 0.6.1
-----------------------

 * added evaluation of heterogeneous string types, using shim-based
   type-tunneling

19th April 2008 - 0.5.2
-----------------------

 * added implicit link support for VC++ 9

16th April 2008 - 0.5.1
-----------------------

 * added explicit support for character tests
 * fixed bug in formatting of != tests

13th April 2008 - 0.4.1
-----------------------

 * added explicit support for boolean tests

18th March 2008 - 0.3.3
-----------------------

 * fix for wide string support

17th March 2008 - 0.3.2
-----------------------

 * minor bug fix to prevent confusion about threading models on some UNIX
   operating systems

15th March 2008 - 0.3.1
-----------------------

 * added wide string comparison
 * enhanced multibyte string comparison

13th March 2008 - 0.2.2
-----------------------

 * minor bug fix in definition of XTEST_TEST_POINTER_???? macros

12th March 2008 - 0.2.1
-----------------------

 * added support for pointer testing
 * enhanced string testing
 * fixed implicit link bug

24th February 2008 - 0.1.15
---------------------------

 * fixed compilation bug when exception-handling support not enabled

23rd February 2008 - 0.1.14
---------------------------

 * fix in main header for bug encountered in C compilation units
 * enhancements to test & example programs

23rd February 2008 - 0.1.13
---------------------------

 * minor bug fix for Borland compilation

22nd February 2008 - 0.1.12
---------------------------

 This is the first released version.

 All history before this day is moot!


<!-- ########################### end of file ########################### -->

