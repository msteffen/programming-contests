# 1000
# 9999
# K digits, 10^(k-1)*9 options
# 1st must be 13579
# 2nd must be 02468
# Total is 5^k

# then for e.g. 3A,BCD:
# c([3A.BCD,99.999]) = c([40.000,99.999]) + c([3A.BCD,39.999])
# first digit+1 -> 9-(first)*5^(k-1) + 3ABCD where

def alld(ex, n):
  assert(ex >= 0 and ex < 10)
  assert(type(n) is list)

  for d in n:
    if d != ex:
      return False
  return True

def fil(n, d, li):
  assert(type(n) is int)
  assert(type(d) is int)
  if type(li) is list:
    return [n]+([d]*(len(li)-1))
  if type(li) is int:
    return [n]+([d]*(li-1))

def f(p, l, r):
  # print(f"p:{p} l:{l} r:{r}")
  assert(type(l) is list)
  if alld(0,l): l = [0]*len(r) # match lengths for (000,B)
  assert(len(l) > 0)
  assert(type(r) is list)
  assert(len(r) > 0)
  assert(len(r) >= len(l))
  assert(p == 0 or p == 1)

  # Cases:
  # Base case: f(p,A,B): sum([ i%2 == p for i in range(A,B+1)])
  # Base case: f(p,000,999): 5^3
  # Base case: f(p,Aaa,Abb): (A%2==p)*f(p',aa,bb)
  # Case f(p,Aaa,Bbb) = f(p,Aaa,A99)
  #                   + f(p,(A+1)00,(A+1)99)+...+f(p,(B-1)00,(B-1)99)
  #                   + f(p,B00,Bbb)
  # Case f(p, Aa,Bbbb) = f(p,Aa,99) + f(p,100,999) + f(p,1000,Bbbb)

  if len(l) == 1 and len(r) == 1:
    # print("Base case: f(p,A,B)")
    return sum([ i%2 == p for i in range(l[0],r[0]+1)])
  if alld(0,l) and alld(9,r):
    # print("Base case: f(p,000,999)")
    assert(len(l) == len(r))
    return 5**(len(r))
  elif len(l) == len(r) and l[0] == r[0]:
    # print("Base case: f(Aaa,Abb)")
    if l[0]%2 != p:
      return  0
    return f((p+1)%2,l[1:],r[1:])
  elif len(l) == len(r) and l[0] < r[0]:
    # print("Case f(p,Aaa,Bbb) = f(p,Aaa,A99)+...+f(p,B00,Bbb)")
    count = f(p, l, fil(l[0],9,l))
    for i in range(l[0]+1,r[0]):
      count += f(p, fil(i,0,l), fil(i,9,l))
    count = f(p, fil(r[0],0,l), r)
    return count
  elif len(l) < len(r):
    # print("Case f(Aa,Bbbb) = f(Aa,99) + f(100,999) + f(1000,Bbbb)")
    count = f(p, l, fil(9,9,l))
    for i in range(len(l)+1, len(r)):
      count += f(p, fil(1,0,i), fil(9,9,i))
    count += f(p, fil(1,0,r), r)
    return count
  else:
    assert(False)

def main():
  for Z in range(int(input())):
    l, r = [ list(map(int,n)) for n in input().split() ]
    print(f"Case #{Z+1}: {f(1,l,r)}")

main()
