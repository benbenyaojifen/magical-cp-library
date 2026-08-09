#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    vector<vector<pair<double, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, d, s; cin >> u >> v >> d >> s;
        double w = (double) d / (double) s * (double) 60; //minute
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    vector<pair<double, int>> dist(n + 1, make_pair(inf, inf));
    dist[1] = {(double) 0, 0};
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
    // same dist, same edge count
    pq.emplace(0, 0, 1);
    while (!pq.empty()) {
         auto[w, e, u] = pq.top(); pq.pop();
         if (u == n) break;
        //  if (w > dist[u].first) continue;
         for (auto[wt, v] : adj[u]) {
            if (dist[v].first > wt + w) {
                dist[v].first = wt + w;
                dist[v].second = e + 1;
                pq.emplace(dist[v].first, e + 1, v);
            } else if(dist[v].first == wt + w && e + 1 < dist[v].second) {
                dist[v].second = e + 1;
                pq.emplace(dist[v].first, e + 1, v);
            }
         }
    }
    cout << dist[n].second << '\n';
    cout << round(dist[n].first / 3) << '\n';
    return 0;
}