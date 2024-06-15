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
    for (int i = 0; i < n; i++) cin >> a[i];
    int id = 1;
    for (int i = 1; i < n - 1; i++) {
        if (gcd(a[i - 1], a[i]) > gcd(a[i], a[i + 1])) {
            id = i;
            break;
        }
    }
    vector<int> b, c, d;
    b = a, c = a, d = a;
    bool r1 = true, r2 = true, r3 = true;
    b.erase(b.begin() + id - 1);
    c.erase(c.begin() + id);
    d.erase(d.begin() + id + 1);

    for (int i = 1; i < n - 2; i++) {
        if (gcd(b[i - 1], b[i]) > gcd(b[i], b[i + 1])) {
            r1 = false;
            break;
        }
    }
    for (int i = 1; i < n - 2; i++) {
        if (gcd(c[i - 1], c[i]) > gcd(c[i], c[i + 1])) {
            r2 = false;
            break;
        }
    }
    for (int i = 1; i < n - 2; i++) {
        if (gcd(d[i - 1], d[i]) > gcd(d[i], d[i + 1])) {
            r3 = false;
            break;
        }
    }

    cout << (r1 || r2 || r3 ? "YES" : "NO") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}