#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    vector<int> dist(n + 1, 0);
    dist[1] = inf;
    priority_queue<pair<int, int>> pq;
    pq.push({inf, 1});
    while (!pq.empty()) {
        auto[w, cur] = pq.top(); pq.pop();
        if (w < dist[cur]) continue;
        for (auto[wt, v] : adj[cur]) {
            if (min(w, wt) > dist[v]) {
                dist[v] = min(w, wt);
                pq.push({min(w, wt), v});
            }
        }
    }
    cout << 0 << '\n';
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << '\n';
    }
    return 0;
}