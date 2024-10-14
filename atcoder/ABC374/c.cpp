#include <bits/stdc++.h>

#define int long long
using namespace std;

int res = INT_MAX;

int dfs(vector<int>& k, int start, int n, int sm, int cur) {
    if (start == n) {
        res = min(res, max(sm, cur));
        return res;
    }
    res = min(res, max(dfs(k, start + 1, n, sm, cur), dfs(k, start + 1, n, sm - k[start], cur + k[start])));
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> k(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        sm += k[i];
    }
    cout << dfs(k, 0, n, sm, 0) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}