#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //idea is to use bfs to find shortest path without using teleport and then run bfs one more time with teleportion device taken into consideration
    int row, col; cin >> row >> col;
    int a, b; cin >> a >> b;
    int mr, mc; cin >> mr >> mc;
    vector<vector<char>> g(row, vector<char>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> g[i][j];
        }
    }
    vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
    dist[a][b] = 0;
    queue<pair<int, int>> q;
    vector<pair<int, int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    q.push({a, b});
    while(!q.empty()){
        auto[r, c] = q.front(); q.pop();
        for(auto[rr, cc] : dir){
            int nr = r + rr, nc = c + cc;
            if(nr >= 0 && nr < row && nc >= 0 && nc < col && g[nr][nc] != 'X' && dist[nr][nc] == INT_MAX){
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    int distance = dist[mr][mc];
    int t; cin >> t;
    vector<pair<int, int>> tel;
    for(int i = 0; i < t; i++){
        int x, y; cin >> x >> y;
        tel.emplace_back(x, y);
    }
    int tel_dist = INT_MAX;
    for(auto[r, c] : tel){
        tel_dist = min(tel_dist, dist[r][c]);
    }
    int ans = distance - (tel_dist != INT_MAX ? tel_dist : distance);
    cout << ans << '\n';
    return 0;
}