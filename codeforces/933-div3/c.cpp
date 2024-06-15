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
    int i = 0;
    int res = 0;
    while (i < n) {
        if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
            res++;
            i += 3;
        }
        else if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
            res++;
            i += 3;
        }
        else i++;
    }
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