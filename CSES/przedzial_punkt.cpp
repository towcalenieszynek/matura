#include <bits/stdc++.h>
using namespace std;

long long drzewo[4 * 200007];
int base = 1;

long long odp(int a) {
    a += base - 1;
    long long wynik = 0;
    while(a > 0) {
        wynik += drzewo[a];
        a /= 2;
    }
    return wynik;
}

void aktu(int a, int b, int wartosc) {
    int L = (a-1) + base - 1;
    int P = (b+1) + base - 1;
    while (P - L > 1) {
        if (L % 2 == 0) {
            drzewo[L+1] += wartosc;
        }
        if (P % 2 == 1) {
            drzewo[P-1] += wartosc;
        }
        L /= 2;
        P /= 2;
    }
}

int main() {
    int n, m, q, a, b, wart;
    cin >> n >> m;
    while (base < n) base *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> drzewo[i + base - 1];
    }
    for (int i = 0; i < m; i++) {
        cin >> q;
        if (q == 1) {
            cin >> a >> b >> wart;
            aktu(a, b, wart);
        } else {
            cin >> a;
            cout << odp(a) << "\n";
        }
    }
}
/*
8 3 3 2 4 5 1 1 5 3 2 4 1 2 5 1 2 4*/