
#include <bits/stdc++.h>

using namespace std;

const vector<vector<int>> DIR = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1,  -1}, {-1, 1}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 5;
    while(t-- > 0){
    vector<vector<char>> grid(10, vector<char>(10));
    int r, c;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
                char g;
                cin >> g;
                grid[i][j] = g;
                if(g == 'X'){
                    r = i; c = j;
                }
            }
        }
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(10, vector<bool>(10));
        vector<vector<int>> dist(10, vector<int>(10));
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                dist[i][j] = 0;
            }
        }
        visited[r][c] = true;
        q.push({r, c});
        bool end = false;
        while(!q.empty()){
            auto[cr, cc] = q.front(); q.pop();
            for(auto d : DIR){
                int nr, nc;
                nr = cr + d[0]; 
                nc = cc + d[1];
                if(nr >= 0 && nr < 10 && nc >= 0 && nc < 10 && !visited[nr][nc] && grid[nr][nc] != '#'){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                    dist[nr][nc] = dist[cr][cc] + 1;
                    if(grid[nr][nc] == 'X'){
                        cout << dist[nr][nc] << '\n';
                        end = true;
                    }
                    if(end) break;
                }
            }
            if(end) break;
        }
        cin.ignore();
        string dash;
        getline(cin, dash);
    }
    return 0;
}