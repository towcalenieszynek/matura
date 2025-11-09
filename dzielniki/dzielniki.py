import math

liczby = []
with open("liczby.txt") as f:
    for linia in f:
        liczby.append(int(linia.strip()))

# 1 podpunkt
mnniz1000 = []
res1 = 0
for liczba in liczby:
    if liczba < 1000:
        res1 += 1
        mnniz1000.append(liczba)

print(res1)
print(mnniz1000[-2:])


# 2 podpunkt
def dz(n):
    dzielniki = []
    for i in range(1, int(math.sqrt(n))+1):
        if n%i == 0:
            dzielniki.append(i)
            dzielniki.append(n//i)
    return sorted(dzielniki)


dane = [] #(liczba, dzielniki)

for liczba in liczby:
    dzielnik = dz(liczba)
    dane.append((liczba, dzielnik))
    if len(dzielnik) == 18:
        print("{} - {}".format(liczba, dzielnik))



# 3 podpunkt
# dane = (a, b)
# print(dane)
# for i, (a, b) in enumerate(dane):
#     print(a)
#     print(b)

wzgl = []

for i, (liczba, dzielniki) in enumerate(dane):
    dzielniki = dzielniki[1:]
    dzielniki = set(dzielniki)
    res = 0
    for liczba2, dzielniki2 in dane[:i] + dane[i+1:]:
        dzielniki2 = dzielniki2[1:]
        dzielniki2 = set(dzielniki2)
        if dzielniki.isdisjoint(dzielniki2):
            # print('względnie pierwsza {} z {}'.format(liczba, liczba2))
            res += 1
    wzgl.append((liczba, res))

res3 = -1
for liczba, n in wzgl:
    if n == 200-1:
        # print('wzgl pierwsza ze wszystkimi' + str(liczba))
        res3 = max(res3, liczba)

print(res3)
