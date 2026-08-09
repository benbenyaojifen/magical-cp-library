#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    vector<vector<char>> vis(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0') vis[i][j] = 1;
        }
    }
    int cnt = 0;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto bfs = [&](int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while (!q.empty()) {
            auto[r, c] = q.front(); q.pop();
            for (int d = 0; d < dir.size(); d++) {
                int nr = r + dir[d].first, nc = c + dir[d].second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}