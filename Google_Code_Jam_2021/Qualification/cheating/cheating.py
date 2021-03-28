Q = 10000
S = 100
# Q = 3
# S = 8

def main():
  for CASE in range(1,int(input())+1):
    input()
    easyness = [0]*Q
    player = []
    for i in range(S):
      l = input()
      player.append(l)
      for j, c in enumerate(l):
        if c == '1':
          easyness[j] += 1

    qr = sorted(enumerate(easyness), key = lambda x: (x[1],x[0]))
    print(f"qr:{qr}")

    most_swaps = (-1, -1)
    __player_swaps = []
    for n, p in enumerate(player):
      corrects, highest_easyness_to_num_right, swaps = 0, [0, 0], 0
      for q, easyness in qr:
        if p[q] == '1':
          corrects += 1
          if highest_easyness_to_num_right[0] != easyness:
            highest_easyness_to_num_right = [ easyness, 0]
          highest_easyness_to_num_right[1] += 1
        else:
          if highest_easyness_to_num_right[0] == easyness:
            # no swap if X is wrong but Qs as easy as X are right--only Qs
            # harder than X make swaps here
            swaps += (corrects - highest_easyness_to_num_right[1])
            # print(f"{q} is wrong: {corrects - highest_easyness_to_num_right[1]} swaps")
          else:
            swaps += corrects
            # print(f"{q} is wrong: {corrects} swaps")
      __player_swaps.append((n, swaps))
      if swaps > most_swaps[1]:
        most_swaps = (n+1, swaps)
      __player_swaps.sort(key = lambda x: (x[1], x[0]))
      print("\n".join([ f"{s[0]+1:2d}: {s[1]} swaps" for s in __player_swaps ]))

    print(f"Case #{CASE}: {most_swaps[0]}")

if __name__ == "__main__":
  main()
