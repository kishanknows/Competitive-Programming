#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) a[i] = i;
    if(m == 1) cout << 0 << endl;
    else cout << (n < m ? n+1 : m) << endl;
    for(int i = 0; i < min(n, m-1); i++){
        for(int j = 0; j < m; j++){
            cout << a[j] << " ";
        }
        cout << endl;
        int x = a.back(); a.pop_back();
        a.insert(a.begin(), x);
    }
    for(int i = m-1; i < n; i++){
        for(int j = 0; j < m; j++) cout << j << " ";
        cout << endl;
    }
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}