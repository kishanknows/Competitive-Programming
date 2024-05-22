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
    string s;
    cin >> s;
    for (int k = n; k > 0; k--) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!q.empty() && i - q.front() == k) q.pop();
            if (q.size() % 2 == 0 && s[i] == '0' || q.size() % 2 == 1 && s[i] == '1') {
                q.push(i);
            }
        }
        if (q.size() == 0 || q.size() == 1 && n - q.front() == k) {
            cout << k << endl;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}