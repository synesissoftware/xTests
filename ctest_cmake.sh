#! /bin/bash

ScriptPath=$0
Dir=$(cd "$(dirname "$ScriptPath")"; pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
[[ -n "$MSYSTEM" ]] && DefaultMakeCmd=mingw32-make.exe || DefaultMakeCmd=make
MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-$DefaultMakeCmd}}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")

CTestVerbose=
RunMake=1


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --no-make|-M)

      RunMake=0
      ;;
    --verbose|-V)

      CTestVerbose=--verbose
      ;;
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Runs CMake's CTest test program(s)

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -M
    --no-make
        does not execute make before running tests

    -V
    --verbose
        verbose test output, for passing tests as well as failing ones;
        output from failing tests is shown regardless


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

  echo "Executing build of ${ProjectName} (via command \`$MakeCmd\`) and then running automated tests"

  mkdir -p "$CMakeDir" || exit 1

  cd "$CMakeDir"

  $MakeCmd
  status=$?

  cd ->/dev/null
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"

    exit 1
  fi
fi

if [ $status -eq 0 ]; then

  echo "Running ${ProjectName} CMake tests"

  ctest --test-dir "$CMakeDir" --output-on-failure $CTestVerbose
  status=$?
fi

exit $status


# ############################## end of file ############################# #

