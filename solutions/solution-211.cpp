#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int cur, t; cin >> cur >> t;
    int need = 80 * (t + 1) - (cur * t);
    if(need < 0){
        cout << 0 << endl;
    } else if(need > 100){
        cout << -1 << endl;
    } else{
        cout << need << endl;
    }
}