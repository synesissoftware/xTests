#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakePath=$Dir/_build


mkdir -p $CMakePath || exit 1

cd $CMakePath





echo "Executing make and then running all test programs"

make && for f in $(find . -type f -perm +111 -print -name 'test_*' -o -name 'test.*')
do
	echo
	echo "executing $f:"
	# NOTE: we do not break on fail, because, this being a unit-testing library, the scratch-tests actually fail
	$f
done

cd ->/dev/null

