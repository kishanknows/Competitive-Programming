#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

const int MOD = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int sum(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = 1, res = 0;
    for (int i = 0; i < 30; i++) {
        int s1 = 0, s0 = 0, c1 = 0, c0 = 1, cur = 0, x = 0;
        for (int j = 0; j < n; j++) {
            x ^= ((a[j] >> i) & 1);
            if (x) {
                int r = mul(c0, j + 1);
                add(cur, sum(r, -s0));
                c1++;
                add(s1, j + 1);
            }
            else {
                int r = mul(c1, j + 1);
                add(cur, sum(r, -s1));
                c0++;
                add(s0, j + 1);
            }
        }
        add(res, mul(cur, (1 << i)));
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}