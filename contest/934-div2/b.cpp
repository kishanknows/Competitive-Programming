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
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) mp1[a[i]]++;
    for (int i = n; i < 2 * n; i++) mp2[a[i]]++;
    vector<int> res1, res2, res3;
    for (auto it = mp1.begin(); it != mp1.end(); it++) {
        if (it->second == 1) res3.push_back(it->first);
    }
    for (auto it = mp1.begin(); it != mp1.end(); it++) {
        if (it->second == 2) {
            res1.push_back(it->first);
        }
    }
    for (auto it = mp2.begin(); it != mp2.end(); it++) {
        if (it->second == 2) {
            res2.push_back(it->first);
        }
    }
    int tmp = 2 * k;
    for (int i = 0; i < res1.size() && tmp; i++) {
        cout << res1[i] << " " << res1[i] << " ";
        tmp -= 2;
    }
    for (int i = 0; i < res3.size() && tmp; i++) {
        cout << res3[i] << " ";
        tmp--;
    }
    cout << endl;
    tmp = 2 * k;
    for (int i = 0; i < res2.size() && tmp; i++) {
        cout << res2[i] << " " << res2[i] << " ";
        tmp -= 2;
    }
    for (int i = 0; i < res3.size() && tmp; i++) {
        cout << res3[i] << " ";
        tmp--;
    }
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