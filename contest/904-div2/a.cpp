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

int calcSum(int x){
    int res = 0;
    while(x){
        res += x%10;
        x /= 10;
    }
    return res;
}

void solve(){
    int x, k;
    cin >> x >> k;
    while(calcSum(x)%k != 0) x++;
    cout << x << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}