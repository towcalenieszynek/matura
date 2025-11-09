import math

trojki = []
with open("./trojkiliczb/trojki.txt", 'r') as f:
    for linia in f:
        trojki.append(linia.strip())


#1 podpunkt
print('1 podpunkt:')
for trojka in trojki:
    a, b, c = map(str, trojka.split(' '))
    sum = 0
    for liczba in a:
        sum += int(liczba)
    for liczba in b:
        sum += int(liczba)
    if sum == int(c):
        print(trojka)

#2 podpunkt
def czyPierwsza(n):
    for i in range(2, int(math.sqrt(n)+1)):
        if n%i == 0:
            return False
    return True

print('2 podpunkt:')
for trojka in trojki:
    a, b, c = map(int, trojka.split(' '))
    if czyPierwsza(a) and czyPierwsza(b) and c == a*b:
        print(trojka)

#3 podpunkt
print('3 podpunkt:')
near = False
last = ''
for trojka in trojki:
    a, b, c = sorted(map(int, trojka.split(' ')))
    if a*a + b*b == c*c:
        if near == False:
            near = True
            last = trojka
        else:
            print(last)
            print(trojka)
            print('\n')
            near = False
    else:
        near = False

#4 podpunkt
print('4 podpunkt:')
sum = 0
streak = 0
max_streak = 0
for trojka in trojki:
    a, b, c = sorted(map(int, trojka.split(' ')))
    if a + b > c:
        sum += 1
        streak += 1
        max_streak = max(max_streak, streak)
    else:
        streak = 0
print('Liczba wierszy:', sum)
print('Najdluzszy ciag:', max_streak)
