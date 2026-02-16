#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long s;

    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<pair<long long, int>> pref(n+1);
    pref[0] = {0, -1};
    for(int i = 1; i <= n; i++) {
        pref[i] = {pref[i-1].first + v[i-1], i-1};
    }

    sort(pref.begin(), pref.end());

    long long suma = 0;
    int kon = 0;
    int wynik = -1;

    for(int pocz = 0; pocz <= n; pocz++) {
        while(kon <= n && pref[kon].first - pref[pocz].first <= s)
        {
            if (pref[kon].first - pref[pocz].first == s && kon >= pocz) {
                wynik = max(wynik, abs(pref[kon].second - pref[pocz].second));
            }
            kon++;
        }
    }

    if (wynik == -1) cout << "BRAK";
    else cout << wynik;
}