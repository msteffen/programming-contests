import sys
import time

Q = 10000
P = 100
# Q = 3
# S = 8

def main():
  for CASE in range(1,int(input())+1):
    input()
    easyness = [0]*Q
    player = []
    for i in range(P):
      l = input()
      player.append(l)
      for j, c in enumerate(l):
        if c == '1':
          easyness[j] += 1

    qr = sorted(enumerate(easyness), key = lambda x: (x[1],x[0]))
    print(f"qr:{qr}")
    # sys.exit(1)

    weirdest = (0, 0)
    for n, p in enumerate(player):
      # add correct questions to error for skill levels > q (skill line is right-inclusive)
      error, skill_errors = 0, [0]*(Q+1)
      for i, (q, easiness) in enumerate(qr):
        if p[q] == '1':
          error += P-easiness
        skill_errors[i+1] += error
      # add wrong answers to error for skill levels <= q
      error = 0
      for i in range(Q-1,-1,-1):
        q, easiness = qr[i]
        if p[q] == '0':
          error += easiness
        skill_errors[i] += error

      # find min(skill_error) and see if this player has max(min(skill_error))
      player_err = -1
      for err in skill_errors:
        if player_err == -1 or err < player_err:
          player_err = err
      print(f"{n+1}: {player_err}")
      # time.sleep(3)
      if player_err > weirdest[1]:
        weirdest = (n+1, player_err)
    print(f"Case #{CASE}: {weirdest[0]}")

if __name__ == "__main__":
  main()
