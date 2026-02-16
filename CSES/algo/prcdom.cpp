#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> tab(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }
    // int L[n]; L[0] = 0;
    // int P[n]; P[n-1] = 0;
    vector<int> L(n, 0);
    vector<int> P(n, 0);
    for(int i = 1; i < n; i++)
    {
        L[i] = max(0, L[i-1] + tab[i]);
    }
    for(int i = n-2; i >= 0; i--)
    {
        P[i] = max(0, P[i+1] + tab[i]);
    }

    for(int i = 0; i < n; i++)
    {
        cout << L[i] << " " << P[i] << "\n";
    }

    int wynik = -1;

    for(int i = 1; i < n-1; i++)
    {
        wynik = max(wynik, L[i-1] + P[i+1]);
    }

    cout << "WYNIK = " << wynik;
}