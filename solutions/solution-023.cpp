#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
unordered_map<ll, ll> memo;
ll solve(ll n) {
    if (n == 1) return 1;
    if (memo.count(n)) return memo[n];
    ll ans = 0;
    for (ll i = 2; i <= n;) {
        ll branch_weight = n / i;
        ll nxt = n / branch_weight + 1;
        ans += (nxt - i) * solve(branch_weight);
        i = nxt;
    }
    memo[n] = ans;
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    ll weight; cin >> weight;
    cout << solve(weight) << '\n';
    return 0;
}