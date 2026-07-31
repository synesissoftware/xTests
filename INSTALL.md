# xTests - Installation and Use <!-- omit in toc -->

Fundamentally, **xTests** is a classic-form C/C++ library, insofar as it has
implementation files in its **src** directory and header files in its
**include/xtests** directory. Thus, once "installed", one must simply
include **xtests/xtests.h** (or one of the utility headers), and compile-in
or link-in the implementation. There are several ways to do this:

- [CMake](#cmake)
- [Bundled](#bundled)


## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **xTests**, from
   https://github.com/synesissoftware/xTests/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/xTests/
   ```

2. Obtain the latest distribution of **STLSoft**, from
   https://github.com/synesissoftware/STLSoft/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/STLSoft/
   ```

   (**NOTE**: As of the time of writing, the **STLSoft** libraries are
   still available in separate forms - 1.9 (via
   https://github.com/synesissoftware/STLSoft-1.9), 1.10 (via
   https://github.com/synesissoftware/STLSoft-1.10), 1.11 (via
   https://github.com/synesissoftware/STLSoft) - but this will be
   rectified sometime in 2023/24. Until such time as a consolidated
   project is available - via https://github.com/synesissoftware/STLSoft -
   you are advised to prefer **1.11**.)

3. Prepare the CMake configuration, via the **prepare_cmake.sh** script,
   passing the **STLSoft** root directory obtained in step 2 with the
   `--stlsoft-root-dir` option, as in:

   ```bash
   # Assuming step-2 cloned into ~/open-source/STLSoft
   $ cd ~/open-source/xTests
   $ ./prepare_cmake.sh --stlsoft-root-dir ~/open-source/STLSoft -v
   ```

   (**Hint**: execute `$ ./prepare_cmake.sh --help` for more information.)

   If you have already installed **STLSoft** on your system and have (or can
   provide) the environment variable `STLSOFT` set to the root directory
   of your **STLSoft** installation then you can omit the
   `--stlsoft-root-dir` option, as in:

   ```bash
   $ if [ -z "${STLSOFT}" ]; then echo "STLSOFT not defined\!"; else ./prepare_cmake.sh -v; fi
   ```

   or:

   ```bash
   $ STLSOFT=~/open-source/STLSoft ./prepare_cmake.sh -v
   ```

   As of version **0.20.5**, if you have already obtained **STLSoft** and
   installed it via its **CMake** scripts then you need not specify any
   further details related to **STLSoft**, as in:

   ```bash
   $ ./prepare_cmake.sh -v
   ```

4. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` in step 3 then you do
   not need this step.)

5. As a check, execute the built test program files via the
   **build_run_all_unit_tests.sh** script, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

   (**NOTE**: because **xTests** is a unit-testing library its own tests
   are just scratch tests, and all fail _by-design_ so expect to see a
   lot of output, which is indicative of what you will see when you
   detect failure in your own tests using **xTests**.)

6. Install the library on the host, via `cmake`, as in:


   ```bash
   $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

7. Then to use the library, it is a simple matter as follows:

   1. Assuming a simplest possible program to verify the installation:

      ```cpp
      // main.cpp
      #include <xtests/xtests.h>
      #include <stdio.h>

      int main(int argc, char* argv[])
      {
         int retCode = EXIT_SUCCESS;
         int verbosity;

         XTESTS_COMMANDLINE_PARSE_VERBOSITY(argc, argv, &verbosity);

         fprintf(stderr, "verbosity=%d\n", verbosity);

         return retCode;
      }
      ```

   2. Compile your project against **xTests**:

      Due to the installation step (Step 6 above) there is no requirement
      for an explicit include directory for **xTests**:

      ```bash
      $ g++ -c -I ${STLSOFT}/include -std=c++11 main.cpp
      ```

      (**NOTE**: the need to specify the **STLSoft** include explicitly will
      be removed with a forthcoming release of the **STLSoft** libraries
      that will also do installation via **CMake**.)

   3. Link your project against **xTests**:

      Due to the installation step (Step 6 above) there is no requirement
      for an explicit library directory for **xTests**:

      ```bash
      $ g++ main.o -lxtests
      ```

   4. Test your project:

      Then you can run this with the argument `--verbosity=4` as in:

      ```bash
      $ ./a.out --verbosity=4
      verbosity=4
      ```


## Bundled

**xTests** is small and portable enough that it is commonly bundled into
other projects (for example **Pantheios**). In that case:

* ensure **STLSoft**'s **include** directory is on your project's include
  path (required for both the interface and the implementation);
* add **xTests**'s **include** directory to your project's include path;
* compile **src/xtests.core.cpp** into your build (or link a previously
  built **libxtests.core**); and
* `#include <xtests/xtests.h>` (and, optionally, **xtests/terse-api.h**
  for the shorter assertion macros).

If **shwild** is available — either installed or itself bundled — and
either `XTESTS_HAS_SHWILD` is defined or **shwild**'s headers are
included before **xtests.h**, the pattern-matching macros
`XTESTS_TEST_MULTIBYTE_STRING_MATCHES` and
`XTESTS_TEST_MULTIBYTE_STRING_DOES_NOT_MATCH` are enabled.


<!-- ########################### end of file ########################### -->

