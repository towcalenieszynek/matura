#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<vector<bool>> odwiedzony;
int n, m, pokoje;

void dfs(int i, int j) {
    if (i < 0 || i > n-1 || j < 0 || j > m - 1) {
        return;
    } else {
        if (odwiedzony[i][j] || v[i][j] == '#') {
            return;
        } else {
            odwiedzony[i][j] = true;
            dfs(i-1, j);
            dfs(i+1, j);
            dfs(i, j-1);
            dfs(i, j+1);
        }
    }
}

int main() {
    cin >> n >> m;
    v.resize(n);
    odwiedzony.resize(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (!odwiedzony[i][j] && v[i][j] == '.') {
                pokoje++;
                dfs(i, j);
            }
        }
    }

    cout << pokoje;
}