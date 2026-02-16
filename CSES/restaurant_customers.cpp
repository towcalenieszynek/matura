#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> customers;
int maks = -1;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        customers.push({a, b});
    }
    int czas = 0;
    while(!customers.empty()) {
        czas++;
        if (customers.top().first == czas) {
            q.push(customers.top().second);
            customers.pop();
        }
        if (!q.empty()) {
            if (q.top() == czas) {
                q.pop();
            }
        }
        maks = max(maks, (int)q.size());
    }
    cout << maks;
}