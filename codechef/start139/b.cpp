#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    if (m < n) {
        cout << n - m << endl;
        return;
    }
    cout << min(m % n, n - m % n) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
