# **xTests** Changes <!-- omit in toc -->


## 0.26.4 (alpha 3) - 30th August 2025

* CTest compatibility;
* GitHub Actions;


## 0.26.4 (alpha 2) - 30th June 2025

* Allowing comparisons between integer values/variables of arbitrary type and sign;
* C++-98 compatibility;


## 0.26.4 (alpha 1) - 6th May 2025

* MinGW compatibility;
* Various CMake scripts canonicalisation;


## 0.26.3 - 6th May 2025

* Fixed defect in format specifiers for end-case summary;


## 0.26.2 - 3rd May 2025

* Compatibility with older compilers (incl. Visual C++ 14);
* Compatibility with older operating systems (incl. Windows Vista);


## 0.26.2-alpha1 - 26th April 2025

* N-len string comparisons now works regardless of integral type of length argument;


## 0.26.1-alpha1 - 23rd April 2025

* Fix wrong conditionality on inclusion of **stlsoft/conversion/sas_to_string.hpp**;


## 0.26.0 - 23rd April 2025

* Improved compatibility to types that provide shims `stlsoft::c_str_data_a()` and `stlsoft::c_str_len_a()`, rather than `stlsoft::c_str_ptr_a()`;
* Fixed inconsistency in handling of verbosity levels (esp. `XTESTS_VERBOSITY_FIRST_CASE_SUMMARY_ON_ERROR`);
* Visual C++ compatibility;
* Further application of terse api in example and test programs;
* Various tidyings;
* Improved scope and consistency in example and test programs;


## 0.26.0-beta3 - 23rd February 2025

* added support (including coloured output) for (in)equality testing of UDTs;
* `temp_directory` now finds and deletes sockets (in addition to files);
* fixed defect (when on UNIX) in `temp_file`;
* now ensures that does not emit ANSI colour sequences when running on Windows on an old terminal that does not support them;


## 0.26.0-beta1 - 31st December 2024

* now uses `stlsoft::integral_traits<>` for integer test macros (in C++) to allow for custom integral types to be tested;
* `temp_file` now takes a `hint_dir` parameter to allow specification of directory for (temporary) file;
* added missing test macros `XTESTS_TEST_FLOATINGPOINT_GREATER()`, `XTESTS_TEST_FLOATINGPOINT_GREATER_OR_EQUAL()`, `XTESTS_TEST_FLOATINGPOINT_LESS()`, `XTESTS_TEST_FLOATINGPOINT_LESS_OR_EQUAL()`;
* added macro `XTESTS_COMMANDLINE_PARSE_HELP_OR_VERBOSITY()`, which allows for a unified command-line parsing in test programs;
* added terse forms of macros, available by including **xtests/terse-api.h**;
* `XTESTS_COMMANDLINE_PARSE_VERBOSITY()` now also recognises, if the command-line argument `"--verbosity= . . ."` is not found, the enviroment variables `"XTESTS_VERBOSITY"` and `"TEST_VERBOSITY"`;
* added test programs **test.scratch.all_failure_messages**, **test.scratch.basics2**, **test.scratch.custom_integral_types**;
* substantial internal refactoring;
* minor tidying to CMake facilities;
* minor improvements to examples;
* minor improvements to project boilerplate files;
* updated **STLSoft** constructs, incl. macros;


## 0.25.4 - 18th November 2024

* added CMake MSVC MT support;


## 0.25.3 - 25th October 2024

* Fix to colour output at high verbosity levels;


## 0.25.2 - 22nd October 2024

* Added and applied CMake functions for examples and test programs;
* Some refactoring in main header **include/xtests/xtests.h**;
* VC++ 19+ warnings;
* Fixed vulnerability in length-limited string comparisons;
* Renamed project **test.scratch.string_slices.c** => **test.unit.string_slices.c**;


## 0.25.0 - 20th October 2024

* no changes;


## 0.24.0-alpha7 - 18th October 2024

* Coloured output now bold;
* Minor fixes to CMake build scripts;


## 0.24.0-alpha6 - 17th October 2024

* Expanded shwild integration (including CMake detection);
* Significant enhancement and refactoring around use of CMake;
* Added coloured output for test-case / runner names;
* General tidying;
* Compatibility with legacy versions of Visual C++;


## 0.24.0-alpha5 - 15th October 2024

* Refactored common aspects of example and test `main()` functions;
* Language/compiler compatibility fixes, including **MinGW-W64** compatibility;
* CMake build scripts enhancements;


## 0.24.0-alpha4 - 5th August 2024

* compatibility with STLSoft 1.11.1-alpha13 or later;


## 0.24.0-alpha3 - 4th August 2024

* minimal coloured console output;


## 0.24.0-alpha2 - 4th August 2024

* fixed VC++ / CMake configuration;


## 0.24.0-alpha1 - 3rd August 2024

* `XTESTS_TEST_INTEGER_EQUAL_EXACT()`, `XTESTS_TEST_INTEGER_NOT_EQUAL()`, `XTESTS_TEST_INTEGER_GREATER()`, `XTESTS_TEST_INTEGER_GREATER_OR_EQUAL()`, `XTESTS_TEST_INTEGER_LESS()`, `XTESTS_TEST_INTEGER_LESS_OR_EQUAL()` are all implemented in terms of `_Generic` (where supported) in C compilation units in order to be able to report the expected and actual values upon failure (as is done in C++ compilation units);
* general tidying;


## 0.23.1 - 14th July 2024

* Various CMake standardisations and simplifications;


## 0.22.1 - 9th July 2024

* Visual C++ 17 (2022) compatibility;
* CMake Windows compatibility;
* Small improvements for `temp_directory` and `temp_file`;
* now depends on STLSoft 1.11;


## 0.21.4 - 28th January 2024

* Clang 14+ compatibility;
* CMake scripts improvements;
* now depends on STLSoft 1.10.6;


## 0.21.3 - 28th January 2024

* Clang 14+ compatibility;


## 0.21.2 - 28th January 2024

* CMake support minor improvements;


## 0.21.1 - 11th January 2024

* fixed include of **STLSoft** header-file in presence of **shwild**;


## 0.21.0 - 2nd January 2024

* added `XTESTS_TEST_MULTIBYTE_STRING_MATCHES()` that, in the presence of the shwild library, provides pattern matching;


## 0.20.5 - 2nd January 2024

* completed CMake support, with flexible mechanism to select STLSoft dependency;


## 0.20.4 - 14th December 2023

* added CMake support;
* added Doxygen;
* added makefile(s) for GCC generic version;
* fix to xtests::cpp::util::temp_directory;
* fix defect in example;


## 0.20.3 - 13th December 2020

* fixed xtests::cpp::util::temp_directory dtor semantics for EmptyOnClose and RemoveOnClose;
* compatibility with Visual Studio 2019 (16.8.2);


## 0.20.2 - 30th July 2020

* added implicit-link support for VC++ 15 and VC++16;
* added makefile(s) for VC++ 15 and VC++16;
* various makefile improvements;
* GCC 8 compatibility;


## 0.20.1 - 12th October 2019

* added xtests::cpp::util::temp_file ctor that takes a callback function that is used to provide initial contents of the file;
* added VC++ 10 project and solution files;
* fixed range comparison tests;
* fixing up VC++-specific non-standard token-pasting;
* removed dependency on/discrimination for STLSoft 1.10 delta (though now works perfectly well with STLSoft 1.10 proper);


## 0.18.9 - 22nd July 2016

* fix to 0.18.8 release;
* NOTE: requires STLSoft 1.9.128;
* bundles shwild 0.10.1;


## 0.18.8 - 22nd July 2016

* changed no-throw declaration from stlsoft_throw_0() to STLSOFT_NOEXCEPT;
* support for Borland C++ 6.2x;
* added makefiles for Borland 5.82, 6.1x, 6.2x;
* significant refactoring of structure of makefiles;
* strict C-compilation compatibility;
* NOTE: requires STLSoft 1.9.128;
* bundles shwild 0.10.1;


## 0.18.4 - 7th October 2015

* added temp_directory and temp_file utility classes;
* now supports test cases that have void* param (for setup param);
* support for cdecl and stdcall test cases;
* support for Clang;
* support for VC++ 11;
* support for VC++ 12;
* support for VC++ 14;
* NOTE: requires STLSoft 1.9.121;
* bundles shwild 0.10.1;


## 0.17.1 - 1st March 2013

* added XTESTS_TEST_MULTIBYTE_STRING_SLICE_EQUAL() / XTESTS_TEST_WIDE_STRING_SLICE_EQUAL() macros for testing string slices;
* expected/unexpected exception event messages now include file+line;
* refactoring of implementation;
* tidying up of makefile gripes;
* NOTE: requires STLSoft 1.9.117;
* bundles shwild 0.9.18;


## 0.16.6 - 16th February 2013

* improved handling of booleans;
* VC++ 11 compatibility;
* NOTE: requires STLSoft 1.9.115;
* bundles shwild 0.9.18;


## 0.16.3 - 2nd December 2011

* workaround for strange behaviour (probably code-generation fault) in GCC 4.2 on Mac OS-X 10.7;
* NOTE: requires STLSoft 1.9.111;


## 0.16.2 - 13th August 2010

* various minor modifications for compatibility with recent versions of GCC 4.X;
* NOTE: requires STLSoft 1.9.111;


## 0.16.1 - 13th August 2010

* added function pointer testing, via XTESTS_TEST_FUNCTION_POINTER_EQUAL() and XTESTS_TEST_FUNCTION_POINTER_NOT_EQUAL();
* added implicit-link support for VC++ 10;
* fixes for 64-bit compatibility;
* NOTE: requires STLSoft 1.9.100;


## 0.15.2 - 21st June 2010

* minimal compatibility enhancements;
* NOTE: requires STLSoft 1.9.97;


## 0.15.1 - 4th April 2010

* added in-range testing, via XTESTS_TEST_INTEGER_EQUAL_ANY_IN_RANGE() and XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE();
* added XTESTS_ARRAY_END_POST;
* VC6 compatibility for signed __int16, unsigned __int16, & signed __int1632;
* NOTE: requires STLSoft 1.9.97;


## 0.14.4 - 20th January 2010

* workaround for erroneous Borland compilation error;
* NOTE: requires STLSoft 1.9.89;


## 0.14.3 - 19th January 2010

* removed erroneous debug information in UNIXem release builds;
* NOTE: requires STLSoft 1.9.89;


## 0.14.2 - 11th August 2009

* workaround for minor warning;
* NOTE: requires STLSoft 1.9.87;


## 0.14.1 - 13th July 2009

* added ability to display a summary of only the first case to fail;
* renamed and add to enumerators of xtests_verbosity_t;
* NOTE: requires STLSoft 1.9.85;


## 0.13.3 - 8th July 2009

* workaround for Intel C/C++ compiler defect;
* NOTE: requires STLSoft 1.9.85;


## 0.13.2 - 16th June 2009

* added XTESTS_REQUIRE(), to allow testing to stop after test failure, to avoid contract violations;
* NOTE: requires STLSoft 1.9.85;


## 0.12.1 - 1st May 2009

* added XTESTS_FLOATINGPOINT_FACTOR_SCOPE scoping class;
* added XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_EXACT, XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL_APPROX, and XTESTS_TEST_FLOATINGPOINT_NOT_EQUAL test macros;
* NOTE: requires STLSoft 1.9.78;


## 0.11.5 - 25th April 2009

* fixed defect in XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS();
* added implicit link support for Intel C/C++ 10 & 11;
* allows stream to be NULL, and assumes stdout if no reporter specified;
* NOTE: requires STLSoft 1.9.77;


## 0.11.4 - 17th April 2009

* changes to defn of exceptions & RTTI, for conformance to other library (e.g. Pantheios) makefile templates;
* now allows compilation absent RTTI;
* NOTE: now requires STLSoft 1.9.77;


## 0.11.3 - 15th April 2009

* fixed defect in internal snprintf() abstraction, which faults on Linux;
* NOTE: now requires STLSoft 1.9.77;


## 0.11.2 - 9th March 2009

* fixed defect in core, whereby snprintf() overrun led to fault;
* NOTE: now requires STLSoft 1.9.76;


## 0.11.1 - 6th March 2009

* added setup / teardown functionality;
* NOTE: now requires STLSoft 1.9.75;


## 0.10.4 - 13th February 2009

* added support for Borland 5.9.x and 6.1.x;
* added workaround for over-eager warnings in GCC 4.3;
* NOTE: now requires STLSoft 1.9.74;


## 0.10.3 - 1st February 2009

* added ability to suppress reporting of empty test cases;
* added XTESTS_START_RUNNER_WITH_FLAGS();
* now uses Windows debugging support when emulating UNIX on Windows;


## 0.10.2 - 20th January 2009

* added facilities for length-limiting string comparison;
* added missing macros for case-insensitive string inequality;
* added full support for custom reporter functionality;
* corrected defect whereby s/uint64 integer failures were not counted towards the total;
* fixed various minor defects;


## 0.9.3 - 29th December 2008

* added XTESTS_TEST_ENUM_TRUE() and XTESTS_TEST_ENUM_FALSE();


## 0.9.2 - 18th November 2008

* added XTESTS_TEST_BOOLEAN_TRUE() and XTESTS_TEST_BOOLEAN_FALSE();
* avoid precipitating warnings about unused return values;


## 0.9.1 - 25th October 2008

* added xtestsComparisonApproxNotEqual comparison enumerator, and adjusted all comparison operations accordingly;
* added xtests_testMultibyteStringContains() and xtests_testWideStringContains(), and all corresponding test macros;
* cleared up some wrong (but benign) code exercised when compiling with exception-support switched off;


## 0.8.7 - 25th October 2008

* fixed defective != comparison of signed & unsigned 64-bit integers;


## 0.8.6 - 19th October 2008

* added more integer specialisations of xtests_failure_reporter<>;


## 0.8.5 - 23rd August 2008

* added call to XTESTS_TEST_PASSED() when an expected exception is received;
* added more integer specialisations of xtests_failure_reporter<>;
* fixed a defect in the approximate comparison of negative floating-point numbers;


## 0.8.4 - 10th August 2008

* fixed a bug in the reporting mechanism for boolean enforcement failures;


## 0.8.2 - 16th June 2008

* elimination of compiler warning on VC++ 8+;


## 0.8.1 - 5th June 2008

* added ability to specify output stream (FILE*) when starting a test runner;


## 0.7.4 - 4th June 2008

* addition of missing makefiles in the distro;
* bundles shwild 0.9.18;


## 0.7.3 - 20th May 2008

* minor weakening of string comparison;
* bundles shwild 0.9.17;


## 0.7.2 - 11th May 2008

* minor compatibility enhancements;


## 0.7.1 - 4th May 2008

* added Win64-compatibility;


## 0.6.5 - 29th April 2008

* added compatibity with heterogeneous string types to xtests_writeFailMessage();


## 0.6.4 - 25th April 2008

* fix for Sun Pro compatibility;


## 0.6.3 - 22nd April 2008

* fix for Borland compilation error with widestring macros;


## 0.6.2 - 21st April 2008

* added makefiles for VC9, GCC 4.1 and GCC 4.2;
* altered library names to use UNIX libXXXX naming convention in UNIX builds;


## 0.6.1 - 20th April 2008

* added evaluation of heterogeneous string types, using shim-based type-tunneling;


## 0.5.2 - 19th April 2008

* added implicit link support for VC++ 9;


## 0.5.1 - 16th April 2008

* added explicit support for character tests;
* fixed bug in formatting of != tests;


## 0.4.1 - 13th April 2008

* added explicit support for boolean tests;


## 0.3.3 - 18th March 2008

* fix for wide string support;


## 0.3.2 - 15th March 2008

* minor bug fix to prevent confusion about threading models on some UNIX operating systems;


## 0.3.1 - 15th March 2008

* added wide string comparison;
* enhanced multibyte string comparison;


## 0.2.2 - 13th March 2008

* minor bug fix in definition of XTEST_TEST_POINTER_???? macros;


## 0.2.1 - 12th March 2008

* added support for pointer testing;
* enhanced string testing;
* fixed implicit link bug;


## 0.1.15 - 24th February 2008

* fixed compilation bug when exception-handling support not enabled;


## 0.1.14 - 23rd February 2008

* fix in main header for bug encountered in C compilation units;
* enhancements to test & example programs;


## 0.1.13 - 23rd February 2008

* minor bug fix for Borland compilation;


## 0.1.12 - 22nd February 2008

* First public release;


<!-- ########################### end of file ########################### -->
