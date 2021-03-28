#!/bin/bash

if [[ "$#" -lt 1 ]]; then
  echo "Need one argument: name of binary"
  exit 1
fi

name="$1"

./"${name}" <expected.in | tee actual.out \
  && diff expected.out actual.out
