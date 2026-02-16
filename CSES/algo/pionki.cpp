#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i-1] + v[i-1]);
    }
    cout << dp[n];
}