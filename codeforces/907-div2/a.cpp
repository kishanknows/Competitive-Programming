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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int start = 2;
    while(start < n){
        for(int i = start+1; i < 2*start && i < n; i++){
            if(a[i-1] > a[i]){
                cout << "NO" << endl;
                return;
            }
        }
        start *= 2;
    }
    cout << "YES" << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    cout << endl;
    while(t--) solve();
    return 0;
}