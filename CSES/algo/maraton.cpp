#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    // no tez ok ale useless przy gasienicy

    // vector<long long> pref(n+1, 0);
    // for (int i = 1; i <= n; i++) {
    //     pref[i] = pref[i-1] + t[i-1];
    // }

    long long suma = 0; 

    /*
    5 10
    5 1 2 4 10
    */

    int kon = 0;
    long long wynik = 0;

    for (int pocz = 0; pocz < n; pocz++) {
        while(kon < n && suma + t[kon] <= k) {
            suma += t[kon];
            kon++;
        }
        wynik += kon - pocz;
        suma -= t[pocz];
    }

    cout << wynik;
}