def main():
  for CASE in range(1,int(input())+1):
    cj, jc, L = input().split()
    cj, jc = int(cj), int(jc)
    # print(f"cj:{cj}, jc:{jc}")
    prev='X'
    cost=0
    for i, l in enumerate(L):
      if l == 'C':
        if prev=='J':
          # print(f"{i-1}: JC")
          cost += jc
        prev=l
      if l == 'J':
        if prev=='C':
          # print(f"{i-1}: CJ")
          cost += cj
        prev=l
    print(f"Case #{CASE}: {cost}")

if __name__ == "__main__":
  main()
