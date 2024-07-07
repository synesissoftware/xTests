#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do
    case $1 in
        --help)
            cat << EOF
xTests is a small, lightweight, portable, simple unit- and component-test framework suitable for exercising C and C++ libraries
Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
Runs all (matching) unit-test programs

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:


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

mkdir -p $CMakePath || exit 1

cd $CMakePath

echo "Executing make and then running all test programs"

status=0

if make; then

    for f in $(find $Dir -type f -exec test -x {} \; '(' -name 'test_unit*' -o -name 'test.unit.*' ')' -print) $(find $Dir -type f -exec test -x {} \; '(' -name 'test_component*' -o -name 'test.component.*' ')' -print)
    do

        echo
        echo "executing $f:"

        if $f; then

            :
        else

            status=$?

            break 1
        fi
    done
else

    status=$?
fi

cd ->/dev/null

exit $status


# ############################## end of file ############################# #

