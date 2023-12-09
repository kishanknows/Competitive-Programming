#include <vector>
#include <iostream>
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
    int n, k, res = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int second = n, first = i;
        bool valid = true;
        for(int j = 0; j < k-2 ; j++){
            int tmp = second - first;
            second = first; first = tmp;
            if(first < 0 || second < 0 || first > second){
                valid = false;
                break;
            }
        }
        if(valid) res++;
    }
    cout<<res<<endl;
}