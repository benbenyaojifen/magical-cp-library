#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t = 5;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> coin(m);
        for (int i = 0; i < m; i++) {
            cin >> coin[i];
        }
        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int x : coin) {
            for (int i = x; i <= n; i++) {
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}