#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 0 << endl;
        return;
    }
    if (k <= n) {
        cout << 1 << endl;
        return;
    }
    k -= n;
    int res = 1;
    while (--n) {
        k -= n;
        res++;
        if (k <= 0) {
            cout << res << endl;
            return;
        }
        k -= n;
        res++;
        if (k <= 0) {
            cout << res << endl;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}