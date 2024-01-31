#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int __int128_t
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) tmp[i] = a[i];
        ll k;
        cin >> k;
        int m = pow(2, 60);
        for (int i = 60; i >= 0; i--) {
            int cur = 0LL;
            for (int j = 0; j < n; j++) {
                cur += (tmp[j] & m) == 0 ? (m - (tmp[j] % m)) : 0;
            }
            if (cur <= k && k != 0) {
                for (int j = 0; j < n; j++) {
                    tmp[j] -= (tmp[j] & m) == 0 ? (tmp[j] % m) : 0;
                    tmp[j] += (tmp[j] & m) == 0 ? m : 0;
                }
                k -= cur;
            }
            m /= 2;
        }
        ll res = tmp[0];
        for (int i = 1; i < n; i++) res &= tmp[i];
        cout << res << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}