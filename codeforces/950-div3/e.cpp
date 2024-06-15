#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> ax(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    vector<vector<int>> bx(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            ax[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            bx[i][j] = b[i][j];
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        sort(ax[i].begin(), ax[i].end());
        sort(bx[i].begin(), bx[i].end());
        mp[ax[i][0]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (mp.find(bx[i][0]) == mp.end()) {
            cout << "NO" << endl;
            return;
        }
        else {
            int k = mp[bx[i][0]];
            for (int j = 0; j < m; j++) {
                if (bx[i][j] != ax[k][j]) {
                    cout << "NO" << endl;
                    return;
                }
            }
            mp.erase(bx[i][0]);
        }
    }
    vector<vector<int>> ay(m, vector<int>(n));
    vector<vector<int>> by(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ay[j][i] = a[i][j];
            by[j][i] = b[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        sort(ay[i].begin(), ay[i].end());
        sort(by[i].begin(), by[i].end());
        mp[ay[i][0]] = i;
    }
    for (int i = 0; i < m; i++) {
        if (mp.find(by[i][0]) == mp.end()) {
            cout << "NO" << endl;
            return;
        }
        else {
            int k = mp[by[i][0]];
            for (int j = 0; j < n; j++) {
                if (by[i][j] != ay[k][j]) {
                    cout << "NO" << endl;
                    return;
                }
            }
            mp.erase(by[i][0]);
        }
    }

    cout << "YES" << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}