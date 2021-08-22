#!/usr/bin/python3
from sys import stdin, stdout

ZZZ = int(stdin.readline().strip())
for Z in range(ZZZ):
    A = stdin.readline().strip()
    if len(A) == 1:
        stdout.write("Case #{}: Impossible\n".format(Z+1))
        continue
    cnd = 0
    diff = False
    match_start = 0
    n = 0
    for i in range(1, len(A)):
        #print("{}[i ({})]: {}".format(A, i, A[i]))
        #print("{}[c ({})]: {}".format(A, cnd, A[cnd]))
        if A[i] != A[cnd] and cnd != 0:
            diff = True
            n = i
            break
        elif A[i] == A[cnd]:
            if cnd == 0:
                match_start = i
            cnd+=1
    if (not diff) or (cnd == 0) or (cnd == (len(A)-1)):
        stdout.write("Case #{}: Impossible\n".format(Z+1))
    else:
        # Have to think through this more -- need part of the string up to a
        # disagreement and then the whole string, so that part of the string
        # will have matched already. Example:
        # ABACUS
        #   ABACUS
        #    ^ break is here, but because ABACUS is self-similar, [AB][ABACUS]
        #    means ethan's algorithm tries to match [ABA(C)] and fails
        #    the match that has already started. Basically, we need to print
        #    the part of W up to the point where W begins to match itself, and
        #    then all of W, so that ethan's algorithm begins readings the full
        #    occurrance of W thinking that it's parsing the latter part
        # This was my original thought, but I think it's wrong
        stdout.write("(orig) Case #{}: {}{}\n".format(Z+1, A[:cnd+1], A))
        # This is what I submitted, but I think it's wrong too
        stdout.write("(subm) Case #{}: {}{}\n".format(Z+1, A[:n-1], A))
        # I think this is correct
        stdout.write("(corr) Case #{}: {}{}\n".format(Z+1, A[:match_start], A))
