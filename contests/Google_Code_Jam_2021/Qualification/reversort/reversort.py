def main():
  for CASE in range(1,int(input())+1):
    N = int(input())
    L = list(map(int, input().split()))
    LS = sorted(L)
    cost = 0
    for i, s in enumerate(LS[:-1]):
      #print(f"i:{i}, s:{s}, L:{L}")
      j = i+L[i:].index(s)
      cost += (j-i+1)
      #print(f"reverse({i},{j}) => +{cost}")
      for k in range((j+1-i)//2):
        #print(f"i:i+k:{i+k}, j-k:{j-k} <=> j-k:{j-k}, i+k:{i+k}")
        L[i+k], L[j-k] = L[j-k], L[i+k]
    print(f"Case #{CASE}: {cost}")

if __name__ == "__main__":
  main()
