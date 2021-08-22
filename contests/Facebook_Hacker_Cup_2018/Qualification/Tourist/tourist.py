#!/usr/bin/python3
from sys import stdin, stdout
from itertools import *

ZZZ = int(stdin.readline().strip())
for Z in range(ZZZ):
    N, K, V = stdin.readline().strip().split()
    N, K = map(int, (N, K))
    # Read in attractions
    As = []
    for i in range(N):
        As.append(stdin.readline().strip())
    i = 0
    for c in V:
        i = (i*10)%N
        i += (K*(ord(c)-ord('0')))%N
        i %= N
    i -= K
    i %= N
    # Gather activities for trip #V
    Vs = []
    for x in range(K):
        Vs.append(As[i])
        i+=1
        i%=N
    stdout.write("Case #{}:".format(Z+1))
    for x in sorted(Vs, key=As.index):
        stdout.write(" {}".format(x))
    stdout.write("\n")
