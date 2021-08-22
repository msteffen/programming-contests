for Z in range(int(input())):
  n, k, s = map(int, input().split())
  print(f"Case #{Z+1}: {min((k-1)+1+n, (k-1)+(k-s)+(n-s+1))}")
