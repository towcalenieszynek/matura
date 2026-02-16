#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
vector<bool> odwiedzony;
vector<int> poprzednicy;

int n, m;


int main() {
    cin >> n >> m;
    int a, b;

    t.resize(n+1);
    odwiedzony.resize(n+1, false);
    poprzednicy.resize(n+1);
    poprzednicy[1] = 0;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    odwiedzony[1] = true;

    int res = -1;

    while(!q.empty()) {
        int w = q.front();
        q.pop();

        if (w == n) {
            res = poprzednicy[w];
            break;
        }

        for (int sasiad : t[w]) {
            if (!odwiedzony[sasiad]) {
                odwiedzony[sasiad] = true;
                poprzednicy[sasiad] = w;
                q.push(sasiad);
            }
        }
    }

    if (res == -1) {
        cout << "IMPOSSIBLE";
    }
    else {
        // backtracking
        vector<int> sciezka;
        int curr = n;
        sciezka.push_back(curr);
        while(curr > 1) {
            sciezka.push_back(poprzednicy[curr]);
            curr = poprzednicy[curr];
        }
        reverse(sciezka.begin(), sciezka.end());

        cout << sciezka.size() << "\n";
        for (auto el : sciezka) {
            cout << el << " ";
        }
    }
}