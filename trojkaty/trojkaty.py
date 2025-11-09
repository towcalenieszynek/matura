liczby = []
#dlugosc pliku dane_trojkaty.txt to 500
with open('./trojkaty/dane_trojkaty.txt', 'r') as f:
    for linia in f:
        liczby.append(int(linia.strip()))

#1 podpunkt
def czy_prostokatny(a, b, c):
    a, b, c = sorted([a, b, c])
    return a*a + b*b == c*c

print('1 podpunkt:')
for i in range(2, len(liczby), 1):
    if czy_prostokatny(liczby[i-2], liczby[i-1], liczby[i]):
        print(liczby[i-2], liczby[i-1], liczby[i])

#2 podpunkt
def czy_trojkat(a, b, c):
    a, b, c = sorted([a, b, c])
    return a + b > c
posortowane = sorted(liczby, reverse=True)

print('2 podpunkt:')
for i in range(len(posortowane) - 2):
    a, b, c = posortowane[i], posortowane[i+1], posortowane[i+2]
    if czy_trojkat(a, b, c):
        print('Obwod:', a + b + c)
        print(a, b, c)
        break

#3 podpunkt
res = 0
# trojkaty = []
print('3 podpunkt:')
for i in range(len(liczby)):
    for j in range(i + 1, len(liczby)):
        for k in range(j + 1, len(liczby)):
            a, b, c = liczby[i], liczby[j], liczby[k]
            if czy_trojkat(a, b, c):
                res += 1
                print(a, b, c)
                # trojkaty.append(tuple(sorted([a, b, c])))
print('Liczba trojkatow:', res)