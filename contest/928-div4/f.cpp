#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    vector<string> a(7);
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
    }
    map<pair<int, int>, bool> mp;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (a[i][j] == 'W') continue;
            bool flag = i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j - 1] == 'B';
            flag = flag && i - 1 >= 0 && j + 1 < 7 && a[i - 1][j + 1] == 'B';
            flag = flag && i + 1 < 7 && j - 1 >= 0 && a[i + 1][j - 1] == 'B';
            flag = flag && i + 1 < 7 && j + 1 < 7 && a[i + 1][j + 1] == 'B';
            if (flag) {
                mp[{i, j}] = true;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (mp[{i + 1, j + 1}] && mp[{i + 1, j - 1}] && mp[{i - 1, j + 1}] && mp[{i - 1, j - 1}]) {
                mp.erase({ i + 1, j + 1 });
                mp.erase({ i + 1, j - 1 });
                mp.erase({ i - 1, j + 1 });
                mp.erase({ i - 1, j - 1 });
                res++;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (mp[{i + 1, j + 1}] && mp[{i + 1, j - 1}] && mp[{i - 1, j + 1}]) {
                mp.erase({ i + 1, j + 1 });
                mp.erase({ i + 1, j - 1 });
                mp.erase({ i - 1, j + 1 });
                res++;
            }
            if (mp[{i + 1, j + 1}] && mp[{i + 1, j - 1}] && mp[{i - 1, j - 1}]) {
                mp.erase({ i + 1, j + 1 });
                mp.erase({ i + 1, j - 1 });
                mp.erase({ i - 1, j - 1 });
                res++;
            }
            if (mp[{i + 1, j + 1}] && mp[{i - 1, j + 1}] && mp[{i - 1, j - 1}]) {
                mp.erase({ i + 1, j + 1 });
                mp.erase({ i - 1, j + 1 });
                mp.erase({ i - 1, j - 1 });
                res++;
            }
            if (mp[{i + 1, j - 1}] && mp[{i - 1, j + 1}] && mp[{i - 1, j - 1}]) {
                mp.erase({ i + 1, j - 1 });
                mp.erase({ i - 1, j + 1 });
                mp.erase({ i - 1, j - 1 });
                res++;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (mp[{i + 1, j - 1}] && mp[{i - 1, j + 1}]) {
                mp.erase({ i + 1, j - 1 });
                mp.erase({ i - 1, j + 1 });
                res++;
            }
            if (mp[{i + 1, j + 1}] && mp[{i - 1, j - 1}]) {
                mp.erase({ i + 1, j + 1 });
                mp.erase({ i - 1, j - 1 });
                res++;
            }
            if (mp[{i - 1, j + 1}] && mp[{i + 1, j + 1}]) {
                mp.erase({ i - 1, j + 1 });
                mp.erase({ i + 1, j + 1 });
                res++;
            }
            if (mp[{i + 1, j + 1}] && mp[{i + 1, j - 1}]) {
                mp.erase({ i + 1, j + 1 });
                mp.erase({ i + 1, j - 1 });
                res++;
            }
            if (mp[{i - 1, j - 1}] && mp[{i + 1, j - 1}]) {
                mp.erase({ i - 1, j - 1 });
                mp.erase({ i + 1, j - 1 });
                res++;
            }
            if (mp[{i - 1, j + 1}] && mp[{i - 1, j - 1}]) {
                mp.erase({ i - 1, j + 1 });
                mp.erase({ i - 1, j - 1 });
                res++;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (mp[{i + 1, j + 1}]) {
                mp.erase({ i + 1, j + 1 });
                res++;
            }
            if (mp[{i - 1, j - 1}]) {
                mp.erase({ i - 1, j - 1 });
                res++;
            }
            if (mp[{i - 1, j + 1}]) {
                mp.erase({ i - 1, j + 1 });
                res++;
            }
            if (mp[{i + 1, j - 1}]) {
                mp.erase({ i + 1, j - 1 });
                res++;
            }
        }
    }

    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}