#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int cnt = 0;
    vector<int> vis(n + 1);
    auto dfs = [&](auto &&self, int x) -> void {
        if (vis[x]) return;
        vis[x] = 1;
        for (int v : adj[x]) {
            self(self, v);
        }
        return;
    };
    dfs(dfs, 1);
    for (int i = 1; i < vis.size(); i++) {
        if (vis[i]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}