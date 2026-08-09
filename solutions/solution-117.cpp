#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin >> n >> m;
    vector<bool> vis(n + 1); vector<int> sz(n + 1);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        int a;
        if (c == 'M') a = 2;
        else if (c == 'S') a = 1;
        else a = 3;
        sz[i] = a;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        char c; cin >> c; 
        int a ;
        if (c == 'M') a = 2;
        else if (c == 'S') a = 1;
        else a = 3;
        int num; cin >> num;
        if (a <= sz[num] && !vis[num]) {
            ans++;
            vis[num] = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}