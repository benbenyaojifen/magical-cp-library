#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dist(k + 1, vector<int>(n + 1, inf)); //dist[i][j] = the minimum cost to reach node j with the first i items purchased
    deque<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            dist[0][i] = 0;
            q.push_back(make_pair(i, 0));
        }
    }
    while (!q.empty()) {
        auto[u, p] = q.front(); q.pop_front();
        int cur = dist[p][u];
        if (p < k && v[u] == p + 1) {
           if (cur < dist[p + 1][u]) {
            dist[p + 1][u] = cur;
            q.push_front(make_pair(u, p + 1));
           }
        }
        for (int v : adj[u]) {
            if (dist[p][v] > cur + 1) {
                dist[p][v] = cur + 1;
                q.push_back(make_pair(v, p));
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dist[k][i]);
    }
    cout << ans << '\n';
    return 0;
}