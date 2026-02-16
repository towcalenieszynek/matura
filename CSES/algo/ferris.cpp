#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, x, t, sum, res;
vector<int> v;

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    
    int i = 1;
    while (i <= n) {
        int weight = v[i];
        if (weight > 0) {
            int max_combined = -1;
            int idx = -1;
            for(int j = n-1; j > 0; j--)
            {
                if (weight + v[j] <= x) {
                    if (weight + v[j] > max_combined)
                    {
                        idx = j;
                        max_combined = weight + v[j];
                    }
                }
            }
            v[idx] = -1;
            res++;
        }
        v[i] = -1;
        i++;
    }
    res++;

    
    cout << res;
}