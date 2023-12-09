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

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n), x(q);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) cin >> x[i];
    vector<int>
    for(int i = 0; i < n; i++){
        int mult = 1;
        while(a[i]%mult == 0){
            mult = mult*2;
        }
        mp[mult] = a[i];
    }
}

int32_t main(){
    int t; 
    cin >> t;
    cout << endl;
    while(t--) solve();
    return 0;
}