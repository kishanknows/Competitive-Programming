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
    vector<int> divs;
    divs.push_back(1);
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && n / i == i) {
            divs.push_back(i);
        }
        else if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }
    divs.push_back(n);
    sort(divs.begin(), divs.end());
    for (auto d : divs) {
        int cnt = 0;
        for (int i = 0; i < d; i++) {
            map<char, int> mp;
            for (int j = i; j < n; j += d) {
                mp[s[j]]++;
            }
            if (mp.size() == 1) continue;
            else if (mp.size() == 2) {
                auto it = mp.begin();
                auto it2 = next(mp.begin());
                cnt += min(it->second, it2->second);
            }
            else cnt += mp.size();
            if (cnt > 1) break;
        }
        if (cnt <= 1) {
            cout << d << endl;
            return;
        }
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