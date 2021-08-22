from collections import deque

for Z in range(int(input())):
  n, k, p = map(int, input().split())
  s = []
  for i in range(n):
    s.append(list(map(int, input().split())))

  best = 0
  def foo(b, nxt):
    global best
    if sum(map(len, nxt)) > ((n*k)-p):
      for i in range(len(nxt)):
        if len(nxt[i]) == 0: continue # no plate to pop
        nxt2 = [[n for n in stack] for stack in nxt]
        nxt2[i] = nxt[i][1:] # drop last plate from stack i
        foo(b+nxt[i][0], nxt2)
    elif p == ((n*k)-sum(map(len, nxt))) and b > best:
      best = b

  foo(0, s)
  print(f"Case #{Z+1}: {best}")
