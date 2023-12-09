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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    int i = 0, res;
    for(int i = 0; i < n; i++){
        if(a[i]*2 >= sum){
            res += a[i]+1;
            sum -= 2*a[i];
        }
    }
}

int32_t main(){
    int t; 
    cin >> t;
    cout << endl;
    while(t--) solve();
    return 0;
}