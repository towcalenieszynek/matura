liczby = []
with open('./liczby_binarne/liczby.txt', 'r') as f:
    for linia in f:
        liczby.append(linia.strip())

max_liczba = liczby[0]
min_liczba = liczby[0]
max_wiersz = None
min_wiersz = None
for wiersz, liczba in enumerate(liczby[1:]):
    # Porównaj dwie liczby binarne literka po literce
    # Najpierw wyrównaj długości (dłuższa jest zawsze większa)
    if len(liczba) > len(max_liczba):
        max_liczba = liczba
        max_wiersz = wiersz + 2
    elif len(liczba) == len(max_liczba) and liczba > max_liczba:
        max_liczba = liczba
        max_wiersz = wiersz + 2
    
    if len(liczba) < len(min_liczba):
        min_liczba = liczba
        min_wiersz = wiersz + 2
    elif len(liczba) == len(min_liczba) and liczba < min_liczba:
        min_liczba = liczba
        min_wiersz = wiersz + 2

print('Największa liczba (wiersz {}): {}'.format(max_wiersz, max_liczba))
print('Najmniejsza liczba (wiersz {}): {}'.format(min_wiersz, min_liczba))



