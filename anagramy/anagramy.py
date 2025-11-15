with open('./anagramy/dane_napisy.txt', 'r') as f:
    slowa = [tuple(linia.strip().split()) for linia in f.readlines()]


#1 podpunkt
def czy_jednolite(first, second):
    litera = first[0]
    for l in first:
        if l != litera:
            return False
    for l in second:
        if l != litera:
            return False
    return True

def czy_anagram(first, second):
    if len(first) == len(second):
        return sorted(first) == sorted(second)
    return False

res1, res2 = 0, 0

for slowo1, slowo2 in slowa:
    if czy_anagram(slowo1, slowo2):
        res2 += 1
        if czy_jednolite(slowo1, slowo2):
            res1 += 1

k = -1

for i in range(2, 21):
    slowa_same_dlugosc = []
    for slowo1, slowo2 in slowa:
        if len(slowo1) == i:
            slowa_same_dlugosc.append(str(sorted(slowo1)))
        if len(slowo2) == i:
            slowa_same_dlugosc.append(str(sorted(slowo2)))
    
    slowa_same_dlugosc = list(sorted(slowa_same_dlugosc))
    t = 1
    for j in range(1, len(slowa_same_dlugosc)):
        if slowa_same_dlugosc[j] == slowa_same_dlugosc[j-1]: 
            t += 1
        else:
            k = max(k, t)
            t = 1
    k = max(k, t)

print('1 podpunkt', res1)
print('2 podpunkt', res2)
print('3 podpunkt', k)