#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> pre(n);
    int sum = 0;
    int odds = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        pre[i] = sum;
    }
    int tmp = 0;
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 1){
            odds++;
        }
        tmp = pre[i];
        if(i > 0)
            tmp -= (odds/3 + (odds%3 == 1 ? 1 : 0));
        cout << tmp << " ";
    }
    cout << endl;
    
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}