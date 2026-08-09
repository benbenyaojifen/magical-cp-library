#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    vector<int> dist(n + 1, inf);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto[w, u] = pq.top(); pq.pop();
        if (w > dist[u]) continue;
        for (auto &[wt, v] : adj[u]) {
            if (dist[v] > wt + w) {
                dist[v] = wt + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == inf) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}