#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 6;
    int n = 3;
    vector<int> c = {1, 2, 3};
    vector<int> dp(k+1, INT_MAX - 1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for (int j = c[i-1]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - c[i - 1]] + 1);
        }
    }
    
    for(int i = 0; i <= k; i++) {
        cout << dp[i] << " ";
    }
}