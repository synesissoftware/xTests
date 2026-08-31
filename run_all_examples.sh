#! /bin/bash

ScriptPath=$0
Dir=$(cd "$(dirname "$ScriptPath")"; pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
[[ -n "$MSYSTEM" ]] && DefaultMakeCmd=mingw32-make.exe || DefaultMakeCmd=make
MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-$DefaultMakeCmd}}
ProjectNameFile="$Dir/.sis/project_name.txt"
ProjectName=$(tr -d '[:space:]' < "$ProjectNameFile")

ListOnly=0
RunMake=1


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
    --help)

      [ -f "$Dir/.sis/script_info_lines.txt" ] && cat "$Dir/.sis/script_info_lines.txt"
      cat << EOF
Runs all example programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -l
    --list-only
        lists the target programs but does not execute them

    -M
    --no-make
        does not execute make before running examples


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

    echo "Executing build of ${ProjectName} (via command \`$MakeCmd\`) and then running all example programs"

    mkdir -p "$CMakeDir" || exit 1

    cd "$CMakeDir"

    $MakeCmd
    status=$?

    cd ->/dev/null
  fi
else

  if [ ! -d "$CMakeDir" ] || [ ! -f "$CMakeDir/CMakeCache.txt" ] || [ ! -d "$CMakeDir/CMakeFiles" ]; then

    >&2 echo "$ScriptPath: cannot run in '--no-make' mode without a previous successful build step"

    exit 1
  fi
fi

if [ $status -eq 0 ]; then

  if [ $ListOnly -ne 0 ]; then

    echo "Listing all ${ProjectName} example programs"
  else

    echo "Running all ${ProjectName} example programs"
  fi

  # NUL-delimited, so that a path containing whitespace is one program and
  # not several
  NumPrograms=0

  while IFS= read -r -d '' f; do

    NumPrograms=$((NumPrograms + 1))

    if [ $ListOnly -ne 0 ]; then

      echo "would execute $f:"

      continue
    fi

    echo
    echo "executing $f:"

    # NOTE: we do not break on fail, because, this being a unit-testing
    # library, several examples exist precisely to demonstrate failure
    # reporting and so exit non-zero by design
    "$f"
  done < <(find "$CMakeDir/examples" -type f -exec test -x {} \; -print0 | sort -z)

  # discovering nothing is a failure, not a success: it is how C1 stayed
  # invisible, a whole CI matrix reporting green while running nothing
  if [ $NumPrograms -eq 0 ]; then

    >&2 echo "$ScriptPath: found no example programs under '$CMakeDir/examples'"

    exit 1
  fi
fi

exit $status


# ############################## end of file ############################# #

