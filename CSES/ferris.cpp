#include <bits/stdc++.h>
using namespace std;

vector<int> t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int res = 0;
    cin >> n >> k;

    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int i = n - 1;
    int j = 0;
    while(j <= i) {
        if (t[i] + t[j] <= k) {
            res++;
            i--;
            j++;
        } else {
            res++;
            i--;
        }
    }
    cout << res;
}