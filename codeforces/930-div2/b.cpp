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
    string s, t;
    cin >> s >> t;
    vector<int> eq(n);
    bool flag = false;
    cout << s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] - '0' < t[i - 1] - '0') eq[i] = 1;
        else if (s[i] - '0' > t[i - 1] - '0') {
            eq[i] = 2;
            flag = true;
        }
        else eq[i] = 0;
        cout << (flag ? t[i - 1] : s[i]);
    }
    cout << t[n - 1] << endl;
    int p = 1;
    while (p < n && eq[p] != 2) p++;
    int q = p;
    while (q > 0 && eq[q] != 1) q--;
    cout << max(1LL, p - q) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}