#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    int res = 0;
    res += (n / 15);
    n -= (n / 15) * 15;
    res += (n / 10);
    n -= (n / 10) * 10;
    res += (n / 6);
    n -= (n / 6) * 6;
    res += (n / 3);
    n -= (n / 3) * 3;
    res += n;
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