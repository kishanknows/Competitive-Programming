#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int res = h[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (h[i] > res) {
            res = h[i];
        }
        else {
            res++;
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}