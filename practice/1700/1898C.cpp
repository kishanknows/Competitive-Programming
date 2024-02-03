#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n + m - 2 > k) {
        cout << "NO" << endl;
        return;
    }
    if ((k - (n + m - 2)) % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<vector<char>> row(n, vector<char>(m - 1, 'R'));
    vector<vector<char>> col(n - 1, vector<char>(m, 'R'));
    for (int i = 0; i < m - 1; i++) row[0][i] = i & 1 ? 'B' : 'R';
    bool flag = row[0][m - 2] == 'R';
    for (int i = 0; i < n - 1; i++) {
        col[i][m - 1] = flag ? 'B' : 'R';
        flag = !flag;
    }
    col[0][0] = 'B'; col[0][1] = 'B';
    row[1][0] = 'R';
    flag = col[n - 2][m - 1] == 'R';
    col[n - 2][m - 2] = flag ? 'B' : 'R';
    row[n - 1][m - 2] = flag ? 'R' : 'B';
    row[n - 2][m - 2] = flag ? 'R' : 'B';
    for (auto rs : row) {
        for (auto ch : rs)
            cout << ch << " ";
        cout << endl;
    }
    for (auto cs : col) {
        for (auto ch : cs)
            cout << ch << " ";
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}