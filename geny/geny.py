from collections import Counter

with open('./geny/dane_geny.txt', 'r') as f:
    genotypy = [linia.strip() for linia in f.readlines()]

def extract(genotyp):
    geny = []
    i = 0
    n = len(genotyp)
    
    while i < n - 1:
        # Szukamy początku genu (AA)
        if genotyp[i] == 'A' and genotyp[i+1] == 'A':
            gen_start = i
            i += 2
            # Szukamy końca genu (BB)
            while i < n - 1:
                if genotyp[i] == 'B' and genotyp[i+1] == 'B':
                    # Znaleźliśmy koniec genu
                    gen = genotyp[gen_start:i+2]
                    geny.append(gen)
                    i += 2
                    break
                i += 1
            else:
                # Nie znaleziono BB - koniec genotypu
                break
        else:
            i += 1
    
    return tuple(geny)

#1 podpunkt
dl_genotypow = []

for genotyp in genotypy:
    dl_genotypow.append(len(genotyp))

wystapienia_dl = Counter(dl_genotypow)

print('1 podpunkt')
print(len(wystapienia_dl))
print(max(wystapienia_dl.values()))

#2 podpunkt
# gatunki = {
# }

# for genotyp in genotypy:
#     l = len(genotyp)
#     if l not in gatunki:
#         gatunki[l] = []
#     gatunki[l].append(genotyp)

res = 0
for genotyp in genotypy:
    for gen in extract(genotyp):
        if 'BCDDC' in gen:
            res += 1
            break

print('2 podpunkt')
print(res)

#3 podpunkt
ilosc_genow_u_osobnika = []
for genotyp in genotypy:
    geny = extract(genotyp)
    print(geny)
    print(len(geny))
    ilosc_genow_u_osobnika.append(len(geny))

print('3 podpunkt')
print(len(max(genotypy, key=lambda g: len(g))))
print(max(ilosc_genow_u_osobnika))