#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
const long long INF = 1e17; //❄️
int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> f(n + 1);
    int cnt = 0;
    ll ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n && cnt < k) {
            if (f[a[r]]++ == 0) cnt++;
            r++;
        } 
        if (cnt == k) ans += n - r + 1;
        if (--f[a[l]] == 0) cnt--;
    }
    cout << ans << '\n';
    return 0;
}