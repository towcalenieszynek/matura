#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }

    int kon = 0;
    int wynik = 0;

    for(int pocz = 0; pocz < n; pocz++) {
        int maks_dolna = -1;
        while (kon < n && maks_dolna <= v[kon].second)
        {
            maks_dolna = max(maks_dolna, v[kon].first);
            kon++;
        }
        wynik = max(wynik, kon - pocz);
    }

    cout << wynik;
}