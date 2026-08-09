#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e17; //❄️
#define int long long
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> psa(n + 1);
    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i - 1] + v[i - 1];
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = INF;
            for (int k = l; k < r; k++) {
                int cost = dp[l][k] + dp[k + 1][r] + psa[r + 1] - psa[l];
                dp[l][r] = min(dp[l][r], cost);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}