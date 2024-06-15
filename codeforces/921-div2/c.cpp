#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<set<int>> idx(k);
    for (int i = 0; i < m; i++) {
        idx[s[i] - 'a'].insert(i);
    }
    int mx = -1;
    string res = "";
    for (int i = 0; i < n; i++) {
        int val = -1;
        for (int j = 0; j < k; j++) {
            if (idx[j].empty()) {
                cout << "NO" << endl;
                cout << res;
                for (int l = i; l < n; l++) cout << char('a' + j);
                cout << endl;
                return;
            }
            mx = max(mx, *idx[j].begin());
        }
        res += s[mx];
        for (int j = 0; j < k; j++) {
            while (!idx[j].empty() && *idx[j].begin() <= mx)
                idx[j].erase(idx[j].begin());
        }
    }
    cout << "YES" << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}