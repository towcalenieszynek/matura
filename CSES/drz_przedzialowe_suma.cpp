#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 7;
long long drzewo[4 * MAXN];
int base = 1;

void wstaw(int v, long long wart) {
    v += base - 1;
    drzewo[v] = wart;
    v /= 2;
    while (v > 0) {
        drzewo[v] = drzewo[2*v] + drzewo[2*v + 1];
        v /= 2;
    }
}

long long odp(int a, int b) {
    long long wynik = 0;
    int L = (a - 1) + base - 1;
    int P = (b + 1) + base - 1;
    while (P - L > 1) {
        if (L % 2 == 0) {
            wynik += drzewo[L+1];
        }
        if (P % 2 == 1) {
            wynik += drzewo[P-1];
        }
        L /= 2;
        P /= 2;
    }
    return wynik;
}



int main() {
    int n, m, q, a, b;
    cin >> n >> m;

    while (base < n) base *= 2;
    for(int i = 1; i <= n; i++) {
        cin >> q;
        wstaw(i, q);
    }
    // for (int i = 0; i < m; i++) {
    //     cin >> a >> b;
    //     cout << odp(a, b) << "\n";
    // }
    for (int i = 0; i < m; i++) {
        cin >> q >> a >> b;
        if (q == 1) {
            wstaw(a, b);
        } else {
            cout << odp(a, b) << "\n";
        }
    }
}

/*8 4 3 2 4 5 1 1 5 3 2 1 4 2 5 6 1 3 1 2 1 4*/