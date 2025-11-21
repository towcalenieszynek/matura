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
            if second_a:
                encoding = True
                second_a = False
                gen += l
            else:
                second_a = True
                gen += l
        elif l == 'B':
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

geny = []

for genotyp in genotypy:
    geny.append(extract(genotyp))

print(len(geny), len(set(geny)))