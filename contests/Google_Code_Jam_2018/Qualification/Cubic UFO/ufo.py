#!/usr/bin/python3

from sys import *
from math import *

cases = int(stdin.readline())
eps=1e-6

for Z in range(1, cases+1):
    A = float(stdin.readline())
    print("A: {}", A)
    if A < (1-eps):
        print("Case #{}: IMPOSSIBLE".format(Z, moves))
        continue
    if abs(A-1) < eps:
        print("Case #{}:\n0.5 0 0\n0 0.5 0\n0 0 0.5".format(Z))
    elif A > (1+eps) and A < (sqrt(2)+eps):
        # binary search through angles like a moron
        l, r = 0, pi/4
        while True:
            theta = (l+r)/2
            newa=sin(theta)+cos(theta)
            if abs(newa-A) < eps:
                print("theta: {}".format(theta*180/pi))
                print("Case #{}:\n{} {} 0\n{} {} 0\n0 0 0.5".format(
                    Z,
                    0.5*cos(theta), 0.5*sin(theta),
                    -0.5*sin(theta), 0.5*cos(theta)))
                break
            if newa < A:
                l = theta
            else:
                r = theta
    else:
        # again, binary search through angles like a moron
        l, r = 0, pi/4
        while True:
            theta = (l+r)/2
            newa=sin(theta)+((2*cos(theta))/sqrt(2))
            print("theta: {}".format(theta*180/pi))
            print("sin(theta): {}, 2/√2 * cos(theta)".format(sin(theta), ((2*cos(theta))/sqrt(2))))
            print("A: {}, newa: {}".format(A, newa))
            if abs(newa-A) < eps:
                print("theta: {}".format(theta*180/pi))
                print("Case #{}:\n{} {} {}\n{} {} {}\n0 {} {}".format(
                    Z,
                    1/(2*sqrt(2)), 1/(2*sqrt(2)), -0.5*sin(theta),
                    -1/(2*sqrt(2)), 1/(2*sqrt(2)), -0.5*sin(theta),
                    0.5*sin(theta), 0.5*cos(theta)))
                break
            if newa < A:
                l = theta
            else:
                r = theta
