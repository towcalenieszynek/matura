with open('./liczby_2019/przyklad.txt') as f:
    liczby = [int(linia.strip()) for linia in f]

#1 podpunkt
def solve_1(n):
    while n > 1:
        if n%3 != 0:
            return False
        n //= 3
    return True

res = 0
print('1 podpunkt')
for liczba in liczby:
    if solve_1(liczba):
        res += 1
print(res)

#2 podpunkt
import math
res = 0
print('2 podpunkt')
for liczba in liczby:
    if liczba > 0:
        silnia_cyfr = 0
        for cyfra in str(liczba):
            silnia_cyfr += math.factorial(int(cyfra))
        res += 1 if silnia_cyfr == liczba else 0
print(res)

#3 podpunkt
def nwd(a, b):
    while b:
        a, b = b, a % b
    return a

max_ciag = -1
ciag = [liczby[0]]
nwd_ciagu = liczby[0]

for liczba in liczby[1:]:
    if nwd(nwd_ciagu, liczba) > 1:
        ciag.append(liczba)
        nwd_ciagu = nwd(nwd_ciagu, liczba)
    else:
        max_ciag = max(max_ciag, len(ciag))
        ciag = [liczba]
        nwd_ciagu = liczba
max_ciag = max(max_ciag, len(ciag))

print('3 podpunkt')
print(max_ciag)
