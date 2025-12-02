from collections import Counter

with open('./geny/dane_geny.txt', 'r') as f:
    genotypy = [linia.strip() for linia in f.readlines()]

def extract(genotyp):
    second_a = False
    second_b = False
    encoding = False
    geny = []
    gen = ''
    for l in genotyp:
        if l == 'A':
            second_b = False
            if second_a:
                encoding = True
                second_a = False
                gen += l
            else:
                second_a = True
                gen += l
        elif l == 'B':
            second_a = False
            if second_b:
                encoding = False
                second_b = False
                gen += l
                geny.append(gen)
                gen = ''
            else:
                second_b = True
                gen += l
        else:
            second_a = False
            second_b = False
            if encoding:
                gen += l

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