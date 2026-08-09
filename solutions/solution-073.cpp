#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
const int inf = 1e9;
const ll INF = 1e18; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; ll k; cin >> n >> k;
    vector<ll>v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (k >= v[i]) {
            k -= v[i];
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}