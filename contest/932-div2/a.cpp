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
    int i = 0, j = s.length() - 1;
    while (i < j && s[i] == s[j]) {
        i++;
        j--;
    }
    if (s[i] > s[j]) {
        string st = s;
        reverse(s.begin(), s.end());
        cout << s << st << endl;
        return;
    }
    cout << s << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}