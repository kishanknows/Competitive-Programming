#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

vector<int> a = { 5, 6, 7, 8, 9 };
map<int, bool> mp;
bool func(int x) {
    if (x <= 0) return false;
    if (mp.find(x) != mp.end()) return mp[x];
    bool res = false;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i] + a[j] == x) {
                res = true;
                break;
            }
            if ((a[i] + a[j]) % 10 == x % 10) {
                res = res || func(x / 10 - (a[i] + a[j]) / 10);
            }
        }
    }
    mp[x] = res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    cout << (func(n) ? "YES" : "NO") << endl;
    mp.clear();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}