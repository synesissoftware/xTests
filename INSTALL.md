# xTests - Installation and Use

Fundamentally, **xTests** is a classic-form C/C++ library, insofar as it has
implementation files in its **src** directory and header files in its
**include/xtests** directory. Thus, once "installed", one must simply
include **xtests/xtests.h** (or one of the utility headers), and compile-in
or link-in the implementation. There are several ways to do this:

* [CMake](#cmake) - recommended
* [Custom makefile (as peer project)](#custom-makefile-as-peer-project) - previously recommended approach
* [Bundled](#bundled)
* [Custom makefile parameters](#custom-makefile-parameters)


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
   https://github.com/synesissoftware/STLSoft-1.10/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/STLSoft-1.10/
   ```

   (**NOTE**: As of the time of writing, the **STLSoft** libraries are
   still available in separate forms - 1.9 (via
   https://github.com/synesissoftware/STLSoft-1.9), (1.10 via
   https://github.com/synesissoftware/STLSoft-1.10) - but this will be
   rectified sometime in 2023/24. Until such time as a consolidated
   project is available - via https://github.com/synesissoftware/STLSoft -
   you are advised to prefer **1.10**.)

3. Prepare the CMake configuration, via the **prepare_cmake.sh** script,
   passing the **STLSoft** root directory obtained in step 2 with the
   `--stlsoft-root-dir` option, as in:

   ```bash
   # Assuming step-2 cloned into ~/open-source/STLSoft-1.10
   $ ./prepare_cmake.sh --stlsoft-root-dir ~/open-source/STLSoft-1.10 -v
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
   $ STLSOFT=~/open-source/STLSoft-1.10 ./prepare_cmake.sh -v
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
   $ sudo cmake --install ./_build --config Release
   ```


## Custom makefile (as peer project)

Before support for **CMake** was provided, the recommended approach was to
use one of the custom makefiles provided with the project, as follows:

1. Obtain the latest distribution of **xTests**, from
   https://github.com/synesissoftware/xTests/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/xTests/
   ```

2. Obtain the latest distribution of **STLSoft**, from
   https://github.com/synesissoftware/STLSoft-1.10/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/STLSoft-1.10/
   ```

   (**NOTE**: As of the time of writing, the **STLSoft** libraries are
   still available in separate forms - 1.9 (via
   https://github.com/synesissoftware/STLSoft-1.9), (1.10 via
   https://github.com/synesissoftware/STLSoft-1.10) - but this will be
   rectified sometime in 2023/24. Until such time as a consolidated
   project is available - via https://github.com/synesissoftware/STLSoft -
   you are advised to prefer **1.10**.)

3. Determine the custom makefile appropriate for your compiler. For example,
   if running on **UNIX** and using **GCC v4.2.1** then the requisite
   **makefile** will reside in **build/gcc42.unix**;

   ```bash
   $ ls -al build/gcc42.unix/makefile
   ```

4. Execute a test build, passing the target `clean`. For this to succeed the
   environment variable `STLSOFT` must exist or be provided, hence:

   ```bash
   # from within build/gcc42.unix
   $ if [ -z "${STLSOFT}" ]; then echo "STLSOFT not defined\!"; else make clean; fi
   ```

   or:

   ```bash
   # from within build/gcc42.unix
   $ STLSOFT=~/open-source/STLSoft-1.10 make clean
   ```

   In either case, you should see output such as the following:

   ```
   cleaning Core libraries ...
   cleaning shwild libraries ...
   cleaning Test:Component programs ...
   cleaning Test:Scratch programs ...
   cleaning Test:Unit programs ...
   ```

5. Build the **xTests** library configurations, using the target `build`:

   ```bash
   # from within build/gcc42.unix
   $ STLSOFT=~/open-source/STLSoft-1.10 make build
   ```

   or just:

   ```bash
   # from within build/gcc42.unix
   $ STLSOFT=~/open-source/STLSoft-1.10 make
   ```

6. Then to use the library, it was customary practice to make available the
   **xTests** header files and built files as follows:

   1. make a link to the appropriate archive (aka static-library) file.
      Given the above main steps, examining the **lib** directory:

      ```bash
      $ ls -al lib
      ```

      should show a bunch of files, including:

      ```
      . . .
      -rw-r--r--   1 mwan  staff   110K 30 Nov 12:24 libxtests.0.core.gcc42.a
      -rw-r--r--   1 mwan  staff   262K 30 Nov 12:24 libxtests.0.core.gcc42.debug.a
      -rw-r--r--   1 mwan  staff   110K 30 Nov 12:24 libxtests.0.core.gcc42.mt.a
      -rw-r--r--   1 mwan  staff   262K 30 Nov 12:24 libxtests.0.core.gcc42.mt.debug.a
      ```

      The best choice is `libxtests.0.core.gcc42.mt.a`, which is the archive
      for Release configuration and compiled with `_REENTRANT` to be
      suitable for multithreaded programs. So, all we need to do is
      designate this as the "default" library, via:

      ```bash
      $ cp lib/libxtests.0.core.gcc42.mt.a lib/libxtests.a
      ```

   2. create an environment variable `XTESTS_C_ROOT` with the value of the
      root directory of the **xTests** project, as in:

      ```bash
      $ export XTESTS_C_ROOT=~/open-source/xTests
      ```

   3. compile and link your project against **xTests** via the environment
      variable `XTESTS_C_ROOT` (and the environment variable `STLSOFT`
      discussed above).

      Assuming you have the following (trivial) implementation file, called
      **main.cpp**:

      ```cpp
      // main.cpp
      #include <xtests/xtests.h>
      #include <stdio.h>

      int main(int argc, char* argv[])
      {
         int retCode = EXIT_SUCCESS;
         int verbosity;

         XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

         fprintf(stderr, "verbosity=%d\n", verbosity);

         return 0;
      }
      ```

      This can be compiled against the environment variable as in:

      ```bash
      $ g++ -I ${XTESTS_C_ROOT}/include -I ${STLSOFT}/include -std=c++11 main.cpp
      ```

      And can be linked against **libxtests.a** (step 6.1) as in:

      ```bash
      $ g++ main.o -L ${XTESTS_C_ROOT}/lib -lxtests
      ```

      Then you can run this with the argument `--verbosity=4` as in:

      ```bash
      $ ./a.out --verbosity=4
      verbosity=4
      ```







## Bundled

Some other open-source libraries require **xTests** for their unit-testing,
and so the source files in **src** and **include/xtests** (including
sub-directory structure and content) are bundled into their archive (.zip)
distributions as follows:

   * contents of `src` bundled into the library's `src/shwild` directory;
   * contents of `include/xtests` bundled into the library's
     `include/xtests` directory;

An extract from one of the [**recls**](https://github.com/synesissoftware/recls) library's makefiles illustrates:

```makefile
########################################
# directories

. . .

XTESTS_INCLUDE_DIR      =   $(PROJ_BASE_DIR)/include
XTESTS_SRC_DIR          =   $(PROJ_SRC_DIR)/xtests
XTESTS_PROJ_INCLUDE     =   -I$(XTESTS_INCLUDE_DIR)


. . .

# CC includes

CC_INCLUDES_BASE=\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_1_10_INCLUDE)\
 $(STLSOFT_PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(ENV_INCLUDES)\
 \

. . .

# CPPC includes

CPPC_INCLUDES_BASE=\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_1_10_INCLUDE)\
 $(STLSOFT_PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(ENV_INCLUDES)\
 \



. . .


########################################
# libraries

# recls
LIB_CORE_MT_D           =   $(PROJ_LIB_DIR)/lib$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.debug.a
LIB_CORE_MT_R           =   $(PROJ_LIB_DIR)/lib$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.a
LIB_CORE_ST_D           =   $(PROJ_LIB_DIR)/lib$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).debug.a
LIB_CORE_ST_R           =   $(PROJ_LIB_DIR)/lib$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).a

. . .

# xTests
LIB_XTESTS_MT_D         =   $(PROJ_LIB_DIR)/lib$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.debug.a
LIB_XTESTS_MT_R         =   $(PROJ_LIB_DIR)/lib$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.a
LIB_XTESTS_ST_D         =   $(PROJ_LIB_DIR)/lib$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).debug.a
LIB_XTESTS_ST_R         =   $(PROJ_LIB_DIR)/lib$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).a


. . .


########################################
# xTests library - 'xtests.X.recls.core.a'

$(LIB_XTESTS_MT_D): $(OBJ_XTESTS_MT_D) $(PROJ_MAKEFILE_NAME)
    @-mkdir -p $(PROJ_LIB_DIR)
    $(AR) $(AR_ARGS) rcs $@ $(OBJ_XTESTS_MT_D)

$(OBJ_xts_core_MT_D): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
    $(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_XTESTS_INCLUDES_MT_D) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_MT_R): $(OBJ_XTESTS_MT_R) $(PROJ_MAKEFILE_NAME)
    @-mkdir -p $(PROJ_LIB_DIR)
    $(AR) $(AR_ARGS) rcs $@ $(OBJ_XTESTS_MT_R)

$(OBJ_xts_core_MT_R): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
    $(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_XTESTS_INCLUDES_MT_R) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_ST_D): $(OBJ_XTESTS_ST_D) $(PROJ_MAKEFILE_NAME)
    @-mkdir -p $(PROJ_LIB_DIR)
    $(AR) $(AR_ARGS) rcs $@ $(OBJ_XTESTS_ST_D)

$(OBJ_xts_core_ST_D): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
    $(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_XTESTS_INCLUDES_ST_D) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_ST_R): $(OBJ_XTESTS_ST_R) $(PROJ_MAKEFILE_NAME)
    @-mkdir -p $(PROJ_LIB_DIR)
    $(AR) $(AR_ARGS) rcs $@ $(OBJ_XTESTS_ST_R)

$(OBJ_xts_core_ST_R): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
    $(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_XTESTS_INCLUDES_ST_R) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

```

This is an advanced technique and not recommended **xTests** users of - in
no small way because it's a big hassle - so is not elaborated further here.
Contact the project team for further details.


## Custom makefile parameters

The following assumes you have read and understood all of the
[Custom makefile (as peer project)](#custom-makefile-as-peer-project) and
[Bundled](#bundled) sections.

As described in the [Bundled](#bundled) section, some other open-source
projects depend on **xTests** in a manner that assumes bundling. If,
however, you are using such a project directly (i.e. cloning from its
repository, rather than unpacking an archive) it will not contain any
bundled **xTests** (or other) files. In this case, you can use custom
makefile parameters.

Let's look more deeply at the **recls** makefile shown in the earlier
section:

```makefile
########################################
# directories

. . .

XTESTS_PROJ_INCLUDE     =
ifdef RECLS_XTESTS_BASE_DIR
XTESTS_INCLUDE_DIR      =   $(RECLS_XTESTS_BASE_DIR)/include
XTESTS_SRC_DIR          =   $(RECLS_XTESTS_BASE_DIR)/src
XTESTS_PROJ_INCLUDE     =   -I$(XTESTS_INCLUDE_DIR)
else
XTESTS_INCLUDE_DIR      =   $(PROJ_BASE_DIR)/include
XTESTS_SRC_DIR          =   $(PROJ_SRC_DIR)/xtests
endif # !RECLS_XTESTS_BASE_DIR


. . .

```

In the absence of a definition of the variable `RECLS_XTESTS_BASE_DIR` the
makefile assumes that **xTests** headers are under **include/xtests** and
implementation files are under **src/xtests**. However, when
`RECLS_XTESTS_BASE_DIR` is defined, it is expected to contain the root
directory of an **xTests** clone, in which its headers are under
 **include/xtests** and its implementation files are under **src**.

Hence, to build, say, **recls**, using this form, can be done as follows:

1. Clone **recls**:

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/recls/
   ```

2. Set up `STLSOFT` environment variable:

   ```bash
   $ export STLSOFT=~/open-source/STLSoft-1.10
   ```

3. Invoke **recls** build using custom makefile parameter
   `RECLS_XTESTS_BASE_DIR`:

   ```bash
   # from within ~/open-source/recls/build/gcc42.unix
   $ RECLS_XTESTS_BASE_DIR=~/open-source/xTests make
   ```

Once again, this is an advanced technique and quite messy, so work is
currently underway to enable **xTests** (and other related open-source
projects - see [README.md](./README.md)) to obtain their **CMAke**
dependencies automatically.