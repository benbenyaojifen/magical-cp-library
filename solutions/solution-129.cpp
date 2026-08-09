#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
struct DSU {
    int n;
    vector<int> parent, rank;
    DSU (int _n) : n(_n) , parent(n + 1), rank(n + 1, 0) {
        for (int i = 0; i < parent.size(); i++) parent[i] = i;
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else if (rank[y] > rank[x]) {
            parent[x] = y;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
};
struct edge {
    int u, v, w;
    bool operator<(const edge& other) const{
        return w < other.w;
    }
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, k; cin >> n >> k;
    vector<edge> v;
    for (int i = 1; i <= n; i++) {
        int w; cin >> w;
        if(i == n) break;
        v.push_back({i, i + 1, w});
    }
    for(int i = 1; i <= n; i++){
        if (i + k > n) {
            break;
        }
        v.push_back({i, i + k, 0});
    }
    sort(v.begin(), v.end());
    DSU dsu(n);
    int ans = 0, cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        auto[x, y, w] = v[i];
        if (dsu.find(x) != dsu.find(y)) {
            dsu.unite(x, y);
            ans += w; cnt++;
        }
        if(cnt == n - 1) break;
    }
    cout << ans << '\n';
    return 0;
}