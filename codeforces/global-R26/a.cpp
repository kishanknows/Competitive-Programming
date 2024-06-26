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
    vector<int> a(n);
    string res = "";
    map<int, int> mp;
    int mx = -1, id = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res.push_back('R');
        mp[a[i]]++;
        if (mp[a[i]] > mx) {
            mx = mp[a[i]];
            id = i;
        }
    }
    if (count(a.begin(), a.end(), a[0]) == n) {
        cout << "NO" << endl;
        return;
    }
    res[id] = 'B';
    cout << "YES" << endl;
    cout << res << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}