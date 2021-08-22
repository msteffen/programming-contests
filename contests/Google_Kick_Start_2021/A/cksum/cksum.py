
def s(B):
  return "\n" + "\n".join([ " ".join(map(str, row)) for row in B ])

def main():
  for Z in range(int(input())):
    N = int(input())
    A, B = [], []
    for i in range(N):
      A.append(list(map(int, input().split())))
    for i in range(N):
      B.append(list(map(int, input().split())))
    input()
    input()

    total_cost = 0

    for X in range(2*N):
      # Find missing numbers & fix
      rmissing = [0]*N
      cmissing = [0]*N
      # SHould only run N times
      fixed = True
      while fixed:
        fixed = False
        for r in range(N):
          for c in range(N):
            if B[r][c] != 0:
              rmissing[r] += 1
              cmissing[c] += 1
        for i in range(N):
          if rmissing[i] == 1:
            rmissing[i] = 0
            for j in range(N):
              if B[i][j] != 0:
                B[i][j] = 0
                cmissing[j] -= 1
                fixed = True
          if cmissing[i] == 1:
            cmissing[i] = 0
            for j in range(N):
              if B[j][i] != 0:
                B[j][i] = 0
                rmissing[j] -= 1
                fixed = True
        # print(f"B: {s(B)}")
        # print(f"rmissing:{rmissing} cmissing:{cmissing}")

      # print(f"B: {s(B)}")
      for i in range(N):
        if rmissing[i] > 0 or cmissing[i] > 0:
          # print(f"missing:{i}")
          break
      else:
        # print("Nothing missing")
        break

      # compute cost to fix each row/column
      # = Cost to restore all but one bit (cksum determines last bit)
      # => cost is all but most expensive bit
      rmax, cmax = [0]*N, [0]*N
      rcost, ccost = [0]*N, [0]*N
      for r in range(N):
        for c in range(N):
          rmax[r] = max(rmax[r], B[r][c])
          cmax[c] = max(cmax[c], B[r][c])
          rcost[r] += B[r][c]
          ccost[c] += B[r][c]
      best, besti, bestdir = 0, 0, ""
      for i in range(N):
        if best == 0 or (rcost[i] - rmax[i]) < best:
          best, besti, bestdir = (rcost[i]-rmax[i]), i, "row"
        if best == 0 or (ccost[i] - cmax[i]) < best:
          best, besti, bestdir = (ccost[i]-cmax[i]), i, "col"
      #print(f"best:{bestdir} {besti}: {best}")

      # Fix cheapest row/col
      total_cost += best
      for i in range(N):
        if bestdir == "row":
          B[besti][i] = 0
        if bestdir == "col":
          B[i][besti] = 0
    print(f"Case #{Z+1}: {total_cost}")

main()
