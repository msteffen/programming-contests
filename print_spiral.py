#!/usr/bin/python3
from sys import argv, exit

ch = '\u2588'

def main(N):
  # Build empty NxN matrix of dots
  mat=[ch*N]
  for i in range(N-1): mat.append(['.']*N)

  # Fill in matrix with chars
  dr=[1,0,-1,0]
  dc=[0,-1,0,1]
  r, c = 0, (N-1)
  for i in range(N-1):
    for j in range(N-1-((i//2)*2)):
      r += dr[i%4]
      c += dc[i%4]
      # print(f" - {r},{c}")
      mat[r][c] = ch
  print("\n".join([ "".join(r) for r in mat]))

if len(argv) != 2:
  print("need size argument!")
  exit(1)

main(int(argv[1]))
