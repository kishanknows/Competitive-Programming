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
    int n, k, tmp;
    cin >> n >> k;
    tmp = k;
    //have to remove exactly k elements
    string s;
    cin >> s;
    vector<int> counts(26);
    for(char ch: s) counts[ch-'a']++;
    for(int i = 0; i < 26; i++){
        if(counts[i]%2 == 1 && tmp) {
            counts[i]--;
            tmp--;
        }
    }
    for(int i = 0; i < 26; i++){
        while(tmp && counts[i]) {
            counts[i]--;
            tmp--;
        }
    }
    int tolerance;
    if((n-k)%2 == 0) tolerance = 0;
    else tolerance = 1;
    for(int i = 0; i < 26; i++){
        if(counts[i]%2 == 1) tolerance--;
    }
    cout << (tolerance == 0 ? "YES" : "NO") << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}