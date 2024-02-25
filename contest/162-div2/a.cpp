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
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sm += a[i];
        pre[i] = sm;
    }
    int i = 1, j = n;
    while (a[i] != 1) i++;
    while (a[j] != 1) j--;
    cout << j - i + 1 - (pre[j] - pre[i - 1]) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}