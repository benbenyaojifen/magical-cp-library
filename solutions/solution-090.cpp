#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> to;
vector<int> color, parent;
vector<vector<int>> cycles;
void dfs(int u){
    color[u] = 1; //visiting
    int v = to[u];
    if(color[v] == 0){ // unvisited 
        parent[v] = u;
        dfs(v);
    }else if(color[v] == 1){
        vector<int> cyc;
        int x = v;
        do {
            cyc.push_back(x);
            x = to[x];
        } while(x != v);
        int pos = min_element(cyc.begin(), cyc.end()) - cyc.begin();
        rotate(cyc.begin(), cyc.begin() + pos, cyc.end());
        cycles.push_back(move(cyc));
    }
    color[u] = 2; // done
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    to.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> to[i];
    }
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    for(int i = 1; i <= n; i++){
        if(color[i] == 0) dfs(i);
    }
    sort(cycles.begin(), cycles.end());
    cout << cycles.size() << '\n';
    for(auto &c : cycles){
        for(int i = 0; i < c.size(); i++){
            cout << c[i] << (i == c.size() - 1 ? "\n" : " ");
        }
    }
    return 0;
}