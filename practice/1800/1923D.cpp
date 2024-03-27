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
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> pre(n + 1), post(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i > 0; i--) {
        post[i] = post[i + 1] + a[i];
    }
    vector<int> code(n + 1);
    int k = 1;
    while (k <= n) {
        int j = k;
        while (j <= n && a[j] == a[k]) {
            code[j] = k;
            j++;
        }
        k = j;
    }
    for (int i = 1; i <= n; i++) {
        if ((i + 1 <= n && a[i + 1] > a[i]) || a[i - 1] > a[i]) {
            cout << 1 << " ";
            continue;
        }
        int l = i + 1, r = n + 1;
        int res = INT_MAX;
        while (l < r) {
            int mi = (l + r) / 2;
            if (pre[mi] - pre[i] <= a[i] || (pre[mi] - pre[i] > a[i] && code[mi] == code[i + 1])) l = mi + 1;
            else r = mi;
        }
        if (l != n + 1) res = min(res, l - i);
        l = 0, r = i - 1;
        while (l < r) {
            int mi = (l + r + 1) / 2;
            if (post[mi] - post[i] <= a[i] || (post[mi] - post[i] > a[i] && code[mi] == code[i - 1])) r = mi - 1;
            else l = mi;
        }
        if (l != 0) res = min(res, i - l);
        cout << (res == INT_MAX ? -1 : res) << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}