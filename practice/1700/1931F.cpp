#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if (k == 1) {
        cout << "YES" << endl;
        return;
    }
    int x = a[0][0], y = a[1][0];
    int ix = 0, iy = 0;
    vector<int> tmp;
    for (int i = 1; i < n; i++) {
        if (a[0][i] == y) iy = i;
        tmp.push_back(a[0][i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[1][i] == x) ix = i;
    }
    vector<int> tmp2 = tmp;
    tmp.insert(tmp.begin() + ix, x);
    tmp2.insert(tmp2.begin() + ix - 1, x);

    bool res1 = true, res2 = true;

    for (int i = 0; i < k; i++) {
        int p = a[i][0];
        int l = 0, r = 0;
        while (l < n && r < n) {
            if (a[i][l] == p) {
                l++;
                continue;
            }
            if (tmp[r] == p) {
                r++;
                continue;
            }
            if (a[i][l] != tmp[r]) {
                res1 = false;
                break;
            }
            l++; r++;
        }
        if (!res1) break;
    }
    for (int i = 0; i < k; i++) {
        int p = a[i][0];
        int l = 0, r = 0;
        while (l < n && r < n) {
            if (a[i][l] == p) {
                l++;
                continue;
            }
            if (tmp2[r] == p) {
                r++;
                continue;
            }
            if (a[i][l] != tmp2[r]) {
                res2 = false;
                break;
            }
            l++; r++;
        }
        if (!res2) break;
    }
    cout << ((res1 || res2) ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}