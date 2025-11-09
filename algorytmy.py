import math

def czyPierwsza(n):
    for i in range(2, int(math.sqrt(n)+1)):
        if n%i == 0:
            return False
    return True

def rozklad(n):
    i = 2
    czynniki = []

    while (n > 1):
        while(n%i == 0):
            n = n/i
            czynniki.append(i)
        i += 1
    return czynniki

def horner(wspolczynniki, podstawa):
    # wsp = [], podstawa = int
    wynik = []
    wynik.append(wspolczynniki[0])
    for i in range(1, len(wspolczynniki)):
        wynik.append(wynik[i-1]*podstawa + wspolczynniki[i])
    return wynik[-1]

# print(horner([1,0,1,0,1,0], 2))

# print(horner(
#     [int(digit) for digit in input('Podaj liczbę: ')],
#     int(input('Podaj podstawę systemu: '))
#     ))

# tab = [1,2,5,6,3,9,11,34,27,18]



def naPozycyjny(n, podstawa):
    liczba = []
    while(n > 1):
        liczba.append(n%podstawa)
        n = n // podstawa
    liczba.append(n%podstawa)
    return list(reversed(liczba))

# print(naPozycyjny(41, 2))


def pierwiastek(n, dokl):
    a = 1
    b = n
    eps = pow(0.1, dokl)
    while(abs(a-b) >= eps):
        a = (a+b) / 2
        b = n/a

    return round((a+b)/2, dokl)

print(pierwiastek(3, 3))
print(pierwiastek(3, ))