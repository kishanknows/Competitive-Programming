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
    int n, m, h, rpoints = 0, rpenalty = 0, res = 1, tmp = 0;
    cin >> n >> m >> h;
    vector<vector<int> > t(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> t[i][j];
        }
    }
    for(int i = 0; i < n; i++) sort(t[i].begin(), t[i].end());
    for(int i = 0; i < m; i++){
        if(tmp + t[0][i] <= h){
            tmp += t[0][i];
            rpenalty += tmp;
            rpoints++;
        }
    }
    for(int i = 1; i < n; i++){
        int points = 0, penalty = 0, time = 0;
        for(int j = 0; j < m; j++){
            if(time + t[i][j] <= h){
                time += t[i][j];
                penalty += time;
                points++;
            }
        }
        if(points > rpoints) res++;
        else if(points == rpoints && penalty < rpenalty) res++;
    }
    cout<<res<<endl;
}