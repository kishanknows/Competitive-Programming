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
    string s;
    cin >> s;
    int i = 0, n = s.length();
    vector<int> res;
    while(i < n){
        int count = 0;
        while(i < n && s[i] != 'B'){
            count++;
            i++;
        }
        res.push_back(count);
        i++;
    }
    int b = count(s.begin(), s.end(), 'B');
    sort(res.rbegin(), res.rend());
    int ans = 0;
    for(int i = 0; i < b; i++){
        ans += res[i];
    }
    cout << ans << endl;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}