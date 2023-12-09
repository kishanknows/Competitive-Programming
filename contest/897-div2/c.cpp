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
    int n, x = 0, y = -3;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        s[i] = num;
        if(num == x) x++;
    }
    // int moves = 0;

    while(y != -1 && y != -2){
        cout << x << endl;
        cout.flush();
        cin >> y;
        x = y;
    }
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}