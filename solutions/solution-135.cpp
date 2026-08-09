#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; ll t; cin >> n >> m >> k >> t;
    vector<char> v(n + 1);
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        v[x] = 1;
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    //muti source dijkstras
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            pq.push({0, i});
            dist[i] = 0;
        }
    }
    while (!pq.empty()) {
        auto[w, u] = pq.top(); pq.pop();
        if (w > dist[u]) continue;
        for (auto[c, v] : adj[u]) {
            if (w + c < dist[v]) {
                dist[v] = w + c;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (dist[i] <= t ? 0 : 1) << (i == n ? "\n" : "");
    }
    return 0;
}