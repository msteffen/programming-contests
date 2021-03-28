#!/bin/bash

name="$(basename $(ls | grep cc$) .cc)"

make "${name}" \
  && ./"${name}" <${name}.in >actual.out \
  && diff expected.out actual.out
