s1 = []
with open('./systemyliczbowemeteo/dane_systemy1.txt', 'r') as f:
    for linia in f.readlines():
        zegar, temperatura = linia.strip().split()
        zegar = int(zegar, 2)
        if temperatura[0] == '-':
            temperatura = -int(temperatura[1:], 2)
        else:
            temperatura = int(temperatura, 2)
        s1.append((zegar, temperatura))

print(s1)

s2 = []
with open('./systemyliczbowemeteo/dane_systemy2.txt', 'r') as f:
    for linia in f.readlines():
        zegar, temperatura = linia.strip().split()
        zegar = int(zegar, 4)
        if temperatura[0] == '-':
            temperatura = -int(temperatura[1:], 4)
        else:
            temperatura = int(temperatura, 4)
        s2.append((zegar, temperatura))

s3 = []
with open('./systemyliczbowemeteo/dane_systemy3.txt', 'r') as f:
    for linia in f.readlines():
        zegar, temperatura = linia.strip().split()
        zegar = int(zegar, 8)
        if temperatura[0] == '-':
            temperatura = -int(temperatura[1:], 8)
        else:
            temperatura = int(temperatura, 8)
        s3.append((zegar, temperatura))


stacje = [s1, s2, s3]

#1 podpunkt
min_s1, min_s2, min_s3 = 999999999999, 99999999999, 99999999999

for _, temperatura in s1:
    min_s1 = min(min_s1, temperatura)

for _, temperatura in s2:
    min_s2 = min(min_s2, temperatura)

for _, temperatura in s3:
    min_s3 = min(min_s3, temperatura)

print('1 podpunkt', min_s1, min_s2, min_s3)

#2 podpunkt
def czy_niepoprawny(poprz, teraz):
    if teraz % 24 == 12 and poprz % 24 == 12:
        if teraz > poprz:
            return True
    return False

np1 = []

for i in range(1, len(s1)):
    if czy_niepoprawny(s1[i-1][0], s1[i][0]):
        np1.append(i)
if s1[0][0] % 24 != 12:
    np1.append(0)

#powtorz te logike dla s2 i s3
np2 = []
for i in range(1, len(s2)):
    if czy_niepoprawny(s2[i-1][0], s2[i][0]):
        np2.append(i)
if s2[0][0] % 24 != 12:
    np2.append(0)

np3 = []
for i in range(1, len(s3)):
    if czy_niepoprawny(s3[i-1][0], s3[i][0]):
        np3.append(i)
if s3[0][0] % 24 != 12:
    np3.append(0)

np1, np2, np3 = set(np1), set(np2), set(np3)

res = np1.intersection(np2).intersection(np3)

print('2 podpunkt')
print(len(res))
print(res)

#3 podpunkt
res3 = 0

for stacja in stacje:
    rekord = -9999999999
    # print(stacja)
    for zegar, temperatura in stacja:
        if rekord is None or temperatura > rekord:
            res3 += 1
            # print('Znaleziono dzień rekordowy: poprzednia {} nowa {}'.format(rekord, temperatura))
            rekord = temperatura
            # print('Znaleziono dzień rekordowy: poprzednia {} nowa {}'.format(rekord, temperatura))

print('3 podpunkt')
print(res3)

#4 podpunkt
skoki = []
for i in range(len(s1)):
    for j in range(i+1, len(s1)):
        ti, tj = s1[i][1], s1[j][1]
        r_ij = (ti-tj)**2
        skok = r_ij // abs(i - j)
        skoki.append(skok)

print('4 podpunkt')
print(skoki)
print(max(skoki))