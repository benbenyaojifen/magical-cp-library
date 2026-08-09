#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
void solve() {
    vector<int> v(7);
    for (int i = 0; i < 7; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    sum *= -1;
    sum += v[6] * 2;
    cout << sum << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}