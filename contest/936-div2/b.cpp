#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int mod = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
        if (sm <= -mod) sm += mod;
        if (sm > mod) sm -= mod;
    }
    int i = 0;
    int mx = 0, res = 0;
    while (i < n) {
        while (i < n && mx >= 0) {
            mx += a[i];
            res = max(res, mx);
            i++;
        }
        // i++;
        mx = 0;
    }
    sm -= res;
    int tmp = res;
    int cur = 2, p = 1;
    while (k > 0) {
        while (k > 0 && sm + res * cur < mod) {
            k -= p;
            cur = cur * cur;
            p *= 2;
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