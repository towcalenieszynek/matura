#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, x;
    cin >> x >> k;
    int n = pow(2, k);
    vector<int> right(n+1, false);
    int i, new_i;
    for(int a = 0; a < x; a++) {
        i = 1; new_i = 0;
        while (i < n / 2 - 1) {
            new_i = 2*i + right[i];
            right[i] = !right[i];
            i = new_i;
        }
    }
    cout << i % (n/2);
}
