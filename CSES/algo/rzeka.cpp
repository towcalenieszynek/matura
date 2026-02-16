#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    pair<unsigned int, unsigned int> tab[n];
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i].first >> tab[i].second;
    }
 
    cout << "PRINTUJE";

    sort(tab, tab + n); // sortuje po pierwszym elemencie pary, czyli x, co jest pozadane
    long long wynik = LLONG_MAX;
    long long odleglosc = tab[0].second;
    for(int i = 1; i < n; i++)
    {
        odleglosc += tab[i].first - tab[i-1].first;
        wynik = min(wynik, odleglosc+tab[i].second);
        odleglosc = min(odleglosc, (long long)tab[i].second); // tutaj powinien byc rzekomo min
    }

    cout << endl << "wynik to " << wynik << endl;
}