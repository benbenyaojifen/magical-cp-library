#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t, n, m, g; cin >> t >> n >> m >> g;
    unordered_set<int> d;
    for (int i = 0; i < g; i++) {
        int x; cin >> x;
        d.insert(x);
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
    }
    vector<int> dist(n + 1, inf);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto[w, u] = pq.top(); pq.pop();
        if (w > dist[u]) continue;
        for (auto[wt, v] : adj[u]) {
            if (dist[v] > wt + w) {
                dist[v] = wt + w;
                pq.push({dist[v], v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d.count(i) && dist[i] <= t) ans++;
    }
    cout << ans << '\n';
    return 0;
}