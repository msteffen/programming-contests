#!/bin/bash

# Run "test.sh" in a directory named "A" to build "A.cc" and run on "A.in" and "A.out"

prob="$(basename "${PWD}")"
tmp="$( mktemp -p . "${prob}_output_XXXXXX.txt")"
make ${prob} && ./${prob} <"${prob}.in" >"${tmp}"
pr -m ./${tmp} ${prob}.out
diff ./${tmp} ${prob}.out
rm "${tmp}"
