#!/usr/bin/python3
from sys import stdin, stdout
from itertools import *

ZZZ = int(stdin.readline().strip())
for Z in range(ZZZ):
    deg = int(stdin.readline().strip())
    for i in range(deg+1):
        stdin.readline()
    stdout.write("Case #{}: ".format(Z+1))
    if deg%2 == 1:
        stdout.write("1\n0.0\n")
    else:
        stdout.write("0\n")

