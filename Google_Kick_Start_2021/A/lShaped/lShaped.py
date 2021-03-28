# mm = make matrix
def mm(n, *dims):
  if len(dims) == 0:
    return [0]*n
  return [ mm(*dims) for i in range(n) ]

def p(mat):
  for r in mat: print(r)

def main():
  for Z in range(int(input())):
    r, c = map(int, input().split())
    M = []
    for i in range(r):
      M.append(list(map(int, input().split())))
    # p(M)
    # DP - figure out "good" segments cornered at each (i,j)
    lef, rit, up, dn = [ mm(r, c) for i in range(4) ]
    for i in range(r):
      for j in range(c):
        if M[i][j] == 1:
          lef[i][j] = (lef[i][j-1] + 1 if j > 0 else 1)
          up[i][j] = (up[i-1][j] + 1 if i > 0 else 1)
    for i in range(r-1, -1, -1):
      for j in range(c-1, -1, -1):
        if M[i][j] == 1:
          rit[i][j] = (rit[i][j+1] + 1 if j < (c-1) else 1)
          dn[i][j] = (dn[i+1][j] + 1 if i < (r-1) else 1)

    # Count Ls by looking for valid corners & counting ells at that corner
    ells = 0
    for a, b in [ (rit, up), (rit, dn), (lef, up), (lef, dn), ]:
      # print("--")
      for i in range(r):
        for j in range(c):
          # ells where a is shorter
          # print(f"i:{i} j:{j} ells:+{max(0, min(a[i][j]-1, (b[i][j]//2)-1))}")
          ells += max(0, min(a[i][j]-1, (b[i][j]//2)-1))
          # ells where b is shorter
          # print(f"i:{i} j:{j} ells:+{max(0, min(b[i][j]-1, (a[i][j]//2)-1))}")
          ells += max(0, min(b[i][j]-1, (a[i][j]//2)-1))
    print(f"Case #{Z+1}: {ells}")


main()
