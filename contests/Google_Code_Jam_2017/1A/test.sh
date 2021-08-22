#!/bin/bash

if [[ "$#" -lt 1 ]]; then
  echo "Need one argument: name of binary"
  exit 1
fi

name="$1"

make "${name}" \
  && ./"${name}" <${name}.in >actual.out \
  && diff expected.out actual.out
