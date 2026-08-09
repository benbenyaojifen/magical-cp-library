#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k, p, x; cin >> k >> p >> x;
    double pre = x * 1 + (k * p) / 1;
    for(double i = 2; ; i++){
        double f = x * i + (k * p) / i;
        if(f > pre) break;
        pre = f;
    }
    cout << fixed << setprecision(3) << pre << '\n';
    return 0;
}