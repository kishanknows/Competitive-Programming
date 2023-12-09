#include <vector>
#include <iostream>
#include <iomanip>
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
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> heights(n);
    for(int i = 0; i < n; i++) cin>>heights[i];
    long double res = (long double)n*d*h/2;
    for(int i = 1; i < n; i++){
        int len = heights[i] - heights[i-1];
        if(len < h) res -= (long double)(h-len)*(h-len)*d/(2*h);
    }
    cout<<setprecision(15)<<res<<endl;
}