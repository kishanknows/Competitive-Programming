#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int> fib(46, 0);

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int tmp = n + 1;
    while (tmp > 1) {
        int l = fib[tmp] - fib[tmp - 1] + 1;
        int r = fib[tmp - 1];
        if (l <= y && y <= r) {
            cout << "NO" << endl;
            return;
        }
        if (y > r) y -= r;
        tmp--;
        swap(x, y);
    }
    cout << "YES" << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    fib[0] = 1; fib[1] = 1;
    for (int i = 2; i < 46; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    while (t--) solve();
    return 0;
}