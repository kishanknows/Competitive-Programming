#include <vector>
#include <iostream>
#include <math.h>
#define int long long
using namespace std;

void solve(void);
int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}
double dist(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void solve(){
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double res = INT_MAX;
    double OA = dist(ax, ay, 0, 0), OB = dist(bx, by, 0, 0);
    double AP = dist(ax, ay, px, py), BP = dist(bx, by, px, py);
    double AB = dist(ax, ay, bx, by)/2.0;

    res = min(res, max(OA, AP));
    res = min(res, max(OB, BP));

    if((OA <= AB && BP <= AB && AP >= AB && OB >= AB) || (OA >= AB && BP >= AB && AP <= AB && OB <= AB)){
        res = min(res, AB);
    }
    cout << res << endl;
}