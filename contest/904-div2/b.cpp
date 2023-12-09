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
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    queue<int> q, q1;
    int ones = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0' && i != 0) q.push(i);
        if(s[i] == '1') ones++;
    }
    vector<int> res(n+1, -1);
    res[0] = 0;
    for(int i = 1; i < n - ones + 1 ; i++){
        if(s[i-1] == '1'){
            int id = q.front(); q.pop();
            res[i] = id - i + 1 + res[i-1];
            swap(s[i-1], s[id]);
        }
        else{
            res[i] = res[i-1];
            while(!q.empty() && q.front() <= i) q.pop();
        }
    }
    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;

}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}