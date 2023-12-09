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
    vector<int> s(n), e(n);
    for(int i = 0; i < n; i++) cin >> s[i] >> e[i];
    int w = s[0], count = e[0];
    for(int i = 1; i < n; i++){
        if(s[i] < w) continue;
        if(e[i] >= count){
            cout << -1 << endl;
            return;
        }
    }
    cout << w << endl;
}

int main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}