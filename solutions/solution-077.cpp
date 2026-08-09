#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
vector<int> parent, rk;
int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unite(int x, int y){
    x = find(x); y = find(y);
    if (rk[x] > rk[y]) {
        parent[y] = x;
    } else if(rk[y] > rk[x]) {
        parent[y] = x;
    } else {
        parent[y] = x;
        rk[x]++;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edge;
    parent.resize(n + 1); rk.resize(n + 1);
    for (int i = 0; i < parent.size(); i++) parent[i] = i;
    for (int i =  0; i < m; i++) { 
        int u, v; cin >> u >> v;
        edge.emplace_back(u, v);
    }
    vector<int> ans;
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        auto[x, y] = edge[i];
        if (find(x) != find(y)) {
            cnt++;
            unite(x, y);
            ans.push_back(i + 1);
        }
        if (cnt == n - 1) break;
    }
    if(cnt < n - 1){
        cout << "Disconnected Graph" << '\n';
        return 0;
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
    return 0;
}