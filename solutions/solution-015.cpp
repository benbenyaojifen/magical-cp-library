#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
int find (int x, vector<int>& parent) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}
void unite (int x, int y, vector<int>& parent) {
    int px = find(x, parent), py = find(y, parent);
    parent[px] = py;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, q; cin >> n >> q;
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i; 
    for (int i = 0; i < q; i++) {
        char c; int a, b; cin >> c >> a >> b;
        if(c == 'A'){
            unite(a, b, parent);
            
        } else {
            int pa = find(a, parent), pb = find(b, parent);
            if (pa == pb) cout << 'Y' << '\n';
            else cout << "N" << '\n';
        }
    }
    return 0;
}