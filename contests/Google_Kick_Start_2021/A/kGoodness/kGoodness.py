#!/usr/bin/python3.7
from sys import stdin

def l():
  return stdin.readline().rstrip()

for Z in range(int(l())):
  n, k = map(int, l().split())
  s = l()
  goodness = 0
  for i in range(len(s)//2):
    if s[i] != s[n-1-i]:
      goodness += 1
  print(f"Case #{Z+1}: {abs(k-goodness)}")

