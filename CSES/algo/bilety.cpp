#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k, t;
    priority_queue<int, vector<int>, greater<int>> pq;

    int res = 0;

    for(int i = 0; i < n; i++) {
        cin >> t >> k;
        for(int j = 0; j < k; j++) pq.push(t);
        res += pq.top();
        pq.pop();
    }
    cout << res;
}