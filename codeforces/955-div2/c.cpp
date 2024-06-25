#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cur = 0, res = 0, j = 0;
    for (int i = 0; i < n; i++) {
        while (cur + a[i] > r) {
            cur -= a[j];
            j++;
        }
        cur += a[i];
        if (cur >= l && cur <= r) {
            res++;
            j = i + 1;
            cur = 0;
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