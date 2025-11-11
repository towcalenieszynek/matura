with open('./slowa/slowa_przyklad.txt', 'r') as f:
    slowa = [linia.strip() for linia in f]

#1 podpunkt
def znajdz_wystapienie(slowo):
    for i in range(len(slowo)-2):
        if slowo[i] == 'k' and slowo[i+2] == 't':
            return True
    return False

res = 0
for slowo in slowa:
    res += 1 if znajdz_wystapienie(slowo) else 0

print('1 podpunkt')
print(res)

#2 podpunkt
res = []
for slowo in slowa:
    rod13 = ''
    for litera in slowo:
        rod13 += chr((ord(litera) - 97 + 13) % 26 + 97)
    # print(slowo, rod13)
    if rod13[::-1] == slowo:
        res.append(slowo)

print('2 podpunkt')
print(len(res))
print(max(res, key=len))

#3 podpunkt
print('3 podpunkt')
for slowo in slowa:
    wystapienia = {}
    for litera in slowo:
        if litera not in wystapienia:
            wystapienia[litera] = 0
        wystapienia[litera] += 1
    l = len(slowo)
    for litera in wystapienia:
        if wystapienia[litera] >= l / 2:
            print(slowo)
            break