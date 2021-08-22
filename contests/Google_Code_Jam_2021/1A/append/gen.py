#!/usr/bin/python3

print(10000+1000000)
for i in range(10000):
  print(2)
  print(f"{(i//100)%100 + 1} {i%100 + 1}")

for i in range(1000000):
  print(3)
  print(f"{((i//100)//100)%100 + 1} {(i//100)%100 + 1} {i%100 + 1}")
