plansza = list()

with open('./2016_matura/gra.txt', 'r') as f:
    for wiersz in f:
        plansza.append(wiersz.strip().split(' '))
print(plansza)