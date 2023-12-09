#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define int long long
using namespace std;

int n, k, a, b;
vector<int> x, y;

int dist(int i, int j){
    if(i < k && j < k) return 0;
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}

void solve(){
    cin >> n >> k >> a >> b;
    vector<int> r(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> r[i] >> c[i];
    }
    x = r, y = c;
    int mina = LLONG_MAX, minb = LLONG_MAX;
    int ia = -1, ib = -1;
    for(int i = 0; i < k ; i++){
        if(dist(a-1, i) < mina){
            mina = dist(a-1, i);
            ia = i;
        }
        if(dist(b-1, i) < minb){
            minb = dist(b-1, i);
            ib = i;
        }
    }
    if(ia < 0 || ib < 0) cout << dist(a-1, b-1) << endl;
    else cout << min(dist(ia, a-1) + dist(ib, b-1), dist(a-1, b-1)) << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}