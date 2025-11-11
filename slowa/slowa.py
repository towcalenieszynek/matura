with open('./slowa/slowa_przyklad.txt', 'r') as f:
    slowa = [linia.strip() for linia in f]

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