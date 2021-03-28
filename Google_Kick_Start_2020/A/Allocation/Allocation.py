cases = int(input())
for Z in range(cases):
    n, b = [ int(t) for t in input().split() ]
    As = sorted([ int(t) for t in input().split() ])
    s = 0
    for i in range(len(As)):
        s+=As[i]
        if s > b:
            print(f"Case #{Z+1}: {i}")
            break
