#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18;
int n;
vector<vector<pair<int, int>>> adj;
vector<long long> dijkstra(int start) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        long long d = cur.first;
        int u = cur.second;
        if (d != dist[u]) continue;
        for (auto edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            long long nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<long long> dist1 = dijkstra(1);
    int A = 1;
    for (int i = 1; i <= n; i++){
        if (dist1[i] > dist1[A]) A = i;
    }
    vector<long long> distA = dijkstra(A);
    int B = A;
    for (int i = 1; i <= n; i++){
        if (distA[i] > distA[B]) B = i;
    }
    long long diameter = distA[B];
    vector<long long> distB = dijkstra(B);
    long long radius = INF;
    for (int i = 1; i <= n; i++) {
        long long ecc = max(distA[i], distB[i]);
        if (ecc < radius) radius = ecc;
    }
    cout << diameter << "\n" << radius << "\n";
    return 0;
}
