#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
[[ -n "$MSYSTEM" ]] && DefaultMakeCmd=mingw32-make.exe || DefaultMakeCmd=make
MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-$DefaultMakeCmd}}

ListOnly=0
RunMake=1
Verbosity=${XTESTS_VERBOSITY:-${TEST_VERBOSITY:-3}}


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --list-only|-l)

      ListOnly=1
      ;;
    --no-make|-M)

      RunMake=0
      ;;
    --verbosity)

      shift
      Verbosity=$1
      ;;
    --help)

      cat << EOF
xTests is a small, lightweight, portable, simple unit- and component-test framework suitable for exercising C and C++ libraries
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
Runs all (matching) scratch-test programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -l
    --list-only
        lists the target programs but does not execute them

    -M
    --no-make
        does not execute CMake and make before running tests

    --verbosity <verbosity>
        specifies an explicit verbosity for the unit-test(s)


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

status=0

if [ $RunMake -ne 0 ]; then

  if [ $ListOnly -eq 0 ]; then

    echo "Executing build (via command \`$MakeCmd\`) and then running all scratch test programs"

    mkdir -p $CMakeDir || exit 1

    cd $CMakeDir

    $MakeCmd
    status=$?

    cd ->/dev/null
  fi
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"
  fi
fi

if [ $status -eq 0 ]; then

  if [ $ListOnly -ne 0 ]; then

    echo "Listing all scratch (and performance) test programs"
  else

    echo "Running all scratch (and performance) test programs"
  fi

  for f in $(find $CMakeDir -type f '(' -name 'test_scratch*' -o -name 'test.scratch.*' -o -name 'test_performance*' -o -name 'test.performance.*' ')' -exec test -x {} \; -print)
  do

    if [ $ListOnly -ne 0 ]; then

      echo "would execute $f:"

      continue
    fi

    if [ $Verbosity -ge 3 ]; then

      echo
    fi
    if [ $Verbosity -ge 2 ]; then

      echo "executing $f:"
    fi

    # NOTE: we do not break on fail, because, this being a unit-testing library, the scratch-tests actually fail
    $f
  done
fi

exit $status


# ############################## end of file ############################# #

