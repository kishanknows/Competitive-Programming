#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt1 = 1, cnt2 = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) cnt1++;
        else break;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1]) cnt2++;
        else break;
    }
    if (a.front() == a.back()) {
        cout << max(0LL, n - cnt1 - cnt2) << endl;
    }
    else {
        cout << min(n - cnt1, n - cnt2) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}