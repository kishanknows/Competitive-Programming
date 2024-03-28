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
    string a = "##";
    string b = "..";
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            cout << (i & 1 ? b : a);
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << (i & 1 ? b : a);
        }
        cout << endl;
        swap(a, b);
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