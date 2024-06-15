#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> a(n+1), xors(n+1, 0);
    for(int i = 1; i <= n ; i++) cin >> a[i];
    long long res = 0;
    for(int l = 1; l <= n; l++){
        xors[l] = (xors[l-1]^a[l]);
        for(int r = 0; r < l; r++){
            res = (res  + ((xors[r]^xors[l])*(l - r)))%998244353;
        }
    }
    cout << res << endl;

}

int main(){
    // int t; 
    // cin >> t;
    // while(t--) 
    solve();
    return 0;
}