#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < mx) {
            pq.push(mx - a[i]);
        }
        else {
            mx = a[i];
        }
    }
    int cur = 0, res = 0;
    while (!pq.empty()) {
        res += (pq.size() + 1) * (pq.top() - cur);
        cur = pq.top();
        while (!pq.empty() && pq.top() <= cur) {
            pq.pop();
        }
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