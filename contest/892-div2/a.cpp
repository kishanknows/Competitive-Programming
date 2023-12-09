#include <vector>
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

void solve(void);
int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin()+1, v.end());
    vector<int> b, c;
    int start = n;
    c.push_back(v[start]);
    start--;
    while(start > 0 && c.back() == v[start]){
        c.push_back(v[start]);
        start--;
    }
    while(start > 0){
        b.push_back(v[start]);
        start--;
    }
    if(b.size() == 0){
        cout<<-1<<endl;
        return;
    }
    cout << b.size() <<" "<< c.size()<<endl;
    for(int i = 0; i < b.size(); i++) cout<<b[i]<<" ";
    cout<<endl;
    for(int i = 0; i < c.size(); i++) cout<<c[i]<<" ";
    cout<<endl;
}