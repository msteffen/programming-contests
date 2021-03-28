#!/bin/bash

make a \
  && ./a <a.in >actual.out \
  && diff expected.out actual.out
