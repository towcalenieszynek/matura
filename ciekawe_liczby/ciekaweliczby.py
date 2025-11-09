liczby = []
with open('liczby.txt') as f:
    for liczba in f:
        liczby.append(int(liczba.strip()))


#1 podpunkt

def cz_pierw(n):
    i = 2
    czynniki = set([])
    if n%2 == 1:
        while i*i <= n:
            while(n%i == 0):
                n = n // i
                czynniki.add(i)
            i += 1

    return len(czynniki) == 3

res1 = 0
for liczba in liczby:
    if cz_pierw(liczba):
        res1 += 1

print(res1)

#2 podpunkt

for liczba in liczby:
    suma = liczba + int(str(liczba)[::-1])
    print(suma)


