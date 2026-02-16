#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
vector<int> sasiedzi;

int ile_sasiadow(int w) {
    int sum = 0;
    for (int sasiad : t[w]) {
        sum++;
        if (sasiedzi[sasiad] == -1) {
            sum += ile_sasiadow(sasiad);
        } else {
            sum += sasiedzi[sasiad];
        }
    }
    sasiedzi[w] = sum;
    return sum;
}

int main() {
    int n, x;
    cin >> n;
    t.resize(n+1);
    sasiedzi.assign(n+1, -1);
    for(int i = 2; i <= n; i++) {
        cin >> x;
        t[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ile_sasiadow(i) << " ";
    }
}