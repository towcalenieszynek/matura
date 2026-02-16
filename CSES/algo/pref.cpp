#include <bits/stdc++.h>
using namespace std;
int p[6];

int main() {
    int tab[5] = {1, 2, 3, 4, 5};
    for (auto el : tab) {
        cout << el << endl;
    }

    for(int k = 1; k <= 5; k++)
    {
        p[k] = p[k-1] + tab[k-1];
    }

    for(auto el : p) {
        cout << el << endl;
    }

    int suma(int x, int y) {
        return p[y+1] - p[x];
    }

    cout << "SUMA od 1 do 3 (czyli od 2 do 4) " << suma(1, 3) << endl;

}
