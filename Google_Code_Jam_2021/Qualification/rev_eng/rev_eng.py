def t(n):
  if n%2 == 0:
    return (n/2)*(n+1)
  return n*((n+1)/2)

def main():
  for CASE in range(1,int(input())+1):
    n, c = map(int, input().split())
    if c < (n-1) or c > t(n)-1:
      print(f"Case #{CASE}: IMPOSSIBLE")
      continue
    L = [ x+1 for x in range(n) ]
    start, end, dir = 0, n-1, 0
    for m in range(n,1,-1):
      #print(f"C:{c} n:{m} L:{L}")
      if c >= (m+(m-1)-1):
        for j in range(m//2):
          L[start+j], L[end-j] = L[end-j], L[start+j]
        dir += 1
        c -= m
      else:
        c -= 1
      if dir%2 == 0:
        start += 1
      else:
        end -= 1

    print(f"Case #{CASE}: {' '.join(map(str, L))}")

if __name__ == "__main__":
  main()
