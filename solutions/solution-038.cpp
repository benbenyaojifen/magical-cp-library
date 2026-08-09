#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + v[i - 1];
        if (i >= 2) {
            dp[i] = min(dp[i], dp[i - 2] + max(v[i - 1], v[i - 2]) + min(v[i - 1], v[i - 2]) / 4 * 3);
            if (i >= 3) {
                vector<int> a = {v[i - 1], v[i - 2], v[i - 3]};
                sort(a.begin(), a.end());
                dp[i] = min(dp[i], dp[i - 3] + a[0] / 2 + a[1] + a[2]);
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}