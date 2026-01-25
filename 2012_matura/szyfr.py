import math

with open('tj.txt', 'r') as f:
    slowa = [t.strip() for t in f]

with open('klucze1.txt', 'r') as f:
    klucze = [t.strip() for t in f]

do_szyfrowania = dict()

for i in range(len(slowa)):
    do_szyfrowania[slowa[i]] = klucze[i]


#szyfrowanie - OK
def szyfruj(tekst: str, klucz: str) -> str:
    klucz_temp = math.ceil(len(tekst) / len(klucz)) * klucz
    klucz_temp = klucz_temp[:len(tekst)]
    klucz = klucz_temp
    zaszyfrowany = ''
    for j in range(len(tekst)):
        zaszyfrowany += chr(65 + (ord(tekst[j]) + ord(klucz[j]))%26 + 1)
    return zaszyfrowany

#deszyfrowanie - OK
def deszyfruj(tekst: str, klucz: str) -> str:
    klucz_temp = math.ceil(len(tekst) / len(klucz)) * klucz
    klucz_temp = klucz_temp[:len(tekst)]
    klucz = klucz_temp
    deszyfrowany = ''
    for j in range(len(tekst)):
        deszyfrowany += chr(65 + (ord(tekst[j]) - ord(klucz[j])) % 26 - 1)
    return deszyfrowany

