#include<bits/stdc++.h>
using namespace std; //❄️ idea is to use binary lifting to precompute the jumps(how many teleport)
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    const int MM = 30; // cuz 2 ^ 30 > k(1e9)
    vector<vector<int>> jump(MM, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        jump[0][i] = t; // jump[i][j] = the planet you reach if you start at j and take 2^i teleports.
    }
    for(int i = 1; i < MM; i++){
        for(int j = 1; j <= n; j++){
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }
    while(q--){
        int x; long long y; cin >> x >> y;
        for(int i = 0; i < MM; i++){
            if((y >> i) & 1LL) x = jump[i][x];
        }
        cout << x << '\n';
    }
    return 0;
}