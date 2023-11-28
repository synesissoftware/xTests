#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build


mkdir -p $CMakePath || exit 1

cd $CMakePath

echo "Executing CMake"

cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON .. || (cd ->/dev/null ; exit 1)

echo "Executing make"

# NOTE: we do not break on fail, because, this being a unit-testing library, the scratch-tests actually fail
make && for f in $(find . -type f -name 'test.*' -perm +111 -print) ; do echo ; echo "executing $f:" ; $f ; done

cd ->/dev/null

