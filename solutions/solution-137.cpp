#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    vector<int> vis(m + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vis[x]++;
    }
    bool ok1 = 1, ok2 = 1;
    for (int i = 1; i <= m; i++) {
        if (vis[i] > 1) ok1 = 0;
        if (!vis[i]) ok2 = 0;
    }
    if (ok1) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    if (ok2) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}