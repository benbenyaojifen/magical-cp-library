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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> dp(n + 1);
    dp[1] = max(0, v[0]);
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i - 1]);
    }
    cout << dp[n] << '\n';
    return 0;
}