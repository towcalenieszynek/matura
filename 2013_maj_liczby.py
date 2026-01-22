with open('./dane.txt', 'r') as f:
    dane = [liczba.strip() for liczba in f]

#1 podpunkt
    res1 = 0
    for l in dane:
        if l[0] == l[-1]:
            res1 += 1
    
#2 podpunkt
    res2 = 0
    dane_dec = [str(int(l, base=8)) for l in dane]
    for l in dane_dec:
        if l[0] == l[-1]:
            res2 += 1

#3 podpunkt
    def warunek(liczba: str) -> bool:
        prev = liczba[0]
        for i in range(1, len(liczba)):
            if liczba[i] < prev:
                return False
        return True
    
    liczby_spelniajace_warunek = list()

    for liczba in dane:
        if warunek(liczba):
            liczby_spelniajace_warunek.append(liczba)

    temp = [int(liczba, base=8) for liczba in liczby_spelniajace_warunek]
    print(min(temp))
    print(max(temp))

print('1 podpunkt:', res1)
print('2 podpunkt:', res2)
print('3 podpunkt:')
print(f'Min: {str(oct(min(temp))[2:])} (dec: {min(temp)})')
print(f'Max: {str(oct(max(temp))[2:])} (dec: {max(temp)})')
