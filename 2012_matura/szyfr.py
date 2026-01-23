import math

# with open('tj.txt', 'r') as f:
#     teksty_jawne = [t.strip() for t in f]

# with open('klucze1.txt', 'r') as f:
#     klucze1 = [t.strip() for t in f]


tekst = 'IPXP'
klucz = 'WODA'


# for i in range(len(teksty_jawne)):
#     tekst = teksty_jawne[i]
#     klucz = klucze1[i] 

klucz_temp = math.ceil(len(tekst) / len(klucz)) * klucz
klucz_temp = klucz_temp[:len(tekst)]

#szyfrowanie - OK
zaszyfrowany = ''
for j in range(len(tekst)):
    zaszyfrowany += chr(65 + (ord(tekst[j]) + ord(klucz[j]))%26 + 1)
print(zaszyfrowany)

#deszyfrowanie
deszyfrowany = ''
for j in range(len(tekst)):
    deszyfrowany += chr(65 + (ord(tekst[j]) - ord(klucz[j])) % 26 - 1)
print(deszyfrowany)