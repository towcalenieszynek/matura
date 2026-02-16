#include <bits/stdc++.h>
using namespace std;

// int drzewo[4 * 200007];
vector<int> drzewo(4*200007, INT_MAX);
int base = 1;

void wstaw(int v, int wart) {
    v += base - 1;
    drzewo[v] = wart;
    v /= 2;
    while (v > 0) {
        drzewo[v] = min(drzewo[2*v], drzewo[2*v + 1]);
        v /= 2;
    }
}

int odp(int a, int b) {
    int wynik = INT_MAX;
    int L = (a-1) + base - 1;
    int P = (b+1) + base - 1;
    while (P - L > 1) {
        if (L%2 == 0) {
            wynik = min(wynik, drzewo[L+1]);
        }
        if (P%2 == 1) {
            wynik = min(wynik, drzewo[P-1]);
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

    for (int i = 1; i <= n; i++) {
        cin >> q;
        wstaw(i, q);
    }

    // for (int i = 0; i < m; i++) {
    //     cin >> a >> b;
    //     cout << odp(a,b) << "\n";
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

/*
8 4 3 2 4 5 1 1 5 3 2 1 4 2 5 6 1 2 3 2 1 4*/