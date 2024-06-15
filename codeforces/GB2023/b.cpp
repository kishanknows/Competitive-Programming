#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <numeric>
#include <climits>
#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int lcm = (a*b)/gcd(a, b);
    if(lcm == a || lcm == b){
        lcm = lcm * (max(a, b)/min(a,b));
    }
    cout << lcm <<  endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}