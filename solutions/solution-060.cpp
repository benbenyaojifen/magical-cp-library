#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mx = -1;
    cin >> n;
    vector<pair<string, int>> v;
    for(int i = 0; i < n; i++){
        string c;
        int x;
        cin >> c >> x;
        if(x > mx) mx = x;
        v.emplace_back(c, x);
    }
    int ans = n;
    for(auto[a, b] : v){
        int cnt = 0;
        for(auto[x, y] : v){
            if(x == "L" && b > y) cnt++;
            else if(x == "G" && b < y) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}