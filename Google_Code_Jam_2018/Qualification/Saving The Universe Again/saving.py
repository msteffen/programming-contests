#!/usr/bin/python3

from sys import *

cases = int(stdin.readline())

for Z in range(cases):
    D, prog = stdin.readline().strip().split()
    prog = list(prog)
    D = int(D)

    mindamage = sum([1 for c in prog if c == 'S'])
    if mindamage > D:
        print("Case #{}: IMPOSSIBLE".format(Z+1))
        continue
    moves = 0
    while True:
        dmg, curdmg=0, 1
        for c in prog:
            # print(" > {}".format(c))
            if c == 'S':
                # print(" > {}".format(c))
                dmg += curdmg
            else:
                curdmg *= 2
        if dmg <= D:
            break
        mademove=False
        # print("prog: {}".format(prog))
        for i in range(len(prog)-1, -1, -1):
            # print("i: {}".format(i))
            if prog[i] == 'S' and i > 0 and prog[i-1] == "C":
                prog[i-1] = 'S'
                prog[i] = "C"
                mademove=True
                break
        # print("prog: {}".format(prog))
        assert(mademove)
        moves +=1
    print("Case #{}: {}".format(Z+1, moves))
