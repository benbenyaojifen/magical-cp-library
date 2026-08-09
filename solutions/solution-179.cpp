#include <bits/stdc++.h>

using namespace std;

#define int long long 

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<int, vector<int>> row, col;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        row[y].push_back(x); col[x].push_back(y);
    }  
    for(auto &r : row){
        auto &v = r.second;
        sort(v.begin(), v.end());
    }
    for(auto &c : col){
        auto &v = c.second;
        sort(v.begin(), v.end());
    }
    int m;
    cin >> m;
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for(int i = 1; i < m; i++){
        int nx, ny;
        cin >> nx >> ny;
        if(x == nx){ 
            int lo = min(ny, y), hi = max(ny, y);
            if(col.count(nx)){
                const auto &v = col[nx];
                cnt += upper_bound(v.begin(), v.end(), hi) - lower_bound(v.begin(), v.end(), lo);
            }
        } else { 
            int lo = min(nx, x), hi = max(nx, x);
            if(row.count(ny)){
                const auto &v = row[ny];
                cnt += upper_bound(v.begin(), v.end(), hi) - lower_bound(v.begin(), v.end(), lo);
            }
        }
        x = nx; y = ny;
    }
    cout << cnt << '\n';
    return 0;
}