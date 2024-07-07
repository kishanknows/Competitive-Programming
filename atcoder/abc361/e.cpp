#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    int sm = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
        sm += w;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, 1e15);
    dist[1] = 0;
    pq.push({ 0, 1 });
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        for (auto [u, w] : adj[cur]) {
            if (dist[u] > d + w) {
                dist[u] = d + w;
                pq.push({ dist[u], u });
            }
        }
    }
    int id = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    vector<int> dist2(n + 1, 1e15);
    dist2[id] = 0;
    pq.push({ 0, id });
    while (!pq.empty()) {
        auto [d, cur] = pq.top(); pq.pop();
        for (auto [u, w] : adj[cur]) {
            if (dist2[u] > d + w) {
                dist2[u] = d + w;
                pq.push({ dist2[u], u });
            }
        }
    }
    int res = *max_element(dist2.begin() + 1, dist2.end());
    cout << 2 * sm - res << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}