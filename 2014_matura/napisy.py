with open('./2014_matura/NAPIS.txt', 'r') as f:
    napisy = [napis.strip() for napis in f]

#1 podpunkt
import math
def czy_pierwsza(liczba: int) -> bool:
    for i in range(2, int(math.sqrt(liczba)) + 1):
        if liczba % i == 0:
            return False
    return True

res1 = 0

for napis in napisy:
    suma_ascii = 0
    for char in napis:
        suma_ascii += ord(char)
    if czy_pierwsza(suma_ascii):
        res1 += 1

print(res1)

#2 podpunkt
def solve(napis: str) -> bool:
    prev = 0
    for char in napis:
        if ord(char) > prev:
            prev = ord(char)
        else:
            return False
    return True


res2 = list()

for napis in napisy:
    if solve(napis):
        res2.append(napis)


print(res2, len(res2))

#3 podpunkt
from collections import Counter
c = Counter(napisy)
for key, value in c.items():
    if value > 1:
        print(key)