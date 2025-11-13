with open('./statystyki/tekst.txt', 'r') as f:
    slowa = f.read().split(' ')
    slowa[-1] = slowa[-1].strip()

#1 podpunkt
def dwie_nastepne(slowo):
    for i in range(1, len(slowo)):
        if slowo[i] == slowo[i-1]:
            return True
    return False
print('1 podpunkt')
res = 0
for slowo in slowa:
    res += 1 if dwie_nastepne(slowo) else 0
print(res)

#2 podpunkt
wystapienia = {}
for slowo in slowa:
    for litera in slowo:
        if litera not in wystapienia:
            wystapienia[litera] = 0
        wystapienia[litera] += 1

wystapienia = dict(sorted(wystapienia.items()))
ilosc_liter = 0
for liczba in wystapienia.values():
    ilosc_liter += liczba
print('2 podpunkt')
for litera, ilosc_litery in wystapienia.items():
    print('{}: ({}%)'.format(litera, round(ilosc_litery/ilosc_liter*100,2)))

#3 podpunkt
def najdluzszy_ciag_spolglosek(slowo):
    samogloski = 'AEIOUY'
    max_dlugosc = 0
    aktualna_dlugosc = 0
    
    for litera in slowo:
        if litera not in samogloski:
            aktualna_dlugosc += 1
            max_dlugosc = max(max_dlugosc, aktualna_dlugosc)
        else:
            aktualna_dlugosc = 0
    
    return max_dlugosc

print('3 podpunkt')
max_dlugosc_spolglosek = 0
for slowo in slowa:
    dlugosc = najdluzszy_ciag_spolglosek(slowo)
    max_dlugosc_spolglosek = max(max_dlugosc_spolglosek, dlugosc)

slowa_z_max_dlugoscia = []
for slowo in slowa:
    if najdluzszy_ciag_spolglosek(slowo) == max_dlugosc_spolglosek:
        slowa_z_max_dlugoscia.append(slowo)

print('Dlugosc najdluzszego podslowa:', max_dlugosc_spolglosek)
print('Liczba slow z takiej dlugosci podslowem:', len(slowa_z_max_dlugoscia))
print('Pierwsze slowo:', slowa_z_max_dlugoscia[0])