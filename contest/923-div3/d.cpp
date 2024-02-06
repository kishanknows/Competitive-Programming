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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> code(n + 1);
    map<int, vector<int>> mp;
    int x = 1;
    mp[x].push_back(1);
    code[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) mp[x].push_back(i);
        else {
            x++;
            mp[x].push_back(i);
        }
        code[i] = x;
    }
    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (code[l] == code[r]) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        else {
            cout << mp[code[l]].back() << " " << mp[code[l] + 1][0] << endl;
        }
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}