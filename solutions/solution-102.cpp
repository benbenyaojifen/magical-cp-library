#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    vector<long long> dp(n + 1);
    dp[0] = 1; // empty set
    for (long long i = 1; i <= n; i++) {
        long long skip = dp[i - 1];
        long long take = (i >= k ? dp[i - k] : 1);
        dp[i] = (skip + take) % MOD;
    }
    cout << dp[n] % MOD << '\n';
    return 0;
}
