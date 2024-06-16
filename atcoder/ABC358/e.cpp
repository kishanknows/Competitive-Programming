#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<int> fact(1001);
int mod = 998244353;

vector<int> tmp;
int res;
void dfs(int k, int cur, int id, vector<int>& c) {
    if (k == cur) {
        int dem = 1;
        for (auto x : tmp) {
            // cout << x << " ";
            dem = (dem * fact[x]) % mod;
        }
        // cout << endl;
        res = (res + fact[k] / dem) % mod;
    }
    if (id >= 26 || cur > k) return;
    for (int i = 0; i <= c[id]; i++) {
        tmp.push_back(i);
        dfs(k, cur + i, id + 1, c);
        tmp.pop_back();
    }
}

void solve() {
    int k;
    cin >> k;
    vector<int> c(26);
    for (int i = 0; i < 26; i++) {
        cin >> c[i];
    }
    res = 0;
    for (int i = 1; i <= k; i++) {
        dfs(i, 0, 0, c);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    fact[0] = 1;
    for (int i = 1; i < 1001; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    while (t--) solve();
    return 0;
}