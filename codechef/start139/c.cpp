#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    vector<int> res;
    for (int i = 1; i <= n; i++) {

    }
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) cout << ((i + (n + 1) / 2) > n ? (i + (n + 1) / 2) - n : (i + (n + 1) / 2)) << " ";
    cout << endl;
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}