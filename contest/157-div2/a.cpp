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

//how many cases can we think of?
//0 - x - y
//0 - y - x
//x - 0 - y
//y - 0 - x

void solve(){
    int x, y, k;
    cin >> x >> y >> k;
    if(x < 0 && y < 0){
        x = abs(x);
        y = abs(y);
    }
    if(x < 0 && y > 0){
        cout << min(abs(x) + )
    }
    if(y < 0 && x > 0){

    }
    if(x >= y){
        cout << x << endl;
        return;
    }
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}