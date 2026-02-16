#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> kolejka = {5, 2, 4, 3};
    int n = kolejka.size();

    int minimum = kolejka[n-1];
    int poprzedni = n+1;
    int wynik = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (kolejka[i] < minimum)
        {
            wynik += minimum*(poprzedni - i);
            minimum = kolejka[i];
            poprzedni = i+1;
        }
    }
    cout << "wynik " << wynik;
}