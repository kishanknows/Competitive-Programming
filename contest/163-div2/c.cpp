#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

bool dfs(int r, int c, vector<string>& s, bool flag, int n, map<vector<int>, bool>& mp) {
    if (mp.find({ r, c, flag }) != mp.end()) return mp[{r, c, flag}];
    if (r != 0 && r != 1) return false;
    if (c < 0 || c >= n) return false;
    if (r == 1 && c == n - 1) return true;
    if (flag) {
        bool res = false;
        res = res || dfs(r + 1, c, s, !flag, n, mp);
        res = res || dfs(r - 1, c, s, !flag, n, mp);
        res = res || dfs(r, c + 1, s, !flag, n, mp);
        // res = res || dfs(r, c - 1, s, !flag, n, mp);
        mp[{r, c, flag}] = res;
    }
    else {
        if (s[r][c] == '<') {
            // mp[{r, c, flag}] = dfs(r, c - 1, s, !flag, n, mp);
        }
        if (s[r][c] == '>') {
            mp[{r, c, flag}] = dfs(r, c + 1, s, !flag, n, mp);
        }
    }
    return mp[{r, c, flag}];
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    map<vector<int>, bool> mp;
    bool flag = true;
    bool res = dfs(0, 0, s, flag, n, mp);
    cout << (res ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}