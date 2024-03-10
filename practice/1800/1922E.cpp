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
    vector<int> len;
    for (int i = 60; i >= 0; i--) {
        if ((n & (1LL << i)) != 0) len.push_back(i);
    }
    vector<int> res;
    int cur = 1, k = 0;
    int x = len[0];
    while (x--) {
        res.push_back(cur);
        cur++;
    }
    for (int i = 1; i < len.size(); i++) {
        res.insert(res.begin() + res.size() - len[i], 0LL);
    }
    cout << res.size() << endl;
    for (auto r : res) cout << r << " ";
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