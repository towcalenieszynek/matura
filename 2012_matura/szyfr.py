import math

with open('./2012_matura/tj.txt', 'r') as f:
    slowa = [t.strip() for t in f]

with open('./2012_matura/klucze1.txt', 'r') as f:
    klucze = [t.strip() for t in f]

do_szyfrowania = dict()

for i in range(len(slowa)):
    do_szyfrowania[slowa[i]] = klucze[i]

with open('./2012_matura/sz.txt', 'r') as f:
    slowa = [t.strip() for t in f]

with open('./2012_matura/klucze2.txt', 'r') as f:
    klucze = [t.strip() for t in f]

do_deszyfrowania = dict()

for i in range(len(slowa)):
    do_deszyfrowania[slowa[i]] = klucze[i]


#szyfrowanie - OK
def szyfruj(tekst: str, klucz: str) -> str:
    klucz_temp = math.ceil(len(tekst) / len(klucz)) * klucz
    klucz_temp = klucz_temp[:len(tekst)]
    klucz = klucz_temp
    zaszyfrowany = ''
    for j in range(len(tekst)):
        zaszyfrowany += chr(65 + (ord(tekst[j]) + ord(klucz[j])+1)%26)
    return zaszyfrowany

#deszyfrowanie - OK
def deszyfruj(tekst: str, klucz: str) -> str:
    klucz_temp = math.ceil(len(tekst) / len(klucz)) * klucz
    klucz_temp = klucz_temp[:len(tekst)]
    klucz = klucz_temp
    deszyfrowany = ''
    for j in range(len(tekst)):
        deszyfrowany += chr(65 + (ord(tekst[j]) - ord(klucz[j]) - 1) % 26 )
    return deszyfrowany

print('Dlugosc do szyfrowania:', len(do_szyfrowania))
with open('./2012_matura/wynik4a.txt', 'w') as plik:
    for tekst, klucz in do_szyfrowania.items():
        print(f'{tekst} - {klucz} = {szyfruj(tekst, klucz)}')
        plik.write(szyfruj(tekst, klucz)+'\n')
    plik.close()

print('Dlugosc do deszyfrowania:', len(do_deszyfrowania))
with open('./2012_matura/wynik4b.txt', 'w') as plik:
    for tekst, klucz in do_deszyfrowania.items():
        print(f'{tekst} - {klucz} = {deszyfruj(tekst, klucz)}')
        plik.write(deszyfruj(tekst, klucz)+'\n')
    plik.close()


