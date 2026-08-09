#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(int i, int j, vector<vector<char>> &g, vector<vector<bool>> & vis){
    vis[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        auto[r, c] = q.front(); q.pop();
        for(auto[rr, cc] : dir){
            int nr = r + rr, nc = c + cc;
            if(nr >= 0 && nr < g.size() && nc >= 0 && nc < g[0].size() && !vis[nr][nc] && g[nr][nc] != '#'){
                q.push({nr, nc});
                vis[nr][nc] = 1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int row, col; cin >> row >> col;
    vector<vector<char>> g(row, vector<char>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> g[i][j];
        }
    }
    int ans = 0;
    vector<vector<bool>> vis(row, vector<bool>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(!vis[i][j] && g[i][j] == 'M'){
                bfs(i, j, g, vis);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}