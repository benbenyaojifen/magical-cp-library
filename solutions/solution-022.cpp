#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<vector<char>> grid;
vector<vector<bool>> visited; 
const vector<pair<int,int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1},{0, -1},{0, 1},{1, -1}, {1, 0}, {1, 1}};

bool dfs(int x, int y, const string &w, int idx) {
    visited[x][y] = true;
    if (idx == (int) w.size() - 1) {
        visited[x][y] = false;
        return true;
    }
    for (auto [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || grid[nx][ny] != w[idx + 1]) 
            continue;
        if (dfs(nx, ny, w, idx + 1)) {
            visited[x][y] = false;
            return true;
        }
    }
    // does not exist
    visited[x][y] = false;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    grid.resize(n);
    for(int i = 0; i < n; i++)grid[i].resize(n);
    visited.assign(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    string _;
    getline(cin, _);
    while(q--> 0){
        string word;
        getline(cin, word);
        for (char &c : word) c = tolower(c);
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == word[0]) {
                    // reset visited
                    for (auto &k : visited) 
                        fill(k.begin(), k.end(), false);
                    if (dfs(i, j, word, 0)) {
                        found = true;
                    }
                }
            }
        }
        cout << (found ? "good puzzle!\n" : "bad puzzle!") << '\n';
    }
    return 0;
}