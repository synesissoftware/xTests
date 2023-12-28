# xTests

## Table of Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Components](#components)
4. [Examples](#examples)
5. [Project Information](#project-information)

## Introduction

**xTests** is a testing library for C and C++. Specifically, it is a small,
lightweight, portable, simple unit- and component-test framework suitable
for exercising C and C++ libraries. Its primary design features are:

- **Portability**. It relies on no platform-specific or compiler-specific
constructs. The only library it relies on is the 100% header-only,
open-source **STLSoft** library. It works with a large number of C/C++
compilers. Importantly, it is sufficiently simple and lightweight that it
is bundled with several other open-source libraries, and is an integral
part of their automated unit- and component-testing in their builds;
- **Simplicity**. It doesn't require pre-processing of your source code by
scripting languages. It doesn't use macros to create secret classes that
use Schwarz counters to register test cases. It relies on you to simply
code what you want, and nothing that you don't want.

xTests is completely free and includes source released under a BSD-style
license.

## Installation

Detailed instructions - via **CMake**, via bundling, via custom makefile
parameters - are provided in the accompanying [INSTALL.md](./INSTALL.md)
file.

## Components

T.B.C.

## Examples

Examples are provided in the ```examples``` directory, along with a markdown description for each.

## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/xTests "GitHub Page")

### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/xTests.

If you'd like to help out with the project, please contact us via the
project website on SourceForge: http://sourceforge.net/projects/xtests -
you'll be very welcome!

### Dependencies

#### STLSoft

**xTests** depends on the STLSoft libraries, version 1.9.134 (or later). Version 1.10.1 beta19 (or later) is recommended.

* [STLSoft 1.9](http://github.com/synesissoftware/STLSoft-1.9/)
* [STLSoft 1.10](http://github.com/synesissoftware/STLSoft-1.10/) (Recommended)

### Related projects

Projects in which **xTests** is used for testing include:

* [**b64**](https://github.com/synesissoftware/b64)
* [**cstring**](https://github.com/synesissoftware/cstring)
* [**FastFormat**](https://github.com/synesissoftware/FastFormat)
* [**libpath**](https://github.com/synesissoftware/libpath)
* [**Pantheios**](https://github.com/synesissoftware/Pantheios)
* [**recls**](https://github.com/synesissoftware/recls)
* [**shwild**](https://github.com/synesissoftware/shwild)
* [**UNIXem**](https://github.com/synesissoftware/UNIXem)

### License

**xTests** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.

