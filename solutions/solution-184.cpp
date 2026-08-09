#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    vector<long double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<long double> dp(n + 1);
    dp[1] = v[0];
    for (int i = 1; i <= n; i++) {
        if (i >= 2) dp[i] = min(dp[i - 1] + v[i - 1], dp[i - 2] + max(v[i - 1], v[i - 2]) + min(v[i - 1], v[i - 2]) * (long double) 0.5);
        if (i >= 3) {
            vector<long double> a = {v[i - 1], v[i - 2], v[i - 3]};
            sort(a.begin(), a.end());
            dp[i] = min(dp[i], dp[i - 3] + a[2] + a[1]);
        }
    }
    cout << fixed << setprecision(1) << dp[n] << '\n';
    return 0;
}