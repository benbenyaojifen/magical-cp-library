#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 2e18; //❄️
struct cell {
    ll val;
    int r, c;
    bool operator<(const cell &a) const {
        return val < a.val;
    }
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n));
    vector<cell> cells;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            cells.push_back({v[i][j], i, j});
        }
    }
    sort(cells.begin(), cells.end());
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ans = 0;
    for (int i = 0; i < cells.size(); i++) {
        int r = cells[i].r, c = cells[i].c;
        for (auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if (v[nr][nc] < v[r][c]) {
                    dp[r][c] = max(dp[nr][nc] + 1, dp[r][c]);
                }
            }
        }
        ans = max(ans, dp[r][c]);
    }
    cout << ans << '\n';
    return 0;
}
//recursion implementation
/*
#include <bits/stdc++.h>
using namespace std;
int n, g[1502][1502], dp[1502][1502], ans = 0;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int f(int r, int c) {
    if(dp[r][c]) return dp[r][c];
    dp[r][c] = 1;
    for(int k=0; k<4; k++) {
        int nr = r + dir[k][0], nc = c + dir[k][1];
        if(g[r][c] < g[nr][nc]) dp[r][c] = max(dp[r][c], f(nr, nc) + 1);
    }
    return dp[r][c];
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin >> g[i][j];
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            ans = max(ans, f(i, j));
    }
    cout << ans - 1 << endl;
}
*/