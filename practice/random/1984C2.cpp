#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int mod = 998244353;
vector<int> res(200001);

void solve() {
    int n, sm = 0, mn = 0, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
        mn = min(mn, sm);
    }
    if (mn == 0) {
        cout << res[n] << endl;
        return;
    }
    sm = 0;
    int ops = 0;
    for (int i = 0; i < n; i++) {
        sm += a[i];
        if (sm == mn) {
            ans = (ans + res[n - i - 1 + ops]) % mod;
        }
        if (sm >= 0) ops++;
    }
    cout << ans << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    res[0] = 1;
    for (int i = 1; i < 200001; i++) {
        res[i] = (res[i - 1] * 2) % mod;
    }
    while (t--) solve();
    return 0;
}