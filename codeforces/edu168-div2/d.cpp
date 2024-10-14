#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<set<int>> adj(n + 1);
    vector<int> par(n + 1);
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].insert(i);
        adj[i].insert(x);
        par[i] = x;
    }
    set<int> q;
    for (int i = 2; i <= n; i++) {
        if (adj[i].size() == 1) {
            q.insert(par[i]);
        }
    }
    while (!q.empty()) {
        int len = q.size();
        set<int> tmp;
        for (int i = 0; i < len; i++) {
            int x = *q.begin(); q.erase(*q.begin());
            int mn = a[*adj[x].begin()];
            for (auto y : adj[x]) {
                mn = min(mn, a[y]);
            }
            if (a[x] < mn) {
                a[x] = (mn + a[x]) / 2;
            }
            else {
                a[x] = mn;
            }
            tmp.insert(par[x]);
        }
        for (auto x : tmp) q.insert(x);
    }
    cout << a[1] << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}